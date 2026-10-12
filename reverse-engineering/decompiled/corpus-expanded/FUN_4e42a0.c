/* Ghidra pseudocode, not original source.
 * ev_9cfa2c7caaff9bea1a8899eb9da7a192a21c6dc6359864cdd250e80ead8b0fa3
 * Entry: 0x4e42a0; label: FUN_004e42a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004e42a0(void)

{
  if ((((DAT_00951b50 == 0) && (DAT_0088960c != 0)) && (*(float *)(DAT_0088960c + 0x28) == 1.0)) &&
     (DAT_0087b15c != 0)) {
    FUN_0057a580((int)*(short *)(DAT_0087b160 + 0x62));
  }
  if ((DAT_00889610 == '\0') &&
     ((((DAT_0093d7f0 != 0 && (*(char *)(DAT_0093d7f0 + 0x28b) != '\0')) &&
       ((*(uint *)(DAT_0093d7f0 + 0x1f8) & 0x40000) == 0)) ||
      (((DAT_0093d7f4 != 0 && (*(char *)(DAT_0093d7f4 + 0x28b) != '\0')) &&
       ((*(uint *)(DAT_0093d7f4 + 0x1f8) & 0x40000) == 0)))))) {
    DAT_00889610 = '\x01';
    FUN_0057a620(0,0,1);
  }
  return;
}

