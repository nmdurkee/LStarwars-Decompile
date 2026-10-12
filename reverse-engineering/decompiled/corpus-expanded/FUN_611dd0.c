/* Ghidra pseudocode, not original source.
 * ev_a21f2a299e5366e10834c725088fc75c17a10a6d511d5a9cecc863d5aa4880c1
 * Entry: 0x611dd0; label: FUN_00611dd0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00611dd0(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  if (0.0 < *(float *)(in_ECX + 0x1c1c)) {
    uVar1 = FUN_006e6b90();
    return uVar1;
  }
  return *(undefined4 *)(in_ECX + 0x1c);
}

