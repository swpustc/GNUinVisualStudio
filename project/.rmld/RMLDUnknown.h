#pragma once

typedef BOOL (APIENTRY *lpDllMain)(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved);

class CRMLDUnknown : public IRemoteMemLoadDll
{
private:
    ULONG m_Ref;
    DWORD m_LastErr;

public:
    virtual HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, __RPC__deref_out void __RPC_FAR *__RPC_FAR *ppvObject);
    virtual ULONG STDMETHODCALLTYPE AddRef();
    virtual ULONG STDMETHODCALLTYPE Release();
    virtual DWORD STDMETHODCALLTYPE GetLastError();
    CRMLDUnknown();

protected:
    VOID SetLastError(DWORD err);
    virtual ~CRMLDUnknown();
};
