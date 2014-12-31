#ifndef _STRINGPRINTF_WINDOWS_EXTRA_H_
#define _STRINGPRINTF_WINDOWS_EXTRA_H_

#if defined(_STRINGPRINTF_H_) && HAVE_WINDOWS


/* using C++ objects */
_STDEX_BEGIN _STDEX_MY_BEGIN

/* overloaded for basic_string */
template<typename T> inline void OutputDebugString(T&& OutputString)
{
    static_assert(is_string<T>::value || is_wstring<T>::value, "OutputString is NOT a string");
    _STDEX_WINDOWS OutputDebugString(string_forward(OutputString));
}

/* overloaded for basic_string */
template<typename T> inline HANDLE CreateMutex(LPSECURITY_ATTRIBUTES lpMutexAttributes, BOOL bInitialOwner, T&& Name)
{
    static_assert(is_string<T>::value || is_wstring<T>::value, "Name is NOT a string");
    return _STDEX_WINDOWS CreateMutex(lpMutexAttributes, bInitialOwner, string_forward(Name));
}
/* overloaded for empty name */
inline HANDLE CreateMutex(LPSECURITY_ATTRIBUTES lpMutexAttributes, BOOL bInitialOwner)
{
    return _STDEX_WINDOWS CreateMutex(lpMutexAttributes, bInitialOwner, string_forward(nullptr));
}

/* overloaded for basic_string */
template<typename T> inline HANDLE CreateEvent(LPSECURITY_ATTRIBUTES lpEventAttributes, BOOL bManualReset, BOOL bInitialState, T&& Name)
{
    static_assert(is_string<T>::value || is_wstring<T>::value, "Name is NOT a string");
    return _STDEX_WINDOWS CreateEvent(lpEventAttributes, bManualReset, bInitialState, string_forward(Name));
}
/* overloaded for empty name */
inline HANDLE CreateEvent(LPSECURITY_ATTRIBUTES lpEventAttributes, BOOL bManualReset, BOOL bInitialState)
{
    return _STDEX_WINDOWS CreateEvent(lpEventAttributes, bManualReset, bInitialState, string_forward(nullptr));
}

/* overloaded for basic_string */
template<typename T> inline HANDLE CreateFile(T&& FileName, DWORD dwDesiredAccess = GENERIC_READ, DWORD dwShareMode = FILE_SHARE_READ, LPSECURITY_ATTRIBUTES lpSecurityAttributes = nullptr, DWORD dwCreationDisposition = OPEN_EXISTING, DWORD dwFlagsAndAttributes = NULL, HANDLE hTemplateFile = nullptr)
{
    static_assert(is_string<T>::value || is_wstring<T>::value, "FileName is NOT a string");
    return _STDEX_WINDOWS CreateFile(string_forward(FileName), dwDesiredAccess, dwShareMode, lpSecurityAttributes, dwCreationDisposition, dwFlagsAndAttributes, hTemplateFile);
}

template<typename T> inline
/* return pair<FullPath or Original FileName, !!Successed> */
auto GetFullPathName(T&& FileName) -> _STD pair<typename is_wstring<T>::type, bool>
{
    static_assert(is_string<T>::value || is_wstring<T>::value, "FileName is NOT a string");
    size_t result, length = string_size(FileName) + _STDEX_TYPE BUFFER_LENGTH - 1;
    typename is_wstring<T>::type buf(length = length / _STDEX_TYPE BUFFER_LENGTH * _STDEX_TYPE BUFFER_LENGTH - 1,
        typename is_wstring<T>::_Elem());
    while (length + 1 < (result = _STDEX_WINDOWS GetFullPathName(string_forward(FileName), length + 1, const_cast<typename is_wstring<T>::_Elem*>(buf.data()), nullptr)))
        buf.resize(length = (result + _STDEX_TYPE BUFFER_LENGTH) / _STDEX_TYPE BUFFER_LENGTH * _STDEX_TYPE BUFFER_LENGTH - 1);
    if (result)
    {
        assert(result <= length);
        if (result < length)
            buf.resize(result);
        return _STD make_pair(_STD move(buf), true);
    }
    else
        return _STD make_pair(_STD forward<T>(FileName), false);
}

template<typename _Elem DEF_VALUE(char), typename _Traits DEF_VALUE(_STD char_traits<_Elem>), typename _Alloc DEF_VALUE(_STD allocator<_Elem>), typename T> inline
/* return MultiByteStr */
auto WideCharToMultiByte(T&& WideCharStr, UINT CodePage = CP_ACP) -> _STD basic_string<_Elem, _Traits, _Alloc>
{
    static_assert(is_wstring<T>::value, "WideCharStr is NOT a wstring");
    size_t length = (size_t)::WideCharToMultiByte(CodePage, NULL, string_forward(WideCharStr), string_size(WideCharStr),
        nullptr, 0, nullptr, nullptr);
    if (0 == length)
        return _STD basic_string<_Elem, _Traits, _Alloc>();
    length = (length + sizeof(_Elem) - 1) / sizeof(_Elem) + _STDEX_TYPE BUFFER_LENGTH;
    _STD basic_string<_Elem, _Traits, _Alloc> buf(length = length / _STDEX_TYPE BUFFER_LENGTH * _STDEX_TYPE BUFFER_LENGTH - 1, _Elem());
    size_t result = (size_t)::WideCharToMultiByte(CodePage, NULL, string_forward(WideCharStr), string_size(WideCharStr),
        (char*)(const_cast<_Elem*>(buf.c_str())), int(length * sizeof(_Elem)), nullptr, nullptr);
    result = (result + sizeof(_Elem) - 1) / sizeof(_Elem);
    assert(result <= length);
    if (result < length)
        buf.resize(result);
    return move(buf);
}

template<typename _Elem DEF_VALUE(wchar_t), typename _Traits DEF_VALUE(_STD char_traits<_Elem>), typename _Alloc DEF_VALUE(_STD allocator<_Elem>), typename T> inline
/* return WideCharStr */
auto MultiByteToWideChar(T&& MultiByteStr, UINT CodePage = CP_ACP) -> _STD basic_string<_Elem, _Traits, _Alloc>
{
    static_assert(is_string<T>::value, "MultiByteStr is NOT a string");
    size_t length = (size_t)::MultiByteToWideChar(CodePage, NULL, string_forward(MultiByteStr), string_size(MultiByteStr), nullptr, 0);
    if (0 == length)
        return _STD basic_string<_Elem, _Traits, _Alloc>();
    length = (length * sizeof(wchar_t) + (sizeof(_Elem) - 1) / sizeof(wchar_t) * sizeof(wchar_t)) / sizeof(_Elem) +
        _STDEX_TYPE BUFFER_LENGTH;
    _STD basic_string<_Elem, _Traits, _Alloc> buf(length = length / _STDEX_TYPE BUFFER_LENGTH * _STDEX_TYPE BUFFER_LENGTH - 1, _Elem());
    size_t result = (size_t)::MultiByteToWideChar(CodePage, NULL, string_forward(MultiByteStr), string_size(MultiByteStr),
        (wchar_t*)(const_cast<_Elem*>(buf.c_str())), int(length * sizeof(_Elem) / sizeof(wchar_t)));
    result = (result * sizeof(wchar_t) + (sizeof(_Elem) - 1) / sizeof(wchar_t) * sizeof(wchar_t)) / sizeof(_Elem);
    assert(result <= length);
    if (result < length)
        buf.resize(result);
    return move(buf);
}


#if _MSC_VER < 1800
template<typename T> inline auto
WideCharToMultiByte(T&& WideCharStr, UINT CodePage = CP_ACP) -> _STD basic_string<char, _STD char_traits<char>, _STD allocator<char> >
{
    return WideCharToMultiByte<char, _STD char_traits<char>, _STD allocator<char> >(_STD forward<T>(WideCharStr), CodePage);
}
template<typename _Elem, typename T> inline auto
WideCharToMultiByte(T&& WideCharStr, UINT CodePage = CP_ACP) -> _STD basic_string<_Elem, _STD char_traits<_Elem>, _STD allocator<_Elem> >
{
    return WideCharToMultiByte<_Elem, _STD char_traits<_Elem>, _STD allocator<_Elem> >(_STD forward<T>(WideCharStr), CodePage);
}
template<typename _Elem, typename _Traits, typename T> inline auto
WideCharToMultiByte(T&& WideCharStr, UINT CodePage = CP_ACP) -> _STD basic_string<_Elem, _Traits, _STD allocator<_Elem> >
{
    return WideCharToMultiByte<_Elem, _Traits, _STD allocator<_Elem> >(_STD forward<T>(WideCharStr), CodePage);
}

template<typename T> inline auto
MultiByteToWideChar(T&& MultiByteStr, UINT CodePage = CP_ACP) -> _STD basic_string<wchar_t, _STD char_traits<wchar_t>, _STD allocator<wchar_t> >
{
    return MultiByteToWideChar<wchar_t, _STD char_traits<wchar_t>, _STD allocator<wchar_t> >(_STD forward<T>(MultiByteStr), CodePage);
}
template<typename _Elem, typename T> inline auto
MultiByteToWideChar(T&& MultiByteStr, UINT CodePage = CP_ACP) -> _STD basic_string<_Elem, _STD char_traits<_Elem>, _STD allocator<_Elem> >
{
    return MultiByteToWideChar<_Elem, _STD char_traits<_Elem>, _STD allocator<_Elem> >(_STD forward<T>(MultiByteStr), CodePage);
}
template<typename _Elem, typename _Traits, typename T> inline auto
MultiByteToWideChar(T&& MultiByteStr, UINT CodePage = CP_ACP) -> _STD basic_string<_Elem, _Traits, _STD allocator<_Elem> >
{
    return MultiByteToWideChar<_Elem, _Traits, _STD allocator<_Elem> >(_STD forward<T>(MultiByteStr), CodePage);
}

#endif /* _MSC_VER < 1800 */

_STDEX_WINDOWS_USING;

_STDEX_MY_END

FUNCTION_OBJECT_2(gettimeofday)
FUNCTION_OBJECT_1(OutputDebugString)
FUNCTION_OBJECT_3_2(CreateMutex)
FUNCTION_OBJECT_4_3(CreateEvent)
FUNCTION_OBJECT_7_1(CreateFile)
FUNCTION_OBJECT_1(GetFullPathName)
FUNCTION_OBJECT_2_1(WideCharToMultiByte)
FUNCTION_OBJECT_2_1(MultiByteToWideChar)

_STDEX_MY_USING;

_STDEX_END


#endif /* defined(_STRINGPRINTF_H_) && HAVE_WINDOWS */

#endif /* _STRINGPRINTF_WINDOWS_EXTRA_H_ */
