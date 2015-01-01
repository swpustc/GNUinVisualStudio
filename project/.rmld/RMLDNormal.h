#pragma once

class CRMLDNormal : public CRMLDUnknown
{
public:
    CRMLDNormal(DWORD Flags = NULL);

    virtual HMODULE STDMETHODCALLTYPE LoadLibrary(HANDLE hProc, LPCVOID lpFileData, INT DataLength);
    virtual BOOL STDMETHODCALLTYPE FreeLibrary();
    virtual FARPROC STDMETHODCALLTYPE GetProcAddress(LPCSTR lpProcName);
    virtual BOOL STDMETHODCALLTYPE CallDllMain(DWORD ul_reason_for_call);

protected:
    virtual ~CRMLDNormal();
    BOOL CheckDataValide(LPCVOID lpFileData, INT DataLength);
    int CalcTotalImageSize();

    BOOL CopyDllDatas(LPVOID pDest, LPCVOID pSrc);
    BOOL FillRavAddress(void* pBase);
    void DoRelocation(void* NewBase);
    BOOL SetPageProtect(LPCVOID lpFileData, LPVOID lpBase);
    BOOL GetPageProtect(DWORD Characteristics, DWORD &nProtect);

    int GetAlignedSize(int Origin, int Alignment);

    DWORD RemoteFunction(LPTHREAD_START_ROUTINE lpStartAddress, LPVOID lpParameter);

    void WriteMemory(LPVOID lpBase, DWORD64 q);
    void WriteMemory(LPVOID lpBase, DWORD d);
    void WriteMemory(LPVOID lpBase, WORD w);
    void WriteMemory(LPVOID lpBase, BYTE b);

    DWORD64 ReadMemoryQ(LPVOID lpBase);
    DWORD ReadMemoryD(LPVOID lpBase);
    DWORD_PTR ReadMemoryD_PTR(LPVOID lpBase);
    WORD ReadMemoryW(LPVOID lpBase);
    BYTE ReadMemoryB(LPVOID lpBase);

    HANDLE m_hProc;
    lpDllMain m_pDllMain;
    LPTHREAD_START_ROUTINE ProcessAttach;
    LPTHREAD_START_ROUTINE ThreadAttach;
    LPTHREAD_START_ROUTINE ThreadDetach;
    LPTHREAD_START_ROUTINE ProcessDetach;
    LPTHREAD_START_ROUTINE pRelGetProcAddress;
    LPTHREAD_START_ROUTINE pFillRavAddress;
    LPTHREAD_START_ROUTINE pDoRelocation;
    LPTHREAD_START_ROUTINE pInitBase;
    FARPROC pLoadLibraryA;
    FARPROC pGetProcAddress;

    HMODULE m_pImageBase;
    LPBYTE  m_pcode;
    PIMAGE_DOS_HEADER m_pDosHeader;
    PIMAGE_NT_HEADERS m_pNTHeader;
    PIMAGE_SECTION_HEADER m_pSectionHeader;

    BOOL m_bWithoutDllMain;
    BOOL m_bIgnoreSharedProtect;
    BOOL m_bRandomBaseAddress;
};
