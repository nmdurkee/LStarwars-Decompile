/* Ghidra analysis pseudocode, not original source.
 * ev_17b66c49ee27a79138b1f69ed50983bbb8f85fa72fbf9f24d2924e74b686a814
 * Entry: 0x5ffc80; label: FUN_005ffc80
 */

undefined4 FUN_005ffc80(void)

{
  if (DAT_02854cec == 0) {
    if (DAT_02854d00 != 0) {
      FUN_006e5bc0((&DAT_0280d3cc)[DAT_02854cf0]);
      if (DAT_02854cec != 0) goto LAB_005ffcb1;
    }
    if (DAT_02854cf0 + 1 < 4) {
      DAT_02854cf0 = DAT_02854cf0 + 1 & 3;
    }
    else {
      DAT_02854cf0 = 0;
      DAT_02854cec = 1;
    }
  }
  else {
LAB_005ffcb1:
    if (7 < DAT_02854cf0 + 1) {
      FUN_005f7490();
      return 0;
    }
    DAT_02854cf0 = DAT_02854cf0 + 1 & 7;
  }
  DAT_02854cf4 = 0;
  if (DAT_02854cec != 0) {
    DAT_02854d00 = (&DAT_02854b8c)[DAT_02854cf0];
    return 1;
  }
  FUN_006e5b90(0,DAT_02854cf8,&DAT_02854d00,0x2000,(&DAT_0280d3cc)[DAT_02854cf0]);
  return 1;
}

