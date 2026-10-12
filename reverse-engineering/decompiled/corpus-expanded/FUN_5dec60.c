/* Ghidra pseudocode, not original source.
 * ev_cede8c042851d77bd106acb1edcf2aeeffc4764a47601c9bcb205898acb43edb
 * Entry: 0x5dec60; label: FUN_005dec60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005dec60(int param_1)

{
  *(undefined1 *)(DAT_00973f98 + param_1 + -1) = 0;
  FUN_005de0c0();
  FUN_00603940((param_1 + -1) * 0x20 + DAT_00973fa0);
  return;
}

