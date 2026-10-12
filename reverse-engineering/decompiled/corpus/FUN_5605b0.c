/* Ghidra analysis pseudocode, not original source.
 * ev_b8818be8b1d42ca956a2be2988b1e4995be83f28184475e50ebee2db8720dc05
 * Entry: 0x5605b0; label: FUN_005605b0
 */

void FUN_005605b0(void)

{
  if ((((DAT_00951b7c == DAT_00951b88) || (DAT_0087b71c != 0)) || (DAT_00803784 != DAT_0095121c)) ||
     (DAT_007fac04 == 0)) {
    FUN_0055ffb0(&DAT_0093d858,0xffffffff);
    if ((DAT_0095121c == -1) || ((*(byte *)(DAT_0095121c * 0x9c + 0x7a + DAT_00951354) & 8) == 0)) {
      FUN_0055ffb0(&DAT_00942a04,0xffffffff);
    }
    DAT_00802c68 = 0xffffffff;
  }
  return;
}

