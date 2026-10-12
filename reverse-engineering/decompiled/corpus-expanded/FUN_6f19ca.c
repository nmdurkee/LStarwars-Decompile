/* Ghidra pseudocode, not original source.
 * ev_8db3786b1d2e9370d3feb832809c6ae27354528dfff9c38ddb75cfb6eefed4ac
 * Entry: 0x6f19ca; label: FUN_006f19ca
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006f19ca(int param_1)

{
  uint in_EAX;
  uint in_ECX;
  
  for (; (in_EAX < in_ECX && (0xfffff < (uint)(param_1 - *(int *)(in_EAX + 0xc))));
      in_EAX = in_EAX + 0x14) {
  }
  return;
}

