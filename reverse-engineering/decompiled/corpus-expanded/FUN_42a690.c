/* Ghidra pseudocode, not original source.
 * ev_07ae9e2e04489686a5b927c1fa0593b6d570aedc464c7aee9c2d2b7a39d3047e
 * Entry: 0x42a690; label: FUN_0042a690
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0042a690(int param_1)

{
  if (((*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_0087b150) &&
      (*(float *)(param_1 + 0x1014) == 2e+06)) && (*(float *)(param_1 + 0x5c) < 11.0)) {
    *(undefined1 *)(param_1 + 0x107b) = 3;
    *(undefined4 *)(param_1 + 0x1014) = 0xc21ccccd;
  }
  if (*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_0087b1b0) {
    if (20.75 < *(float *)(param_1 + 100)) {
      *(undefined1 *)(param_1 + 0x107b) = 3;
      *(undefined4 *)(param_1 + 0x1014) = 0x41b33333;
    }
    if (*(float *)(param_1 + 0x5c) < -20.75) {
      *(undefined1 *)(param_1 + 0x107b) = 1;
      *(undefined4 *)(param_1 + 0x1014) = 0xc1b33333;
    }
  }
  return;
}

