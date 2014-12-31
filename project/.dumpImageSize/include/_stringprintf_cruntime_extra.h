#ifndef _STRINGPRINTF_CRUNTIME_EXTRA_H_
#define _STRINGPRINTF_CRUNTIME_EXTRA_H_

#ifdef _STRINGPRINTF_H_


/* using C++ objects */
_STDEX_BEGIN _STDEX_MY_BEGIN

/* overloaded for basic_string */
template<typename T> inline int chdir(T&& _Path, int _FileMode = 0755)
{
    static_assert(is_string<T>::value || is_wstring<T>::value, "_Str is NOT a string");
    return _STDEX_STDC chdir(string_forward(_Path));
}
/* overloaded for basic_string */
template<typename T> inline int mkdir(T&& _Path, int _FileMode = 0755)
{
    static_assert(is_string<T>::value || is_wstring<T>::value, "_Str is NOT a string");
    return _STDEX_STDC mkdir(string_forward(_Path));
}
/* overloaded for basic_string */
template<typename T> inline int rmdir(T&& _Path, int _FileMode = 0755)
{
    static_assert(is_string<T>::value || is_wstring<T>::value, "_Str is NOT a string");
    return _STDEX_STDC rmdir(string_forward(_Path));
}

/* overloaded for basic_string */
template<typename T> inline double strtod(T&& _Str, typename is_wstring<T>::_Elem** _EndPtr = nullptr)
{
    static_assert(is_string<T>::value || is_wstring<T>::value, "_Str is NOT a string");
    return _STDEX_STDC strtod(string_forward(_Str), _EndPtr);
}
/* overloaded for basic_string and char*& */
template<typename T> inline double strtod(T&& _Str, typename is_wstring<T>::_Elem*& _EndPtrRef)
{
    return _STDEX_STDC strtod(string_forward(_Str), &_EndPtrRef);
}
/* overloaded for basic_string and size_t& */
template<typename T> inline double strtod(T&& _Str, size_t& _Idx)
{
    const typename is_wstring<T>::_Elem* _pStr = string_forward(_Str);
    typename is_wstring<T>::_Elem* _EndPtr;
    auto _Ans = _STDEX_STDC strtod(_pStr, &_EndPtr);
    _Idx = _EndPtr - _pStr;
    return _Ans;
}

/* overloaded for basic_string */
template<typename T> inline long strtol(T&& _Str, typename is_wstring<T>::_Elem** _EndPtr = nullptr, int _Radix = 10)
{
    static_assert(is_string<T>::value || is_wstring<T>::value, "_Str is NOT a string");
    return _STDEX_STDC strtol(string_forward(_Str), _EndPtr, _Radix);
}
/* overloaded for basic_string and char*& */
template<typename T> inline long strtol(T&& _Str, typename is_wstring<T>::_Elem*& _EndPtrRef, int _Radix = 10)
{
    return _STDEX_STDC strtol(string_forward(_Str), &_EndPtrRef, _Radix);
}
/* overloaded for basic_string and size_t& */
template<typename T> inline long strtol(T&& _Str, size_t& _Idx, int _Radix = 10)
{
    const typename is_wstring<T>::_Elem* _pStr = string_forward(_Str);
    typename is_wstring<T>::_Elem* _EndPtr;
    auto _Ans = _STDEX_STDC strtol(_pStr, &_EndPtr, _Radix);
    _Idx = _EndPtr - _pStr;
    return _Ans;
}

/* overloaded for basic_string */
template<typename T> inline long long strtoll(T&& _Str, typename is_wstring<T>::_Elem** _EndPtr = nullptr, int _Radix = 10)
{
    static_assert(is_string<T>::value || is_wstring<T>::value, "_Str is NOT a string");
    return _STDEX_STDC strtoll(string_forward(_Str), _EndPtr, _Radix);
}
/* overloaded for basic_string and char*& */
template<typename T> inline long long strtoll(T&& _Str, typename is_wstring<T>::_Elem*& _EndPtrRef, int _Radix = 10)
{
    return _STDEX_STDC strtoll(string_forward(_Str), &_EndPtrRef, _Radix);
}
/* overloaded for basic_string and size_t& */
template<typename T> inline long long strtoll(T&& _Str, size_t& _Idx, int _Radix = 10)
{
    const typename is_wstring<T>::_Elem* _pStr = string_forward(_Str);
    typename is_wstring<T>::_Elem* _EndPtr;
    auto _Ans = _STDEX_STDC strtoll(_pStr, &_EndPtr, _Radix);
    _Idx = _EndPtr - _pStr;
    return _Ans;
}

/* overloaded for basic_string */
template<typename T> inline unsigned long strtoul(T&& _Str, typename is_wstring<T>::_Elem** _EndPtr = nullptr, int _Radix = 10)
{
    static_assert(is_string<T>::value || is_wstring<T>::value, "_Str is NOT a string");
    return _STDEX_STDC strtoul(string_forward(_Str), _EndPtr, _Radix);
}
/* overloaded for basic_string and char*& */
template<typename T> inline unsigned long strtoul(T&& _Str, typename is_wstring<T>::_Elem*& _EndPtrRef, int _Radix = 10)
{
    return _STDEX_STDC strtoul(string_forward(_Str), &_EndPtrRef, _Radix);
}
/* overloaded for basic_string and size_t& */
template<typename T> inline unsigned long strtoul(T&& _Str, size_t& _Idx, int _Radix = 10)
{
    const typename is_wstring<T>::_Elem* _pStr = string_forward(_Str);
    typename is_wstring<T>::_Elem* _EndPtr;
    auto _Ans = _STDEX_STDC strtoul(_pStr, &_EndPtr, _Radix);
    _Idx = _EndPtr - _pStr;
    return _Ans;
}

/* overloaded for basic_string */
template<typename T> inline unsigned long long strtoull(T&& _Str, typename is_wstring<T>::_Elem** _EndPtr = nullptr, int _Radix = 10)
{
    static_assert(is_string<T>::value || is_wstring<T>::value, "_Str is NOT a string");
    return _STDEX_STDC strtoull(string_forward(_Str), _EndPtr, _Radix);
}
/* overloaded for basic_string and char*& */
template<typename T> inline unsigned long long strtoull(T&& _Str, typename is_wstring<T>::_Elem*& _EndPtrRef, int _Radix = 10)
{
    return _STDEX_STDC strtoull(string_forward(_Str), &_EndPtrRef, _Radix);
}
/* overloaded for basic_string and size_t& */
template<typename T> inline unsigned long long strtoull(T&& _Str, size_t& _Idx, int _Radix = 10)
{
    const typename is_wstring<T>::_Elem* _pStr = string_forward(_Str);
    typename is_wstring<T>::_Elem* _EndPtr;
    auto _Ans = _STDEX_STDC strtoull(_pStr, &_EndPtr, _Radix);
    _Idx = _EndPtr - _pStr;
    return _Ans;
}

/* overloaded for basic_string */
template<typename T> inline long double strtold(T&& _Str, typename is_wstring<T>::_Elem** _EndPtr = nullptr)
{
    static_assert(is_string<T>::value || is_wstring<T>::value, "_Str is NOT a string");
    return _STDEX_STDC strtold(string_forward(_Str), _EndPtr);
}
/* overloaded for basic_string and char*& */
template<typename T> inline long double strtold(T&& _Str, typename is_wstring<T>::_Elem*& _EndPtrRef)
{
    return _STDEX_STDC strtold(string_forward(_Str), &_EndPtrRef);
}
/* overloaded for basic_string and size_t& */
template<typename T> inline long double strtold(T&& _Str, size_t& _Idx)
{
    const typename is_wstring<T>::_Elem* _pStr = string_forward(_Str);
    typename is_wstring<T>::_Elem* _EndPtr;
    auto _Ans = _STDEX_STDC strtold(_pStr, &_EndPtr);
    _Idx = _EndPtr - _pStr;
    return _Ans;
}

/* overloaded for basic_string */
template<typename T> inline float strtof(T&& _Str, typename is_wstring<T>::_Elem** _EndPtr = nullptr)
{
    static_assert(is_string<T>::value || is_wstring<T>::value, "_Str is NOT a string");
    return _STDEX_STDC strtof(string_forward(_Str), _EndPtr);
}
/* overloaded for basic_string and char*& */
template<typename T> inline float strtof(T&& _Str, typename is_wstring<T>::_Elem*& _EndPtrRef)
{
    return _STDEX_STDC strtof(string_forward(_Str), &_EndPtrRef);
}
/* overloaded for basic_string and size_t& */
template<typename T> inline float strtof(T&& _Str, size_t& _Idx)
{
    const typename is_wstring<T>::_Elem* _pStr = string_forward(_Str);
    typename is_wstring<T>::_Elem* _EndPtr;
    auto _Ans = _STDEX_STDC strtof(_pStr, &_EndPtr);
    _Idx = _EndPtr - _pStr;
    return _Ans;
}

/* overloaded for basic_string */
template<typename T> inline size_t strlen(T&& _Str)
{
    static_assert(is_string<T>::value || is_wstring<T>::value, "_Str is NOT a string");
    return _STDEX_STDC strlen(string_forward(_Str));
}

/* overloaded for basic_string */
template<typename _Ty1, typename _Ty2> inline int stricmp(_Ty1&& _Str1, _Ty2&& _Str2)
{
    static_assert(is_string<_Ty1>::value || is_wstring<_Ty1>::value, "_Str1 is NOT a string");
    static_assert(is_string<_Ty2>::value || is_wstring<_Ty2>::value, "_Str2 is NOT a string");
    static_assert(_STD is_same<typename is_wstring<_Ty1>::_Elem, typename is_wstring<_Ty2>::_Elem>::value, "_Str2 do not match _Str1 element");
    return _STDEX_STDC stricmp(string_forward(_Str1), string_forward(_Str2));
}

/* overloaded for basic_ostream and basic_string */
template<typename _Elem, typename _Traits, typename T> inline size_t fputc(_STD basic_ostream<_Elem, _Traits>& _Out, T&& _Ch)
{
    static_assert(is_string<_Elem*>::value || is_wstring<_Elem*>::value, "Bad string element");
    static_assert(is_string<T*>::value || is_wstring<T*>::value, "_Ch is NOT a char");
    static_assert(_STD is_same<_Elem, typename is_wstring<T*>::_Elem>::value, "_Out do not match _Ch");
    _Out.put(_Ch);
    return (size_t)_Ch;
}
/* overloaded for FILE* and basic_string */
template<typename T> inline size_t fputc(FILE* _File, T&& _Ch)
{
    assert(_File);
    static_assert(is_string<T*>::value || is_wstring<T*>::value, "_Ch is NOT a char");
    return _STDEX_STDC fputc(_File, typename is_wstring<T*>::_Elem(_Ch));
}
#if HAVE_WINDOWS
/* overloaded for csys_t and basic_string */
template<typename T> inline size_t fputc(csys_t& _csys, T&& _Ch)
{
    static_assert(is_string<T*>::value || is_wstring<T*>::value, "_Ch is NOT a char");
    typename is_wstring<T*>::_Elem buffer[2];
    buffer[0] = _Ch;
    buffer[1] = typename is_wstring<T*>::_Elem('\0');
    _STDEX_WINDOWS OutputDebugString(string_forward(buffer));
    return (size_t)_Ch;
}

#endif /* HAVE_WINDOWS */

/* overloaded basic_string */
template<typename T> inline size_t puts(T&& _Str)
{
    static_assert(is_string<T>::value || is_wstring<T>::value, "_Str is NOT a string");
    return _STDEX_STDC puts(string_forward(_Str));
}

/* overloaded for basic_ostream and basic_string */
template<typename _Elem, typename _Traits, typename T> inline size_t fputs(_STD basic_ostream<_Elem, _Traits>& _Out, T&& _Str)
{
    static_assert(is_string<_Elem*>::value || is_wstring<_Elem*>::value, "Bad string element");
    static_assert(is_string<T>::value || is_wstring<T>::value, "_Str is NOT a string");
    static_assert(_STD is_same<_Elem, typename is_wstring<T>::_Elem>::value, "_Out do not match _Str element");
    _Out << _Str;
    return string_size(_Str);
}
/* overloaded for FILE* and basic_string */
template<typename T> inline size_t fputs(FILE* _File, T&& _Str)
{
    assert(_File);
    static_assert(is_string<T>::value || is_wstring<T>::value, "_Str is NOT a string");
    return _STDEX_STDC fputs(_File, string_forward(_Str));
}
#if HAVE_WINDOWS
/* overloaded for csys_t and basic_string */
template<typename T> inline size_t fputs(csys_t& _csys, T&& _Str)
{
    static_assert(is_string<T>::value || is_wstring<T>::value, "_Str is NOT a string");
    _STDEX_WINDOWS OutputDebugString(string_forward(_Str));
    return string_size(_Str);
}
/* overloaded for csys_t and operator<< */
template<typename T> inline csys_t& operator<<(csys_t& _Out, T&& _Val)
{
    static_assert(is_string<T>::value || is_wstring<T>::value, "_Val is NOT a string");
    fputs(_Out, _STD forward<T>(_Val));
    return _Out;
}

#endif /* HAVE_WINDOWS */

_STDEX_STDC_USING;

_STDEX_MY_END

FUNCTION_OBJECT_2_1(chdir)
FUNCTION_OBJECT_2_1(mkdir)
FUNCTION_OBJECT_2_1(rmdir)

FUNCTION_OBJECT_1(isalpha)
FUNCTION_OBJECT_1(isupper)
FUNCTION_OBJECT_1(islower)
FUNCTION_OBJECT_1(isdigit)
FUNCTION_OBJECT_1(isxdigit)
FUNCTION_OBJECT_1(isspace)
FUNCTION_OBJECT_1(ispunct)
FUNCTION_OBJECT_1(isblank)
FUNCTION_OBJECT_1(isalnum)
FUNCTION_OBJECT_1(isprint)
FUNCTION_OBJECT_1(isgraph)
FUNCTION_OBJECT_1(iscntrl)

FUNCTION_OBJECT_1(toupper)
FUNCTION_OBJECT_1(tolower)

FUNCTION_OBJECT_2_1(strtod)
FUNCTION_OBJECT_3_1(strtol)
FUNCTION_OBJECT_3_1(strtoll)
FUNCTION_OBJECT_3_1(strtoul)
FUNCTION_OBJECT_3_1(strtoull)
FUNCTION_OBJECT_2_1(strtold)
FUNCTION_OBJECT_2_1(strtof)

FUNCTION_OBJECT_1(strlen)
FUNCTION_OBJECT_2(stricmp)

FUNCTION_OBJECT_MAX_2(_sprintf)
FUNCTION_OBJECT_1(puts)
FUNCTION_OBJECT_MAX_1(_printf)

FUNCTION_OBJECT_2(fputc)
FUNCTION_OBJECT_2(fputs)
FUNCTION_OBJECT_MAX_2(_fprintf)

_STDEX_MY_USING;

_STDEX_END


#endif /* _STRINGPRINTF_H_ */

#endif /* _STRINGPRINTF_CRUNTIME_EXTRA_H_ */
