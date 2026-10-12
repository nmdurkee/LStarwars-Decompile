/* Ghidra pseudocode, not original source.
 * ev_34bcce3fa22e23c2ab9571957a9a402fab0be6cbc2b7d858acbf9422b22923c6
 * Entry: 0x617f90; label: FUN_00617f90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00617f90(float param_1)

{
  if (param_1 < 0.0) {
    _DAT_02912ea8 = 0.0;
    return;
  }
  if (1.0 < param_1) {
    _DAT_02912ea8 = 1.0;
    return;
  }
  _DAT_02912ea8 = param_1;
  return;
}

