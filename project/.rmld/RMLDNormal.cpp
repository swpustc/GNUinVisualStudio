#include <stdlib.h>
#include <tchar.h>
#include <windows.h>

#include "RemoteMemLoadDll.h"
#include "RMLDUnknown.h"
#include "RemoteCode.h"
#include "RMLDNormal.h"

CRMLDNormal::CRMLDNormal(DWORD Flags /*=NULL*/)
{
    m_pImageBase = NULL;
    m_pcode = NULL;
    m_hProc = NULL;
    m_pDllMain = NULL;
    pLoadLibraryA = ::GetProcAddress(GetModuleHandle(_T("kernel32.dll")), "LoadLibraryA");
    pGetProcAddress = ::GetProcAddress(GetModuleHandle(_T("kernel32.dll")), "GetProcAddress");
    m_bWithoutDllMain = Flags & RMLD_WITHOUT_DLLMAIN;
    m_bIgnoreSharedProtect = Flags & RMLD_IGNORE_SHARED_PROTECT;
    m_bRandomBaseAddress = Flags & RMLD_RANDOM_BASE_ADDRESS;
}

CRMLDNormal::~CRMLDNormal()
{
    if(m_hProc && m_pcode)
    {
        VirtualFreeEx(m_hProc, m_pcode, 0, MEM_RELEASE);
        m_pcode = NULL;
    }
}

HMODULE CRMLDNormal::LoadLibrary(HANDLE hProc, LPCVOID lpFileData, INT DataLength)
{
    SetLastError(RMLD_ERROR_SUCCESS);
    if(m_pImageBase != NULL)
    {
        SetLastError(RMLD_ERROR_DLL_ALREADY_LOADED);
        return NULL; // 已经加载一个dll
    }
    if(m_hProc || hProc == NULL)
    {
        SetLastError(RMLD_ERROR_PROCESS_HANDLE_IS_NULL);
        return NULL;
    }
    m_hProc = hProc;
    // 检查数据有效性，并初始化
    if(!CheckDataValide(lpFileData, DataLength))
        return NULL;
    // 计算所需的加载空间
    int ImageSize = CalcTotalImageSize();
    if(ImageSize == 0)
        return NULL;
    // 分配虚拟内存
    LPVOID pMemoryAddress;
    if(m_bRandomBaseAddress)
    {
        pMemoryAddress = VirtualAllocEx(m_hProc, NULL, ImageSize, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
        if(pMemoryAddress == NULL)
        {
            SetLastError(RMLD_ERROR_ALLOC_BASE_IMAGE);
            return NULL;
        }
    }
    else
    {
        pMemoryAddress = VirtualAllocEx(m_hProc, (PBYTE)m_pNTHeader->OptionalHeader.ImageBase, ImageSize, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
        if(pMemoryAddress == NULL)
        {
            pMemoryAddress = VirtualAllocEx(m_hProc, NULL, ImageSize, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
            if(pMemoryAddress == NULL)
            {
                SetLastError(RMLD_ERROR_ALLOC_BASE_IMAGE);
                return NULL;
            }
        }
    }
    m_pcode = (LPBYTE)VirtualAllocEx(m_hProc, NULL, 0x1000, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
    if(!m_pcode)
    {
        VirtualFreeEx(m_hProc, pMemoryAddress, 0, MEM_RELEASE);
        SetLastError(RMLD_ERROR_ALLOC_CODE_IMAGE);
        return NULL;
    }
    ProcessAttach = (LPTHREAD_START_ROUTINE)(m_pcode); // m_code1
    ThreadAttach = (LPTHREAD_START_ROUTINE)((PBYTE)ProcessAttach + sizeof_m_code1); // m_code1
    ThreadDetach = (LPTHREAD_START_ROUTINE)((PBYTE)ThreadAttach + sizeof_m_code1); // m_code1
    ProcessDetach = (LPTHREAD_START_ROUTINE)((PBYTE)ThreadDetach + sizeof_m_code1); // m_code1
    pRelGetProcAddress = (LPTHREAD_START_ROUTINE)((PBYTE)ProcessDetach + sizeof_m_code1); // m_code2
    pFillRavAddress = (LPTHREAD_START_ROUTINE)((PBYTE)pRelGetProcAddress + sizeof_m_code2); // m_code3
    pDoRelocation = (LPTHREAD_START_ROUTINE)((PBYTE)pFillRavAddress + sizeof_m_code3); // m_code4
    pInitBase = (LPTHREAD_START_ROUTINE)((PBYTE)pDoRelocation + sizeof_m_code4); // m_code5
    *((PDWORD_PTR)&m_code2[__pos2_GetProcAddress]) = (DWORD_PTR)pGetProcAddress;
    *((PDWORD_PTR)&m_code3[__pos3_LoadLibraryA]) = (DWORD_PTR)pLoadLibraryA;
    *((PDWORD_PTR)&m_code3[__pos3_GetProcAddress1]) = (DWORD_PTR)pGetProcAddress;
    *((PDWORD_PTR)&m_code3[__pos3_GetProcAddress2]) = (DWORD_PTR)pGetProcAddress;
    *((PDWORD_PTR)&m_code5[__pos5_GetDoRelocation]) = (DWORD_PTR)pDoRelocation;
    *((PDWORD_PTR)&m_code5[__pos5_FillRavAddress]) = (DWORD_PTR)pFillRavAddress;
    WriteProcessMemory(m_hProc, pRelGetProcAddress, m_code2, sizeof_m_code2, NULL);
    WriteProcessMemory(m_hProc, pFillRavAddress, m_code3, sizeof_m_code3, NULL);
    WriteProcessMemory(m_hProc, pDoRelocation, m_code4, sizeof_m_code4, NULL);
    WriteProcessMemory(m_hProc, pInitBase, m_code5, sizeof_m_code5, NULL);
    if(!CopyDllDatas(pMemoryAddress, lpFileData)) // 复制dll数据，并对齐每个段
        return NULL;
    // 重定位信息
    // if( ReadMemoryD(&m_pNTHeader->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_BASERELOC].VirtualAddress) > 0 &&
    //     ReadMemoryD(&m_pNTHeader->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_BASERELOC].Size) > 0 )
    // {
    //     DoRelocation(pMemoryAddress);
    // }
    // 填充引入地址表
    if(!RemoteFunction(pInitBase, pMemoryAddress))
    // if(!RemoteFunction(pFillRavAddress, pMemoryAddress))
    // if(!FillRavAddress(pMemoryAddress)) // 修正引入地址表失败
    {
        VirtualFreeEx(m_hProc, pMemoryAddress, 0, MEM_RELEASE);
        VirtualFreeEx(m_hProc, m_pcode, 0, MEM_RELEASE);
        m_pcode = NULL;
        SetLastError(RMLD_ERROR_FILL_RAV_ADDRESS);
        return NULL;
    }
    // 修改页属性
    if(!SetPageProtect(lpFileData, pMemoryAddress))
    {
        VirtualFreeEx(m_hProc, pMemoryAddress, 0, MEM_RELEASE);
        VirtualFreeEx(m_hProc, m_pcode, 0, MEM_RELEASE);
        m_pcode = NULL;
        return NULL;
    }
    // 修正基地址
    m_pImageBase = (HMODULE)pMemoryAddress;
    WriteMemory(&m_pNTHeader->OptionalHeader.ImageBase, (DWORD_PTR)m_pImageBase);
    // 调用dll的入口
    m_pDllMain = (lpDllMain)(ReadMemoryD(&m_pNTHeader->OptionalHeader.AddressOfEntryPoint) + (PBYTE)m_pImageBase);
    *((PDWORD_PTR)&m_code1[__pos1_DllMain]) = (DWORD_PTR)m_pDllMain;
    m_code1[__pos1_ul_reason_for_call] = DLL_PROCESS_ATTACH;
    WriteProcessMemory(m_hProc, ProcessAttach, m_code1, sizeof_m_code1, NULL);
    m_code1[__pos1_ul_reason_for_call] = DLL_THREAD_ATTACH;
    WriteProcessMemory(m_hProc, ThreadAttach, m_code1, sizeof_m_code1, NULL);
    m_code1[__pos1_ul_reason_for_call] = DLL_THREAD_DETACH;
    WriteProcessMemory(m_hProc, ThreadDetach, m_code1, sizeof_m_code1, NULL);
    m_code1[__pos1_ul_reason_for_call] = DLL_PROCESS_DETACH;
    WriteProcessMemory(m_hProc, ProcessDetach, m_code1, sizeof_m_code1, NULL);
    if(m_bWithoutDllMain)
        return m_pImageBase;
    else
    {
        if(!m_pImageBase)
            return m_pImageBase;
        else if(CallDllMain(DLL_PROCESS_ATTACH))
            return m_pImageBase;
        else // 初始化失败
        {
            m_pDllMain = NULL;
            DWORD err = GetLastError();
            FreeLibrary();
            SetLastError(err);
            return NULL;
        }
    }
}

BOOL CRMLDNormal::FreeLibrary()
{
    SetLastError(RMLD_ERROR_SUCCESS);
    if(!m_hProc)
    {
        SetLastError(RMLD_ERROR_PROCESS_HANDLE_IS_NULL);
        return FALSE;
    }
    if(m_pDllMain)
    {
        CallDllMain(DLL_PROCESS_DETACH);
        m_pDllMain = NULL;
    }
    if(m_pImageBase)
    {
        VirtualFreeEx(m_hProc, m_pImageBase, 0, MEM_RELEASE);
        m_pImageBase = NULL;
    }
    if(m_pcode)
    {
        VirtualFreeEx(m_hProc, m_pcode, 0, MEM_RELEASE);
        m_pcode = NULL;
    }
    m_hProc = NULL;
    return TRUE;
}

FARPROC CRMLDNormal::GetProcAddress(LPCSTR lpProcName)
{
    SetLastError(RMLD_ERROR_SUCCESS);
    if(!m_hProc)
    {
        SetLastError(RMLD_ERROR_PROCESS_HANDLE_IS_NULL);
        return NULL;
    }
    if(!m_pImageBase)
    {
        SetLastError(RMLD_ERROR_NO_BASE_IMAGE);
        return NULL;
    }
    if( ReadMemoryD(&m_pNTHeader->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].VirtualAddress) == 0 ||
        ReadMemoryD(&m_pNTHeader->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].Size) == 0 )
    {
        SetLastError(RMLD_ERROR_NO_ENTRY_EXPORT);
        return NULL;
    }
    DWORD OffsetStart = ReadMemoryD(&m_pNTHeader->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].VirtualAddress);
    DWORD Size = ReadMemoryD(&m_pNTHeader->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].Size);
    PIMAGE_EXPORT_DIRECTORY pExport = (PIMAGE_EXPORT_DIRECTORY)(
        (PBYTE)m_pImageBase +
        ReadMemoryD(&m_pNTHeader->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].VirtualAddress) );
    int iBase = (int)ReadMemoryD(&pExport->Base);
    int iNumberOfFunctions = ReadMemoryD(&pExport->NumberOfFunctions);
    int iNumberOfNames = ReadMemoryD(&pExport->NumberOfNames); // <= iNumberOfFunctions

    LPDWORD pAddressOfFunctions = (LPDWORD)(ReadMemoryD(&pExport->AddressOfFunctions) + (PBYTE)m_pImageBase);
    LPWORD  pAddressOfOrdinals = (LPWORD)(ReadMemoryD(&pExport->AddressOfNameOrdinals) + (PBYTE)m_pImageBase);
    LPDWORD pAddressOfNames = (LPDWORD)(ReadMemoryD(&pExport->AddressOfNames) + (PBYTE)m_pImageBase);

    int iOrdinal = -1;
    if(HIWORD(lpProcName) == 0) // IT IS A ORDINAL!
    {
        iOrdinal = (DWORD)lpProcName - iBase;
    }
    else //use name
    {
        int iFound = -1;
        for(int i = 0; i < iNumberOfNames; i++)
        {
            LPSTR pName = (LPSTR)((DWORD_PTR)ReadMemoryD(&pAddressOfNames[i]) + (DWORD_PTR)m_pImageBase);
            CHAR name[MAX_PATH] = {0};
            LPSTR pname = name;
            while(*pname++ = (CHAR)ReadMemoryB(pName++));
            if(strcmp(name, lpProcName) == 0)
            {
                iFound = i;
                break;
            }
        }
        if(iFound >= 0)
        {
            iOrdinal = (int)(ReadMemoryW(&pAddressOfOrdinals[iFound]));
        }
    }
    if( iOrdinal < 0 ||
        iOrdinal >= iNumberOfFunctions )
        return NULL;
    else
    {
        DWORD pFunctionOffset = ReadMemoryD(&pAddressOfFunctions[iOrdinal]);
        if( pFunctionOffset > OffsetStart &&
            pFunctionOffset < (OffsetStart + Size) ) // maybe Export Forwarding
        {
            SetLastError(RMLD_ERROR_OFFSET_OUT_OF_IMAGE);
            return NULL;
        }
        else
            return (FARPROC)(pFunctionOffset + (PBYTE)m_pImageBase);
    }
}

BOOL CRMLDNormal::CheckDataValide(LPCVOID lpFileData, INT DataLength)
{
    SetLastError(RMLD_ERROR_SUCCESS);
    // 检查长度
    if(lpFileData == NULL)
    {
        SetLastError(RMLD_ERROR_FILE_DATA_IS_NULL);
        return FALSE;
    }
    if(DataLength < sizeof(IMAGE_DOS_HEADER))
    {
        SetLastError(RMLD_ERROR_DOS_LENGTH);
        return FALSE;
    }
    m_pDosHeader = (PIMAGE_DOS_HEADER)lpFileData; // DOS头
    // 检查dos头的标记
    if(m_pDosHeader->e_magic != IMAGE_DOS_SIGNATURE)
    {
        SetLastError(RMLD_ERROR_DOS_HEADER_SIGNA);
        return FALSE; //0*5A4D : MZ
    }
    // 检查长度
    if((DWORD)DataLength < (m_pDosHeader->e_lfanew + sizeof(IMAGE_NT_HEADERS)) )
    {
        SetLastError(RMLD_ERROR_NT_LENGTH);
        return FALSE;
    }
    // 取得PE头
    m_pNTHeader = (PIMAGE_NT_HEADERS)( (PBYTE)lpFileData + m_pDosHeader->e_lfanew); // PE头
    // 检查PE头的合法性
    if(m_pNTHeader->Signature != IMAGE_NT_SIGNATURE)
    {
        SetLastError(RMLD_ERROR_NT_HEADER_SIGNA);
        return FALSE; // 0*00004550 : PE00
    }
    if((m_pNTHeader->FileHeader.Characteristics & IMAGE_FILE_DLL) == 0) // 0*2000 : File is a DLL
    {
        SetLastError(RMLD_ERROR_NOT_DLL_FILE);
        return FALSE;
    }
    if((m_pNTHeader->FileHeader.Characteristics & IMAGE_FILE_EXECUTABLE_IMAGE) == 0) // 0*0002 : 指出文件可以运行
    {
        SetLastError(RMLD_ERROR_NOT_EXECUTABLE);
        return FALSE;
    }
    if(m_pNTHeader->FileHeader.SizeOfOptionalHeader != sizeof(IMAGE_OPTIONAL_HEADER))
    {
        SetLastError(RMLD_ERROR_FILE_HEAD_SIZE);
        return FALSE;
    }
    // 取得节表（段表）
    m_pSectionHeader = (PIMAGE_SECTION_HEADER)((PBYTE)m_pNTHeader + sizeof(IMAGE_NT_HEADERS));
    // 验证每个节表的空间
    for(int i = 0; i < m_pNTHeader->FileHeader.NumberOfSections; i++)
    {
        if((m_pSectionHeader[i].PointerToRawData + m_pSectionHeader[i].SizeOfRawData) > (DWORD)DataLength)
        {
            SetLastError(RMLD_ERROR_SECTION_SIZE);
            return FALSE;
        }
    }
    return TRUE;
}

int CRMLDNormal::CalcTotalImageSize()
{
    SetLastError(RMLD_ERROR_SUCCESS);
    int Size;
    if(m_pNTHeader == NULL)
    {
        SetLastError(RMLD_ERROR_NO_NT_HEADER);
        return 0;
    }
    int nAlign = m_pNTHeader->OptionalHeader.SectionAlignment; // 段对齐字节数
    // 计算所有头的尺寸。包括dos, coff, pe头 和 段表的大小
    Size = GetAlignedSize(m_pNTHeader->OptionalHeader.SizeOfHeaders, nAlign);
    // 计算所有节的大小
    for(int i = 0; i < m_pNTHeader->FileHeader.NumberOfSections; i++)
    {
        //得到该节的大小
        int CodeSize = m_pSectionHeader[i].Misc.VirtualSize;
        int LoadSize = m_pSectionHeader[i].SizeOfRawData;
        int MaxSize = max(CodeSize, LoadSize);
        int SectionSize = GetAlignedSize(m_pSectionHeader[i].VirtualAddress + MaxSize, nAlign);
        if(Size < SectionSize)
            Size = SectionSize; //Use the Max;
    }
    return Size;
}

BOOL CRMLDNormal::CopyDllDatas(LPVOID pDest, LPCVOID pSrc)
{
    SetLastError(RMLD_ERROR_SUCCESS);
    // 计算需要复制的PE头+段表字节数
    if(m_pNTHeader == NULL)
    {
        SetLastError(RMLD_ERROR_NO_NT_HEADER);
        return FALSE;
    }
    int HeaderSize = m_pNTHeader->OptionalHeader.SizeOfHeaders;
    int SectionSize = m_pNTHeader->FileHeader.NumberOfSections * sizeof(IMAGE_SECTION_HEADER);
    int MoveSize = HeaderSize + SectionSize;
    // 复制头和段信息
    WriteProcessMemory(m_hProc, pDest, pSrc, MoveSize, NULL);
    // 复制每个节
    for(int i = 0; i < m_pNTHeader->FileHeader.NumberOfSections; i++)
    {
        if( m_pSectionHeader[i].VirtualAddress == 0 ||
            m_pSectionHeader[i].SizeOfRawData == 0 )
            continue;
        // 定位该节在内存中的位置
        LPVOID pSectionAddress = (LPVOID)((PBYTE)pDest + m_pSectionHeader[i].VirtualAddress);
        // 复制段数据到虚拟内存
        WriteProcessMemory(m_hProc,
            pSectionAddress,
            (LPCVOID)((PBYTE)pSrc + m_pSectionHeader[i].PointerToRawData),
            m_pSectionHeader[i].SizeOfRawData,
            NULL);
    }
    // 修正指针，指向新分配的内存
    // 新的dos头
    m_pDosHeader = (PIMAGE_DOS_HEADER)pDest;
    // 新的pe头地址
    m_pNTHeader = (PIMAGE_NT_HEADERS)((PBYTE)pDest + ReadMemoryD(&m_pDosHeader->e_lfanew));
    // 新的节表地址
    m_pSectionHeader = (PIMAGE_SECTION_HEADER)((PBYTE)m_pNTHeader + sizeof(IMAGE_NT_HEADERS));
    return TRUE;
}

BOOL CRMLDNormal::FillRavAddress(void* pBase)
{
    // 引入表实际上是一个 IMAGE_IMPORT_DESCRIPTOR 结构数组，全部是0表示结束
    // 数组定义如下：
    //
    // DWORD OriginalFirstThunk; // 0表示结束，否则指向未绑定的IAT结构数组
    // DWORD TimeDateStamp;
    // DWORD ForwarderChain; // -1 if no forwarders
    // DWORD Name; // 给出dll的名字
    // DWORD FirstThunk; // 指向IAT结构数组的地址(绑定后，这些IAT里面就是实际的函数地址)
    DWORD Offset;
    if( ReadMemoryD(&m_pNTHeader->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].Size) == 0 ||
        (Offset = ReadMemoryD(&m_pNTHeader->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].VirtualAddress)) == 0 )
        return TRUE; // No Import Table
    PIMAGE_IMPORT_DESCRIPTOR pID = (PIMAGE_IMPORT_DESCRIPTOR)((PBYTE)pBase + Offset);
    while(ReadMemoryD(&pID->Characteristics) != 0)
    {
        PIMAGE_THUNK_DATA pRealIAT = (PIMAGE_THUNK_DATA)((PBYTE)pBase + ReadMemoryD(&pID->FirstThunk));
        PIMAGE_THUNK_DATA pOriginalIAT = (PIMAGE_THUNK_DATA)((PBYTE)pBase + ReadMemoryD(&pID->OriginalFirstThunk));
        // 获取dll的名字
        LPSTR pName = (LPSTR)((PBYTE)pBase + ReadMemoryD(&pID->Name));
        HMODULE hDll = (HMODULE)RemoteFunction((LPTHREAD_START_ROUTINE)pLoadLibraryA, pName); // 加载dll, 添加引用计数
        if(hDll == NULL)
            return FALSE; // NOT FOUND DLL
        // 获取DLL中每个导出函数的地址，填入IAT
        // 每个IAT结构是 ：
        // union { PBYTE ForwarderString;
        // PDWORD Function;
        // DWORD Ordinal;
        // PIMAGE_IMPORT_BY_NAME AddressOfData;
        // } u1;
        // 长度是一个DWORD ，正好容纳一个地址。
        for(int i = 0; ; i++)
        {
            if(ReadMemoryD_PTR(&pOriginalIAT[i].u1.Function) == 0)
                break;
            FARPROC lpFunction = NULL;
            if(ReadMemoryD_PTR(&pOriginalIAT[i].u1.Ordinal) & IMAGE_ORDINAL_FLAG) // 这里的值给出的是导出序号
            {
                WriteMemory((LPVOID)((PBYTE)m_pcode + 0x800), (DWORD_PTR)hDll);
                WriteMemory((LPVOID)((PBYTE)m_pcode + 0x800 + sizeof(DWORD_PTR)), (DWORD_PTR)(ReadMemoryD_PTR(&pOriginalIAT[i].u1.Ordinal) & 0x0000FFFF));
                lpFunction = (FARPROC)RemoteFunction(pRelGetProcAddress, (LPVOID)((PBYTE)m_pcode + 0x800));
            }
            else // 按照名字导入
            {
                // 获取此IAT项所描述的函数名称
                PIMAGE_IMPORT_BY_NAME pByName = (PIMAGE_IMPORT_BY_NAME)(
                    (PBYTE)pBase +
                    ReadMemoryD_PTR(&pOriginalIAT[i].u1.AddressOfData) );
                // if(pByName->Hint !=0)
                // lpFunction = GetProcAddress(hDll, (LPCSTR)pByName->Hint);
                // else
                WriteMemory((LPVOID)((PBYTE)m_pcode + 0x800), (DWORD_PTR)hDll);
                WriteMemory((LPVOID)((PBYTE)m_pcode + 0x800 + sizeof(DWORD_PTR)), (DWORD_PTR)pByName->Name);
                lpFunction = (FARPROC)RemoteFunction(pRelGetProcAddress, (LPVOID)((PBYTE)m_pcode + 0x800));
            }
            if(lpFunction != NULL) //找到了
            {
                WriteMemory(&pRealIAT[i].u1.Function, (DWORD_PTR)lpFunction);
            }
            else
                return FALSE;
        }
        //move to next
        pID++;
    }
    return TRUE;
}

void CRMLDNormal::DoRelocation(void* NewBase)
{
    // 重定位表的结构：
    // DWORD sectionAddress, DWORD size (包括本节需要重定位的数据)
    // 例如 1000节需要修正5个重定位数据的话，重定位表的数据是
    // 00 10 00 00 14 00 00 00 xxxx xxxx xxxx xxxx xxxx 0000
        
    // 给出节的偏移 总尺寸=8+6*2 需要修正的地址 用于对齐4字节
    // 重定位表是若干个相连，如果address 和 size都是0 表示结束
    // 需要修正的地址是12位的，高4位是形态字，intel cpu下是3
    // 假设NewBase是0x600000, 而文件中设置的缺省ImageBase是0x400000, 则修正偏移量就是0x200000
    DWORD_PTR Delta = (DWORD_PTR)NewBase - ReadMemoryD_PTR(&m_pNTHeader->OptionalHeader.ImageBase);
        
    //注意重定位表的位置可能和硬盘文件中的偏移地址不同，应该使用加载后的地址
    PIMAGE_BASE_RELOCATION pLoc = (PIMAGE_BASE_RELOCATION)(
        (PBYTE)NewBase +
        ReadMemoryD(&m_pNTHeader->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_BASERELOC].VirtualAddress) );
        
    while((ReadMemoryD(&pLoc->VirtualAddress) + ReadMemoryD(&pLoc->SizeOfBlock)) != 0) // 开始扫描重定位表
    {
        LPWORD pLocData = (LPWORD)((PBYTE)pLoc + sizeof(IMAGE_BASE_RELOCATION));
        // 计算本节需要修正的重定位项（地址）的数目
        int NumberOfReloc = (
            ReadMemoryD(&pLoc->SizeOfBlock) -
            sizeof(IMAGE_BASE_RELOCATION) ) /
            sizeof(WORD);
        for(int i = 0; i < NumberOfReloc; i++)
        {
            // 每个WORD由两部分组成。高4位指出了重定位的类型，WINNT.H中的一系列IMAGE_REL_BASED_xxx定义了重定位类型的取值。
            // 低12位是相对于VirtualAddress域的偏移，指出了必须进行重定位的位置。
#ifndef _M_X64
            if( (ReadMemoryW(&pLocData[i]) & 0xF000) == (IMAGE_REL_BASED_HIGHLOW << 12) ||  // x86
                (ReadMemoryW(&pLocData[i]) & 0xF000) == (IMAGE_REL_BASED_DIR64 << 12) ||    // ia64 or amd64
#else
            if( (ReadMemoryW(&pLocData[i]) & 0xF000) == (IMAGE_REL_BASED_DIR64 << 12) ||    // x86
                (ReadMemoryW(&pLocData[i]) & 0xF000) == (IMAGE_REL_BASED_HIGHLOW << 12) ||  // ia64 or amd64
#endif
                (ReadMemoryW(&pLocData[i]) & 0xF000) == (IMAGE_REL_BASED_IA64_IMM64 << 12) ) // 这是一个需要修正的地址
            {
                // 32位dll重定位，IMAGE_REL_BASED_HIGHLOW
                // 对于x86的可执行文件，所有的基址重定位都是IMAGE_REL_BASED_HIGHLOW类型的。
                // 64位dll重定位，IMAGE_REL_BASED_DIR64
                // 对于IA-64的可执行文件，重定位似乎总是IMAGE_REL_BASED_DIR64类型的。
                // 举例：
                // pLoc->VirtualAddress = 0x1000;
                // pLocData[i] = 0x313E; 表示本节偏移地址0x13E处需要修正
                // 因此 pAddress = 基地址 + 0x113E
                // 里面的内容是 A1 0C D4 02 10 汇编代码是： mov eax,[1002d40c]
                // 需要修正1002d40c这个地址
                PDWORD_PTR pAddress = (PDWORD_PTR)(
                    (PBYTE)NewBase +
                    ReadMemoryD(&pLoc->VirtualAddress) +
                    (ReadMemoryW(&pLocData[i]) & 0x0FFF) );
                WriteMemory(pAddress, ReadMemoryD_PTR(pAddress) + Delta);
            }
        }
        //转移到下一个节进行处理
        pLoc = (PIMAGE_BASE_RELOCATION)((PBYTE)pLoc + ReadMemoryD(&pLoc->SizeOfBlock));
    }
}

BOOL CRMLDNormal::SetPageProtect(LPCVOID lpFileData, LPVOID lpBase)
{
    SetLastError(RMLD_ERROR_SUCCESS);
    // 计算需要PE头+段表字节数
    PIMAGE_DOS_HEADER pDosHeader = (PIMAGE_DOS_HEADER)lpFileData; // DOS头
    // 取得PE头
    PIMAGE_NT_HEADERS pNTHeader = (PIMAGE_NT_HEADERS)((PBYTE)pDosHeader + pDosHeader->e_lfanew); // PE头
    // 取得节表（段表）
    PIMAGE_SECTION_HEADER pSectionHeader = (PIMAGE_SECTION_HEADER)((PBYTE)pNTHeader + sizeof(IMAGE_NT_HEADERS));
    int nAlign = pNTHeader->OptionalHeader.SectionAlignment; // 段对齐字节数
    int HeaderSize = pNTHeader->OptionalHeader.SizeOfHeaders;
    int SectionSize = pNTHeader->FileHeader.NumberOfSections * sizeof(IMAGE_SECTION_HEADER);
    int MoveSize = HeaderSize + SectionSize;
    DWORD old;
    // 复制头和段信息页属性为 RW
    VirtualProtectEx(m_hProc, lpBase, GetAlignedSize(MoveSize, nAlign), PAGE_READWRITE, &old);
    // 设置每个节页属性
    for(int i = 0; i < pNTHeader->FileHeader.NumberOfSections; i++)
    {
        if( pSectionHeader[i].VirtualAddress == 0 ||
            pSectionHeader[i].SizeOfRawData == 0 )
            continue;
        int SectionSize = GetAlignedSize(pSectionHeader[i].SizeOfRawData, nAlign);
        // 设置节的页属性
        DWORD nProtect;
        if(!GetPageProtect(pSectionHeader[i].Characteristics, nProtect))
            return FALSE;
        // 定位该节在内存中的位置
        LPVOID pSectionAddress = (LPVOID)((PBYTE)lpBase + pSectionHeader[i].VirtualAddress);
        VirtualProtectEx(m_hProc, pSectionAddress, GetAlignedSize(MoveSize, nAlign), nProtect, &old);
    }
    return TRUE;
}

BOOL CRMLDNormal::GetPageProtect(DWORD Characteristics, DWORD &nProtect)
{
    if( (!m_bIgnoreSharedProtect) &&
        (Characteristics & IMAGE_SCN_MEM_SHARED) )
    {
        SetLastError(RMLD_ERROR_PAGE_PROTECT_SHARED);
        return FALSE;
    }
    switch(Characteristics & (IMAGE_SCN_MEM_EXECUTE | IMAGE_SCN_MEM_READ | IMAGE_SCN_MEM_WRITE))
    {
    case IMAGE_SCN_MEM_READ:
        nProtect = PAGE_READONLY;
        break;
    case IMAGE_SCN_MEM_READ | IMAGE_SCN_MEM_WRITE:
        nProtect = PAGE_READWRITE;
        break;
    case IMAGE_SCN_MEM_EXECUTE:
        nProtect = PAGE_EXECUTE;
        break;
    case IMAGE_SCN_MEM_EXECUTE | IMAGE_SCN_MEM_READ:
        nProtect = PAGE_EXECUTE_READ;
        break;
    case IMAGE_SCN_MEM_EXECUTE | IMAGE_SCN_MEM_READ | IMAGE_SCN_MEM_WRITE:
        nProtect = PAGE_EXECUTE_WRITECOPY;
        break;
    default:
        nProtect = PAGE_NOACCESS;
        SetLastError(RMLD_ERROR_PAGE_PROTECT_NOACCESS);
        return FALSE;
    }
    return TRUE;
}

int CRMLDNormal::GetAlignedSize(int Origin, int Alignment)
{
    return (Origin + Alignment - 1) / Alignment * Alignment;
}

DWORD CRMLDNormal::RemoteFunction(LPTHREAD_START_ROUTINE lpStartAddress, LPVOID lpParameter)
{
    HANDLE hThread;
    SECURITY_ATTRIBUTES ThreadBuffer = {0};
    DWORD dwID;
    hThread = CreateRemoteThread(m_hProc, &ThreadBuffer, NULL, lpStartAddress, lpParameter, NULL, &dwID);
    WaitForSingleObject(hThread, INFINITE);
    DWORD InitResult;
    GetExitCodeThread(hThread, &InitResult);
    CloseHandle(hThread);
    return InitResult;
}

void CRMLDNormal::WriteMemory(LPVOID lpBase, DWORD64 q)
{
    WriteProcessMemory(m_hProc, lpBase, &q, sizeof(q), NULL);
}

void CRMLDNormal::WriteMemory(LPVOID lpBase, DWORD d)
{
    WriteProcessMemory(m_hProc, lpBase, &d, sizeof(d), NULL);
}

void CRMLDNormal::WriteMemory(LPVOID lpBase, WORD w)
{
    WriteProcessMemory(m_hProc, lpBase, &w, sizeof(w), NULL);
}

void CRMLDNormal::WriteMemory(LPVOID lpBase, BYTE b)
{
    WriteProcessMemory(m_hProc, lpBase, &b, sizeof(b), NULL);
}

DWORD64 CRMLDNormal::ReadMemoryQ(LPVOID lpBase)
{
    DWORD64 buf = 0;
    ReadProcessMemory(m_hProc, lpBase, &buf, sizeof(buf), NULL);
    return buf;
}

DWORD CRMLDNormal::ReadMemoryD(LPVOID lpBase)
{
    DWORD buf = 0;
    ReadProcessMemory(m_hProc, lpBase, &buf, sizeof(buf), NULL);
    return buf;
}

DWORD_PTR CRMLDNormal::ReadMemoryD_PTR(LPVOID lpBase)
{
    DWORD_PTR buf = 0;
    ReadProcessMemory(m_hProc, lpBase, &buf, sizeof(buf), NULL);
    return buf;
}

WORD CRMLDNormal::ReadMemoryW(LPVOID lpBase)
{
    WORD buf = 0;
    ReadProcessMemory(m_hProc, lpBase, &buf, sizeof(buf), NULL);
    return buf;
}

BYTE CRMLDNormal::ReadMemoryB(LPVOID lpBase)
{
    BYTE buf = 0;
    ReadProcessMemory(m_hProc, lpBase, &buf, sizeof(buf), NULL);
    return buf;
}

BOOL CRMLDNormal::CallDllMain(DWORD ul_reason_for_call)
{
    SetLastError(RMLD_ERROR_SUCCESS);
    if(m_pDllMain)
    {
        switch(ul_reason_for_call)
        {
        case DLL_PROCESS_ATTACH:
            return (BOOL)RemoteFunction(ProcessAttach, m_pImageBase);
        case DLL_THREAD_ATTACH:
            return (BOOL)RemoteFunction(ThreadAttach, m_pImageBase);
        case DLL_THREAD_DETACH:
            return (BOOL)RemoteFunction(ThreadDetach, m_pImageBase);
        case DLL_PROCESS_DETACH:
            return (BOOL)RemoteFunction(ProcessDetach, m_pImageBase);
        default:
            SetLastError(RMLD_ERROR_REASON_FOR_CALL_DLLMAIN);
            return FALSE;
        }
    }
    else
    {
        SetLastError(RMLD_ERROR_NO_DLLMAIN);
        return TRUE; // 无入口点，直接返回
    }
}
