/* Ghidra analysis pseudocode, not original source.
 * ev_79d77eca71f7fc5404139f960d2da4bb199b6774aebfe9446502c31b4f71f31f
 * Entry: 0x552020; label: FUN_00552020
 */

undefined4 FUN_00552020(float *param_1,short *param_2,float *param_3,float *param_4,int param_5)

{
  float *pfVar1;
  undefined4 uVar2;
  float *pfVar3;
  undefined4 *puVar4;
  int iVar5;
  float *pfVar6;
  float fVar7;
  int iVar8;
  int iVar9;
  float fVar10;
  float fVar11;
  uint uVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float local_44;
  int local_3c;
  float local_30;
  float local_2c;
  float local_28;
  undefined4 local_24;
  float local_20;
  undefined4 local_1c;
  float local_18 [3];
  undefined4 local_c;
  float local_8;
  undefined4 local_4;
  
  local_44 = 1e+09;
  if ((param_1 == (float *)0x0) || (param_2 == (short *)0x0)) {
    return 0;
  }
  local_18[0] = *param_1;
  local_18[2] = param_1[1];
  local_30 = *param_1;
  local_28 = param_1[1];
  puVar4 = *(undefined4 **)(param_2 + 4);
  local_1c = puVar4[1];
  local_2c = -param_1[2];
  iVar9 = 1;
  uVar12 = 0;
  local_18[1] = 100000.0;
  local_20 = -(float)puVar4[2];
  if (1 < *param_2) {
    local_3c = 0xc;
    local_c = *puVar4;
    do {
      local_8 = local_20;
      puVar4 = (undefined4 *)(*(int *)(param_2 + 4) + local_3c);
      uVar2 = *puVar4;
      local_4 = local_1c;
      local_20 = -(float)puVar4[2];
      local_24 = uVar2;
      local_1c = puVar4[1];
      iVar5 = FUN_00550ff0(&local_30,local_18,&local_c,&local_24,0,0);
      local_3c = local_3c + 0xc;
      iVar9 = iVar9 + 1;
      uVar12 = uVar12 + iVar5;
      local_c = uVar2;
    } while (iVar9 < *param_2);
  }
  if (param_5 == 0) {
    if ((uVar12 & 1) == 0) {
LAB_00552177:
      pfVar3 = *(float **)(param_2 + 4);
      local_18[2] = pfVar3[2];
      fVar10 = *pfVar3;
      fVar13 = pfVar3[1];
      iVar5 = (int)*param_2;
      iVar9 = 0;
      iVar8 = 0;
      if (3 < iVar5 + -1) {
        pfVar6 = pfVar3 + 6;
        do {
          fVar15 = (pfVar6[-6] - *param_1) * (pfVar6[-6] - *param_1) +
                   (pfVar6[-4] - param_1[2]) * (pfVar6[-4] - param_1[2]);
          if (fVar15 < local_44) {
            local_18[2] = pfVar6[-4];
            fVar10 = pfVar6[-6];
            fVar13 = pfVar6[-5];
            iVar9 = iVar8;
            local_44 = fVar15;
          }
          fVar15 = (pfVar6[-3] - *param_1) * (pfVar6[-3] - *param_1) +
                   (pfVar6[-1] - param_1[2]) * (pfVar6[-1] - param_1[2]);
          if (fVar15 < local_44) {
            local_18[2] = pfVar6[-1];
            fVar10 = pfVar6[-3];
            fVar13 = pfVar6[-2];
            iVar9 = iVar8 + 1;
            local_44 = fVar15;
          }
          fVar15 = (*pfVar6 - *param_1) * (*pfVar6 - *param_1) +
                   (pfVar6[2] - param_1[2]) * (pfVar6[2] - param_1[2]);
          if (fVar15 < local_44) {
            local_18[2] = pfVar6[2];
            fVar10 = *pfVar6;
            fVar13 = pfVar6[1];
            iVar9 = iVar8 + 2;
            local_44 = fVar15;
          }
          fVar15 = (pfVar6[3] - *param_1) * (pfVar6[3] - *param_1) +
                   (pfVar6[5] - param_1[2]) * (pfVar6[5] - param_1[2]);
          if (fVar15 < local_44) {
            local_18[2] = pfVar6[5];
            fVar10 = pfVar6[3];
            fVar13 = pfVar6[4];
            iVar9 = iVar8 + 3;
            local_44 = fVar15;
          }
          iVar8 = iVar8 + 4;
          pfVar6 = pfVar6 + 0xc;
        } while (iVar8 < iVar5 + -4);
      }
      if (iVar8 < iVar5 + -1) {
        pfVar6 = pfVar3 + iVar8 * 3;
        do {
          fVar15 = (*pfVar6 - *param_1) * (*pfVar6 - *param_1) +
                   (pfVar6[2] - param_1[2]) * (pfVar6[2] - param_1[2]);
          if (fVar15 < local_44) {
            local_18[2] = pfVar6[2];
            fVar10 = *pfVar6;
            fVar13 = pfVar6[1];
            iVar9 = iVar8;
            local_44 = fVar15;
          }
          iVar8 = iVar8 + 1;
          pfVar6 = pfVar6 + 3;
        } while (iVar8 < iVar5 + -1);
      }
      if (iVar9 == 0) {
        iVar8 = 1;
        iVar5 = iVar5 + -2;
      }
      else if (iVar9 == iVar5 + -2) {
        iVar8 = 0;
        iVar5 = iVar5 + -3;
      }
      else {
        iVar8 = iVar9 + 1;
        iVar5 = iVar9 + -1;
      }
      pfVar6 = pfVar3 + iVar8 * 3;
      pfVar1 = pfVar3 + iVar5 * 3;
      if ((*pfVar1 - *param_1) * (*pfVar1 - *param_1) +
          (pfVar1[2] - param_1[2]) * (pfVar1[2] - param_1[2]) <=
          (pfVar3[iVar8 * 3] - *param_1) * (pfVar3[iVar8 * 3] - *param_1) +
          (pfVar6[2] - param_1[2]) * (pfVar6[2] - param_1[2])) {
        fVar15 = *pfVar1;
        fVar16 = pfVar1[1];
        fVar7 = pfVar1[2];
        fVar11 = fVar10;
        fVar14 = fVar13;
      }
      else {
        fVar7 = local_18[2];
        local_18[2] = pfVar6[2];
        fVar11 = *pfVar6;
        fVar14 = pfVar6[1];
        fVar15 = fVar10;
        fVar16 = fVar13;
      }
      if (param_3 != (float *)0x0) {
        *param_3 = fVar11;
        param_3[1] = fVar14;
        param_3[2] = local_18[2];
      }
      if (param_4 != (float *)0x0) {
        *param_4 = fVar15;
        param_4[1] = fVar16;
        param_4[2] = fVar7;
      }
      return 1;
    }
  }
  else if ((uVar12 & 1) != 0) goto LAB_00552177;
  return 0;
}

