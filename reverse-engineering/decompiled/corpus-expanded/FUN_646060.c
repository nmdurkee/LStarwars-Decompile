/* Ghidra pseudocode, not original source.
 * ev_e99a99ac40850efc4319cfa1070f50eca7ba45fd57a73000da90cd7b4a6a9b3b
 * Entry: 0x646060; label: FUN_00646060
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00646060(void)

{
  int iVar1;
  int iVar2;
  
  if (*(char *)(DAT_02920970 + 0xb0) == '\0') {
    iVar2 = 0;
    iVar1 = 0x90;
    do {
      *(undefined2 *)(iVar1 + DAT_02920970) = 0xffff;
      *(undefined1 *)(DAT_02920970 + 0xa0 + iVar2) = 1;
      iVar1 = iVar1 + 2;
      iVar2 = iVar2 + 1;
    } while (iVar1 < 0xa0);
    *(undefined2 *)(DAT_02920970 + 0x90) = 9999;
    *(uint *)(DAT_02920970 + 0x114) = *(uint *)(DAT_02920970 + 0x114) | 0x10;
  }
  FUN_00624220(DAT_029209f8);
  DAT_029209f8 = 0;
  return;
}

