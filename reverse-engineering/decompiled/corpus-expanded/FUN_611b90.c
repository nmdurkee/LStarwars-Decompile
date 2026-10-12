/* Ghidra pseudocode, not original source.
 * ev_a21f2a299e5366e10834c725088fc75c17a10a6d511d5a9cecc863d5aa4880c1
 * Entry: 0x611b90; label: FUN_00611b90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00611b90(int param_1)

{
  int in_ECX;
  
  *(uint *)(in_ECX + 8) = param_1 + -1 + *(int *)(in_ECX + 8) & ~(param_1 - 1U);
  return;
}

