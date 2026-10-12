/* Ghidra pseudocode, not original source.
 * ev_ba497556ae4cb5529d0570e30fa122537b7c12099b06aeea7aeb0dc1b59874db
 * Entry: 0x5b1610; label: FUN_005b1610
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005b1610(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00763f18;
  if ((param_1 & 1) != 0) {
    FUN_006334d0(in_ECX,0x24);
  }
  return;
}

