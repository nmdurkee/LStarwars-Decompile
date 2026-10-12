/* Ghidra pseudocode, not original source.
 * ev_a21f2a299e5366e10834c725088fc75c17a10a6d511d5a9cecc863d5aa4880c1
 * Entry: 0x611bc0; label: FUN_00611bc0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

bool FUN_00611bc0(ushort param_1)

{
  int in_ECX;
  
  return (*(ushort *)(in_ECX + 0xe) & param_1) != 0;
}

