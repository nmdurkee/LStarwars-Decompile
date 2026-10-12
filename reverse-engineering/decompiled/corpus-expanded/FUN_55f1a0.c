/* Ghidra pseudocode, not original source.
 * ev_d279921681329594f701fe8f20a56ba9d177d693157112987774dc2af4761a09
 * Entry: 0x55f1a0; label: FUN_0055f1a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0055f1a0(void)

{
  if ((((DAT_0093d7f0 != 0) && ((*(byte *)(DAT_0093d7f0 + 0x1fc) & 0x80) != 0)) &&
      (DAT_0093d7f4 != 0)) && ((*(byte *)(DAT_0093d7f4 + 0x1fc) & 0x80) != 0)) {
    return 1;
  }
  return 0;
}

