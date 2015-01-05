#define OPERATION_and_n 1
#undef  func
#undef  call
#include "logops_n.c"
#undef  OPERATION_and_n

#define OPERATION_andn_n 1
#undef  func
#undef  call
#include "logops_n.c"
#undef  OPERATION_andn_n

#define OPERATION_nand_n 1
#undef  func
#undef  call
#include "logops_n.c"
#undef  OPERATION_nand_n

#define OPERATION_ior_n 1
#undef  func
#undef  call
#include "logops_n.c"
#undef  OPERATION_ior_n

#define OPERATION_iorn_n 1
#undef  func
#undef  call
#include "logops_n.c"
#undef  OPERATION_iorn_n

#define OPERATION_nior_n 1
#undef  func
#undef  call
#include "logops_n.c"
#undef  OPERATION_nior_n

#define OPERATION_xor_n 1
#undef  func
#undef  call
#include "logops_n.c"
#undef  OPERATION_xor_n

#define OPERATION_xnor_n 1
#undef  func
#undef  call
#include "logops_n.c"
#undef  OPERATION_xnor_n


#define OPERATION_popcount 1
#undef  FNAME
#undef  POPHAM
#include "popham.c"
#undef  OPERATION_popcount

#define OPERATION_hamdist 1
#undef  FNAME
#undef  POPHAM
#include "popham.c"
#undef  OPERATION_hamdist


#define OPERATION_sec_add_1 1
#undef  FNAME
#undef  FNAME_itch
#undef  OP_N
#include "sec_aors_1.c"
#undef  OPERATION_sec_add_1

#define OPERATION_sec_sub_1 1
#undef  FNAME
#undef  FNAME_itch
#undef  OP_N
#include "sec_aors_1.c"
#undef  OPERATION_sec_sub_1


#define OPERATION_sec_div_qr 1
#undef  FNAME
#undef  FNAME_itch
#undef  Q
#undef  RETTYPE
#include "sec_div.c"
#undef  OPERATION_sec_div_qr

#define OPERATION_sec_div_r 1
#undef  FNAME
#undef  FNAME_itch
#undef  Q
#undef  RETTYPE
#include "sec_div.c"
#undef  OPERATION_sec_div_r


#define OPERATION_sec_pi1_div_qr 1
#undef  FNAME
#undef  Q
#undef  RETTYPE
#include "sec_pi1_div.c"
#undef  OPERATION_sec_pi1_div_qr

#define OPERATION_sec_pi1_div_r 1
#undef  FNAME
#undef  Q
#undef  RETTYPE
#include "sec_pi1_div.c"
#undef  OPERATION_sec_pi1_div_r
