/* Ghidra pseudocode, not original source.
 * ev_ba1f842bfa0104f1b5ed7b121d230225c91ad84bbbac79703c0a3e54823fb4da
 * Entry: 0x613050; label: FUN_00613050
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00613050(undefined4 param_1)

{
  int *in_ECX;
  
  (**(code **)(*in_ECX + 8))(param_1,4,1);
  return;
}

