/* Ghidra analysis pseudocode, not original source.
 * ev_5e4e6a590c471e22d2a814bcf9fd12a554b410855fef8706c3d4a3775c91fbe8
 * Entry: 0x6e91e8; label: FUN_006e91e8
 */

uint FUN_006e91e8(int param_1,uint param_2)

{
  uint in_EAX;
  uint uVar1;
  bool in_ZF;
  unkbyte10 in_ST0;
  
  if (in_ZF) {
    if (((in_EAX & 0xfffff) != 0) || (param_1 != 0)) {
      uVar1 = FUN_006f690c();
      goto LAB_006e9281;
    }
    param_2 = 0;
    if ((in_EAX & 0x80000000) == 0) goto LAB_006e9215;
  }
  else {
    if ((((param_2 & 0x7ff00000) == 0) && ((param_2 & 0xfffff) == 0)) && (param_1 == 0)) {
      uVar1 = 2;
      goto LAB_006e9281;
    }
    if ((param_2 & 0x80000000) == 0) {
      log2(in_ST0);
LAB_006e9215:
      if (DAT_0297c180 != 0) {
        return param_2;
      }
      uVar1 = __math_exit();
      return uVar1;
    }
  }
  uVar1 = 1;
LAB_006e9281:
  if (DAT_0297c180 != 0) {
    return uVar1;
  }
  uVar1 = __startOneArgErrorHandling();
  return uVar1;
}

