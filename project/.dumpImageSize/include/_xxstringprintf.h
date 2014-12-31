#if MY_NARGS == 0
#define MY_CORE(x)                  MY_CORE_0(x)
#define MY_CORE15(x, y)             MY_CORE15_0(x, y)
#define MY_CORE2(x, y)              MY_CORE2_0(x, y)
#define MY_CORE_CALL(x, y, f)       MY_CORE2_0_CALL(x, y, f)
#define MY_MOV_CORE_CALL(x, y, f)   MY_MOV_CORE2_0_CALL(x, y, f)
#define MY_TAIL(x)                  MY_TAIL_0(x)
#define MY_NARGSm1                  MY_NARGSm1_0

#elif MY_NARGS == 1
#define MY_CORE(x)                  MY_CORE_1(x)
#define MY_CORE15(x, y)             MY_CORE15_1(x, y)
#define MY_CORE2(x, y)              MY_CORE2_1(x, y)
#define MY_CORE_CALL(x, y, f)       MY_CORE2_1_CALL(x, y, f)
#define MY_MOV_CORE_CALL(x, y, f)   MY_MOV_CORE2_1_CALL(x, y, f)
#define MY_TAIL(x)                  MY_TAIL_1(x)
#define MY_NARGSm1                  MY_NARGSm1_1

#elif MY_NARGS == 2
#define MY_CORE(x)                  MY_CORE_2(x)
#define MY_CORE15(x, y)             MY_CORE15_2(x, y)
#define MY_CORE2(x, y)              MY_CORE2_2(x, y)
#define MY_CORE_CALL(x, y, f)       MY_CORE2_2_CALL(x, y, f)
#define MY_MOV_CORE_CALL(x, y, f)   MY_MOV_CORE2_2_CALL(x, y, f)
#define MY_TAIL(x)                  MY_TAIL_2(x)
#define MY_NARGSm1                  MY_NARGSm1_2

#elif MY_NARGS == 3
#define MY_CORE(x)                  MY_CORE_3(x)
#define MY_CORE15(x, y)             MY_CORE15_3(x, y)
#define MY_CORE2(x, y)              MY_CORE2_3(x, y)
#define MY_CORE_CALL(x, y, f)       MY_CORE2_3_CALL(x, y, f)
#define MY_MOV_CORE_CALL(x, y, f)   MY_MOV_CORE2_3_CALL(x, y, f)
#define MY_TAIL(x)                  MY_TAIL_3(x)
#define MY_NARGSm1                  MY_NARGSm1_3

#elif MY_NARGS == 4
#define MY_CORE(x)                  MY_CORE_4(x)
#define MY_CORE15(x, y)             MY_CORE15_4(x, y)
#define MY_CORE2(x, y)              MY_CORE2_4(x, y)
#define MY_CORE_CALL(x, y, f)       MY_CORE2_4_CALL(x, y, f)
#define MY_MOV_CORE_CALL(x, y, f)   MY_MOV_CORE2_4_CALL(x, y, f)
#define MY_TAIL(x)                  MY_TAIL_4(x)
#define MY_NARGSm1                  MY_NARGSm1_4

#elif MY_NARGS == 5
#define MY_CORE(x)                  MY_CORE_5(x)
#define MY_CORE15(x, y)             MY_CORE15_5(x, y)
#define MY_CORE2(x, y)              MY_CORE2_5(x, y)
#define MY_CORE_CALL(x, y, f)       MY_CORE2_5_CALL(x, y, f)
#define MY_MOV_CORE_CALL(x, y, f)   MY_MOV_CORE2_5_CALL(x, y, f)
#define MY_TAIL(x)                  MY_TAIL_5(x)
#define MY_NARGSm1                  MY_NARGSm1_5

#elif MY_NARGS == 6
#define MY_CORE(x)                  MY_CORE_6(x)
#define MY_CORE15(x, y)             MY_CORE15_6(x, y)
#define MY_CORE2(x, y)              MY_CORE2_6(x, y)
#define MY_CORE_CALL(x, y, f)       MY_CORE2_6_CALL(x, y, f)
#define MY_MOV_CORE_CALL(x, y, f)   MY_MOV_CORE2_6_CALL(x, y, f)
#define MY_TAIL(x)                  MY_TAIL_6(x)
#define MY_NARGSm1                  MY_NARGSm1_6

#elif MY_NARGS == 7
#define MY_CORE(x)                  MY_CORE_7(x)
#define MY_CORE15(x, y)             MY_CORE15_7(x, y)
#define MY_CORE2(x, y)              MY_CORE2_7(x, y)
#define MY_CORE_CALL(x, y, f)       MY_CORE2_7_CALL(x, y, f)
#define MY_MOV_CORE_CALL(x, y, f)   MY_MOV_CORE2_7_CALL(x, y, f)
#define MY_TAIL(x)                  MY_TAIL_7(x)
#define MY_NARGSm1                  MY_NARGSm1_7

#elif MY_NARGS == 8
#define MY_CORE(x)                  MY_CORE_8(x)
#define MY_CORE15(x, y)             MY_CORE15_8(x, y)
#define MY_CORE2(x, y)              MY_CORE2_8(x, y)
#define MY_CORE_CALL(x, y, f)       MY_CORE2_8_CALL(x, y, f)
#define MY_MOV_CORE_CALL(x, y, f)   MY_MOV_CORE2_8_CALL(x, y, f)
#define MY_TAIL(x)                  MY_TAIL_8(x)
#define MY_NARGSm1                  MY_NARGSm1_8

#elif MY_NARGS == 9
#define MY_CORE(x)                  MY_CORE_9(x)
#define MY_CORE15(x, y)             MY_CORE15_9(x, y)
#define MY_CORE2(x, y)              MY_CORE2_9(x, y)
#define MY_CORE_CALL(x, y, f)       MY_CORE2_9_CALL(x, y, f)
#define MY_MOV_CORE_CALL(x, y, f)   MY_MOV_CORE2_9_CALL(x, y, f)
#define MY_TAIL(x)                  MY_TAIL_9(x)
#define MY_NARGSm1                  MY_NARGSm1_9

#elif MY_NARGS == 10
#define MY_CORE(x)                  MY_CORE_10(x)
#define MY_CORE15(x, y)             MY_CORE15_10(x, y)
#define MY_CORE2(x, y)              MY_CORE2_10(x, y)
#define MY_CORE_CALL(x, y, f)       MY_CORE2_10_CALL(x, y, f)
#define MY_MOV_CORE_CALL(x, y, f)   MY_MOV_CORE2_10_CALL(x, y, f)
#define MY_TAIL(x)                  MY_TAIL_10(x)
#define MY_NARGSm1                  MY_NARGSm1_10

#elif MY_NARGS == 11
#define MY_CORE(x)                  MY_CORE_11(x)
#define MY_CORE15(x, y)             MY_CORE15_11(x, y)
#define MY_CORE2(x, y)              MY_CORE2_11(x, y)
#define MY_CORE_CALL(x, y, f)       MY_CORE2_11_CALL(x, y, f)
#define MY_MOV_CORE_CALL(x, y, f)   MY_MOV_CORE2_11_CALL(x, y, f)
#define MY_TAIL(x)                  MY_TAIL_11(x)
#define MY_NARGSm1                  MY_NARGSm1_11

#elif MY_NARGS == 12
#define MY_CORE(x)                  MY_CORE_12(x)
#define MY_CORE15(x, y)             MY_CORE15_12(x, y)
#define MY_CORE2(x, y)              MY_CORE2_12(x, y)
#define MY_CORE_CALL(x, y, f)       MY_CORE2_12_CALL(x, y, f)
#define MY_MOV_CORE_CALL(x, y, f)   MY_MOV_CORE2_12_CALL(x, y, f)
#define MY_TAIL(x)                  MY_TAIL_12(x)
#define MY_NARGSm1                  MY_NARGSm1_12

#elif MY_NARGS == 13
#define MY_CORE(x)                  MY_CORE_13(x)
#define MY_CORE15(x, y)             MY_CORE15_13(x, y)
#define MY_CORE2(x, y)              MY_CORE2_13(x, y)
#define MY_CORE_CALL(x, y, f)       MY_CORE2_13_CALL(x, y, f)
#define MY_MOV_CORE_CALL(x, y, f)   MY_MOV_CORE2_13_CALL(x, y, f)
#define MY_TAIL(x)                  MY_TAIL_13(x)
#define MY_NARGSm1                  MY_NARGSm1_13

#elif MY_NARGS == 14
#define MY_CORE(x)                  MY_CORE_14(x)
#define MY_CORE15(x, y)             MY_CORE15_14(x, y)
#define MY_CORE2(x, y)              MY_CORE2_14(x, y)
#define MY_CORE_CALL(x, y, f)       MY_CORE2_14_CALL(x, y, f)
#define MY_MOV_CORE_CALL(x, y, f)   MY_MOV_CORE2_14_CALL(x, y, f)
#define MY_TAIL(x)                  MY_TAIL_14(x)
#define MY_NARGSm1                  MY_NARGSm1_14

#elif MY_NARGS == 15
#define MY_CORE(x)                  MY_CORE_15(x)
#define MY_CORE15(x, y)             MY_CORE15_15(x, y)
#define MY_CORE2(x, y)              MY_CORE2_15(x, y)
#define MY_CORE_CALL(x, y, f)       MY_CORE2_15_CALL(x, y, f)
#define MY_MOV_CORE_CALL(x, y, f)   MY_MOV_CORE2_15_CALL(x, y, f)
#define MY_TAIL(x)                  MY_TAIL_15(x)
#define MY_NARGSm1                  MY_NARGSm1_15

#elif MY_NARGS == 16
#define MY_CORE(x)                  MY_CORE_16(x)
#define MY_CORE15(x, y)             MY_CORE15_16(x, y)
#define MY_CORE2(x, y)              MY_CORE2_16(x, y)
#define MY_CORE_CALL(x, y, f)       MY_CORE2_16_CALL(x, y, f)
#define MY_MOV_CORE_CALL(x, y, f)   MY_MOV_CORE2_16_CALL(x, y, f)
#define MY_TAIL(x)                  MY_TAIL_16(x)
#define MY_NARGSm1                  MY_NARGSm1_16

#elif MY_NARGS == 17
#define MY_CORE(x)                  MY_CORE_17(x)
#define MY_CORE15(x, y)             MY_CORE15_17(x, y)
#define MY_CORE2(x, y)              MY_CORE2_17(x, y)
#define MY_CORE_CALL(x, y, f)       MY_CORE2_17_CALL(x, y, f)
#define MY_MOV_CORE_CALL(x, y, f)   MY_MOV_CORE2_17_CALL(x, y, f)
#define MY_TAIL(x)                  MY_TAIL_17(x)
#define MY_NARGSm1                  MY_NARGSm1_17

#elif MY_NARGS == 18
#define MY_CORE(x)                  MY_CORE_18(x)
#define MY_CORE15(x, y)             MY_CORE15_18(x, y)
#define MY_CORE2(x, y)              MY_CORE2_18(x, y)
#define MY_CORE_CALL(x, y, f)       MY_CORE2_18_CALL(x, y, f)
#define MY_MOV_CORE_CALL(x, y, f)   MY_MOV_CORE2_18_CALL(x, y, f)
#define MY_TAIL(x)                  MY_TAIL_18(x)
#define MY_NARGSm1                  MY_NARGSm1_18

#elif MY_NARGS == 19
#define MY_CORE(x)                  MY_CORE_19(x)
#define MY_CORE15(x, y)             MY_CORE15_19(x, y)
#define MY_CORE2(x, y)              MY_CORE2_19(x, y)
#define MY_CORE_CALL(x, y, f)       MY_CORE2_19_CALL(x, y, f)
#define MY_MOV_CORE_CALL(x, y, f)   MY_MOV_CORE2_19_CALL(x, y, f)
#define MY_TAIL(x)                  MY_TAIL_19(x)
#define MY_NARGSm1                  MY_NARGSm1_19

#elif MY_NARGS == 20
#define MY_CORE(x)                  MY_CORE_20(x)
#define MY_CORE15(x, y)             MY_CORE15_20(x, y)
#define MY_CORE2(x, y)              MY_CORE2_20(x, y)
#define MY_CORE_CALL(x, y, f)       MY_CORE2_20_CALL(x, y, f)
#define MY_MOV_CORE_CALL(x, y, f)   MY_MOV_CORE2_20_CALL(x, y, f)
#define MY_TAIL(x)                  MY_TAIL_20(x)
#define MY_NARGSm1                  MY_NARGSm1_20

#elif MY_NARGS == 21
#define MY_CORE(x)                  MY_CORE_21(x)
#define MY_CORE15(x, y)             MY_CORE15_21(x, y)
#define MY_CORE2(x, y)              MY_CORE2_21(x, y)
#define MY_CORE_CALL(x, y, f)       MY_CORE2_21_CALL(x, y, f)
#define MY_MOV_CORE_CALL(x, y, f)   MY_MOV_CORE2_21_CALL(x, y, f)
#define MY_TAIL(x)                  MY_TAIL_21(x)
#define MY_NARGSm1                  MY_NARGSm1_21

#elif MY_NARGS == 22
#define MY_CORE(x)                  MY_CORE_22(x)
#define MY_CORE15(x, y)             MY_CORE15_22(x, y)
#define MY_CORE2(x, y)              MY_CORE2_22(x, y)
#define MY_CORE_CALL(x, y, f)       MY_CORE2_22_CALL(x, y, f)
#define MY_MOV_CORE_CALL(x, y, f)   MY_MOV_CORE2_22_CALL(x, y, f)
#define MY_TAIL(x)                  MY_TAIL_22(x)
#define MY_NARGSm1                  MY_NARGSm1_22

#elif MY_NARGS == 23
#define MY_CORE(x)                  MY_CORE_23(x)
#define MY_CORE15(x, y)             MY_CORE15_23(x, y)
#define MY_CORE2(x, y)              MY_CORE2_23(x, y)
#define MY_CORE_CALL(x, y, f)       MY_CORE2_23_CALL(x, y, f)
#define MY_MOV_CORE_CALL(x, y, f)   MY_MOV_CORE2_23_CALL(x, y, f)
#define MY_TAIL(x)                  MY_TAIL_23(x)
#define MY_NARGSm1                  MY_NARGSm1_23

#elif MY_NARGS == 24
#define MY_CORE(x)                  MY_CORE_24(x)
#define MY_CORE15(x, y)             MY_CORE15_24(x, y)
#define MY_CORE2(x, y)              MY_CORE2_24(x, y)
#define MY_CORE_CALL(x, y, f)       MY_CORE2_24_CALL(x, y, f)
#define MY_MOV_CORE_CALL(x, y, f)   MY_MOV_CORE2_24_CALL(x, y, f)
#define MY_TAIL(x)                  MY_TAIL_24(x)
#define MY_NARGSm1                  MY_NARGSm1_24

#elif MY_NARGS == 25
#define MY_CORE(x)                  MY_CORE_25(x)
#define MY_CORE15(x, y)             MY_CORE15_25(x, y)
#define MY_CORE2(x, y)              MY_CORE2_25(x, y)
#define MY_CORE_CALL(x, y, f)       MY_CORE2_25_CALL(x, y, f)
#define MY_MOV_CORE_CALL(x, y, f)   MY_MOV_CORE2_25_CALL(x, y, f)
#define MY_TAIL(x)                  MY_TAIL_25(x)
#define MY_NARGSm1                  MY_NARGSm1_25

#elif MY_NARGS == 26
#define MY_CORE(x)                  MY_CORE_26(x)
#define MY_CORE15(x, y)             MY_CORE15_26(x, y)
#define MY_CORE2(x, y)              MY_CORE2_26(x, y)
#define MY_CORE_CALL(x, y, f)       MY_CORE2_26_CALL(x, y, f)
#define MY_MOV_CORE_CALL(x, y, f)   MY_MOV_CORE2_26_CALL(x, y, f)
#define MY_TAIL(x)                  MY_TAIL_26(x)
#define MY_NARGSm1                  MY_NARGSm1_26

#elif MY_NARGS == 27
#define MY_CORE(x)                  MY_CORE_27(x)
#define MY_CORE15(x, y)             MY_CORE15_27(x, y)
#define MY_CORE2(x, y)              MY_CORE2_27(x, y)
#define MY_CORE_CALL(x, y, f)       MY_CORE2_27_CALL(x, y, f)
#define MY_MOV_CORE_CALL(x, y, f)   MY_MOV_CORE2_27_CALL(x, y, f)
#define MY_TAIL(x)                  MY_TAIL_27(x)
#define MY_NARGSm1                  MY_NARGSm1_27

#elif MY_NARGS == 28
#define MY_CORE(x)                  MY_CORE_28(x)
#define MY_CORE15(x, y)             MY_CORE15_28(x, y)
#define MY_CORE2(x, y)              MY_CORE2_28(x, y)
#define MY_CORE_CALL(x, y, f)       MY_CORE2_28_CALL(x, y, f)
#define MY_MOV_CORE_CALL(x, y, f)   MY_MOV_CORE2_28_CALL(x, y, f)
#define MY_TAIL(x)                  MY_TAIL_28(x)
#define MY_NARGSm1                  MY_NARGSm1_28

#elif MY_NARGS == 29
#define MY_CORE(x)                  MY_CORE_29(x)
#define MY_CORE15(x, y)             MY_CORE15_29(x, y)
#define MY_CORE2(x, y)              MY_CORE2_29(x, y)
#define MY_CORE_CALL(x, y, f)       MY_CORE2_29_CALL(x, y, f)
#define MY_MOV_CORE_CALL(x, y, f)   MY_MOV_CORE2_29_CALL(x, y, f)
#define MY_TAIL(x)                  MY_TAIL_29(x)
#define MY_NARGSm1                  MY_NARGSm1_29

#elif MY_NARGS == 30
#define MY_CORE(x)                  MY_CORE_30(x)
#define MY_CORE15(x, y)             MY_CORE15_30(x, y)
#define MY_CORE2(x, y)              MY_CORE2_30(x, y)
#define MY_CORE_CALL(x, y, f)       MY_CORE2_30_CALL(x, y, f)
#define MY_MOV_CORE_CALL(x, y, f)   MY_MOV_CORE2_30_CALL(x, y, f)
#define MY_TAIL(x)                  MY_TAIL_30(x)
#define MY_NARGSm1                  MY_NARGSm1_30

#elif MY_NARGS == -1 /* Using C++11 Style */
#define MY_CORE(x)
#define MY_CORE15(x, y)
#define MY_CORE2(x, y)
#define MY_CORE_CALL(x, y, f)
#define MY_MOV_CORE_CALL(x, y, f)
#define MY_TAIL(x)
#define MY_NARGSm1

#else /* MY_NARGS */
#error bad number of arguments
#endif /* MY_NARGS */

#if MY_NARGS == 0
#define MY_C_TAIL(x)                MY_TAIL(x)

#elif MY_NARGS == MY_NMAX
#define MY_C_TAIL(x)

#else /* MY_NARGS */
#define MY_C_TAIL(x)                , MY_TAIL(x)
#endif /* MY_NARGS */

#if MY_NARGS == 0
#define MY_FIRST(x)
#define MY_FIRST15(x, y)
#define MY_FIRST2(x, y)
#define MY_FIRST_CALL(x, y, f)
#define MY_MOV_FIRST_CALL(x, y, f)
#define MY_LAST(x)
#define MY_LAST15(x, y)
#define MY_LAST2(x, y)
#define MY_LAST_CALL(x, y, f)
#define MY_MOV_LAST_CALL(x, y, f)
#define MY_COMMA0
#define MY_COMMA1

#elif MY_NARGS == 1
#define MY_FIRST(x)                 MY_YNAME(x, 0)
#define MY_FIRST15(x, y)            MY_YNAME15(x, y, 0)
#define MY_FIRST2(x, y)             MY_YNAME2(x, y, 0)
#define MY_FIRST_CALL(x, y, f)      MY_YCALL3(x, y, 0, f)
#define MY_MOV_FIRST_CALL(x, y, f)  MY_MOV_YCALL3(y, 0, f)
#define MY_LAST(x)
#define MY_LAST15(x, y)
#define MY_LAST2(x, y)
#define MY_LAST_CALL(x, y, f)
#define MY_MOV_LAST_CALL(x, y, f)
#define MY_COMMA0                   ,
#define MY_COMMA1

#else /* MY_NARGS */
#define MY_FIRST(x)                 MY_YNAME(x, 0)
#define MY_FIRST15(x, y)            MY_YNAME15(x, y, 0)
#define MY_FIRST2(x, y)             MY_YNAME2(x, y, 0)
#define MY_FIRST_CALL(x, y, f)      MY_YCALL3(x, y, 0, f)
#define MY_MOV_FIRST_CALL(x, y, f)  MY_MOV_YCALL3(y, 0, f)
#define MY_LAST(x)                  MY_YNAME(x, MY_NARGSm1)
#define MY_LAST15(x, y)             MY_YNAME15(x, y, MY_NARGSm1)
#define MY_LAST2(x, y)              MY_YNAME2(x, y, MY_NARGSm1)
#define MY_LAST_CALL(x, y, f)       MY_YCALL3(x, y, MY_NARGSm1, f)
#define MY_MOV_LAST_CALL(x, y, f)   MY_MOV_YCALL3(y, MY_NARGSm1, f)
#define MY_COMMA0                   ,
#define MY_COMMA1                   ,
#endif /* MY_NARGS */

#if MY_NARGS < 2
#define MY_MCOMMA

#else /* MY_NARGS < 2 */
#define MY_MCOMMA                   ,
#endif /* MY_NARGS < 2*/

#if MY_NARGS < 3
#define MY_LCOMMA

#else /* MY_NARGS < 3*/
#define MY_LCOMMA                   ,
#endif /* MY_NARGS < 3*/

#define MY_CLASS_NAME(x)            MY_YNAME(x, MY_NARGS)
#define MY_PREV_NAME(x)             MY_YNAME(x, MY_NARGSm1)

#define MY_CDR(x)                   MY_CORE(x) MY_LCOMMA MY_LAST(x)
#define MY_CDR15(x, y)              MY_CORE15(x, y) MY_LCOMMA MY_LAST15(x, y)
#define MY_CDR2(x, y)               MY_CORE2(x, y) MY_LCOMMA MY_LAST2(x, y)
#define MY_CDR2_CALL(x, y, f)       MY_CORE_CALL(x, y, f) MY_LCOMMA MY_LAST_CALL(x, y, f)
#define MY_MOV_CDR2_CALL(x, y, f)   MY_MOV_CORE_CALL(x, y, f) MY_LCOMMA MY_MOV_LAST_CALL(x, y, f)
#define MY_LIST(x)                  MY_FIRST(x) MY_MCOMMA MY_CDR(x)
#define MY_LIST15(x, y)             MY_FIRST15(x, y) MY_MCOMMA MY_CDR15(x, y)
#define MY_LIST2(x, y)              MY_FIRST2(x, y) MY_MCOMMA MY_CDR2(x, y)
#define MY_LIST_CALL(x, y, f)       MY_FIRST_CALL(x, y, f) MY_MCOMMA MY_CDR2_CALL(x, y, f)
#define MY_MOV_LIST_CALL(x, y, f)   MY_MOV_FIRST_CALL(x, y, f) MY_MCOMMA MY_MOV_CDR2_CALL(x, y, f)

#if MY_NARGS == -1
#define MY_CLASS_ARG0               typename... _Arg
#define MY_ARG0_ARG1                _Arg...
#define MY_ARG0_ARG1_REF            _Arg&...
#define MY_ARG0_ARG1_CREF           const _Arg&...
#define MY_ARG0_A0                  _Arg... _Ax
#define MY_ARG0_A0_REF              _Arg&... _Ax
#define MY_ARG0_A0_REFREF           _Arg&&... _Ax
#define MY_ARG0_A0_CREF             const _Arg&... _Ax
#define MY_A0_A1                    _Ax...

#define MY_A0_A1_FWD                _STD forward<_Arg>(_Ax)...
#define MY_A0_A1_MOV                _STD move(_Ax)...
#define MY_A0_A1_STRFWD             string_forward(_Ax)...

#else /* MY_NARGS == -1 */
#define MY_CLASS_ARG0               MY_LIST(typename _Arg)
#define MY_ARG0_ARG1                MY_LIST(_Arg)
#define MY_ARG0_ARG1_REF            MY_LIST15(_Arg, &)
#define MY_ARG0_ARG1_CREF           MY_LIST15(const _Arg, &)
#define MY_ARG0_A0                  MY_LIST2(_Arg, _Ax)
#define MY_ARG0_A0_REF              MY_LIST2(_Arg, &_Ax)
#define MY_ARG0_A0_REFREF           MY_LIST2(_Arg, && _Ax)
#define MY_ARG0_A0_CREF             MY_LIST2(const _Arg, &_Ax)
#define MY_A0_A1                    MY_LIST(_Ax)

#define MY_A0_A1_FWD                MY_LIST_CALL(_Arg, _Ax, _STD forward)
#define MY_A0_A1_MOV                MY_MOV_LIST_CALL(_Arg, _Ax, _STD move)
#define MY_A0_A1_STRFWD             MY_MOV_LIST_CALL(_Arg, _Ax, string_forward)
#endif

#define MY_C_CLASS_ARG0             MY_COMMA0 MY_CLASS_ARG0
#define MY_C_ARG0_ARG1              MY_COMMA0 MY_ARG0_ARG1
#define MY_C_ARG0_ARG1_REF          MY_COMMA0 MY_ARG0_ARG1_REF
#define MY_C_ARG0_ARG1_CREF         MY_COMMA0 MY_ARG0_ARG1_CREF
#define MY_C_ARG0_A0                MY_COMMA0 MY_ARG0_A0
#define MY_C_ARG0_A0_REF            MY_COMMA0 MY_ARG0_A0_REF
#define MY_C_ARG0_A0_REFREF         MY_COMMA0 MY_ARG0_A0_REFREF
#define MY_C_ARG0_A0_CREF           MY_COMMA0 MY_ARG0_A0_CREF
#define MY_C_A0_A1                  MY_COMMA0 MY_A0_A1

#define MY_C_A0_A1_FWD              MY_COMMA0 MY_A0_A1_FWD
#define MY_C_A0_A1_MOV              MY_COMMA0 MY_A0_A1_MOV
#define MY_C_A0_A1_STRFWD           MY_COMMA0 MY_A0_A1_STRFWD


#ifdef _INCL_STRING_PRINTF_FUNCTION
#include <_xxstringprintf_function.h>
#endif /* _INCL_STRING_PRINTF_FUNCTION */


#undef MY_CORE
#undef MY_CORE15
#undef MY_CORE2
#undef MY_CORE_CALL
#undef MY_MOV_CORE_CALL
#undef MY_TAIL
#undef MY_NARGSm1

#undef MY_C_TAIL

#undef MY_FIRST
#undef MY_FIRST15
#undef MY_FIRST2
#undef MY_FIRST_CALL
#undef MY_MOV_FIRST_CALL
#undef MY_LAST
#undef MY_LAST15
#undef MY_LAST2
#undef MY_LAST_CALL
#undef MY_MOV_LAST_CALL
#undef MY_COMMA0
#undef MY_COMMA1

#undef MY_MCOMMA
#undef MY_LCOMMA
#undef MY_CLASS_NAME
#undef MY_PREV_NAME

#undef MY_CDR
#undef MY_CDR15
#undef MY_CDR2
#undef MY_CDR2_CALL
#undef MY_MOV_CDR2_CALL
#undef MY_LIST
#undef MY_LIST15
#undef MY_LIST2
#undef MY_LIST_CALL
#undef MY_MOV_LIST_CALL

#undef MY_CLASS_ARG0
#undef MY_ARG0_ARG1
#undef MY_ARG0_ARG1_REF
#undef MY_ARG0_ARG1_CREF
#undef MY_ARG0_A0
#undef MY_ARG0_A0_REF
#undef MY_ARG0_A0_REFREF
#undef MY_ARG0_A0_CREF
#undef MY_A0_A1

#undef MY_A0_A1_FWD
#undef MY_A0_A1_MOV
#undef MY_A0_A1_STRFWD

#undef MY_C_CLASS_ARG0
#undef MY_C_ARG0_ARG1
#undef MY_C_ARG0_ARG1_REF
#undef MY_C_ARG0_ARG1_CREF
#undef MY_C_ARG0_A0
#undef MY_C_ARG0_A0_REF
#undef MY_C_ARG0_A0_REFREF
#undef MY_C_ARG0_A0_CREF
#undef MY_C_A0_A1

#undef MY_C_A0_A1_FWD
#undef MY_C_A0_A1_MOV
#undef MY_C_A0_A1_STRFWD
