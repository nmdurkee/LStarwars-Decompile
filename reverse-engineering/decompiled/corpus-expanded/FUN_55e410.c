/* Ghidra pseudocode, not original source.
 * ev_d279921681329594f701fe8f20a56ba9d177d693157112987774dc2af4761a09
 * Entry: 0x55e410; label: FUN_0055e410
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0055e410(void)

{
  if ((DAT_0093d7f0 == 0) || ((*(byte *)(DAT_0093d7f0 + 0x1fc) & 0x80) == 0)) {
    if ((DAT_0093d7f4 == 0) || ((*(byte *)(DAT_0093d7f4 + 0x1fc) & 0x80) == 0)) {
      DAT_0093d810 = 0;
      return;
    }
    DAT_0093d810 = DAT_0093d7f4;
  }
  else {
    DAT_0093d810 = DAT_0093d7f0;
    if ((DAT_0093d7f4 != 0) && ((*(byte *)(DAT_0093d7f4 + 0x1fc) & 0x80) != 0)) {
      DAT_0093d814 = DAT_0093d7f4;
      return;
    }
  }
  DAT_0093d814 = 0;
  return;
}

