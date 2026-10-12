/* Ghidra pseudocode, not original source.
 * ev_34bcce3fa22e23c2ab9571957a9a402fab0be6cbc2b7d858acbf9422b22923c6
 * Entry: 0x6179c0; label: FUN_006179c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_006179c0(void)

{
  float10 fVar1;
  undefined4 local_8 [2];
  
  FUN_004f3bd0(local_8);
  fVar1 = (float10)FUN_004f3d10(local_8);
  local_8[0] = (undefined4)(longlong)ROUND(fVar1);
  return local_8[0];
}

