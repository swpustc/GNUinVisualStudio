#define FILE_VERSION_MAJOR  1
#define FILE_VERSION_MINOR  1
#define FILE_VERSION_POINT  9
#define FILE_VERSION_POINT2 11

#define INTERAL_NAME        "dumpImageSize"
#define EMAIL_ADDRESS       "swpustc@mail.ustc.edu.cn"
#define LEGAL_COPYRIGHT     "Copyright (C) 2014-2014 " EMAIL_ADDRESS " & USTC."
#define LICENSE_INFORMATION "License LGPLv3+: GNU LGPL version 3 or later <http://gnu.org/licenses/lgpl.html>."
#define HOME_PAGE_URL       "https://git.ustclug.org/swp/gnuinvisualstudio"

#ifndef _CRT_STRINGIZE
#define __CRT_STRINGIZE(_Value) #_Value
#define _CRT_STRINGIZE(_Value) __CRT_STRINGIZE(_Value)
#endif
#define FILE_VERSION        _CRT_STRINGIZE(FILE_VERSION_MAJOR) "." _CRT_STRINGIZE(FILE_VERSION_MINOR) "." _CRT_STRINGIZE(FILE_VERSION_POINT) "." _CRT_STRINGIZE(FILE_VERSION_POINT2)

#ifndef FILE_VERSION_NUMBER /* Should set in Solution by <PreprocessorDefinitions> */
#ifndef _ZERO_NUM
#define __ZERO_NUM(n)       0 ## n
#define _ZERO_NUM(n)        __ZERO_NUM(n)
#endif
#if FILE_VERSION_MINOR < 10
#define _FILE_VERSION_MINOR _ZERO_NUM(FILE_VERSION_MINOR)
#else
#define _FILE_VERSION_MINOR FILE_VERSION_MINOR
#endif
#if FILE_VERSION_POINT < 10
#define _FILE_VERSION_POINT _ZERO_NUM(FILE_VERSION_POINT)
#else
#define _FILE_VERSION_POINT FILE_VERSION_POINT
#endif
#define __FILE_VER(m,n,p)   m ## n ## p
#define _FILE_VER(m,n,p)    __FILE_VER(m,n,p)
#define FILE_VERSION_NUMBER _FILE_VER(FILE_VERSION_MAJOR, _FILE_VERSION_MINOR, _FILE_VERSION_POINT)
#pragma message (__FILE__ "(" _CRT_STRINGIZE(__LINE__) "): warning C4083: macro FILE_VERSION_NUMBER is NOT set in the Solution.")
#endif
#ifndef FILE_VERSION_NUMSTR
#define FILE_VERSION_NUMSTR _CRT_STRINGIZE(FILE_VERSION_NUMBER)
#endif

#if defined(_DLL) && defined(_CRT_MSVCP_CURRENT)
#define CUR_CRT_DLL         "  (" _CRT_MSVCP_CURRENT ")"
#define CUR_CRT_DLL_C       "  (" _CRT_MSVCP_CURRENT ", "
#else
#define CUR_CRT_DLL
#define CUR_CRT_DLL_C       "  ("
#endif

#ifdef _M_X64
#define FILE_VERSION_EXTRA  CUR_CRT_DLL_C "x64)"
#else
#define FILE_VERSION_EXTRA  CUR_CRT_DLL
#endif
