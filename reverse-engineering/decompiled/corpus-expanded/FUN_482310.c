/* Ghidra pseudocode, not original source.
 * ev_6d95b912f1db8f5f9ae5a1d448774b8e294221a9d492d15be8ca5acea434db46
 * Entry: 0x482310; label: FUN_00482310
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00482310(int param_1,float *param_2,float *param_3,float *param_4,short *param_5)

{
  float *pfVar1;
  short sVar2;
  bool bVar3;
  ushort uVar4;
  float fVar5;
  int iVar6;
  short sVar7;
  int iVar8;
  int iVar9;
  float10 fVar10;
  float local_58;
  float local_54;
  int local_48;
  int local_44;
  int local_3c;
  float local_30 [4];
  undefined4 local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  iVar8 = *(int *)(param_1 + 0x50a8);
  if (iVar8 != 0) {
    local_58 = 100000.0;
    local_48 = 0;
    local_54 = 100000.0;
    local_44 = 0;
    sVar7 = 0;
    sVar2 = 0;
    local_3c = 0;
    if (0 < *(int *)(param_1 + 0x50ac)) {
      do {
        if (((((*(byte *)(iVar8 + 0x17) & 2) != 0) && ((*(byte *)(iVar8 + 0x17) & 1) != 0)) &&
            (((*(byte *)(iVar8 + 0x19) & 1) == 0 || (DAT_0087baf0 != 0)))) &&
           (((((*param_3 <= *(float *)(iVar8 + 0x2c) && (*(float *)(iVar8 + 0x20) <= *param_4)) &&
              (param_3[2] <= *(float *)(iVar8 + 0x34))) &&
             ((*(float *)(iVar8 + 0x28) <= param_4[2] && (param_3[1] <= *(float *)(iVar8 + 0x30)))))
            && (*(float *)(iVar8 + 0x24) <= param_4[1])))) {
          local_30[0] = *param_2 - *(float *)(iVar8 + 8);
          iVar9 = (uint)*(byte *)(iVar8 + 0x18) * 0x20;
          local_30[1] = 0.0;
          local_30[2] = param_2[2] - *(float *)(iVar8 + 0x10);
          FUN_005b3620(local_30,local_30,-(uint)*(ushort *)(iVar8 + 0x14));
          bVar3 = false;
          pfVar1 = (float *)(&DAT_007fa37c + iVar9);
          if ((&DAT_007fa37b)[iVar9] == '\0') {
            uVar4 = FUN_005be2d0(local_30[0] - *pfVar1,
                                 local_30[2] - *(float *)(&DAT_007fa390 + iVar9));
            iVar6 = FUN_00550040(*(undefined2 *)(&DAT_007fa396 + iVar9),(uint)uVar4);
            if (iVar6 + 0x2000U < 0x4001) {
              local_30[3] = (float)(&DAT_029899a0)[uVar4 >> 1] * ABS(*pfVar1) + *pfVar1;
              local_20 = 0;
              local_1c = (float)(&DAT_029899a0)[(int)(uVar4 + 0x4000) >> 1 & 0x7fff] * ABS(*pfVar1)
                         + *(float *)(&DAT_007fa390 + iVar9);
              fVar10 = (float10)FUN_005becc0(local_30,local_30 + 3,0);
              fVar5 = (float)fVar10;
              if (fVar5 < local_58) {
                FUN_005b3620(local_30,local_30 + 3,*(undefined2 *)(iVar8 + 0x14));
                FUN_005b37d0(&local_18,local_30,iVar8 + 8);
                sVar7 = *(short *)(iVar8 + 0x14) + uVar4;
                local_58 = fVar5;
                local_48 = iVar8;
                if (0x8000 < *(ushort *)(&DAT_007fa394 + iVar9)) {
                  sVar7 = sVar7 + -0x8000;
                }
              }
            }
            else {
              bVar3 = true;
LAB_00482636:
              fVar10 = (float10)FUN_005b3c50(local_30,pfVar1,0);
              if ((float)fVar10 < local_54) {
                FUN_005b3620(local_30,pfVar1,*(undefined2 *)(iVar8 + 0x14));
                FUN_005b37d0(&local_c,local_30,iVar8 + 8);
                sVar2 = *(short *)(iVar8 + 0x14);
                local_54 = (float)fVar10;
                local_44 = iVar8;
              }
              if (bVar3) goto LAB_0048269c;
            }
          }
          else if ((*pfVar1 < local_30[0] == (*pfVar1 == local_30[0])) ||
                  (*(float *)(&DAT_007fa388 + iVar9) < local_30[0])) {
            if (local_30[0] < *pfVar1) goto LAB_00482636;
LAB_0048269c:
            fVar10 = (float10)FUN_005b3c50(local_30,&DAT_007fa388 + iVar9,0);
            fVar5 = (float)fVar10;
            if (fVar5 < local_54) {
              FUN_005b3620(local_30,&DAT_007fa388 + iVar9,*(undefined2 *)(iVar8 + 0x14));
              FUN_005b37d0(&local_c,local_30,iVar8 + 8);
              sVar2 = *(short *)(iVar8 + 0x14);
              local_54 = fVar5;
              local_44 = iVar8;
              if ((&DAT_007fa37b)[iVar9] == '\0') {
                sVar2 = sVar2 + *(short *)(&DAT_007fa394 + iVar9);
              }
            }
          }
          else {
            fVar5 = ABS(local_30[2]);
            if (fVar5 < local_58) {
              local_30[2] = 0.0;
              FUN_005b3620(local_30,local_30,*(undefined2 *)(iVar8 + 0x14));
              FUN_005b37d0(&local_18,local_30,iVar8 + 8);
              sVar7 = *(short *)(iVar8 + 0x14);
              local_58 = fVar5;
              local_48 = iVar8;
            }
          }
        }
        local_3c = local_3c + 1;
        iVar8 = iVar8 + 0x38;
      } while (local_3c < *(int *)(param_1 + 0x50ac));
      if (local_48 != 0) {
        *param_2 = local_18;
        param_2[1] = local_14;
        param_2[2] = local_10;
        *param_5 = sVar7;
        return local_48;
      }
      if (local_44 != 0) {
        *param_2 = local_c;
        param_2[1] = local_8;
        param_2[2] = local_4;
        *param_5 = sVar2;
        return local_44;
      }
    }
  }
  return 0;
}

