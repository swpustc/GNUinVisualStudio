#pragma once

#include <Windows.h> // typedef ...

class CWINAPI_IAT_HOOK
{
protected:
    FARPROC m_iatReal;          // 要 hook 的函数指针
    FARPROC m_myfun;            // 跳转函数指针
    BOOL    m_bInit;            // 是否成功初始化
    BOOL    m_bhook;            // 是否 Hook 标志

public:
    CWINAPI_IAT_HOOK();
    ~CWINAPI_IAT_HOOK();

    HMODULE m_hModule;          // 所在 DLL 句柄

    BOOL Init(const FARPROC lpMyFun, const FARPROC lpProcFun);
    BOOL Init(const FARPROC lpMyFun, LPCTSTR lpLibFileName, LPCSTR lpProcName);
    BOOL HookOn();
    BOOL HookOff();
};
