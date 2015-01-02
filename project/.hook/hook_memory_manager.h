#pragma once

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN
#endif
#include "hook.h" // HOOK_EXP
#include <Windows.h> // FARPROC, BOOL
#include "hook_inline.h" // CWINAPI_INLINE_HOOK
#include "hook_iat.h" // CWINAPI_IAT_HOOK


HOOK_EXP BOOL InlineHookOn(FARPROC relPoint, FARPROC hookPoint, CWINAPI_INLINE_HOOK* pObject = NULL);
HOOK_EXP BOOL InlineHookOff(FARPROC relPoint, FARPROC hookPoint);

HOOK_EXP BOOL IatHookOn(FARPROC relPoint, CWINAPI_IAT_HOOK* pObject = NULL);
HOOK_EXP BOOL IatHookOff(FARPROC relPoint);
