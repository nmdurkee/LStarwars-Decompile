/* Ghidra analysis pseudocode, not original source.
 * ev_16752497ebe96469e4b3deeac467b7e56d3adcbbd74f32adb05b8515faa59936
 * Entry: 0x5ceee0; label: FUN_005ceee0
 */

void FUN_005ceee0(float *param_1,char *param_2,byte param_3,undefined4 param_4,int param_5,
                 float *param_6,float *param_7,int param_8,float *param_9,float *param_10,
                 undefined4 *param_11)

{
  float *pfVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  float10 fVar5;
  float local_30;
  float local_2c;
  float local_28;
  uint local_24;
  uint local_20;
  uint local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  if (param_10 != (float *)0x0) {
    param_10[2] = 0.0;
    param_10[1] = 0.0;
    *param_10 = 0.0;
  }
  if (param_11 != (undefined4 *)0x0) {
    param_11[2] = 0;
    param_11[1] = 0;
    *param_11 = 0;
  }
  if (param_9 == (float *)0x0) {
    bVar2 = 0;
  }
  else {
    bVar2 = *(byte *)((int)param_9 + 0x31);
  }
  if (((param_3 & 1) == 0) && ((bVar2 & 1) == 0)) {
    FUN_005b44e0(param_8);
  }
  else {
    if ((param_3 & 1) == 0) {
      local_28 = 0.0;
      local_2c = 0.0;
      local_30 = 0.0;
    }
    else {
      if (param_2[3] == '\0') {
        fVar5 = (float10)param_1[3];
      }
      else {
        fVar5 = (float10)FUN_005c9520(param_1 + 3,param_4,(int)param_2[3]);
      }
      local_30 = (float)fVar5;
      if (param_2[4] == '\0') {
        fVar5 = (float10)param_1[4];
      }
      else {
        fVar5 = (float10)FUN_005c9520(param_1 + 4,param_4,(int)param_2[4]);
      }
      local_2c = (float)fVar5;
      if (param_2[5] == '\0') {
        local_28 = param_1[5];
      }
      else {
        fVar5 = (float10)FUN_005c9520(param_1 + 5,param_4,(int)param_2[5]);
        local_28 = (float)fVar5;
      }
    }
    if ((bVar2 & 1) == 0) {
      local_24 = FUN_006e6b90();
      local_20 = FUN_006e6b90();
      local_1c = FUN_006e6b90();
    }
    else {
      local_30 = *param_9 + local_30;
      local_2c = param_9[1] + local_2c;
      local_28 = param_9[2] + local_28;
      uVar3 = FUN_006e6b90();
      local_24 = uVar3;
      uVar4 = FUN_006e6b90();
      local_20 = uVar4;
      local_1c = FUN_006e6b90();
      if ((bVar2 & 8) != 0) {
        local_24 = uVar3 & 0xffff;
        if (0x7fff < local_24) {
          local_24 = local_24 - 0x10000;
        }
        uVar3 = (uint)*(short *)(param_9 + 9);
        if (((int)uVar3 < (int)local_24) ||
           (uVar3 = (uint)*(short *)((int)param_9 + 0x2a), (int)local_24 < (int)uVar3)) {
          local_24 = uVar3;
        }
      }
      if ((bVar2 & 0x10) != 0) {
        local_20 = uVar4 & 0xffff;
        if (0x7fff < local_20) {
          local_20 = local_20 - 0x10000;
        }
        uVar3 = (uint)*(short *)((int)param_9 + 0x26);
        if (((int)uVar3 < (int)local_20) ||
           (uVar3 = (uint)*(short *)(param_9 + 0xb), (int)local_20 < (int)uVar3)) {
          local_20 = uVar3;
        }
      }
      if ((bVar2 & 0x20) != 0) {
        uVar3 = local_1c & 0xffff;
        if (0x7fff < uVar3) {
          uVar3 = uVar3 - 0x10000;
        }
        local_1c = (uint)*(short *)(param_9 + 10);
        if (((int)uVar3 <= (int)local_1c) &&
           (local_1c = uVar3, (int)uVar3 < (int)*(short *)((int)param_9 + 0x2e))) {
          local_1c = (int)*(short *)((int)param_9 + 0x2e);
        }
      }
    }
    thunk_FUN_005b5300(param_8,&local_24);
  }
  if ((param_3 & 0x20) != 0) {
    thunk_FUN_005b5700(param_8,param_8,param_5);
  }
  if (((param_3 & 8) == 0) && ((bVar2 & 4) == 0)) {
    *param_6 = *param_7;
    param_6[1] = param_7[1];
    param_6[2] = param_7[2];
  }
  else {
    if ((param_3 & 8) == 0) {
      param_6[2] = 0.0;
      param_6[1] = 0.0;
      *param_6 = 0.0;
    }
    else {
      if (param_2[6] == '\0') {
        fVar5 = (float10)param_1[6];
      }
      else {
        fVar5 = (float10)FUN_005c9520(param_1 + 6,param_4,(int)param_2[6]);
      }
      *param_6 = (float)fVar5;
      if (param_2[7] == '\0') {
        fVar5 = (float10)param_1[7];
      }
      else {
        fVar5 = (float10)FUN_005c9520(param_1 + 7,param_4,(int)param_2[7]);
      }
      param_6[1] = (float)fVar5;
      if (param_2[8] == '\0') {
        param_6[2] = param_1[8];
      }
      else {
        fVar5 = (float10)FUN_005c9520(param_1 + 8,param_4,(int)param_2[8]);
        param_6[2] = (float)fVar5;
      }
    }
    if ((bVar2 & 4) != 0) {
      *param_6 = param_9[6] + *param_6;
      param_6[1] = param_9[7] + param_6[1];
      param_6[2] = param_9[8] + param_6[2];
    }
    thunk_FUN_005b4c30(param_8,param_6);
    *param_6 = *param_6 * *param_7;
    param_6[1] = param_7[1] * param_6[1];
    param_6[2] = param_7[2] * param_6[2];
  }
  if ((param_3 & 0x10) != 0) {
    local_28 = 0.0;
    if (((*param_7 == 0.0) || (param_7[1] == 0.0)) || (param_7[2] == 0.0)) {
      local_30 = 0.0;
      local_2c = 0.0;
    }
    else {
      local_30 = 1.0 / *param_7;
      local_2c = 1.0 / param_7[1];
      local_28 = 1.0 / param_7[2];
    }
    thunk_FUN_005b4a50(param_8,&local_30);
    *param_6 = *param_6 * local_30;
    param_6[1] = local_2c * param_6[1];
    param_6[2] = param_6[2] * local_28;
  }
  if (*param_2 == '\0') {
    fVar5 = (float10)*param_1;
  }
  else {
    fVar5 = (float10)FUN_005c9520(param_1,param_4,(int)*param_2);
  }
  local_18 = (float)fVar5;
  if (param_2[1] == '\0') {
    fVar5 = (float10)param_1[1];
  }
  else {
    fVar5 = (float10)FUN_005c9520(param_1 + 1,param_4,(int)param_2[1]);
  }
  local_14 = (float)fVar5;
  if (param_2[2] == '\0') {
    fVar5 = (float10)param_1[2];
  }
  else {
    fVar5 = (float10)FUN_005c9520(param_1 + 2,param_4,(int)param_2[2]);
  }
  local_10 = (float)fVar5;
  if (param_10 != (float *)0x0) {
    *param_10 = local_18;
    param_10[1] = local_14;
    param_10[2] = -local_10;
  }
  if ((bVar2 & 2) != 0) {
    local_18 = local_18 + param_9[3];
    local_14 = local_14 + param_9[4];
    local_10 = local_10 + param_9[5];
  }
  FUN_005b4900(param_8,&local_18);
  if ((*(byte *)(param_5 + 0x51) & 8) != 0) {
    pfVar1 = (float *)(param_5 + 0x40);
    FUN_005b4960(param_8,pfVar1);
    local_c = -*pfVar1;
    local_8 = -*(float *)(param_5 + 0x44);
    local_4 = -*(float *)(param_5 + 0x48);
    FUN_005b4900(param_8,&local_c);
    if (param_11 != (undefined4 *)0x0) {
      FUN_005b3200(param_11,pfVar1,param_8);
      FUN_005b3800(param_11,param_11,pfVar1);
      param_11[2] = (float)param_11[2] * -1.0;
    }
  }
  *(float *)(param_8 + 8) = -*(float *)(param_8 + 8);
  *(float *)(param_8 + 0x18) = -*(float *)(param_8 + 0x18);
  *(float *)(param_8 + 0x20) = -*(float *)(param_8 + 0x20);
  *(float *)(param_8 + 0x24) = -*(float *)(param_8 + 0x24);
  *(float *)(param_8 + 0x2c) = -*(float *)(param_8 + 0x2c);
  *(float *)(param_8 + 0x38) = -*(float *)(param_8 + 0x38);
  return;
}

