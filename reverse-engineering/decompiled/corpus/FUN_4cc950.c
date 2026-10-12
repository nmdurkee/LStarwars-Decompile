/* Ghidra analysis pseudocode, not original source.
 * ev_def803aaf6df2de69fb7a62b9730926f531944633efe81a39820bd20d35cd513
 * Entry: 0x4cc950; label: FUN_004cc950
 */

undefined ** FUN_004cc950(char param_1)

{
  char *pcVar1;
  int iVar2;
  
  iVar2 = 0;
  pcVar1 = &DAT_007fcfc7;
  do {
    if (*pcVar1 == param_1) {
      return &PTR_s_batman_007fcfb8 + iVar2 * 6;
    }
    pcVar1 = pcVar1 + 0x18;
    iVar2 = iVar2 + 1;
  } while ((int)pcVar1 < 0x7fd0b7);
  return (undefined **)0x0;
}

