/* Ghidra pseudocode, not original source.
 * ev_ba1f842bfa0104f1b5ed7b121d230225c91ad84bbbac79703c0a3e54823fb4da
 * Entry: 0x613180; label: FUN_00613180
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00613180(undefined4 param_1)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_004ef660(param_1,*(int *)(in_ECX + 8) + *(int *)(in_ECX + 4),1);
    *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + 1;
  }
  return;
}

