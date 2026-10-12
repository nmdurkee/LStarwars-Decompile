/* Ghidra pseudocode, not original source.
 * ev_3e1dd6b2d4f666d2001b5d4d68499aac60c4283e1c30ebf06a77c3cfaf088012
 * Entry: 0x6c6aa0; label: FUN_006c6aa0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006c6aa0(int *param_1)

{
  int in_ECX;
  
  (**(code **)(*param_1 + 8))(in_ECX + 4,4,1);
  (**(code **)(*param_1 + 8))(in_ECX + 8,4,1);
  return;
}

