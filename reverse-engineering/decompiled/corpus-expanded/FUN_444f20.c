/* Ghidra pseudocode, not original source.
 * ev_20f8c411b4261e575accf39560ead20e25095f356798bee204490bf31a6f5756
 * Entry: 0x444f20; label: FUN_00444f20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4
FUN_00444f20(undefined4 param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  float fVar4;
  bool bVar5;
  char cVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  int iVar10;
  int iVar11;
  float10 fVar12;
  float local_4c;
  int local_48;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  float local_34;
  float local_30;
  float local_2c;
  int aiStack_28 [10];
  
  local_4c = 0.0;
  iVar11 = 0;
  iVar10 = 0;
  local_48 = 0;
  if (param_6 != 0) {
    if (0 < param_5) {
      do {
        iVar7 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar11 * 4),"range=");
        if (iVar7 == 0) {
          iVar7 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar11 * 4),&DAT_0075772c);
          if (iVar7 == 0) {
            iVar7 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar11 * 4),"State=");
            if (iVar7 != 0) {
              local_48 = iVar7 + 6;
            }
          }
          else if ((((DAT_00923884 != (code *)0x0) && (DAT_00923894 != (code *)0x0)) &&
                   (cVar6 = (*DAT_00923884)(iVar7 + 5), cVar6 != -1)) &&
                  ((iVar7 = (*DAT_00923894)(cVar6), iVar7 != -1 && (iVar10 < 10)))) {
            aiStack_28[iVar10] = iVar7;
            iVar10 = iVar10 + 1;
          }
        }
        else {
          fVar12 = (float10)FUN_005147c0(param_2,iVar7 + 6);
          local_4c = (float)fVar12 * (float)fVar12;
        }
        iVar11 = iVar11 + 1;
      } while (iVar11 < param_5);
      if ((local_48 != 0) && ((0 < iVar10 || (0.0 < local_4c)))) {
        if ((param_3 != 0) &&
           ((piVar2 = *(int **)(param_3 + 0xd0), piVar2 != (int *)0x0 && (*piVar2 != 0)))) {
          iVar11 = *piVar2;
          local_40 = *(undefined4 *)(iVar11 + 0x80);
          local_3c = *(undefined4 *)(iVar11 + 0x84);
          local_38 = *(undefined4 *)(iVar11 + 0x88);
        }
        iVar11 = 0;
        if (DAT_0093d500 < 1) {
          return 1;
        }
        iVar7 = 0;
        do {
          uVar3 = *(uint *)(iVar7 + 0x1fc + DAT_0093d504);
          iVar1 = iVar7 + DAT_0093d504;
          if ((((uVar3 & 1) != 0) && ((uVar3 & 0x1000) != 0)) &&
             ((*(uint *)(iVar1 + 0x1f8) & 0x400) != 0)) {
            FUN_005b3800(&local_34,&local_40,iVar1 + 0x5c);
            fVar4 = local_2c * local_2c + local_34 * local_34 + local_30 * local_30;
            if (iVar10 == 0) {
              if (fVar4 < local_4c) {
                uVar9 = FUN_00512fc0(local_48,*(undefined4 *)(*(int *)(iVar1 + 4) + 4));
                *(undefined4 *)(*(int *)(iVar1 + 4) + 0x10) = uVar9;
              }
            }
            else {
              bVar5 = false;
              iVar8 = 0;
              if (0 < iVar10) {
                do {
                  if ((int)*(short *)(iVar1 + 0x1064) == aiStack_28[iVar8]) {
                    bVar5 = true;
                  }
                  iVar8 = iVar8 + 1;
                } while (iVar8 < iVar10);
                if ((bVar5) && (fVar4 < local_4c)) {
                  uVar9 = FUN_00512fc0(local_48,*(undefined4 *)(*(int *)(iVar1 + 4) + 4));
                  *(undefined4 *)(*(int *)(iVar1 + 4) + 0x10) = uVar9;
                }
              }
            }
          }
          iVar11 = iVar11 + 1;
          iVar7 = iVar7 + 0x10d8;
        } while (iVar11 < DAT_0093d500);
        return 1;
      }
    }
    uVar9 = FUN_00512fc0(local_48,*(undefined4 *)(param_2 + 4));
    *(undefined4 *)(param_2 + 0x10) = uVar9;
  }
  return 1;
}

