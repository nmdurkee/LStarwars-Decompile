/* Ghidra pseudocode, not original source.
 * ev_9398ef22b4c43c044c1b187060a2935e0b1d1dc3bbb9f543c9cb1dd758ae788c
 * Entry: 0x553380; label: FUN_00553380
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00553380(void)

{
  DAT_0093b104 = FUN_005e4d00(1);
  *(uint *)(DAT_0093b104 + 0x40) = *(uint *)(DAT_0093b104 + 0x40) & 0xffff3fff;
  *(uint *)(DAT_0093b104 + 0x40) = *(uint *)(DAT_0093b104 + 0x40) & 0xfffffff0;
  *(uint *)(DAT_0093b104 + 0x40) = *(uint *)(DAT_0093b104 + 0x40) | 0x40000;
  FUN_005e4b00(DAT_0093b104);
  DAT_0093b108 = FUN_005e4d40(1);
  *(uint *)(DAT_0093b108 + 0x40) = *(uint *)(DAT_0093b108 + 0x40) & 0xffff3fff;
  *(uint *)(DAT_0093b108 + 0x40) = *(uint *)(DAT_0093b108 + 0x40) & 0xfffffff0;
  *(uint *)(DAT_0093b108 + 0x40) = *(uint *)(DAT_0093b108 + 0x40) | 0x40000;
  FUN_005e4b00(DAT_0093b108);
  return;
}

