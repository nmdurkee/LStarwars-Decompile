/* Ghidra pseudocode, not original source.
 * ev_ba1f842bfa0104f1b5ed7b121d230225c91ad84bbbac79703c0a3e54823fb4da
 * Entry: 0x612ff0; label: FUN_00612ff0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00612ff0(int param_1)

{
  int in_ECX;
  
  *(uint *)(in_ECX + 8) = (param_1 + -1 + *(int *)(in_ECX + 8) & ~(param_1 - 1U)) + 4;
  return;
}

