/* Ghidra analysis pseudocode, not original source.
 * ev_b8818be8b1d42ca956a2be2988b1e4995be83f28184475e50ebee2db8720dc05
 * Entry: 0x55f1a0; label: FUN_0055f1a0
 */

undefined4 FUN_0055f1a0(void)

{
  if ((((DAT_0093d7f0 != 0) && ((*(byte *)(DAT_0093d7f0 + 0x1fc) & 0x80) != 0)) &&
      (DAT_0093d7f4 != 0)) && ((*(byte *)(DAT_0093d7f4 + 0x1fc) & 0x80) != 0)) {
    return 1;
  }
  return 0;
}

