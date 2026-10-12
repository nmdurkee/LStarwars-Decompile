/* Ghidra pseudocode, not original source.
 * ev_ba1f842bfa0104f1b5ed7b121d230225c91ad84bbbac79703c0a3e54823fb4da
 * Entry: 0x613070; label: FUN_00613070
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00613070(int param_1)

{
  int in_ECX;
  
  *(uint *)(in_ECX + 8) = (param_1 + -1 + *(int *)(in_ECX + 8) & ~(param_1 - 1U)) + 0xc;
  return;
}

