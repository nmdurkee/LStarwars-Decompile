/* Ghidra analysis pseudocode, not original source.
 * ev_16752497ebe96469e4b3deeac467b7e56d3adcbbd74f32adb05b8515faa59936
 * Entry: 0x5ce820; label: FUN_005ce820
 */

void FUN_005ce820(uint *param_1,undefined4 param_2,uint *param_3,undefined4 param_4,float param_5,
                 int param_6,float *param_7,float *param_8,int param_9,float *param_10)

{
  float *pfVar1;
  int iVar2;
  uint uVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  int iVar8;
  int iVar9;
  int *piVar10;
  float10 fVar11;
  byte local_45;
  uint local_40;
  float local_3c [13];
  float local_8;
  float local_4;
  
  fVar4 = 1.0 - param_5;
  if (param_10 == (float *)0x0) {
    local_45 = 0;
  }
  else {
    local_45 = *(byte *)((int)param_10 + 0x31);
  }
  if ((((*param_1 & 1) == 0) && ((*param_3 & 1) == 0)) && ((local_45 & 1) == 0)) {
    FUN_005b44e0(param_9);
  }
  else {
    iVar9 = 0;
    piVar10 = (int *)(param_3[2] + 0xc);
    iVar8 = param_1[2] - param_3[2];
    do {
      if (*(int *)((int)piVar10 + iVar8) == 0) {
        fVar11 = (float10)*(float *)(param_1[1] + 0xc + iVar9);
      }
      else {
        fVar11 = (float10)FUN_005c91c0(*(undefined4 *)((int)piVar10 + iVar8),param_2);
      }
      iVar2 = *piVar10;
      *(float *)((int)local_3c + iVar9 + 0xc) = (float)fVar11;
      if (iVar2 == 0) {
        fVar11 = (float10)*(float *)(param_3[1] + 0xc + iVar9);
      }
      else {
        fVar11 = (float10)FUN_005c91c0(*piVar10,param_4);
      }
      *(float *)((int)local_3c + iVar9) = (float)fVar11;
      iVar9 = iVar9 + 4;
      piVar10 = piVar10 + 1;
    } while (iVar9 < 9);
    local_40 = (uint)(3.1415927 < local_3c[3] - local_3c[0]);
    fVar6 = local_3c[3] - (float)local_40 * 6.2831855;
    local_40 = (uint)(3.1415927 < local_3c[0] - fVar6);
    local_3c[0] = local_3c[0] - (float)local_40 * 6.2831855;
    local_40 = (uint)(3.1415927 < local_3c[4] - local_3c[1]);
    fVar5 = local_3c[4] - (float)local_40 * 6.2831855;
    local_40 = (uint)(3.1415927 < local_3c[1] - fVar5);
    local_3c[1] = local_3c[1] - (float)local_40 * 6.2831855;
    local_40 = (uint)(3.1415927 < local_3c[5] - local_3c[2]);
    fVar7 = local_3c[5] - (float)local_40 * 6.2831855;
    local_40 = (uint)(3.1415927 < local_3c[2] - fVar7);
    local_3c[2] = local_3c[2] - (float)local_40 * 6.2831855;
    local_3c[3] = fVar4 * fVar6 + param_5 * local_3c[0];
    local_3c[4] = local_3c[1] * param_5 + fVar4 * fVar5;
    local_3c[5] = param_5 * local_3c[2] + fVar7 * fVar4;
    if ((local_45 & 1) == 0) {
      local_3c[0] = (float)FUN_006e6b90();
      local_3c[1] = (float)FUN_006e6b90();
      local_3c[2] = (float)FUN_006e6b90();
    }
    else {
      local_3c[3] = *param_10 + local_3c[3];
      local_3c[4] = param_10[1] + local_3c[4];
      local_3c[5] = param_10[2] + local_3c[5];
      fVar6 = (float)FUN_006e6b90();
      local_3c[0] = fVar6;
      fVar7 = (float)FUN_006e6b90();
      local_3c[1] = fVar7;
      local_3c[2] = (float)FUN_006e6b90();
      if ((local_45 & 8) != 0) {
        local_3c[0] = (float)((uint)fVar6 & 0xffff);
        if (0x7fff < (uint)local_3c[0]) {
          local_3c[0] = (float)((int)local_3c[0] - 0x10000);
        }
        fVar6 = (float)(int)*(short *)(param_10 + 9);
        if (((int)fVar6 < (int)local_3c[0]) ||
           (fVar6 = (float)(int)*(short *)((int)param_10 + 0x2a), (int)local_3c[0] < (int)fVar6)) {
          local_3c[0] = fVar6;
        }
      }
      if ((local_45 & 0x10) != 0) {
        local_3c[1] = (float)((uint)fVar7 & 0xffff);
        if (0x7fff < (uint)local_3c[1]) {
          local_3c[1] = (float)((int)local_3c[1] - 0x10000);
        }
        fVar6 = (float)(int)*(short *)((int)param_10 + 0x26);
        if (((int)fVar6 < (int)local_3c[1]) ||
           (fVar6 = (float)(int)*(short *)(param_10 + 0xb), (int)local_3c[1] < (int)fVar6)) {
          local_3c[1] = fVar6;
        }
      }
      if ((local_45 & 0x20) != 0) {
        fVar6 = (float)((uint)local_3c[2] & 0xffff);
        if (0x7fff < (uint)fVar6) {
          fVar6 = (float)((int)fVar6 - 0x10000);
        }
        local_3c[2] = (float)(int)*(short *)(param_10 + 10);
        if (((int)fVar6 <= (int)local_3c[2]) &&
           (local_3c[2] = fVar6, (int)fVar6 < (int)*(short *)((int)param_10 + 0x2e))) {
          local_3c[2] = (float)(int)*(short *)((int)param_10 + 0x2e);
        }
      }
    }
    thunk_FUN_005b5300(param_9,local_3c);
  }
  if (((*param_1 & 0x20) != 0) || ((*param_3 & 0x20) != 0)) {
    thunk_FUN_005b5700(param_9,param_9,param_6);
  }
  if ((((*param_1 & 8) == 0) && ((*param_3 & 8) == 0)) && ((local_45 & 4) == 0)) {
    *param_7 = *param_8;
    param_7[1] = param_8[1];
    param_7[2] = param_8[2];
  }
  else {
    iVar9 = 0;
    piVar10 = (int *)(param_3[2] + 0x18);
    iVar8 = param_1[2] - param_3[2];
    do {
      if (*(int *)((int)piVar10 + iVar8) == 0) {
        fVar11 = (float10)*(float *)(param_1[1] + 0x18 + iVar9);
      }
      else {
        fVar11 = (float10)FUN_005c91c0(*(undefined4 *)((int)piVar10 + iVar8),param_2);
      }
      iVar2 = *piVar10;
      *(float *)((int)local_3c + iVar9 + 0x24) = (float)fVar11;
      if (iVar2 == 0) {
        fVar11 = (float10)*(float *)(param_3[1] + 0x18 + iVar9);
      }
      else {
        fVar11 = (float10)FUN_005c91c0(*piVar10,param_4);
      }
      *(float *)((int)local_3c + iVar9 + 0xc) = (float)fVar11;
      iVar9 = iVar9 + 4;
      piVar10 = piVar10 + 1;
    } while (iVar9 < 9);
    fVar6 = fVar4 * local_3c[3] + param_5 * local_3c[9];
    *param_7 = fVar6;
    fVar5 = local_3c[10] * param_5 + local_3c[4] * fVar4;
    param_7[1] = fVar5;
    fVar7 = local_3c[5] * fVar4 + local_3c[0xb] * param_5;
    param_7[2] = fVar7;
    if ((local_45 & 4) != 0) {
      *param_7 = param_10[6] + fVar6;
      param_7[1] = fVar5 + param_10[7];
      param_7[2] = fVar7 + param_10[8];
    }
    thunk_FUN_005b4c30(param_9,param_7);
    *param_7 = *param_7 * *param_8;
    param_7[1] = param_8[1] * param_7[1];
    param_7[2] = param_8[2] * param_7[2];
  }
  if (((*param_1 | *param_3) & 0x10) != 0) {
    local_3c[5] = 0.0;
    if (((*param_8 == 0.0) || (param_8[1] == 0.0)) || (param_8[2] == 0.0)) {
      local_3c[3] = 0.0;
      local_3c[4] = 0.0;
    }
    else {
      local_3c[3] = 1.0 / *param_8;
      local_3c[4] = 1.0 / param_8[1];
      local_3c[5] = 1.0 / param_8[2];
    }
    thunk_FUN_005b4a50(param_9,local_3c + 3);
    *param_7 = *param_7 * local_3c[3];
    param_7[1] = param_7[1] * local_3c[4];
    param_7[2] = param_7[2] * local_3c[5];
  }
  uVar3 = param_3[2];
  iVar9 = 0;
  iVar8 = param_1[2] - uVar3;
  do {
    pfVar1 = (float *)((int)local_3c + iVar9 + 0x18);
    piVar10 = (int *)((uVar3 - (int)(local_3c + 6)) + (int)pfVar1);
    if (*(int *)((int)piVar10 + iVar8) == 0) {
      fVar11 = (float10)*(float *)(param_1[1] + iVar9);
    }
    else {
      fVar11 = (float10)FUN_005c91c0(*(undefined4 *)((int)piVar10 + iVar8),param_2);
    }
    *pfVar1 = (float)(fVar11 * (float10)fVar4);
    if (*piVar10 == 0) {
      fVar11 = (float10)*(float *)(param_3[1] + iVar9);
    }
    else {
      fVar11 = (float10)FUN_005c91c0(*piVar10,param_4);
    }
    iVar9 = iVar9 + 4;
    *pfVar1 = (float)(fVar11 * (float10)param_5 + (float10)*pfVar1);
  } while (iVar9 < 9);
  if ((local_45 & 2) != 0) {
    local_3c[6] = param_10[3] + local_3c[6];
    local_3c[7] = param_10[4] + local_3c[7];
    local_3c[8] = param_10[5] + local_3c[8];
  }
  FUN_005b4900(param_9,local_3c + 6);
  if ((*(byte *)(param_6 + 0x51) & 8) != 0) {
    FUN_005b4960(param_9,(float *)(param_6 + 0x40));
    local_3c[0xc] = -*(float *)(param_6 + 0x40);
    local_8 = -*(float *)(param_6 + 0x44);
    local_4 = -*(float *)(param_6 + 0x48);
    FUN_005b4900(param_9,local_3c + 0xc);
  }
  *(float *)(param_9 + 8) = -*(float *)(param_9 + 8);
  *(float *)(param_9 + 0x18) = -*(float *)(param_9 + 0x18);
  *(float *)(param_9 + 0x20) = -*(float *)(param_9 + 0x20);
  *(float *)(param_9 + 0x24) = -*(float *)(param_9 + 0x24);
  *(float *)(param_9 + 0x2c) = -*(float *)(param_9 + 0x2c);
  *(float *)(param_9 + 0x38) = -*(float *)(param_9 + 0x38);
  return;
}

