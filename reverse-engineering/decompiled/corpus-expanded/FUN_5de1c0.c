/* Ghidra pseudocode, not original source.
 * ev_cede8c042851d77bd106acb1edcf2aeeffc4764a47601c9bcb205898acb43edb
 * Entry: 0x5de1c0; label: FUN_005de1c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005de1c0(undefined4 param_1)

{
  FUN_004ffaa0(DAT_00973fa4);
  if (DAT_00973e4c == 600) {
    FUN_004ffac0(DAT_00973fa4);
    FUN_005c12e0();
    return;
  }
  *(undefined4 *)(DAT_00973e50 + DAT_00973e4c * 4) = param_1;
  DAT_00973e4c = DAT_00973e4c + 1;
  FUN_004ffac0();
  return;
}

