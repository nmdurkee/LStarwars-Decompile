/* Ghidra pseudocode, not original source.
 * ev_a21f2a299e5366e10834c725088fc75c17a10a6d511d5a9cecc863d5aa4880c1
 * Entry: 0x611d70; label: FUN_00611d70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00611d70(void)

{
  int in_ECX;
  
  if ((0 < *(int *)(in_ECX + 0xc)) && (*(int *)(in_ECX + 0xc) < 3)) {
    return 1;
  }
  return 0;
}

