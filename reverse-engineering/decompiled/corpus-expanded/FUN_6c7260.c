/* Ghidra pseudocode, not original source.
 * ev_3e1dd6b2d4f666d2001b5d4d68499aac60c4283e1c30ebf06a77c3cfaf088012
 * Entry: 0x6c7260; label: FUN_006c7260
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006c7260(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0076b630;
  if ((param_1 & 1) != 0) {
    FUN_006334d0(in_ECX,0x14);
  }
  return;
}

