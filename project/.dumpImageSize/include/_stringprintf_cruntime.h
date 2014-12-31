#ifndef _STRINGPRINTF_CRUNTIME_H_
#define _STRINGPRINTF_CRUNTIME_H_

#ifdef _STRINGPRINTF_H_


#include <stdio.h>
#include <stdarg.h>
#include <ctype.h>
#include <string.h>
#include <wchar.h>
#include <direct.h>

#define _STDEX_STDC_BEGIN       namespace stdc { /* must in ::stdex::my:: */
#define _STDEX_STDC_END         }
#define _STDEX_STDC             _STDEX_MY stdc::
#define _STDEX_STDC_USING       _STDEX_MY_USING ::stdc


/* overloaded C Runtime function */
_STDEX_BEGIN _STDEX_MY_BEGIN _STDEX_STDC_BEGIN

/* overloaded ::_chdir */
inline int chdir(const char* _Path)
{
    return ::_chdir(_Path);
}
/* overloaded ::_mkdir */
inline int mkdir(const char* _Path)
{
    return ::_mkdir(_Path);
}
/* overloaded ::_rmdir */
inline int rmdir(const char* _Path)
{
    return ::_rmdir(_Path);
}

/* overloaded ::_wchdir */
inline int chdir(const wchar_t* _Path)
{
    return ::_wchdir(_Path);
}
/* overloaded ::_wmkdir */
inline int mkdir(const wchar_t* _Path)
{
    return ::_wmkdir(_Path);
}
/* overloaded ::_rmdir */
inline int rmdir(const wchar_t* _Path)
{
    return ::_wrmdir(_Path);
}

/* overloaded ::isalpha */
inline bool isalpha(char _C)
{
    return !!::isalpha((int)_C);
}
/* overloaded ::isupper */
inline bool isupper(char _C)
{
    return !!::isupper((int)_C);
}
/* overloaded ::islower */
inline bool islower(char _C)
{
    return !!::islower((int)_C);
}
/* overloaded ::isdigit */
inline bool isdigit(char _C)
{
    return !!::isdigit((int)_C);
}
/* overloaded ::isxdigit */
inline bool isxdigit(char _C)
{
    return !!::isxdigit((int)_C);
}
/* overloaded ::isspace */
inline bool isspace(char _C)
{
    return !!::isspace((int)_C);
}
/* overloaded ::ispunct */
inline bool ispunct(char _C)
{
    return !!::ispunct((int)_C);
}
/* overloaded ::isblank */
inline bool isblank(char _C)
{
#if _MSC_VER < 1800
    if (_C == '\t')
        return !!_BLANK;
    else
        return !!::_isctype((int)_C, _BLANK);
#else /* _MSC_VER < 1800 */
    return !!::isblank((int)_C);
#endif
}
/* overloaded ::isalnum */
inline bool isalnum(char _C)
{
    return !!::isalnum((int)_C);
}
/* overloaded ::isprint */
inline bool isprint(char _C)
{
    return !!::isprint((int)_C);
}
/* overloaded ::isgraph */
inline bool isgraph(char _C)
{
    return !!::isgraph((int)_C);
}
/* overloaded ::iscntrl */
inline bool iscntrl(char _C)
{
    return !!::iscntrl((int)_C);
}

/* overloaded ::iswalpha */
inline bool isalpha(wchar_t _C)
{
    return !!::iswalpha((wint_t)_C);
}
/* overloaded ::iswupper */
inline bool isupper(wchar_t _C)
{
    return !!::iswupper((wint_t)_C);
}
/* overloaded ::iswlower */
inline bool islower(wchar_t _C)
{
    return !!::iswlower((wint_t)_C);
}
/* overloaded ::iswdigit */
inline bool isdigit(wchar_t _C)
{
    return !!::iswdigit((wint_t)_C);
}
/* overloaded ::iswxdigit */
inline bool isxdigit(wchar_t _C)
{
    return !!::iswxdigit((wint_t)_C);
}
/* overloaded ::iswspace */
inline bool isspace(wchar_t _C)
{
    return !!::iswspace((wint_t)_C);
}
/* overloaded ::iswpunct */
inline bool ispunct(wchar_t _C)
{
    return !!::iswpunct((wint_t)_C);
}
/* overloaded ::iswblank */
inline bool isblank(wchar_t _C)
{
#if _MSC_VER < 1800
    if(_C == L'\t')
        return !!_BLANK;
    else
        return !!::iswctype((wint_t)_C, _BLANK);
#else /* _MSC_VER < 1800 */
    return !!::iswblank((wint_t)_C);
#endif
}
/* overloaded ::iswalnum */
inline bool isalnum(wchar_t _C)
{
    return !!::iswalnum((wint_t)_C);
}
/* overloaded ::iswprint */
inline bool isprint(wchar_t _C)
{
    return !!::iswprint((wint_t)_C);
}
/* overloaded ::iswgraph */
inline bool isgraph(wchar_t _C)
{
    return !!::iswgraph((wint_t)_C);
}
/* overloaded ::iswcntrl */
inline bool iscntrl(wchar_t _C)
{
    return !!::iswcntrl((wint_t)_C);
}

/* overloaded ::toupper */
inline char toupper(char _Ch)
{
    return (char)::toupper((int)_Ch);
}
/* overloaded ::tolower */
inline char tolower(char _Ch)
{
    return (char)::tolower((int)_Ch);
}

/* overloaded ::towupper */
inline wchar_t toupper(wchar_t _Ch)
{
    return (wchar_t)::towupper((wint_t)_Ch);
}
/* overloaded ::towlower */
inline wchar_t tolower(wchar_t _Ch)
{
    return (wchar_t)::towlower((wint_t)_Ch);
}

/* overloaded ::strtod */
inline double strtod(const char* _Str, char** _EndPtr = nullptr)
{
    return ::strtod(_Str, _EndPtr);
}
/* overloaded ::strtol */
inline long strtol(const char* _Str, char** _EndPtr = nullptr, int _Radix = 10)
{
    return ::strtol(_Str, _EndPtr, _Radix);
}
/* overloaded ::strtoll */
inline long long strtoll(const char* _Str, char** _EndPtr = nullptr, int _Radix = 10)
{
#if _MSC_VER < 1800
    return ::_strtoi64(_Str, _EndPtr, _Radix);
#else /* _MSC_VER < 1800 */
    return ::strtoll(_Str, _EndPtr, _Radix);
#endif
}
/* overloaded ::strtoul */
inline unsigned long strtoul(const char* _Str, char** _EndPtr = nullptr, int _Radix = 10)
{
    return ::strtoul(_Str, _EndPtr, _Radix);
}
/* overloaded ::strtoull */
inline unsigned long long strtoull(const char* _Str, char** _EndPtr = nullptr, int _Radix = 10)
{
#if _MSC_VER < 1800
    return ::_strtoui64(_Str, _EndPtr, _Radix);
#else /* _MSC_VER < 1800 */
    return ::strtoull(_Str, _EndPtr, _Radix);
#endif
}
/* overloaded ::strtold */
inline long double strtold(const char* _Str, char** _EndPtr = nullptr)
{
#if _MSC_VER < 1800
    return (long double)::strtod(_Str, _EndPtr);
#else /* _MSC_VER < 1800 */
    return ::strtold(_Str, _EndPtr);
#endif
}
/* overloaded ::strtof */
inline float strtof(const char* _Str, char** _EndPtr = nullptr)
{
#if _MSC_VER < 1800
    return (float)::strtod(_Str, _EndPtr);
#else /* _MSC_VER < 1800 */
    return ::strtof(_Str, _EndPtr);
#endif
}

/* overloaded ::wcstod */
inline double strtod(const wchar_t* _Str, wchar_t** _EndPtr = nullptr)
{
    return ::wcstod(_Str, _EndPtr);
}
/* overloaded ::wcstol */
inline long strtol(const wchar_t* _Str, wchar_t** _EndPtr = nullptr, int _Radix = 10)
{
    return ::wcstol(_Str, _EndPtr, _Radix);
}
/* overloaded ::wcstoll */
inline long long strtoll(const wchar_t* _Str, wchar_t** _EndPtr = nullptr, int _Radix = 10)
{
#if _MSC_VER < 1800
    return ::_wcstoi64(_Str, _EndPtr, _Radix);
#else /* _MSC_VER < 1800 */
    return ::wcstoll(_Str, _EndPtr, _Radix);
#endif
}
/* overloaded ::wcstoul */
inline unsigned long strtoul(const wchar_t* _Str, wchar_t** _EndPtr = nullptr, int _Radix = 10)
{
    return ::wcstoul(_Str, _EndPtr, _Radix);
}
/* overloaded ::wcstoull */
inline unsigned long long strtoull(const wchar_t* _Str, wchar_t** _EndPtr = nullptr, int _Radix = 10)
{
#if _MSC_VER < 1800
    return ::_wcstoui64(_Str, _EndPtr, _Radix);
#else /* _MSC_VER < 1800 */
    return ::wcstoull(_Str, _EndPtr, _Radix);
#endif
}
/* overloaded ::wcstold */
inline long double strtold(const wchar_t* _Str, wchar_t** _EndPtr = nullptr)
{
#if _MSC_VER < 1800
    return (long double)::wcstod(_Str, _EndPtr);
#else /* _MSC_VER < 1800 */
    return ::wcstold(_Str, _EndPtr);
#endif
}
/* overloaded ::wcstof */
inline float strtof(const wchar_t* _Str, wchar_t** _EndPtr = nullptr)
{
#if _MSC_VER < 1800
    return (float)::wcstod(_Str, _EndPtr);
#else /* _MSC_VER < 1800 */
    return ::wcstof(_Str, _EndPtr);
#endif
}

/* overloaded ::strlen */
inline size_t strlen(const char* _Str)
{
    return ::strlen(_Str);
}
/* overloaded ::wcslen */
inline size_t strlen(const wchar_t* _Str)
{
    return ::wcslen(_Str);
}

/* overloaded ::_stricmp */
inline int stricmp(const char* _Str1, const char* _Str2)
{
    return ::_stricmp(_Str1, _Str2);
}
/* overloaded ::_wcsicmp */
inline int stricmp(const wchar_t* _Str1, const wchar_t* _Str2)
{
    return ::_wcsicmp(_Str1, _Str2);
}

/* overloaded ::_vsnprintf_s */
inline size_t _sprintf(char* _DstBuf, size_t _SizeInBytes, const char* _Format, ...)
{
    assert(_DstBuf);
    assert(_Format);
    va_list arglist;
    va_start(arglist, _Format);
    return (size_t)::_vsnprintf_s(_DstBuf, _SizeInBytes, _TRUNCATE, _Format, arglist);
}
/* overloaded ::_vsnprintf_s */
template<size_t _Size> inline size_t _sprintf(char(&_Dest)[_Size], const char* _Format, ...)
{
    assert(_Format);
    va_list arglist;
    va_start(arglist, _Format);
    return (size_t)::_vsnprintf_s(_Dest, _TRUNCATE, _Format, arglist);
}

/* overloaded ::_vsnwprintf_s */
inline size_t _sprintf(wchar_t* _DstBuf, size_t _SizeInBytes, const wchar_t* _Format, ...)
{
    assert(_DstBuf);
    assert(_Format);
    va_list arglist;
    va_start(arglist, _Format);
    return (size_t)::_vsnwprintf_s(_DstBuf, _SizeInBytes, _TRUNCATE, _Format, arglist);
}
/* overloaded ::_vsnwprintf_s */
template<size_t _Size> inline size_t _sprintf(wchar_t(&_Dest)[_Size], const wchar_t* _Format, ...)
{
    assert(_Format);
    va_list arglist;
    va_start(arglist, _Format);
    return (size_t)::_vsnwprintf_s(_Dest, _TRUNCATE, _Format, arglist);
}

/* overloaded ::puts */
inline size_t puts(const char* _Str)
{
    assert(_Str);
    return (size_t)::puts(_Str);
}
/* overloaded ::_putws */
inline size_t puts(const wchar_t* _Str)
{
    assert(_Str);
    return (size_t)::_putws(_Str);
}

/* overloaded ::vprintf_s */
inline size_t _printf(const char* _Format, ...)
{
    assert(_Format);
    va_list arglist;
    va_start(arglist, _Format);
    return (size_t)::vprintf_s(_Format, arglist);
}
/* overloaded ::vwprintf_s */
inline size_t _printf(const wchar_t* _Format, ...)
{
    assert(_Format);
    va_list arglist;
    va_start(arglist, _Format);
    return (size_t)::vwprintf_s(_Format, arglist);
}

/* overloaded ::fputc */
inline size_t fputc(FILE* _File, char _Ch)
{
    assert(_File);
    return (size_t)::fputc((int)_Ch, _File);
}
/* overloaded ::fputwc */
inline size_t fputc(FILE* _File, wchar_t _Ch)
{
    assert(_File);
    return (size_t)::fputwc(_Ch, _File);
}

/* overloaded ::fputs */
inline size_t fputs(FILE* _File, const char* _Str)
{
    assert(_File);
    assert(_Str);
    return (size_t)::fputs(_Str, _File);
}
/* overloaded ::fputws */
inline size_t fputs(FILE* _File, const wchar_t* _Str)
{
    assert(_File);
    assert(_Str);
    return (size_t)::fputws(_Str, _File);
}

/* overloaded ::vfprintf_s */
inline size_t _fprintf(FILE* _File, const char* _Format, ...)
{
    assert(_File);
    assert(_Format);
    va_list arglist;
    va_start(arglist, _Format);
    return (size_t)::vfprintf_s(_File, _Format, arglist);
}
/* overloaded ::vfwprintf_s */
inline size_t _fprintf(FILE* _File, const wchar_t* _Format, ...)
{
    assert(_File);
    assert(_Format);
    va_list arglist;
    va_start(arglist, _Format);
    return (size_t)::vfwprintf_s(_File, _Format, arglist);
}

_STDEX_STDC_END _STDEX_MY_END _STDEX_END


#endif /* _STRINGPRINTF_H_ */

#endif /* _STRINGPRINTF_CRUNTIME_H_ */
