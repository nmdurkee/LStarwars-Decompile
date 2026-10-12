/* Ghidra pseudocode, not original source.
 * ev_57e4595202f6848139a561b6e4253d561eb3ad03e2f9632ed29ba9ff4f0bafc7
 * Entry: 0x59de40; label: FUN_0059de40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0059de40(undefined4 *param_1,byte *param_2)

{
  int *piVar1;
  ushort uVar2;
  ushort uVar3;
  int iVar4;
  bool bVar5;
  int iVar6;
  bool bVar7;
  int local_4;
  
  local_4 = 0;
  if (*param_2 != 0) {
    do {
      iVar4 = *(int *)(*(int *)(param_2 + 0x10) + local_4 * 4);
      uVar2 = *(ushort *)(iVar4 + 10);
      if ((uVar2 & 0x20) != 0) {
        iVar6 = 0;
        bVar5 = true;
        if (*(char *)(iVar4 + 2) != '\0') {
          do {
            if (!bVar5) goto LAB_0059df43;
            piVar1 = (int *)(*(int *)(iVar4 + 0x14) + iVar6 * 4);
            uVar3 = *(ushort *)(*piVar1 + 10);
            if ((uVar3 & 0xc0) == 0) {
              if ((uVar3 & 1) != 0) {
                bVar7 = (byte *)*piVar1 == param_2;
LAB_0059dead:
                if (!bVar7) goto LAB_0059deaf;
              }
            }
            else {
              if ((uVar3 & 2) != 0) {
                bVar7 = (uVar3 & 0x100) == 0;
                goto LAB_0059dead;
              }
LAB_0059deaf:
              bVar5 = false;
            }
            iVar6 = iVar6 + 1;
          } while (iVar6 < (int)(uint)*(byte *)(iVar4 + 2));
          if (!bVar5) goto LAB_0059df43;
        }
        if ((uVar2 & 8) == 0) {
          if ((uVar2 & 0x10) != 0) {
            piVar1 = *(int **)(iVar4 + 0xc);
            iVar6 = 0;
            if (0 < *piVar1) {
              do {
                FUN_0055a250(*param_1,**(undefined4 **)(piVar1[2] + iVar6 * 4),0,1);
                iVar6 = iVar6 + 1;
              } while (iVar6 < *piVar1);
            }
          }
        }
        else {
          piVar1 = *(int **)(iVar4 + 0xc);
          iVar6 = 0;
          if (0 < *piVar1) {
            do {
              FUN_0055a2b0(*param_1,**(undefined4 **)(piVar1[2] + iVar6 * 4),0,1);
              iVar6 = iVar6 + 1;
            } while (iVar6 < *piVar1);
          }
        }
        if ((*(ushort *)(iVar4 + 10) & 0x40) != 0) {
          *(ushort *)(iVar4 + 10) = *(ushort *)(iVar4 + 10) & 0xfeff;
          FUN_0059de40(param_1,iVar4);
        }
        *(ushort *)(iVar4 + 10) = *(ushort *)(iVar4 + 10) & 0xffdf;
      }
LAB_0059df43:
      local_4 = local_4 + 1;
    } while (local_4 < (int)(uint)*param_2);
  }
  return;
}

