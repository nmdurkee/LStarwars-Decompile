/* Ghidra pseudocode, not original source.
 * ev_a21f2a299e5366e10834c725088fc75c17a10a6d511d5a9cecc863d5aa4880c1
 * Entry: 0x611b60; label: FUN_00611b60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00611b60(int param_1,int param_2)

{
  int *in_ECX;
  
  in_ECX[2] = param_1;
  *in_ECX = param_1;
  in_ECX[1] = param_1 + param_2;
  return;
}

