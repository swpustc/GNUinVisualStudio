#pragma once

#include <Windows.h> // typedef ...

class CWINAPI_INLINE_HOOK
{
protected:
    FARPROC m_pf;               // 要 hook 的函数指针
    FARPROC m_pr;               // 访问真实函数指针
#ifdef _M_X64
    BYTE    m_OldCode[24];
    BYTE    m_NewCode[10];
#else
    BYTE    m_OldCode[12];
    BYTE    m_NewCode[5];
#endif
    bool    m_bInit;            // 是否成功初始化
    bool    m_bhook;            // 是否 Hook 标志

public:
    CWINAPI_INLINE_HOOK();
    ~CWINAPI_INLINE_HOOK();

    HMODULE m_hModule;          // 所在 DLL 句柄

    BOOL Init(const FARPROC lpMyFun, const FARPROC lpProcFun);
    BOOL Init(const FARPROC lpMyFun, LPCSTR lpLibFileName, LPCSTR lpProcName);
    BOOL Init(const FARPROC lpMyFun, LPCWSTR lpLibFileName, LPCSTR lpProcName);
    BOOL HookOn();
    BOOL HookOff();
};
