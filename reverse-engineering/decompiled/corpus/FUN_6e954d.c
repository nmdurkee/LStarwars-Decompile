/* Ghidra analysis pseudocode, not original source.
 * ev_5e4e6a590c471e22d2a814bcf9fd12a554b410855fef8706c3d4a3775c91fbe8
 * Entry: 0x6e954d; label: FUN_006e954d
 */

uint FUN_006e954d(uint param_1,uint param_2)

{
  uint uVar1;
  bool in_ZF;
  short in_FPUControlWord;
  
  if (in_ZF) {
    if (((param_2 & 0xfffff) != 0) || (param_1 != 0)) {
      uVar1 = FUN_006f690c();
      goto LAB_006e95cb;
    }
    param_1 = param_2 & 0x80000000;
    param_2 = 0;
joined_r0x006e95bc:
    if (param_1 == 0) {
LAB_006e956e:
      if (DAT_0297c180 != 0) {
        return param_2;
      }
      uVar1 = __math_exit();
      return uVar1;
    }
  }
  else {
    if (in_FPUControlWord != 0x27f) {
      param_2 = FUN_006f68f5();
    }
    if ((param_2 & 0x80000000) == 0) goto LAB_006e956e;
    if (((param_2 & 0x7ff00000) == 0) && ((param_2 & 0xfffff) == 0)) goto joined_r0x006e95bc;
  }
  uVar1 = 1;
LAB_006e95cb:
  if (DAT_0297c180 != 0) {
    return uVar1;
  }
  uVar1 = __startOneArgErrorHandling();
  return uVar1;
}

