/* Ghidra pseudocode, not original source.
 * ev_c772dacde58c2298bb9853679eadc775f76d2c3f9befd22496ec5bd64ba1d43a
 * Entry: 0x580430; label: FUN_00580430
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00580430(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_004f7fb0(param_1);
  if ((iVar1 != 0) && (DAT_00951cb8 != 0)) {
    FUN_005cf5b0(DAT_00951cb8,DAT_00951cc0 + 0x8c,*(undefined4 *)(param_1 + 0x510),1);
  }
  return;
}

