/* Ghidra pseudocode, not original source.
 * ev_dfa41b6c39560a6d4e303a9a42849e633890ea31aa955743b15917c3077a3c9c
 * Entry: 0x5c2450; label: FUN_005c2450
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005c2450(int param_1,int param_2)

{
  *(int *)(param_2 + 4) = param_1 + *(int *)(param_2 + 4);
  return;
}

