/* Ghidra analysis pseudocode, not original source.
 * ev_5e4e6a590c471e22d2a814bcf9fd12a554b410855fef8706c3d4a3775c91fbe8
 * Entry: 0x6e8ecf; label: FUN_006e8ecf
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort FUN_006e8ecf(int param_1)

{
  ushort uVar1;
  uint uVar2;
  undefined1 in_ZF;
  ushort in_FPUStatusWord;
  unkbyte10 extraout_ST0;
  float10 fVar3;
  
  uVar2 = __fload_withFB();
  if ((bool)in_ZF) {
    if (((uVar2 & 0xfffff) == 0) && (param_1 == 0)) {
      in_FPUStatusWord = 1;
    }
    else {
      in_FPUStatusWord = FUN_006f690c();
    }
    if (DAT_0297c180 == 0) {
      uVar1 = __startOneArgErrorHandling();
      return uVar1;
    }
  }
  else {
    fVar3 = (float10)fsin(extraout_ST0);
    if ((in_FPUStatusWord & 0x400) != 0) {
      do {
        fVar3 = fVar3 - ROUND(fVar3 / _DAT_00778f1a) * _DAT_00778f1a;
      } while ((in_FPUStatusWord & 0x400) != 0);
      fsin(fVar3);
    }
    if (DAT_0297c180 == 0) {
      uVar1 = __math_exit();
      return uVar1;
    }
  }
  return in_FPUStatusWord;
}

