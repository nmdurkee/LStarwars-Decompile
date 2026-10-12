/* Ghidra analysis pseudocode, not original source.
 * ev_619d50b6392102a54c9e38c540a3f8930ee6fdfe94aeb342acdefb90820d232e
 * Entry: 0x59f990; label: FUN_0059f990
 */

void FUN_0059f990(int param_1)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  
  iVar3 = DAT_00956608;
  if (((((*(byte *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x90) & 0x80) == 0) &&
       ((*(uint *)(param_1 + 0x1f8) & 0x4000) != 0)) &&
      ((*(uint *)(*(int *)(PTR_DAT_00802c54 + 0x128) + 100) & 0x100000) == 0)) &&
     ((uVar1 = *(undefined1 *)(*(int *)(PTR_DAT_00802c54 + 0x128) + 200), DAT_00956608 < 8 &&
      ((*(uint *)(param_1 + 0x1f8) & 0x400) != 0)))) {
    iVar5 = 0;
    if (0 < DAT_00956608) {
      piVar4 = &DAT_00956438;
      do {
        if (*piVar4 == param_1) {
          return;
        }
        iVar5 = iVar5 + 1;
        piVar4 = piVar4 + 0xb;
      } while (iVar5 < DAT_00956608);
    }
    iVar6 = iVar5 * 0x2c;
    (&DAT_00956438)[iVar5 * 0xb] = param_1;
    if ((*(int *)(param_1 + 0x2cc) != 0) &&
       (iVar2 = *(int *)(*(int *)(param_1 + 0x2cc) + 8), iVar2 != 0)) {
      FUN_004f1f40(&DAT_0095644c + iVar6,iVar2,0x10);
      iVar3 = DAT_00956608;
    }
    (&DAT_0095645c)[iVar5 * 0x16] = *(undefined2 *)(param_1 + 0x1064);
    DAT_00956608 = iVar3 + 1;
    (&DAT_0095645e)[iVar6] = *(undefined1 *)(param_1 + 0x400);
    (&DAT_0095645f)[iVar6] = uVar1;
    (&DAT_00956460)[iVar6] = uVar1;
  }
  return;
}

