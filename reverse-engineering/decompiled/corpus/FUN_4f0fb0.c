/* Ghidra analysis pseudocode, not original source.
 * ev_45a150495450541a978e32c6b8aebbcc21ab633f871105898ebe02d8fbcf8855
 * Entry: 0x4f0fb0; label: FUN_004f0fb0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004f0fb0(int *param_1,int param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = param_2 - 1;
  _DAT_0091eeb8 = 0;
  if ((-1 < (int)uVar2) && (uVar2 < (uint)param_1[1])) {
    if (*param_1 == 0x12345678) {
      param_1 = param_1 + 3;
    }
    else if (*param_1 == 0x1234567a) {
      param_1 = param_1 + 6;
    }
    else {
      param_1 = param_1 + 5;
    }
    uVar1 = param_1[uVar2 * 7 + 4];
    if ((uVar1 & 2) == 0) {
      param_1[uVar2 * 7 + 4] = (uVar1 ^ param_3) & 1 ^ uVar1;
    }
    return 1;
  }
  return 0;
}

