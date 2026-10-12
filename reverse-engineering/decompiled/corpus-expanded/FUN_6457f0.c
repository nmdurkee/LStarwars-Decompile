/* Ghidra pseudocode, not original source.
 * ev_e99a99ac40850efc4319cfa1070f50eca7ba45fd57a73000da90cd7b4a6a9b3b
 * Entry: 0x6457f0; label: FUN_006457f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006457f0(undefined4 param_1,int param_2)

{
  int iVar1;
  short *psVar2;
  int iVar3;
  
  if (DAT_02920970 != 0) {
    if (*(int *)(param_2 + 0xc) == 9999) {
      iVar3 = 0;
      iVar1 = 0x90;
      do {
        *(undefined2 *)(iVar1 + DAT_02920970) = 0xffff;
        *(undefined1 *)(DAT_02920970 + 0xa0 + iVar3) = 1;
        iVar1 = iVar1 + 2;
        iVar3 = iVar3 + 1;
      } while (iVar1 < 0xa0);
      if ((*(byte *)(param_2 + 0x11) & 1) != 0) {
        *(undefined2 *)(DAT_02920970 + 0x90) = 9999;
      }
      *(uint *)(DAT_02920970 + 0x114) = *(uint *)(DAT_02920970 + 0x114) | 0x10;
      *(undefined1 *)(DAT_02920970 + 0xb0) = 0;
      return;
    }
    *(byte *)(DAT_02920a88 + 0x11) = *(byte *)(DAT_02920a88 + 0x11) & 0xfe;
    if ((*(byte *)(param_2 + 0x11) & 1) != 0) {
      if (*(char *)(DAT_02920970 + 0xb0) < '\b') {
        *(undefined2 *)(DAT_02920970 + 0x90 + *(char *)(DAT_02920970 + 0xb0) * 2) =
             *(undefined2 *)(param_2 + 0xc);
        *(undefined1 *)(*(char *)(DAT_02920970 + 0xb0) + 0xa0 + DAT_02920970) = DAT_008101a4;
        *(char *)(DAT_02920970 + 0xb0) = *(char *)(DAT_02920970 + 0xb0) + '\x01';
        return;
      }
      *(byte *)(param_2 + 0x11) = *(byte *)(param_2 + 0x11) & 0xfe;
      return;
    }
    iVar1 = 0;
    psVar2 = (short *)(DAT_02920970 + 0x90);
    while ((int)*psVar2 != *(int *)(param_2 + 0xc)) {
      iVar1 = iVar1 + 1;
      psVar2 = psVar2 + 1;
      if (7 < iVar1) {
        return;
      }
    }
    if (iVar1 < 7) {
      iVar3 = iVar1 * 2 + 0x90;
      do {
        *(undefined2 *)(iVar3 + DAT_02920970) = *(undefined2 *)(iVar3 + 2 + DAT_02920970);
        *(undefined1 *)(DAT_02920970 + 0xa0 + iVar1) = *(undefined1 *)(DAT_02920970 + 0xa1 + iVar1);
        iVar3 = iVar3 + 2;
        iVar1 = iVar1 + 1;
      } while (iVar3 < 0x9e);
    }
    *(undefined2 *)(DAT_02920970 + 0x9e) = 0xffff;
    *(undefined1 *)(DAT_02920970 + 0xa7) = 0xff;
    *(char *)(DAT_02920970 + 0xb0) = *(char *)(DAT_02920970 + 0xb0) + -1;
  }
  return;
}

