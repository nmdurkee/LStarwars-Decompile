/* Ghidra pseudocode, not original source.
 * ev_4e08cb6b9a05324ae7a2b7ff12e5cd4300e2bf96324e358c1c445da0c9e3f38b
 * Entry: 0x62f520; label: FUN_0062f520
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0062f520(int param_1,int param_2,float *param_3,float *param_4,float *param_5,
                 undefined4 param_6)

{
  float *pfVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar4 = *(int *)(param_2 + 0x50);
  iVar5 = *(short *)(param_2 + 0x3a) * 4;
  piVar2 = (int *)(iVar5 + *(int *)(iVar4 + 8));
  if ((*(byte *)(*piVar2 + 4) & 0x20) == 0) {
    local_30 = *param_3;
    local_40 = 0.0;
    local_44 = 0.0;
    local_2c = param_3[1];
    local_48 = 0.0;
    local_28 = param_3[2];
    *(undefined4 *)(param_2 + 0x25c) = 0x7f7fffff;
  }
  else {
    if ((*(float *)(param_2 + 0x18) < *(float *)(param_2 + 0x25c)) ||
       (*piVar2 != *(int *)(param_2 + 0x264))) {
      *(float *)(param_2 + 0x244) = *param_3;
      *(float *)(param_2 + 0x248) = param_3[1];
      *(float *)(param_2 + 0x24c) = param_3[2];
      *(undefined4 *)(param_2 + 0x264) = *(undefined4 *)(iVar5 + *(int *)(iVar4 + 8));
    }
    local_48 = *param_3 - *(float *)(param_2 + 0x244);
    if ((*(uint *)(*(int *)(iVar5 + *(int *)(iVar4 + 8)) + 4) & 0x200) == 0) {
      local_44 = 0.0;
    }
    else {
      local_44 = param_3[1] - *(float *)(param_2 + 0x248);
    }
    local_40 = param_3[2] - *(float *)(param_2 + 0x24c);
    *(float *)(param_2 + 0x244) = *param_3;
    *(float *)(param_2 + 0x248) = param_3[1];
    *(float *)(param_2 + 0x24c) = param_3[2];
    local_30 = 0.0;
    if ((*(uint *)(*(int *)(iVar5 + *(int *)(iVar4 + 8)) + 4) & 0x200) == 0) {
      local_2c = param_3[1];
      local_28 = 0.0;
      *(undefined4 *)(param_2 + 0x25c) = *(undefined4 *)(param_2 + 0x18);
    }
    else {
      local_2c = 0.0;
      local_28 = 0.0;
      *(undefined4 *)(param_2 + 0x25c) = *(undefined4 *)(param_2 + 0x18);
    }
  }
  local_18 = *(undefined4 *)(*(int *)(iVar5 + *(int *)(iVar4 + 8)) + 0x3c);
  local_14 = *(undefined4 *)(*(int *)(iVar5 + *(int *)(iVar4 + 8)) + 0x40);
  local_10 = *(undefined4 *)(*(int *)(iVar5 + *(int *)(iVar4 + 8)) + 0x44);
  iVar5 = *(short *)(param_2 + 0x3c) * 4;
  if ((*(byte *)(*(int *)(iVar5 + *(int *)(iVar4 + 8)) + 4) & 0x20) == 0) {
    local_34 = 0.0;
    local_24 = *param_4;
    local_38 = 0.0;
    local_3c = 0.0;
    uVar3 = 0x7f7fffff;
    local_20 = param_4[1];
    local_1c = param_4[2];
  }
  else {
    if ((*(float *)(param_2 + 0x1c) < *(float *)(param_2 + 0x260)) ||
       (*(int *)(iVar5 + *(int *)(iVar4 + 8)) != *(int *)(param_2 + 0x268))) {
      *(float *)(param_2 + 0x250) = *param_4;
      *(float *)(param_2 + 0x254) = param_4[1];
      *(float *)(param_2 + 600) = param_4[2];
      *(undefined4 *)(param_2 + 0x268) = *(undefined4 *)(iVar5 + *(int *)(iVar4 + 8));
    }
    local_3c = *param_4 - *(float *)(param_2 + 0x250);
    if ((*(uint *)(*(int *)(iVar5 + *(int *)(iVar4 + 8)) + 4) & 0x200) == 0) {
      local_38 = 0.0;
    }
    else {
      local_38 = param_4[1] - *(float *)(param_2 + 0x254);
    }
    local_34 = param_4[2] - *(float *)(param_2 + 600);
    *(float *)(param_2 + 0x250) = *param_4;
    *(float *)(param_2 + 0x254) = param_4[1];
    *(float *)(param_2 + 600) = param_4[2];
    local_24 = 0.0;
    if ((*(uint *)(*(int *)(iVar5 + *(int *)(iVar4 + 8)) + 4) & 0x200) == 0) {
      local_20 = param_4[1];
      local_1c = 0.0;
      uVar3 = *(undefined4 *)(param_2 + 0x1c);
    }
    else {
      local_20 = 0.0;
      local_1c = 0.0;
      uVar3 = *(undefined4 *)(param_2 + 0x1c);
    }
  }
  *(undefined4 *)(param_2 + 0x260) = uVar3;
  local_c = *(undefined4 *)(*(int *)(iVar5 + *(int *)(iVar4 + 8)) + 0x3c);
  local_8 = *(undefined4 *)(*(int *)(iVar5 + *(int *)(iVar4 + 8)) + 0x40);
  local_4 = *(undefined4 *)(*(int *)(iVar5 + *(int *)(iVar4 + 8)) + 0x44);
  FUN_005b3d80(param_1 + 0x30,&local_24,&local_30,param_6);
  FUN_005b3d80(&local_54,&local_c,&local_18,param_6);
  *param_5 = *param_5 + local_54;
  param_5[1] = local_50 + param_5[1];
  param_5[2] = param_5[2] + local_4c;
  FUN_005b4900(param_1,param_5);
  FUN_005b3200(&local_48,&local_48,param_2 + 0xb8);
  if ((*(uint *)(*(int *)(*(int *)(*(int *)(param_2 + 0x50) + 8) + *(short *)(param_2 + 0x3a) * 4) +
                4) & 0x200) == 0) {
    local_44 = 0.0;
  }
  FUN_005b3200(&local_3c,&local_3c,param_2 + 0xb8);
  if ((*(uint *)(*(int *)(*(int *)(*(int *)(param_2 + 0x50) + 8) + *(short *)(param_2 + 0x3c) * 4) +
                4) & 0x200) == 0) {
    local_38 = 0.0;
  }
  pfVar1 = (float *)(param_2 + 0x26c);
  FUN_005b3d80(pfVar1,&local_3c,&local_48,param_6);
  iVar4 = *(int *)(*(int *)(param_2 + 0x50) + 8);
  if ((((*(uint *)(*(int *)(iVar4 + *(short *)(param_2 + 0x3a) * 4) + 4) & 0x200) != 0) ||
      ((*(uint *)(*(int *)(iVar4 + *(short *)(param_2 + 0x3c) * 4) + 4) & 0x200) != 0)) &&
     (*(float *)(param_2 + 0x270) == 0.0)) {
    *(undefined4 *)(param_2 + 0x270) = 0x2d2febff;
    return;
  }
  if (((*pfVar1 == 0.0) && (*(float *)(param_2 + 0x270) == 0.0)) &&
     (*(float *)(param_2 + 0x274) == 0.0)) {
    *pfVar1 = 1e-11;
    return;
  }
  return;
}

