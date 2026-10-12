/* Ghidra analysis pseudocode, not original source.
 * ev_101b67aa7badcd34fc3aca69d932f1af6fd7c0870f1a0aed34e591760076c155
 * Entry: 0x505f20; label: FUN_00505f20
 */

void FUN_00505f20(int param_1)

{
  byte *pbVar1;
  int iVar2;
  uint *puVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  uint uVar7;
  
  *(undefined4 *)(param_1 + 0x90) = 0x3f800000;
  *(uint *)(param_1 + 0x8c) = *(uint *)(param_1 + 0x8c) & 0xffffefff;
  *(undefined4 *)(param_1 + 0x94) = 0x3f800000;
  *(uint *)(param_1 + 0x88) = *(uint *)(param_1 + 0x88) & 0xffffeffe | 2;
  if (*(float *)(param_1 + 0x98) < 0.0) {
    *(float *)(param_1 + 0x98) = -*(float *)(param_1 + 0x98);
  }
  iVar2 = *(int *)(param_1 + 0x9c);
  if (iVar2 != 0) {
    puVar3 = *(uint **)(*(int *)(param_1 + 0x58) + 0x10);
    *(undefined1 *)(iVar2 + 8) = 0;
    *(char *)(iVar2 + 9) = (char)puVar3[4];
    *(undefined1 *)(iVar2 + 10) = 0;
    uVar7 = 0;
    if (*puVar3 != 0) {
      do {
        iVar4 = *(int *)(iVar2 + 4);
        pbVar1 = (byte *)(iVar4 + uVar7 * 4);
        *pbVar1 = *pbVar1 & 0xfd;
        iVar6 = uVar7 * 4;
        uVar7 = uVar7 + 1;
        *(undefined1 *)(iVar4 + iVar6 + 1) = 0;
      } while (uVar7 < *puVar3);
    }
  }
  if (*(int *)(param_1 + 0xa0) != 0) {
    FUN_005026f0(*(int *)(param_1 + 0xa0));
  }
  if (*(int *)(param_1 + 0xa8) != 0) {
    FUN_00501540(*(int *)(param_1 + 0xa8));
  }
  iVar2 = *(int *)(param_1 + 0xac);
  if (iVar2 != 0) {
    piVar5 = *(int **)(*(int *)(param_1 + 0x58) + 0x24);
    iVar6 = 0;
    if (0 < *piVar5) {
      do {
        *(undefined1 *)(*(int *)(iVar2 + 4) + iVar6 * 4) = 0;
        iVar6 = iVar6 + 1;
      } while (iVar6 < *piVar5);
    }
  }
  if ((*(short *)(param_1 + 0xd8) != 0) && (*(char *)(param_1 + 0xdf) == '\0')) {
    *(uint *)(param_1 + 0x88) = *(uint *)(param_1 + 0x88) | 0x40000000;
    *(uint *)(param_1 + 0x8c) = *(uint *)(param_1 + 0x8c) & 0xfffffffa | 10;
  }
  return;
}

