/* Ghidra analysis pseudocode, not original source.
 * ev_411dd83ba30300d5831318e5e0d5db9024421d970d639e52cbaaaf14146f88dc
 * Entry: 0x6a5a20; label: FUN_006a5a20
 */

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */

void FUN_006a5a20(int param_1,uint *param_2,float *param_3,int param_4,float param_5,int param_6)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  uint uVar6;
  float fVar7;
  undefined1 *puVar8;
  float *pfVar9;
  float *pfVar10;
  float fVar11;
  int iVar12;
  float *pfVar13;
  float *pfVar14;
  uint uVar15;
  int iVar16;
  int iVar17;
  float *pfVar18;
  undefined4 uStack_94;
  undefined8 local_84;
  undefined8 local_7c;
  undefined8 local_74;
  int local_6c;
  int local_68;
  int local_64;
  int local_60;
  undefined1 *local_5c;
  int local_58;
  float *local_54;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  float *local_3c;
  float *local_38;
  float *local_30;
  float *local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  int local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  
  fVar7 = param_5;
  iVar17 = param_1 * -4;
  (&uStack_94)[-param_1] = 0x6a5a43;
  (&uStack_94)[param_1 * -2] = 0x6a5a4c;
  (&uStack_94)[param_1 * -3] = 0x6a5a5a;
  local_54 = (float *)(&stack0xffffff70 + param_1 * -0x10);
  (&uStack_94)[param_1 * -4] = 0x6a5a69;
  pfVar18 = local_54;
  local_28 = 0.0;
  local_24 = 0.0;
  local_20 = 1.0;
  local_10 = 0.0;
  local_14 = 0.0;
  local_c = *param_3 + param_5;
  if (local_c < 1.0) {
    local_c = 1.0;
  }
  fVar3 = local_c;
  local_18 = 1;
  fVar2 = local_c * local_c * 0.5;
  fVar1 = fVar2 + 0.0;
  local_1c = fVar1;
  local_c = fVar1;
  local_8 = fVar2 * fVar3 + 0.0;
  *(float *)(&stack0xffffff70 + iVar17) = fVar1;
  *(float *)(&stack0xffffff70 + param_1 * -8) = local_c;
  *(undefined4 *)(&stack0xffffff70 + param_1 * -0xc) = 0;
  *local_54 = local_8;
  *(undefined4 *)(&stack0xffffff70 + param_1 * -0x14) = 0;
  param_5 = 1.0;
  if (3 < param_1 + -1) {
    local_38 = local_54 + 1;
    local_3c = (float *)((int)&local_84 + param_1 * -0xc + 4);
    local_30 = (float *)(&local_84 + -param_1);
    local_2c = (float *)(&stack0xffffff78 + iVar17);
    local_40 = (int)param_3 - (int)(&stack0xffffff70 + iVar17);
    local_44 = iVar17;
    local_48 = param_1 * -8;
    local_4c = (int)local_54 - (int)(&stack0xffffff70 + iVar17);
    local_50 = param_1 * -0x10;
    local_60 = (int)param_3 - (int)(&stack0xffffff70 + param_1 * -8);
    local_64 = iVar17;
    local_68 = (int)local_54 - (int)(&stack0xffffff70 + param_1 * -8);
    local_6c = param_1 * -0xc;
    local_74._4_4_ = (int)param_3 - (int)(&stack0xffffff70 + param_1 * -0xc);
    local_7c._4_4_ = (int)local_54 - (int)(&stack0xffffff70 + param_1 * -0xc);
    local_84 = (double)CONCAT44(param_1 * -8,(undefined4)local_84);
    local_58 = (int)param_3 - (int)local_54;
    iVar12 = param_1 * -0x14 - (int)local_54;
    local_54 = (float *)((param_1 - 5U >> 2) + 1);
    local_5c = &stack0xffffff70 + iVar12;
    local_18 = (int)local_54 * 4 + 1;
    fVar2 = local_c;
    do {
      pfVar14 = local_38;
      local_c = *(float *)(local_58 + (int)local_38) + fVar7;
      if (local_c < 1.0) {
        local_c = 1.0;
      }
      fVar4 = local_c * local_c;
      fVar3 = param_5 * fVar4;
      local_14 = fVar3 * param_5 + local_14;
      local_8 = local_8 + fVar4 * local_c;
      local_10 = fVar3 * local_c + local_10;
      local_c = fVar2 + fVar3;
      local_2c[-1] = fVar1 + fVar4;
      fVar2 = local_c;
      local_30[-2] = local_c;
      local_3c[-3] = local_14;
      puVar8 = local_5c;
      *pfVar14 = local_8;
      pfVar9 = local_2c;
      iVar12 = local_44;
      *(float *)(puVar8 + (int)pfVar14) = local_10;
      param_5 = param_5 + 1.0;
      local_c = *(float *)(local_40 + (int)local_2c) + fVar7;
      if (local_c < 1.0) {
        local_c = 1.0;
      }
      fVar5 = local_c * local_c;
      fVar1 = fVar1 + fVar4 + fVar5;
      fVar3 = param_5 * fVar5;
      local_14 = fVar3 * param_5 + local_14;
      local_8 = local_8 + fVar5 * local_c;
      local_10 = fVar3 * local_c + local_10;
      local_c = fVar2 + fVar3;
      *local_2c = fVar1;
      fVar2 = local_c;
      pfVar14 = local_30;
      *(float *)(iVar12 + (int)pfVar9) = local_c;
      *(float *)(local_48 + (int)pfVar9) = local_14;
      *(float *)(local_4c + (int)pfVar9) = local_8;
      *(float *)(local_50 + (int)pfVar9) = local_10;
      param_5 = param_5 + 1.0;
      local_c = *(float *)(local_60 + (int)local_30) + fVar7;
      if (local_c < 1.0) {
        local_c = 1.0;
      }
      fVar4 = local_c * local_c;
      fVar1 = fVar1 + fVar4;
      fVar3 = param_5 * fVar4;
      local_14 = fVar3 * param_5 + local_14;
      local_8 = local_8 + fVar4 * local_c;
      local_10 = fVar3 * local_c + local_10;
      local_c = fVar2 + fVar3;
      local_2c[1] = fVar1;
      fVar2 = local_c;
      iVar12 = local_64;
      *pfVar14 = local_c;
      pfVar10 = local_2c;
      pfVar9 = local_3c;
      *(float *)(iVar12 + (int)pfVar14) = local_14;
      *(float *)(local_68 + (int)pfVar14) = local_8;
      *(float *)(local_6c + (int)pfVar14) = local_10;
      param_5 = param_5 + 1.0;
      local_c = *(float *)(local_74._4_4_ + (int)local_3c) + fVar7;
      if (local_c < 1.0) {
        local_c = 1.0;
      }
      fVar5 = local_c;
      local_2c = local_2c + 4;
      fVar4 = local_c * local_c;
      local_38 = local_38 + 4;
      pfVar13 = local_3c + 4;
      local_3c = pfVar13;
      fVar1 = fVar1 + fVar4;
      local_1c = fVar1;
      fVar3 = param_5 * fVar4;
      local_c = fVar2 + fVar3;
      local_14 = fVar3 * param_5 + local_14;
      local_8 = local_8 + fVar4 * fVar5;
      local_10 = fVar3 * fVar5 + local_10;
      pfVar10[2] = fVar1;
      iVar12 = (int)local_54 + -1;
      local_54 = (float *)iVar12;
      pfVar14 = local_30 + 1;
      local_30 = local_30 + 4;
      *pfVar14 = local_c;
      iVar16 = local_7c._4_4_;
      *pfVar9 = local_14;
      *(float *)(iVar16 + -0x10 + (int)pfVar13) = local_8;
      *(float *)(local_84._4_4_ + -0x10 + (int)pfVar13) = local_10;
      param_5 = param_5 + 1.0;
      fVar2 = local_c;
    } while (iVar12 != 0);
  }
  if (local_18 < param_1) {
    local_84 = (double)CONCAT44(&stack0xffffff70 + local_18 * 4 + iVar17,(undefined4)local_84);
    iVar12 = (int)param_3 - (int)(&stack0xffffff70 + iVar17);
    local_40 = iVar12;
    local_44 = iVar17;
    local_48 = param_1 * -8;
    local_4c = (int)pfVar18 - (int)(&stack0xffffff70 + iVar17);
    local_50 = param_1 * -0x10;
    param_3 = (float *)(param_1 - local_18);
    pfVar14 = (float *)(&stack0xffffff70 + local_18 * 4 + iVar17);
    fVar1 = local_c;
    do {
      local_c = *(float *)((int)pfVar14 + iVar12) + fVar7;
      if (local_c < 1.0) {
        local_c = 1.0;
      }
      fVar11 = local_c;
      param_3 = (float *)((int)param_3 + -1);
      fVar4 = local_c * local_c;
      local_1c = local_1c + fVar4;
      fVar3 = param_5 * fVar4;
      local_c = fVar1 + fVar3;
      fVar2 = fVar3 * param_5 + local_14;
      local_14 = fVar2;
      fVar5 = local_8 + fVar4 * fVar11;
      local_8 = fVar5;
      fVar4 = fVar3 * fVar11 + local_10;
      local_10 = fVar4;
      *pfVar14 = local_1c;
      pfVar14[-param_1] = fVar1 + fVar3;
      pfVar14[param_1 * -2] = fVar2;
      *(float *)((int)pfVar14 + ((int)pfVar18 - (int)(&stack0xffffff70 + iVar17))) = fVar5;
      pfVar14[param_1 * -4] = fVar4;
      param_5 = param_5 + 1.0;
      pfVar14 = pfVar14 + 1;
      fVar1 = local_c;
    } while (param_3 != (float *)0x0);
  }
  uVar15 = *param_2;
  param_5 = 0.0;
  iVar12 = (int)uVar15 >> 0x10;
  local_18 = 0;
  if (iVar12 < 0) {
    local_30 = (float *)0x0;
    do {
      uVar15 = uVar15 & 0xffff;
      iVar16 = iVar12 * -4;
      local_1c = *(float *)(&stack0xffffff70 + uVar15 * 4 + iVar17) +
                 *(float *)(&stack0xffffff70 + iVar16 + iVar17);
      local_c = *(float *)(&stack0xffffff70 + uVar15 * 4 + param_1 * -8) -
                *(float *)(&stack0xffffff70 + iVar16 + param_1 * -8);
      local_14 = *(float *)(&stack0xffffff70 + uVar15 * 4 + param_1 * -0xc) +
                 *(float *)(&stack0xffffff70 + iVar16 + param_1 * -0xc);
      local_8 = pfVar18[uVar15] + pfVar18[-iVar12];
      local_10 = *(float *)(&stack0xffffff70 + uVar15 * 4 + param_1 * -0x14) -
                 *(float *)(&stack0xffffff70 + iVar16 + param_1 * -0x14);
      local_84 = (double)local_10;
      local_28 = local_14 * local_8 - local_10 * local_c;
      local_24 = local_10 * local_1c - local_8 * local_c;
      local_20 = local_14 * local_1c - local_c * local_c;
      param_3 = (float *)((local_28 + local_24 * param_5) / local_20);
      if ((float)param_3 < 0.0) {
        param_3 = (float *)0x0;
      }
      *(float *)((int)local_30 + param_4) = (float)param_3 - fVar7;
      local_18 = local_18 + 1;
      param_5 = param_5 + 1.0;
      uVar15 = param_2[local_18];
      local_30 = (float *)(local_18 * 4);
      iVar12 = (int)uVar15 >> 0x10;
    } while (iVar12 < 0);
  }
  local_30 = (float *)(local_18 * 4);
  uVar15 = param_2[local_18];
  while (uVar6 = uVar15 & 0xffff, (int)uVar6 < param_1) {
    param_3 = (float *)((int)uVar15 >> 0x10);
    local_1c = *(float *)(&stack0xffffff70 + uVar6 * 4 + iVar17) -
               *(float *)(&stack0xffffff70 + (int)param_3 * 4 + iVar17);
    local_c = *(float *)(&stack0xffffff70 + uVar6 * 4 + param_1 * -8) -
              *(float *)(&stack0xffffff70 + (int)param_3 * 4 + param_1 * -8);
    local_14 = *(float *)(&stack0xffffff70 + uVar6 * 4 + param_1 * -0xc) -
               *(float *)(&stack0xffffff70 + (int)param_3 * 4 + param_1 * -0xc);
    local_8 = pfVar18[uVar6] - pfVar18[(int)param_3];
    local_10 = *(float *)(&stack0xffffff70 + uVar6 * 4 + param_1 * -0x14) -
               *(float *)(&stack0xffffff70 + (int)param_3 * 4 + param_1 * -0x14);
    local_84 = (double)local_10;
    local_28 = local_14 * local_8 - local_10 * local_c;
    local_24 = local_10 * local_1c - local_8 * local_c;
    local_20 = local_14 * local_1c - local_c * local_c;
    param_3 = (float *)((local_28 + local_24 * param_5) / local_20);
    if ((float)param_3 < 0.0) {
      param_3 = (float *)0x0;
    }
    *(float *)((int)local_30 + param_4) = (float)param_3 - fVar7;
    local_18 = local_18 + 1;
    param_5 = param_5 + 1.0;
    local_30 = (float *)(local_18 * 4);
    uVar15 = param_2[local_18];
  }
  if (local_18 < param_1) {
    local_84 = (double)local_24;
    local_7c = (double)local_28;
    local_74 = (double)local_20;
    do {
      param_3 = (float *)((local_24 * param_5 + local_28) / local_20);
      if ((float)param_3 < 0.0) {
        param_3 = (float *)0x0;
      }
      local_18 = local_18 + 1;
      *(float *)(param_4 + -4 + local_18 * 4) = (float)param_3 - fVar7;
      param_5 = param_5 + 1.0;
    } while (local_18 < param_1);
  }
  if (param_6 < 1) {
    return;
  }
  param_5 = 0.0;
  iVar12 = param_6 / 2;
  local_18 = 0;
  if (iVar12 - param_6 < 0) {
    local_84 = (double)CONCAT44(iVar12 * 4,(undefined4)local_84);
    local_4c = iVar12 - param_6;
    local_50 = iVar12 * 4;
    iVar16 = (iVar12 - param_6) * -4;
    local_54 = (float *)((param_6 - iVar12) * 4);
    do {
      local_1c = *(float *)(&stack0xffffff70 + iVar16 + iVar17) +
                 *(float *)(&stack0xffffff70 + local_50 + iVar17);
      local_c = *(float *)(&stack0xffffff70 + local_50 + param_1 * -8) -
                *(float *)(&stack0xffffff70 + iVar16 + param_1 * -8);
      local_14 = *(float *)(&stack0xffffff70 + iVar16 + param_1 * -0xc) +
                 *(float *)(&stack0xffffff70 + local_50 + param_1 * -0xc);
      local_8 = *(float *)(iVar16 + (int)pfVar18) + *(float *)(local_50 + (int)pfVar18);
      local_10 = *(float *)(&stack0xffffff70 + local_50 + param_1 * -0x14) -
                 *(float *)(&stack0xffffff70 + iVar16 + param_1 * -0x14);
      local_28 = local_14 * local_8 - local_10 * local_c;
      local_24 = local_10 * local_1c - local_8 * local_c;
      local_20 = local_14 * local_1c - local_c * local_c;
      fVar1 = (local_28 + local_24 * param_5) / local_20 - fVar7;
      if (fVar1 < *(float *)(param_4 + local_18 * 4)) {
        *(float *)(param_4 + local_18 * 4) = fVar1;
      }
      local_50 = local_50 + 4;
      param_5 = param_5 + 1.0;
      local_18 = local_18 + 1;
      iVar16 = (int)local_54 + -4;
      local_4c = local_4c + 1;
      local_54 = (float *)iVar16;
    } while (local_4c < 0);
  }
  local_50 = local_18 + iVar12;
  local_84 = (double)CONCAT44(local_50,(undefined4)local_84);
  if (local_50 < param_1) {
    param_3 = (float *)((local_50 - param_6) * 4);
    local_54 = (float *)(local_50 * 4);
    local_4c = local_50 * 4;
    param_2 = (uint *)(((iVar12 - param_6) + local_18) * 4);
    do {
      local_1c = *(float *)(&stack0xffffff70 + local_4c + iVar17) -
                 *(float *)(&stack0xffffff70 + (int)param_3 + iVar17);
      local_c = *(float *)(&stack0xffffff70 + local_4c + param_1 * -8) -
                *(float *)(&stack0xffffff70 + (int)param_3 + param_1 * -8);
      local_14 = *(float *)(&stack0xffffff70 + local_4c + param_1 * -0xc) -
                 *(float *)(&stack0xffffff70 + (int)param_3 + param_1 * -0xc);
      local_8 = *(float *)(local_4c + (int)pfVar18) - *(float *)((int)param_3 + (int)pfVar18);
      local_10 = *(float *)(&stack0xffffff70 + local_4c + param_1 * -0x14) -
                 *(float *)(&stack0xffffff70 + (int)param_3 + param_1 * -0x14);
      local_28 = local_14 * local_8 - local_10 * local_c;
      local_24 = local_10 * local_1c - local_8 * local_c;
      local_20 = local_14 * local_1c - local_c * local_c;
      fVar1 = (local_28 + local_24 * param_5) / local_20 - fVar7;
      if (fVar1 < *(float *)(param_4 + local_18 * 4)) {
        *(float *)(param_4 + local_18 * 4) = fVar1;
      }
      param_2 = (uint *)((int)param_2 + 4);
      param_5 = param_5 + 1.0;
      local_18 = local_18 + 1;
      local_50 = local_50 + 1;
      local_54 = (float *)(local_4c + 4);
      local_4c = local_4c + 4;
      param_3 = (float *)param_2;
    } while (local_50 < param_1);
  }
  iVar17 = local_18;
  if (3 < param_1 - local_18) {
    iVar12 = ((param_1 - local_18) - 4U >> 2) + 1;
    iVar17 = local_18 + iVar12 * 4;
    pfVar18 = (float *)(param_4 + 8 + local_18 * 4);
    do {
      fVar1 = (local_24 * param_5 + local_28) / local_20 - fVar7;
      if (fVar1 < pfVar18[-2]) {
        pfVar18[-2] = fVar1;
      }
      fVar1 = (local_24 * (param_5 + 1.0) + local_28) / local_20 - fVar7;
      if (fVar1 < pfVar18[-1]) {
        pfVar18[-1] = fVar1;
      }
      param_5 = param_5 + 1.0 + 1.0;
      fVar1 = (local_24 * param_5 + local_28) / local_20 - fVar7;
      if (fVar1 < *pfVar18) {
        *pfVar18 = fVar1;
      }
      param_5 = param_5 + 1.0;
      fVar1 = (local_24 * param_5 + local_28) / local_20 - fVar7;
      if (fVar1 < pfVar18[1]) {
        pfVar18[1] = fVar1;
      }
      param_5 = param_5 + 1.0;
      pfVar18 = pfVar18 + 4;
      iVar12 = iVar12 + -1;
    } while (iVar12 != 0);
  }
  if (iVar17 < param_1) {
    do {
      fVar1 = (local_24 * param_5 + local_28) / local_20 - fVar7;
      if (fVar1 < *(float *)(param_4 + iVar17 * 4)) {
        *(float *)(param_4 + iVar17 * 4) = fVar1;
      }
      param_5 = param_5 + 1.0;
      iVar17 = iVar17 + 1;
    } while (iVar17 < param_1);
    return;
  }
  return;
}

