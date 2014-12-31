#ifndef _STRINGPRINTF_STL_EXTRA_H_
#define _STRINGPRINTF_STL_EXTRA_H_

#ifdef _STRINGPRINTF_H_

_STDEX_BEGIN _STDEX_TYPE_BEGIN


/* string compare nocase */

/* struct string_equal_to_nocase */
typedef struct string_equal_to_nocase FIX_VS_STL_RESULT_TYPE(bool)
{
    template<typename _Ty1, typename _Ty2> inline bool operator()(_Ty1&& _Str1, _Ty2&& _Str2) const
    {
        static_assert(is_string<_Ty1>::value || is_wstring<_Ty1>::value, "_Str1 is NOT a string");
        static_assert(is_string<_Ty2>::value || is_wstring<_Ty2>::value, "_Str2 is NOT a string");
        static_assert(_STD is_same<typename is_wstring<_Ty1>::_Elem, typename is_wstring<_Ty2>::_Elem>::value,
            "_Str2 do not match _Str1 element");
        return stricmp(_Str1, _Str2) == NULL;
    }
} equal_to_nocase;

/* struct string_not_equal_to_nocase */
typedef struct string_not_equal_to_nocase FIX_VS_STL_RESULT_TYPE(bool)
{
    template<typename _Ty1, typename _Ty2> inline bool operator()(_Ty1&& _Str1, _Ty2&& _Str2) const
    {
        static_assert(is_string<_Ty1>::value || is_wstring<_Ty1>::value, "_Str1 is NOT a string");
        static_assert(is_string<_Ty2>::value || is_wstring<_Ty2>::value, "_Str2 is NOT a string");
        static_assert(_STD is_same<typename is_wstring<_Ty1>::_Elem, typename is_wstring<_Ty2>::_Elem>::value,
            "_Str2 do not match _Str1 element");
        return stricmp(_Str1, _Str2) != NULL;
    }
} not_equal_to_nocase;

/* struct string_greater_nocase */
typedef struct string_greater_nocase FIX_VS_STL_RESULT_TYPE(bool)
{
    template<typename _Ty1, typename _Ty2> inline bool operator()(_Ty1&& _Str1, _Ty2&& _Str2) const
    {
        static_assert(is_string<_Ty1>::value || is_wstring<_Ty1>::value, "_Str1 is NOT a string");
        static_assert(is_string<_Ty2>::value || is_wstring<_Ty2>::value, "_Str2 is NOT a string");
        static_assert(_STD is_same<typename is_wstring<_Ty1>::_Elem, typename is_wstring<_Ty2>::_Elem>::value,
            "_Str2 do not match _Str1 element");
        return stricmp(_Str1, _Str2) > NULL;
    }
} greater_nocase;

/* struct string_greater_equal_nocase */
typedef struct string_greater_equal_nocase FIX_VS_STL_RESULT_TYPE(bool)
{
    template<typename _Ty1, typename _Ty2> inline bool operator()(_Ty1&& _Str1, _Ty2&& _Str2) const
    {
        static_assert(is_string<_Ty1>::value || is_wstring<_Ty1>::value, "_Str1 is NOT a string");
        static_assert(is_string<_Ty2>::value || is_wstring<_Ty2>::value, "_Str2 is NOT a string");
        static_assert(_STD is_same<typename is_wstring<_Ty1>::_Elem, typename is_wstring<_Ty2>::_Elem>::value,
            "_Str2 do not match _Str1 element");
        return stricmp(_Str1, _Str2) >= NULL;
    }
} greater_equal_nocase;

/* struct string_less_nocase */
typedef struct string_less_nocase FIX_VS_STL_RESULT_TYPE(bool)
{
    template<typename _Ty1, typename _Ty2> inline bool operator()(_Ty1&& _Str1, _Ty2&& _Str2) const
    {
        static_assert(is_string<_Ty1>::value || is_wstring<_Ty1>::value, "_Str1 is NOT a string");
        static_assert(is_string<_Ty2>::value || is_wstring<_Ty2>::value, "_Str2 is NOT a string");
        static_assert(_STD is_same<typename is_wstring<_Ty1>::_Elem, typename is_wstring<_Ty2>::_Elem>::value,
            "_Str2 do not match _Str1 element");
        return stricmp(_Str1, _Str2) < NULL;
    }
} less_nocase;

/* struct string_less_equal_nocase */
typedef struct string_less_equal_nocase FIX_VS_STL_RESULT_TYPE(bool)
{
    template<typename _Ty1, typename _Ty2> inline bool operator()(_Ty1&& _Str1, _Ty2&& _Str2) const
    {
        static_assert(is_string<_Ty1>::value || is_wstring<_Ty1>::value, "_Str1 is NOT a string");
        static_assert(is_string<_Ty2>::value || is_wstring<_Ty2>::value, "_Str2 is NOT a string");
        static_assert(_STD is_same<typename is_wstring<_Ty1>::_Elem, typename is_wstring<_Ty2>::_Elem>::value,
            "_Str2 do not match _Str1 element");
        return stricmp(_Str1, _Str2) <= NULL;
    }
} less_equal_nocase;

_STDEX_TYPE_END

using _STDEX_TYPE equal_to_nocase;
using _STDEX_TYPE not_equal_to_nocase;
using _STDEX_TYPE greater_nocase;
using _STDEX_TYPE greater_equal_nocase;
using _STDEX_TYPE less_nocase;
using _STDEX_TYPE less_equal_nocase;


_STDEX_TYPE_BEGIN

/* struct _Tuple_compare_l */
template<size_t _LIndex, typename _Pr>
struct _Tuple_compare_l FIX_VS_STL_RESULT_TYPE(bool)
{
    _Pr _Pred;
    inline _Tuple_compare_l(_Pr __Pred) : _Pred(__Pred){}
    template<typename _Ty1, typename _Ty2> inline auto operator()(_Ty1&& _Left, _Ty2&& _Right) const
        -> decltype(_Pred(_STD get<_LIndex>(_STD forward<_Ty1>(_Left)), _STD forward<_Ty2>(_Right)))
    {
        return _Pred(_STD get<_LIndex>(_STD forward<_Ty1>(_Left)), _STD forward<_Ty2>(_Right));
    }
};

/* struct _Tuple_compare_r */
template<size_t _RIndex, typename _Pr>
struct _Tuple_compare_r FIX_VS_STL_RESULT_TYPE(bool)
{
    _Pr _Pred;
    inline _Tuple_compare_r(_Pr __Pred) : _Pred(__Pred){}
    template<typename _Ty1, typename _Ty2> inline auto operator()(_Ty1&& _Left, _Ty2&& _Right) const
        -> decltype(_Pred(_STD forward<_Ty1>(_Left), _STD get<_RIndex>(_STD forward<_Ty2>(_Right))))
    {
        return _Pred(_STD forward<_Ty1>(_Left), _STD get<_RIndex>(_STD forward<_Ty2>(_Right)));
    }
};

/* struct _Tuple_compare_lr */
template<size_t _LIndex, size_t _RIndex, typename _Pr>
struct _Tuple_compare_lr FIX_VS_STL_RESULT_TYPE(bool)
{
    _Pr _Pred;
    inline _Tuple_compare_lr(_Pr __Pred) : _Pred(__Pred){}
    template<typename _Ty1, typename _Ty2> inline auto operator()(_Ty1&& _Left, _Ty2&& _Right) const
        -> decltype(_Pred(_STD get<_LIndex>(_STD forward<_Ty1>(_Left)),
            _STD get<_RIndex>(_STD forward<_Ty2>(_Right))))
    {
        return _Pred(_STD get<_LIndex>(_STD forward<_Ty1>(_Left)),
            _STD get<_RIndex>(_STD forward<_Ty2>(_Right)));
    }
};


/* struct _Tuple_compare_ll */
template<size_t _LIndex1, size_t _LIndex2, typename _Pr>
struct _Tuple_compare_ll FIX_VS_STL_RESULT_TYPE(bool)
{
    _Pr _Pred;
    inline _Tuple_compare_ll(_Pr __Pred) : _Pred(__Pred){}
    template<typename _Ty1, typename _Ty2> inline auto operator()(_Ty1&& _Left, _Ty2&& _Right) const
        -> decltype(_Pred(_STD get<_LIndex2>(_STD get<_LIndex1>(_STD forward<_Ty1>(_Left))),
            _STD forward<_Ty2>(_Right)))
    {
        return _Pred(_STD get<_LIndex2>(_STD get<_LIndex1>(_STD forward<_Ty1>(_Left))),
            _STD forward<_Ty2>(_Right));
    }
};

/* struct _Tuple_compare_rr */
template<size_t _RIndex1, size_t _RIndex2, typename _Pr>
struct _Tuple_compare_rr FIX_VS_STL_RESULT_TYPE(bool)
{
    _Pr _Pred;
    inline _Tuple_compare_rr(_Pr __Pred) : _Pred(__Pred){}
    template<typename _Ty1, typename _Ty2> inline auto operator()(_Ty1&& _Left, _Ty2&& _Right) const
        -> decltype(_Pred(_STD forward<_Ty1>(_Left),
            _STD get<_RIndex2>(_STD get<_RIndex1>(_STD forward<_Ty2>(_Right)))))
    {
        return _Pred(_STD forward<_Ty1>(_Left),
            _STD get<_RIndex2>(_STD get<_RIndex1>(_STD forward<_Ty2>(_Right))));
    }
};

/* struct _Tuple_compare_llr */
template<size_t _LIndex1, size_t _LIndex2, size_t _RIndex, typename _Pr>
struct _Tuple_compare_llr FIX_VS_STL_RESULT_TYPE(bool)
{
    _Pr _Pred;
    inline _Tuple_compare_llr(_Pr __Pred) : _Pred(__Pred){}
    template<typename _Ty1, typename _Ty2> inline auto operator()(_Ty1&& _Left, _Ty2&& _Right) const
        -> decltype(_Pred(_STD get<_LIndex2>(_STD get<_LIndex1>(_STD forward<_Ty1>(_Left))),
            _STD get<_RIndex>(_STD forward<_Ty2>(_Right))))
    {
        return _Pred(_STD get<_LIndex2>(_STD get<_LIndex1>(_STD forward<_Ty1>(_Left))),
            _STD get<_RIndex>(_STD forward<_Ty2>(_Right)));
    }
};

/* struct _Tuple_compare_lrr */
template<size_t _LIndex, size_t _RIndex1, size_t _RIndex2, typename _Pr>
struct _Tuple_compare_lrr FIX_VS_STL_RESULT_TYPE(bool)
{
    _Pr _Pred;
    inline _Tuple_compare_lrr(_Pr __Pred) : _Pred(__Pred){}
    template<typename _Ty1, typename _Ty2> inline auto operator()(_Ty1&& _Left, _Ty2&& _Right) const
        -> decltype(_Pred(_STD get<_LIndex>(_STD forward<_Ty1>(_Left)),
            _STD get<_RIndex2>(_STD get<_RIndex1>(_STD forward<_Ty2>(_Right)))))
    {
        return _Pred(_STD get<_LIndex>(_STD forward<_Ty1>(_Left)),
            _STD get<_RIndex2>(_STD get<_RIndex1>(_STD forward<_Ty2>(_Right))));
    }
};

/* struct _Tuple_compare_llrr */
template<size_t _LIndex1, size_t _LIndex2, size_t _RIndex1, size_t _RIndex2, typename _Pr>
struct _Tuple_compare_llrr FIX_VS_STL_RESULT_TYPE(bool)
{
    _Pr _Pred;
    inline _Tuple_compare_llrr(_Pr __Pred) : _Pred(__Pred){}
    template<typename _Ty1, typename _Ty2> inline auto operator()(_Ty1&& _Left, _Ty2&& _Right) const
        -> decltype(_Pred(_STD get<_LIndex2>(_STD get<_LIndex1>(_STD forward<_Ty1>(_Left))),
            _STD get<_RIndex2>(_STD get<_RIndex1>(_STD forward<_Ty2>(_Right)))))
    {
        return _Pred(_STD get<_LIndex2>(_STD get<_LIndex1>(_STD forward<_Ty1>(_Left))),
            _STD get<_RIndex2>(_STD get<_RIndex1>(_STD forward<_Ty2>(_Right))));
    }
};


/* struct _Tuple_compare_lll */
template<size_t _LIndex1, size_t _LIndex2, size_t _LIndex3, typename _Pr>
struct _Tuple_compare_lll FIX_VS_STL_RESULT_TYPE(bool)
{
    _Pr _Pred;
    inline _Tuple_compare_lll(_Pr __Pred) : _Pred(__Pred){}
    template<typename _Ty1, typename _Ty2> inline auto operator()(_Ty1&& _Left, _Ty2&& _Right) const
        -> decltype(_Pred(_STD get<_LIndex3>(_STD get<_LIndex2>(_STD get<_LIndex1>(_STD forward<_Ty1>(_Left)))),
            _STD forward<_Ty2>(_Right)))
    {
        return _Pred(_STD get<_LIndex3>(_STD get<_LIndex2>(_STD get<_LIndex1>(_STD forward<_Ty1>(_Left)))),
            _STD forward<_Ty2>(_Right));
    }
};

/* struct _Tuple_compare_rrr */
template<size_t _RIndex1, size_t _RIndex2, size_t _RIndex3, typename _Pr>
struct _Tuple_compare_rrr FIX_VS_STL_RESULT_TYPE(bool)
{
    _Pr _Pred;
    inline _Tuple_compare_rrr(_Pr __Pred) : _Pred(__Pred){}
    template<typename _Ty1, typename _Ty2> inline auto operator()(_Ty1&& _Left, _Ty2&& _Right) const
        -> decltype(_Pred(_STD forward<_Ty1>(_Left),
            _STD get<_RIndex3>(_STD get<_RIndex2>(_STD get<_RIndex1>(_STD forward<_Ty2>(_Right))))))
    {
        return _Pred(_STD forward<_Ty1>(_Left),
            _STD get<_RIndex3>(_STD get<_RIndex2>(_STD get<_RIndex1>(_STD forward<_Ty2>(_Right)))));
    }
};

/* struct _Tuple_compare_lllr */
template<size_t _LIndex1, size_t _LIndex2, size_t _LIndex3, size_t _RIndex, typename _Pr>
struct _Tuple_compare_lllr FIX_VS_STL_RESULT_TYPE(bool)
{
    _Pr _Pred;
    inline _Tuple_compare_lllr(_Pr __Pred) : _Pred(__Pred){}
    template<typename _Ty1, typename _Ty2> inline auto operator()(_Ty1&& _Left, _Ty2&& _Right) const
        -> decltype(_Pred(_STD get<_LIndex3>(_STD get<_LIndex2>(_STD get<_LIndex1>(_STD forward<_Ty1>(_Left)))),
            _STD get<_RIndex>(_STD forward<_Ty2>(_Right))))
    {
        return _Pred(_STD get<_LIndex3>(_STD get<_LIndex2>(_STD get<_LIndex1>(_STD forward<_Ty1>(_Left)))),
            _STD get<_RIndex>(_STD forward<_Ty2>(_Right)));
    }
};

/* struct _Tuple_compare_lllrr */
template<size_t _LIndex1, size_t _LIndex2, size_t _LIndex3, size_t _RIndex1, size_t _RIndex2, typename _Pr>
struct _Tuple_compare_lllrr FIX_VS_STL_RESULT_TYPE(bool)
{
    _Pr _Pred;
    inline _Tuple_compare_lllrr(_Pr __Pred) : _Pred(__Pred){}
    template<typename _Ty1, typename _Ty2> inline auto operator()(_Ty1&& _Left, _Ty2&& _Right) const
        -> decltype(_Pred(_STD get<_LIndex3>(_STD get<_LIndex2>(_STD get<_LIndex1>(_STD forward<_Ty1>(_Left)))),
            _STD get<_RIndex2>(_STD get<_RIndex1>(_STD forward<_Ty2>(_Right)))))
    {
        return _Pred(_STD get<_LIndex3>(_STD get<_LIndex2>(_STD get<_LIndex1>(_STD forward<_Ty1>(_Left)))),
            _STD get<_RIndex2>(_STD get<_RIndex1>(_STD forward<_Ty2>(_Right))));
    }
};

/* struct _Tuple_compare_lrrr */
template<size_t _LIndex, size_t _RIndex1, size_t _RIndex2, size_t _RIndex3, typename _Pr>
struct _Tuple_compare_lrrr FIX_VS_STL_RESULT_TYPE(bool)
{
    _Pr _Pred;
    inline _Tuple_compare_lrrr(_Pr __Pred) : _Pred(__Pred){}
    template<typename _Ty1, typename _Ty2> inline auto operator()(_Ty1&& _Left, _Ty2&& _Right) const
        -> decltype(_Pred(_STD get<_LIndex>(_STD forward<_Ty1>(_Left)),
            _STD get<_RIndex3>(_STD get<_RIndex2>(_STD get<_RIndex1>(_STD forward<_Ty2>(_Right))))))
    {
        return _Pred(_STD get<_LIndex>(_STD forward<_Ty1>(_Left)),
            _STD get<_RIndex3>(_STD get<_RIndex2>(_STD get<_RIndex1>(_STD forward<_Ty2>(_Right)))));
    }
};

/* struct _Tuple_compare_llrrr */
template<size_t _LIndex1, size_t _LIndex2, size_t _RIndex1, size_t _RIndex2, size_t _RIndex3, typename _Pr>
struct _Tuple_compare_llrrr FIX_VS_STL_RESULT_TYPE(bool)
{
    _Pr _Pred;
    inline _Tuple_compare_llrrr(_Pr __Pred) : _Pred(__Pred){}
    template<typename _Ty1, typename _Ty2> inline auto operator()(_Ty1&& _Left, _Ty2&& _Right) const
        -> decltype(_Pred(_STD get<_LIndex2>(_STD get<_LIndex1>(_STD forward<_Ty1>(_Left))),
            _STD get<_RIndex3>(_STD get<_RIndex2>(_STD get<_RIndex1>(_STD forward<_Ty2>(_Right))))))
    {
        return _Pred(_STD get<_LIndex2>(_STD get<_LIndex1>(_STD forward<_Ty1>(_Left))),
            _STD get<_RIndex3>(_STD get<_RIndex2>(_STD get<_RIndex1>(_STD forward<_Ty2>(_Right)))));
    }
};

/* struct _Tuple_compare_lllrrr */
template<size_t _LIndex1, size_t _LIndex2, size_t _LIndex3, size_t _RIndex1, size_t _RIndex2, size_t _RIndex3, typename _Pr>
struct _Tuple_compare_lllrrr FIX_VS_STL_RESULT_TYPE(bool)
{
    _Pr _Pred;
    inline _Tuple_compare_lllrrr(_Pr __Pred) : _Pred(__Pred){}
    template<typename _Ty1, typename _Ty2> inline auto operator()(_Ty1&& _Left, _Ty2&& _Right) const
        -> decltype(_Pred(_STD get<_LIndex3>(_STD get<_LIndex2>(_STD get<_LIndex1>(_STD forward<_Ty1>(_Left)))),
            _STD get<_RIndex3>(_STD get<_RIndex2>(_STD get<_RIndex1>(_STD forward<_Ty2>(_Right))))))
    {
        return _Pred(_STD get<_LIndex3>(_STD get<_LIndex2>(_STD get<_LIndex1>(_STD forward<_Ty1>(_Left)))),
            _STD get<_RIndex3>(_STD get<_RIndex2>(_STD get<_RIndex1>(_STD forward<_Ty2>(_Right)))));
    }
};

_STDEX_TYPE_END


#define _TUPLE_COMPARE_1(function_name)                                                                                                 \
template<size_t _Index> inline                                                                                                          \
/* compare algorithm tuple_ ## function_name */                                                                                         \
_STDEX_TYPE _Tuple_compare_lr<_Index, _Index, _STDEX_TYPE function_name> tuple_ ## function_name()                                      \
{                                                                                                                                       \
    return _STDEX_TYPE _Tuple_compare_lr<_Index, _Index, _STDEX_TYPE function_name>(_STDEX_TYPE function_name());                       \
}                                                                                                                                       \
template<size_t _Index, typename _Pr> inline                                                                                            \
/* compare algorithm tuple_ ## function_name using _Pr */                                                                               \
_STDEX_TYPE _Tuple_compare_lr<_Index, _Index, _Pr> tuple_ ## function_name(_Pr _Pred)                                                   \
{                                                                                                                                       \
    return _STDEX_TYPE _Tuple_compare_lr<_Index, _Index, _Pr>(_Pred);                                                                   \
}

#define _TUPLE_COMPARE_L(function_name)                                                                                                 \
template<size_t _LIndex> inline                                                                                                         \
/* compare algorithm tuple_ ## function_name ## _l */                                                                                   \
_STDEX_TYPE _Tuple_compare_l<_LIndex, _STDEX_TYPE function_name> tuple_ ## function_name ## _l()                                        \
{                                                                                                                                       \
    return _STDEX_TYPE _Tuple_compare_l<_LIndex, _STDEX_TYPE function_name>(_STDEX_TYPE function_name());                               \
}                                                                                                                                       \
template<size_t _LIndex, typename _Pr> inline                                                                                           \
/* compare algorithm tuple_ ## function_name ## _l using _Pr */                                                                         \
_STDEX_TYPE _Tuple_compare_l<_LIndex, _Pr> tuple_ ## function_name ## _l(_Pr _Pred)                                                     \
{                                                                                                                                       \
    return _STDEX_TYPE _Tuple_compare_l<_LIndex, _Pr>(_Pred);                                                                           \
}

#define _TUPLE_COMPARE_R(function_name)                                                                                                 \
template<size_t _RIndex> inline                                                                                                         \
/* compare algorithm tuple_ ## function_name ## _r */                                                                                   \
_STDEX_TYPE _Tuple_compare_r<_RIndex, _STDEX_TYPE function_name> tuple_ ## function_name ## _r()                                        \
{                                                                                                                                       \
    return _STDEX_TYPE _Tuple_compare_r<_RIndex, _STDEX_TYPE function_name>(_STDEX_TYPE function_name());                               \
}                                                                                                                                       \
template<size_t _RIndex, typename _Pr> inline                                                                                           \
/* compare algorithm tuple_ ## function_name ## _r using _Pr */                                                                         \
_STDEX_TYPE _Tuple_compare_r<_RIndex, _Pr> tuple_ ## function_name ## _r(_Pr _Pred)                                                     \
{                                                                                                                                       \
    return _STDEX_TYPE _Tuple_compare_r<_RIndex, _Pr>(_Pred);                                                                           \
}

#define _TUPLE_COMPARE_LR(function_name)                                                                                                \
template<size_t _LIndex, size_t _RIndex> inline                                                                                         \
/* compare algorithm tuple_ ## function_name ## _lr */                                                                                  \
_STDEX_TYPE _Tuple_compare_lr<_LIndex, _RIndex, _STDEX_TYPE function_name> tuple_ ## function_name ## _lr()                             \
{                                                                                                                                       \
    return _STDEX_TYPE _Tuple_compare_lr<_LIndex, _RIndex, _STDEX_TYPE function_name>(_STDEX_TYPE function_name());                     \
}                                                                                                                                       \
template<size_t _LIndex, size_t _RIndex, typename _Pr> inline                                                                           \
/* compare algorithm tuple_ ## function_name ## _lr using _Pr */                                                                        \
_STDEX_TYPE _Tuple_compare_lr<_LIndex, _RIndex, _Pr> tuple_ ## function_name ## _lr(_Pr _Pred)                                          \
{                                                                                                                                       \
    return _STDEX_TYPE _Tuple_compare_lr<_LIndex, _RIndex, _Pr>(_Pred);                                                                 \
}


#define _TUPLE_COMPARE_2(function_name)                                                                                                 \
template<size_t _Index1, size_t _Index2> inline                                                                                         \
/* compare algorithm tuple_ ## function_name */                                                                                         \
_STDEX_TYPE _Tuple_compare_llrr<_Index1, _Index2, _Index1, _Index2, _STDEX_TYPE function_name> tuple_ ## function_name()                \
{                                                                                                                                       \
    return _STDEX_TYPE _Tuple_compare_llrr<_Index1, _Index2, _Index1, _Index2, _STDEX_TYPE function_name>(_STDEX_TYPE function_name()); \
}                                                                                                                                       \
template<size_t _Index1, size_t _Index2, typename _Pr> inline                                                                           \
/* compare algorithm tuple_ ## function_name using _Pr */                                                                               \
_STDEX_TYPE _Tuple_compare_llrr<_Index1, _Index2, _Index1, _Index2, _Pr> tuple_ ## function_name(_Pr _Pred)                             \
{                                                                                                                                       \
    return _STDEX_TYPE _Tuple_compare_llrr<_Index1, _Index2, _Index1, _Index2, _Pr>(_Pred);                                             \
}

#define _TUPLE_COMPARE_LL(function_name)                                                                                                \
template<size_t _LIndex1, size_t _LIndex2> inline                                                                                       \
/* compare algorithm tuple_ ## function_name ## _ll */                                                                                  \
_STDEX_TYPE _Tuple_compare_ll<_LIndex1, _LIndex2, _STDEX_TYPE function_name> tuple_ ## function_name ## _ll()                           \
{                                                                                                                                       \
    return _STDEX_TYPE _Tuple_compare_ll<_LIndex1, _LIndex2, _STDEX_TYPE function_name>(_STDEX_TYPE function_name());                   \
}                                                                                                                                       \
template<size_t _LIndex1, size_t _LIndex2, typename _Pr> inline                                                                         \
/* compare algorithm tuple_ ## function_name ## _ll using _Pr */                                                                        \
_STDEX_TYPE _Tuple_compare_ll<_LIndex1, _LIndex2, _Pr> tuple_ ## function_name ## _ll(_Pr _Pred)                                        \
{                                                                                                                                       \
    return _STDEX_TYPE _Tuple_compare_ll<_LIndex1, _LIndex2, _Pr>(_Pred);                                                               \
}

#define _TUPLE_COMPARE_RR(function_name)                                                                                                \
template<size_t _RIndex1, size_t _RIndex2> inline                                                                                       \
/* compare algorithm tuple_ ## function_name ## _rr */                                                                                  \
_STDEX_TYPE _Tuple_compare_rr<_RIndex1, _RIndex2, _STDEX_TYPE function_name> tuple_ ## function_name ## _rr()                           \
{                                                                                                                                       \
    return _STDEX_TYPE _Tuple_compare_rr<_RIndex1, _RIndex2, _STDEX_TYPE function_name>(_STDEX_TYPE function_name());                   \
}                                                                                                                                       \
template<size_t _RIndex1, size_t _RIndex2, typename _Pr> inline                                                                         \
/* compare algorithm tuple_ ## function_name ## _rr using _Pr */                                                                        \
_STDEX_TYPE _Tuple_compare_rr<_RIndex1, _RIndex2, _Pr> tuple_ ## function_name ## _rr(_Pr _Pred)                                        \
{                                                                                                                                       \
    return _STDEX_TYPE _Tuple_compare_rr<_RIndex1, _RIndex2, _Pr>(_Pred);                                                               \
}

#define _TUPLE_COMPARE_LLR(function_name)                                                                                               \
template<size_t _LIndex1, size_t _LIndex2, size_t _RIndex> inline                                                                       \
/* compare algorithm tuple_ ## function_name ## _llr */                                                                                 \
_STDEX_TYPE _Tuple_compare_llr<_LIndex1, _LIndex2, _RIndex, _STDEX_TYPE function_name> tuple_ ## function_name ## _llr()                \
{                                                                                                                                       \
    return _STDEX_TYPE _Tuple_compare_llr<_LIndex1, _LIndex2, _RIndex, _STDEX_TYPE function_name>(_STDEX_TYPE function_name());         \
}                                                                                                                                       \
template<size_t _LIndex1, size_t _LIndex2, size_t _RIndex, typename _Pr> inline                                                         \
/* compare algorithm tuple_ ## function_name ## _llr using _Pr */                                                                       \
_STDEX_TYPE _Tuple_compare_llr<_LIndex1, _LIndex2, _RIndex, _Pr> tuple_ ## function_name ## _llr(_Pr _Pred)                             \
{                                                                                                                                       \
    return _STDEX_TYPE _Tuple_compare_llr<_LIndex1, _LIndex2, _RIndex, _Pr>(_Pred);                                                     \
}

#define _TUPLE_COMPARE_LRR(function_name)                                                                                               \
template<size_t _LIndex, size_t _RIndex1, size_t _RIndex2> inline                                                                       \
/* compare algorithm tuple_ ## function_name ## _lrr */                                                                                 \
_STDEX_TYPE _Tuple_compare_lrr<_LIndex, _RIndex1, _RIndex2, _STDEX_TYPE function_name> tuple_ ## function_name ## _lrr()                \
{                                                                                                                                       \
    return _STDEX_TYPE _Tuple_compare_lrr<_LIndex, _RIndex1, _RIndex2, _STDEX_TYPE function_name>(_STDEX_TYPE function_name());         \
}                                                                                                                                       \
template<size_t _LIndex, size_t _RIndex1, size_t _RIndex2, typename _Pr> inline                                                         \
/* compare algorithm tuple_ ## function_name ## _lrr using _Pr */                                                                       \
_STDEX_TYPE _Tuple_compare_lrr<_LIndex, _RIndex1, _RIndex2, _Pr> tuple_ ## function_name ## _lrr(_Pr _Pred)                             \
{                                                                                                                                       \
    return _STDEX_TYPE _Tuple_compare_lrr<_LIndex, _RIndex1, _RIndex2, _Pr>(_Pred);                                                     \
}

#define _TUPLE_COMPARE_LLRR(function_name)                                                                                              \
template<size_t _LIndex1, size_t _LIndex2, size_t _RIndex1, size_t _RIndex2> inline                                                     \
/* compare algorithm tuple_ ## function_name ## _llrr */                                                                                \
_STDEX_TYPE _Tuple_compare_llrr<_LIndex1, _LIndex2, _RIndex1, _RIndex2, _STDEX_TYPE function_name> tuple_ ## function_name ## _llrr()   \
{                                                                                                                                       \
    return _STDEX_TYPE _Tuple_compare_llrr<_LIndex1, _LIndex2, _RIndex1, _RIndex2, _STDEX_TYPE function_name>                           \
        (_STDEX_TYPE function_name());                                                                                                  \
}                                                                                                                                       \
template<size_t _LIndex1, size_t _LIndex2, size_t _RIndex1, size_t _RIndex2, typename _Pr> inline                                       \
/* compare algorithm tuple_ ## function_name ## _llrr using _Pr */                                                                      \
_STDEX_TYPE _Tuple_compare_llrr<_LIndex1, _LIndex2, _RIndex1, _RIndex2, _Pr> tuple_ ## function_name ## _llrr(_Pr _Pred)                \
{                                                                                                                                       \
    return _STDEX_TYPE _Tuple_compare_llrr<_LIndex1, _LIndex2, _RIndex1, _RIndex2, _Pr>(_Pred);                                         \
}


#define _TUPLE_COMPARE_3(function_name)                                                                                                 \
template<size_t _Index1, size_t _Index2, size_t _Index3> inline                                                                         \
/* compare algorithm tuple_ ## function_name */                                                                                         \
_STDEX_TYPE _Tuple_compare_lllrrr<_Index1, _Index2, _Index3, _Index1, _Index2, _Index3, _STDEX_TYPE function_name>                      \
    tuple_ ## function_name()                                                                                                           \
{                                                                                                                                       \
    return _STDEX_TYPE _Tuple_compare_lllrrr<_Index1, _Index2, _Index3, _Index1, _Index2, _Index3, _STDEX_TYPE function_name>           \
        (_STDEX_TYPE function_name());                                                                                                  \
}                                                                                                                                       \
template<size_t _Index1, size_t _Index2, size_t _Index3, typename _Pr> inline                                                           \
/* compare algorithm tuple_ ## function_name using _Pr */                                                                               \
_STDEX_TYPE _Tuple_compare_lllrrr<_Index1, _Index2, _Index3, _Index1, _Index2, _Index3,                                                 \
    _Pr> tuple_ ## function_name(_Pr _Pred)                                                                                             \
{                                                                                                                                       \
    return _STDEX_TYPE _Tuple_compare_lllrrr<_Index1, _Index2, _Index3, _Index1, _Index2, _Index3, _Pr>(_Pred);                         \
}

#define _TUPLE_COMPARE_LLL(function_name)                                                                                               \
template<size_t _LIndex1, size_t _LIndex2, size_t _LIndex3> inline                                                                      \
/* compare algorithm tuple_ ## function_name ## _lll */                                                                                 \
_STDEX_TYPE _Tuple_compare_lll<_LIndex1, _LIndex2, _LIndex3, _STDEX_TYPE function_name> tuple_ ## function_name ## _lll()               \
{                                                                                                                                       \
    return _STDEX_TYPE _Tuple_compare_lll<_LIndex1, _LIndex2, _LIndex3, _STDEX_TYPE function_name>(_STDEX_TYPE function_name());        \
}                                                                                                                                       \
template<size_t _LIndex1, size_t _LIndex2, size_t _LIndex3, typename _Pr> inline                                                        \
/* compare algorithm tuple_ ## function_name ## _lll using _Pr */                                                                       \
_STDEX_TYPE _Tuple_compare_lll<_LIndex1, _LIndex2, _LIndex3, _Pr> tuple_ ## function_name ## _lll(_Pr _Pred)                            \
{                                                                                                                                       \
    return _STDEX_TYPE _Tuple_compare_lll<_LIndex1, _LIndex2, _LIndex3, _Pr>(_Pred);                                                    \
}

#define _TUPLE_COMPARE_RRR(function_name)                                                                                               \
template<size_t _RIndex1, size_t _RIndex2, size_t _RIndex3> inline                                                                      \
/* compare algorithm tuple_ ## function_name ## _rrr */                                                                                 \
_STDEX_TYPE _Tuple_compare_rrr<_RIndex1, _RIndex2, _RIndex3, _STDEX_TYPE function_name> tuple_ ## function_name ## _rrr()               \
{                                                                                                                                       \
    return _STDEX_TYPE _Tuple_compare_rrr<_RIndex1, _RIndex2, _RIndex3, _STDEX_TYPE function_name>(_STDEX_TYPE function_name());        \
}                                                                                                                                       \
template<size_t _RIndex1, size_t _RIndex2, size_t _RIndex3, typename _Pr> inline                                                        \
/* compare algorithm tuple_ ## function_name ## _rrr using _Pr */                                                                       \
_STDEX_TYPE _Tuple_compare_rrr<_RIndex1, _RIndex2, _RIndex3, _Pr> tuple_ ## function_name ## _rrr(_Pr _Pred)                            \
{                                                                                                                                       \
    return _STDEX_TYPE _Tuple_compare_rrr<_RIndex1, _RIndex2, _RIndex3, _Pr>(_Pred);                                                    \
}

#define _TUPLE_COMPARE_LLLR(function_name)                                                                                              \
template<size_t _LIndex1, size_t _LIndex2, size_t _LIndex3, size_t _RIndex> inline                                                      \
/* compare algorithm tuple_ ## function_name ## _lllr */                                                                                \
_STDEX_TYPE _Tuple_compare_lllr<_LIndex1, _LIndex2, _LIndex3, _RIndex, _STDEX_TYPE function_name> tuple_ ## function_name ## _lllr()    \
{                                                                                                                                       \
    return _STDEX_TYPE _Tuple_compare_lllr<_LIndex1, _LIndex2, _LIndex3, _RIndex, _STDEX_TYPE function_name>                            \
        (_STDEX_TYPE function_name());                                                                                                  \
}                                                                                                                                       \
template<size_t _LIndex1, size_t _LIndex2, size_t _LIndex3, size_t _RIndex, typename _Pr> inline                                        \
/* compare algorithm tuple_ ## function_name ## _lllr using _Pr */                                                                      \
_STDEX_TYPE _Tuple_compare_lllr<_LIndex1, _LIndex2, _LIndex3, _RIndex, _Pr> tuple_ ## function_name ## _lllr(_Pr _Pred)                 \
{                                                                                                                                       \
    return _STDEX_TYPE _Tuple_compare_lllr<_LIndex1, _LIndex2, _LIndex3, _RIndex, _Pr>(_Pred);                                          \
}

#define _TUPLE_COMPARE_LLLRR(function_name)                                                                                             \
template<size_t _LIndex1, size_t _LIndex2, size_t _LIndex3, size_t _RIndex1, size_t _RIndex2> inline                                    \
/* compare algorithm tuple_ ## function_name ## _lllrr */                                                                               \
_STDEX_TYPE _Tuple_compare_lllrr<_LIndex1, _LIndex2, _LIndex3, _RIndex1, _RIndex2, _STDEX_TYPE function_name>                           \
    tuple_ ## function_name ## _lllrr()                                                                                                 \
{                                                                                                                                       \
    return _STDEX_TYPE _Tuple_compare_lllrr<_LIndex1, _LIndex2, _LIndex3, _RIndex1, _RIndex2, _STDEX_TYPE function_name>                \
        (_STDEX_TYPE function_name());                                                                                                  \
}                                                                                                                                       \
template<size_t _LIndex1, size_t _LIndex2, size_t _LIndex3, size_t _RIndex1, size_t _RIndex2, typename _Pr> inline                      \
/* compare algorithm tuple_ ## function_name ## _lllrr using _Pr */                                                                     \
_STDEX_TYPE _Tuple_compare_lllrr<_LIndex1, _LIndex2, _LIndex3, _RIndex1, _RIndex2, _Pr> tuple_ ## function_name ## _lllrr(_Pr _Pred)    \
{                                                                                                                                       \
    return _STDEX_TYPE _Tuple_compare_lllrr<_LIndex1, _LIndex2, _LIndex3, _RIndex1, _RIndex2, _Pr>(_Pred);                              \
}

#define _TUPLE_COMPARE_LRRR(function_name)                                                                                              \
template<size_t _LIndex, size_t _RIndex1, size_t _RIndex2, size_t _RIndex3> inline                                                      \
/* compare algorithm tuple_ ## function_name ## _lrrr */                                                                                \
_STDEX_TYPE _Tuple_compare_lrrr<_LIndex, _RIndex1, _RIndex2, _RIndex3, _STDEX_TYPE function_name> tuple_ ## function_name ## _lrrr()    \
{                                                                                                                                       \
    return _STDEX_TYPE _Tuple_compare_lrrr<_LIndex, _RIndex1, _RIndex2, _RIndex3, _STDEX_TYPE function_name>                            \
        (_STDEX_TYPE function_name());                                                                                                  \
}                                                                                                                                       \
template<size_t _LIndex, size_t _RIndex1, size_t _RIndex2, size_t _RIndex3, typename _Pr> inline                                        \
/* compare algorithm tuple_ ## function_name ## _lrrr using _Pr */                                                                      \
_STDEX_TYPE _Tuple_compare_lrrr<_LIndex, _RIndex1, _RIndex2, _RIndex3, _Pr> tuple_ ## function_name ## _lrrr(_Pr _Pred)                 \
{                                                                                                                                       \
    return _STDEX_TYPE _Tuple_compare_lrrr<_LIndex, _RIndex1, _RIndex2, _RIndex3, _Pr>(_Pred);                                          \
}

#define _TUPLE_COMPARE_LLRRR(function_name)                                                                                             \
template<size_t _LIndex1, size_t _LIndex2, size_t _RIndex1, size_t _RIndex2, size_t _RIndex3> inline                                    \
/* compare algorithm tuple_ ## function_name ## _llrrr */                                                                               \
_STDEX_TYPE _Tuple_compare_llrrr<_LIndex1, _LIndex2, _RIndex1, _RIndex2, _RIndex3, _STDEX_TYPE function_name>                           \
    tuple_ ## function_name ## _llrrr()                                                                                                 \
{                                                                                                                                       \
    return _STDEX_TYPE _Tuple_compare_llrrr<_LIndex1, _LIndex2, _RIndex1, _RIndex2, _RIndex3, _STDEX_TYPE function_name>                \
        (_STDEX_TYPE function_name());                                                                                                  \
}                                                                                                                                       \
template<size_t _LIndex1, size_t _LIndex2, size_t _RIndex1, size_t _RIndex2, size_t _RIndex3, typename _Pr> inline                      \
/* compare algorithm tuple_ ## function_name ## _llrrr using _Pr */                                                                     \
_STDEX_TYPE _Tuple_compare_llrrr<_LIndex1, _LIndex2, _RIndex1, _RIndex2, _RIndex3, _Pr> tuple_ ## function_name ## _llrrr(_Pr _Pred)    \
{                                                                                                                                       \
    return _STDEX_TYPE _Tuple_compare_llrrr<_LIndex1, _LIndex2, _RIndex1, _RIndex2, _RIndex3, _Pr>(_Pred);                              \
}

#define _TUPLE_COMPARE_LLLRRR(function_name)                                                                                            \
template<size_t _LIndex1, size_t _LIndex2, size_t _LIndex3, size_t _RIndex1, size_t _RIndex2, size_t _RIndex3> inline                   \
/* compare algorithm tuple_ ## function_name ## _lllrrr */                                                                              \
_STDEX_TYPE _Tuple_compare_lllrrr<_LIndex1, _LIndex2, _LIndex3, _RIndex1, _RIndex2, _RIndex3, _STDEX_TYPE function_name>                \
    tuple_ ## function_name ## _lllrrr()                                                                                                \
{                                                                                                                                       \
    return _STDEX_TYPE _Tuple_compare_lllrrr<_LIndex1, _LIndex2, _LIndex3, _RIndex1, _RIndex2, _RIndex3, _STDEX_TYPE function_name>     \
        (_STDEX_TYPE function_name());                                                                                                  \
}                                                                                                                                       \
template<size_t _LIndex1, size_t _LIndex2, size_t _LIndex3, size_t _RIndex1, size_t _RIndex2, size_t _RIndex3, typename _Pr> inline     \
/* compare algorithm tuple_ ## function_name ## _lllrrr using _Pr */                                                                    \
_STDEX_TYPE _Tuple_compare_lllrrr<_LIndex1, _LIndex2, _LIndex3, _RIndex1, _RIndex2, _RIndex3, _Pr>                                      \
    tuple_ ## function_name ## _lllrrr(_Pr _Pred)                                                                                       \
{                                                                                                                                       \
    return _STDEX_TYPE _Tuple_compare_lllrrr<_LIndex1, _LIndex2, _LIndex3, _RIndex1, _RIndex2, _RIndex3, _Pr>(_Pred);                   \
}


#define TUPLE_COMPARE(function_name)    \
    _TUPLE_COMPARE_1(function_name)     \
    _TUPLE_COMPARE_L(function_name)     \
    _TUPLE_COMPARE_R(function_name)     \
    _TUPLE_COMPARE_LR(function_name)    \
                                        \
    _TUPLE_COMPARE_2(function_name)     \
    _TUPLE_COMPARE_LL(function_name)    \
    _TUPLE_COMPARE_RR(function_name)    \
    _TUPLE_COMPARE_LLR(function_name)   \
    _TUPLE_COMPARE_LRR(function_name)   \
    _TUPLE_COMPARE_LLRR(function_name)  \
                                        \
    _TUPLE_COMPARE_3(function_name)     \
    _TUPLE_COMPARE_LLL(function_name)   \
    _TUPLE_COMPARE_RRR(function_name)   \
    _TUPLE_COMPARE_LLLR(function_name)  \
    _TUPLE_COMPARE_LLLRR(function_name) \
    _TUPLE_COMPARE_LRRR(function_name)  \
    _TUPLE_COMPARE_LLRRR(function_name) \
    _TUPLE_COMPARE_LLLRRR(function_name)


TUPLE_COMPARE(equal_to)
TUPLE_COMPARE(not_equal_to)
TUPLE_COMPARE(greater)
TUPLE_COMPARE(greater_equal)
TUPLE_COMPARE(less)
TUPLE_COMPARE(less_equal)


_STDEX_END


#endif /* _STRINGPRINTF_H_ */

#endif /* _STRINGPRINTF_STL_EXTRA_H_ */
