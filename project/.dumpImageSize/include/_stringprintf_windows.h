#ifndef _STRINGPRINTF_WINDOWS_H_
#define _STRINGPRINTF_WINDOWS_H_

#if defined(_STRINGPRINTF_H_) && HAVE_WINDOWS


#ifndef _WINSOCKAPI_
#include <WinSock2.h>  /* Prevent inclusion of winsock.h in windows.h */
#endif
#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN
#endif
#include <Windows.h>

#define _STDEX_WINDOWS_BEGIN    namespace windows { /* must in ::stdex::my:: */
#define _STDEX_WINDOWS_END      }
#define _STDEX_WINDOWS          _STDEX_MY windows::
#define _STDEX_WINDOWS_USING    _STDEX_MY_USING ::windows


_STDEX_BEGIN

_STDEX_TYPE_BEGIN
struct timezone
{
    int tz_minuteswest;
    int tz_dsttime;
};
_STDEX_TYPE_END

/* overloaded Windows API */
_STDEX_MY_BEGIN _STDEX_WINDOWS_BEGIN

using _STDEX_TYPE timezone;
/* implement gettimeofday */
inline int gettimeofday(struct timeval* tv, struct timezone* tz)
{
    if (tv)
    {
        union {
            FILETIME ft;
            DWORD64  ut;
        } filetime;
        DWORD64 time_now;
        static const DWORD64 EPOCH_BIAS = 116444736000000000; /*1970/01/01*/
        ::GetSystemTimeAsFileTime(&filetime.ft);
        time_now = filetime.ut - EPOCH_BIAS;
        tv->tv_sec = (long)(time_now / 10000000ULL);
        tv->tv_usec = (long)((time_now % 10000000ULL) / 10ULL);
    }
    if (tz)
    {
        TIME_ZONE_INFORMATION TimeZoneInformation;
        ::GetTimeZoneInformation(&TimeZoneInformation);
        tz->tz_dsttime = (int)TimeZoneInformation.DaylightBias;
        tz->tz_minuteswest = (int)TimeZoneInformation.Bias;
    }
    return 0;
}

#undef OutputDebugString
/* overloaded ::OutputDebugStringA */
inline void OutputDebugString(const char* lpOutputString)
{
    assert(lpOutputString);
    ::OutputDebugStringA(lpOutputString);
}
/* overloaded ::OutputDebugStringW */
inline void OutputDebugString(const wchar_t* lpOutputString)
{
    assert(lpOutputString);
    ::OutputDebugStringW(lpOutputString);
}

#undef CreateMutex
/* overloaded ::CreateMutexA */
inline HANDLE CreateMutex(LPSECURITY_ATTRIBUTES lpMutexAttributes, BOOL bInitialOwner, const char* lpName)
{
    return ::CreateMutexA(lpMutexAttributes, bInitialOwner, lpName);
}
/* overloaded ::CreateMutexW */
inline HANDLE CreateMutex(LPSECURITY_ATTRIBUTES lpMutexAttributes, BOOL bInitialOwner, const wchar_t* lpName)
{
    return ::CreateMutexW(lpMutexAttributes, bInitialOwner, lpName);
}

#undef CreateEvent
/* overloaded ::CreateEventA */
inline HANDLE CreateEvent(LPSECURITY_ATTRIBUTES lpEventAttributes, BOOL bManualReset, BOOL bInitialState, const char* lpName)
{
    return ::CreateEventA(lpEventAttributes, bManualReset, bInitialState, lpName);
}
/* overloaded ::CreateEventW */
inline HANDLE CreateEvent(LPSECURITY_ATTRIBUTES lpEventAttributes, BOOL bManualReset, BOOL bInitialState, const wchar_t* lpName)
{
    return ::CreateEventW(lpEventAttributes, bManualReset, bInitialState, lpName);
}

#undef CreateFile
/* overloaded ::CreateFileA */
inline HANDLE CreateFile(const char* lpFileName, DWORD dwDesiredAccess, DWORD dwShareMode, LPSECURITY_ATTRIBUTES lpSecurityAttributes, DWORD dwCreationDisposition, DWORD dwFlagsAndAttributes, HANDLE hTemplateFile)
{
    return ::CreateFileA(lpFileName, dwDesiredAccess, dwShareMode, lpSecurityAttributes, dwCreationDisposition, dwFlagsAndAttributes, hTemplateFile);
}
/* overloaded ::CreateFileW */
inline HANDLE CreateFile(const wchar_t* lpFileName, DWORD dwDesiredAccess, DWORD dwShareMode, LPSECURITY_ATTRIBUTES lpSecurityAttributes, DWORD dwCreationDisposition, DWORD dwFlagsAndAttributes, HANDLE hTemplateFile)
{
    return ::CreateFileW(lpFileName, dwDesiredAccess, dwShareMode, lpSecurityAttributes, dwCreationDisposition, dwFlagsAndAttributes, hTemplateFile);
}

#undef GetFullPathName
/* overloaded ::GetFullPathNameA */
inline size_t GetFullPathName(const char* lpFileName, size_t nBufferLength, char* lpBuffer, char** lpFilePart)
{
    assert(lpFileName);
    return (size_t)::GetFullPathNameA(lpFileName, (DWORD)nBufferLength, lpBuffer, lpFilePart);
}
/* overloaded ::GetFullPathNameW */
inline size_t GetFullPathName(const wchar_t* lpFileName, size_t nBufferLength, wchar_t* lpBuffer, wchar_t** lpFilePart)
{
    assert(lpFileName);
    return (size_t)::GetFullPathNameW(lpFileName, (DWORD)nBufferLength, lpBuffer, lpFilePart);
}

_STDEX_WINDOWS_END _STDEX_MY_END _STDEX_END


#endif /* defined(_STRINGPRINTF_H_) && HAVE_WINDOWS */

#endif /* _STRINGPRINTF_WINDOWS_H_ */
