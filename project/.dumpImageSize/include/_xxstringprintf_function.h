template<typename T MY_C_CLASS_ARG0> inline
/* format string to std::string using _sprintf */
auto string_printf(T&& _Format MY_C_ARG0_A0_REFREF) -> typename is_wstring<T>::type
{
    static_assert(is_string<T>::value || is_wstring<T>::value, "_Format is NOT a string");
    size_t result, length;
    typename is_wstring<T>::type buf(length = (string_size(_Format) + _STDEX_TYPE BUFFER_LENGTH - 1) /
        _STDEX_TYPE BUFFER_LENGTH * _STDEX_TYPE BUFFER_LENGTH - 1, typename is_wstring<T>::_Elem());
    while (-1 == (result = _STDEX_MY _sprintf(const_cast<typename is_wstring<T>::_Elem*>(buf.c_str()), length + 1, string_forward(_Format) MY_C_A0_A1_STRFWD)))
        buf.resize(length = length > _STDEX_TYPE MAX_BUFFER_LENGTH ? length + _STDEX_TYPE MAX_BUFFER_LENGTH : length * 2 + 1);
    assert(result <= length);
    if (result < length)
        buf.resize(result);
    return _STD move(buf);
}

template<typename T MY_C_CLASS_ARG0> inline
/* format string to std::string using _sprintf, initial buffer with send size */
auto string_printf(size_t _InitialBufferStringSize, T&& _Format MY_C_ARG0_A0_REFREF) -> typename is_wstring<T>::type
{
    static_assert(is_string<T>::value || is_wstring<T>::value, "_Format is NOT a string");
    assert(_InitialBufferStringSize != 0);
    assert(_InitialBufferStringSize != -1);
    size_t result, length;
    typename is_wstring<T>::type buf(length = (_InitialBufferStringSize + _STDEX_TYPE BUFFER_LENGTH - 1) /
        _STDEX_TYPE BUFFER_LENGTH * _STDEX_TYPE BUFFER_LENGTH - 1, typename is_wstring<T>::_Elem());
    while (-1 == (result = _STDEX_MY _sprintf(const_cast<typename is_wstring<T>::_Elem*>(buf.c_str()), length + 1, string_forward(_Format) MY_C_A0_A1_STRFWD)))
        buf.resize(length = length > _STDEX_TYPE MAX_BUFFER_LENGTH ? length + _STDEX_TYPE MAX_BUFFER_LENGTH : length * 2 + 1);
    assert(result <= length);
    if (result < length)
        buf.resize(result);
    return _STD move(buf);
}

template<typename T MY_C_CLASS_ARG0> inline
/* format string to std::string using _sprintf, initial buffer with send size */
auto string_printf(ssize_t _InitialBufferStringSize, T&& _Format MY_C_ARG0_A0_REFREF) -> typename is_wstring<T>::type
{
    static_assert(is_string<T>::value || is_wstring<T>::value, "_Format is NOT a string");
    assert(_InitialBufferStringSize != 0);
    assert(_InitialBufferStringSize != -1);
    return string_printf((size_t)_InitialBufferStringSize, _STD forward<T>(_Format) MY_C_A0_A1_FWD);
}

template<size_t _InitialBufferStringSize, typename T MY_C_CLASS_ARG0> inline
/* format string to std::string using _sprintf, initial buffer with send size */
auto string_printf(T&& _Format MY_C_ARG0_A0_REFREF) -> typename is_wstring<T>::type
{
    static_assert(is_string<T>::value || is_wstring<T>::value, "_Format is NOT a string");
    static_assert(_InitialBufferStringSize != 0, "_InitialBufferStringSize cannot be zero");
    static_assert(_InitialBufferStringSize != -1, "_InitialBufferStringSize cannot be -1");
    size_t result, length;
    typename is_wstring<T>::type buf(length = (_InitialBufferStringSize + _STDEX_TYPE BUFFER_LENGTH - 1) /
        _STDEX_TYPE BUFFER_LENGTH * _STDEX_TYPE BUFFER_LENGTH - 1, typename is_wstring<T>::_Elem());
    while (-1 == (result = _STDEX_MY _sprintf(const_cast<typename is_wstring<T>::_Elem*>(buf.c_str()), length + 1, string_forward(_Format) MY_C_A0_A1_STRFWD)))
        buf.resize(length = length > _STDEX_TYPE MAX_BUFFER_LENGTH ? length + _STDEX_TYPE MAX_BUFFER_LENGTH : length * 2 + 1);
    assert(result <= length);
    if (result < length)
        buf.resize(result);
    return _STD move(buf);
}



template<bool _EndLine DEF_VALUE(false), typename T MY_C_CLASS_ARG0> inline
/* output format string to stdout */
size_t std_printf(T&& _Format MY_C_ARG0_A0_REFREF)
{
    static_assert(is_string<T>::value || is_wstring<T>::value, "_Format is NOT a string");
    if (_EndLine)
    {
        size_t result = _STDEX_MY _printf(string_forward(_Format) MY_C_A0_A1_STRFWD);
        puts(_STDEX_TYPE endline<typename is_wstring<T>::_Elem>::pointer());
        return result + string_size(_STDEX_TYPE endline<typename is_wstring<T>::_Elem>::string());
    }
    else
        return _STDEX_MY _printf(string_forward(_Format) MY_C_A0_A1_STRFWD);
}

#if _MSC_VER < 1800
template<typename _Ty MY_C_CLASS_ARG0> inline
size_t std_printf(_Ty&& _Flag MY_C_ARG0_A0_REFREF)
{
    return std_printf<false>(_STD forward<_Ty>(_Flag) MY_C_A0_A1_FWD);
}
#endif /* _MSC_VER < 1800 */



template<bool _EndLine DEF_VALUE(false), typename _Elem, typename _Traits, typename T MY_C_CLASS_ARG0> inline
/* output format string to ostream */
size_t stream_printf(_STD basic_ostream<_Elem, _Traits>& _Out, T&& _Format MY_C_ARG0_A0_REFREF)
{
    static_assert(is_string<T>::value || is_wstring<T>::value, "_Format is NOT a string");
    static_assert(_STD is_same<_Elem, typename is_wstring<T>::_Elem>::value, "_Out do not match _Format element");
    typename is_wstring<T>::type buffer = string_printf(_STD forward<T>(_Format) MY_C_A0_A1_FWD);
    if (_EndLine)
        buffer.push_back(typename is_wstring<T>::_Elem('\n'));
    fputs(_Out, buffer);
    return string_size(buffer);
}

template<bool _EndLine DEF_VALUE(false), typename T MY_C_CLASS_ARG0> inline
/* output format string to FILE* */
size_t stream_printf(FILE* _File, T&& _Format MY_C_ARG0_A0_REFREF)
{
    assert(_File);
    static_assert(is_string<T>::value || is_wstring<T>::value, "_Format is NOT a string");
    if (_EndLine)
    {
        size_t result = _STDEX_MY _fprintf(_File, string_forward(_Format) MY_C_A0_A1_STRFWD);
        fputs(_File, _STDEX_TYPE endline<typename is_wstring<T>::_Elem>::pointer());
        return result + string_size(_STDEX_TYPE endline<typename is_wstring<T>::_Elem>::string());
    }
    else
        return _STDEX_MY _fprintf(_File, string_forward(_Format) MY_C_A0_A1_STRFWD);
}

#if HAVE_WINDOWS
template<bool _EndLine DEF_VALUE(false), typename T MY_C_CLASS_ARG0> inline
/* output format string to SystemDebugOutput */
size_t stream_printf(csys_t& _csys, T&& _Format MY_C_ARG0_A0_REFREF)
{
    static_assert(is_string<T>::value || is_wstring<T>::value, "_Format is NOT a string");
    typename is_wstring<T>::type buffer = string_printf(_STD forward<T>(_Format) MY_C_A0_A1_FWD);
    if (_EndLine)
        buffer.push_back(typename is_wstring<T>::_Elem('\n'));
    fputs(_csys, buffer);
    return string_size(buffer);
}

#endif /* HAVE_WINDOWS */

#if _MSC_VER < 1800
template<typename _Ty MY_C_CLASS_ARG0> inline
size_t stream_printf(_Ty&& _Flag MY_C_ARG0_A0_REFREF)
{
    return stream_printf<false>(_STD forward<_Ty>(_Flag) MY_C_A0_A1_FWD);
}
#endif /* _MSC_VER < 1800 */



template<bool _EndLine DEF_VALUE(false), bool _Force DEF_VALUE(false), typename T MY_C_CLASS_ARG0> inline
/* format debug string if force: debug_printf<endl, force format string> */
/* the return value is pair<format string(if force), (bool)force> */
auto debug_printf(T&& _Format MY_C_ARG0_A0_REFREF)
-> _STD pair<typename _STDEX_TYPE format_string_type<T MY_C_ARG0_ARG1>::type, bool>
{
    static_assert(is_string<T>::value || is_wstring<T>::value, "_Format is NOT a string");
    if (_Force)
    {
        typename is_wstring<T>::type buffer = string_printf(_STD forward<T>(_Format) MY_C_A0_A1_FWD);
        if (_EndLine)
            buffer.push_back(typename is_wstring<T>::_Elem('\n'));
        return _STD make_pair(_STD move(buffer), _Force);
    }
    else
        return _STD make_pair(typename is_wstring<T>::type(), _Force);
}

template<bool _EndLine DEF_VALUE(false), bool _Force DEF_VALUE(false), typename _Elem, typename _Traits MY_C_CLASS_ARG0> inline
/* output format string to ostream... */
auto debug_printf(_STD basic_ostream<_Elem, _Traits>& _Out MY_C_ARG0_A0_REFREF)
-> _STD pair<typename _STDEX_TYPE format_string_type<MY_ARG0_ARG1>::type, bool>
{
    auto buffer = debug_printf<_EndLine, true>(MY_A0_A1_FWD);
    static_assert(_STD is_same<_Elem, typename is_wstring<decltype(buffer.first)>::_Elem>::value, "_Out do not match _Format element");
    stream_puts(_Out, buffer.first);
    return _STD move(buffer);
}

template<bool _EndLine DEF_VALUE(false), bool _Force DEF_VALUE(false), typename _Elem, typename _Traits MY_C_CLASS_ARG0> inline
/* output format string to ostream*... */
auto debug_printf(_STD basic_ostream<_Elem, _Traits>* _pOut MY_C_ARG0_A0_REFREF)
-> _STD pair<typename _STDEX_TYPE format_string_type<MY_ARG0_ARG1>::type, bool>
{
    if (_pOut)
        return debug_printf<_EndLine, _Force>(*_pOut MY_C_A0_A1_FWD);
    else
        return debug_printf<_EndLine, _Force>(MY_A0_A1_FWD);
}

template<bool _EndLine DEF_VALUE(false), bool _Force DEF_VALUE(false) MY_C_CLASS_ARG0> inline
/* output format string to FILE*... */
auto debug_printf(FILE* _File MY_C_ARG0_A0_REFREF)
-> _STD pair<typename _STDEX_TYPE format_string_type<MY_ARG0_ARG1>::type, bool>
{
    if (_File)
    {
        auto buffer = debug_printf<_EndLine, true>(MY_A0_A1_FWD);
        stream_puts(_File, buffer.first);
        return _STD move(buffer);
    }
    else
        return debug_printf<_EndLine, _Force>(MY_A0_A1_FWD);
}

template<bool _EndLine DEF_VALUE(false), bool _Force DEF_VALUE(false) MY_C_CLASS_ARG0> inline
/* output format string to FILE**... */
auto debug_printf(FILE** _pFile MY_C_ARG0_A0_REFREF)
-> _STD pair<typename _STDEX_TYPE format_string_type<MY_ARG0_ARG1>::type, bool>
{
    if (_pFile)
        return debug_printf<_EndLine, _Force>(*_pFile MY_C_A0_A1_FWD);
    else
        return debug_printf<_EndLine, _Force>(MY_A0_A1_FWD);
}

template<bool _EndLine DEF_VALUE(false), bool _Force DEF_VALUE(false) MY_C_CLASS_ARG0> inline
/* output format string to void*... */
auto debug_printf(void* MY_C_ARG0_A0_REFREF)
-> _STD pair<typename _STDEX_TYPE format_string_type<MY_ARG0_ARG1>::type, bool>
{
    return debug_printf<_EndLine, _Force>(MY_A0_A1_FWD);
}

template<bool _EndLine DEF_VALUE(false), bool _Force DEF_VALUE(false) MY_C_CLASS_ARG0> inline
/* output format string to const void*... */
auto debug_printf(const void* MY_C_ARG0_A0_REFREF)
-> _STD pair<typename _STDEX_TYPE format_string_type<MY_ARG0_ARG1>::type, bool>
{
    return debug_printf<_EndLine, _Force>(MY_A0_A1_FWD);
}

template<bool _EndLine DEF_VALUE(false), bool _Force DEF_VALUE(false) MY_C_CLASS_ARG0> inline
/* output format string to nullptr... */
auto debug_printf(_STD nullptr_t MY_C_ARG0_A0_REFREF)
-> _STD pair<typename _STDEX_TYPE format_string_type<MY_ARG0_ARG1>::type, bool>
{
    return debug_printf<_EndLine, _Force>(MY_A0_A1_FWD);
}

#if HAVE_WINDOWS
template<bool _EndLine DEF_VALUE(false), bool _Force DEF_VALUE(false) MY_C_CLASS_ARG0> inline
/* output format string to SystemDebugOutput... */
auto debug_printf(csys_t& _csys MY_C_ARG0_A0_REFREF)
-> _STD pair<typename _STDEX_TYPE format_string_type<MY_ARG0_ARG1>::type, bool>
{
    auto buffer = debug_printf<_EndLine, true>(MY_A0_A1_FWD);
    stream_puts(_csys, buffer.first);
    return _STD move(buffer);
}

template<bool _EndLine DEF_VALUE(false), bool _Force DEF_VALUE(false) MY_C_CLASS_ARG0> inline
/* output format string to SystemDebugOutput*... */
auto debug_printf(csys_t* _pcsys MY_C_ARG0_A0_REFREF)
-> _STD pair<typename _STDEX_TYPE format_string_type<MY_ARG0_ARG1>::type, bool>
{
    if (_pcsys)
        return debug_printf<_EndLine, _Force>(*_pcsys MY_C_A0_A1_FWD);
    else
        return debug_printf<_EndLine, _Force>(MY_A0_A1_FWD);
}

#endif /* HAVE_WINDOWS */

#if _MSC_VER < 1800
template<typename _Ty MY_C_CLASS_ARG0> inline
/* format debug string if force: debug_printf<endl, force format string> */
/* the return value is pair<format string(if force), (bool)force> */
auto debug_printf(_Ty&& _Flag MY_C_ARG0_A0_REFREF)
-> _STD pair<typename _STDEX_TYPE format_string_type<_Ty MY_C_ARG0_ARG1>::type, bool>
{
    return debug_printf<false, false>(_STD forward<_Ty>(_Flag) MY_C_A0_A1_FWD);
}

template<bool _EndLine, typename _Ty MY_C_CLASS_ARG0> inline
/* format debug string if force: debug_printf<endl, force format string> */
/* the return value is pair<format string(if force), (bool)force> */
auto debug_printf(_Ty&& _Flag MY_C_ARG0_A0_REFREF)
-> _STD pair<typename _STDEX_TYPE format_string_type<_Ty MY_C_ARG0_ARG1>::type, bool>
{
    return debug_printf<_EndLine, false>(_STD forward<_Ty>(_Flag) MY_C_A0_A1_FWD);
}

#endif /* _MSC_VER < 1800 */



template<bool _EndLine DEF_VALUE(false), typename T, typename _Elem, typename _Traits MY_C_CLASS_ARG0> inline
/* output string to ostream... */
void debug_puts(T&& _String, _STD basic_ostream<_Elem, _Traits>& _Out MY_C_ARG0_A0_REFREF)
{
    static_assert(is_string<T>::value || is_wstring<T>::value, "_String is NOT a string");
    static_assert(_STD is_same<_Elem, typename is_wstring<T>::_Elem>::value, "_Out do not match _Format element");
    if (_EndLine)
    {   /* only move() if _String is a rvalue */
        typename is_wstring<T>::type buffer = _STD forward<T>(_String);
        buffer.push_back(typename is_wstring<T>::_Elem('\n'));
        stream_puts(_Out, buffer);
        return debug_puts<false>(_STD move(buffer) MY_C_A0_A1_FWD);
    }
    else
    {
        stream_puts(_Out, _String);
        return debug_puts<_EndLine>(_STD forward<T>(_String) MY_C_A0_A1_FWD);
    }
}

template<bool _EndLine DEF_VALUE(false), typename T, typename _Elem, typename _Traits MY_C_CLASS_ARG0> inline
/* output string to ostream*... */
void debug_puts(T&& _String, _STD basic_ostream<_Elem, _Traits>* _pOut MY_C_ARG0_A0_REFREF)
{
    static_assert(is_string<T>::value || is_wstring<T>::value, "_String is NOT a string");
    static_assert(_STD is_same<_Elem, typename is_wstring<T>::_Elem>::value, "_pOut do not match _Format element");
    if (_pOut)
        return debug_puts<_EndLine>(_STD forward<T>(_String), *_pOut MY_C_A0_A1_FWD);
    else
        return debug_puts<_EndLine>(_STD forward<T>(_String) MY_C_A0_A1_FWD);
}

template<bool _EndLine DEF_VALUE(false), typename T MY_C_CLASS_ARG0> inline
/* output string to FILE*... */
void debug_puts(T&& _String, FILE* _File MY_C_ARG0_A0_REFREF)
{
    static_assert(is_string<T>::value || is_wstring<T>::value, "_String is NOT a string");
    if (_EndLine)
    {
        if (_File)
        {   /* only move() if _String is a rvalue */
            typename is_wstring<T>::type buffer = _STD forward<T>(_String);
            buffer.push_back(typename is_wstring<T>::_Elem('\n'));
            stream_puts(_File, buffer);
            return debug_puts<false>(_STD move(buffer) MY_C_A0_A1_FWD);
        }
        else
            return debug_puts<_EndLine>(_STD forward<T>(_String) MY_C_A0_A1_FWD);
    }
    else
    {
        if (_File)
            stream_puts(_File, _String);
        return debug_puts<_EndLine>(_STD forward<T>(_String) MY_C_A0_A1_FWD);
    }
}

template<bool _EndLine DEF_VALUE(false), typename T MY_C_CLASS_ARG0> inline
/* output string to FILE**... */
void debug_puts(T&& _String, FILE** _pFile MY_C_ARG0_A0_REFREF)
{
    static_assert(is_string<T>::value || is_wstring<T>::value, "_String is NOT a string");
    if (_pFile)
        return debug_puts<_EndLine>(_STD forward<T>(_String), *_pFile MY_C_A0_A1_FWD);
    else
        return debug_puts<_EndLine>(_STD forward<T>(_String) MY_C_A0_A1_FWD);
}

template<bool _EndLine DEF_VALUE(false), typename T MY_C_CLASS_ARG0> inline
/* output string to void*... */
void debug_puts(T&& _String, void* MY_C_ARG0_A0_REFREF)
{
    static_assert(is_string<T>::value || is_wstring<T>::value, "_String is NOT a string");
    return debug_puts<_EndLine>(_STD forward<T>(_String) MY_C_A0_A1_FWD);
}

template<bool _EndLine DEF_VALUE(false), typename T MY_C_CLASS_ARG0> inline
/* output string to const void*... */
void debug_puts(T&& _String, const void* MY_C_ARG0_A0_REFREF)
{
    static_assert(is_string<T>::value || is_wstring<T>::value, "_String is NOT a string");
    return debug_puts<_EndLine>(_STD forward<T>(_String) MY_C_A0_A1_FWD);
}

template<bool _EndLine DEF_VALUE(false), typename T MY_C_CLASS_ARG0> inline
/* output string to nullptr... */
void debug_puts(T&& _String, _STD nullptr_t MY_C_ARG0_A0_REFREF)
{
    static_assert(is_string<T>::value || is_wstring<T>::value, "_String is NOT a string");
    return debug_puts<_EndLine>(_STD forward<T>(_String) MY_C_A0_A1_FWD);
}

#if HAVE_WINDOWS
template<bool _EndLine DEF_VALUE(false), typename T MY_C_CLASS_ARG0> inline
/* output string to SystemDebugOutput... */
void debug_puts(T&& _String, csys_t& _csys MY_C_ARG0_A0_REFREF)
{
    static_assert(is_string<T>::value || is_wstring<T>::value, "_String is NOT a string");
    if (_EndLine)
    {   /* only move() if _String is a rvalue */
        typename is_wstring<T>::type buffer = _STD forward<T>(_String);
        buffer.push_back(typename is_wstring<T>::_Elem('\n'));
        stream_puts(_csys, buffer);
        return debug_puts<false>(_STD move(buffer) MY_C_A0_A1_FWD);
    }
    else
    {
        stream_puts(_csys, _String);
        return debug_puts<_EndLine>(_STD forward<T>(_String) MY_C_A0_A1_FWD);
    }
}

template<bool _EndLine DEF_VALUE(false), typename T MY_C_CLASS_ARG0> inline
/* output string to SystemDebugOutput*... */
void debug_puts(T&& _String, csys_t* _pcsys MY_C_ARG0_A0_REFREF)
{
    static_assert(is_string<T>::value || is_wstring<T>::value, "_String is NOT a string");
    if (_pcsys)
        return debug_puts<_EndLine>(_STD forward<T>(_String), *_pcsys MY_C_A0_A1_FWD);
    else
        return debug_puts<_EndLine>(_STD forward<T>(_String) MY_C_A0_A1_FWD);
}

#endif /* HAVE_WINDOWS */

#if _MSC_VER < 1800
template<typename _Ty1, typename _Ty2 MY_C_CLASS_ARG0> inline
void debug_puts(_Ty1&& _Flag1, _Ty2&& _Flag2 MY_C_ARG0_A0_REFREF)
{
    debug_puts<false>(_STD forward<_Ty1>(_Flag1), _STD forward<_Ty2>(_Flag2) MY_C_A0_A1_FWD);
}
#endif /* _MSC_VER < 1800 */
