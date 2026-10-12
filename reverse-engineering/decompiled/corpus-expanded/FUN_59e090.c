/* Ghidra pseudocode, not original source.
 * ev_57e4595202f6848139a561b6e4253d561eb3ad03e2f9632ed29ba9ff4f0bafc7
 * Entry: 0x59e090; label: FUN_0059e090
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0059e090(undefined4 *param_1,byte *param_2,undefined4 param_3)

{
  ushort *puVar1;
  ushort uVar2;
  int *piVar3;
  int iVar4;
  ushort uVar5;
  int iVar6;
  byte bVar7;
  
  if ((param_2[0xb] & 1) != 0) {
    FUN_0059df70(param_1);
  }
  if ((param_2[10] & 1) == 0) {
    return;
  }
  iVar6 = (*(code *)(&PTR_FUN_00805518)[(uint)param_2[3] * 3])(param_1,param_2,param_3);
  if (iVar6 == 0) {
    return;
  }
  uVar2 = *(ushort *)(param_2 + 10);
  if (((uVar2 & 0x400) != 0) && ((uVar2 & 0x800) != 0)) {
    *(ushort *)(param_2 + 10) = uVar2 & 0xfbff;
  }
  uVar2 = *(ushort *)(param_2 + 10);
  uVar5 = uVar2 & 0xfffe | 0x802;
  *(ushort *)(param_2 + 10) = uVar5;
  if (param_2[3] == 0) {
    bVar7 = (byte)uVar5 >> 3;
    if (((bVar7 & 1) != 0) || ((uVar2 & 0x10) != 0)) {
      if (param_2[2] == 0) {
        piVar3 = *(int **)(param_2 + 0xc);
        if ((bVar7 & 1) == 0) {
          if (((uVar2 & 0x10) != 0) && (iVar6 = 0, 0 < *piVar3)) {
            do {
              FUN_0055a250(*param_1,**(undefined4 **)(piVar3[2] + iVar6 * 4),0,1);
              iVar6 = iVar6 + 1;
            } while (iVar6 < *piVar3);
          }
        }
        else {
          iVar6 = 0;
          if (0 < *piVar3) {
            do {
              FUN_0055a2b0(*param_1,**(undefined4 **)(piVar3[2] + iVar6 * 4),0,1);
              iVar6 = iVar6 + 1;
            } while (iVar6 < *piVar3);
            *(ushort *)(param_2 + 10) = *(ushort *)(param_2 + 10) & 0xffdf;
            goto LAB_0059e18f;
          }
        }
        *(ushort *)(param_2 + 10) = *(ushort *)(param_2 + 10) & 0xffdf;
      }
      else {
        *(ushort *)(param_2 + 10) = uVar2 & 0xfffe | 0x822;
      }
    }
LAB_0059e18f:
    if ((*(ushort *)(param_2 + 10) & 0xc0) != 0) {
      iVar6 = 0;
      *(ushort *)(param_2 + 10) = *(ushort *)(param_2 + 10) | 0x120;
      if (*param_2 != 0) {
        do {
          iVar4 = *(int *)(*(int *)(param_2 + 0x10) + iVar6 * 4);
          if (*(char *)(iVar4 + 3) == '\x01') {
            puVar1 = (ushort *)(iVar4 + 10);
            *puVar1 = *puVar1 | 0x200;
          }
          iVar4 = *(int *)(*(int *)(param_2 + 0x10) + iVar6 * 4);
          if ((*(char *)(iVar4 + 3) == '\0') && ((*(byte *)(iVar4 + 10) & 0x40) != 0)) {
            *(ushort *)(iVar4 + 10) = *(ushort *)(iVar4 + 10) | 0x100;
            puVar1 = (ushort *)(*(int *)(*(int *)(param_2 + 0x10) + iVar6 * 4) + 10);
            *puVar1 = *puVar1 | 0x20;
          }
          iVar6 = iVar6 + 1;
        } while (iVar6 < (int)(uint)*param_2);
      }
    }
    if (param_2[3] == 0) goto LAB_0059e20a;
  }
  FUN_0059de40(param_1,param_2);
LAB_0059e20a:
  iVar6 = 0;
  if (param_2[2] != 0) {
    do {
      puVar1 = (ushort *)(*(int *)(*(int *)(param_2 + 0x14) + iVar6 * 4) + 10);
      *puVar1 = *puVar1 | 1;
      iVar4 = *(int *)(*(int *)(param_2 + 0x14) + iVar6 * 4);
      if ((*(char *)(iVar4 + 8) != (char)param_3) || (param_2[3] == 1)) {
        *(char *)(iVar4 + 8) = (char)param_3;
        FUN_0059e090(param_1,*(undefined4 *)(*(int *)(param_2 + 0x14) + iVar6 * 4),param_3);
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < (int)(uint)param_2[2]);
  }
  return;
}

