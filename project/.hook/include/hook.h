#pragma once

#ifdef USING_hook_DLL
#  define HOOK_EXP __declspec(dllimport)
#elif defined HOOK_EXPORTS
#  define HOOK_EXP __declspec(dllexport)
#else
#  define HOOK_EXP
#endif

#ifdef __cplusplus
extern "C" {
#endif  /* __cplusplus */




#ifdef __cplusplus
}
#endif  /* __cplusplus */



