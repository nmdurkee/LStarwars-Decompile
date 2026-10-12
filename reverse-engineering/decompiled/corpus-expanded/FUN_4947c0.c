/* Ghidra pseudocode, not original source.
 * ev_f838318f8db109b6dcd3b75a6a424a1459b1413cbbc9987106adb019bff4cb04
 * Entry: 0x4947c0; label: thunk_FUN_0055c600
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void thunk_FUN_0055c600(void)

{
  FUN_00547b20(DAT_0093b0d8);
  FUN_00547ab0(DAT_0093b0d8);
  if (DAT_0093b0d8 != 0) {
    FUN_004f5120((float)*(byte *)(DAT_0093b0d8 + 0xc) / 10.0);
  }
  return;
}

