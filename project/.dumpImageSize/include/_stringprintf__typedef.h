#ifndef _STRINGPRINTF__TYPEDEF_H_
#define _STRINGPRINTF__TYPEDEF_H_

#ifdef _STRINGPRINTF_H_


#define _STDEX_TYPE_BEGIN       _STDEX_MY_BEGIN namespace type { /* must in ::stdex:: */
#define _STDEX_TYPE_END         } _STDEX_MY_END
#define _STDEX_TYPE             _STDEX_MY type::
#define _STDEX_TYPE_USING       _STDEX_MY_USING ::type


/* string_printf type defined namespace */
_STDEX_BEGIN _STDEX_TYPE_BEGIN

#ifdef _UNICODE
// The default basic_string element type(wchar_t), defined(_UNICODE)
typedef wchar_t     defChar;
#else /* _UNICODE */
// The default basic_string element type(char), !defined(_UNICODE)
typedef char        defChar;
#endif /* _UNICODE */

#if HAVE_WINDOWS
/* for System Debug Output */
struct csys_t{};

#ifdef _WIN64
typedef signed __int64      ssize_t;

#else /* _WIN64 */
typedef _W64 signed int     ssize_t;
#endif

#endif /* HAVE_WINDOWS */

#if _MSC_VER < 1700
template<class _Result> struct result_function
{
    typedef _Result result_type;
};
/* for vs2010 tr1 */
#define FIX_VS_STL_RESULT_TYPE(type)    : result_function<type>
#define DEF_VALUE(_Val)

#elif _MSC_VER < 1800
#define FIX_VS_STL_RESULT_TYPE(type)
#define DEF_VALUE(_Val)

#else /* _MSC_VER < 1800 */
#define FIX_VS_STL_RESULT_TYPE(type)
#define DEF_VALUE(_Val)                 = _Val

#endif /* _MSC_VER < 1800 */


_STDEX_TYPE_END

using _STDEX_TYPE defChar;

#if HAVE_WINDOWS
using _STDEX_TYPE csys_t;
using _STDEX_TYPE ssize_t;

#endif /* HAVE_WINDOWS */

_STDEX_END


/* preprocessor string helpers */
#ifndef _CRT_STRINGIZE
#define __CRT_STRINGIZE(_Value) #_Value
#define _CRT_STRINGIZE(_Value) __CRT_STRINGIZE(_Value)
#endif  /* _CRT_STRINGIZE */

#ifndef _CRT_WIDE
#define __CRT_WIDE(_String) L ## _String
#define _CRT_WIDE(_String) __CRT_WIDE(_String)
#endif  /* _CRT_WIDE */

#ifndef _CRT_APPEND
#define __CRT_APPEND(_Value1, _Value2) _Value1 ## _Value2
#define _CRT_APPEND(_Value1, _Value2) __CRT_APPEND(_Value1, _Value2)
#endif  /* _CRT_APPEND */


/* default to using variadic templates if the compiler support */
#if _MSC_VER < 1800 || _STRING_PRINTF_NO_VARIADIC_TEMPLATES_
// maximum number of arguments to call wrappers
#define MY_NMAX 30

#define MY_XNAME(x, z)                  x ## z
#define MY_YNAME(x, z)                  MY_XNAME(x, z)
#define MY_YNAME15(x, y, z)             MY_XNAME(x, z) y
#define MY_YNAME2(x, y, z)              MY_XNAME(x, z) MY_XNAME(y, z)

#define MY_YCALL3(x, y, z, f)           f<MY_XNAME(x, z)>(MY_XNAME(y, z))
#define MY_MOV_YCALL3(y, z, f)          f(MY_XNAME(y, z))

#define MY_CORE_0(x)
#define MY_CORE15_0(x, y)
#define MY_CORE2_0_CALL(x, y, f)
#define MY_MOV_CORE2_0_CALL(x, y, f)
#define MY_CORE2_0(x, y)
#define MY_NARGSm1_0                    0

#define MY_CORE_1(x)
#define MY_CORE15_1(x, y)
#define MY_CORE2_1_CALL(x, y, f)
#define MY_MOV_CORE2_1_CALL(x, y, f)
#define MY_CORE2_1(x, y)
#define MY_NARGSm1_1                    0

#define MY_CORE_2(x)
#define MY_CORE15_2(x, y)
#define MY_CORE2_2_CALL(x, y, f)
#define MY_MOV_CORE2_2_CALL(x, y, f)
#define MY_CORE2_2(x, y)
#define MY_NARGSm1_2                    1

#define MY_CORE_3(x)                    MY_YNAME(x, 1)
#define MY_CORE15_3(x, y)               MY_YNAME15(x, y, 1)
#define MY_CORE2_3_CALL(x, y, f)        MY_YCALL3(x, y, 1, f)
#define MY_MOV_CORE2_3_CALL(x, y, f)    MY_MOV_YCALL3(y, 1, f)
#define MY_CORE2_3(x, y)                MY_YNAME2(x, y, 1)
#define MY_NARGSm1_3                    2

#define MY_CORE_4(x)                    MY_CORE_3(x), MY_YNAME(x, 2)
#define MY_CORE15_4(x, y)               MY_CORE15_3(x, y), MY_YNAME15(x, y, 2)
#define MY_CORE2_4_CALL(x, y, f)        MY_CORE2_3_CALL(x, y, f), MY_YCALL3(x, y, 2, f)
#define MY_MOV_CORE2_4_CALL(x, y, f)    MY_MOV_CORE2_3_CALL(x, y, f), MY_MOV_YCALL3(y, 2, f)
#define MY_CORE2_4(x, y)                MY_CORE2_3(x, y), MY_YNAME2(x, y, 2)
#define MY_NARGSm1_4                    3

#define MY_CORE_5(x)                    MY_CORE_4(x), MY_YNAME(x, 3)
#define MY_CORE15_5(x, y)               MY_CORE15_4(x, y), MY_YNAME15(x, y, 3)
#define MY_CORE2_5_CALL(x, y, f)        MY_CORE2_4_CALL(x, y, f), MY_YCALL3(x, y, 3, f)
#define MY_MOV_CORE2_5_CALL(x, y, f)    MY_MOV_CORE2_4_CALL(x, y, f), MY_MOV_YCALL3(y, 3, f)
#define MY_CORE2_5(x, y)                MY_CORE2_4(x, y), MY_YNAME2(x, y, 3)
#define MY_NARGSm1_5                    4

#define MY_CORE_6(x)                    MY_CORE_5(x), MY_YNAME(x, 4)
#define MY_CORE15_6(x, y)               MY_CORE15_5(x, y), MY_YNAME15(x, y, 4)
#define MY_CORE2_6_CALL(x, y, f)        MY_CORE2_5_CALL(x, y, f), MY_YCALL3(x, y, 4, f)
#define MY_MOV_CORE2_6_CALL(x, y, f)    MY_MOV_CORE2_5_CALL(x, y, f), MY_MOV_YCALL3(y, 4, f)
#define MY_CORE2_6(x, y)                MY_CORE2_5(x, y), MY_YNAME2(x, y, 4)
#define MY_NARGSm1_6                    5

#define MY_CORE_7(x)                    MY_CORE_6(x), MY_YNAME(x, 5)
#define MY_CORE15_7(x, y)               MY_CORE15_6(x, y), MY_YNAME15(x, y, 5)
#define MY_CORE2_7_CALL(x, y, f)        MY_CORE2_6_CALL(x, y, f), MY_YCALL3(x, y, 5, f)
#define MY_MOV_CORE2_7_CALL(x, y, f)    MY_MOV_CORE2_6_CALL(x, y, f), MY_MOV_YCALL3(y, 5, f)
#define MY_CORE2_7(x, y)                MY_CORE2_6(x, y), MY_YNAME2(x, y, 5)
#define MY_NARGSm1_7                    6

#define MY_CORE_8(x)                    MY_CORE_7(x), MY_YNAME(x, 6)
#define MY_CORE15_8(x, y)               MY_CORE15_7(x, y), MY_YNAME15(x, y, 6)
#define MY_CORE2_8_CALL(x, y, f)        MY_CORE2_7_CALL(x, y, f), MY_YCALL3(x, y, 6, f)
#define MY_MOV_CORE2_8_CALL(x, y, f)    MY_MOV_CORE2_7_CALL(x, y, f), MY_MOV_YCALL3(y, 6, f)
#define MY_CORE2_8(x, y)                MY_CORE2_7(x, y), MY_YNAME2(x, y, 6)
#define MY_NARGSm1_8                    7

#define MY_CORE_9(x)                    MY_CORE_8(x), MY_YNAME(x, 7)
#define MY_CORE15_9(x, y)               MY_CORE15_8(x, y), MY_YNAME15(x, y, 7)
#define MY_CORE2_9_CALL(x, y, f)        MY_CORE2_8_CALL(x, y, f), MY_YCALL3(x, y, 7, f)
#define MY_MOV_CORE2_9_CALL(x, y, f)    MY_MOV_CORE2_8_CALL(x, y, f), MY_MOV_YCALL3(y, 7, f)
#define MY_CORE2_9(x, y)                MY_CORE2_8(x, y), MY_YNAME2(x, y, 7)
#define MY_NARGSm1_9                    8

#define MY_CORE_10(x)                   MY_CORE_9(x), MY_YNAME(x, 8)
#define MY_CORE15_10(x, y)              MY_CORE15_9(x, y), MY_YNAME15(x, y, 8)
#define MY_CORE2_10_CALL(x, y, f)       MY_CORE2_9_CALL(x, y, f), MY_YCALL3(x, y, 8, f)
#define MY_MOV_CORE2_10_CALL(x, y, f)   MY_MOV_CORE2_9_CALL(x, y, f), MY_MOV_YCALL3(y, 8, f)
#define MY_CORE2_10(x, y)               MY_CORE2_9(x, y), MY_YNAME2(x, y, 8)
#define MY_NARGSm1_10                   9

#define MY_CORE_11(x)                   MY_CORE_10(x), MY_YNAME(x, 9)
#define MY_CORE15_11(x, y)              MY_CORE15_10(x, y), MY_YNAME15(x, y, 9)
#define MY_CORE2_11_CALL(x, y, f)       MY_CORE2_10_CALL(x, y, f), MY_YCALL3(x, y, 9, f)
#define MY_MOV_CORE2_11_CALL(x, y, f)   MY_MOV_CORE2_10_CALL(x, y, f), MY_MOV_YCALL3(y, 9, f)
#define MY_CORE2_11(x, y)               MY_CORE2_10(x, y), MY_YNAME2(x, y, 9)
#define MY_NARGSm1_11                   10

#define MY_CORE_12(x)                   MY_CORE_11(x), MY_YNAME(x, 10)
#define MY_CORE15_12(x, y)              MY_CORE15_11(x, y), MY_YNAME15(x, y, 10)
#define MY_CORE2_12_CALL(x, y, f)       MY_CORE2_11_CALL(x, y, f), MY_YCALL3(x, y, 10, f)
#define MY_MOV_CORE2_12_CALL(x, y, f)   MY_MOV_CORE2_11_CALL(x, y, f), MY_MOV_YCALL3(y, 10, f)
#define MY_CORE2_12(x, y)               MY_CORE2_11(x, y), MY_YNAME2(x, y, 10)
#define MY_NARGSm1_12                   11

#define MY_CORE_13(x)                   MY_CORE_12(x), MY_YNAME(x, 11)
#define MY_CORE15_13(x, y)              MY_CORE15_12(x, y), MY_YNAME15(x, y, 11)
#define MY_CORE2_13_CALL(x, y, f)       MY_CORE2_12_CALL(x, y, f), MY_YCALL3(x, y, 11, f)
#define MY_MOV_CORE2_13_CALL(x, y, f)   MY_MOV_CORE2_12_CALL(x, y, f), MY_MOV_YCALL3(y, 11, f)
#define MY_CORE2_13(x, y)               MY_CORE2_12(x, y), MY_YNAME2(x, y, 11)
#define MY_NARGSm1_13                   12

#define MY_CORE_14(x)                   MY_CORE_13(x), MY_YNAME(x, 12)
#define MY_CORE15_14(x, y)              MY_CORE15_13(x, y), MY_YNAME15(x, y, 12)
#define MY_CORE2_14_CALL(x, y, f)       MY_CORE2_13_CALL(x, y, f), MY_YCALL3(x, y, 12, f)
#define MY_MOV_CORE2_14_CALL(x, y, f)   MY_MOV_CORE2_13_CALL(x, y, f), MY_MOV_YCALL3(y, 12, f)
#define MY_CORE2_14(x, y)               MY_CORE2_13(x, y), MY_YNAME2(x, y, 12)
#define MY_NARGSm1_14                   13

#define MY_CORE_15(x)                   MY_CORE_14(x), MY_YNAME(x, 13)
#define MY_CORE15_15(x, y)              MY_CORE15_14(x, y), MY_YNAME15(x, y, 13)
#define MY_CORE2_15_CALL(x, y, f)       MY_CORE2_14_CALL(x, y, f), MY_YCALL3(x, y, 13, f)
#define MY_MOV_CORE2_15_CALL(x, y, f)   MY_MOV_CORE2_14_CALL(x, y, f), MY_MOV_YCALL3(y, 13, f)
#define MY_CORE2_15(x, y)               MY_CORE2_14(x, y), MY_YNAME2(x, y, 13)
#define MY_NARGSm1_15                   14

#define MY_CORE_16(x)                   MY_CORE_15(x), MY_YNAME(x, 14)
#define MY_CORE15_16(x, y)              MY_CORE15_15(x, y), MY_YNAME15(x, y, 14)
#define MY_CORE2_16_CALL(x, y, f)       MY_CORE2_15_CALL(x, y, f), MY_YCALL3(x, y, 14, f)
#define MY_MOV_CORE2_16_CALL(x, y, f)   MY_MOV_CORE2_15_CALL(x, y, f), MY_MOV_YCALL3(y, 14, f)
#define MY_CORE2_16(x, y)               MY_CORE2_15(x, y), MY_YNAME2(x, y, 14)
#define MY_NARGSm1_16                   15

#define MY_CORE_17(x)                   MY_CORE_16(x), MY_YNAME(x, 15)
#define MY_CORE15_17(x, y)              MY_CORE15_16(x, y), MY_YNAME15(x, y, 15)
#define MY_CORE2_17_CALL(x, y, f)       MY_CORE2_16_CALL(x, y, f), MY_YCALL3(x, y, 15, f)
#define MY_MOV_CORE2_17_CALL(x, y, f)   MY_MOV_CORE2_16_CALL(x, y, f), MY_MOV_YCALL3(y, 15, f)
#define MY_CORE2_17(x, y)               MY_CORE2_16(x, y), MY_YNAME2(x, y, 15)
#define MY_NARGSm1_17                   16

#define MY_CORE_18(x)                   MY_CORE_17(x), MY_YNAME(x, 16)
#define MY_CORE15_18(x, y)              MY_CORE15_17(x, y), MY_YNAME15(x, y, 16)
#define MY_CORE2_18_CALL(x, y, f)       MY_CORE2_17_CALL(x, y, f), MY_YCALL3(x, y, 16, f)
#define MY_MOV_CORE2_18_CALL(x, y, f)   MY_MOV_CORE2_17_CALL(x, y, f), MY_MOV_YCALL3(y, 16, f)
#define MY_CORE2_18(x, y)               MY_CORE2_17(x, y), MY_YNAME2(x, y, 16)
#define MY_NARGSm1_18                   17

#define MY_CORE_19(x)                   MY_CORE_18(x), MY_YNAME(x, 17)
#define MY_CORE15_19(x, y)              MY_CORE15_18(x, y), MY_YNAME15(x, y, 17)
#define MY_CORE2_19_CALL(x, y, f)       MY_CORE2_18_CALL(x, y, f), MY_YCALL3(x, y, 17, f)
#define MY_MOV_CORE2_19_CALL(x, y, f)   MY_MOV_CORE2_18_CALL(x, y, f), MY_MOV_YCALL3(y, 17, f)
#define MY_CORE2_19(x, y)               MY_CORE2_18(x, y), MY_YNAME2(x, y, 17)
#define MY_NARGSm1_19                   18

#define MY_CORE_20(x)                   MY_CORE_19(x), MY_YNAME(x, 18)
#define MY_CORE15_20(x, y)              MY_CORE15_19(x, y), MY_YNAME15(x, y, 18)
#define MY_CORE2_20_CALL(x, y, f)       MY_CORE2_19_CALL(x, y, f), MY_YCALL3(x, y, 18, f)
#define MY_MOV_CORE2_20_CALL(x, y, f)   MY_MOV_CORE2_19_CALL(x, y, f), MY_MOV_YCALL3(y, 18, f)
#define MY_CORE2_20(x, y)               MY_CORE2_19(x, y), MY_YNAME2(x, y, 18)
#define MY_NARGSm1_20                   19

#define MY_CORE_21(x)                   MY_CORE_20(x), MY_YNAME(x, 19)
#define MY_CORE15_21(x, y)              MY_CORE15_20(x, y), MY_YNAME15(x, y, 19)
#define MY_CORE2_21_CALL(x, y, f)       MY_CORE2_20_CALL(x, y, f), MY_YCALL3(x, y, 19, f)
#define MY_MOV_CORE2_21_CALL(x, y, f)   MY_MOV_CORE2_20_CALL(x, y, f), MY_MOV_YCALL3(y, 19, f)
#define MY_CORE2_21(x, y)               MY_CORE2_20(x, y), MY_YNAME2(x, y, 19)
#define MY_NARGSm1_21                   20

#define MY_CORE_22(x)                   MY_CORE_21(x), MY_YNAME(x, 20)
#define MY_CORE15_22(x, y)              MY_CORE15_21(x, y), MY_YNAME15(x, y, 20)
#define MY_CORE2_22_CALL(x, y, f)       MY_CORE2_21_CALL(x, y, f), MY_YCALL3(x, y, 20, f)
#define MY_MOV_CORE2_22_CALL(x, y, f)   MY_MOV_CORE2_21_CALL(x, y, f), MY_MOV_YCALL3(y, 20, f)
#define MY_CORE2_22(x, y)               MY_CORE2_21(x, y), MY_YNAME2(x, y, 20)
#define MY_NARGSm1_22                   21

#define MY_CORE_23(x)                   MY_CORE_22(x), MY_YNAME(x, 21)
#define MY_CORE15_23(x, y)              MY_CORE15_22(x, y), MY_YNAME15(x, y, 21)
#define MY_CORE2_23_CALL(x, y, f)       MY_CORE2_22_CALL(x, y, f), MY_YCALL3(x, y, 21, f)
#define MY_MOV_CORE2_23_CALL(x, y, f)   MY_MOV_CORE2_22_CALL(x, y, f), MY_MOV_YCALL3(y, 21, f)
#define MY_CORE2_23(x, y)               MY_CORE2_22(x, y), MY_YNAME2(x, y, 21)
#define MY_NARGSm1_23                   22

#define MY_CORE_24(x)                   MY_CORE_23(x), MY_YNAME(x, 22)
#define MY_CORE15_24(x, y)              MY_CORE15_23(x, y), MY_YNAME15(x, y, 22)
#define MY_CORE2_24_CALL(x, y, f)       MY_CORE2_23_CALL(x, y, f), MY_YCALL3(x, y, 22, f)
#define MY_MOV_CORE2_24_CALL(x, y, f)   MY_MOV_CORE2_23_CALL(x, y, f), MY_MOV_YCALL3(y, 22, f)
#define MY_CORE2_24(x, y)               MY_CORE2_23(x, y), MY_YNAME2(x, y, 22)
#define MY_NARGSm1_24                   23

#define MY_CORE_25(x)                   MY_CORE_24(x), MY_YNAME(x, 23)
#define MY_CORE15_25(x, y)              MY_CORE15_24(x, y), MY_YNAME15(x, y, 23)
#define MY_CORE2_25_CALL(x, y, f)       MY_CORE2_24_CALL(x, y, f), MY_YCALL3(x, y, 23, f)
#define MY_MOV_CORE2_25_CALL(x, y, f)   MY_MOV_CORE2_24_CALL(x, y, f), MY_MOV_YCALL3(y, 23, f)
#define MY_CORE2_25(x, y)               MY_CORE2_24(x, y), MY_YNAME2(x, y, 23)
#define MY_NARGSm1_25                   24

#define MY_CORE_26(x)                   MY_CORE_25(x), MY_YNAME(x, 24)
#define MY_CORE15_26(x, y)              MY_CORE15_25(x, y), MY_YNAME15(x, y, 24)
#define MY_CORE2_26_CALL(x, y, f)       MY_CORE2_25_CALL(x, y, f), MY_YCALL3(x, y, 24, f)
#define MY_MOV_CORE2_26_CALL(x, y, f)   MY_MOV_CORE2_25_CALL(x, y, f), MY_MOV_YCALL3(y, 24, f)
#define MY_CORE2_26(x, y)               MY_CORE2_25(x, y), MY_YNAME2(x, y, 24)
#define MY_NARGSm1_26                   25

#define MY_CORE_27(x)                   MY_CORE_26(x), MY_YNAME(x, 25)
#define MY_CORE15_27(x, y)              MY_CORE15_26(x, y), MY_YNAME15(x, y, 25)
#define MY_CORE2_27_CALL(x, y, f)       MY_CORE2_26_CALL(x, y, f), MY_YCALL3(x, y, 25, f)
#define MY_MOV_CORE2_27_CALL(x, y, f)   MY_MOV_CORE2_26_CALL(x, y, f), MY_MOV_YCALL3(y, 25, f)
#define MY_CORE2_27(x, y)               MY_CORE2_26(x, y), MY_YNAME2(x, y, 25)
#define MY_NARGSm1_27                   26

#define MY_CORE_28(x)                   MY_CORE_27(x), MY_YNAME(x, 26)
#define MY_CORE15_28(x, y)              MY_CORE15_27(x, y), MY_YNAME15(x, y, 26)
#define MY_CORE2_28_CALL(x, y, f)       MY_CORE2_27_CALL(x, y, f), MY_YCALL3(x, y, 26, f)
#define MY_MOV_CORE2_28_CALL(x, y, f)   MY_MOV_CORE2_27_CALL(x, y, f), MY_MOV_YCALL3(y, 26, f)
#define MY_CORE2_28(x, y)               MY_CORE2_27(x, y), MY_YNAME2(x, y, 26)
#define MY_NARGSm1_28                   27

#define MY_CORE_29(x)                   MY_CORE_28(x), MY_YNAME(x, 27)
#define MY_CORE15_29(x, y)              MY_CORE15_28(x, y), MY_YNAME15(x, y, 27)
#define MY_CORE2_29_CALL(x, y, f)       MY_CORE2_28_CALL(x, y, f), MY_YCALL3(x, y, 27, f)
#define MY_MOV_CORE2_29_CALL(x, y, f)   MY_MOV_CORE2_28_CALL(x, y, f), MY_MOV_YCALL3(y, 27, f)
#define MY_CORE2_29(x, y)               MY_CORE2_28(x, y), MY_YNAME2(x, y, 27)
#define MY_NARGSm1_29                   28

#define MY_CORE_30(x)                   MY_CORE_29(x), MY_YNAME(x, 28)
#define MY_CORE15_30(x, y)              MY_CORE15_29(x, y), MY_YNAME15(x, y, 28)
#define MY_CORE2_30_CALL(x, y, f)       MY_CORE2_29_CALL(x, y, f), MY_YCALL3(x, y, 28, f)
#define MY_MOV_CORE2_30_CALL(x, y, f)   MY_MOV_CORE2_29_CALL(x, y, f), MY_MOV_YCALL3(y, 28, f)
#define MY_CORE2_30(x, y)               MY_CORE2_29(x, y), MY_YNAME2(x, y, 28)
#define MY_NARGSm1_30                   29

#define MY_TAIL_30(x)
#define MY_TAIL_29(x)                   x
#define MY_TAIL_28(x)                   MY_TAIL_29(x), x
#define MY_TAIL_27(x)                   MY_TAIL_28(x), x
#define MY_TAIL_26(x)                   MY_TAIL_27(x), x
#define MY_TAIL_25(x)                   MY_TAIL_26(x), x
#define MY_TAIL_24(x)                   MY_TAIL_25(x), x
#define MY_TAIL_23(x)                   MY_TAIL_24(x), x
#define MY_TAIL_22(x)                   MY_TAIL_23(x), x
#define MY_TAIL_21(x)                   MY_TAIL_22(x), x
#define MY_TAIL_20(x)                   MY_TAIL_21(x), x
#define MY_TAIL_19(x)                   MY_TAIL_20(x), x
#define MY_TAIL_18(x)                   MY_TAIL_19(x), x
#define MY_TAIL_17(x)                   MY_TAIL_18(x), x
#define MY_TAIL_16(x)                   MY_TAIL_17(x), x
#define MY_TAIL_15(x)                   MY_TAIL_16(x), x
#define MY_TAIL_14(x)                   MY_TAIL_15(x), x
#define MY_TAIL_13(x)                   MY_TAIL_14(x), x
#define MY_TAIL_12(x)                   MY_TAIL_13(x), x
#define MY_TAIL_11(x)                   MY_TAIL_12(x), x
#define MY_TAIL_10(x)                   MY_TAIL_11(x), x
#define MY_TAIL_9(x)                    MY_TAIL_10(x), x
#define MY_TAIL_8(x)                    MY_TAIL_9(x), x
#define MY_TAIL_7(x)                    MY_TAIL_8(x), x
#define MY_TAIL_6(x)                    MY_TAIL_7(x), x
#define MY_TAIL_5(x)                    MY_TAIL_6(x), x
#define MY_TAIL_4(x)                    MY_TAIL_5(x), x
#define MY_TAIL_3(x)                    MY_TAIL_4(x), x
#define MY_TAIL_2(x)                    MY_TAIL_3(x), x
#define MY_TAIL_1(x)                    MY_TAIL_2(x), x
#define MY_TAIL_0(x)                    MY_TAIL_1(x), x

#define MY_ARG_MAX                      29
#define MY_CDR_MAX(x)                   MY_CORE_30(x), MY_YNAME(x, MY_ARG_MAX)
#define MY_CDR15_MAX(x, y)              MY_CORE15_30(x, y), MY_YNAME15(x, y, MY_ARG_MAX)
#define MY_CDR2_MAX(x, y)               MY_CORE2_30(x, y), MY_YNAME2(x, y, MY_ARG_MAX)
#define MY_CDR2_CALL_MAX(x, y, f)       MY_CORE2_30_CALL(x, y, f), MY_YCALL3(x, y, MY_ARG_MAX, f)
#define MY_MOV_CDR2_CALL_MAX(x, y, f)   MY_MOV_CORE2_30_CALL(x, y, f), MY_MOV_YCALL3(y, MY_ARG_MAX, f)
#define MY_LIST_MAX(x)                  MY_YNAME(x, 0), MY_CDR_MAX(x)
#define MY_LIST15_MAX(x, y)             MY_YNAME15(x, y, 0), MY_CDR15_MAX(x, y)
#define MY_LIST2_MAX(x, y)              MY_YNAME2(x, y, 0), MY_CDR2_MAX(x, y)
#define MY_LIST2_CALL_MAX(x, y, f)      MY_YCALL3(x, y, 0, f), MY_CDR2_CALL_MAX(x, y, f)
#define MY_MOV_LIST2_CALL_MAX(x, y, f)  MY_MOV_YCALL3(y, 0, f), MY_MOV_CDR2_CALL_MAX(x, y, f)

#define MY_CLASS_ARG0_MAX               MY_LIST_MAX(typename _Arg)
#define MY_ARG0_ARG1_MAX                MY_LIST_MAX(_Arg)
#define MY_ARG0_ARG1_REF_MAX            MY_LIST15_MAX(_Arg, &)
#define MY_ARG0_ARG1_CREF_MAX           MY_LIST15_MAX(const _Arg, &)
#define MY_ARG0_A0_MAX                  MY_LIST2_MAX(_Arg, _Ax)
#define MY_ARG0_A0_REF_MAX              MY_LIST2_MAX(_Arg, &_Ax)
#define MY_ARG0_A0_REFREF_MAX           MY_LIST2_MAX(_Arg, && _Ax)
#define MY_ARG0_A0_CREF_MAX             MY_LIST2_MAX(const _Arg, &_Ax)
#define MY_A0_A1_MAX                    MY_LIST_MAX(_Ax)

#define MY_A0_A1_FWD_MAX                MY_LIST_CALL_MAX(_Arg, _Ax, _STD forward)
#define MY_A0_A1_MOV_MAX                MY_MOV_LIST_CALL_MAX(_Arg, _Ax, _STD move)
#define MY_A0_A1_STRFWD_MAX             MY_MOV_LIST_CALL_MAX(_Arg, _Ax, string_forward)

#define MY_CLASS_ARG1_MAX               MY_CDR_MAX(typename _Arg)
#define MY_ARG1_ARG2_MAX                MY_CDR_MAX(_Arg)
#define MY_ARG1_ARG2_REF_MAX            MY_CDR15_MAX(_Arg, &)
#define MY_ARG1_ARG2_CREF_MAX           MY_CDR15_MAX(const _Arg, &)
#define MY_ARG1_A1_MAX                  MY_CDR2_MAX(_Arg, _Ax)
#define MY_ARG1_A1_REF_MAX              MY_CDR2_MAX(_Arg, &_Ax)
#define MY_ARG1_A1_REFREF_MAX           MY_CDR2_MAX(_Arg, && _Ax)
#define MY_ARG1_A1_CREF_MAX             MY_CDR2_MAX(const _Arg, &_Ax)
#define MY_A1_A2_MAX                    MY_CDR_MAX(_Ax)

#define MY_A1_A2_FWD_MAX                MY_CDR_CALL_MAX(_Arg, _Ax, _STD forward)
#define MY_A1_A2_MOV_MAX                MY_MOV_CDR_CALL_MAX(_Arg, _Ax, _STD move)
#define MY_A1_A2_STRFWD_MAX             MY_MOV_CDR_CALL_MAX(_Arg, _Ax, string_forward)

#define MY_TAIL_MAX(x)                  MY_TAIL_0(x)
#define MY_CLASS_ARG0_DEF_MAX(_Val)     MY_LIST15_MAX(typename _Arg, = _Val)
#define MY_CLASS_ARG1_DEF_MAX(_Val)     MY_CDR15_MAX(typename _Arg, = _Val)

#else /* _MSC_VER < 1800 || _STRING_PRINTF_NO_VARIADIC_TEMPLATES_ */
#define MY_CLASS_ARG0_MAX               typename... _Arg
#define MY_ARG0_ARG1_MAX                _Arg...
#define MY_ARG0_ARG1_REF_MAX            _Arg&...
#define MY_ARG0_ARG1_CREF_MAX           const _Arg&...
#define MY_ARG0_A0_MAX                  _Arg... _Ax
#define MY_ARG0_A0_REF_MAX              _Arg&... _Ax
#define MY_ARG0_A0_REFREF_MAX           _Arg&&... _Ax
#define MY_ARG0_A0_CREF_MAX             const _Arg&... _Ax
#define MY_A0_A1_MAX                    _Ax...

#define MY_A0_A1_FWD_MAX                _STD forward<_Arg>(_Ax)...
#define MY_A0_A1_MOV_MAX                _STD move(_Ax)...
#define MY_A0_A1_STRFWD_MAX             string_forward(_Ax)...

#define MY_CLASS_ARG1_MAX               typename... _Arg
#define MY_ARG1_ARG2_MAX                _Arg...
#define MY_ARG1_ARG2_REF_MAX            _Arg&...
#define MY_ARG1_ARG2_CREF_MAX           const _Arg&...
#define MY_ARG1_A1_MAX                  _Arg... _Ax
#define MY_ARG1_A1_REF_MAX              _Arg&... _Ax
#define MY_ARG1_A1_REFREF_MAX           _Arg&&... _Ax
#define MY_ARG1_A1_CREF_MAX             const _Arg&... _Ax
#define MY_A1_A2_MAX                    _Ax...

#define MY_A1_A2_FWD_MAX                _STD forward<_Arg>(_Ax)...
#define MY_A1_A2_MOV_MAX                _STD move(_Ax)...
#define MY_A1_A2_STRFWD_MAX             string_forward(_Ax)...

#define MY_TAIL_MAX(x)                  x...
#define MY_CLASS_ARG0_DEF_MAX(_Val)     typename... _Arg
#define MY_CLASS_ARG1_DEF_MAX(_Val)     typename... _Arg

#endif /* _MSC_VER < 1800 || _STRING_PRINTF_NO_VARIADIC_TEMPLATES_ */


#define __FUNCTION_OBJECT_STRUCT_BEGIN(function_name)   \
_STDEX_TYPE_BEGIN                                       \
struct function_name ## _t {

#define __FUNCTION_OBJECT_STRUCT_END(function_name)     \
};                                                      \
_STDEX_TYPE_END


#define __FUNCTION_OBJECT__(function_name)              \
inline _STDEX_TYPE function_name ## _t function_name()  \
{                                                       \
    return _STDEX_TYPE function_name ## _t();           \
}


#define __FUNCTION_OBJECT_EXTRA(call_function, function_name)



#define __FUNCTION_OBJECT_PART1_1(next)     next
#define __FUNCTION_OBJECT_PART1_2(next)     __FUNCTION_OBJECT_PART1_1(typename T1), next
#define __FUNCTION_OBJECT_PART1_3(next)     __FUNCTION_OBJECT_PART1_2(typename T2), next
#define __FUNCTION_OBJECT_PART1_4(next)     __FUNCTION_OBJECT_PART1_3(typename T3), next
#define __FUNCTION_OBJECT_PART1_5(next)     __FUNCTION_OBJECT_PART1_4(typename T4), next
#define __FUNCTION_OBJECT_PART1_6(next)     __FUNCTION_OBJECT_PART1_5(typename T5), next
#define __FUNCTION_OBJECT_PART1_7(next)     __FUNCTION_OBJECT_PART1_6(typename T6), next
#define __FUNCTION_OBJECT_PART1_8(next)     __FUNCTION_OBJECT_PART1_7(typename T7), next
#define __FUNCTION_OBJECT_PART1_9(next)     __FUNCTION_OBJECT_PART1_8(typename T8), next
#define __FUNCTION_OBJECT_PART1_10(next)    __FUNCTION_OBJECT_PART1_9(typename T9), next
#define __FUNCTION_OBJECT_PART1_11(next)    __FUNCTION_OBJECT_PART1_10(typename T10), next
#define __FUNCTION_OBJECT_PART1_12(next)    __FUNCTION_OBJECT_PART1_11(typename T11), next
#define __FUNCTION_OBJECT_PART1_13(next)    __FUNCTION_OBJECT_PART1_12(typename T12), next
#define __FUNCTION_OBJECT_PART1_14(next)    __FUNCTION_OBJECT_PART1_13(typename T13), next
#define __FUNCTION_OBJECT_PART1_15(next)    __FUNCTION_OBJECT_PART1_14(typename T14), next
#define __FUNCTION_OBJECT_PART1_16(next)    __FUNCTION_OBJECT_PART1_15(typename T15), next
#define __FUNCTION_OBJECT_PART1_17(next)    __FUNCTION_OBJECT_PART1_16(typename T16), next
#define __FUNCTION_OBJECT_PART1_18(next)    __FUNCTION_OBJECT_PART1_17(typename T17), next
#define __FUNCTION_OBJECT_PART1_19(next)    __FUNCTION_OBJECT_PART1_18(typename T18), next
#define __FUNCTION_OBJECT_PART1_20(next)    __FUNCTION_OBJECT_PART1_19(typename T19), next
#define __FUNCTION_OBJECT_PART1_21(next)    __FUNCTION_OBJECT_PART1_20(typename T20), next
#define __FUNCTION_OBJECT_PART1_22(next)    __FUNCTION_OBJECT_PART1_21(typename T21), next
#define __FUNCTION_OBJECT_PART1_23(next)    __FUNCTION_OBJECT_PART1_22(typename T22), next
#define __FUNCTION_OBJECT_PART1_24(next)    __FUNCTION_OBJECT_PART1_23(typename T23), next
#define __FUNCTION_OBJECT_PART1_25(next)    __FUNCTION_OBJECT_PART1_24(typename T24), next
#define __FUNCTION_OBJECT_PART1_26(next)    __FUNCTION_OBJECT_PART1_25(typename T25), next
#define __FUNCTION_OBJECT_PART1_27(next)    __FUNCTION_OBJECT_PART1_26(typename T26), next
#define __FUNCTION_OBJECT_PART1_28(next)    __FUNCTION_OBJECT_PART1_27(typename T27), next
#define __FUNCTION_OBJECT_PART1_29(next)    __FUNCTION_OBJECT_PART1_28(typename T28), next
#define __FUNCTION_OBJECT_PART1_30(next)    __FUNCTION_OBJECT_PART1_29(typename T29), next
#define __FUNCTION_OBJECT_PART1_31(next)    __FUNCTION_OBJECT_PART1_30(typename T30), next

#define __FUNCTION_OBJECT_PART2_1(next)     next
#define __FUNCTION_OBJECT_PART2_2(next)     __FUNCTION_OBJECT_PART2_1(T1&& A1), next
#define __FUNCTION_OBJECT_PART2_3(next)     __FUNCTION_OBJECT_PART2_2(T2&& A2), next
#define __FUNCTION_OBJECT_PART2_4(next)     __FUNCTION_OBJECT_PART2_3(T3&& A3), next
#define __FUNCTION_OBJECT_PART2_5(next)     __FUNCTION_OBJECT_PART2_4(T4&& A4), next
#define __FUNCTION_OBJECT_PART2_6(next)     __FUNCTION_OBJECT_PART2_5(T5&& A5), next
#define __FUNCTION_OBJECT_PART2_7(next)     __FUNCTION_OBJECT_PART2_6(T6&& A6), next
#define __FUNCTION_OBJECT_PART2_8(next)     __FUNCTION_OBJECT_PART2_7(T7&& A7), next
#define __FUNCTION_OBJECT_PART2_9(next)     __FUNCTION_OBJECT_PART2_8(T8&& A8), next
#define __FUNCTION_OBJECT_PART2_10(next)    __FUNCTION_OBJECT_PART2_9(T9&& A9), next
#define __FUNCTION_OBJECT_PART2_11(next)    __FUNCTION_OBJECT_PART2_10(T10&& A10), next
#define __FUNCTION_OBJECT_PART2_12(next)    __FUNCTION_OBJECT_PART2_11(T11&& A11), next
#define __FUNCTION_OBJECT_PART2_13(next)    __FUNCTION_OBJECT_PART2_12(T12&& A12), next
#define __FUNCTION_OBJECT_PART2_14(next)    __FUNCTION_OBJECT_PART2_13(T13&& A13), next
#define __FUNCTION_OBJECT_PART2_15(next)    __FUNCTION_OBJECT_PART2_14(T14&& A14), next
#define __FUNCTION_OBJECT_PART2_16(next)    __FUNCTION_OBJECT_PART2_15(T15&& A15), next
#define __FUNCTION_OBJECT_PART2_17(next)    __FUNCTION_OBJECT_PART2_16(T16&& A16), next
#define __FUNCTION_OBJECT_PART2_18(next)    __FUNCTION_OBJECT_PART2_17(T17&& A17), next
#define __FUNCTION_OBJECT_PART2_19(next)    __FUNCTION_OBJECT_PART2_18(T18&& A18), next
#define __FUNCTION_OBJECT_PART2_20(next)    __FUNCTION_OBJECT_PART2_19(T19&& A19), next
#define __FUNCTION_OBJECT_PART2_21(next)    __FUNCTION_OBJECT_PART2_20(T20&& A20), next
#define __FUNCTION_OBJECT_PART2_22(next)    __FUNCTION_OBJECT_PART2_21(T21&& A21), next
#define __FUNCTION_OBJECT_PART2_23(next)    __FUNCTION_OBJECT_PART2_22(T22&& A22), next
#define __FUNCTION_OBJECT_PART2_24(next)    __FUNCTION_OBJECT_PART2_23(T23&& A23), next
#define __FUNCTION_OBJECT_PART2_25(next)    __FUNCTION_OBJECT_PART2_24(T24&& A24), next
#define __FUNCTION_OBJECT_PART2_26(next)    __FUNCTION_OBJECT_PART2_25(T25&& A25), next
#define __FUNCTION_OBJECT_PART2_27(next)    __FUNCTION_OBJECT_PART2_26(T26&& A26), next
#define __FUNCTION_OBJECT_PART2_28(next)    __FUNCTION_OBJECT_PART2_27(T27&& A27), next
#define __FUNCTION_OBJECT_PART2_29(next)    __FUNCTION_OBJECT_PART2_28(T28&& A28), next
#define __FUNCTION_OBJECT_PART2_30(next)    __FUNCTION_OBJECT_PART2_29(T29&& A29), next
#define __FUNCTION_OBJECT_PART2_31(next)    __FUNCTION_OBJECT_PART2_30(T30&& A30), next

#define __FUNCTION_OBJECT_PART3_1(next)     next
#define __FUNCTION_OBJECT_PART3_2(next)     __FUNCTION_OBJECT_PART3_1(_STD forward<T1>(A1)), next
#define __FUNCTION_OBJECT_PART3_3(next)     __FUNCTION_OBJECT_PART3_2(_STD forward<T2>(A2)), next
#define __FUNCTION_OBJECT_PART3_4(next)     __FUNCTION_OBJECT_PART3_3(_STD forward<T3>(A3)), next
#define __FUNCTION_OBJECT_PART3_5(next)     __FUNCTION_OBJECT_PART3_4(_STD forward<T4>(A4)), next
#define __FUNCTION_OBJECT_PART3_6(next)     __FUNCTION_OBJECT_PART3_5(_STD forward<T5>(A5)), next
#define __FUNCTION_OBJECT_PART3_7(next)     __FUNCTION_OBJECT_PART3_6(_STD forward<T6>(A6)), next
#define __FUNCTION_OBJECT_PART3_8(next)     __FUNCTION_OBJECT_PART3_7(_STD forward<T7>(A7)), next
#define __FUNCTION_OBJECT_PART3_9(next)     __FUNCTION_OBJECT_PART3_8(_STD forward<T8>(A8)), next
#define __FUNCTION_OBJECT_PART3_10(next)    __FUNCTION_OBJECT_PART3_9(_STD forward<T9>(A9)), next
#define __FUNCTION_OBJECT_PART3_11(next)    __FUNCTION_OBJECT_PART3_10(_STD forward<T10>(A10)), next
#define __FUNCTION_OBJECT_PART3_12(next)    __FUNCTION_OBJECT_PART3_11(_STD forward<T11>(A11)), next
#define __FUNCTION_OBJECT_PART3_13(next)    __FUNCTION_OBJECT_PART3_12(_STD forward<T12>(A12)), next
#define __FUNCTION_OBJECT_PART3_14(next)    __FUNCTION_OBJECT_PART3_13(_STD forward<T13>(A13)), next
#define __FUNCTION_OBJECT_PART3_15(next)    __FUNCTION_OBJECT_PART3_14(_STD forward<T14>(A14)), next
#define __FUNCTION_OBJECT_PART3_16(next)    __FUNCTION_OBJECT_PART3_15(_STD forward<T15>(A15)), next
#define __FUNCTION_OBJECT_PART3_17(next)    __FUNCTION_OBJECT_PART3_16(_STD forward<T16>(A16)), next
#define __FUNCTION_OBJECT_PART3_18(next)    __FUNCTION_OBJECT_PART3_17(_STD forward<T17>(A17)), next
#define __FUNCTION_OBJECT_PART3_19(next)    __FUNCTION_OBJECT_PART3_18(_STD forward<T18>(A18)), next
#define __FUNCTION_OBJECT_PART3_20(next)    __FUNCTION_OBJECT_PART3_19(_STD forward<T19>(A19)), next
#define __FUNCTION_OBJECT_PART3_21(next)    __FUNCTION_OBJECT_PART3_20(_STD forward<T20>(A20)), next
#define __FUNCTION_OBJECT_PART3_22(next)    __FUNCTION_OBJECT_PART3_21(_STD forward<T21>(A21)), next
#define __FUNCTION_OBJECT_PART3_23(next)    __FUNCTION_OBJECT_PART3_22(_STD forward<T22>(A22)), next
#define __FUNCTION_OBJECT_PART3_24(next)    __FUNCTION_OBJECT_PART3_23(_STD forward<T23>(A23)), next
#define __FUNCTION_OBJECT_PART3_25(next)    __FUNCTION_OBJECT_PART3_24(_STD forward<T24>(A24)), next
#define __FUNCTION_OBJECT_PART3_26(next)    __FUNCTION_OBJECT_PART3_25(_STD forward<T25>(A25)), next
#define __FUNCTION_OBJECT_PART3_27(next)    __FUNCTION_OBJECT_PART3_26(_STD forward<T26>(A26)), next
#define __FUNCTION_OBJECT_PART3_28(next)    __FUNCTION_OBJECT_PART3_27(_STD forward<T27>(A27)), next
#define __FUNCTION_OBJECT_PART3_29(next)    __FUNCTION_OBJECT_PART3_28(_STD forward<T28>(A28)), next
#define __FUNCTION_OBJECT_PART3_30(next)    __FUNCTION_OBJECT_PART3_29(_STD forward<T29>(A29)), next
#define __FUNCTION_OBJECT_PART3_31(next)    __FUNCTION_OBJECT_PART3_30(_STD forward<T30>(A30)), next


#define __FUNCTION_OBJECT_BASE(call_function, function_name, part1, part2, part3)   \
template<part1> inline auto function_name(part2) -> decltype(call_function(part3))  \
{                                                                                   \
    return call_function(part3);                                                    \
}


#define __FUNCTION_OBJECT_1(call_function, function_name)                                           \
    __FUNCTION_OBJECT_BASE(call_function, function_name, __FUNCTION_OBJECT_PART1_1(typename T1),    \
        __FUNCTION_OBJECT_PART2_1(T1&& A1), __FUNCTION_OBJECT_PART3_1(_STD forward<T1>(A1)))
#define __FUNCTION_OBJECT_2(call_function, function_name)                                           \
    __FUNCTION_OBJECT_BASE(call_function, function_name, __FUNCTION_OBJECT_PART1_2(typename T2),    \
        __FUNCTION_OBJECT_PART2_2(T2&& A2), __FUNCTION_OBJECT_PART3_2(_STD forward<T2>(A2)))
#define __FUNCTION_OBJECT_3(call_function, function_name)                                           \
    __FUNCTION_OBJECT_BASE(call_function, function_name, __FUNCTION_OBJECT_PART1_3(typename T3),    \
        __FUNCTION_OBJECT_PART2_3(T3&& A3), __FUNCTION_OBJECT_PART3_3(_STD forward<T3>(A3)))
#define __FUNCTION_OBJECT_4(call_function, function_name)                                           \
    __FUNCTION_OBJECT_BASE(call_function, function_name, __FUNCTION_OBJECT_PART1_4(typename T4),    \
        __FUNCTION_OBJECT_PART2_4(T4&& A4), __FUNCTION_OBJECT_PART3_4(_STD forward<T4>(A4)))
#define __FUNCTION_OBJECT_5(call_function, function_name)                                           \
    __FUNCTION_OBJECT_BASE(call_function, function_name, __FUNCTION_OBJECT_PART1_5(typename T5),    \
        __FUNCTION_OBJECT_PART2_5(T5&& A5), __FUNCTION_OBJECT_PART3_5(_STD forward<T5>(A5)))
#define __FUNCTION_OBJECT_6(call_function, function_name)                                           \
    __FUNCTION_OBJECT_BASE(call_function, function_name, __FUNCTION_OBJECT_PART1_6(typename T6),    \
        __FUNCTION_OBJECT_PART2_6(T6&& A6), __FUNCTION_OBJECT_PART3_6(_STD forward<T6>(A6)))
#define __FUNCTION_OBJECT_7(call_function, function_name)                                           \
    __FUNCTION_OBJECT_BASE(call_function, function_name, __FUNCTION_OBJECT_PART1_7(typename T7),    \
        __FUNCTION_OBJECT_PART2_7(T7&& A7), __FUNCTION_OBJECT_PART3_7(_STD forward<T7>(A7)))
#define __FUNCTION_OBJECT_8(call_function, function_name)                                           \
    __FUNCTION_OBJECT_BASE(call_function, function_name, __FUNCTION_OBJECT_PART1_8(typename T8),    \
        __FUNCTION_OBJECT_PART2_8(T8&& A8), __FUNCTION_OBJECT_PART3_8(_STD forward<T8>(A8)))
#define __FUNCTION_OBJECT_9(call_function, function_name)                                           \
    __FUNCTION_OBJECT_BASE(call_function, function_name, __FUNCTION_OBJECT_PART1_9(typename T9),    \
        __FUNCTION_OBJECT_PART2_9(T9&& A9), __FUNCTION_OBJECT_PART3_9(_STD forward<T9>(A9)))
#define __FUNCTION_OBJECT_10(call_function, function_name)                                          \
    __FUNCTION_OBJECT_BASE(call_function, function_name, __FUNCTION_OBJECT_PART1_10(typename T10),  \
        __FUNCTION_OBJECT_PART2_10(T10&& A10), __FUNCTION_OBJECT_PART3_10(_STD forward<T10>(A10)))
#define __FUNCTION_OBJECT_11(call_function, function_name)                                          \
    __FUNCTION_OBJECT_BASE(call_function, function_name, __FUNCTION_OBJECT_PART1_11(typename T11),  \
        __FUNCTION_OBJECT_PART2_11(T11&& A11), __FUNCTION_OBJECT_PART3_11(_STD forward<T11>(A11)))
#define __FUNCTION_OBJECT_12(call_function, function_name)                                          \
    __FUNCTION_OBJECT_BASE(call_function, function_name, __FUNCTION_OBJECT_PART1_12(typename T12),  \
        __FUNCTION_OBJECT_PART2_12(T12&& A12), __FUNCTION_OBJECT_PART3_12(_STD forward<T12>(A12)))
#define __FUNCTION_OBJECT_13(call_function, function_name)                                          \
    __FUNCTION_OBJECT_BASE(call_function, function_name, __FUNCTION_OBJECT_PART1_13(typename T13),  \
        __FUNCTION_OBJECT_PART2_13(T13&& A13), __FUNCTION_OBJECT_PART3_13(_STD forward<T13>(A13)))
#define __FUNCTION_OBJECT_14(call_function, function_name)                                          \
    __FUNCTION_OBJECT_BASE(call_function, function_name, __FUNCTION_OBJECT_PART1_14(typename T14),  \
        __FUNCTION_OBJECT_PART2_14(T14&& A14), __FUNCTION_OBJECT_PART3_14(_STD forward<T14>(A14)))
#define __FUNCTION_OBJECT_15(call_function, function_name)                                          \
    __FUNCTION_OBJECT_BASE(call_function, function_name, __FUNCTION_OBJECT_PART1_15(typename T15),  \
        __FUNCTION_OBJECT_PART2_15(T15&& A15), __FUNCTION_OBJECT_PART3_15(_STD forward<T15>(A15)))
#define __FUNCTION_OBJECT_16(call_function, function_name)                                          \
    __FUNCTION_OBJECT_BASE(call_function, function_name, __FUNCTION_OBJECT_PART1_16(typename T16),  \
        __FUNCTION_OBJECT_PART2_16(T16&& A16), __FUNCTION_OBJECT_PART3_16(_STD forward<T16>(A16)))
#define __FUNCTION_OBJECT_17(call_function, function_name)                                          \
    __FUNCTION_OBJECT_BASE(call_function, function_name, __FUNCTION_OBJECT_PART1_17(typename T17),  \
        __FUNCTION_OBJECT_PART2_17(T17&& A17), __FUNCTION_OBJECT_PART3_17(_STD forward<T17>(A17)))
#define __FUNCTION_OBJECT_18(call_function, function_name)                                          \
    __FUNCTION_OBJECT_BASE(call_function, function_name, __FUNCTION_OBJECT_PART1_18(typename T18),  \
        __FUNCTION_OBJECT_PART2_18(T18&& A18), __FUNCTION_OBJECT_PART3_18(_STD forward<T18>(A18)))
#define __FUNCTION_OBJECT_19(call_function, function_name)                                          \
    __FUNCTION_OBJECT_BASE(call_function, function_name, __FUNCTION_OBJECT_PART1_19(typename T19),  \
        __FUNCTION_OBJECT_PART2_19(T19&& A19), __FUNCTION_OBJECT_PART3_19(_STD forward<T19>(A19)))
#define __FUNCTION_OBJECT_20(call_function, function_name)                                          \
    __FUNCTION_OBJECT_BASE(call_function, function_name, __FUNCTION_OBJECT_PART1_20(typename T20),  \
        __FUNCTION_OBJECT_PART2_20(T20&& A20), __FUNCTION_OBJECT_PART3_20(_STD forward<T20>(A20)))
#define __FUNCTION_OBJECT_21(call_function, function_name)                                          \
    __FUNCTION_OBJECT_BASE(call_function, function_name, __FUNCTION_OBJECT_PART1_21(typename T21),  \
        __FUNCTION_OBJECT_PART2_21(T21&& A21), __FUNCTION_OBJECT_PART3_21(_STD forward<T21>(A21)))
#define __FUNCTION_OBJECT_22(call_function, function_name)                                          \
    __FUNCTION_OBJECT_BASE(call_function, function_name, __FUNCTION_OBJECT_PART1_22(typename T22),  \
        __FUNCTION_OBJECT_PART2_22(T22&& A22), __FUNCTION_OBJECT_PART3_22(_STD forward<T22>(A22)))
#define __FUNCTION_OBJECT_23(call_function, function_name)                                          \
    __FUNCTION_OBJECT_BASE(call_function, function_name, __FUNCTION_OBJECT_PART1_23(typename T23),  \
        __FUNCTION_OBJECT_PART2_23(T23&& A23), __FUNCTION_OBJECT_PART3_23(_STD forward<T23>(A23)))
#define __FUNCTION_OBJECT_24(call_function, function_name)                                          \
    __FUNCTION_OBJECT_BASE(call_function, function_name, __FUNCTION_OBJECT_PART1_24(typename T24),  \
        __FUNCTION_OBJECT_PART2_24(T24&& A24), __FUNCTION_OBJECT_PART3_24(_STD forward<T24>(A24)))
#define __FUNCTION_OBJECT_25(call_function, function_name)                                          \
    __FUNCTION_OBJECT_BASE(call_function, function_name, __FUNCTION_OBJECT_PART1_25(typename T25),  \
        __FUNCTION_OBJECT_PART2_25(T25&& A25), __FUNCTION_OBJECT_PART3_25(_STD forward<T25>(A25)))
#define __FUNCTION_OBJECT_26(call_function, function_name)                                          \
    __FUNCTION_OBJECT_BASE(call_function, function_name, __FUNCTION_OBJECT_PART1_26(typename T26),  \
        __FUNCTION_OBJECT_PART2_26(T26&& A26), __FUNCTION_OBJECT_PART3_26(_STD forward<T26>(A26)))
#define __FUNCTION_OBJECT_27(call_function, function_name)                                          \
    __FUNCTION_OBJECT_BASE(call_function, function_name, __FUNCTION_OBJECT_PART1_27(typename T27),  \
        __FUNCTION_OBJECT_PART2_27(T27&& A27), __FUNCTION_OBJECT_PART3_27(_STD forward<T27>(A27)))
#define __FUNCTION_OBJECT_28(call_function, function_name)                                          \
    __FUNCTION_OBJECT_BASE(call_function, function_name, __FUNCTION_OBJECT_PART1_28(typename T28),  \
        __FUNCTION_OBJECT_PART2_28(T28&& A28), __FUNCTION_OBJECT_PART3_28(_STD forward<T28>(A28)))
#define __FUNCTION_OBJECT_29(call_function, function_name)                                          \
    __FUNCTION_OBJECT_BASE(call_function, function_name, __FUNCTION_OBJECT_PART1_29(typename T29),  \
        __FUNCTION_OBJECT_PART2_29(T29&& A29), __FUNCTION_OBJECT_PART3_29(_STD forward<T29>(A29)))
#define __FUNCTION_OBJECT_30(call_function, function_name)                                          \
    __FUNCTION_OBJECT_BASE(call_function, function_name, __FUNCTION_OBJECT_PART1_30(typename T30),  \
        __FUNCTION_OBJECT_PART2_30(T30&& A30), __FUNCTION_OBJECT_PART3_30(_STD forward<T30>(A30)))


#define __FUNCTION_OBJECT_1_1(call_function, function_name)     __FUNCTION_OBJECT_1(call_function, function_name)

#define __FUNCTION_OBJECT_2_2(call_function, function_name)     __FUNCTION_OBJECT_2(call_function, function_name)
#define __FUNCTION_OBJECT_2_1(call_function, function_name)     \
            __FUNCTION_OBJECT_1(call_function, function_name)   __FUNCTION_OBJECT_2_2(call_function, function_name)

#define __FUNCTION_OBJECT_3_3(call_function, function_name)     __FUNCTION_OBJECT_3(call_function, function_name)
#define __FUNCTION_OBJECT_3_2(call_function, function_name)     \
            __FUNCTION_OBJECT_2(call_function, function_name)   __FUNCTION_OBJECT_3_3(call_function, function_name)
#define __FUNCTION_OBJECT_3_1(call_function, function_name)     \
            __FUNCTION_OBJECT_1(call_function, function_name)   __FUNCTION_OBJECT_3_2(call_function, function_name)

#define __FUNCTION_OBJECT_4_4(call_function, function_name)     __FUNCTION_OBJECT_4(call_function, function_name)
#define __FUNCTION_OBJECT_4_3(call_function, function_name)     \
            __FUNCTION_OBJECT_3(call_function, function_name)   __FUNCTION_OBJECT_4_4(call_function, function_name)
#define __FUNCTION_OBJECT_4_2(call_function, function_name)     \
            __FUNCTION_OBJECT_2(call_function, function_name)   __FUNCTION_OBJECT_4_3(call_function, function_name)
#define __FUNCTION_OBJECT_4_1(call_function, function_name)     \
            __FUNCTION_OBJECT_1(call_function, function_name)   __FUNCTION_OBJECT_4_2(call_function, function_name)

#define __FUNCTION_OBJECT_5_5(call_function, function_name)     __FUNCTION_OBJECT_5(call_function, function_name)
#define __FUNCTION_OBJECT_5_4(call_function, function_name)     \
            __FUNCTION_OBJECT_4(call_function, function_name)   __FUNCTION_OBJECT_5_5(call_function, function_name)
#define __FUNCTION_OBJECT_5_3(call_function, function_name)     \
            __FUNCTION_OBJECT_3(call_function, function_name)   __FUNCTION_OBJECT_5_4(call_function, function_name)
#define __FUNCTION_OBJECT_5_2(call_function, function_name)     \
            __FUNCTION_OBJECT_2(call_function, function_name)   __FUNCTION_OBJECT_5_3(call_function, function_name)
#define __FUNCTION_OBJECT_5_1(call_function, function_name)     \
            __FUNCTION_OBJECT_1(call_function, function_name)   __FUNCTION_OBJECT_5_2(call_function, function_name)

#define __FUNCTION_OBJECT_6_6(call_function, function_name)     __FUNCTION_OBJECT_6(call_function, function_name)
#define __FUNCTION_OBJECT_6_5(call_function, function_name)     \
            __FUNCTION_OBJECT_5(call_function, function_name)   __FUNCTION_OBJECT_6_6(call_function, function_name)
#define __FUNCTION_OBJECT_6_4(call_function, function_name)     \
            __FUNCTION_OBJECT_4(call_function, function_name)   __FUNCTION_OBJECT_6_5(call_function, function_name)
#define __FUNCTION_OBJECT_6_3(call_function, function_name)     \
            __FUNCTION_OBJECT_3(call_function, function_name)   __FUNCTION_OBJECT_6_4(call_function, function_name)
#define __FUNCTION_OBJECT_6_2(call_function, function_name)     \
            __FUNCTION_OBJECT_2(call_function, function_name)   __FUNCTION_OBJECT_6_3(call_function, function_name)
#define __FUNCTION_OBJECT_6_1(call_function, function_name)     \
            __FUNCTION_OBJECT_1(call_function, function_name)   __FUNCTION_OBJECT_6_2(call_function, function_name)

#define __FUNCTION_OBJECT_7_7(call_function, function_name)     __FUNCTION_OBJECT_7(call_function, function_name)
#define __FUNCTION_OBJECT_7_6(call_function, function_name)     \
            __FUNCTION_OBJECT_6(call_function, function_name)   __FUNCTION_OBJECT_7_7(call_function, function_name)
#define __FUNCTION_OBJECT_7_5(call_function, function_name)     \
            __FUNCTION_OBJECT_5(call_function, function_name)   __FUNCTION_OBJECT_7_6(call_function, function_name)
#define __FUNCTION_OBJECT_7_4(call_function, function_name)     \
            __FUNCTION_OBJECT_4(call_function, function_name)   __FUNCTION_OBJECT_7_5(call_function, function_name)
#define __FUNCTION_OBJECT_7_3(call_function, function_name)     \
            __FUNCTION_OBJECT_3(call_function, function_name)   __FUNCTION_OBJECT_7_4(call_function, function_name)
#define __FUNCTION_OBJECT_7_2(call_function, function_name)     \
            __FUNCTION_OBJECT_2(call_function, function_name)   __FUNCTION_OBJECT_7_3(call_function, function_name)
#define __FUNCTION_OBJECT_7_1(call_function, function_name)     \
            __FUNCTION_OBJECT_1(call_function, function_name)   __FUNCTION_OBJECT_7_2(call_function, function_name)

#define __FUNCTION_OBJECT_8_8(call_function, function_name)     __FUNCTION_OBJECT_8(call_function, function_name)
#define __FUNCTION_OBJECT_8_7(call_function, function_name)     \
            __FUNCTION_OBJECT_7(call_function, function_name)   __FUNCTION_OBJECT_8_8(call_function, function_name)
#define __FUNCTION_OBJECT_8_6(call_function, function_name)     \
            __FUNCTION_OBJECT_6(call_function, function_name)   __FUNCTION_OBJECT_8_7(call_function, function_name)
#define __FUNCTION_OBJECT_8_5(call_function, function_name)     \
            __FUNCTION_OBJECT_5(call_function, function_name)   __FUNCTION_OBJECT_8_6(call_function, function_name)
#define __FUNCTION_OBJECT_8_4(call_function, function_name)     \
            __FUNCTION_OBJECT_4(call_function, function_name)   __FUNCTION_OBJECT_8_5(call_function, function_name)
#define __FUNCTION_OBJECT_8_3(call_function, function_name)     \
            __FUNCTION_OBJECT_3(call_function, function_name)   __FUNCTION_OBJECT_8_4(call_function, function_name)
#define __FUNCTION_OBJECT_8_2(call_function, function_name)     \
            __FUNCTION_OBJECT_2(call_function, function_name)   __FUNCTION_OBJECT_8_3(call_function, function_name)
#define __FUNCTION_OBJECT_8_1(call_function, function_name)     \
            __FUNCTION_OBJECT_1(call_function, function_name)   __FUNCTION_OBJECT_8_2(call_function, function_name)

#define __FUNCTION_OBJECT_9_9(call_function, function_name)     __FUNCTION_OBJECT_9(call_function, function_name)
#define __FUNCTION_OBJECT_9_8(call_function, function_name)     \
            __FUNCTION_OBJECT_8(call_function, function_name)   __FUNCTION_OBJECT_9_9(call_function, function_name)
#define __FUNCTION_OBJECT_9_7(call_function, function_name)     \
            __FUNCTION_OBJECT_7(call_function, function_name)   __FUNCTION_OBJECT_9_8(call_function, function_name)
#define __FUNCTION_OBJECT_9_6(call_function, function_name)     \
            __FUNCTION_OBJECT_6(call_function, function_name)   __FUNCTION_OBJECT_9_7(call_function, function_name)
#define __FUNCTION_OBJECT_9_5(call_function, function_name)     \
            __FUNCTION_OBJECT_5(call_function, function_name)   __FUNCTION_OBJECT_9_6(call_function, function_name)
#define __FUNCTION_OBJECT_9_4(call_function, function_name)     \
            __FUNCTION_OBJECT_4(call_function, function_name)   __FUNCTION_OBJECT_9_5(call_function, function_name)
#define __FUNCTION_OBJECT_9_3(call_function, function_name)     \
            __FUNCTION_OBJECT_3(call_function, function_name)   __FUNCTION_OBJECT_9_4(call_function, function_name)
#define __FUNCTION_OBJECT_9_2(call_function, function_name)     \
            __FUNCTION_OBJECT_2(call_function, function_name)   __FUNCTION_OBJECT_9_3(call_function, function_name)
#define __FUNCTION_OBJECT_9_1(call_function, function_name)     \
            __FUNCTION_OBJECT_1(call_function, function_name)   __FUNCTION_OBJECT_9_2(call_function, function_name)

#define __FUNCTION_OBJECT_10_10(call_function, function_name)   __FUNCTION_OBJECT_10(call_function, function_name)
#define __FUNCTION_OBJECT_10_9(call_function, function_name)    \
            __FUNCTION_OBJECT_9(call_function, function_name)   __FUNCTION_OBJECT_10_10(call_function, function_name)
#define __FUNCTION_OBJECT_10_8(call_function, function_name)    \
            __FUNCTION_OBJECT_8(call_function, function_name)   __FUNCTION_OBJECT_10_9(call_function, function_name)
#define __FUNCTION_OBJECT_10_7(call_function, function_name)    \
            __FUNCTION_OBJECT_7(call_function, function_name)   __FUNCTION_OBJECT_10_8(call_function, function_name)
#define __FUNCTION_OBJECT_10_6(call_function, function_name)    \
            __FUNCTION_OBJECT_6(call_function, function_name)   __FUNCTION_OBJECT_10_7(call_function, function_name)
#define __FUNCTION_OBJECT_10_5(call_function, function_name)    \
            __FUNCTION_OBJECT_5(call_function, function_name)   __FUNCTION_OBJECT_10_6(call_function, function_name)
#define __FUNCTION_OBJECT_10_4(call_function, function_name)    \
            __FUNCTION_OBJECT_4(call_function, function_name)   __FUNCTION_OBJECT_10_5(call_function, function_name)
#define __FUNCTION_OBJECT_10_3(call_function, function_name)    \
            __FUNCTION_OBJECT_3(call_function, function_name)   __FUNCTION_OBJECT_10_4(call_function, function_name)
#define __FUNCTION_OBJECT_10_2(call_function, function_name)    \
            __FUNCTION_OBJECT_2(call_function, function_name)   __FUNCTION_OBJECT_10_3(call_function, function_name)
#define __FUNCTION_OBJECT_10_1(call_function, function_name)    \
            __FUNCTION_OBJECT_1(call_function, function_name)   __FUNCTION_OBJECT_10_2(call_function, function_name)

#define __FUNCTION_OBJECT_11_11(call_function, function_name)   __FUNCTION_OBJECT_11(call_function, function_name)
#define __FUNCTION_OBJECT_11_10(call_function, function_name)   \
            __FUNCTION_OBJECT_10(call_function, function_name)  __FUNCTION_OBJECT_11_11(call_function, function_name)
#define __FUNCTION_OBJECT_11_9(call_function, function_name)    \
            __FUNCTION_OBJECT_9(call_function, function_name)   __FUNCTION_OBJECT_11_10(call_function, function_name)
#define __FUNCTION_OBJECT_11_8(call_function, function_name)    \
            __FUNCTION_OBJECT_8(call_function, function_name)   __FUNCTION_OBJECT_11_9(call_function, function_name)
#define __FUNCTION_OBJECT_11_7(call_function, function_name)    \
            __FUNCTION_OBJECT_7(call_function, function_name)   __FUNCTION_OBJECT_11_8(call_function, function_name)
#define __FUNCTION_OBJECT_11_6(call_function, function_name)    \
            __FUNCTION_OBJECT_6(call_function, function_name)   __FUNCTION_OBJECT_11_7(call_function, function_name)
#define __FUNCTION_OBJECT_11_5(call_function, function_name)    \
            __FUNCTION_OBJECT_5(call_function, function_name)   __FUNCTION_OBJECT_11_6(call_function, function_name)
#define __FUNCTION_OBJECT_11_4(call_function, function_name)    \
            __FUNCTION_OBJECT_4(call_function, function_name)   __FUNCTION_OBJECT_11_5(call_function, function_name)
#define __FUNCTION_OBJECT_11_3(call_function, function_name)    \
            __FUNCTION_OBJECT_3(call_function, function_name)   __FUNCTION_OBJECT_11_4(call_function, function_name)
#define __FUNCTION_OBJECT_11_2(call_function, function_name)    \
            __FUNCTION_OBJECT_2(call_function, function_name)   __FUNCTION_OBJECT_11_3(call_function, function_name)
#define __FUNCTION_OBJECT_11_1(call_function, function_name)    \
            __FUNCTION_OBJECT_1(call_function, function_name)   __FUNCTION_OBJECT_11_2(call_function, function_name)

#define __FUNCTION_OBJECT_12_12(call_function, function_name)   __FUNCTION_OBJECT_12(call_function, function_name)
#define __FUNCTION_OBJECT_12_11(call_function, function_name)   \
            __FUNCTION_OBJECT_11(call_function, function_name)  __FUNCTION_OBJECT_12_12(call_function, function_name)
#define __FUNCTION_OBJECT_12_10(call_function, function_name)   \
            __FUNCTION_OBJECT_10(call_function, function_name)  __FUNCTION_OBJECT_12_11(call_function, function_name)
#define __FUNCTION_OBJECT_12_9(call_function, function_name)    \
            __FUNCTION_OBJECT_9(call_function, function_name)   __FUNCTION_OBJECT_12_10(call_function, function_name)
#define __FUNCTION_OBJECT_12_8(call_function, function_name)    \
            __FUNCTION_OBJECT_8(call_function, function_name)   __FUNCTION_OBJECT_12_9(call_function, function_name)
#define __FUNCTION_OBJECT_12_7(call_function, function_name)    \
            __FUNCTION_OBJECT_7(call_function, function_name)   __FUNCTION_OBJECT_12_8(call_function, function_name)
#define __FUNCTION_OBJECT_12_6(call_function, function_name)    \
            __FUNCTION_OBJECT_6(call_function, function_name)   __FUNCTION_OBJECT_12_7(call_function, function_name)
#define __FUNCTION_OBJECT_12_5(call_function, function_name)    \
            __FUNCTION_OBJECT_5(call_function, function_name)   __FUNCTION_OBJECT_12_6(call_function, function_name)
#define __FUNCTION_OBJECT_12_4(call_function, function_name)    \
            __FUNCTION_OBJECT_4(call_function, function_name)   __FUNCTION_OBJECT_12_5(call_function, function_name)
#define __FUNCTION_OBJECT_12_3(call_function, function_name)    \
            __FUNCTION_OBJECT_3(call_function, function_name)   __FUNCTION_OBJECT_12_4(call_function, function_name)
#define __FUNCTION_OBJECT_12_2(call_function, function_name)    \
            __FUNCTION_OBJECT_2(call_function, function_name)   __FUNCTION_OBJECT_12_3(call_function, function_name)
#define __FUNCTION_OBJECT_12_1(call_function, function_name)    \
            __FUNCTION_OBJECT_1(call_function, function_name)   __FUNCTION_OBJECT_12_2(call_function, function_name)

#define __FUNCTION_OBJECT_13_13(call_function, function_name)   __FUNCTION_OBJECT_13(call_function, function_name)
#define __FUNCTION_OBJECT_13_12(call_function, function_name)   \
            __FUNCTION_OBJECT_12(call_function, function_name)  __FUNCTION_OBJECT_13_13(call_function, function_name)
#define __FUNCTION_OBJECT_13_11(call_function, function_name)   \
            __FUNCTION_OBJECT_11(call_function, function_name)  __FUNCTION_OBJECT_13_12(call_function, function_name)
#define __FUNCTION_OBJECT_13_10(call_function, function_name)   \
            __FUNCTION_OBJECT_10(call_function, function_name)  __FUNCTION_OBJECT_13_11(call_function, function_name)
#define __FUNCTION_OBJECT_13_9(call_function, function_name)    \
            __FUNCTION_OBJECT_9(call_function, function_name)   __FUNCTION_OBJECT_13_10(call_function, function_name)
#define __FUNCTION_OBJECT_13_8(call_function, function_name)    \
            __FUNCTION_OBJECT_8(call_function, function_name)   __FUNCTION_OBJECT_13_9(call_function, function_name)
#define __FUNCTION_OBJECT_13_7(call_function, function_name)    \
            __FUNCTION_OBJECT_7(call_function, function_name)   __FUNCTION_OBJECT_13_8(call_function, function_name)
#define __FUNCTION_OBJECT_13_6(call_function, function_name)    \
            __FUNCTION_OBJECT_6(call_function, function_name)   __FUNCTION_OBJECT_13_7(call_function, function_name)
#define __FUNCTION_OBJECT_13_5(call_function, function_name)    \
            __FUNCTION_OBJECT_5(call_function, function_name)   __FUNCTION_OBJECT_13_6(call_function, function_name)
#define __FUNCTION_OBJECT_13_4(call_function, function_name)    \
            __FUNCTION_OBJECT_4(call_function, function_name)   __FUNCTION_OBJECT_13_5(call_function, function_name)
#define __FUNCTION_OBJECT_13_3(call_function, function_name)    \
            __FUNCTION_OBJECT_3(call_function, function_name)   __FUNCTION_OBJECT_13_4(call_function, function_name)
#define __FUNCTION_OBJECT_13_2(call_function, function_name)    \
            __FUNCTION_OBJECT_2(call_function, function_name)   __FUNCTION_OBJECT_13_3(call_function, function_name)
#define __FUNCTION_OBJECT_13_1(call_function, function_name)    \
            __FUNCTION_OBJECT_1(call_function, function_name)   __FUNCTION_OBJECT_13_2(call_function, function_name)

#define __FUNCTION_OBJECT_14_14(call_function, function_name)   __FUNCTION_OBJECT_14(call_function, function_name)
#define __FUNCTION_OBJECT_14_13(call_function, function_name)   \
            __FUNCTION_OBJECT_13(call_function, function_name)  __FUNCTION_OBJECT_14_14(call_function, function_name)
#define __FUNCTION_OBJECT_14_12(call_function, function_name)   \
            __FUNCTION_OBJECT_12(call_function, function_name)  __FUNCTION_OBJECT_14_13(call_function, function_name)
#define __FUNCTION_OBJECT_14_11(call_function, function_name)   \
            __FUNCTION_OBJECT_11(call_function, function_name)  __FUNCTION_OBJECT_14_12(call_function, function_name)
#define __FUNCTION_OBJECT_14_10(call_function, function_name)   \
            __FUNCTION_OBJECT_10(call_function, function_name)  __FUNCTION_OBJECT_14_11(call_function, function_name)
#define __FUNCTION_OBJECT_14_9(call_function, function_name)    \
            __FUNCTION_OBJECT_9(call_function, function_name)   __FUNCTION_OBJECT_14_10(call_function, function_name)
#define __FUNCTION_OBJECT_14_8(call_function, function_name)    \
            __FUNCTION_OBJECT_8(call_function, function_name)   __FUNCTION_OBJECT_14_9(call_function, function_name)
#define __FUNCTION_OBJECT_14_7(call_function, function_name)    \
            __FUNCTION_OBJECT_7(call_function, function_name)   __FUNCTION_OBJECT_14_8(call_function, function_name)
#define __FUNCTION_OBJECT_14_6(call_function, function_name)    \
            __FUNCTION_OBJECT_6(call_function, function_name)   __FUNCTION_OBJECT_14_7(call_function, function_name)
#define __FUNCTION_OBJECT_14_5(call_function, function_name)    \
            __FUNCTION_OBJECT_5(call_function, function_name)   __FUNCTION_OBJECT_14_6(call_function, function_name)
#define __FUNCTION_OBJECT_14_4(call_function, function_name)    \
            __FUNCTION_OBJECT_4(call_function, function_name)   __FUNCTION_OBJECT_14_5(call_function, function_name)
#define __FUNCTION_OBJECT_14_3(call_function, function_name)    \
            __FUNCTION_OBJECT_3(call_function, function_name)   __FUNCTION_OBJECT_14_4(call_function, function_name)
#define __FUNCTION_OBJECT_14_2(call_function, function_name)    \
            __FUNCTION_OBJECT_2(call_function, function_name)   __FUNCTION_OBJECT_14_3(call_function, function_name)
#define __FUNCTION_OBJECT_14_1(call_function, function_name)    \
            __FUNCTION_OBJECT_1(call_function, function_name)   __FUNCTION_OBJECT_14_2(call_function, function_name)

#define __FUNCTION_OBJECT_15_15(call_function, function_name)   __FUNCTION_OBJECT_15(call_function, function_name)
#define __FUNCTION_OBJECT_15_14(call_function, function_name)   \
            __FUNCTION_OBJECT_14(call_function, function_name)  __FUNCTION_OBJECT_15_15(call_function, function_name)
#define __FUNCTION_OBJECT_15_13(call_function, function_name)   \
            __FUNCTION_OBJECT_13(call_function, function_name)  __FUNCTION_OBJECT_15_14(call_function, function_name)
#define __FUNCTION_OBJECT_15_12(call_function, function_name)   \
            __FUNCTION_OBJECT_12(call_function, function_name)  __FUNCTION_OBJECT_15_13(call_function, function_name)
#define __FUNCTION_OBJECT_15_11(call_function, function_name)   \
            __FUNCTION_OBJECT_11(call_function, function_name)  __FUNCTION_OBJECT_15_12(call_function, function_name)
#define __FUNCTION_OBJECT_15_10(call_function, function_name)   \
            __FUNCTION_OBJECT_10(call_function, function_name)  __FUNCTION_OBJECT_15_11(call_function, function_name)
#define __FUNCTION_OBJECT_15_9(call_function, function_name)    \
            __FUNCTION_OBJECT_9(call_function, function_name)   __FUNCTION_OBJECT_15_10(call_function, function_name)
#define __FUNCTION_OBJECT_15_8(call_function, function_name)    \
            __FUNCTION_OBJECT_8(call_function, function_name)   __FUNCTION_OBJECT_15_9(call_function, function_name)
#define __FUNCTION_OBJECT_15_7(call_function, function_name)    \
            __FUNCTION_OBJECT_7(call_function, function_name)   __FUNCTION_OBJECT_15_8(call_function, function_name)
#define __FUNCTION_OBJECT_15_6(call_function, function_name)    \
            __FUNCTION_OBJECT_6(call_function, function_name)   __FUNCTION_OBJECT_15_7(call_function, function_name)
#define __FUNCTION_OBJECT_15_5(call_function, function_name)    \
            __FUNCTION_OBJECT_5(call_function, function_name)   __FUNCTION_OBJECT_15_6(call_function, function_name)
#define __FUNCTION_OBJECT_15_4(call_function, function_name)    \
            __FUNCTION_OBJECT_4(call_function, function_name)   __FUNCTION_OBJECT_15_5(call_function, function_name)
#define __FUNCTION_OBJECT_15_3(call_function, function_name)    \
            __FUNCTION_OBJECT_3(call_function, function_name)   __FUNCTION_OBJECT_15_4(call_function, function_name)
#define __FUNCTION_OBJECT_15_2(call_function, function_name)    \
            __FUNCTION_OBJECT_2(call_function, function_name)   __FUNCTION_OBJECT_15_3(call_function, function_name)
#define __FUNCTION_OBJECT_15_1(call_function, function_name)    \
            __FUNCTION_OBJECT_1(call_function, function_name)   __FUNCTION_OBJECT_15_2(call_function, function_name)

#define __FUNCTION_OBJECT_16_16(call_function, function_name)   __FUNCTION_OBJECT_16(call_function, function_name)
#define __FUNCTION_OBJECT_16_15(call_function, function_name)   \
            __FUNCTION_OBJECT_15(call_function, function_name)  __FUNCTION_OBJECT_16_16(call_function, function_name)
#define __FUNCTION_OBJECT_16_14(call_function, function_name)   \
            __FUNCTION_OBJECT_14(call_function, function_name)  __FUNCTION_OBJECT_16_15(call_function, function_name)
#define __FUNCTION_OBJECT_16_13(call_function, function_name)   \
            __FUNCTION_OBJECT_13(call_function, function_name)  __FUNCTION_OBJECT_16_14(call_function, function_name)
#define __FUNCTION_OBJECT_16_12(call_function, function_name)   \
            __FUNCTION_OBJECT_12(call_function, function_name)  __FUNCTION_OBJECT_16_13(call_function, function_name)
#define __FUNCTION_OBJECT_16_11(call_function, function_name)   \
            __FUNCTION_OBJECT_11(call_function, function_name)  __FUNCTION_OBJECT_16_12(call_function, function_name)
#define __FUNCTION_OBJECT_16_10(call_function, function_name)   \
            __FUNCTION_OBJECT_10(call_function, function_name)  __FUNCTION_OBJECT_16_11(call_function, function_name)
#define __FUNCTION_OBJECT_16_9(call_function, function_name)    \
            __FUNCTION_OBJECT_9(call_function, function_name)   __FUNCTION_OBJECT_16_10(call_function, function_name)
#define __FUNCTION_OBJECT_16_8(call_function, function_name)    \
            __FUNCTION_OBJECT_8(call_function, function_name)   __FUNCTION_OBJECT_16_9(call_function, function_name)
#define __FUNCTION_OBJECT_16_7(call_function, function_name)    \
            __FUNCTION_OBJECT_7(call_function, function_name)   __FUNCTION_OBJECT_16_8(call_function, function_name)
#define __FUNCTION_OBJECT_16_6(call_function, function_name)    \
            __FUNCTION_OBJECT_6(call_function, function_name)   __FUNCTION_OBJECT_16_7(call_function, function_name)
#define __FUNCTION_OBJECT_16_5(call_function, function_name)    \
            __FUNCTION_OBJECT_5(call_function, function_name)   __FUNCTION_OBJECT_16_6(call_function, function_name)
#define __FUNCTION_OBJECT_16_4(call_function, function_name)    \
            __FUNCTION_OBJECT_4(call_function, function_name)   __FUNCTION_OBJECT_16_5(call_function, function_name)
#define __FUNCTION_OBJECT_16_3(call_function, function_name)    \
            __FUNCTION_OBJECT_3(call_function, function_name)   __FUNCTION_OBJECT_16_4(call_function, function_name)
#define __FUNCTION_OBJECT_16_2(call_function, function_name)    \
            __FUNCTION_OBJECT_2(call_function, function_name)   __FUNCTION_OBJECT_16_3(call_function, function_name)
#define __FUNCTION_OBJECT_16_1(call_function, function_name)    \
            __FUNCTION_OBJECT_1(call_function, function_name)   __FUNCTION_OBJECT_16_2(call_function, function_name)

#define __FUNCTION_OBJECT_17_17(call_function, function_name)   __FUNCTION_OBJECT_17(call_function, function_name)
#define __FUNCTION_OBJECT_17_16(call_function, function_name)   \
            __FUNCTION_OBJECT_16(call_function, function_name)  __FUNCTION_OBJECT_17_17(call_function, function_name)
#define __FUNCTION_OBJECT_17_15(call_function, function_name)   \
            __FUNCTION_OBJECT_15(call_function, function_name)  __FUNCTION_OBJECT_17_16(call_function, function_name)
#define __FUNCTION_OBJECT_17_14(call_function, function_name)   \
            __FUNCTION_OBJECT_14(call_function, function_name)  __FUNCTION_OBJECT_17_15(call_function, function_name)
#define __FUNCTION_OBJECT_17_13(call_function, function_name)   \
            __FUNCTION_OBJECT_13(call_function, function_name)  __FUNCTION_OBJECT_17_14(call_function, function_name)
#define __FUNCTION_OBJECT_17_12(call_function, function_name)   \
            __FUNCTION_OBJECT_12(call_function, function_name)  __FUNCTION_OBJECT_17_13(call_function, function_name)
#define __FUNCTION_OBJECT_17_11(call_function, function_name)   \
            __FUNCTION_OBJECT_11(call_function, function_name)  __FUNCTION_OBJECT_17_12(call_function, function_name)
#define __FUNCTION_OBJECT_17_10(call_function, function_name)   \
            __FUNCTION_OBJECT_10(call_function, function_name)  __FUNCTION_OBJECT_17_11(call_function, function_name)
#define __FUNCTION_OBJECT_17_9(call_function, function_name)    \
            __FUNCTION_OBJECT_9(call_function, function_name)   __FUNCTION_OBJECT_17_10(call_function, function_name)
#define __FUNCTION_OBJECT_17_8(call_function, function_name)    \
            __FUNCTION_OBJECT_8(call_function, function_name)   __FUNCTION_OBJECT_17_9(call_function, function_name)
#define __FUNCTION_OBJECT_17_7(call_function, function_name)    \
            __FUNCTION_OBJECT_7(call_function, function_name)   __FUNCTION_OBJECT_17_8(call_function, function_name)
#define __FUNCTION_OBJECT_17_6(call_function, function_name)    \
            __FUNCTION_OBJECT_6(call_function, function_name)   __FUNCTION_OBJECT_17_7(call_function, function_name)
#define __FUNCTION_OBJECT_17_5(call_function, function_name)    \
            __FUNCTION_OBJECT_5(call_function, function_name)   __FUNCTION_OBJECT_17_6(call_function, function_name)
#define __FUNCTION_OBJECT_17_4(call_function, function_name)    \
            __FUNCTION_OBJECT_4(call_function, function_name)   __FUNCTION_OBJECT_17_5(call_function, function_name)
#define __FUNCTION_OBJECT_17_3(call_function, function_name)    \
            __FUNCTION_OBJECT_3(call_function, function_name)   __FUNCTION_OBJECT_17_4(call_function, function_name)
#define __FUNCTION_OBJECT_17_2(call_function, function_name)    \
            __FUNCTION_OBJECT_2(call_function, function_name)   __FUNCTION_OBJECT_17_3(call_function, function_name)
#define __FUNCTION_OBJECT_17_1(call_function, function_name)    \
            __FUNCTION_OBJECT_1(call_function, function_name)   __FUNCTION_OBJECT_17_2(call_function, function_name)

#define __FUNCTION_OBJECT_18_18(call_function, function_name)   __FUNCTION_OBJECT_18(call_function, function_name)
#define __FUNCTION_OBJECT_18_17(call_function, function_name)   \
            __FUNCTION_OBJECT_17(call_function, function_name)  __FUNCTION_OBJECT_18_18(call_function, function_name)
#define __FUNCTION_OBJECT_18_16(call_function, function_name)   \
            __FUNCTION_OBJECT_16(call_function, function_name)  __FUNCTION_OBJECT_18_17(call_function, function_name)
#define __FUNCTION_OBJECT_18_15(call_function, function_name)   \
            __FUNCTION_OBJECT_15(call_function, function_name)  __FUNCTION_OBJECT_18_16(call_function, function_name)
#define __FUNCTION_OBJECT_18_14(call_function, function_name)   \
            __FUNCTION_OBJECT_14(call_function, function_name)  __FUNCTION_OBJECT_18_15(call_function, function_name)
#define __FUNCTION_OBJECT_18_13(call_function, function_name)   \
            __FUNCTION_OBJECT_13(call_function, function_name)  __FUNCTION_OBJECT_18_14(call_function, function_name)
#define __FUNCTION_OBJECT_18_12(call_function, function_name)   \
            __FUNCTION_OBJECT_12(call_function, function_name)  __FUNCTION_OBJECT_18_13(call_function, function_name)
#define __FUNCTION_OBJECT_18_11(call_function, function_name)   \
            __FUNCTION_OBJECT_11(call_function, function_name)  __FUNCTION_OBJECT_18_12(call_function, function_name)
#define __FUNCTION_OBJECT_18_10(call_function, function_name)   \
            __FUNCTION_OBJECT_10(call_function, function_name)  __FUNCTION_OBJECT_18_11(call_function, function_name)
#define __FUNCTION_OBJECT_18_9(call_function, function_name)    \
            __FUNCTION_OBJECT_9(call_function, function_name)   __FUNCTION_OBJECT_18_10(call_function, function_name)
#define __FUNCTION_OBJECT_18_8(call_function, function_name)    \
            __FUNCTION_OBJECT_8(call_function, function_name)   __FUNCTION_OBJECT_18_9(call_function, function_name)
#define __FUNCTION_OBJECT_18_7(call_function, function_name)    \
            __FUNCTION_OBJECT_7(call_function, function_name)   __FUNCTION_OBJECT_18_8(call_function, function_name)
#define __FUNCTION_OBJECT_18_6(call_function, function_name)    \
            __FUNCTION_OBJECT_6(call_function, function_name)   __FUNCTION_OBJECT_18_7(call_function, function_name)
#define __FUNCTION_OBJECT_18_5(call_function, function_name)    \
            __FUNCTION_OBJECT_5(call_function, function_name)   __FUNCTION_OBJECT_18_6(call_function, function_name)
#define __FUNCTION_OBJECT_18_4(call_function, function_name)    \
            __FUNCTION_OBJECT_4(call_function, function_name)   __FUNCTION_OBJECT_18_5(call_function, function_name)
#define __FUNCTION_OBJECT_18_3(call_function, function_name)    \
            __FUNCTION_OBJECT_3(call_function, function_name)   __FUNCTION_OBJECT_18_4(call_function, function_name)
#define __FUNCTION_OBJECT_18_2(call_function, function_name)    \
            __FUNCTION_OBJECT_2(call_function, function_name)   __FUNCTION_OBJECT_18_3(call_function, function_name)
#define __FUNCTION_OBJECT_18_1(call_function, function_name)    \
            __FUNCTION_OBJECT_1(call_function, function_name)   __FUNCTION_OBJECT_18_2(call_function, function_name)

#define __FUNCTION_OBJECT_19_19(call_function, function_name)   __FUNCTION_OBJECT_19(call_function, function_name)
#define __FUNCTION_OBJECT_19_18(call_function, function_name)   \
            __FUNCTION_OBJECT_18(call_function, function_name)  __FUNCTION_OBJECT_19_19(call_function, function_name)
#define __FUNCTION_OBJECT_19_17(call_function, function_name)   \
            __FUNCTION_OBJECT_17(call_function, function_name)  __FUNCTION_OBJECT_19_18(call_function, function_name)
#define __FUNCTION_OBJECT_19_16(call_function, function_name)   \
            __FUNCTION_OBJECT_16(call_function, function_name)  __FUNCTION_OBJECT_19_17(call_function, function_name)
#define __FUNCTION_OBJECT_19_15(call_function, function_name)   \
            __FUNCTION_OBJECT_15(call_function, function_name)  __FUNCTION_OBJECT_19_16(call_function, function_name)
#define __FUNCTION_OBJECT_19_14(call_function, function_name)   \
            __FUNCTION_OBJECT_14(call_function, function_name)  __FUNCTION_OBJECT_19_15(call_function, function_name)
#define __FUNCTION_OBJECT_19_13(call_function, function_name)   \
            __FUNCTION_OBJECT_13(call_function, function_name)  __FUNCTION_OBJECT_19_14(call_function, function_name)
#define __FUNCTION_OBJECT_19_12(call_function, function_name)   \
            __FUNCTION_OBJECT_12(call_function, function_name)  __FUNCTION_OBJECT_19_13(call_function, function_name)
#define __FUNCTION_OBJECT_19_11(call_function, function_name)   \
            __FUNCTION_OBJECT_11(call_function, function_name)  __FUNCTION_OBJECT_19_12(call_function, function_name)
#define __FUNCTION_OBJECT_19_10(call_function, function_name)   \
            __FUNCTION_OBJECT_10(call_function, function_name)  __FUNCTION_OBJECT_19_11(call_function, function_name)
#define __FUNCTION_OBJECT_19_9(call_function, function_name)    \
            __FUNCTION_OBJECT_9(call_function, function_name)   __FUNCTION_OBJECT_19_10(call_function, function_name)
#define __FUNCTION_OBJECT_19_8(call_function, function_name)    \
            __FUNCTION_OBJECT_8(call_function, function_name)   __FUNCTION_OBJECT_19_9(call_function, function_name)
#define __FUNCTION_OBJECT_19_7(call_function, function_name)    \
            __FUNCTION_OBJECT_7(call_function, function_name)   __FUNCTION_OBJECT_19_8(call_function, function_name)
#define __FUNCTION_OBJECT_19_6(call_function, function_name)    \
            __FUNCTION_OBJECT_6(call_function, function_name)   __FUNCTION_OBJECT_19_7(call_function, function_name)
#define __FUNCTION_OBJECT_19_5(call_function, function_name)    \
            __FUNCTION_OBJECT_5(call_function, function_name)   __FUNCTION_OBJECT_19_6(call_function, function_name)
#define __FUNCTION_OBJECT_19_4(call_function, function_name)    \
            __FUNCTION_OBJECT_4(call_function, function_name)   __FUNCTION_OBJECT_19_5(call_function, function_name)
#define __FUNCTION_OBJECT_19_3(call_function, function_name)    \
            __FUNCTION_OBJECT_3(call_function, function_name)   __FUNCTION_OBJECT_19_4(call_function, function_name)
#define __FUNCTION_OBJECT_19_2(call_function, function_name)    \
            __FUNCTION_OBJECT_2(call_function, function_name)   __FUNCTION_OBJECT_19_3(call_function, function_name)
#define __FUNCTION_OBJECT_19_1(call_function, function_name)    \
            __FUNCTION_OBJECT_1(call_function, function_name)   __FUNCTION_OBJECT_19_2(call_function, function_name)

#define __FUNCTION_OBJECT_20_20(call_function, function_name)   __FUNCTION_OBJECT_20(call_function, function_name)
#define __FUNCTION_OBJECT_20_19(call_function, function_name)   \
            __FUNCTION_OBJECT_19(call_function, function_name)  __FUNCTION_OBJECT_20_20(call_function, function_name)
#define __FUNCTION_OBJECT_20_18(call_function, function_name)   \
            __FUNCTION_OBJECT_18(call_function, function_name)  __FUNCTION_OBJECT_20_19(call_function, function_name)
#define __FUNCTION_OBJECT_20_17(call_function, function_name)   \
            __FUNCTION_OBJECT_17(call_function, function_name)  __FUNCTION_OBJECT_20_18(call_function, function_name)
#define __FUNCTION_OBJECT_20_16(call_function, function_name)   \
            __FUNCTION_OBJECT_16(call_function, function_name)  __FUNCTION_OBJECT_20_17(call_function, function_name)
#define __FUNCTION_OBJECT_20_15(call_function, function_name)   \
            __FUNCTION_OBJECT_15(call_function, function_name)  __FUNCTION_OBJECT_20_16(call_function, function_name)
#define __FUNCTION_OBJECT_20_14(call_function, function_name)   \
            __FUNCTION_OBJECT_14(call_function, function_name)  __FUNCTION_OBJECT_20_15(call_function, function_name)
#define __FUNCTION_OBJECT_20_13(call_function, function_name)   \
            __FUNCTION_OBJECT_13(call_function, function_name)  __FUNCTION_OBJECT_20_14(call_function, function_name)
#define __FUNCTION_OBJECT_20_12(call_function, function_name)   \
            __FUNCTION_OBJECT_12(call_function, function_name)  __FUNCTION_OBJECT_20_13(call_function, function_name)
#define __FUNCTION_OBJECT_20_11(call_function, function_name)   \
            __FUNCTION_OBJECT_11(call_function, function_name)  __FUNCTION_OBJECT_20_12(call_function, function_name)
#define __FUNCTION_OBJECT_20_10(call_function, function_name)   \
            __FUNCTION_OBJECT_10(call_function, function_name)  __FUNCTION_OBJECT_20_11(call_function, function_name)
#define __FUNCTION_OBJECT_20_9(call_function, function_name)    \
            __FUNCTION_OBJECT_9(call_function, function_name)   __FUNCTION_OBJECT_20_10(call_function, function_name)
#define __FUNCTION_OBJECT_20_8(call_function, function_name)    \
            __FUNCTION_OBJECT_8(call_function, function_name)   __FUNCTION_OBJECT_20_9(call_function, function_name)
#define __FUNCTION_OBJECT_20_7(call_function, function_name)    \
            __FUNCTION_OBJECT_7(call_function, function_name)   __FUNCTION_OBJECT_20_8(call_function, function_name)
#define __FUNCTION_OBJECT_20_6(call_function, function_name)    \
            __FUNCTION_OBJECT_6(call_function, function_name)   __FUNCTION_OBJECT_20_7(call_function, function_name)
#define __FUNCTION_OBJECT_20_5(call_function, function_name)    \
            __FUNCTION_OBJECT_5(call_function, function_name)   __FUNCTION_OBJECT_20_6(call_function, function_name)
#define __FUNCTION_OBJECT_20_4(call_function, function_name)    \
            __FUNCTION_OBJECT_4(call_function, function_name)   __FUNCTION_OBJECT_20_5(call_function, function_name)
#define __FUNCTION_OBJECT_20_3(call_function, function_name)    \
            __FUNCTION_OBJECT_3(call_function, function_name)   __FUNCTION_OBJECT_20_4(call_function, function_name)
#define __FUNCTION_OBJECT_20_2(call_function, function_name)    \
            __FUNCTION_OBJECT_2(call_function, function_name)   __FUNCTION_OBJECT_20_3(call_function, function_name)
#define __FUNCTION_OBJECT_20_1(call_function, function_name)    \
            __FUNCTION_OBJECT_1(call_function, function_name)   __FUNCTION_OBJECT_20_2(call_function, function_name)

#define __FUNCTION_OBJECT_21_21(call_function, function_name)   __FUNCTION_OBJECT_21(call_function, function_name)
#define __FUNCTION_OBJECT_21_20(call_function, function_name)   \
            __FUNCTION_OBJECT_20(call_function, function_name)  __FUNCTION_OBJECT_21_21(call_function, function_name)
#define __FUNCTION_OBJECT_21_19(call_function, function_name)   \
            __FUNCTION_OBJECT_19(call_function, function_name)  __FUNCTION_OBJECT_21_20(call_function, function_name)
#define __FUNCTION_OBJECT_21_18(call_function, function_name)   \
            __FUNCTION_OBJECT_18(call_function, function_name)  __FUNCTION_OBJECT_21_19(call_function, function_name)
#define __FUNCTION_OBJECT_21_17(call_function, function_name)   \
            __FUNCTION_OBJECT_17(call_function, function_name)  __FUNCTION_OBJECT_21_18(call_function, function_name)
#define __FUNCTION_OBJECT_21_16(call_function, function_name)   \
            __FUNCTION_OBJECT_16(call_function, function_name)  __FUNCTION_OBJECT_21_17(call_function, function_name)
#define __FUNCTION_OBJECT_21_15(call_function, function_name)   \
            __FUNCTION_OBJECT_15(call_function, function_name)  __FUNCTION_OBJECT_21_16(call_function, function_name)
#define __FUNCTION_OBJECT_21_14(call_function, function_name)   \
            __FUNCTION_OBJECT_14(call_function, function_name)  __FUNCTION_OBJECT_21_15(call_function, function_name)
#define __FUNCTION_OBJECT_21_13(call_function, function_name)   \
            __FUNCTION_OBJECT_13(call_function, function_name)  __FUNCTION_OBJECT_21_14(call_function, function_name)
#define __FUNCTION_OBJECT_21_12(call_function, function_name)   \
            __FUNCTION_OBJECT_12(call_function, function_name)  __FUNCTION_OBJECT_21_13(call_function, function_name)
#define __FUNCTION_OBJECT_21_11(call_function, function_name)   \
            __FUNCTION_OBJECT_11(call_function, function_name)  __FUNCTION_OBJECT_21_12(call_function, function_name)
#define __FUNCTION_OBJECT_21_10(call_function, function_name)   \
            __FUNCTION_OBJECT_10(call_function, function_name)  __FUNCTION_OBJECT_21_11(call_function, function_name)
#define __FUNCTION_OBJECT_21_9(call_function, function_name)    \
            __FUNCTION_OBJECT_9(call_function, function_name)   __FUNCTION_OBJECT_21_10(call_function, function_name)
#define __FUNCTION_OBJECT_21_8(call_function, function_name)    \
            __FUNCTION_OBJECT_8(call_function, function_name)   __FUNCTION_OBJECT_21_9(call_function, function_name)
#define __FUNCTION_OBJECT_21_7(call_function, function_name)    \
            __FUNCTION_OBJECT_7(call_function, function_name)   __FUNCTION_OBJECT_21_8(call_function, function_name)
#define __FUNCTION_OBJECT_21_6(call_function, function_name)    \
            __FUNCTION_OBJECT_6(call_function, function_name)   __FUNCTION_OBJECT_21_7(call_function, function_name)
#define __FUNCTION_OBJECT_21_5(call_function, function_name)    \
            __FUNCTION_OBJECT_5(call_function, function_name)   __FUNCTION_OBJECT_21_6(call_function, function_name)
#define __FUNCTION_OBJECT_21_4(call_function, function_name)    \
            __FUNCTION_OBJECT_4(call_function, function_name)   __FUNCTION_OBJECT_21_5(call_function, function_name)
#define __FUNCTION_OBJECT_21_3(call_function, function_name)    \
            __FUNCTION_OBJECT_3(call_function, function_name)   __FUNCTION_OBJECT_21_4(call_function, function_name)
#define __FUNCTION_OBJECT_21_2(call_function, function_name)    \
            __FUNCTION_OBJECT_2(call_function, function_name)   __FUNCTION_OBJECT_21_3(call_function, function_name)
#define __FUNCTION_OBJECT_21_1(call_function, function_name)    \
            __FUNCTION_OBJECT_1(call_function, function_name)   __FUNCTION_OBJECT_21_2(call_function, function_name)

#define __FUNCTION_OBJECT_22_22(call_function, function_name)   __FUNCTION_OBJECT_22(call_function, function_name)
#define __FUNCTION_OBJECT_22_21(call_function, function_name)   \
            __FUNCTION_OBJECT_21(call_function, function_name)  __FUNCTION_OBJECT_22_22(call_function, function_name)
#define __FUNCTION_OBJECT_22_20(call_function, function_name)   \
            __FUNCTION_OBJECT_20(call_function, function_name)  __FUNCTION_OBJECT_22_21(call_function, function_name)
#define __FUNCTION_OBJECT_22_19(call_function, function_name)   \
            __FUNCTION_OBJECT_19(call_function, function_name)  __FUNCTION_OBJECT_22_20(call_function, function_name)
#define __FUNCTION_OBJECT_22_18(call_function, function_name)   \
            __FUNCTION_OBJECT_18(call_function, function_name)  __FUNCTION_OBJECT_22_19(call_function, function_name)
#define __FUNCTION_OBJECT_22_17(call_function, function_name)   \
            __FUNCTION_OBJECT_17(call_function, function_name)  __FUNCTION_OBJECT_22_18(call_function, function_name)
#define __FUNCTION_OBJECT_22_16(call_function, function_name)   \
            __FUNCTION_OBJECT_16(call_function, function_name)  __FUNCTION_OBJECT_22_17(call_function, function_name)
#define __FUNCTION_OBJECT_22_15(call_function, function_name)   \
            __FUNCTION_OBJECT_15(call_function, function_name)  __FUNCTION_OBJECT_22_16(call_function, function_name)
#define __FUNCTION_OBJECT_22_14(call_function, function_name)   \
            __FUNCTION_OBJECT_14(call_function, function_name)  __FUNCTION_OBJECT_22_15(call_function, function_name)
#define __FUNCTION_OBJECT_22_13(call_function, function_name)   \
            __FUNCTION_OBJECT_13(call_function, function_name)  __FUNCTION_OBJECT_22_14(call_function, function_name)
#define __FUNCTION_OBJECT_22_12(call_function, function_name)   \
            __FUNCTION_OBJECT_12(call_function, function_name)  __FUNCTION_OBJECT_22_13(call_function, function_name)
#define __FUNCTION_OBJECT_22_11(call_function, function_name)   \
            __FUNCTION_OBJECT_11(call_function, function_name)  __FUNCTION_OBJECT_22_12(call_function, function_name)
#define __FUNCTION_OBJECT_22_10(call_function, function_name)   \
            __FUNCTION_OBJECT_10(call_function, function_name)  __FUNCTION_OBJECT_22_11(call_function, function_name)
#define __FUNCTION_OBJECT_22_9(call_function, function_name)    \
            __FUNCTION_OBJECT_9(call_function, function_name)   __FUNCTION_OBJECT_22_10(call_function, function_name)
#define __FUNCTION_OBJECT_22_8(call_function, function_name)    \
            __FUNCTION_OBJECT_8(call_function, function_name)   __FUNCTION_OBJECT_22_9(call_function, function_name)
#define __FUNCTION_OBJECT_22_7(call_function, function_name)    \
            __FUNCTION_OBJECT_7(call_function, function_name)   __FUNCTION_OBJECT_22_8(call_function, function_name)
#define __FUNCTION_OBJECT_22_6(call_function, function_name)    \
            __FUNCTION_OBJECT_6(call_function, function_name)   __FUNCTION_OBJECT_22_7(call_function, function_name)
#define __FUNCTION_OBJECT_22_5(call_function, function_name)    \
            __FUNCTION_OBJECT_5(call_function, function_name)   __FUNCTION_OBJECT_22_6(call_function, function_name)
#define __FUNCTION_OBJECT_22_4(call_function, function_name)    \
            __FUNCTION_OBJECT_4(call_function, function_name)   __FUNCTION_OBJECT_22_5(call_function, function_name)
#define __FUNCTION_OBJECT_22_3(call_function, function_name)    \
            __FUNCTION_OBJECT_3(call_function, function_name)   __FUNCTION_OBJECT_22_4(call_function, function_name)
#define __FUNCTION_OBJECT_22_2(call_function, function_name)    \
            __FUNCTION_OBJECT_2(call_function, function_name)   __FUNCTION_OBJECT_22_3(call_function, function_name)
#define __FUNCTION_OBJECT_22_1(call_function, function_name)    \
            __FUNCTION_OBJECT_1(call_function, function_name)   __FUNCTION_OBJECT_22_2(call_function, function_name)

#define __FUNCTION_OBJECT_23_23(call_function, function_name)   __FUNCTION_OBJECT_23(call_function, function_name)
#define __FUNCTION_OBJECT_23_22(call_function, function_name)   \
            __FUNCTION_OBJECT_22(call_function, function_name)  __FUNCTION_OBJECT_23_23(call_function, function_name)
#define __FUNCTION_OBJECT_23_21(call_function, function_name)   \
            __FUNCTION_OBJECT_21(call_function, function_name)  __FUNCTION_OBJECT_23_22(call_function, function_name)
#define __FUNCTION_OBJECT_23_20(call_function, function_name)   \
            __FUNCTION_OBJECT_20(call_function, function_name)  __FUNCTION_OBJECT_23_21(call_function, function_name)
#define __FUNCTION_OBJECT_23_19(call_function, function_name)   \
            __FUNCTION_OBJECT_19(call_function, function_name)  __FUNCTION_OBJECT_23_20(call_function, function_name)
#define __FUNCTION_OBJECT_23_18(call_function, function_name)   \
            __FUNCTION_OBJECT_18(call_function, function_name)  __FUNCTION_OBJECT_23_19(call_function, function_name)
#define __FUNCTION_OBJECT_23_17(call_function, function_name)   \
            __FUNCTION_OBJECT_17(call_function, function_name)  __FUNCTION_OBJECT_23_18(call_function, function_name)
#define __FUNCTION_OBJECT_23_16(call_function, function_name)   \
            __FUNCTION_OBJECT_16(call_function, function_name)  __FUNCTION_OBJECT_23_17(call_function, function_name)
#define __FUNCTION_OBJECT_23_15(call_function, function_name)   \
            __FUNCTION_OBJECT_15(call_function, function_name)  __FUNCTION_OBJECT_23_16(call_function, function_name)
#define __FUNCTION_OBJECT_23_14(call_function, function_name)   \
            __FUNCTION_OBJECT_14(call_function, function_name)  __FUNCTION_OBJECT_23_15(call_function, function_name)
#define __FUNCTION_OBJECT_23_13(call_function, function_name)   \
            __FUNCTION_OBJECT_13(call_function, function_name)  __FUNCTION_OBJECT_23_14(call_function, function_name)
#define __FUNCTION_OBJECT_23_12(call_function, function_name)   \
            __FUNCTION_OBJECT_12(call_function, function_name)  __FUNCTION_OBJECT_23_13(call_function, function_name)
#define __FUNCTION_OBJECT_23_11(call_function, function_name)   \
            __FUNCTION_OBJECT_11(call_function, function_name)  __FUNCTION_OBJECT_23_12(call_function, function_name)
#define __FUNCTION_OBJECT_23_10(call_function, function_name)   \
            __FUNCTION_OBJECT_10(call_function, function_name)  __FUNCTION_OBJECT_23_11(call_function, function_name)
#define __FUNCTION_OBJECT_23_9(call_function, function_name)    \
            __FUNCTION_OBJECT_9(call_function, function_name)   __FUNCTION_OBJECT_23_10(call_function, function_name)
#define __FUNCTION_OBJECT_23_8(call_function, function_name)    \
            __FUNCTION_OBJECT_8(call_function, function_name)   __FUNCTION_OBJECT_23_9(call_function, function_name)
#define __FUNCTION_OBJECT_23_7(call_function, function_name)    \
            __FUNCTION_OBJECT_7(call_function, function_name)   __FUNCTION_OBJECT_23_8(call_function, function_name)
#define __FUNCTION_OBJECT_23_6(call_function, function_name)    \
            __FUNCTION_OBJECT_6(call_function, function_name)   __FUNCTION_OBJECT_23_7(call_function, function_name)
#define __FUNCTION_OBJECT_23_5(call_function, function_name)    \
            __FUNCTION_OBJECT_5(call_function, function_name)   __FUNCTION_OBJECT_23_6(call_function, function_name)
#define __FUNCTION_OBJECT_23_4(call_function, function_name)    \
            __FUNCTION_OBJECT_4(call_function, function_name)   __FUNCTION_OBJECT_23_5(call_function, function_name)
#define __FUNCTION_OBJECT_23_3(call_function, function_name)    \
            __FUNCTION_OBJECT_3(call_function, function_name)   __FUNCTION_OBJECT_23_4(call_function, function_name)
#define __FUNCTION_OBJECT_23_2(call_function, function_name)    \
            __FUNCTION_OBJECT_2(call_function, function_name)   __FUNCTION_OBJECT_23_3(call_function, function_name)
#define __FUNCTION_OBJECT_23_1(call_function, function_name)    \
            __FUNCTION_OBJECT_1(call_function, function_name)   __FUNCTION_OBJECT_23_2(call_function, function_name)

#define __FUNCTION_OBJECT_24_24(call_function, function_name)   __FUNCTION_OBJECT_24(call_function, function_name)
#define __FUNCTION_OBJECT_24_23(call_function, function_name)   \
            __FUNCTION_OBJECT_23(call_function, function_name)  __FUNCTION_OBJECT_24_24(call_function, function_name)
#define __FUNCTION_OBJECT_24_22(call_function, function_name)   \
            __FUNCTION_OBJECT_22(call_function, function_name)  __FUNCTION_OBJECT_24_23(call_function, function_name)
#define __FUNCTION_OBJECT_24_21(call_function, function_name)   \
            __FUNCTION_OBJECT_21(call_function, function_name)  __FUNCTION_OBJECT_24_22(call_function, function_name)
#define __FUNCTION_OBJECT_24_20(call_function, function_name)   \
            __FUNCTION_OBJECT_20(call_function, function_name)  __FUNCTION_OBJECT_24_21(call_function, function_name)
#define __FUNCTION_OBJECT_24_19(call_function, function_name)   \
            __FUNCTION_OBJECT_19(call_function, function_name)  __FUNCTION_OBJECT_24_20(call_function, function_name)
#define __FUNCTION_OBJECT_24_18(call_function, function_name)   \
            __FUNCTION_OBJECT_18(call_function, function_name)  __FUNCTION_OBJECT_24_19(call_function, function_name)
#define __FUNCTION_OBJECT_24_17(call_function, function_name)   \
            __FUNCTION_OBJECT_17(call_function, function_name)  __FUNCTION_OBJECT_24_18(call_function, function_name)
#define __FUNCTION_OBJECT_24_16(call_function, function_name)   \
            __FUNCTION_OBJECT_16(call_function, function_name)  __FUNCTION_OBJECT_24_17(call_function, function_name)
#define __FUNCTION_OBJECT_24_15(call_function, function_name)   \
            __FUNCTION_OBJECT_15(call_function, function_name)  __FUNCTION_OBJECT_24_16(call_function, function_name)
#define __FUNCTION_OBJECT_24_14(call_function, function_name)   \
            __FUNCTION_OBJECT_14(call_function, function_name)  __FUNCTION_OBJECT_24_15(call_function, function_name)
#define __FUNCTION_OBJECT_24_13(call_function, function_name)   \
            __FUNCTION_OBJECT_13(call_function, function_name)  __FUNCTION_OBJECT_24_14(call_function, function_name)
#define __FUNCTION_OBJECT_24_12(call_function, function_name)   \
            __FUNCTION_OBJECT_12(call_function, function_name)  __FUNCTION_OBJECT_24_13(call_function, function_name)
#define __FUNCTION_OBJECT_24_11(call_function, function_name)   \
            __FUNCTION_OBJECT_11(call_function, function_name)  __FUNCTION_OBJECT_24_12(call_function, function_name)
#define __FUNCTION_OBJECT_24_10(call_function, function_name)   \
            __FUNCTION_OBJECT_10(call_function, function_name)  __FUNCTION_OBJECT_24_11(call_function, function_name)
#define __FUNCTION_OBJECT_24_9(call_function, function_name)    \
            __FUNCTION_OBJECT_9(call_function, function_name)   __FUNCTION_OBJECT_24_10(call_function, function_name)
#define __FUNCTION_OBJECT_24_8(call_function, function_name)    \
            __FUNCTION_OBJECT_8(call_function, function_name)   __FUNCTION_OBJECT_24_9(call_function, function_name)
#define __FUNCTION_OBJECT_24_7(call_function, function_name)    \
            __FUNCTION_OBJECT_7(call_function, function_name)   __FUNCTION_OBJECT_24_8(call_function, function_name)
#define __FUNCTION_OBJECT_24_6(call_function, function_name)    \
            __FUNCTION_OBJECT_6(call_function, function_name)   __FUNCTION_OBJECT_24_7(call_function, function_name)
#define __FUNCTION_OBJECT_24_5(call_function, function_name)    \
            __FUNCTION_OBJECT_5(call_function, function_name)   __FUNCTION_OBJECT_24_6(call_function, function_name)
#define __FUNCTION_OBJECT_24_4(call_function, function_name)    \
            __FUNCTION_OBJECT_4(call_function, function_name)   __FUNCTION_OBJECT_24_5(call_function, function_name)
#define __FUNCTION_OBJECT_24_3(call_function, function_name)    \
            __FUNCTION_OBJECT_3(call_function, function_name)   __FUNCTION_OBJECT_24_4(call_function, function_name)
#define __FUNCTION_OBJECT_24_2(call_function, function_name)    \
            __FUNCTION_OBJECT_2(call_function, function_name)   __FUNCTION_OBJECT_24_3(call_function, function_name)
#define __FUNCTION_OBJECT_24_1(call_function, function_name)    \
            __FUNCTION_OBJECT_1(call_function, function_name)   __FUNCTION_OBJECT_24_2(call_function, function_name)

#define __FUNCTION_OBJECT_25_25(call_function, function_name)   __FUNCTION_OBJECT_25(call_function, function_name)
#define __FUNCTION_OBJECT_25_24(call_function, function_name)   \
            __FUNCTION_OBJECT_24(call_function, function_name)  __FUNCTION_OBJECT_25_25(call_function, function_name)
#define __FUNCTION_OBJECT_25_23(call_function, function_name)   \
            __FUNCTION_OBJECT_23(call_function, function_name)  __FUNCTION_OBJECT_25_24(call_function, function_name)
#define __FUNCTION_OBJECT_25_22(call_function, function_name)   \
            __FUNCTION_OBJECT_22(call_function, function_name)  __FUNCTION_OBJECT_25_23(call_function, function_name)
#define __FUNCTION_OBJECT_25_21(call_function, function_name)   \
            __FUNCTION_OBJECT_21(call_function, function_name)  __FUNCTION_OBJECT_25_22(call_function, function_name)
#define __FUNCTION_OBJECT_25_20(call_function, function_name)   \
            __FUNCTION_OBJECT_20(call_function, function_name)  __FUNCTION_OBJECT_25_21(call_function, function_name)
#define __FUNCTION_OBJECT_25_19(call_function, function_name)   \
            __FUNCTION_OBJECT_19(call_function, function_name)  __FUNCTION_OBJECT_25_20(call_function, function_name)
#define __FUNCTION_OBJECT_25_18(call_function, function_name)   \
            __FUNCTION_OBJECT_18(call_function, function_name)  __FUNCTION_OBJECT_25_19(call_function, function_name)
#define __FUNCTION_OBJECT_25_17(call_function, function_name)   \
            __FUNCTION_OBJECT_17(call_function, function_name)  __FUNCTION_OBJECT_25_18(call_function, function_name)
#define __FUNCTION_OBJECT_25_16(call_function, function_name)   \
            __FUNCTION_OBJECT_16(call_function, function_name)  __FUNCTION_OBJECT_25_17(call_function, function_name)
#define __FUNCTION_OBJECT_25_15(call_function, function_name)   \
            __FUNCTION_OBJECT_15(call_function, function_name)  __FUNCTION_OBJECT_25_16(call_function, function_name)
#define __FUNCTION_OBJECT_25_14(call_function, function_name)   \
            __FUNCTION_OBJECT_14(call_function, function_name)  __FUNCTION_OBJECT_25_15(call_function, function_name)
#define __FUNCTION_OBJECT_25_13(call_function, function_name)   \
            __FUNCTION_OBJECT_13(call_function, function_name)  __FUNCTION_OBJECT_25_14(call_function, function_name)
#define __FUNCTION_OBJECT_25_12(call_function, function_name)   \
            __FUNCTION_OBJECT_12(call_function, function_name)  __FUNCTION_OBJECT_25_13(call_function, function_name)
#define __FUNCTION_OBJECT_25_11(call_function, function_name)   \
            __FUNCTION_OBJECT_11(call_function, function_name)  __FUNCTION_OBJECT_25_12(call_function, function_name)
#define __FUNCTION_OBJECT_25_10(call_function, function_name)   \
            __FUNCTION_OBJECT_10(call_function, function_name)  __FUNCTION_OBJECT_25_11(call_function, function_name)
#define __FUNCTION_OBJECT_25_9(call_function, function_name)    \
            __FUNCTION_OBJECT_9(call_function, function_name)   __FUNCTION_OBJECT_25_10(call_function, function_name)
#define __FUNCTION_OBJECT_25_8(call_function, function_name)    \
            __FUNCTION_OBJECT_8(call_function, function_name)   __FUNCTION_OBJECT_25_9(call_function, function_name)
#define __FUNCTION_OBJECT_25_7(call_function, function_name)    \
            __FUNCTION_OBJECT_7(call_function, function_name)   __FUNCTION_OBJECT_25_8(call_function, function_name)
#define __FUNCTION_OBJECT_25_6(call_function, function_name)    \
            __FUNCTION_OBJECT_6(call_function, function_name)   __FUNCTION_OBJECT_25_7(call_function, function_name)
#define __FUNCTION_OBJECT_25_5(call_function, function_name)    \
            __FUNCTION_OBJECT_5(call_function, function_name)   __FUNCTION_OBJECT_25_6(call_function, function_name)
#define __FUNCTION_OBJECT_25_4(call_function, function_name)    \
            __FUNCTION_OBJECT_4(call_function, function_name)   __FUNCTION_OBJECT_25_5(call_function, function_name)
#define __FUNCTION_OBJECT_25_3(call_function, function_name)    \
            __FUNCTION_OBJECT_3(call_function, function_name)   __FUNCTION_OBJECT_25_4(call_function, function_name)
#define __FUNCTION_OBJECT_25_2(call_function, function_name)    \
            __FUNCTION_OBJECT_2(call_function, function_name)   __FUNCTION_OBJECT_25_3(call_function, function_name)
#define __FUNCTION_OBJECT_25_1(call_function, function_name)    \
            __FUNCTION_OBJECT_1(call_function, function_name)   __FUNCTION_OBJECT_25_2(call_function, function_name)

#define __FUNCTION_OBJECT_26_26(call_function, function_name)   __FUNCTION_OBJECT_26(call_function, function_name)
#define __FUNCTION_OBJECT_26_25(call_function, function_name)   \
            __FUNCTION_OBJECT_25(call_function, function_name)  __FUNCTION_OBJECT_26_26(call_function, function_name)
#define __FUNCTION_OBJECT_26_24(call_function, function_name)   \
            __FUNCTION_OBJECT_24(call_function, function_name)  __FUNCTION_OBJECT_26_25(call_function, function_name)
#define __FUNCTION_OBJECT_26_23(call_function, function_name)   \
            __FUNCTION_OBJECT_23(call_function, function_name)  __FUNCTION_OBJECT_26_24(call_function, function_name)
#define __FUNCTION_OBJECT_26_22(call_function, function_name)   \
            __FUNCTION_OBJECT_22(call_function, function_name)  __FUNCTION_OBJECT_26_23(call_function, function_name)
#define __FUNCTION_OBJECT_26_21(call_function, function_name)   \
            __FUNCTION_OBJECT_21(call_function, function_name)  __FUNCTION_OBJECT_26_22(call_function, function_name)
#define __FUNCTION_OBJECT_26_20(call_function, function_name)   \
            __FUNCTION_OBJECT_20(call_function, function_name)  __FUNCTION_OBJECT_26_21(call_function, function_name)
#define __FUNCTION_OBJECT_26_19(call_function, function_name)   \
            __FUNCTION_OBJECT_19(call_function, function_name)  __FUNCTION_OBJECT_26_20(call_function, function_name)
#define __FUNCTION_OBJECT_26_18(call_function, function_name)   \
            __FUNCTION_OBJECT_18(call_function, function_name)  __FUNCTION_OBJECT_26_19(call_function, function_name)
#define __FUNCTION_OBJECT_26_17(call_function, function_name)   \
            __FUNCTION_OBJECT_17(call_function, function_name)  __FUNCTION_OBJECT_26_18(call_function, function_name)
#define __FUNCTION_OBJECT_26_16(call_function, function_name)   \
            __FUNCTION_OBJECT_16(call_function, function_name)  __FUNCTION_OBJECT_26_17(call_function, function_name)
#define __FUNCTION_OBJECT_26_15(call_function, function_name)   \
            __FUNCTION_OBJECT_15(call_function, function_name)  __FUNCTION_OBJECT_26_16(call_function, function_name)
#define __FUNCTION_OBJECT_26_14(call_function, function_name)   \
            __FUNCTION_OBJECT_14(call_function, function_name)  __FUNCTION_OBJECT_26_15(call_function, function_name)
#define __FUNCTION_OBJECT_26_13(call_function, function_name)   \
            __FUNCTION_OBJECT_13(call_function, function_name)  __FUNCTION_OBJECT_26_14(call_function, function_name)
#define __FUNCTION_OBJECT_26_12(call_function, function_name)   \
            __FUNCTION_OBJECT_12(call_function, function_name)  __FUNCTION_OBJECT_26_13(call_function, function_name)
#define __FUNCTION_OBJECT_26_11(call_function, function_name)   \
            __FUNCTION_OBJECT_11(call_function, function_name)  __FUNCTION_OBJECT_26_12(call_function, function_name)
#define __FUNCTION_OBJECT_26_10(call_function, function_name)   \
            __FUNCTION_OBJECT_10(call_function, function_name)  __FUNCTION_OBJECT_26_11(call_function, function_name)
#define __FUNCTION_OBJECT_26_9(call_function, function_name)    \
            __FUNCTION_OBJECT_9(call_function, function_name)   __FUNCTION_OBJECT_26_10(call_function, function_name)
#define __FUNCTION_OBJECT_26_8(call_function, function_name)    \
            __FUNCTION_OBJECT_8(call_function, function_name)   __FUNCTION_OBJECT_26_9(call_function, function_name)
#define __FUNCTION_OBJECT_26_7(call_function, function_name)    \
            __FUNCTION_OBJECT_7(call_function, function_name)   __FUNCTION_OBJECT_26_8(call_function, function_name)
#define __FUNCTION_OBJECT_26_6(call_function, function_name)    \
            __FUNCTION_OBJECT_6(call_function, function_name)   __FUNCTION_OBJECT_26_7(call_function, function_name)
#define __FUNCTION_OBJECT_26_5(call_function, function_name)    \
            __FUNCTION_OBJECT_5(call_function, function_name)   __FUNCTION_OBJECT_26_6(call_function, function_name)
#define __FUNCTION_OBJECT_26_4(call_function, function_name)    \
            __FUNCTION_OBJECT_4(call_function, function_name)   __FUNCTION_OBJECT_26_5(call_function, function_name)
#define __FUNCTION_OBJECT_26_3(call_function, function_name)    \
            __FUNCTION_OBJECT_3(call_function, function_name)   __FUNCTION_OBJECT_26_4(call_function, function_name)
#define __FUNCTION_OBJECT_26_2(call_function, function_name)    \
            __FUNCTION_OBJECT_2(call_function, function_name)   __FUNCTION_OBJECT_26_3(call_function, function_name)
#define __FUNCTION_OBJECT_26_1(call_function, function_name)    \
            __FUNCTION_OBJECT_1(call_function, function_name)   __FUNCTION_OBJECT_26_2(call_function, function_name)

#define __FUNCTION_OBJECT_27_27(call_function, function_name)   __FUNCTION_OBJECT_27(call_function, function_name)
#define __FUNCTION_OBJECT_27_26(call_function, function_name)   \
            __FUNCTION_OBJECT_26(call_function, function_name)  __FUNCTION_OBJECT_27_27(call_function, function_name)
#define __FUNCTION_OBJECT_27_25(call_function, function_name)   \
            __FUNCTION_OBJECT_25(call_function, function_name)  __FUNCTION_OBJECT_27_26(call_function, function_name)
#define __FUNCTION_OBJECT_27_24(call_function, function_name)   \
            __FUNCTION_OBJECT_24(call_function, function_name)  __FUNCTION_OBJECT_27_25(call_function, function_name)
#define __FUNCTION_OBJECT_27_23(call_function, function_name)   \
            __FUNCTION_OBJECT_23(call_function, function_name)  __FUNCTION_OBJECT_27_24(call_function, function_name)
#define __FUNCTION_OBJECT_27_22(call_function, function_name)   \
            __FUNCTION_OBJECT_22(call_function, function_name)  __FUNCTION_OBJECT_27_23(call_function, function_name)
#define __FUNCTION_OBJECT_27_21(call_function, function_name)   \
            __FUNCTION_OBJECT_21(call_function, function_name)  __FUNCTION_OBJECT_27_22(call_function, function_name)
#define __FUNCTION_OBJECT_27_20(call_function, function_name)   \
            __FUNCTION_OBJECT_20(call_function, function_name)  __FUNCTION_OBJECT_27_21(call_function, function_name)
#define __FUNCTION_OBJECT_27_19(call_function, function_name)   \
            __FUNCTION_OBJECT_19(call_function, function_name)  __FUNCTION_OBJECT_27_20(call_function, function_name)
#define __FUNCTION_OBJECT_27_18(call_function, function_name)   \
            __FUNCTION_OBJECT_18(call_function, function_name)  __FUNCTION_OBJECT_27_19(call_function, function_name)
#define __FUNCTION_OBJECT_27_17(call_function, function_name)   \
            __FUNCTION_OBJECT_17(call_function, function_name)  __FUNCTION_OBJECT_27_18(call_function, function_name)
#define __FUNCTION_OBJECT_27_16(call_function, function_name)   \
            __FUNCTION_OBJECT_16(call_function, function_name)  __FUNCTION_OBJECT_27_17(call_function, function_name)
#define __FUNCTION_OBJECT_27_15(call_function, function_name)   \
            __FUNCTION_OBJECT_15(call_function, function_name)  __FUNCTION_OBJECT_27_16(call_function, function_name)
#define __FUNCTION_OBJECT_27_14(call_function, function_name)   \
            __FUNCTION_OBJECT_14(call_function, function_name)  __FUNCTION_OBJECT_27_15(call_function, function_name)
#define __FUNCTION_OBJECT_27_13(call_function, function_name)   \
            __FUNCTION_OBJECT_13(call_function, function_name)  __FUNCTION_OBJECT_27_14(call_function, function_name)
#define __FUNCTION_OBJECT_27_12(call_function, function_name)   \
            __FUNCTION_OBJECT_12(call_function, function_name)  __FUNCTION_OBJECT_27_13(call_function, function_name)
#define __FUNCTION_OBJECT_27_11(call_function, function_name)   \
            __FUNCTION_OBJECT_11(call_function, function_name)  __FUNCTION_OBJECT_27_12(call_function, function_name)
#define __FUNCTION_OBJECT_27_10(call_function, function_name)   \
            __FUNCTION_OBJECT_10(call_function, function_name)  __FUNCTION_OBJECT_27_11(call_function, function_name)
#define __FUNCTION_OBJECT_27_9(call_function, function_name)    \
            __FUNCTION_OBJECT_9(call_function, function_name)   __FUNCTION_OBJECT_27_10(call_function, function_name)
#define __FUNCTION_OBJECT_27_8(call_function, function_name)    \
            __FUNCTION_OBJECT_8(call_function, function_name)   __FUNCTION_OBJECT_27_9(call_function, function_name)
#define __FUNCTION_OBJECT_27_7(call_function, function_name)    \
            __FUNCTION_OBJECT_7(call_function, function_name)   __FUNCTION_OBJECT_27_8(call_function, function_name)
#define __FUNCTION_OBJECT_27_6(call_function, function_name)    \
            __FUNCTION_OBJECT_6(call_function, function_name)   __FUNCTION_OBJECT_27_7(call_function, function_name)
#define __FUNCTION_OBJECT_27_5(call_function, function_name)    \
            __FUNCTION_OBJECT_5(call_function, function_name)   __FUNCTION_OBJECT_27_6(call_function, function_name)
#define __FUNCTION_OBJECT_27_4(call_function, function_name)    \
            __FUNCTION_OBJECT_4(call_function, function_name)   __FUNCTION_OBJECT_27_5(call_function, function_name)
#define __FUNCTION_OBJECT_27_3(call_function, function_name)    \
            __FUNCTION_OBJECT_3(call_function, function_name)   __FUNCTION_OBJECT_27_4(call_function, function_name)
#define __FUNCTION_OBJECT_27_2(call_function, function_name)    \
            __FUNCTION_OBJECT_2(call_function, function_name)   __FUNCTION_OBJECT_27_3(call_function, function_name)
#define __FUNCTION_OBJECT_27_1(call_function, function_name)    \
            __FUNCTION_OBJECT_1(call_function, function_name)   __FUNCTION_OBJECT_27_2(call_function, function_name)

#define __FUNCTION_OBJECT_28_28(call_function, function_name)   __FUNCTION_OBJECT_28(call_function, function_name)
#define __FUNCTION_OBJECT_28_27(call_function, function_name)   \
            __FUNCTION_OBJECT_27(call_function, function_name)  __FUNCTION_OBJECT_28_28(call_function, function_name)
#define __FUNCTION_OBJECT_28_26(call_function, function_name)   \
            __FUNCTION_OBJECT_26(call_function, function_name)  __FUNCTION_OBJECT_28_27(call_function, function_name)
#define __FUNCTION_OBJECT_28_25(call_function, function_name)   \
            __FUNCTION_OBJECT_25(call_function, function_name)  __FUNCTION_OBJECT_28_26(call_function, function_name)
#define __FUNCTION_OBJECT_28_24(call_function, function_name)   \
            __FUNCTION_OBJECT_24(call_function, function_name)  __FUNCTION_OBJECT_28_25(call_function, function_name)
#define __FUNCTION_OBJECT_28_23(call_function, function_name)   \
            __FUNCTION_OBJECT_23(call_function, function_name)  __FUNCTION_OBJECT_28_24(call_function, function_name)
#define __FUNCTION_OBJECT_28_22(call_function, function_name)   \
            __FUNCTION_OBJECT_22(call_function, function_name)  __FUNCTION_OBJECT_28_23(call_function, function_name)
#define __FUNCTION_OBJECT_28_21(call_function, function_name)   \
            __FUNCTION_OBJECT_21(call_function, function_name)  __FUNCTION_OBJECT_28_22(call_function, function_name)
#define __FUNCTION_OBJECT_28_20(call_function, function_name)   \
            __FUNCTION_OBJECT_20(call_function, function_name)  __FUNCTION_OBJECT_28_21(call_function, function_name)
#define __FUNCTION_OBJECT_28_19(call_function, function_name)   \
            __FUNCTION_OBJECT_19(call_function, function_name)  __FUNCTION_OBJECT_28_20(call_function, function_name)
#define __FUNCTION_OBJECT_28_18(call_function, function_name)   \
            __FUNCTION_OBJECT_18(call_function, function_name)  __FUNCTION_OBJECT_28_19(call_function, function_name)
#define __FUNCTION_OBJECT_28_17(call_function, function_name)   \
            __FUNCTION_OBJECT_17(call_function, function_name)  __FUNCTION_OBJECT_28_18(call_function, function_name)
#define __FUNCTION_OBJECT_28_16(call_function, function_name)   \
            __FUNCTION_OBJECT_16(call_function, function_name)  __FUNCTION_OBJECT_28_17(call_function, function_name)
#define __FUNCTION_OBJECT_28_15(call_function, function_name)   \
            __FUNCTION_OBJECT_15(call_function, function_name)  __FUNCTION_OBJECT_28_16(call_function, function_name)
#define __FUNCTION_OBJECT_28_14(call_function, function_name)   \
            __FUNCTION_OBJECT_14(call_function, function_name)  __FUNCTION_OBJECT_28_15(call_function, function_name)
#define __FUNCTION_OBJECT_28_13(call_function, function_name)   \
            __FUNCTION_OBJECT_13(call_function, function_name)  __FUNCTION_OBJECT_28_14(call_function, function_name)
#define __FUNCTION_OBJECT_28_12(call_function, function_name)   \
            __FUNCTION_OBJECT_12(call_function, function_name)  __FUNCTION_OBJECT_28_13(call_function, function_name)
#define __FUNCTION_OBJECT_28_11(call_function, function_name)   \
            __FUNCTION_OBJECT_11(call_function, function_name)  __FUNCTION_OBJECT_28_12(call_function, function_name)
#define __FUNCTION_OBJECT_28_10(call_function, function_name)   \
            __FUNCTION_OBJECT_10(call_function, function_name)  __FUNCTION_OBJECT_28_11(call_function, function_name)
#define __FUNCTION_OBJECT_28_9(call_function, function_name)    \
            __FUNCTION_OBJECT_9(call_function, function_name)   __FUNCTION_OBJECT_28_10(call_function, function_name)
#define __FUNCTION_OBJECT_28_8(call_function, function_name)    \
            __FUNCTION_OBJECT_8(call_function, function_name)   __FUNCTION_OBJECT_28_9(call_function, function_name)
#define __FUNCTION_OBJECT_28_7(call_function, function_name)    \
            __FUNCTION_OBJECT_7(call_function, function_name)   __FUNCTION_OBJECT_28_8(call_function, function_name)
#define __FUNCTION_OBJECT_28_6(call_function, function_name)    \
            __FUNCTION_OBJECT_6(call_function, function_name)   __FUNCTION_OBJECT_28_7(call_function, function_name)
#define __FUNCTION_OBJECT_28_5(call_function, function_name)    \
            __FUNCTION_OBJECT_5(call_function, function_name)   __FUNCTION_OBJECT_28_6(call_function, function_name)
#define __FUNCTION_OBJECT_28_4(call_function, function_name)    \
            __FUNCTION_OBJECT_4(call_function, function_name)   __FUNCTION_OBJECT_28_5(call_function, function_name)
#define __FUNCTION_OBJECT_28_3(call_function, function_name)    \
            __FUNCTION_OBJECT_3(call_function, function_name)   __FUNCTION_OBJECT_28_4(call_function, function_name)
#define __FUNCTION_OBJECT_28_2(call_function, function_name)    \
            __FUNCTION_OBJECT_2(call_function, function_name)   __FUNCTION_OBJECT_28_3(call_function, function_name)
#define __FUNCTION_OBJECT_28_1(call_function, function_name)    \
            __FUNCTION_OBJECT_1(call_function, function_name)   __FUNCTION_OBJECT_28_2(call_function, function_name)

#define __FUNCTION_OBJECT_29_29(call_function, function_name)   __FUNCTION_OBJECT_29(call_function, function_name)
#define __FUNCTION_OBJECT_29_28(call_function, function_name)   \
            __FUNCTION_OBJECT_28(call_function, function_name)  __FUNCTION_OBJECT_29_29(call_function, function_name)
#define __FUNCTION_OBJECT_29_27(call_function, function_name)   \
            __FUNCTION_OBJECT_27(call_function, function_name)  __FUNCTION_OBJECT_29_28(call_function, function_name)
#define __FUNCTION_OBJECT_29_26(call_function, function_name)   \
            __FUNCTION_OBJECT_26(call_function, function_name)  __FUNCTION_OBJECT_29_27(call_function, function_name)
#define __FUNCTION_OBJECT_29_25(call_function, function_name)   \
            __FUNCTION_OBJECT_25(call_function, function_name)  __FUNCTION_OBJECT_29_26(call_function, function_name)
#define __FUNCTION_OBJECT_29_24(call_function, function_name)   \
            __FUNCTION_OBJECT_24(call_function, function_name)  __FUNCTION_OBJECT_29_25(call_function, function_name)
#define __FUNCTION_OBJECT_29_23(call_function, function_name)   \
            __FUNCTION_OBJECT_23(call_function, function_name)  __FUNCTION_OBJECT_29_24(call_function, function_name)
#define __FUNCTION_OBJECT_29_22(call_function, function_name)   \
            __FUNCTION_OBJECT_22(call_function, function_name)  __FUNCTION_OBJECT_29_23(call_function, function_name)
#define __FUNCTION_OBJECT_29_21(call_function, function_name)   \
            __FUNCTION_OBJECT_21(call_function, function_name)  __FUNCTION_OBJECT_29_22(call_function, function_name)
#define __FUNCTION_OBJECT_29_20(call_function, function_name)   \
            __FUNCTION_OBJECT_20(call_function, function_name)  __FUNCTION_OBJECT_29_21(call_function, function_name)
#define __FUNCTION_OBJECT_29_19(call_function, function_name)   \
            __FUNCTION_OBJECT_19(call_function, function_name)  __FUNCTION_OBJECT_29_20(call_function, function_name)
#define __FUNCTION_OBJECT_29_18(call_function, function_name)   \
            __FUNCTION_OBJECT_18(call_function, function_name)  __FUNCTION_OBJECT_29_19(call_function, function_name)
#define __FUNCTION_OBJECT_29_17(call_function, function_name)   \
            __FUNCTION_OBJECT_17(call_function, function_name)  __FUNCTION_OBJECT_29_18(call_function, function_name)
#define __FUNCTION_OBJECT_29_16(call_function, function_name)   \
            __FUNCTION_OBJECT_16(call_function, function_name)  __FUNCTION_OBJECT_29_17(call_function, function_name)
#define __FUNCTION_OBJECT_29_15(call_function, function_name)   \
            __FUNCTION_OBJECT_15(call_function, function_name)  __FUNCTION_OBJECT_29_16(call_function, function_name)
#define __FUNCTION_OBJECT_29_14(call_function, function_name)   \
            __FUNCTION_OBJECT_14(call_function, function_name)  __FUNCTION_OBJECT_29_15(call_function, function_name)
#define __FUNCTION_OBJECT_29_13(call_function, function_name)   \
            __FUNCTION_OBJECT_13(call_function, function_name)  __FUNCTION_OBJECT_29_14(call_function, function_name)
#define __FUNCTION_OBJECT_29_12(call_function, function_name)   \
            __FUNCTION_OBJECT_12(call_function, function_name)  __FUNCTION_OBJECT_29_13(call_function, function_name)
#define __FUNCTION_OBJECT_29_11(call_function, function_name)   \
            __FUNCTION_OBJECT_11(call_function, function_name)  __FUNCTION_OBJECT_29_12(call_function, function_name)
#define __FUNCTION_OBJECT_29_10(call_function, function_name)   \
            __FUNCTION_OBJECT_10(call_function, function_name)  __FUNCTION_OBJECT_29_11(call_function, function_name)
#define __FUNCTION_OBJECT_29_9(call_function, function_name)    \
            __FUNCTION_OBJECT_9(call_function, function_name)   __FUNCTION_OBJECT_29_10(call_function, function_name)
#define __FUNCTION_OBJECT_29_8(call_function, function_name)    \
            __FUNCTION_OBJECT_8(call_function, function_name)   __FUNCTION_OBJECT_29_9(call_function, function_name)
#define __FUNCTION_OBJECT_29_7(call_function, function_name)    \
            __FUNCTION_OBJECT_7(call_function, function_name)   __FUNCTION_OBJECT_29_8(call_function, function_name)
#define __FUNCTION_OBJECT_29_6(call_function, function_name)    \
            __FUNCTION_OBJECT_6(call_function, function_name)   __FUNCTION_OBJECT_29_7(call_function, function_name)
#define __FUNCTION_OBJECT_29_5(call_function, function_name)    \
            __FUNCTION_OBJECT_5(call_function, function_name)   __FUNCTION_OBJECT_29_6(call_function, function_name)
#define __FUNCTION_OBJECT_29_4(call_function, function_name)    \
            __FUNCTION_OBJECT_4(call_function, function_name)   __FUNCTION_OBJECT_29_5(call_function, function_name)
#define __FUNCTION_OBJECT_29_3(call_function, function_name)    \
            __FUNCTION_OBJECT_3(call_function, function_name)   __FUNCTION_OBJECT_29_4(call_function, function_name)
#define __FUNCTION_OBJECT_29_2(call_function, function_name)    \
            __FUNCTION_OBJECT_2(call_function, function_name)   __FUNCTION_OBJECT_29_3(call_function, function_name)
#define __FUNCTION_OBJECT_29_1(call_function, function_name)    \
            __FUNCTION_OBJECT_1(call_function, function_name)   __FUNCTION_OBJECT_29_2(call_function, function_name)

#define __FUNCTION_OBJECT_30_30(call_function, function_name)   __FUNCTION_OBJECT_30(call_function, function_name)
#define __FUNCTION_OBJECT_30_29(call_function, function_name)   \
            __FUNCTION_OBJECT_29(call_function, function_name)  __FUNCTION_OBJECT_30_30(call_function, function_name)
#define __FUNCTION_OBJECT_30_28(call_function, function_name)   \
            __FUNCTION_OBJECT_28(call_function, function_name)  __FUNCTION_OBJECT_30_29(call_function, function_name)
#define __FUNCTION_OBJECT_30_27(call_function, function_name)   \
            __FUNCTION_OBJECT_27(call_function, function_name)  __FUNCTION_OBJECT_30_28(call_function, function_name)
#define __FUNCTION_OBJECT_30_26(call_function, function_name)   \
            __FUNCTION_OBJECT_26(call_function, function_name)  __FUNCTION_OBJECT_30_27(call_function, function_name)
#define __FUNCTION_OBJECT_30_25(call_function, function_name)   \
            __FUNCTION_OBJECT_25(call_function, function_name)  __FUNCTION_OBJECT_30_26(call_function, function_name)
#define __FUNCTION_OBJECT_30_24(call_function, function_name)   \
            __FUNCTION_OBJECT_24(call_function, function_name)  __FUNCTION_OBJECT_30_25(call_function, function_name)
#define __FUNCTION_OBJECT_30_23(call_function, function_name)   \
            __FUNCTION_OBJECT_23(call_function, function_name)  __FUNCTION_OBJECT_30_24(call_function, function_name)
#define __FUNCTION_OBJECT_30_22(call_function, function_name)   \
            __FUNCTION_OBJECT_22(call_function, function_name)  __FUNCTION_OBJECT_30_23(call_function, function_name)
#define __FUNCTION_OBJECT_30_21(call_function, function_name)   \
            __FUNCTION_OBJECT_21(call_function, function_name)  __FUNCTION_OBJECT_30_22(call_function, function_name)
#define __FUNCTION_OBJECT_30_20(call_function, function_name)   \
            __FUNCTION_OBJECT_20(call_function, function_name)  __FUNCTION_OBJECT_30_21(call_function, function_name)
#define __FUNCTION_OBJECT_30_19(call_function, function_name)   \
            __FUNCTION_OBJECT_19(call_function, function_name)  __FUNCTION_OBJECT_30_20(call_function, function_name)
#define __FUNCTION_OBJECT_30_18(call_function, function_name)   \
            __FUNCTION_OBJECT_18(call_function, function_name)  __FUNCTION_OBJECT_30_19(call_function, function_name)
#define __FUNCTION_OBJECT_30_17(call_function, function_name)   \
            __FUNCTION_OBJECT_17(call_function, function_name)  __FUNCTION_OBJECT_30_18(call_function, function_name)
#define __FUNCTION_OBJECT_30_16(call_function, function_name)   \
            __FUNCTION_OBJECT_16(call_function, function_name)  __FUNCTION_OBJECT_30_17(call_function, function_name)
#define __FUNCTION_OBJECT_30_15(call_function, function_name)   \
            __FUNCTION_OBJECT_15(call_function, function_name)  __FUNCTION_OBJECT_30_16(call_function, function_name)
#define __FUNCTION_OBJECT_30_14(call_function, function_name)   \
            __FUNCTION_OBJECT_14(call_function, function_name)  __FUNCTION_OBJECT_30_15(call_function, function_name)
#define __FUNCTION_OBJECT_30_13(call_function, function_name)   \
            __FUNCTION_OBJECT_13(call_function, function_name)  __FUNCTION_OBJECT_30_14(call_function, function_name)
#define __FUNCTION_OBJECT_30_12(call_function, function_name)   \
            __FUNCTION_OBJECT_12(call_function, function_name)  __FUNCTION_OBJECT_30_13(call_function, function_name)
#define __FUNCTION_OBJECT_30_11(call_function, function_name)   \
            __FUNCTION_OBJECT_11(call_function, function_name)  __FUNCTION_OBJECT_30_12(call_function, function_name)
#define __FUNCTION_OBJECT_30_10(call_function, function_name)   \
            __FUNCTION_OBJECT_10(call_function, function_name)  __FUNCTION_OBJECT_30_11(call_function, function_name)
#define __FUNCTION_OBJECT_30_9(call_function, function_name)    \
            __FUNCTION_OBJECT_9(call_function, function_name)   __FUNCTION_OBJECT_30_10(call_function, function_name)
#define __FUNCTION_OBJECT_30_8(call_function, function_name)    \
            __FUNCTION_OBJECT_8(call_function, function_name)   __FUNCTION_OBJECT_30_9(call_function, function_name)
#define __FUNCTION_OBJECT_30_7(call_function, function_name)    \
            __FUNCTION_OBJECT_7(call_function, function_name)   __FUNCTION_OBJECT_30_8(call_function, function_name)
#define __FUNCTION_OBJECT_30_6(call_function, function_name)    \
            __FUNCTION_OBJECT_6(call_function, function_name)   __FUNCTION_OBJECT_30_7(call_function, function_name)
#define __FUNCTION_OBJECT_30_5(call_function, function_name)    \
            __FUNCTION_OBJECT_5(call_function, function_name)   __FUNCTION_OBJECT_30_6(call_function, function_name)
#define __FUNCTION_OBJECT_30_4(call_function, function_name)    \
            __FUNCTION_OBJECT_4(call_function, function_name)   __FUNCTION_OBJECT_30_5(call_function, function_name)
#define __FUNCTION_OBJECT_30_3(call_function, function_name)    \
            __FUNCTION_OBJECT_3(call_function, function_name)   __FUNCTION_OBJECT_30_4(call_function, function_name)
#define __FUNCTION_OBJECT_30_2(call_function, function_name)    \
            __FUNCTION_OBJECT_2(call_function, function_name)   __FUNCTION_OBJECT_30_3(call_function, function_name)
#define __FUNCTION_OBJECT_30_1(call_function, function_name)    \
            __FUNCTION_OBJECT_1(call_function, function_name)   __FUNCTION_OBJECT_30_2(call_function, function_name)



#if _MSC_VER < 1800
#define __FUNCTION_OBJECT_MAX_1(call_function, function_name)   __FUNCTION_OBJECT_30_1(call_function, function_name)
#define __FUNCTION_OBJECT_MAX_2(call_function, function_name)   __FUNCTION_OBJECT_30_2(call_function, function_name)
#define __FUNCTION_OBJECT_MAX_3(call_function, function_name)   __FUNCTION_OBJECT_30_3(call_function, function_name)
#define __FUNCTION_OBJECT_MAX_4(call_function, function_name)   __FUNCTION_OBJECT_30_4(call_function, function_name)
#define __FUNCTION_OBJECT_MAX_5(call_function, function_name)   __FUNCTION_OBJECT_30_5(call_function, function_name)
#define __FUNCTION_OBJECT_MAX_6(call_function, function_name)   __FUNCTION_OBJECT_30_6(call_function, function_name)
#define __FUNCTION_OBJECT_MAX_7(call_function, function_name)   __FUNCTION_OBJECT_30_7(call_function, function_name)
#define __FUNCTION_OBJECT_MAX_8(call_function, function_name)   __FUNCTION_OBJECT_30_8(call_function, function_name)
#define __FUNCTION_OBJECT_MAX_9(call_function, function_name)   __FUNCTION_OBJECT_30_9(call_function, function_name)
#define __FUNCTION_OBJECT_MAX_10(call_function, function_name)  __FUNCTION_OBJECT_30_10(call_function, function_name)
#define __FUNCTION_OBJECT_MAX_11(call_function, function_name)  __FUNCTION_OBJECT_30_11(call_function, function_name)
#define __FUNCTION_OBJECT_MAX_12(call_function, function_name)  __FUNCTION_OBJECT_30_12(call_function, function_name)
#define __FUNCTION_OBJECT_MAX_13(call_function, function_name)  __FUNCTION_OBJECT_30_13(call_function, function_name)
#define __FUNCTION_OBJECT_MAX_14(call_function, function_name)  __FUNCTION_OBJECT_30_14(call_function, function_name)
#define __FUNCTION_OBJECT_MAX_15(call_function, function_name)  __FUNCTION_OBJECT_30_15(call_function, function_name)
#define __FUNCTION_OBJECT_MAX_16(call_function, function_name)  __FUNCTION_OBJECT_30_16(call_function, function_name)
#define __FUNCTION_OBJECT_MAX_17(call_function, function_name)  __FUNCTION_OBJECT_30_17(call_function, function_name)
#define __FUNCTION_OBJECT_MAX_18(call_function, function_name)  __FUNCTION_OBJECT_30_18(call_function, function_name)
#define __FUNCTION_OBJECT_MAX_19(call_function, function_name)  __FUNCTION_OBJECT_30_19(call_function, function_name)
#define __FUNCTION_OBJECT_MAX_20(call_function, function_name)  __FUNCTION_OBJECT_30_20(call_function, function_name)
#define __FUNCTION_OBJECT_MAX_21(call_function, function_name)  __FUNCTION_OBJECT_30_21(call_function, function_name)
#define __FUNCTION_OBJECT_MAX_22(call_function, function_name)  __FUNCTION_OBJECT_30_22(call_function, function_name)
#define __FUNCTION_OBJECT_MAX_23(call_function, function_name)  __FUNCTION_OBJECT_30_23(call_function, function_name)
#define __FUNCTION_OBJECT_MAX_24(call_function, function_name)  __FUNCTION_OBJECT_30_24(call_function, function_name)
#define __FUNCTION_OBJECT_MAX_25(call_function, function_name)  __FUNCTION_OBJECT_30_25(call_function, function_name)
#define __FUNCTION_OBJECT_MAX_26(call_function, function_name)  __FUNCTION_OBJECT_30_26(call_function, function_name)
#define __FUNCTION_OBJECT_MAX_27(call_function, function_name)  __FUNCTION_OBJECT_30_27(call_function, function_name)
#define __FUNCTION_OBJECT_MAX_28(call_function, function_name)  __FUNCTION_OBJECT_30_28(call_function, function_name)
#define __FUNCTION_OBJECT_MAX_29(call_function, function_name)  __FUNCTION_OBJECT_30_29(call_function, function_name)
#define __FUNCTION_OBJECT_MAX_30(call_function, function_name)  __FUNCTION_OBJECT_30_30(call_function, function_name)

#else /* _MSC_VER < 1800 */
#define __FUNCTION_OBJECT_MAX_1(call_function, function_name)                                       \
    __FUNCTION_OBJECT_BASE(call_function, function_name, __FUNCTION_OBJECT_PART1_2(typename... T),  \
        __FUNCTION_OBJECT_PART2_2(T&&... A), __FUNCTION_OBJECT_PART3_2(_STD forward<T>(A)...))
#define __FUNCTION_OBJECT_MAX_2(call_function, function_name)                                       \
    __FUNCTION_OBJECT_BASE(call_function, function_name, __FUNCTION_OBJECT_PART1_3(typename... T),  \
        __FUNCTION_OBJECT_PART2_3(T&&... A), __FUNCTION_OBJECT_PART3_3(_STD forward<T>(A)...))
#define __FUNCTION_OBJECT_MAX_3(call_function, function_name)                                       \
    __FUNCTION_OBJECT_BASE(call_function, function_name, __FUNCTION_OBJECT_PART1_4(typename... T),  \
        __FUNCTION_OBJECT_PART2_4(T&&... A), __FUNCTION_OBJECT_PART3_4(_STD forward<T>(A)...))
#define __FUNCTION_OBJECT_MAX_4(call_function, function_name)                                       \
    __FUNCTION_OBJECT_BASE(call_function, function_name, __FUNCTION_OBJECT_PART1_5(typename... T),  \
        __FUNCTION_OBJECT_PART2_5(T&&... A), __FUNCTION_OBJECT_PART3_5(_STD forward<T>(A)...))
#define __FUNCTION_OBJECT_MAX_5(call_function, function_name)                                       \
    __FUNCTION_OBJECT_BASE(call_function, function_name, __FUNCTION_OBJECT_PART1_6(typename... T),  \
        __FUNCTION_OBJECT_PART2_6(T&&... A), __FUNCTION_OBJECT_PART3_6(_STD forward<T>(A)...))
#define __FUNCTION_OBJECT_MAX_6(call_function, function_name)                                       \
    __FUNCTION_OBJECT_BASE(call_function, function_name, __FUNCTION_OBJECT_PART1_7(typename... T),  \
        __FUNCTION_OBJECT_PART2_7(T&&... A), __FUNCTION_OBJECT_PART3_7(_STD forward<T>(A)...))
#define __FUNCTION_OBJECT_MAX_7(call_function, function_name)                                       \
    __FUNCTION_OBJECT_BASE(call_function, function_name, __FUNCTION_OBJECT_PART1_8(typename... T),  \
        __FUNCTION_OBJECT_PART2_8(T&&... A), __FUNCTION_OBJECT_PART3_8(_STD forward<T>(A)...))
#define __FUNCTION_OBJECT_MAX_8(call_function, function_name)                                       \
    __FUNCTION_OBJECT_BASE(call_function, function_name, __FUNCTION_OBJECT_PART1_9(typename... T),  \
        __FUNCTION_OBJECT_PART2_9(T&&... A), __FUNCTION_OBJECT_PART3_9(_STD forward<T>(A)...))
#define __FUNCTION_OBJECT_MAX_9(call_function, function_name)                                       \
    __FUNCTION_OBJECT_BASE(call_function, function_name, __FUNCTION_OBJECT_PART1_10(typename... T), \
        __FUNCTION_OBJECT_PART2_10(T&&... A), __FUNCTION_OBJECT_PART3_10(_STD forward<T>(A)...))
#define __FUNCTION_OBJECT_MAX_10(call_function, function_name)                                      \
    __FUNCTION_OBJECT_BASE(call_function, function_name, __FUNCTION_OBJECT_PART1_11(typename... T), \
        __FUNCTION_OBJECT_PART2_11(T&&... A), __FUNCTION_OBJECT_PART3_11(_STD forward<T>(A)...))
#define __FUNCTION_OBJECT_MAX_11(call_function, function_name)                                      \
    __FUNCTION_OBJECT_BASE(call_function, function_name, __FUNCTION_OBJECT_PART1_12(typename... T), \
        __FUNCTION_OBJECT_PART2_12(T&&... A), __FUNCTION_OBJECT_PART3_12(_STD forward<T>(A)...))
#define __FUNCTION_OBJECT_MAX_12(call_function, function_name)                                      \
    __FUNCTION_OBJECT_BASE(call_function, function_name, __FUNCTION_OBJECT_PART1_13(typename... T), \
        __FUNCTION_OBJECT_PART2_13(T&&... A), __FUNCTION_OBJECT_PART3_13(_STD forward<T>(A)...))
#define __FUNCTION_OBJECT_MAX_13(call_function, function_name)                                      \
    __FUNCTION_OBJECT_BASE(call_function, function_name, __FUNCTION_OBJECT_PART1_14(typename... T), \
        __FUNCTION_OBJECT_PART2_14(T&&... A), __FUNCTION_OBJECT_PART3_14(_STD forward<T>(A)...))
#define __FUNCTION_OBJECT_MAX_14(call_function, function_name)                                      \
    __FUNCTION_OBJECT_BASE(call_function, function_name, __FUNCTION_OBJECT_PART1_15(typename... T), \
        __FUNCTION_OBJECT_PART2_15(T&&... A), __FUNCTION_OBJECT_PART3_15(_STD forward<T>(A)...))
#define __FUNCTION_OBJECT_MAX_15(call_function, function_name)                                      \
    __FUNCTION_OBJECT_BASE(call_function, function_name, __FUNCTION_OBJECT_PART1_16(typename... T), \
        __FUNCTION_OBJECT_PART2_16(T&&... A), __FUNCTION_OBJECT_PART3_16(_STD forward<T>(A)...))
#define __FUNCTION_OBJECT_MAX_16(call_function, function_name)                                      \
    __FUNCTION_OBJECT_BASE(call_function, function_name, __FUNCTION_OBJECT_PART1_17(typename... T), \
        __FUNCTION_OBJECT_PART2_17(T&&... A), __FUNCTION_OBJECT_PART3_17(_STD forward<T>(A)...))
#define __FUNCTION_OBJECT_MAX_17(call_function, function_name)                                      \
    __FUNCTION_OBJECT_BASE(call_function, function_name, __FUNCTION_OBJECT_PART1_18(typename... T), \
        __FUNCTION_OBJECT_PART2_18(T&&... A), __FUNCTION_OBJECT_PART3_18(_STD forward<T>(A)...))
#define __FUNCTION_OBJECT_MAX_18(call_function, function_name)                                      \
    __FUNCTION_OBJECT_BASE(call_function, function_name, __FUNCTION_OBJECT_PART1_19(typename... T), \
        __FUNCTION_OBJECT_PART2_19(T&&... A), __FUNCTION_OBJECT_PART3_19(_STD forward<T>(A)...))
#define __FUNCTION_OBJECT_MAX_19(call_function, function_name)                                      \
    __FUNCTION_OBJECT_BASE(call_function, function_name, __FUNCTION_OBJECT_PART1_20(typename... T), \
        __FUNCTION_OBJECT_PART2_20(T&&... A), __FUNCTION_OBJECT_PART3_20(_STD forward<T>(A)...))
#define __FUNCTION_OBJECT_MAX_20(call_function, function_name)                                      \
    __FUNCTION_OBJECT_BASE(call_function, function_name, __FUNCTION_OBJECT_PART1_21(typename... T), \
        __FUNCTION_OBJECT_PART2_21(T&&... A), __FUNCTION_OBJECT_PART3_21(_STD forward<T>(A)...))
#define __FUNCTION_OBJECT_MAX_21(call_function, function_name)                                      \
    __FUNCTION_OBJECT_BASE(call_function, function_name, __FUNCTION_OBJECT_PART1_22(typename... T), \
        __FUNCTION_OBJECT_PART2_22(T&&... A), __FUNCTION_OBJECT_PART3_22(_STD forward<T>(A)...))
#define __FUNCTION_OBJECT_MAX_22(call_function, function_name)                                      \
    __FUNCTION_OBJECT_BASE(call_function, function_name, __FUNCTION_OBJECT_PART1_23(typename... T), \
        __FUNCTION_OBJECT_PART2_23(T&&... A), __FUNCTION_OBJECT_PART3_23(_STD forward<T>(A)...))
#define __FUNCTION_OBJECT_MAX_23(call_function, function_name)                                      \
    __FUNCTION_OBJECT_BASE(call_function, function_name, __FUNCTION_OBJECT_PART1_24(typename... T), \
        __FUNCTION_OBJECT_PART2_24(T&&... A), __FUNCTION_OBJECT_PART3_24(_STD forward<T>(A)...))
#define __FUNCTION_OBJECT_MAX_24(call_function, function_name)                                      \
    __FUNCTION_OBJECT_BASE(call_function, function_name, __FUNCTION_OBJECT_PART1_25(typename... T), \
        __FUNCTION_OBJECT_PART2_25(T&&... A), __FUNCTION_OBJECT_PART3_25(_STD forward<T>(A)...))
#define __FUNCTION_OBJECT_MAX_25(call_function, function_name)                                      \
    __FUNCTION_OBJECT_BASE(call_function, function_name, __FUNCTION_OBJECT_PART1_26(typename... T), \
        __FUNCTION_OBJECT_PART2_26(T&&... A), __FUNCTION_OBJECT_PART3_26(_STD forward<T>(A)...))
#define __FUNCTION_OBJECT_MAX_26(call_function, function_name)                                      \
    __FUNCTION_OBJECT_BASE(call_function, function_name, __FUNCTION_OBJECT_PART1_27(typename... T), \
        __FUNCTION_OBJECT_PART2_27(T&&... A), __FUNCTION_OBJECT_PART3_27(_STD forward<T>(A)...))
#define __FUNCTION_OBJECT_MAX_27(call_function, function_name)                                      \
    __FUNCTION_OBJECT_BASE(call_function, function_name, __FUNCTION_OBJECT_PART1_28(typename... T), \
        __FUNCTION_OBJECT_PART2_28(T&&... A), __FUNCTION_OBJECT_PART3_28(_STD forward<T>(A)...))
#define __FUNCTION_OBJECT_MAX_28(call_function, function_name)                                      \
    __FUNCTION_OBJECT_BASE(call_function, function_name, __FUNCTION_OBJECT_PART1_29(typename... T), \
        __FUNCTION_OBJECT_PART2_29(T&&... A), __FUNCTION_OBJECT_PART3_29(_STD forward<T>(A)...))
#define __FUNCTION_OBJECT_MAX_29(call_function, function_name)                                      \
    __FUNCTION_OBJECT_BASE(call_function, function_name, __FUNCTION_OBJECT_PART1_30(typename... T), \
        __FUNCTION_OBJECT_PART2_30(T&&... A), __FUNCTION_OBJECT_PART3_30(_STD forward<T>(A)...))
#define __FUNCTION_OBJECT_MAX_30(call_function, function_name)                                      \
    __FUNCTION_OBJECT_BASE(call_function, function_name, __FUNCTION_OBJECT_PART1_31(typename... T), \
        __FUNCTION_OBJECT_PART2_31(T&&... A), __FUNCTION_OBJECT_PART3_31(_STD forward<T>(A)...))

#endif /* _MSC_VER < 1800 */



#define _FUNCTION_OBJECT_1(call_function, function_name)        \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_1_1(call_function, operator())            \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)


#define _FUNCTION_OBJECT_2(call_function, function_name)        \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_2_2(call_function, operator())            \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_2_1(call_function, function_name)      \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_2_1(call_function, operator())            \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)


#define _FUNCTION_OBJECT_3(call_function, function_name)        \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_3_3(call_function, operator())            \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_3_2(call_function, function_name)      \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_3_2(call_function, operator())            \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_3_1(call_function, function_name)      \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_3_1(call_function, operator())            \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)


#define _FUNCTION_OBJECT_4(call_function, function_name)        \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_4_4(call_function, operator())            \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_4_3(call_function, function_name)      \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_4_3(call_function, operator())            \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_4_2(call_function, function_name)      \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_4_2(call_function, operator())            \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_4_1(call_function, function_name)      \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_4_1(call_function, operator())            \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)


#define _FUNCTION_OBJECT_5(call_function, function_name)        \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_5_5(call_function, operator())            \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_5_4(call_function, function_name)      \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_5_4(call_function, operator())            \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_5_3(call_function, function_name)      \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_5_3(call_function, operator())            \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_5_2(call_function, function_name)      \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_5_2(call_function, operator())            \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_5_1(call_function, function_name)      \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_5_1(call_function, operator())            \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)


#define _FUNCTION_OBJECT_6(call_function, function_name)        \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_6_6(call_function, operator())            \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_6_5(call_function, function_name)      \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_6_5(call_function, operator())            \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_6_4(call_function, function_name)      \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_6_4(call_function, operator())            \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_6_3(call_function, function_name)      \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_6_3(call_function, operator())            \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_6_2(call_function, function_name)      \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_6_2(call_function, operator())            \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_6_1(call_function, function_name)      \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_6_1(call_function, operator())            \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)


#define _FUNCTION_OBJECT_7(call_function, function_name)        \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_7_7(call_function, operator())            \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_7_6(call_function, function_name)      \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_7_6(call_function, operator())            \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_7_5(call_function, function_name)      \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_7_5(call_function, operator())            \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_7_4(call_function, function_name)      \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_7_4(call_function, operator())            \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_7_3(call_function, function_name)      \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_7_3(call_function, operator())            \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_7_2(call_function, function_name)      \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_7_2(call_function, operator())            \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_7_1(call_function, function_name)      \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_7_1(call_function, operator())            \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)


#define _FUNCTION_OBJECT_8(call_function, function_name)        \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_8_8(call_function, operator())            \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_8_7(call_function, function_name)      \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_8_7(call_function, operator())            \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_8_6(call_function, function_name)      \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_8_6(call_function, operator())            \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_8_5(call_function, function_name)      \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_8_5(call_function, operator())            \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_8_4(call_function, function_name)      \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_8_4(call_function, operator())            \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_8_3(call_function, function_name)      \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_8_3(call_function, operator())            \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_8_2(call_function, function_name)      \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_8_2(call_function, operator())            \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_8_1(call_function, function_name)      \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_8_1(call_function, operator())            \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)


#define _FUNCTION_OBJECT_9(call_function, function_name)        \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_9_9(call_function, operator())            \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_9_8(call_function, function_name)      \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_9_8(call_function, operator())            \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_9_7(call_function, function_name)      \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_9_7(call_function, operator())            \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_9_6(call_function, function_name)      \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_9_6(call_function, operator())            \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_9_5(call_function, function_name)      \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_9_5(call_function, operator())            \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_9_4(call_function, function_name)      \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_9_4(call_function, operator())            \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_9_3(call_function, function_name)      \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_9_3(call_function, operator())            \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_9_2(call_function, function_name)      \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_9_2(call_function, operator())            \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_9_1(call_function, function_name)      \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_9_1(call_function, operator())            \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)


#define _FUNCTION_OBJECT_10(call_function, function_name)       \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_10_10(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_10_9(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_10_9(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_10_8(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_10_8(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_10_7(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_10_7(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_10_6(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_10_6(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_10_5(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_10_5(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_10_4(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_10_4(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_10_3(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_10_3(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_10_2(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_10_2(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_10_1(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_10_1(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)


#define _FUNCTION_OBJECT_11(call_function, function_name)       \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_11_11(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_11_10(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_11_10(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_11_9(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_11_9(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_11_8(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_11_8(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_11_7(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_11_7(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_11_6(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_11_6(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_11_5(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_11_5(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_11_4(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_11_4(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_11_3(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_11_3(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_11_2(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_11_2(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_11_1(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_11_1(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)


#define _FUNCTION_OBJECT_12(call_function, function_name)       \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_12_12(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_12_11(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_12_11(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_12_10(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_12_10(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_12_9(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_12_9(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_12_8(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_12_8(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_12_7(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_12_7(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_12_6(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_12_6(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_12_5(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_12_5(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_12_4(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_12_4(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_12_3(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_12_3(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_12_2(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_12_2(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_12_1(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_12_1(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)


#define _FUNCTION_OBJECT_13(call_function, function_name)       \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_13_13(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_13_12(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_13_12(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_13_11(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_13_11(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_13_10(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_13_10(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_13_9(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_13_9(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_13_8(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_13_8(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_13_7(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_13_7(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_13_6(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_13_6(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_13_5(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_13_5(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_13_4(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_13_4(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_13_3(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_13_3(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_13_2(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_13_2(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_13_1(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_13_1(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)


#define _FUNCTION_OBJECT_14(call_function, function_name)       \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_14_14(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_14_13(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_14_13(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_14_12(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_14_12(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_14_11(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_14_11(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_14_10(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_14_10(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_14_9(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_14_9(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_14_8(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_14_8(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_14_7(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_14_7(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_14_6(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_14_6(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_14_5(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_14_5(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_14_4(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_14_4(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_14_3(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_14_3(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_14_2(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_14_2(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_14_1(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_14_1(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)


#define _FUNCTION_OBJECT_15(call_function, function_name)       \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_15_15(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_15_14(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_15_14(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_15_13(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_15_13(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_15_12(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_15_12(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_15_11(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_15_11(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_15_10(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_15_10(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_15_9(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_15_9(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_15_8(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_15_8(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_15_7(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_15_7(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_15_6(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_15_6(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_15_5(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_15_5(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_15_4(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_15_4(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_15_3(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_15_3(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_15_2(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_15_2(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_15_1(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_15_1(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)


#define _FUNCTION_OBJECT_16(call_function, function_name)       \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_16_16(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_16_15(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_16_15(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_16_14(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_16_14(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_16_13(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_16_13(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_16_12(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_16_12(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_16_11(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_16_11(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_16_10(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_16_10(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_16_9(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_16_9(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_16_8(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_16_8(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_16_7(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_16_7(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_16_6(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_16_6(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_16_5(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_16_5(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_16_4(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_16_4(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_16_3(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_16_3(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_16_2(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_16_2(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_16_1(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_16_1(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)


#define _FUNCTION_OBJECT_17(call_function, function_name)       \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_17_17(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_17_16(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_17_16(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_17_15(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_17_15(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_17_14(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_17_14(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_17_13(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_17_13(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_17_12(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_17_12(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_17_11(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_17_11(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_17_10(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_17_10(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_17_9(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_17_9(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_17_8(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_17_8(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_17_7(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_17_7(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_17_6(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_17_6(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_17_5(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_17_5(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_17_4(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_17_4(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_17_3(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_17_3(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_17_2(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_17_2(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_17_1(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_17_1(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)


#define _FUNCTION_OBJECT_18(call_function, function_name)       \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_18_18(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_18_17(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_18_17(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_18_16(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_18_16(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_18_15(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_18_15(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_18_14(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_18_14(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_18_13(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_18_13(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_18_12(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_18_12(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_18_11(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_18_11(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_18_10(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_18_10(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_18_9(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_18_9(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_18_8(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_18_8(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_18_7(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_18_7(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_18_6(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_18_6(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_18_5(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_18_5(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_18_4(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_18_4(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_18_3(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_18_3(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_18_2(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_18_2(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_18_1(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_18_1(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)


#define _FUNCTION_OBJECT_19(call_function, function_name)       \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_19_19(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_19_18(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_19_18(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_19_17(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_19_17(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_19_16(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_19_16(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_19_15(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_19_15(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_19_14(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_19_14(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_19_13(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_19_13(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_19_12(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_19_12(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_19_11(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_19_11(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_19_10(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_19_10(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_19_9(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_19_9(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_19_8(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_19_8(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_19_7(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_19_7(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_19_6(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_19_6(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_19_5(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_19_5(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_19_4(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_19_4(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_19_3(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_19_3(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_19_2(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_19_2(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_19_1(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_19_1(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)


#define _FUNCTION_OBJECT_20(call_function, function_name)       \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_20_20(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_20_19(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_20_19(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_20_18(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_20_18(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_20_17(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_20_17(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_20_16(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_20_16(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_20_15(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_20_15(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_20_14(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_20_14(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_20_13(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_20_13(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_20_12(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_20_12(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_20_11(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_20_11(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_20_10(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_20_10(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_20_9(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_20_9(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_20_8(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_20_8(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_20_7(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_20_7(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_20_6(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_20_6(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_20_5(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_20_5(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_20_4(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_20_4(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_20_3(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_20_3(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_20_2(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_20_2(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_20_1(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_20_1(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)


#define _FUNCTION_OBJECT_21(call_function, function_name)       \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_21_21(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_21_20(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_21_20(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_21_19(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_21_19(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_21_18(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_21_18(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_21_17(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_21_17(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_21_16(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_21_16(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_21_15(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_21_15(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_21_14(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_21_14(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_21_13(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_21_13(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_21_12(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_21_12(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_21_11(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_21_11(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_21_10(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_21_10(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_21_9(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_21_9(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_21_8(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_21_8(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_21_7(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_21_7(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_21_6(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_21_6(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_21_5(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_21_5(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_21_4(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_21_4(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_21_3(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_21_3(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_21_2(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_21_2(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_21_1(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_21_1(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)


#define _FUNCTION_OBJECT_22(call_function, function_name)       \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_22_22(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_22_21(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_22_21(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_22_20(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_22_20(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_22_19(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_22_19(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_22_18(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_22_18(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_22_17(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_22_17(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_22_16(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_22_16(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_22_15(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_22_15(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_22_14(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_22_14(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_22_13(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_22_13(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_22_12(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_22_12(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_22_11(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_22_11(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_22_10(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_22_10(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_22_9(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_22_9(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_22_8(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_22_8(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_22_7(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_22_7(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_22_6(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_22_6(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_22_5(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_22_5(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_22_4(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_22_4(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_22_3(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_22_3(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_22_2(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_22_2(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_22_1(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_22_1(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)


#define _FUNCTION_OBJECT_23(call_function, function_name)       \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_23_23(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_23_22(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_23_22(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_23_21(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_23_21(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_23_20(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_23_20(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_23_19(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_23_19(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_23_18(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_23_18(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_23_17(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_23_17(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_23_16(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_23_16(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_23_15(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_23_15(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_23_14(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_23_14(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_23_13(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_23_13(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_23_12(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_23_12(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_23_11(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_23_11(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_23_10(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_23_10(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_23_9(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_23_9(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_23_8(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_23_8(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_23_7(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_23_7(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_23_6(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_23_6(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_23_5(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_23_5(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_23_4(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_23_4(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_23_3(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_23_3(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_23_2(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_23_2(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_23_1(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_23_1(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)


#define _FUNCTION_OBJECT_24(call_function, function_name)       \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_24_24(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_24_23(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_24_23(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_24_22(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_24_22(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_24_21(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_24_21(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_24_20(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_24_20(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_24_19(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_24_19(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_24_18(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_24_18(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_24_17(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_24_17(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_24_16(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_24_16(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_24_15(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_24_15(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_24_14(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_24_14(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_24_13(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_24_13(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_24_12(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_24_12(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_24_11(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_24_11(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_24_10(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_24_10(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_24_9(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_24_9(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_24_8(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_24_8(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_24_7(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_24_7(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_24_6(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_24_6(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_24_5(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_24_5(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_24_4(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_24_4(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_24_3(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_24_3(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_24_2(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_24_2(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_24_1(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_24_1(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)


#define _FUNCTION_OBJECT_25(call_function, function_name)       \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_25_25(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_25_24(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_25_24(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_25_23(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_25_23(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_25_22(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_25_22(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_25_21(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_25_21(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_25_20(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_25_20(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_25_19(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_25_19(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_25_18(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_25_18(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_25_17(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_25_17(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_25_16(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_25_16(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_25_15(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_25_15(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_25_14(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_25_14(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_25_13(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_25_13(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_25_12(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_25_12(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_25_11(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_25_11(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_25_10(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_25_10(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_25_9(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_25_9(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_25_8(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_25_8(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_25_7(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_25_7(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_25_6(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_25_6(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_25_5(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_25_5(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_25_4(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_25_4(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_25_3(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_25_3(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_25_2(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_25_2(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_25_1(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_25_1(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)


#define _FUNCTION_OBJECT_26(call_function, function_name)       \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_26_26(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_26_25(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_26_25(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_26_24(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_26_24(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_26_23(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_26_23(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_26_22(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_26_22(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_26_21(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_26_21(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_26_20(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_26_20(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_26_19(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_26_19(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_26_18(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_26_18(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_26_17(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_26_17(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_26_16(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_26_16(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_26_15(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_26_15(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_26_14(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_26_14(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_26_13(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_26_13(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_26_12(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_26_12(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_26_11(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_26_11(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_26_10(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_26_10(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_26_9(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_26_9(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_26_8(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_26_8(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_26_7(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_26_7(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_26_6(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_26_6(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_26_5(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_26_5(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_26_4(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_26_4(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_26_3(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_26_3(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_26_2(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_26_2(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_26_1(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_26_1(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)


#define _FUNCTION_OBJECT_27(call_function, function_name)       \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_27_27(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_27_26(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_27_26(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_27_25(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_27_25(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_27_24(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_27_24(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_27_23(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_27_23(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_27_22(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_27_22(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_27_21(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_27_21(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_27_20(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_27_20(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_27_19(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_27_19(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_27_18(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_27_18(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_27_17(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_27_17(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_27_16(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_27_16(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_27_15(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_27_15(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_27_14(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_27_14(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_27_13(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_27_13(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_27_12(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_27_12(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_27_11(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_27_11(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_27_10(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_27_10(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_27_9(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_27_9(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_27_8(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_27_8(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_27_7(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_27_7(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_27_6(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_27_6(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_27_5(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_27_5(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_27_4(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_27_4(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_27_3(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_27_3(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_27_2(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_27_2(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_27_1(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_27_1(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)


#define _FUNCTION_OBJECT_28(call_function, function_name)       \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_28_28(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_28_27(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_28_27(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_28_26(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_28_26(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_28_25(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_28_25(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_28_24(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_28_24(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_28_23(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_28_23(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_28_22(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_28_22(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_28_21(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_28_21(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_28_20(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_28_20(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_28_19(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_28_19(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_28_18(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_28_18(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_28_17(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_28_17(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_28_16(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_28_16(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_28_15(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_28_15(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_28_14(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_28_14(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_28_13(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_28_13(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_28_12(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_28_12(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_28_11(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_28_11(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_28_10(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_28_10(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_28_9(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_28_9(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_28_8(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_28_8(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_28_7(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_28_7(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_28_6(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_28_6(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_28_5(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_28_5(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_28_4(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_28_4(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_28_3(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_28_3(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_28_2(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_28_2(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_28_1(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_28_1(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)


#define _FUNCTION_OBJECT_29(call_function, function_name)       \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_29_29(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_29_28(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_29_28(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_29_27(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_29_27(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_29_26(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_29_26(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_29_25(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_29_25(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_29_24(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_29_24(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_29_23(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_29_23(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_29_22(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_29_22(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_29_21(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_29_21(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_29_20(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_29_20(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_29_19(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_29_19(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_29_18(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_29_18(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_29_17(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_29_17(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_29_16(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_29_16(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_29_15(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_29_15(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_29_14(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_29_14(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_29_13(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_29_13(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_29_12(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_29_12(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_29_11(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_29_11(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_29_10(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_29_10(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_29_9(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_29_9(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_29_8(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_29_8(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_29_7(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_29_7(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_29_6(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_29_6(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_29_5(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_29_5(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_29_4(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_29_4(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_29_3(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_29_3(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_29_2(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_29_2(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_29_1(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_29_1(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)


#define _FUNCTION_OBJECT_30(call_function, function_name)       \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_30_30(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_30_29(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_30_29(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_30_28(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_30_28(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_30_27(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_30_27(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_30_26(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_30_26(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_30_25(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_30_25(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_30_24(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_30_24(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_30_23(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_30_23(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_30_22(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_30_22(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_30_21(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_30_21(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_30_20(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_30_20(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_30_19(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_30_19(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_30_18(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_30_18(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_30_17(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_30_17(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_30_16(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_30_16(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_30_15(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_30_15(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_30_14(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_30_14(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_30_13(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_30_13(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_30_12(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_30_12(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_30_11(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_30_11(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_30_10(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_30_10(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_30_9(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_30_9(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_30_8(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_30_8(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_30_7(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_30_7(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_30_6(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_30_6(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_30_5(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_30_5(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_30_4(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_30_4(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_30_3(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_30_3(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_30_2(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_30_2(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_30_1(call_function, function_name)     \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_30_1(call_function, operator())           \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)



#define _FUNCTION_OBJECT_MAX_30(call_function, function_name)   \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_MAX_30(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_MAX_29(call_function, function_name)   \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_MAX_29(call_function, operator())         \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_MAX_28(call_function, function_name)   \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_MAX_28(call_function, operator())         \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_MAX_27(call_function, function_name)   \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_MAX_27(call_function, operator())         \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_MAX_26(call_function, function_name)   \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_MAX_26(call_function, operator())         \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_MAX_25(call_function, function_name)   \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_MAX_25(call_function, operator())         \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_MAX_24(call_function, function_name)   \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_MAX_24(call_function, operator())         \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_MAX_23(call_function, function_name)   \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_MAX_23(call_function, operator())         \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_MAX_22(call_function, function_name)   \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_MAX_22(call_function, operator())         \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_MAX_21(call_function, function_name)   \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_MAX_21(call_function, operator())         \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_MAX_20(call_function, function_name)   \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_MAX_20(call_function, operator())         \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_MAX_19(call_function, function_name)   \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_MAX_19(call_function, operator())         \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_MAX_18(call_function, function_name)   \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_MAX_18(call_function, operator())         \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_MAX_17(call_function, function_name)   \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_MAX_17(call_function, operator())         \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_MAX_16(call_function, function_name)   \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_MAX_16(call_function, operator())         \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_MAX_15(call_function, function_name)   \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_MAX_15(call_function, operator())         \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_MAX_14(call_function, function_name)   \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_MAX_14(call_function, operator())         \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_MAX_13(call_function, function_name)   \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_MAX_13(call_function, operator())         \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_MAX_12(call_function, function_name)   \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_MAX_12(call_function, operator())         \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_MAX_11(call_function, function_name)   \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_MAX_11(call_function, operator())         \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_MAX_10(call_function, function_name)   \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_MAX_10(call_function, operator())         \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_MAX_9(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_MAX_9(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_MAX_8(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_MAX_8(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_MAX_7(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_MAX_7(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_MAX_6(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_MAX_6(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_MAX_5(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_MAX_5(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_MAX_4(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_MAX_4(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_MAX_3(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_MAX_3(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_MAX_2(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_MAX_2(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)

#define _FUNCTION_OBJECT_MAX_1(call_function, function_name)    \
__FUNCTION_OBJECT_STRUCT_BEGIN(function_name)                   \
    __FUNCTION_OBJECT_MAX_1(call_function, operator())          \
__FUNCTION_OBJECT_STRUCT_END(function_name)                     \
__FUNCTION_OBJECT__(function_name)                              \
__FUNCTION_OBJECT_EXTRA(call_function, function_name)


#define FUNCTION_OBJECT_1(function_name)        _FUNCTION_OBJECT_1(_STDEX_MY function_name, function_name)

#define FUNCTION_OBJECT_2(function_name)        _FUNCTION_OBJECT_2(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_2_1(function_name)      _FUNCTION_OBJECT_2_1(_STDEX_MY function_name, function_name)

#define FUNCTION_OBJECT_3(function_name)        _FUNCTION_OBJECT_3(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_3_2(function_name)      _FUNCTION_OBJECT_3_2(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_3_1(function_name)      _FUNCTION_OBJECT_3_1(_STDEX_MY function_name, function_name)

#define FUNCTION_OBJECT_4(function_name)        _FUNCTION_OBJECT_4(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_4_3(function_name)      _FUNCTION_OBJECT_4_3(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_4_2(function_name)      _FUNCTION_OBJECT_4_2(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_4_1(function_name)      _FUNCTION_OBJECT_4_1(_STDEX_MY function_name, function_name)

#define FUNCTION_OBJECT_5(function_name)        _FUNCTION_OBJECT_5(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_5_4(function_name)      _FUNCTION_OBJECT_5_4(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_5_3(function_name)      _FUNCTION_OBJECT_5_3(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_5_2(function_name)      _FUNCTION_OBJECT_5_2(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_5_1(function_name)      _FUNCTION_OBJECT_5_1(_STDEX_MY function_name, function_name)

#define FUNCTION_OBJECT_6(function_name)        _FUNCTION_OBJECT_6(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_6_5(function_name)      _FUNCTION_OBJECT_6_5(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_6_4(function_name)      _FUNCTION_OBJECT_6_4(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_6_3(function_name)      _FUNCTION_OBJECT_6_3(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_6_2(function_name)      _FUNCTION_OBJECT_6_2(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_6_1(function_name)      _FUNCTION_OBJECT_6_1(_STDEX_MY function_name, function_name)

#define FUNCTION_OBJECT_7(function_name)        _FUNCTION_OBJECT_7(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_7_6(function_name)      _FUNCTION_OBJECT_7_6(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_7_5(function_name)      _FUNCTION_OBJECT_7_5(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_7_4(function_name)      _FUNCTION_OBJECT_7_4(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_7_3(function_name)      _FUNCTION_OBJECT_7_3(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_7_2(function_name)      _FUNCTION_OBJECT_7_2(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_7_1(function_name)      _FUNCTION_OBJECT_7_1(_STDEX_MY function_name, function_name)

#define FUNCTION_OBJECT_8(function_name)        _FUNCTION_OBJECT_8(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_8_7(function_name)      _FUNCTION_OBJECT_8_7(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_8_6(function_name)      _FUNCTION_OBJECT_8_6(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_8_5(function_name)      _FUNCTION_OBJECT_8_5(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_8_4(function_name)      _FUNCTION_OBJECT_8_4(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_8_3(function_name)      _FUNCTION_OBJECT_8_3(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_8_2(function_name)      _FUNCTION_OBJECT_8_2(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_8_1(function_name)      _FUNCTION_OBJECT_8_1(_STDEX_MY function_name, function_name)

#define FUNCTION_OBJECT_9(function_name)        _FUNCTION_OBJECT_9(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_9_8(function_name)      _FUNCTION_OBJECT_9_8(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_9_7(function_name)      _FUNCTION_OBJECT_9_7(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_9_6(function_name)      _FUNCTION_OBJECT_9_6(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_9_5(function_name)      _FUNCTION_OBJECT_9_5(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_9_4(function_name)      _FUNCTION_OBJECT_9_4(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_9_3(function_name)      _FUNCTION_OBJECT_9_3(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_9_2(function_name)      _FUNCTION_OBJECT_9_2(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_9_1(function_name)      _FUNCTION_OBJECT_9_1(_STDEX_MY function_name, function_name)

#define FUNCTION_OBJECT_10(function_name)       _FUNCTION_OBJECT_10(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_10_9(function_name)     _FUNCTION_OBJECT_10_9(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_10_8(function_name)     _FUNCTION_OBJECT_10_8(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_10_7(function_name)     _FUNCTION_OBJECT_10_7(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_10_6(function_name)     _FUNCTION_OBJECT_10_6(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_10_5(function_name)     _FUNCTION_OBJECT_10_5(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_10_4(function_name)     _FUNCTION_OBJECT_10_4(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_10_3(function_name)     _FUNCTION_OBJECT_10_3(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_10_2(function_name)     _FUNCTION_OBJECT_10_2(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_10_1(function_name)     _FUNCTION_OBJECT_10_1(_STDEX_MY function_name, function_name)

#define FUNCTION_OBJECT_11(function_name)       _FUNCTION_OBJECT_11(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_11_10(function_name)    _FUNCTION_OBJECT_11_10(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_11_9(function_name)     _FUNCTION_OBJECT_11_9(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_11_8(function_name)     _FUNCTION_OBJECT_11_8(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_11_7(function_name)     _FUNCTION_OBJECT_11_7(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_11_6(function_name)     _FUNCTION_OBJECT_11_6(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_11_5(function_name)     _FUNCTION_OBJECT_11_5(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_11_4(function_name)     _FUNCTION_OBJECT_11_4(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_11_3(function_name)     _FUNCTION_OBJECT_11_3(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_11_2(function_name)     _FUNCTION_OBJECT_11_2(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_11_1(function_name)     _FUNCTION_OBJECT_11_1(_STDEX_MY function_name, function_name)

#define FUNCTION_OBJECT_12(function_name)       _FUNCTION_OBJECT_12(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_12_11(function_name)    _FUNCTION_OBJECT_12_11(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_12_10(function_name)    _FUNCTION_OBJECT_12_10(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_12_9(function_name)     _FUNCTION_OBJECT_12_9(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_12_8(function_name)     _FUNCTION_OBJECT_12_8(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_12_7(function_name)     _FUNCTION_OBJECT_12_7(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_12_6(function_name)     _FUNCTION_OBJECT_12_6(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_12_5(function_name)     _FUNCTION_OBJECT_12_5(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_12_4(function_name)     _FUNCTION_OBJECT_12_4(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_12_3(function_name)     _FUNCTION_OBJECT_12_3(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_12_2(function_name)     _FUNCTION_OBJECT_12_2(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_12_1(function_name)     _FUNCTION_OBJECT_12_1(_STDEX_MY function_name, function_name)

#define FUNCTION_OBJECT_13(function_name)       _FUNCTION_OBJECT_13(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_13_12(function_name)    _FUNCTION_OBJECT_13_12(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_13_11(function_name)    _FUNCTION_OBJECT_13_11(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_13_10(function_name)    _FUNCTION_OBJECT_13_10(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_13_9(function_name)     _FUNCTION_OBJECT_13_9(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_13_8(function_name)     _FUNCTION_OBJECT_13_8(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_13_7(function_name)     _FUNCTION_OBJECT_13_7(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_13_6(function_name)     _FUNCTION_OBJECT_13_6(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_13_5(function_name)     _FUNCTION_OBJECT_13_5(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_13_4(function_name)     _FUNCTION_OBJECT_13_4(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_13_3(function_name)     _FUNCTION_OBJECT_13_3(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_13_2(function_name)     _FUNCTION_OBJECT_13_2(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_13_1(function_name)     _FUNCTION_OBJECT_13_1(_STDEX_MY function_name, function_name)

#define FUNCTION_OBJECT_14(function_name)       _FUNCTION_OBJECT_14(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_14_13(function_name)    _FUNCTION_OBJECT_14_13(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_14_12(function_name)    _FUNCTION_OBJECT_14_12(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_14_11(function_name)    _FUNCTION_OBJECT_14_11(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_14_10(function_name)    _FUNCTION_OBJECT_14_10(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_14_9(function_name)     _FUNCTION_OBJECT_14_9(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_14_8(function_name)     _FUNCTION_OBJECT_14_8(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_14_7(function_name)     _FUNCTION_OBJECT_14_7(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_14_6(function_name)     _FUNCTION_OBJECT_14_6(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_14_5(function_name)     _FUNCTION_OBJECT_14_5(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_14_4(function_name)     _FUNCTION_OBJECT_14_4(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_14_3(function_name)     _FUNCTION_OBJECT_14_3(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_14_2(function_name)     _FUNCTION_OBJECT_14_2(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_14_1(function_name)     _FUNCTION_OBJECT_14_1(_STDEX_MY function_name, function_name)

#define FUNCTION_OBJECT_15(function_name)       _FUNCTION_OBJECT_15(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_15_14(function_name)    _FUNCTION_OBJECT_15_14(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_15_13(function_name)    _FUNCTION_OBJECT_15_13(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_15_12(function_name)    _FUNCTION_OBJECT_15_12(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_15_11(function_name)    _FUNCTION_OBJECT_15_11(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_15_10(function_name)    _FUNCTION_OBJECT_15_10(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_15_9(function_name)     _FUNCTION_OBJECT_15_9(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_15_8(function_name)     _FUNCTION_OBJECT_15_8(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_15_7(function_name)     _FUNCTION_OBJECT_15_7(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_15_6(function_name)     _FUNCTION_OBJECT_15_6(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_15_5(function_name)     _FUNCTION_OBJECT_15_5(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_15_4(function_name)     _FUNCTION_OBJECT_15_4(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_15_3(function_name)     _FUNCTION_OBJECT_15_3(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_15_2(function_name)     _FUNCTION_OBJECT_15_2(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_15_1(function_name)     _FUNCTION_OBJECT_15_1(_STDEX_MY function_name, function_name)

#define FUNCTION_OBJECT_16(function_name)       _FUNCTION_OBJECT_16(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_16_15(function_name)    _FUNCTION_OBJECT_16_15(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_16_14(function_name)    _FUNCTION_OBJECT_16_14(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_16_13(function_name)    _FUNCTION_OBJECT_16_13(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_16_12(function_name)    _FUNCTION_OBJECT_16_12(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_16_11(function_name)    _FUNCTION_OBJECT_16_11(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_16_10(function_name)    _FUNCTION_OBJECT_16_10(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_16_9(function_name)     _FUNCTION_OBJECT_16_9(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_16_8(function_name)     _FUNCTION_OBJECT_16_8(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_16_7(function_name)     _FUNCTION_OBJECT_16_7(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_16_6(function_name)     _FUNCTION_OBJECT_16_6(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_16_5(function_name)     _FUNCTION_OBJECT_16_5(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_16_4(function_name)     _FUNCTION_OBJECT_16_4(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_16_3(function_name)     _FUNCTION_OBJECT_16_3(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_16_2(function_name)     _FUNCTION_OBJECT_16_2(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_16_1(function_name)     _FUNCTION_OBJECT_16_1(_STDEX_MY function_name, function_name)

#define FUNCTION_OBJECT_17(function_name)       _FUNCTION_OBJECT_17(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_17_16(function_name)    _FUNCTION_OBJECT_17_16(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_17_15(function_name)    _FUNCTION_OBJECT_17_15(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_17_14(function_name)    _FUNCTION_OBJECT_17_14(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_17_13(function_name)    _FUNCTION_OBJECT_17_13(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_17_12(function_name)    _FUNCTION_OBJECT_17_12(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_17_11(function_name)    _FUNCTION_OBJECT_17_11(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_17_10(function_name)    _FUNCTION_OBJECT_17_10(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_17_9(function_name)     _FUNCTION_OBJECT_17_9(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_17_8(function_name)     _FUNCTION_OBJECT_17_8(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_17_7(function_name)     _FUNCTION_OBJECT_17_7(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_17_6(function_name)     _FUNCTION_OBJECT_17_6(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_17_5(function_name)     _FUNCTION_OBJECT_17_5(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_17_4(function_name)     _FUNCTION_OBJECT_17_4(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_17_3(function_name)     _FUNCTION_OBJECT_17_3(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_17_2(function_name)     _FUNCTION_OBJECT_17_2(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_17_1(function_name)     _FUNCTION_OBJECT_17_1(_STDEX_MY function_name, function_name)

#define FUNCTION_OBJECT_18(function_name)       _FUNCTION_OBJECT_18(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_18_17(function_name)    _FUNCTION_OBJECT_18_17(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_18_16(function_name)    _FUNCTION_OBJECT_18_16(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_18_15(function_name)    _FUNCTION_OBJECT_18_15(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_18_14(function_name)    _FUNCTION_OBJECT_18_14(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_18_13(function_name)    _FUNCTION_OBJECT_18_13(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_18_12(function_name)    _FUNCTION_OBJECT_18_12(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_18_11(function_name)    _FUNCTION_OBJECT_18_11(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_18_10(function_name)    _FUNCTION_OBJECT_18_10(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_18_9(function_name)     _FUNCTION_OBJECT_18_9(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_18_8(function_name)     _FUNCTION_OBJECT_18_8(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_18_7(function_name)     _FUNCTION_OBJECT_18_7(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_18_6(function_name)     _FUNCTION_OBJECT_18_6(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_18_5(function_name)     _FUNCTION_OBJECT_18_5(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_18_4(function_name)     _FUNCTION_OBJECT_18_4(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_18_3(function_name)     _FUNCTION_OBJECT_18_3(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_18_2(function_name)     _FUNCTION_OBJECT_18_2(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_18_1(function_name)     _FUNCTION_OBJECT_18_1(_STDEX_MY function_name, function_name)

#define FUNCTION_OBJECT_19(function_name)       _FUNCTION_OBJECT_19(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_19_18(function_name)    _FUNCTION_OBJECT_19_18(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_19_17(function_name)    _FUNCTION_OBJECT_19_17(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_19_16(function_name)    _FUNCTION_OBJECT_19_16(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_19_15(function_name)    _FUNCTION_OBJECT_19_15(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_19_14(function_name)    _FUNCTION_OBJECT_19_14(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_19_13(function_name)    _FUNCTION_OBJECT_19_13(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_19_12(function_name)    _FUNCTION_OBJECT_19_12(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_19_11(function_name)    _FUNCTION_OBJECT_19_11(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_19_10(function_name)    _FUNCTION_OBJECT_19_10(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_19_9(function_name)     _FUNCTION_OBJECT_19_9(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_19_8(function_name)     _FUNCTION_OBJECT_19_8(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_19_7(function_name)     _FUNCTION_OBJECT_19_7(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_19_6(function_name)     _FUNCTION_OBJECT_19_6(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_19_5(function_name)     _FUNCTION_OBJECT_19_5(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_19_4(function_name)     _FUNCTION_OBJECT_19_4(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_19_3(function_name)     _FUNCTION_OBJECT_19_3(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_19_2(function_name)     _FUNCTION_OBJECT_19_2(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_19_1(function_name)     _FUNCTION_OBJECT_19_1(_STDEX_MY function_name, function_name)

#define FUNCTION_OBJECT_20(function_name)       _FUNCTION_OBJECT_20(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_20_19(function_name)    _FUNCTION_OBJECT_20_19(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_20_18(function_name)    _FUNCTION_OBJECT_20_18(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_20_17(function_name)    _FUNCTION_OBJECT_20_17(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_20_16(function_name)    _FUNCTION_OBJECT_20_16(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_20_15(function_name)    _FUNCTION_OBJECT_20_15(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_20_14(function_name)    _FUNCTION_OBJECT_20_14(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_20_13(function_name)    _FUNCTION_OBJECT_20_13(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_20_12(function_name)    _FUNCTION_OBJECT_20_12(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_20_11(function_name)    _FUNCTION_OBJECT_20_11(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_20_10(function_name)    _FUNCTION_OBJECT_20_10(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_20_9(function_name)     _FUNCTION_OBJECT_20_9(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_20_8(function_name)     _FUNCTION_OBJECT_20_8(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_20_7(function_name)     _FUNCTION_OBJECT_20_7(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_20_6(function_name)     _FUNCTION_OBJECT_20_6(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_20_5(function_name)     _FUNCTION_OBJECT_20_5(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_20_4(function_name)     _FUNCTION_OBJECT_20_4(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_20_3(function_name)     _FUNCTION_OBJECT_20_3(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_20_2(function_name)     _FUNCTION_OBJECT_20_2(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_20_1(function_name)     _FUNCTION_OBJECT_20_1(_STDEX_MY function_name, function_name)

#define FUNCTION_OBJECT_21(function_name)       _FUNCTION_OBJECT_21(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_21_20(function_name)    _FUNCTION_OBJECT_21_20(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_21_19(function_name)    _FUNCTION_OBJECT_21_19(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_21_18(function_name)    _FUNCTION_OBJECT_21_18(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_21_17(function_name)    _FUNCTION_OBJECT_21_17(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_21_16(function_name)    _FUNCTION_OBJECT_21_16(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_21_15(function_name)    _FUNCTION_OBJECT_21_15(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_21_14(function_name)    _FUNCTION_OBJECT_21_14(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_21_13(function_name)    _FUNCTION_OBJECT_21_13(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_21_12(function_name)    _FUNCTION_OBJECT_21_12(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_21_11(function_name)    _FUNCTION_OBJECT_21_11(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_21_10(function_name)    _FUNCTION_OBJECT_21_10(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_21_9(function_name)     _FUNCTION_OBJECT_21_9(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_21_8(function_name)     _FUNCTION_OBJECT_21_8(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_21_7(function_name)     _FUNCTION_OBJECT_21_7(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_21_6(function_name)     _FUNCTION_OBJECT_21_6(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_21_5(function_name)     _FUNCTION_OBJECT_21_5(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_21_4(function_name)     _FUNCTION_OBJECT_21_4(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_21_3(function_name)     _FUNCTION_OBJECT_21_3(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_21_2(function_name)     _FUNCTION_OBJECT_21_2(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_21_1(function_name)     _FUNCTION_OBJECT_21_1(_STDEX_MY function_name, function_name)

#define FUNCTION_OBJECT_22(function_name)       _FUNCTION_OBJECT_22(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_22_21(function_name)    _FUNCTION_OBJECT_22_21(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_22_20(function_name)    _FUNCTION_OBJECT_22_20(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_22_19(function_name)    _FUNCTION_OBJECT_22_19(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_22_18(function_name)    _FUNCTION_OBJECT_22_18(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_22_17(function_name)    _FUNCTION_OBJECT_22_17(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_22_16(function_name)    _FUNCTION_OBJECT_22_16(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_22_15(function_name)    _FUNCTION_OBJECT_22_15(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_22_14(function_name)    _FUNCTION_OBJECT_22_14(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_22_13(function_name)    _FUNCTION_OBJECT_22_13(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_22_12(function_name)    _FUNCTION_OBJECT_22_12(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_22_11(function_name)    _FUNCTION_OBJECT_22_11(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_22_10(function_name)    _FUNCTION_OBJECT_22_10(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_22_9(function_name)     _FUNCTION_OBJECT_22_9(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_22_8(function_name)     _FUNCTION_OBJECT_22_8(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_22_7(function_name)     _FUNCTION_OBJECT_22_7(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_22_6(function_name)     _FUNCTION_OBJECT_22_6(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_22_5(function_name)     _FUNCTION_OBJECT_22_5(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_22_4(function_name)     _FUNCTION_OBJECT_22_4(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_22_3(function_name)     _FUNCTION_OBJECT_22_3(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_22_2(function_name)     _FUNCTION_OBJECT_22_2(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_22_1(function_name)     _FUNCTION_OBJECT_22_1(_STDEX_MY function_name, function_name)

#define FUNCTION_OBJECT_23(function_name)       _FUNCTION_OBJECT_23(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_23_22(function_name)    _FUNCTION_OBJECT_23_22(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_23_21(function_name)    _FUNCTION_OBJECT_23_21(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_23_20(function_name)    _FUNCTION_OBJECT_23_20(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_23_19(function_name)    _FUNCTION_OBJECT_23_19(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_23_18(function_name)    _FUNCTION_OBJECT_23_18(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_23_17(function_name)    _FUNCTION_OBJECT_23_17(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_23_16(function_name)    _FUNCTION_OBJECT_23_16(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_23_15(function_name)    _FUNCTION_OBJECT_23_15(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_23_14(function_name)    _FUNCTION_OBJECT_23_14(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_23_13(function_name)    _FUNCTION_OBJECT_23_13(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_23_12(function_name)    _FUNCTION_OBJECT_23_12(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_23_11(function_name)    _FUNCTION_OBJECT_23_11(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_23_10(function_name)    _FUNCTION_OBJECT_23_10(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_23_9(function_name)     _FUNCTION_OBJECT_23_9(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_23_8(function_name)     _FUNCTION_OBJECT_23_8(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_23_7(function_name)     _FUNCTION_OBJECT_23_7(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_23_6(function_name)     _FUNCTION_OBJECT_23_6(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_23_5(function_name)     _FUNCTION_OBJECT_23_5(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_23_4(function_name)     _FUNCTION_OBJECT_23_4(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_23_3(function_name)     _FUNCTION_OBJECT_23_3(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_23_2(function_name)     _FUNCTION_OBJECT_23_2(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_23_1(function_name)     _FUNCTION_OBJECT_23_1(_STDEX_MY function_name, function_name)

#define FUNCTION_OBJECT_24(function_name)       _FUNCTION_OBJECT_24(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_24_23(function_name)    _FUNCTION_OBJECT_24_23(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_24_22(function_name)    _FUNCTION_OBJECT_24_22(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_24_21(function_name)    _FUNCTION_OBJECT_24_21(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_24_20(function_name)    _FUNCTION_OBJECT_24_20(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_24_19(function_name)    _FUNCTION_OBJECT_24_19(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_24_18(function_name)    _FUNCTION_OBJECT_24_18(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_24_17(function_name)    _FUNCTION_OBJECT_24_17(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_24_16(function_name)    _FUNCTION_OBJECT_24_16(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_24_15(function_name)    _FUNCTION_OBJECT_24_15(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_24_14(function_name)    _FUNCTION_OBJECT_24_14(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_24_13(function_name)    _FUNCTION_OBJECT_24_13(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_24_12(function_name)    _FUNCTION_OBJECT_24_12(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_24_11(function_name)    _FUNCTION_OBJECT_24_11(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_24_10(function_name)    _FUNCTION_OBJECT_24_10(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_24_9(function_name)     _FUNCTION_OBJECT_24_9(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_24_8(function_name)     _FUNCTION_OBJECT_24_8(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_24_7(function_name)     _FUNCTION_OBJECT_24_7(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_24_6(function_name)     _FUNCTION_OBJECT_24_6(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_24_5(function_name)     _FUNCTION_OBJECT_24_5(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_24_4(function_name)     _FUNCTION_OBJECT_24_4(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_24_3(function_name)     _FUNCTION_OBJECT_24_3(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_24_2(function_name)     _FUNCTION_OBJECT_24_2(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_24_1(function_name)     _FUNCTION_OBJECT_24_1(_STDEX_MY function_name, function_name)

#define FUNCTION_OBJECT_25(function_name)       _FUNCTION_OBJECT_25(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_25_24(function_name)    _FUNCTION_OBJECT_25_24(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_25_23(function_name)    _FUNCTION_OBJECT_25_23(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_25_22(function_name)    _FUNCTION_OBJECT_25_22(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_25_21(function_name)    _FUNCTION_OBJECT_25_21(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_25_20(function_name)    _FUNCTION_OBJECT_25_20(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_25_19(function_name)    _FUNCTION_OBJECT_25_19(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_25_18(function_name)    _FUNCTION_OBJECT_25_18(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_25_17(function_name)    _FUNCTION_OBJECT_25_17(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_25_16(function_name)    _FUNCTION_OBJECT_25_16(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_25_15(function_name)    _FUNCTION_OBJECT_25_15(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_25_14(function_name)    _FUNCTION_OBJECT_25_14(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_25_13(function_name)    _FUNCTION_OBJECT_25_13(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_25_12(function_name)    _FUNCTION_OBJECT_25_12(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_25_11(function_name)    _FUNCTION_OBJECT_25_11(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_25_10(function_name)    _FUNCTION_OBJECT_25_10(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_25_9(function_name)     _FUNCTION_OBJECT_25_9(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_25_8(function_name)     _FUNCTION_OBJECT_25_8(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_25_7(function_name)     _FUNCTION_OBJECT_25_7(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_25_6(function_name)     _FUNCTION_OBJECT_25_6(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_25_5(function_name)     _FUNCTION_OBJECT_25_5(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_25_4(function_name)     _FUNCTION_OBJECT_25_4(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_25_3(function_name)     _FUNCTION_OBJECT_25_3(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_25_2(function_name)     _FUNCTION_OBJECT_25_2(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_25_1(function_name)     _FUNCTION_OBJECT_25_1(_STDEX_MY function_name, function_name)

#define FUNCTION_OBJECT_26(function_name)       _FUNCTION_OBJECT_26(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_26_25(function_name)    _FUNCTION_OBJECT_26_25(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_26_24(function_name)    _FUNCTION_OBJECT_26_24(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_26_23(function_name)    _FUNCTION_OBJECT_26_23(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_26_22(function_name)    _FUNCTION_OBJECT_26_22(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_26_21(function_name)    _FUNCTION_OBJECT_26_21(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_26_20(function_name)    _FUNCTION_OBJECT_26_20(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_26_19(function_name)    _FUNCTION_OBJECT_26_19(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_26_18(function_name)    _FUNCTION_OBJECT_26_18(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_26_17(function_name)    _FUNCTION_OBJECT_26_17(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_26_16(function_name)    _FUNCTION_OBJECT_26_16(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_26_15(function_name)    _FUNCTION_OBJECT_26_15(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_26_14(function_name)    _FUNCTION_OBJECT_26_14(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_26_13(function_name)    _FUNCTION_OBJECT_26_13(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_26_12(function_name)    _FUNCTION_OBJECT_26_12(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_26_11(function_name)    _FUNCTION_OBJECT_26_11(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_26_10(function_name)    _FUNCTION_OBJECT_26_10(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_26_9(function_name)     _FUNCTION_OBJECT_26_9(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_26_8(function_name)     _FUNCTION_OBJECT_26_8(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_26_7(function_name)     _FUNCTION_OBJECT_26_7(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_26_6(function_name)     _FUNCTION_OBJECT_26_6(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_26_5(function_name)     _FUNCTION_OBJECT_26_5(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_26_4(function_name)     _FUNCTION_OBJECT_26_4(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_26_3(function_name)     _FUNCTION_OBJECT_26_3(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_26_2(function_name)     _FUNCTION_OBJECT_26_2(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_26_1(function_name)     _FUNCTION_OBJECT_26_1(_STDEX_MY function_name, function_name)

#define FUNCTION_OBJECT_27(function_name)       _FUNCTION_OBJECT_27(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_27_26(function_name)    _FUNCTION_OBJECT_27_26(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_27_25(function_name)    _FUNCTION_OBJECT_27_25(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_27_24(function_name)    _FUNCTION_OBJECT_27_24(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_27_23(function_name)    _FUNCTION_OBJECT_27_23(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_27_22(function_name)    _FUNCTION_OBJECT_27_22(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_27_21(function_name)    _FUNCTION_OBJECT_27_21(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_27_20(function_name)    _FUNCTION_OBJECT_27_20(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_27_19(function_name)    _FUNCTION_OBJECT_27_19(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_27_18(function_name)    _FUNCTION_OBJECT_27_18(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_27_17(function_name)    _FUNCTION_OBJECT_27_17(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_27_16(function_name)    _FUNCTION_OBJECT_27_16(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_27_15(function_name)    _FUNCTION_OBJECT_27_15(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_27_14(function_name)    _FUNCTION_OBJECT_27_14(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_27_13(function_name)    _FUNCTION_OBJECT_27_13(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_27_12(function_name)    _FUNCTION_OBJECT_27_12(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_27_11(function_name)    _FUNCTION_OBJECT_27_11(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_27_10(function_name)    _FUNCTION_OBJECT_27_10(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_27_9(function_name)     _FUNCTION_OBJECT_27_9(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_27_8(function_name)     _FUNCTION_OBJECT_27_8(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_27_7(function_name)     _FUNCTION_OBJECT_27_7(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_27_6(function_name)     _FUNCTION_OBJECT_27_6(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_27_5(function_name)     _FUNCTION_OBJECT_27_5(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_27_4(function_name)     _FUNCTION_OBJECT_27_4(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_27_3(function_name)     _FUNCTION_OBJECT_27_3(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_27_2(function_name)     _FUNCTION_OBJECT_27_2(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_27_1(function_name)     _FUNCTION_OBJECT_27_1(_STDEX_MY function_name, function_name)

#define FUNCTION_OBJECT_28(function_name)       _FUNCTION_OBJECT_28(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_28_27(function_name)    _FUNCTION_OBJECT_28_27(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_28_26(function_name)    _FUNCTION_OBJECT_28_26(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_28_25(function_name)    _FUNCTION_OBJECT_28_25(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_28_24(function_name)    _FUNCTION_OBJECT_28_24(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_28_23(function_name)    _FUNCTION_OBJECT_28_23(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_28_22(function_name)    _FUNCTION_OBJECT_28_22(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_28_21(function_name)    _FUNCTION_OBJECT_28_21(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_28_20(function_name)    _FUNCTION_OBJECT_28_20(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_28_19(function_name)    _FUNCTION_OBJECT_28_19(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_28_18(function_name)    _FUNCTION_OBJECT_28_18(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_28_17(function_name)    _FUNCTION_OBJECT_28_17(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_28_16(function_name)    _FUNCTION_OBJECT_28_16(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_28_15(function_name)    _FUNCTION_OBJECT_28_15(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_28_14(function_name)    _FUNCTION_OBJECT_28_14(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_28_13(function_name)    _FUNCTION_OBJECT_28_13(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_28_12(function_name)    _FUNCTION_OBJECT_28_12(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_28_11(function_name)    _FUNCTION_OBJECT_28_11(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_28_10(function_name)    _FUNCTION_OBJECT_28_10(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_28_9(function_name)     _FUNCTION_OBJECT_28_9(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_28_8(function_name)     _FUNCTION_OBJECT_28_8(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_28_7(function_name)     _FUNCTION_OBJECT_28_7(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_28_6(function_name)     _FUNCTION_OBJECT_28_6(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_28_5(function_name)     _FUNCTION_OBJECT_28_5(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_28_4(function_name)     _FUNCTION_OBJECT_28_4(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_28_3(function_name)     _FUNCTION_OBJECT_28_3(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_28_2(function_name)     _FUNCTION_OBJECT_28_2(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_28_1(function_name)     _FUNCTION_OBJECT_28_1(_STDEX_MY function_name, function_name)

#define FUNCTION_OBJECT_29(function_name)       _FUNCTION_OBJECT_29(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_29_28(function_name)    _FUNCTION_OBJECT_29_28(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_29_27(function_name)    _FUNCTION_OBJECT_29_27(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_29_26(function_name)    _FUNCTION_OBJECT_29_26(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_29_25(function_name)    _FUNCTION_OBJECT_29_25(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_29_24(function_name)    _FUNCTION_OBJECT_29_24(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_29_23(function_name)    _FUNCTION_OBJECT_29_23(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_29_22(function_name)    _FUNCTION_OBJECT_29_22(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_29_21(function_name)    _FUNCTION_OBJECT_29_21(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_29_20(function_name)    _FUNCTION_OBJECT_29_20(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_29_19(function_name)    _FUNCTION_OBJECT_29_19(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_29_18(function_name)    _FUNCTION_OBJECT_29_18(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_29_17(function_name)    _FUNCTION_OBJECT_29_17(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_29_16(function_name)    _FUNCTION_OBJECT_29_16(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_29_15(function_name)    _FUNCTION_OBJECT_29_15(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_29_14(function_name)    _FUNCTION_OBJECT_29_14(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_29_13(function_name)    _FUNCTION_OBJECT_29_13(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_29_12(function_name)    _FUNCTION_OBJECT_29_12(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_29_11(function_name)    _FUNCTION_OBJECT_29_11(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_29_10(function_name)    _FUNCTION_OBJECT_29_10(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_29_9(function_name)     _FUNCTION_OBJECT_29_9(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_29_8(function_name)     _FUNCTION_OBJECT_29_8(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_29_7(function_name)     _FUNCTION_OBJECT_29_7(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_29_6(function_name)     _FUNCTION_OBJECT_29_6(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_29_5(function_name)     _FUNCTION_OBJECT_29_5(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_29_4(function_name)     _FUNCTION_OBJECT_29_4(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_29_3(function_name)     _FUNCTION_OBJECT_29_3(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_29_2(function_name)     _FUNCTION_OBJECT_29_2(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_29_1(function_name)     _FUNCTION_OBJECT_29_1(_STDEX_MY function_name, function_name)

#define FUNCTION_OBJECT_30(function_name)       _FUNCTION_OBJECT_30(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_30_29(function_name)    _FUNCTION_OBJECT_30_29(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_30_28(function_name)    _FUNCTION_OBJECT_30_28(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_30_27(function_name)    _FUNCTION_OBJECT_30_27(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_30_26(function_name)    _FUNCTION_OBJECT_30_26(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_30_25(function_name)    _FUNCTION_OBJECT_30_25(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_30_24(function_name)    _FUNCTION_OBJECT_30_24(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_30_23(function_name)    _FUNCTION_OBJECT_30_23(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_30_22(function_name)    _FUNCTION_OBJECT_30_22(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_30_21(function_name)    _FUNCTION_OBJECT_30_21(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_30_20(function_name)    _FUNCTION_OBJECT_30_20(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_30_19(function_name)    _FUNCTION_OBJECT_30_19(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_30_18(function_name)    _FUNCTION_OBJECT_30_18(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_30_17(function_name)    _FUNCTION_OBJECT_30_17(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_30_16(function_name)    _FUNCTION_OBJECT_30_16(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_30_15(function_name)    _FUNCTION_OBJECT_30_15(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_30_14(function_name)    _FUNCTION_OBJECT_30_14(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_30_13(function_name)    _FUNCTION_OBJECT_30_13(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_30_12(function_name)    _FUNCTION_OBJECT_30_12(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_30_11(function_name)    _FUNCTION_OBJECT_30_11(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_30_10(function_name)    _FUNCTION_OBJECT_30_10(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_30_9(function_name)     _FUNCTION_OBJECT_30_9(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_30_8(function_name)     _FUNCTION_OBJECT_30_8(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_30_7(function_name)     _FUNCTION_OBJECT_30_7(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_30_6(function_name)     _FUNCTION_OBJECT_30_6(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_30_5(function_name)     _FUNCTION_OBJECT_30_5(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_30_4(function_name)     _FUNCTION_OBJECT_30_4(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_30_3(function_name)     _FUNCTION_OBJECT_30_3(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_30_2(function_name)     _FUNCTION_OBJECT_30_2(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_30_1(function_name)     _FUNCTION_OBJECT_30_1(_STDEX_MY function_name, function_name)

#define FUNCTION_OBJECT_MAX_30(function_name)   _FUNCTION_OBJECT_MAX_30(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_MAX_29(function_name)   _FUNCTION_OBJECT_MAX_29(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_MAX_28(function_name)   _FUNCTION_OBJECT_MAX_28(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_MAX_27(function_name)   _FUNCTION_OBJECT_MAX_27(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_MAX_26(function_name)   _FUNCTION_OBJECT_MAX_26(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_MAX_25(function_name)   _FUNCTION_OBJECT_MAX_25(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_MAX_24(function_name)   _FUNCTION_OBJECT_MAX_24(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_MAX_23(function_name)   _FUNCTION_OBJECT_MAX_23(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_MAX_22(function_name)   _FUNCTION_OBJECT_MAX_22(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_MAX_21(function_name)   _FUNCTION_OBJECT_MAX_21(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_MAX_20(function_name)   _FUNCTION_OBJECT_MAX_20(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_MAX_19(function_name)   _FUNCTION_OBJECT_MAX_19(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_MAX_18(function_name)   _FUNCTION_OBJECT_MAX_18(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_MAX_17(function_name)   _FUNCTION_OBJECT_MAX_17(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_MAX_16(function_name)   _FUNCTION_OBJECT_MAX_16(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_MAX_15(function_name)   _FUNCTION_OBJECT_MAX_15(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_MAX_14(function_name)   _FUNCTION_OBJECT_MAX_14(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_MAX_13(function_name)   _FUNCTION_OBJECT_MAX_13(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_MAX_12(function_name)   _FUNCTION_OBJECT_MAX_12(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_MAX_11(function_name)   _FUNCTION_OBJECT_MAX_11(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_MAX_10(function_name)   _FUNCTION_OBJECT_MAX_10(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_MAX_9(function_name)    _FUNCTION_OBJECT_MAX_9(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_MAX_8(function_name)    _FUNCTION_OBJECT_MAX_8(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_MAX_7(function_name)    _FUNCTION_OBJECT_MAX_7(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_MAX_6(function_name)    _FUNCTION_OBJECT_MAX_6(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_MAX_5(function_name)    _FUNCTION_OBJECT_MAX_5(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_MAX_4(function_name)    _FUNCTION_OBJECT_MAX_4(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_MAX_3(function_name)    _FUNCTION_OBJECT_MAX_3(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_MAX_2(function_name)    _FUNCTION_OBJECT_MAX_2(_STDEX_MY function_name, function_name)
#define FUNCTION_OBJECT_MAX_1(function_name)    _FUNCTION_OBJECT_MAX_1(_STDEX_MY function_name, function_name)


#endif /* _STRINGPRINTF_H_ */

#endif /* _STRINGPRINTF__TYPEDEF_H_ */
