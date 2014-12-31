// stringprintf header
#pragma once

/*  Support vs2010(vc10.0) and later, maybe support vs2008(vc9.0)
 *      By Wanpeng Song <swpustc@mail.ustc.edu.cn>
*/

#ifndef _STRINGPRINTF_H_
#define _STRINGPRINTF_H_

#ifdef __cplusplus

#include <crtdefs.h>
#include <cassert>
#include <string>
#include <locale>
#include <ostream>
#include <utility>
#include <algorithm>
#include <functional>


#ifndef _STD_BEGIN
#define _STD_BEGIN              namespace std {
#endif /* _STD_BEGIN */

#ifndef _STD_END
#define _STD_END                }
#endif /* _STD_END */

#ifndef _STD
#define _STD                    ::std::
#endif /* _STD */


#define _STDEX_BEGIN            namespace stdex {
#define _STDEX_END              }
#define _STDEX                  ::stdex::
#define _STDEX_USING            using namespace ::stdex

#define _STDEX_MY_BEGIN         namespace my { /* must in ::stdex:: */
#define _STDEX_MY_END           }
#define _STDEX_MY               _STDEX my::
#define _STDEX_MY_USING         _STDEX_USING ::my


#if defined(_MSC_VER) && !defined(HAVE_WINDOWS)
#define HAVE_WINDOWS 1 /* _MSC_VER is setting */
#endif /* _MSC_VER */


/* string_printf namespace */
_STDEX_BEGIN

/* overloaded stdc and windows function */
_STDEX_MY_BEGIN
_STDEX_MY_END

_STDEX_END


#include <_stringprintf__typedef.h>
#include <_stringprintf_stl.h>
#include <_stringprintf_cruntime.h>
#include <_stringprintf_windows.h>


_STDEX_BEGIN

_STDEX_TYPE_BEGIN
static const size_t BUFFER_LENGTH = 16; // 16 bytes, basic_string minimum memory size
static const size_t MAX_BUFFER_LENGTH = 4 * 1024; // 4 KB, memory page size

_STDEX_TYPE_END


/* for System Debug Output */
#if HAVE_WINDOWS
static csys_t csys;

#endif /* HAVE_WINDOWS */


/* arguments forward template */
template<typename _Ty> inline
/* forward basic_string<_Elem, _Traits, _Alloc> to _Elem* */
auto string_forward(_Ty&& _Arg) -> typename _STDEX_TYPE forward_basic_string<_Ty>::type
{
    return _STDEX_TYPE forward_basic_string<_Ty>::string_forward(_STD forward<_Ty>(_Arg));
}
template<typename _Ty> inline
/* get size of string_type */
auto string_size(_Ty&& _Arg) -> typename _STDEX_TYPE forward_basic_string<_Ty>::size_type
{
    return _STDEX_TYPE forward_basic_string<_Ty>::string_size(_STD forward<_Ty>(_Arg));
}


_STDEX_END

#include <_stringprintf_cruntime_extra.h>
#include <_stringprintf_windows_extra.h>
#include <_stringprintf_stl_extra.h>


_STDEX_BEGIN

/* transform toupper with locale */
template<typename T> inline auto string_toupper(T&& _String, const _STD locale& _Loc) -> typename is_wstring<T>::type
{
    static_assert(is_string<T>::value || is_wstring<T>::value, "_String is NOT a string");
    /* only move() if _String is a rvalue */
    typename is_wstring<T>::type buffer = _STD forward<T>(_String);
    _STD transform(buffer.begin(), buffer.end(), buffer.begin(), _STD bind(_STD toupper<typename is_string<T>::_Elem>, _STD placeholders::_1, _STD cref(_Loc)));
    return _STD move(buffer);
}
/* transform toupper */
template<typename T> inline auto string_toupper(T&& _String) -> typename is_wstring<T>::type
{
    static_assert(is_string<T>::value || is_wstring<T>::value, "_String is NOT a string");
    /* only move() if _String is a rvalue */
    typename is_wstring<T>::type buffer = _STD forward<T>(_String);
    _STD transform(buffer.begin(), buffer.end(), buffer.begin(), toupper());
    return _STD move(buffer);
}

/* transform tolower with locale */
template<typename T> inline auto string_tolower(T&& _String, const _STD locale& _Loc) -> typename is_wstring<T>::type
{
    static_assert(is_string<T>::value || is_wstring<T>::value, "_String is NOT a string");
    /* only move() if _String is a rvalue */
    typename is_wstring<T>::type buffer = _STD forward<T>(_String);
    _STD transform(buffer.begin(), buffer.end(), buffer.begin(), _STD bind(_STD tolower<typename is_string<T>::_Elem>, _STD placeholders::_1, _STD cref(_Loc)));
    return _STD move(buffer);
}
/* transform tolower */
template<typename T> inline auto string_tolower(T&& _String) -> typename is_wstring<T>::type
{
    static_assert(is_string<T>::value || is_wstring<T>::value, "_String is NOT a string");
    /* only move() if _String is a rvalue */
    typename is_wstring<T>::type buffer = _STD forward<T>(_String);
    _STD transform(buffer.begin(), buffer.end(), buffer.begin(), tolower());
    return _STD move(buffer);
}


template<typename _Elem DEF_VALUE(defChar), typename _Traits DEF_VALUE(_STD char_traits<_Elem>), typename _Alloc DEF_VALUE(_STD allocator<_Elem>)> inline
/* transform Guid to string */
_STD basic_string<_Elem, _Traits, _Alloc> Guid_tostring(const GUID& _Guid)
{
    return string_printf(_STDEX_TYPE guid_format<_Elem, _Traits, _Alloc>::string(),
        _Guid.Data1,
        _Guid.Data2,
        _Guid.Data3,
        _Guid.Data4[0], _Guid.Data4[1],
        _Guid.Data4[2], _Guid.Data4[3], _Guid.Data4[4], _Guid.Data4[5], _Guid.Data4[6], _Guid.Data4[7]);
}

template<typename T> inline
/* transform string to Guid */
_STD pair<GUID, bool> string_toGUID(T&& _GuidString)
{
    static_assert(is_string<T>::value || is_wstring<T>::value, "_GuidString is NOT a string");
    if (string_size(_GuidString) != 38)
        return _STD make_pair(GUID(), false);
    else
    {
        /* only move() if _GuidString is a rvalue */
        typename is_wstring<T>::type GuidString = _STD forward<T>(_GuidString);
        typename is_wstring<T>::_Elem* pointer = const_cast<typename is_wstring<T>::_Elem*>(GuidString.c_str());
        if (*(pointer + 0) == typename is_wstring<T>::_Elem('{') &&
            *(pointer + 9) == typename is_wstring<T>::_Elem('-') &&
            *(pointer + 14) == typename is_wstring<T>::_Elem('-') &&
            *(pointer + 19) == typename is_wstring<T>::_Elem('-') &&
            *(pointer + 24) == typename is_wstring<T>::_Elem('-') &&
            *(pointer + 37) == typename is_wstring<T>::_Elem('}') &&
            _STD all_of(pointer + 1, pointer + 9, isxdigit()) &&
            _STD all_of(pointer + 10, pointer + 14, isxdigit()) &&
            _STD all_of(pointer + 15, pointer + 19, isxdigit()) &&
            _STD all_of(pointer + 20, pointer + 24, isxdigit()) &&
            _STD all_of(pointer + 25, pointer + 37, isxdigit()))
        {
            GUID _Guid;
            _Guid.Data4[7] = (uint8_t)strtoul(pointer + 35, nullptr, 16); *(pointer + 35) = 0;
            _Guid.Data4[6] = (uint8_t)strtoul(pointer + 33, nullptr, 16); *(pointer + 33) = 0;
            _Guid.Data4[5] = (uint8_t)strtoul(pointer + 31, nullptr, 16); *(pointer + 31) = 0;
            _Guid.Data4[4] = (uint8_t)strtoul(pointer + 29, nullptr, 16); *(pointer + 29) = 0;
            _Guid.Data4[3] = (uint8_t)strtoul(pointer + 27, nullptr, 16); *(pointer + 27) = 0;
            _Guid.Data4[2] = (uint8_t)strtoul(pointer + 25, nullptr, 16); *(pointer + 25) = 0;
            _Guid.Data4[1] = (uint8_t)strtoul(pointer + 22, nullptr, 16); *(pointer + 22) = 0;
            _Guid.Data4[0] = (uint8_t)strtoul(pointer + 20, nullptr, 16); *(pointer + 20) = 0;
            _Guid.Data3 = (uint16_t)strtoul(pointer + 15, nullptr, 16);
            _Guid.Data2 = (uint16_t)strtoul(pointer + 10, nullptr, 16);
            _Guid.Data1 = (uint32_t)strtoul(pointer + 1, nullptr, 16);
            return _STD make_pair(move(_Guid), true);
        }
        else
        {
            return _STD make_pair(GUID(), false);
        }
    }
}

#if _MSC_VER < 1800
_STD basic_string<defChar, _STD char_traits<defChar>, _STD allocator<defChar> > Guid_tostring(const GUID& _Guid)
{
    return Guid_tostring<defChar, _STD char_traits<defChar>, _STD allocator<defChar> >(_Guid);
}
template<typename _Elem> inline
_STD basic_string<_Elem, _STD char_traits<_Elem>, _STD allocator<_Elem> > Guid_tostring(const GUID& _Guid)
{
    return Guid_tostring<_Elem, _STD char_traits<_Elem>, _STD allocator<_Elem> >(_Guid);
}
template<typename _Elem, typename _Traits> inline
_STD basic_string<_Elem, _Traits, _STD allocator<_Elem> > Guid_tostring(const GUID& _Guid)
{
    return Guid_tostring<_Elem, _Traits, _STD allocator<_Elem> >(_Guid);
}

#endif /* _MSC_VER < 1800 */


template<typename _Elem DEF_VALUE(defChar), typename _Traits DEF_VALUE(_STD char_traits<_Elem>), typename _Alloc DEF_VALUE(_STD allocator<_Elem>), typename T> inline
_STD basic_string<_Elem, _Traits, _Alloc> num_tostring(T&& _Number)
{
    static_assert(!is_container<T>::value, "_Number is a container");
    return string_printf(_STDEX_TYPE num_tostring_format<T, _Elem, _Traits, _Alloc>::string(), _STD forward<T>(_Number));
}

#if _MSC_VER < 1800
template<typename T> inline
_STD basic_string<defChar, _STD char_traits<defChar>, _STD allocator<defChar> > num_tostring(T&& _Number)
{
    return num_tostring<defChar, _STD char_traits<defChar>, _STD allocator<defChar>, T>(_STD forward<T>(_Number));
}
template<typename _Elem, typename T> inline
_STD basic_string<_Elem, _STD char_traits<_Elem>, _STD allocator<_Elem> > num_tostring(T&& _Number)
{
    return num_tostring<_Elem, _STD char_traits<_Elem>, _STD allocator<_Elem>, T>(_STD forward<T>(_Number));
}
template<typename _Elem, typename _Traits, typename T> inline
_STD basic_string<_Elem, _Traits, _STD allocator<_Elem> > num_tostring(T&& _Number)
{
    return num_tostring<_Elem, _Traits, _STD allocator<_Elem>, T>(_STD forward<T>(_Number));
}

#endif /* _MSC_VER < 1800 */



/* struct template */
_STDEX_TYPE_BEGIN
template<typename _This = void, MY_CLASS_ARG0_DEF_MAX(void)> struct _Format_string_type
{
    typedef typename is_wstring<_This>::type type;
};
template<MY_CLASS_ARG0_MAX>
struct _Format_string_type<void, MY_ARG0_ARG1_MAX>
{
    typedef void type;
};

template<typename _Elem, typename _Traits, typename _Left, MY_CLASS_ARG1_MAX>
struct _Format_string_type<_STD basic_ostream<_Elem, _Traits>, _Left, MY_ARG1_ARG2_MAX>
{
    typedef typename _Format_string_type<typename _STD remove_cv<typename _STD remove_reference<_Left>::type>::type, MY_ARG1_ARG2_MAX, void>::type type;
};
template<typename _Elem, typename _Traits, typename _Left, MY_CLASS_ARG1_MAX>
struct _Format_string_type<_STD basic_ostream<_Elem, _Traits>*, _Left, MY_ARG1_ARG2_MAX>
{
    typedef typename _Format_string_type<typename _STD remove_cv<typename _STD remove_reference<_Left>::type>::type, MY_ARG1_ARG2_MAX, void>::type type;
};

template<typename _Left, MY_CLASS_ARG1_MAX>
struct _Format_string_type<FILE*, _Left, MY_ARG1_ARG2_MAX>
{
    typedef typename _Format_string_type<typename _STD remove_cv<typename _STD remove_reference<_Left>::type>::type, MY_ARG1_ARG2_MAX, void>::type type;
};
template<typename _Left, MY_CLASS_ARG1_MAX>
struct _Format_string_type<FILE**, _Left, MY_ARG1_ARG2_MAX>
{
    typedef typename _Format_string_type<typename _STD remove_cv<typename _STD remove_reference<_Left>::type>::type, MY_ARG1_ARG2_MAX, void>::type type;
};

template<typename _Left, MY_CLASS_ARG1_MAX>
struct _Format_string_type<void*, _Left, MY_ARG1_ARG2_MAX>
{
    typedef typename _Format_string_type<typename _STD remove_cv<typename _STD remove_reference<_Left>::type>::type, MY_ARG1_ARG2_MAX, void>::type type;
};
template<typename _Left, MY_CLASS_ARG1_MAX>
struct _Format_string_type<const void*, _Left, MY_ARG1_ARG2_MAX>
{
    typedef typename _Format_string_type<typename _STD remove_cv<typename _STD remove_reference<_Left>::type>::type, MY_ARG1_ARG2_MAX, void>::type type;
};
template<typename _Left, MY_CLASS_ARG1_MAX>
struct _Format_string_type<_STD nullptr_t, _Left, MY_ARG1_ARG2_MAX>
{
    typedef typename _Format_string_type<typename _STD remove_cv<typename _STD remove_reference<_Left>::type>::type, MY_ARG1_ARG2_MAX, void>::type type;
};

#if HAVE_WINDOWS
template<typename _Left, MY_CLASS_ARG1_MAX>
struct _Format_string_type<csys_t, _Left, MY_ARG1_ARG2_MAX>
{
    typedef typename _Format_string_type<typename _STD remove_cv<typename _STD remove_reference<_Left>::type>::type, MY_ARG1_ARG2_MAX, void>::type type;
};
template<typename _Left, MY_CLASS_ARG1_MAX>
struct _Format_string_type<csys_t*, _Left, MY_ARG1_ARG2_MAX>
{
    typedef typename _Format_string_type<typename _STD remove_cv<typename _STD remove_reference<_Left>::type>::type, MY_ARG1_ARG2_MAX, void>::type type;
};

#endif /* HAVE_WINDOWS */

template<typename _This = void, MY_CLASS_ARG0_DEF_MAX(void)>
struct format_string_type
    : _Format_string_type<typename _STD remove_cv<typename _STD remove_reference<_This>::type>::type, MY_ARG0_ARG1_MAX>
{};

_STDEX_TYPE_END



template<typename T> inline
/* output string to stdout */
size_t std_puts(T&& _String)
{
    static_assert(is_string<T>::value || is_wstring<T>::value, "_String is NOT a string");
    return puts(_STD forward<T>(_String));
}


template<typename _OutType, typename T> inline
/* output string to _Out */
size_t stream_puts(_OutType&& _Out, T&& _String)
{
    static_assert(is_string<T>::value || is_wstring<T>::value, "_String is NOT a string");
    return fputs(_STD forward<_OutType>(_Out), _STD forward<T>(_String));
}


template<bool _EndLine DEF_VALUE(false), typename T> inline
/* output string to empty */
void debug_puts(T&& _String)
{
    static_assert(is_string<T>::value || is_wstring<T>::value, "_String is NOT a string");
}


/* function template */
#if _MSC_VER < 1800 || _STRING_PRINTF_NO_VARIADIC_TEMPLATES_
#define _INCL_STRING_PRINTF_FUNCTION 1
#define MY_NARGS 0
#include <_xxstringprintf.h>
#undef MY_NARGS
#define MY_NARGS 1
#include <_xxstringprintf.h>
#undef MY_NARGS
#define MY_NARGS 2
#include <_xxstringprintf.h>
#undef MY_NARGS
#define MY_NARGS 3
#include <_xxstringprintf.h>
#undef MY_NARGS
#define MY_NARGS 4
#include <_xxstringprintf.h>
#undef MY_NARGS
#define MY_NARGS 5
#include <_xxstringprintf.h>
#undef MY_NARGS
#define MY_NARGS 6
#include <_xxstringprintf.h>
#undef MY_NARGS
#define MY_NARGS 7
#include <_xxstringprintf.h>
#undef MY_NARGS
#define MY_NARGS 8
#include <_xxstringprintf.h>
#undef MY_NARGS
#define MY_NARGS 9
#include <_xxstringprintf.h>
#undef MY_NARGS
#define MY_NARGS 10
#include <_xxstringprintf.h>
#undef MY_NARGS
#define MY_NARGS 11
#include <_xxstringprintf.h>
#undef MY_NARGS
#define MY_NARGS 12
#include <_xxstringprintf.h>
#undef MY_NARGS
#define MY_NARGS 13
#include <_xxstringprintf.h>
#undef MY_NARGS
#define MY_NARGS 14
#include <_xxstringprintf.h>
#undef MY_NARGS
#define MY_NARGS 15
#include <_xxstringprintf.h>
#undef MY_NARGS
#define MY_NARGS 16
#include <_xxstringprintf.h>
#undef MY_NARGS
#define MY_NARGS 17
#include <_xxstringprintf.h>
#undef MY_NARGS
#define MY_NARGS 18
#include <_xxstringprintf.h>
#undef MY_NARGS
#define MY_NARGS 19
#include <_xxstringprintf.h>
#undef MY_NARGS
#define MY_NARGS 20
#include <_xxstringprintf.h>
#undef MY_NARGS
#define MY_NARGS 21
#include <_xxstringprintf.h>
#undef MY_NARGS
#define MY_NARGS 22
#include <_xxstringprintf.h>
#undef MY_NARGS
#define MY_NARGS 23
#include <_xxstringprintf.h>
#undef MY_NARGS
#define MY_NARGS 24
#include <_xxstringprintf.h>
#undef MY_NARGS
#define MY_NARGS 25
#include <_xxstringprintf.h>
#undef MY_NARGS
#define MY_NARGS 26
#include <_xxstringprintf.h>
#undef MY_NARGS
#define MY_NARGS 27
#include <_xxstringprintf.h>
#undef MY_NARGS
#define MY_NARGS 28
#include <_xxstringprintf.h>
#undef MY_NARGS
#define MY_NARGS 29
#include <_xxstringprintf.h>
#undef MY_NARGS
#define MY_NARGS 30
#include <_xxstringprintf.h>
#undef MY_NARGS
#undef _INCL_STRING_PRINTF_FUNCTION

#else /* _MSC_VER < 1800 || _STRING_PRINTF_NO_VARIADIC_TEMPLATES_ */
#define _INCL_STRING_PRINTF_FUNCTION 1
#define MY_NARGS -1
#include <_xxstringprintf.h>
#undef MY_NARGS
#undef _INCL_STRING_PRINTF_FUNCTION

#endif


_STDEX_END


#endif /* __cplusplus */

#endif /* _STRINGPRINTF_H_ */
