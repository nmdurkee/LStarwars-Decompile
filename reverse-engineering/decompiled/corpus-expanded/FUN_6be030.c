/* Ghidra pseudocode, not original source.
 * ev_4005f8bc77e113ad185f3b0c9eec9d65d23a3485fd73b1b18a7c340409abf10a
 * Entry: 0x6be030; label: FUN_006be030
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006be030(int param_1)

{
  DAT_0081f9e8 = *(int *)(param_1 + 0x14);
  if (DAT_0081f9e8 < 1) {
    DAT_0081f9e8 = 0x14;
  }
  DAT_0081f9ec = *(int *)(param_1 + 0x18);
  if (DAT_0081f9ec < 1) {
    DAT_0081f9ec = 5;
  }
  DAT_0081f9f0 = *(undefined4 *)(param_1 + 0x1c);
  DAT_0081f9f4 = *(undefined4 *)(param_1 + 0x20);
  return;
}

