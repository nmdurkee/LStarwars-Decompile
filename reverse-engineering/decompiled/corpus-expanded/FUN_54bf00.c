/* Ghidra pseudocode, not original source.
 * ev_7e454dac1a79555432f813726d68bcfcf5762a505a2d8dbf5e6e5fb42bc98c3e
 * Entry: 0x54bf00; label: FUN_0054bf00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0054bf00(int param_1)

{
  if ((0 < param_1) && (*(int *)(DAT_00926c20 + param_1 * 4) != 0)) {
    DAT_00802368 = param_1;
  }
  return;
}

