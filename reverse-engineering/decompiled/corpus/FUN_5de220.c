/* Ghidra analysis pseudocode, not original source.
 * ev_d8945a36929edeac9ee45c1fd9ef4d2b22c6103a52c54fc2dc40f3cab4594402
 * Entry: 0x5de220; label: FUN_005de220
 */

void FUN_005de220(int param_1)

{
  uint uVar1;
  
  FUN_004ffaa0(DAT_00973fa4);
  if (*(int *)(param_1 + 0x3c) == 0) {
    FUN_004ffac0();
    return;
  }
  uVar1 = 0;
  if (DAT_00973e08 != 0) {
    while (*(int *)(DAT_00973e0c + uVar1 * 4) != param_1) {
      uVar1 = uVar1 + 1;
      if (DAT_00973e08 <= uVar1) {
        FUN_004ffac0();
        return;
      }
    }
    if (uVar1 != 0xffffffff) {
      if (DAT_00973e54 != 600) {
        *(int *)(DAT_00973e58 + DAT_00973e54 * 4) = param_1;
        DAT_00973e54 = DAT_00973e54 + 1;
        FUN_004ffac0();
        return;
      }
      FUN_005c12e0();
      FUN_004ffac0();
      return;
    }
  }
  FUN_004ffac0();
  return;
}

