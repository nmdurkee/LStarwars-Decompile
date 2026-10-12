/* Ghidra analysis pseudocode, not original source.
 * ev_89c39211f1406cd3750c6bdd67b17168ccea6fd0f0f78c69056da202eee2c473
 * Entry: 0x55e410; label: FUN_0055e410
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

