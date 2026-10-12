/* Ghidra pseudocode, not original source.
 * ev_df72e9ec6d097d98265581ff35a2e461cddfe69d3931fceba3802c9eedcc8d52
 * Entry: 0x6415d0; label: FUN_006415d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006415d0(void)

{
  DAT_029139ac = FUN_005d5330();
  DAT_02913778 = 0;
  DAT_029135ec = FUN_005e4d40(1);
  if (DAT_029135ec != 0) {
    *(uint *)(DAT_029135ec + 0x40) = *(uint *)(DAT_029135ec + 0x40) & 0xffff3fff;
    *(uint *)(DAT_029135ec + 0x40) = *(uint *)(DAT_029135ec + 0x40) & 0xfffffff0;
    FUN_005e4b00(DAT_029135ec);
  }
  DAT_029135f0 = FUN_005e4d40(1);
  if (DAT_029135f0 != 0) {
    *(uint *)(DAT_029135f0 + 0x40) = *(uint *)(DAT_029135f0 + 0x40) | 0xc000;
    *(uint *)(DAT_029135f0 + 0x40) = *(uint *)(DAT_029135f0 + 0x40) & 0xfffffff0;
    FUN_005e4b00(DAT_029135f0);
  }
  DAT_029135f4 = FUN_005e4d40(1);
  if (DAT_029135f4 != 0) {
    *(uint *)(DAT_029135f4 + 0x40) = *(uint *)(DAT_029135f4 + 0x40) | 0xc000;
    *(uint *)(DAT_029135f4 + 0x40) = *(uint *)(DAT_029135f4 + 0x40) & 0xfffffff1 | 1;
    FUN_005e4b00(DAT_029135f4);
  }
  FUN_0063f930();
  return;
}

