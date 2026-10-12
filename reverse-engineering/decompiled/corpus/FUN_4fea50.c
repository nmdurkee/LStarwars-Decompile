/* Ghidra analysis pseudocode, not original source.
 * ev_fd88e83c03467170e633a7d88452db02a14be58504554e3319fa3a0da483c1d2
 * Entry: 0x4fea50; label: FUN_004fea50
 */

undefined1 * FUN_004fea50(int param_1)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  iVar3 = 0;
  if (0 < param_1) {
    do {
      if (DAT_00921228 <= iVar2) break;
      pcVar1 = &DAT_009209e8 + iVar2;
      iVar2 = iVar2 + 1;
      if (*pcVar1 == '\0') {
        iVar3 = iVar3 + 1;
      }
    } while (iVar3 < param_1);
  }
  return &DAT_009209e8 + iVar2;
}

