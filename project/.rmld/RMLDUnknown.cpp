#include <stdlib.h>
#include <windows.h>

#include "RemoteMemLoadDll.h"
#include "RMLDUnknown.h"

CRMLDUnknown::CRMLDUnknown()
{
    m_Ref = 1;
    m_LastErr = RMLD_ERROR_SUCCESS;
}

CRMLDUnknown::~CRMLDUnknown()
{
}

HRESULT CRMLDUnknown::QueryInterface(REFIID riid, __RPC__deref_out void __RPC_FAR *__RPC_FAR *ppvObject)
{
    if(!ppvObject)
        return E_POINTER;
    if(IID_IUnknown == riid)
    {
        *ppvObject = static_cast<IUnknown*>(this);
        return S_OK;
    }
    else if(IID_IRemoteMemLoadDll == riid)
    {
        *ppvObject = dynamic_cast<IRemoteMemLoadDll*>(this);
        return S_OK;
    }
    else
        return E_NOINTERFACE;
}

ULONG CRMLDUnknown::AddRef()
{
    if(this && m_Ref > 0)
    {
        m_Ref++;
        return TRUE;
    }
    else
        return FALSE;
}

ULONG CRMLDUnknown::Release()
{
    if(!this)
        return FALSE;
    if(m_Ref > 1)
        m_Ref--;
    else
    {
        m_Ref = 0;
        delete this;
    }
    return TRUE;
}

DWORD CRMLDUnknown::GetLastError()
{
    return m_LastErr;
}

VOID CRMLDUnknown::SetLastError(DWORD err)
{
    m_LastErr = err;
}
