/* Ghidra pseudocode, not original source.
 * ev_3e1dd6b2d4f666d2001b5d4d68499aac60c4283e1c30ebf06a77c3cfaf088012
 * Entry: 0x6c7090; label: FUN_006c7090
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_006c7090(void)

{
  int in_ECX;
  
  return *(int *)(in_ECX + 0xa0) + *(int *)(in_ECX + 0x6c);
}

