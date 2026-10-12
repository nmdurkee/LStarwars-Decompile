/* Ghidra pseudocode, not original source.
 * ev_6614b6c0ec400e98b17ca3318749993ac398f4a5e7c651bffc9aeb30b42772d2
 * Entry: 0x50a650; label: FUN_0050a650
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0050a650(int param_1)

{
  int iVar1;
  
  DAT_00921e5c = 0;
  iVar1 = DAT_00801598;
  if (6 < DAT_00801598) {
    iVar1 = DAT_00921e84;
  }
  *(short *)(param_1 + 0x10) = (short)iVar1 + -1;
  *(undefined4 *)(param_1 + 0xdc) = 2;
  *(undefined2 *)(param_1 + 0x12) = 1;
  DAT_00921d80 = 0;
  DAT_00921d84 = 0;
  DAT_00921d88 = 0;
  DAT_00921d4c = 1;
  _DAT_00921d58 = 3;
  DAT_00921d28 = 0;
  _DAT_00921d2c = 0;
  if (DAT_00924824 != 0) {
    FUN_00509830(0x3fc,0xffffffff,0xffffffff);
    return;
  }
  if (DAT_00802008 != 2) {
    FUN_00509830(0x3ec,0xffffffff,0xffffffff);
    return;
  }
  if ((DAT_00924810 == 0) || (DAT_00802010 == 0)) {
    FUN_00509830(0x3ed,0xffffffff,0xffffffff);
  }
  return;
}

