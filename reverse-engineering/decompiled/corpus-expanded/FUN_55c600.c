/* Ghidra pseudocode, not original source.
 * ev_ad94bec40fb329b942d4f858c664032de23cf17ab2243631134a23feb763d3d7
 * Entry: 0x55c600; label: FUN_0055c600
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0055c600(void)

{
  FUN_00547b20(DAT_0093b0d8);
  FUN_00547ab0(DAT_0093b0d8);
  if (DAT_0093b0d8 != 0) {
    FUN_004f5120((float)*(byte *)(DAT_0093b0d8 + 0xc) / 10.0);
  }
  return;
}

