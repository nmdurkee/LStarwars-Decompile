/* Ghidra pseudocode, not original source.
 * ev_d27b225b9633e56be6d9d5c2be7adfa4268b9e50bf259b668c645e1f15e7124d
 * Entry: 0x746350; label: FUN_00746350
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00746350(int param_1,int param_2)

{
  *(int *)(param_2 + 4) = param_1 + *(int *)(param_2 + 4);
  return;
}

