/* Ghidra pseudocode, not original source.
 * ev_fe5af94714569ca149d7ee11beb07ec697c406bef5bd6833183fcd21241d309c
 * Entry: 0x51a890; label: FUN_0051a890
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_0051a890(int param_1,uint param_2,uint param_3,int param_4,uint param_5)

{
  byte bVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  ushort uVar6;
  undefined4 uVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  float10 extraout_ST0;
  float10 fVar12;
  float10 fVar13;
  float *local_20;
  float local_1c;
  undefined4 *local_18;
  float local_14;
  float local_10;
  
  fVar13 = (float10)0;
  local_1c = (float)fVar13;
  local_10 = 0.0;
  local_18 = (undefined4 *)0x0;
  local_20 = (float *)0x0;
  if (*(int *)(param_1 + 0x84) == 0) {
    return (float10)3.4028235e+38;
  }
  if (param_2 == param_3) {
    return fVar13;
  }
  iVar9 = param_3 * 0x5c + *(int *)(param_1 + 0x7c);
  iVar10 = param_2 * 0x5c + *(int *)(param_1 + 0x7c);
  if ((param_5 == 0) && (param_4 == 0xff)) {
    if (*(byte *)(iVar10 + 0x2e) == param_3) {
      return (float10)*(float *)(iVar10 + 0x38);
    }
    if (*(byte *)(iVar10 + 0x2f) == param_3) {
      return (float10)*(float *)(iVar10 + 0x3c);
    }
    *(byte *)(iVar10 + 0x2f) = *(byte *)(iVar10 + 0x2e);
    local_20 = (float *)(iVar10 + 0x38);
    *(undefined4 *)(iVar10 + 0x3c) = *(undefined4 *)(iVar10 + 0x38);
    *(char *)(iVar10 + 0x2e) = (char)param_3;
    *local_20 = (float)fVar13;
  }
  iVar3 = *(int *)(param_1 + 0x7c);
  uVar11 = (iVar10 - iVar3) / 0x5c;
  if (param_4 != 0xff) {
    local_18 = (undefined4 *)(*(int *)(param_1 + 0x88) + param_4 * 0x28);
    uVar2 = *(ushort *)(iVar10 + 0x58);
    uVar6 = __allshl();
    if ((uVar2 & uVar6) == 0) {
LAB_0051abdb:
      return (float10)3.4028235e+38;
    }
  }
  do {
    puVar5 = local_18;
    if (iVar10 == iVar9) goto LAB_0051abed;
    if (local_18 == (undefined4 *)0x0) {
      bVar1 = *(byte *)(*(int *)(*(int *)(param_1 + 0x84) + uVar11 * 4) + param_3);
    }
    else {
      uVar2 = *(ushort *)(iVar9 + 0x58);
      uVar6 = __allshl();
      if ((uVar2 & uVar6) == 0) {
        iVar9 = 0;
        local_14 = 3.4028235e+38;
        if (*(char *)((int)local_18 + 0x11) != '\0') {
          uVar7 = __allshl();
          fVar13 = extraout_ST0;
          do {
            fVar12 = fVar13;
            if (*(byte *)(puVar5[3] + iVar9) != param_2) {
              fVar12 = (float10)FUN_0051a890(param_1,param_2,(uint)*(byte *)(puVar5[3] + iVar9),
                                             param_4,0);
              fVar13 = (float10)0;
            }
            local_10 = (float)fVar12;
            fVar12 = fVar13;
            if (*(byte *)(puVar5[3] + iVar9) != param_3) {
              fVar12 = (float10)FUN_0051a890(param_1,(uint)*(byte *)(puVar5[3] + iVar9),param_3,0xff
                                             ,uVar7);
              fVar13 = (float10)0;
            }
            local_18 = (undefined4 *)(float)fVar12;
            if ((local_10 == 3.4028235e+38) || ((float)local_18 == 3.4028235e+38)) {
              local_10 = 3.4028235e+38;
            }
            else {
              local_10 = (float)local_18 + local_10;
            }
            if (local_10 < local_14) {
              local_14 = local_10;
            }
            iVar9 = iVar9 + 1;
          } while (iVar9 < (int)(uint)*(byte *)((int)puVar5 + 0x11));
        }
        fVar13 = (float10)3.4028235e+38;
        if (local_14 != 3.4028235e+38) {
          local_1c = local_14 + local_1c;
LAB_0051abed:
          fVar13 = (float10)local_1c;
        }
LAB_0051abf1:
        if (local_20 == (float *)0x0) {
          return fVar13;
        }
        *local_20 = (float)fVar13;
        return fVar13;
      }
      iVar4 = local_18[1];
      if ((*(byte *)(local_18 + 4) <= *(byte *)(iVar4 + uVar11)) ||
         (*(byte *)(local_18 + 4) <= *(byte *)(iVar4 + param_3))) {
        FUN_00512860(*local_18,uVar11,param_3);
        fVar13 = (float10)3.4028235e+38;
        goto LAB_0051abf1;
      }
      bVar1 = *(byte *)(*(int *)(local_18[5] + (uint)*(byte *)(iVar4 + uVar11) * 4) +
                       (uint)*(byte *)(iVar4 + param_3));
    }
    if (bVar1 == 0xff) {
LAB_0051abd1:
      fVar13 = (float10)3.4028235e+38;
      goto LAB_0051abf1;
    }
    iVar4 = *(int *)(*(int *)(iVar10 + 0x34) + (uint)bVar1 * 4);
    if (iVar4 == 0) goto LAB_0051abdb;
    if ((param_5 & *(ushort *)(iVar4 + 0x14)) != 0) goto LAB_0051abd1;
    if (local_10 == (float)iVar4) goto LAB_0051abed;
    uVar8 = (uint)*(byte *)(iVar4 + 0x10);
    if (uVar11 == uVar8) {
      uVar8 = (uint)*(byte *)(iVar4 + 0x11);
    }
    local_1c = *(float *)(iVar4 + 0x18) + local_1c;
    iVar10 = uVar8 * 0x5c + iVar3;
    uVar11 = uVar8;
    local_10 = (float)iVar4;
  } while( true );
}

