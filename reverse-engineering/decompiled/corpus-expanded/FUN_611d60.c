/* Ghidra pseudocode, not original source.
 * ev_a21f2a299e5366e10834c725088fc75c17a10a6d511d5a9cecc863d5aa4880c1
 * Entry: 0x611d60; label: FUN_00611d60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

bool FUN_00611d60(void)

{
  int in_ECX;
  
  return *(int *)(in_ECX + 0xc) == 3;
}

