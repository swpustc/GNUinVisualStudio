#ifndef _STRINGPRINTF_STL_H_
#define _STRINGPRINTF_STL_H_

#ifdef _STRINGPRINTF_H_


_STDEX_BEGIN _STDEX_TYPE_BEGIN

/* static_assert support */
/* is container */
template<typename _Ty> struct _Is_container : _STD false_type{};
/* Containers */
#ifdef _ARRAY_
template<typename _Ty, size_t _Size>
struct _Is_container<_STD array<_Ty, _Size> > : _STD true_type{};
#endif
#ifdef _DEQUE_
template<typename _Ty, typename _Alloc>
struct _Is_container<_STD deque<_Ty, _Alloc> > : _STD true_type{};
#endif
#ifdef _FORWARD_LIST_
template<typename _Ty, typename _Alloc>
struct _Is_container<_STD forward_list<_Ty, _Alloc> > : _STD true_type{};
#endif
#ifdef _LIST_
template<typename _Ty, typename _Alloc>
struct _Is_container<_STD list<_Ty, _Alloc> > : _STD true_type{};
#endif
#ifdef _MAP_
template<typename _Kty, typename _Ty, typename _Pr, typename _Alloc>
struct _Is_container<_STD map<_Kty, _Ty, _Pr, _Alloc> > : _STD true_type{};
template<typename _Kty, typename _Ty, typename _Pr, typename _Alloc>
struct _Is_container<_STD multimap<_Kty, _Ty, _Pr, _Alloc> > : _STD true_type{};
#endif
#ifdef _QUEUE_
template<typename _Ty, typename _Container>
struct _Is_container<_STD queue<_Ty, _Container> > : _STD true_type{};
template<typename _Ty, typename _Container, typename _Pr>
struct _Is_container<_STD priority_queue<_Ty, _Container, _Pr> > : _STD true_type{};
#endif
#ifdef _SET_
template<typename _Ty, typename _Pr, typename _Alloc>
struct _Is_container<_STD set<_Ty, _Pr, _Alloc> > : _STD true_type{};
template<typename _Ty, typename _Pr, typename _Alloc>
struct _Is_container<_STD multiset<_Ty, _Pr, _Alloc> > : _STD true_type{};
#endif
#ifdef _STACK_
template<typename _Ty, typename _Container>
struct _Is_container<_STD stack<_Ty, _Container> > : _STD true_type{};
#endif
#ifdef _UNORDERED_MAP_
template<typename _Kty, typename _Ty, typename _Hasher, typename _Keyeq, typename _Alloc>
struct _Is_container<_STD unordered_map<_Kty, _Ty, _Hasher, _Keyeq, _Alloc> > : _STD true_type{};
template<typename _Kty, typename _Ty, typename _Hasher, typename _Keyeq, typename _Alloc>
struct _Is_container<_STD unordered_multimap<_Kty, _Ty, _Hasher, _Keyeq, _Alloc> > : _STD true_type{};
#endif
#ifdef _UNORDERED_SET_
template<typename _Kty, typename _Hasher, typename _Keyeq, typename _Alloc>
struct _Is_container<_STD unordered_set<_Kty, _Hasher, _Keyeq, _Alloc> > : _STD true_type{};
template<typename _Kty, typename _Hasher, typename _Keyeq, typename _Alloc>
struct _Is_container<_STD unordered_multiset<_Kty, _Hasher, _Keyeq, _Alloc> > : _STD true_type{};
#endif
#ifdef _VECTOR_
template<typename _Ty, typename _Alloc>
struct _Is_container<_STD vector<_Ty, _Alloc> > : _STD true_type{};
#endif
/* Other */
#ifdef _STRING_
template<typename _Elem, typename _Traits, typename _Alloc>
struct _Is_container<_STD basic_string<_Elem, _Traits, _Alloc> > : _STD true_type{};
#endif
#ifdef _UTILITY_
template<typename _Ty1, typename _Ty2>
struct _Is_container<_STD pair<_Ty1, _Ty2> > : _STD true_type{};
#endif
#ifdef _TUPLE_
#if _MSC_VER < 1700
#if defined(_CLASS_ARG0_MAX) && defined(_ARG0_ARG1_MAX)
template<_CLASS_ARG0_MAX>
struct _Is_container<_STD tuple<_ARG0_ARG1_MAX> > : _STD true_type{};
#endif /* _CLASS_ARG0_MAX && _ARG0_ARG1_MAX */
#elif _MSC_VER < 1800
#if defined(_PAD_LIST0) && defined(_CLASS_TYPE) && defined(_TYPE)
template<typename _TyBegin, _PAD_LIST0(_CLASS_TYPE), typename _TyEnd>
struct _Is_container<_STD tuple<_TyBegin, _PAD_LIST0(_TYPE), _TyEnd> > : _STD true_type{};
#endif /* _MAX_CLASS_LIST && _CLASS_TYPE && _TYPE */
#else /* _MSC_VER < 1800 */
template<typename... _Ty>
struct _Is_container<_STD tuple<_Ty...> > : _STD true_type{};
#endif /* _MSC_VER < 1800 */
#endif
/* Input/Output */
#ifdef _IOS_
template<>
struct _Is_container<_STD ios_base> : _STD true_type{};
template<typename _Elem, typename _Traits>
struct _Is_container<_STD basic_ios<_Elem, _Traits> > : _STD true_type{};
#endif
#ifdef _ISTREAM_
template<typename _Elem, typename _Traits>
struct _Is_container<_STD basic_istream<_Elem, _Traits> > : _STD true_type{};
template<typename _Elem, typename _Traits>
struct _Is_container<_STD basic_iostream<_Elem, _Traits> > : _STD true_type{};
#endif
#ifdef _OSTREAM_
template<typename _Elem, typename _Traits>
struct _Is_container<_STD basic_ostream<_Elem, _Traits> > : _STD true_type{};
#endif
#ifdef _STREAMBUF_
template<typename _Elem, typename _Traits>
struct _Is_container<_STD basic_streambuf<_Elem, _Traits> > : _STD true_type{};
#endif
#ifdef _FSTREAM_
template<typename _Elem, typename _Traits>
struct _Is_container<_STD basic_ifstream<_Elem, _Traits> > : _STD true_type{};
template<typename _Elem, typename _Traits>
struct _Is_container<_STD basic_fstream<_Elem, _Traits> > : _STD true_type{};
template<typename _Elem, typename _Traits>
struct _Is_container<_STD basic_ofstream<_Elem, _Traits> > : _STD true_type{};
template<typename _Elem, typename _Traits>
struct _Is_container<_STD basic_filebuf<_Elem, _Traits> > : _STD true_type{};
#endif
#ifdef _SSTREAM_
template<typename _Elem, typename _Traits, typename _Alloc>
struct _Is_container<_STD basic_istringstream<_Elem, _Traits, _Alloc> > : _STD true_type{};
template<typename _Elem, typename _Traits, typename _Alloc>
struct _Is_container<_STD basic_stringstream<_Elem, _Traits, _Alloc> > : _STD true_type{};
template<typename _Elem, typename _Traits, typename _Alloc>
struct _Is_container<_STD basic_ostringstream<_Elem, _Traits, _Alloc> > : _STD true_type{};
template<typename _Elem, typename _Traits, typename _Alloc>
struct _Is_container<_STD basic_stringbuf<_Elem, _Traits, _Alloc> > : _STD true_type{};
#endif
/* is_container */
template<typename _Ty> struct is_container
    : _Is_container<typename _STD remove_cv<typename _STD remove_reference<_Ty>::type>::type>{};



/* is char element string */
template<typename _Ty, bool _Is_pointer> struct _Is_string : _STD false_type
{
    typedef void _Elem;
    typedef _Ty type;
};
template<typename _Ty> struct _Is_string<_Ty, true> : _STD false_type
{
    typedef typename _Is_string<_Ty, false>::_Elem _Elem;
    typedef typename _STD add_pointer<_Ty>::type type;
};
template<> struct _Is_string<void, true> : _STD true_type
{
    typedef char _Elem;
    typedef _STD basic_string<_Elem> type;
};
template<> struct _Is_string<_STD nullptr_t, false> : _STD true_type
{
    typedef char _Elem;
    typedef _STD basic_string<_Elem> type;
};
template<size_t _Nx> struct _Is_string<char[_Nx], false> : _STD true_type
{
    typedef char _Elem;
    typedef _STD basic_string<_Elem> type;
};
template<> struct _Is_string<char[], false> : _STD true_type
{
    typedef char _Elem;
    typedef _STD basic_string<_Elem> type;
};
template<> struct _Is_string<char, true> : _STD true_type
{
    typedef char _Elem;
    typedef _STD basic_string<_Elem> type;
};
template<typename _Traits, typename _Alloc> struct _Is_string<_STD basic_string<char, _Traits, _Alloc>, false> : _STD true_type
{
    typedef char _Elem;
    typedef _STD basic_string<_Elem, _Traits, _Alloc> type;
};
/* is_string */
template<typename _Ty> struct is_string
    : _Is_string<typename _STD remove_cv<typename _STD remove_pointer<typename _STD remove_reference<_Ty>::type>::type>::type,
    _STD is_pointer<typename _STD remove_reference<_Ty>::type>::value>{};


/* is wchar_t element string */
template<typename _Ty, bool _Is_pointer> struct _Is_wstring : _STD false_type
{
    typedef typename _Is_string<_Ty, _Is_pointer>::_Elem _Elem;
    typedef typename _Is_string<_Ty, _Is_pointer>::type type;
};
template<> struct _Is_wstring<void, true> : _STD true_type
{
    typedef wchar_t _Elem;
    typedef _STD basic_string<_Elem> type;
};
template<> struct _Is_wstring<_STD nullptr_t, false> : _STD true_type
{
    typedef wchar_t _Elem;
    typedef _STD basic_string<_Elem> type;
};
template<size_t _Nx> struct _Is_wstring<wchar_t[_Nx], false> : _STD true_type
{
    typedef wchar_t _Elem;
    typedef _STD basic_string<_Elem> type;
};
template<> struct _Is_wstring<wchar_t[], false> : _STD true_type
{
    typedef wchar_t _Elem;
    typedef _STD basic_string<_Elem> type;
};
template<> struct _Is_wstring<wchar_t, true> : _STD true_type
{
    typedef wchar_t _Elem;
    typedef _STD basic_string<_Elem> type;
};
template<typename _Traits, typename _Alloc> struct _Is_wstring<_STD basic_string<wchar_t, _Traits, _Alloc>, false> : _STD true_type
{
    typedef wchar_t _Elem;
    typedef _STD basic_string<_Elem, _Traits, _Alloc> type;
};
/* is_wstring */
template<typename _Ty> struct is_wstring
    : _Is_wstring<typename _STD remove_cv<typename _STD remove_pointer<typename _STD remove_reference<_Ty>::type>::type>::type,
    _STD is_pointer<typename _STD remove_reference<_Ty>::type>::value>{};



/* overloaded STL */
template<typename _Elem = void, typename _Traits = _STD char_traits<_Elem>, typename _Alloc = _STD allocator<_Elem> >
struct endline
{
    static inline void pointer()
    {
        static_assert(is_string<_Elem*>::value || is_wstring<_Elem*>::value, "Bad string element");
    }
    static inline void string()
    {
        static_assert(is_string<_Elem*>::value || is_wstring<_Elem*>::value, "Bad string element");
    }
};
template<typename _Traits, typename _Alloc> struct endline<char, _Traits, _Alloc>
{
#define _C_END_LINE         "\n"
    static inline const char* pointer() /* get "\n" */
    {
        return _C_END_LINE;
    }
    static inline _STD basic_string<char, _Traits, _Alloc> string() /* get string("\n") */
    {
        return _STD basic_string<char, _Traits, _Alloc>(_C_END_LINE);
    }
};
template<typename _Traits, typename _Alloc> struct endline<wchar_t, _Traits, _Alloc>
{
#define _W_END_LINE         _CRT_WIDE(_C_END_LINE)
    static inline const wchar_t* pointer() /* get L"\n" */
    {
        return _W_END_LINE;
    }
    static inline _STD basic_string<wchar_t, _Traits, _Alloc> string() /* get wstring(L"\n") */
    {
        return _STD basic_string<wchar_t, _Traits, _Alloc>(_W_END_LINE);
    }
};

template<typename _Elem = void, typename _Traits = _STD char_traits<_Elem>, typename _Alloc = _STD allocator<_Elem> >
struct guid_format
{
    static inline void pointer()
    {
        static_assert(is_string<_Elem*>::value || is_wstring<_Elem*>::value, "Bad string element");
    }
    static inline void string()
    {
        static_assert(is_string<_Elem*>::value || is_wstring<_Elem*>::value, "Bad string element");
    }
};
template<typename _Traits, typename _Alloc> struct guid_format<char, _Traits, _Alloc>
{
#define _C_GUID_FORMAT      "{%08X-%04X-%04X-%02X%02X-%02X%02X%02X%02X%02X%02X}"
    static inline const char* pointer() /* get Guid_Format(char*) */
    {
        return _C_GUID_FORMAT;
    }
    static inline _STD basic_string<char, _Traits, _Alloc> string() /* get Guid_Format(string) */
    {
        return _STD basic_string<char, _Traits, _Alloc>(_C_GUID_FORMAT);
    }
};
template<typename _Traits, typename _Alloc> struct guid_format<wchar_t, _Traits, _Alloc>
{
#define _W_GUID_FORMAT      _CRT_WIDE(_C_GUID_FORMAT)
    static inline const wchar_t* pointer() /* get Guid_Format(wchar_t*) */
    {
        return _W_GUID_FORMAT;
    }
    static inline _STD basic_string<wchar_t, _Traits, _Alloc> string() /* get Guid_Format(wstring) */
    {
        return _STD basic_string<wchar_t, _Traits, _Alloc>(_W_GUID_FORMAT);
    }
};


#ifdef _MSC_VER
#define __LONGLONG_FORMAT   "%I64"
#else /* _MSC_VER */
#define __LONGLONG_FORMAT   "%ll"
#endif /* _MSC_VER */

template<typename type = void, typename _Elem = void, typename _Traits = _STD char_traits<_Elem>, typename _Alloc = _STD allocator<_Elem> >
struct _Num_tostring_format
{
    static inline void pointer()
    {
        static_assert(is_string<_Elem*>::value || is_wstring<_Elem*>::value, "Bad string element");
    }
    static inline void string()
    {
        static_assert(is_string<_Elem*>::value || is_wstring<_Elem*>::value, "Bad string element");
    }
};
template<typename _Traits, typename _Alloc> struct _Num_tostring_format<int, char, _Traits, _Alloc>
{
#define _C_INT_FORMAT       "%d"
    static inline const char* pointer() /* get "%d" */
    {
        return _C_INT_FORMAT;
    }
    static inline _STD basic_string<char, _Traits, _Alloc> string() /* get string("%d") */
    {
        return _STD basic_string<char, _Traits, _Alloc>(_C_INT_FORMAT);
    }
};
template<typename _Traits, typename _Alloc> struct _Num_tostring_format<int, wchar_t, _Traits, _Alloc>
{
#define _W_INT_FORMAT       _CRT_WIDE(_C_INT_FORMAT)
    static inline const wchar_t* pointer() /* get L"%d" */
    {
        return _W_INT_FORMAT;
    }
    static inline _STD basic_string<wchar_t, _Traits, _Alloc> string() /* get wstring(L"%d") */
    {
        return _STD basic_string<wchar_t, _Traits, _Alloc>(_W_INT_FORMAT);
    }
};
template<typename _Traits, typename _Alloc> struct _Num_tostring_format<unsigned int, char, _Traits, _Alloc>
{
#define _C_UINT_FORMAT      "%u"
    static inline const char* pointer() /* get "%u" */
    {
        return _C_UINT_FORMAT;
    }
    static inline _STD basic_string<char, _Traits, _Alloc> string() /* get string("%u") */
    {
        return _STD basic_string<char, _Traits, _Alloc>(_C_UINT_FORMAT);
    }
};
template<typename _Traits, typename _Alloc> struct _Num_tostring_format<unsigned int, wchar_t, _Traits, _Alloc>
{
#define _W_UINT_FORMAT      _CRT_WIDE(_C_UINT_FORMAT)
    static inline const wchar_t* pointer() /* get L"%u" */
    {
        return _W_UINT_FORMAT;
    }
    static inline _STD basic_string<wchar_t, _Traits, _Alloc> string() /* get string(L"%u") */
    {
        return _STD basic_string<wchar_t, _Traits, _Alloc>(_W_UINT_FORMAT);
    }
};
template<typename _Traits, typename _Alloc> struct _Num_tostring_format<long, char, _Traits, _Alloc>
{
#define _C_LONG_FORMAT      "%ld"
    static inline const char* pointer() /* get "%ld" */
    {
        return _C_LONG_FORMAT;
    }
    static inline _STD basic_string<char, _Traits, _Alloc> string() /* get string("%ld") */
    {
        return _STD basic_string<char, _Traits, _Alloc>(_C_LONG_FORMAT);
    }
};
template<typename _Traits, typename _Alloc> struct _Num_tostring_format<long, wchar_t, _Traits, _Alloc>
{
#define _W_LONG_FORMAT      _CRT_WIDE(_C_LONG_FORMAT)
    static inline const wchar_t* pointer() /* get L"%ld" */
    {
        return _W_LONG_FORMAT;
    }
    static inline _STD basic_string<wchar_t, _Traits, _Alloc> string() /* get wstring(L"%ld") */
    {
        return _STD basic_string<wchar_t, _Traits, _Alloc>(_W_LONG_FORMAT);
    }
};
template<typename _Traits, typename _Alloc> struct _Num_tostring_format<unsigned long, char, _Traits, _Alloc>
{
#define _C_ULONG_FORMAT     "%lu"
    static inline const char* pointer() /* get "%lu" */
    {
        return _C_ULONG_FORMAT;
    }
    static inline _STD basic_string<char, _Traits, _Alloc> string() /* get string("%lu") */
    {
        return _STD basic_string<char, _Traits, _Alloc>(_C_ULONG_FORMAT);
    }
};
template<typename _Traits, typename _Alloc> struct _Num_tostring_format<unsigned long, wchar_t, _Traits, _Alloc>
{
#define _W_ULONG_FORMAT     _CRT_WIDE(_C_ULONG_FORMAT)
    static inline const wchar_t* pointer() /* get L"%lu" */
    {
        return _W_ULONG_FORMAT;
    }
    static inline _STD basic_string<wchar_t, _Traits, _Alloc> string() /* get wstring(L"%lu") */
    {
        return _STD basic_string<wchar_t, _Traits, _Alloc>(_W_ULONG_FORMAT);
    }
};
template<typename _Traits, typename _Alloc> struct _Num_tostring_format<long long, char, _Traits, _Alloc>
{
#define _C_LONGLONG_FORMAT  __LONGLONG_FORMAT "d"
    static inline const char* pointer() /* get "%lld" */
    {
        return _C_LONGLONG_FORMAT;
    }
    static inline _STD basic_string<char, _Traits, _Alloc> string() /* get string("%lld") */
    {
        return _STD basic_string<char, _Traits, _Alloc>(_C_LONGLONG_FORMAT);
    }
};
template<typename _Traits, typename _Alloc> struct _Num_tostring_format<long long, wchar_t, _Traits, _Alloc>
{
#define _W_LONGLONG_FORMAT  _CRT_WIDE(__LONGLONG_FORMAT) _CRT_WIDE("d")
    static inline const wchar_t* pointer() /* get L"%lld" */
    {
        return _W_LONGLONG_FORMAT;
    }
    static inline _STD basic_string<wchar_t, _Traits, _Alloc> string() /* get wstring(L"%lld") */
    {
        return _STD basic_string<wchar_t, _Traits, _Alloc>(_W_LONGLONG_FORMAT);
    }
};
template<typename _Traits, typename _Alloc> struct _Num_tostring_format<unsigned long long, char, _Traits, _Alloc>
{
#define _C_ULONGLONG_FORMAT __LONGLONG_FORMAT "u"
    static inline const char* pointer() /* get "%lld" */
    {
        return _C_ULONGLONG_FORMAT;
    }
    static inline _STD basic_string<char, _Traits, _Alloc> string() /* get string("%llu") */
    {
        return _STD basic_string<char, _Traits, _Alloc>(_C_ULONGLONG_FORMAT);
    }
};
template<typename _Traits, typename _Alloc> struct _Num_tostring_format<unsigned long long, wchar_t, _Traits, _Alloc>
{
#define _W_ULONGLONG_FORMAT _CRT_WIDE(__LONGLONG_FORMAT) _CRT_WIDE("u")
    static inline const wchar_t* pointer() /* get L"%llu" */
    {
        return _W_ULONGLONG_FORMAT;
    }
    static inline _STD basic_string<wchar_t, _Traits, _Alloc> string() /* get wstring(L"%llu") */
    {
        return _STD basic_string<wchar_t, _Traits, _Alloc>(_W_ULONGLONG_FORMAT);
    }
};
template<typename _Traits, typename _Alloc> struct _Num_tostring_format<long double, char, _Traits, _Alloc>
{
#define _C_LDB_FORMAT       "%lf"
    static inline const char* pointer() /* get "%lf" */
    {
        return _C_LDB_FORMAT;
    }
    static inline _STD basic_string<char, _Traits, _Alloc> string() /* get string("%lf") */
    {
        return _STD basic_string<char, _Traits, _Alloc>(_C_LDB_FORMAT);
    }
};
template<typename _Traits, typename _Alloc> struct _Num_tostring_format<long double, wchar_t, _Traits, _Alloc>
{
#define _W_LDB_FORMAT       _CRT_WIDE(_C_LDB_FORMAT)
    static inline const wchar_t* pointer() /* get L"%lf" */
    {
        return _W_LDB_FORMAT;
    }
    static inline _STD basic_string<wchar_t, _Traits, _Alloc> string() /* get wstring(L"%lf") */
    {
        return _STD basic_string<wchar_t, _Traits, _Alloc>(_W_LDB_FORMAT);
    }
};
template<typename _Traits, typename _Alloc> struct _Num_tostring_format<double, char, _Traits, _Alloc>
{
#define _C_DB_FORMAT        "%lf"
    static inline const char* pointer() /* get "%lf" */
    {
        return _C_DB_FORMAT;
    }
    static inline _STD basic_string<char, _Traits, _Alloc> string() /* get string("%lf") */
    {
        return _STD basic_string<char, _Traits, _Alloc>(_C_DB_FORMAT);
    }
};
template<typename _Traits, typename _Alloc> struct _Num_tostring_format<double, wchar_t, _Traits, _Alloc>
{
#define _W_DB_FORMAT        _CRT_WIDE(_C_DB_FORMAT)
    static inline const wchar_t* pointer() /* get L"%lf" */
    {
        return _W_DB_FORMAT;
    }
    static inline _STD basic_string<wchar_t, _Traits, _Alloc> string() /* get wstring(L"%lf") */
    {
        return _STD basic_string<wchar_t, _Traits, _Alloc>(_W_DB_FORMAT);
    }
};
template<typename _Traits, typename _Alloc> struct _Num_tostring_format<float, char, _Traits, _Alloc>
{
#define _C_FLOAT_FORMAT     "%f"
    static inline const char* pointer() /* get "%f" */
    {
        return _C_FLOAT_FORMAT;
    }
    static inline _STD basic_string<char, _Traits, _Alloc> string() /* get string("%f") */
    {
        return _STD basic_string<char, _Traits, _Alloc>(_C_FLOAT_FORMAT);
    }
};
template<typename _Traits, typename _Alloc> struct _Num_tostring_format<float, wchar_t, _Traits, _Alloc>
{
#define _W_FLOAT_FORMAT     _CRT_WIDE(_C_FLOAT_FORMAT)
    static inline const wchar_t* pointer() /* get L"%f" */
    {
        return _W_FLOAT_FORMAT;
    }
    static inline _STD basic_string<wchar_t, _Traits, _Alloc> string() /* get wstring(L"%f") */
    {
        return _STD basic_string<wchar_t, _Traits, _Alloc>(_W_FLOAT_FORMAT);
    }
};
template<typename _Traits, typename _Alloc> struct _Num_tostring_format<nullptr_t, char, _Traits, _Alloc>
{
#define _C_POINT_FORMAT     "%p"
    static inline const char* pointer() /* get "%p" */
    {
        return _C_POINT_FORMAT;
    }
    static inline _STD basic_string<char, _Traits, _Alloc> string() /* get string("%p") */
    {
        return _STD basic_string<char, _Traits, _Alloc>(_C_POINT_FORMAT);
    }
};
template<typename _Traits, typename _Alloc> struct _Num_tostring_format<nullptr_t, wchar_t, _Traits, _Alloc>
{
#define _W_POINT_FORMAT     _CRT_WIDE(_C_POINT_FORMAT)
    static inline const wchar_t* pointer() /* get L"%p" */
    {
        return _W_POINT_FORMAT;
    }
    static inline _STD basic_string<wchar_t, _Traits, _Alloc> string() /* get wstring(L"%p") */
    {
        return _STD basic_string<wchar_t, _Traits, _Alloc>(_W_POINT_FORMAT);
    }
};
template<typename _Elem, typename _Traits, typename _Alloc> struct _Num_tostring_format<_Elem*, char, _Traits, _Alloc>
{
    static inline const char* pointer() /* get "%p" */
    {
        return _C_POINT_FORMAT;
    }
    static inline _STD basic_string<char, _Traits, _Alloc> string() /* get string("%p") */
    {
        return _STD basic_string<char, _Traits, _Alloc>(_C_POINT_FORMAT);
    }
};
template<typename _Elem, typename _Traits, typename _Alloc> struct _Num_tostring_format<_Elem*, wchar_t, _Traits, _Alloc>
{
    static inline const wchar_t* pointer() /* get L"%p" */
    {
        return _W_POINT_FORMAT;
    }
    static inline _STD basic_string<wchar_t, _Traits, _Alloc> string() /* get wstring(L"%p") */
    {
        return _STD basic_string<wchar_t, _Traits, _Alloc>(_W_POINT_FORMAT);
    }
};
template<typename _Elem, size_t _Index, typename _Traits, typename _Alloc> struct _Num_tostring_format<_Elem[_Index], char, _Traits, _Alloc>
{
    static inline const char* pointer() /* get "%p" */
    {
        return _C_POINT_FORMAT;
    }
    static inline _STD basic_string<char, _Traits, _Alloc> string() /* get string("%p") */
    {
        return _STD basic_string<char, _Traits, _Alloc>(_C_POINT_FORMAT);
    }
};
template<typename _Elem, size_t _Index, typename _Traits, typename _Alloc> struct _Num_tostring_format<_Elem[_Index], wchar_t, _Traits, _Alloc>
{
    static inline const wchar_t* pointer() /* get L"%p" */
    {
        return _W_POINT_FORMAT;
    }
    static inline _STD basic_string<wchar_t, _Traits, _Alloc> string() /* get wstring(L"%p") */
    {
        return _STD basic_string<wchar_t, _Traits, _Alloc>(_W_POINT_FORMAT);
    }
};
template<typename _Elem, typename _Traits, typename _Alloc> struct _Num_tostring_format<_Elem[], char, _Traits, _Alloc>
{
    static inline const char* pointer() /* get "%p" */
    {
        return _C_POINT_FORMAT;
    }
    static inline _STD basic_string<char, _Traits, _Alloc> string() /* get string("%p") */
    {
        return _STD basic_string<char, _Traits, _Alloc>(_C_POINT_FORMAT);
    }
};
template<typename _Elem, typename _Traits, typename _Alloc> struct _Num_tostring_format<_Elem[], wchar_t, _Traits, _Alloc>
{
    static inline const wchar_t* pointer() /* get L"%p" */
    {
        return _W_POINT_FORMAT;
    }
    static inline _STD basic_string<wchar_t, _Traits, _Alloc> string() /* get wstring(L"%p") */
    {
        return _STD basic_string<wchar_t, _Traits, _Alloc>(_W_POINT_FORMAT);
    }
};

template<typename type = void, typename _Elem = void, typename _Traits = _STD char_traits<_Elem>, typename _Alloc = _STD allocator<_Elem> >
struct num_tostring_format
    : _Num_tostring_format<typename _STD remove_cv<typename _STD remove_reference<type>::type>::type, _Elem, _Traits, _Alloc>{};


/* overloaded std::equal_to */
struct equal_to FIX_VS_STL_RESULT_TYPE(bool) /* In most cases, the result_type is bool */
{   // transparent functor for operator==
    template<typename _Ty1, typename _Ty2> inline auto operator()(_Ty1&& _Left, _Ty2&& _Right) const
        -> decltype(_STD forward<_Ty1>(_Left) == _STD forward<_Ty2>(_Right))
    {   // transparently apply operator== to operands
        return _STD forward<_Ty1>(_Left) == _STD forward<_Ty2>(_Right);
    }
};

/* overloaded std::not_equal_to */
struct not_equal_to FIX_VS_STL_RESULT_TYPE(bool) /* In most cases, the result_type is bool */
{   // transparent functor for operator!=
    template<typename _Ty1, typename _Ty2> inline auto operator()(_Ty1&& _Left, _Ty2&& _Right) const
        -> decltype(_STD forward<_Ty1>(_Left) != _STD forward<_Ty2>(_Right))
    {   // transparently apply operator!= to operands
        return _STD forward<_Ty1>(_Left) != _STD forward<_Ty2>(_Right);
    }
};

/* overloaded std::greater */
struct greater FIX_VS_STL_RESULT_TYPE(bool) /* In most cases, the result_type is bool */
{   // transparent functor for operator>
    template<typename _Ty1, typename _Ty2> inline auto operator()(_Ty1&& _Left, _Ty2&& _Right) const
        -> decltype(_STD forward<_Ty1>(_Left) > _STD forward<_Ty2>(_Right))
    {   // transparently apply operator> to operands
        return _STD forward<_Ty1>(_Left) > _STD forward<_Ty2>(_Right);
    }
};

/* overloaded std::greater_equal */
struct greater_equal FIX_VS_STL_RESULT_TYPE(bool) /* In most cases, the result_type is bool */
{   // transparent functor for operator>=
    template<typename _Ty1, typename _Ty2> inline auto operator()(_Ty1&& _Left, _Ty2&& _Right) const
        -> decltype(_STD forward<_Ty1>(_Left) >= _STD forward<_Ty2>(_Right))
    {   // transparently apply operator>= to operands
        return _STD forward<_Ty1>(_Left) >= _STD forward<_Ty2>(_Right);
    }
};

/* overloaded std::less */
struct less FIX_VS_STL_RESULT_TYPE(bool) /* In most cases, the result_type is bool */
{   // transparent functor for operator<
    template<typename _Ty1, typename _Ty2> inline auto operator()(_Ty1&& _Left, _Ty2&& _Right) const
        -> decltype(_STD forward<_Ty1>(_Left) < _STD forward<_Ty2>(_Right))
    {   // transparently apply operator< to operands
        return _STD forward<_Ty1>(_Left) < _STD forward<_Ty2>(_Right);
    }
};

/* overloaded std::less_equal */
struct less_equal FIX_VS_STL_RESULT_TYPE(bool) /* In most cases, the result_type is bool */
{   // transparent functor for operator<=
    template<typename _Ty1, typename _Ty2> inline auto operator()(_Ty1&& _Left, _Ty2&& _Right) const
        -> decltype(_STD forward<_Ty1>(_Left) <= _STD forward<_Ty2>(_Right))
    {   // transparently apply operator<= to operands
        return (_STD forward<_Ty1>(_Left) <= _STD forward<_Ty2>(_Right));
    }
};



template<typename _Original, typename _Ty>
/* forward anything */
struct _Forward_basic_string
{
    typedef _Original&& type;
    typedef size_t size_type;
    static inline type string_forward(_Original&& _Arg)
    {
        static_assert(!is_container<_Original>::value, "Arguments is a container");
        return _STD forward<_Original>(_Arg);
    }
    static inline size_type string_size(_Original&& _Arg)
    {
        static_assert(is_string<_Original>::value || is_wstring<_Original>::value, "_Arg is NOT a string");
        return strlen(_Arg);
    }
};
template<typename _Original>
/* forward void* to const defChar* */
struct _Forward_basic_string<_Original, void*>
{
    typedef const defChar* type;
    typedef size_t size_type;
    static inline type string_forward(_Original&& _Arg)
    {
        static_assert(!is_container<_Original>::value, "Arguments is a container");
        return (type)_Arg;
    }
    static inline size_type string_size(_Original&& _Arg)
    {
        static_assert(is_string<_Original>::value || is_wstring<_Original>::value, "_Arg is NOT a string");
        return NULL;
    }
};
template<typename _Original>
/* forward const void* to const defChar* */
struct _Forward_basic_string<_Original, const void*>
{
    typedef const defChar* type;
    typedef size_t size_type;
    static inline type string_forward(_Original&& _Arg)
    {
        static_assert(!is_container<_Original>::value, "Arguments is a container");
        return (type)_Arg;
    }
    static inline size_type string_size(_Original&& _Arg)
    {
        static_assert(is_string<_Original>::value || is_wstring<_Original>::value, "_Arg is NOT a string");
        return NULL;
    }
};
template<typename _Original>
/* forward std::nullptr_t to const defChar* */
struct _Forward_basic_string<_Original, nullptr_t>
{
    typedef const defChar* type;
    typedef size_t size_type;
    static inline type string_forward(_Original&& _Arg)
    {
        static_assert(!is_container<_Original>::value, "Arguments is a container");
        return nullptr;
    }
    static inline size_type string_size(_Original&& _Arg)
    {
        static_assert(is_string<_Original>::value || is_wstring<_Original>::value, "_Arg is NOT a string");
        return NULL;
    }
};
/* forward basic_string<_Elem, _Traits, _Alloc> to const _Elem* */
template<typename _Original, typename _Elem, typename _Traits, typename _Alloc>
struct _Forward_basic_string<_Original, _STD basic_string<_Elem, _Traits, _Alloc> >
{
    typedef const _Elem* type;
    typedef typename _STD basic_string<_Elem, _Traits, _Alloc>::size_type size_type;
    static inline type string_forward(_Original&& _Arg)
    {
        static_assert(is_string<_Original>::value || is_wstring<_Original>::value, "Bad string element");
        return _Arg.c_str();
    }
    static inline size_type string_size(_Original&& _Arg)
    {
        return _Arg.length();
    }
};
/* forward_basic_string */
template<typename _Ty> struct forward_basic_string
    : _Forward_basic_string<_Ty, typename _STD remove_cv<typename _STD remove_reference<_Ty>::type>::type>{};



_STDEX_TYPE_END

using _STDEX_TYPE is_container;

using _STDEX_TYPE is_string;
using _STDEX_TYPE is_wstring;


_STDEX_END


#endif /* _STRINGPRINTF_H_ */

#endif /* _STRINGPRINTF_STL_H_ */
