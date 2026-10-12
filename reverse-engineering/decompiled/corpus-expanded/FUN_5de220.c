/* Ghidra pseudocode, not original source.
 * ev_cede8c042851d77bd106acb1edcf2aeeffc4764a47601c9bcb205898acb43edb
 * Entry: 0x5de220; label: FUN_005de220
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

