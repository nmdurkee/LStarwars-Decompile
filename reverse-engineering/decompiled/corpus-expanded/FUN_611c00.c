/* Ghidra pseudocode, not original source.
 * ev_a21f2a299e5366e10834c725088fc75c17a10a6d511d5a9cecc863d5aa4880c1
 * Entry: 0x611c00; label: FUN_00611c00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined2 FUN_00611c00(ushort param_1)

{
  int in_ECX;
  
  *(ushort *)(in_ECX + 0xe) = *(ushort *)(in_ECX + 0xe) & ~param_1;
  return *(undefined2 *)(in_ECX + 0xe);
}

