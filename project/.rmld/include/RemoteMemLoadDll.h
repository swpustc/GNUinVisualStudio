#pragma once

#define REMOTEMEMLOADDLL_API extern "C"

struct IRemoteMemLoadDll;

#define RMLD_NORMAL                                     0x0000
#define RMLD_WITHOUT_DLLMAIN                            0x0001
#define RMLD_IGNORE_SHARED_PROTECT                      0x0002
#define RMLD_RANDOM_BASE_ADDRESS                        0x0004

REMOTEMEMLOADDLL_API IRemoteMemLoadDll* WINAPI CreateRemoteMemLoadDll(DWORD Flags);

// {63100DEF-6FB5-4A65-83A8-23BA876B2F35}
DEFINE_GUID(IID_IRemoteMemLoadDll, 
0x63100def, 0x6fb5, 0x4a65, 0x83, 0xa8, 0x23, 0xba, 0x87, 0x6b, 0x2f, 0x35);

extern "C++"
{
    MIDL_INTERFACE("63100DEF-6FB5-4A65-83A8-23BA876B2F35")
    IRemoteMemLoadDll : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, __RPC__deref_out void __RPC_FAR *__RPC_FAR *ppvObject) = 0;
        virtual ULONG STDMETHODCALLTYPE AddRef() = 0;
        virtual ULONG STDMETHODCALLTYPE Release() = 0;
        virtual HMODULE STDMETHODCALLTYPE LoadLibrary(HANDLE hProc, LPCVOID lpFileData, INT DataLength) = 0;
        virtual BOOL STDMETHODCALLTYPE FreeLibrary() = 0;
        virtual FARPROC STDMETHODCALLTYPE GetProcAddress(LPCSTR lpProcName) = 0; // return remote fuction address
        virtual BOOL STDMETHODCALLTYPE CallDllMain(DWORD ul_reason_for_call) = 0;
        virtual DWORD STDMETHODCALLTYPE GetLastError() = 0;
    };
}

#define RMLD_ERROR_SUCCESS                  0L

#define RMLD_ERROR_DLL_ALREADY_LOADED       1L
#define RMLD_ERROR_PROCESS_HANDLE_IS_NULL   2L

#define RMLD_ERROR_FILE_DATA_IS_NULL        4L
#define RMLD_ERROR_DOS_LENGTH               5L
#define RMLD_ERROR_DOS_HEADER_SIGNA         6L
#define RMLD_ERROR_NT_LENGTH                7L
#define RMLD_ERROR_NT_HEADER_SIGNA          8L
#define RMLD_ERROR_NOT_DLL_FILE             9L
#define RMLD_ERROR_NOT_EXECUTABLE           10L
#define RMLD_ERROR_FILE_HEAD_SIZE           11L
#define RMLD_ERROR_SECTION_SIZE             12L

#define RMLD_ERROR_NO_NT_HEADER             15L

#define RMLD_ERROR_ALLOC_BASE_IMAGE         20L
#define RMLD_ERROR_ALLOC_CODE_IMAGE         21L

#define RMLD_ERROR_FILL_RAV_ADDRESS         25L
#define RMLD_ERROR_PAGE_PROTECT_SHARED      27L
#define RMLD_ERROR_PAGE_PROTECT_NOACCESS    28L

#define RMLD_ERROR_NO_BASE_IMAGE            30L
#define RMLD_ERROR_NO_ENTRY_EXPORT          31L
#define RMLD_ERROR_OFFSET_OUT_OF_IMAGE      32L

#define RMLD_ERROR_NO_DLLMAIN               35L
#define RMLD_ERROR_REASON_FOR_CALL_DLLMAIN  36L
