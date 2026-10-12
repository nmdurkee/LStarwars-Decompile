/* Ghidra pseudocode, not original source.
 * ev_34bcce3fa22e23c2ab9571957a9a402fab0be6cbc2b7d858acbf9422b22923c6
 * Entry: 0x617a10; label: FUN_00617a10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00617a10(void)

{
  float10 fVar1;
  undefined4 local_8;
  
  FUN_004f3bd0(&DAT_02900a48);
  fVar1 = (float10)FUN_004f3d10(&DAT_02900a48);
  local_8 = (undefined4)(longlong)ROUND(fVar1);
  DAT_02900a44 = local_8;
  return;
}

