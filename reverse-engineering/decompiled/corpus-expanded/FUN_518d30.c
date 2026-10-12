/* Ghidra pseudocode, not original source.
 * ev_7610d2e5ecab5d7a95653def000f5e9425ca0c842a62593dc010feaabdcb80b1
 * Entry: 0x518d30; label: FUN_00518d30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00518d30(int param_1,float *param_2,float *param_3,float param_4)

{
  float fVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int local_28;
  float local_24;
  float local_1c;
  undefined4 local_18 [2];
  undefined4 local_10;
  undefined4 local_c [2];
  undefined4 local_4;
  
  fVar1 = *(float *)(*(int *)(param_1 + 4) + 0x114) - *param_2;
  local_28 = 0;
  *param_3 = fVar1;
  if (param_4 < fVar1) {
    return;
  }
  if (fVar1 < -param_4) {
    return;
  }
  fVar1 = *(float *)(*(int *)(param_1 + 4) + 0x11c) - param_2[2];
  param_3[2] = fVar1;
  if (param_4 < fVar1) {
    return;
  }
  if (fVar1 < -param_4) {
    return;
  }
  if (param_2[6] < *(float *)(param_1 + 0x17c)) {
    return;
  }
  if (*(float *)(param_1 + 0x188) < param_2[4]) {
    return;
  }
  FUN_005b3620(param_3,param_3,-(int)param_2[0xe]);
  if (*(float *)(*(int *)(param_1 + 4) + 0x120) + param_2[0x10] <= ABS(*param_3)) {
    return;
  }
  if (param_2[0x11] + *(float *)(*(int *)(param_1 + 4) + 0x120) <= ABS(param_3[2])) {
    return;
  }
  *param_3 = *(float *)(param_1 + 0x5c) - *param_2;
  param_3[1] = 0.0;
  param_3[2] = *(float *)(param_1 + 100) - param_2[2];
  FUN_005b3620(local_18,param_3,-(int)param_2[0xe]);
  uVar2 = FUN_005be2d0(local_18[0],local_10);
  *param_3 = *(float *)(*(int *)(param_1 + 4) + 0x104) - *param_2;
  param_3[1] = 0.0;
  param_3[2] = *(float *)(*(int *)(param_1 + 4) + 0x10c) - param_2[2];
  FUN_005b3620(local_c,param_3,-(int)param_2[0xe]);
  uVar3 = FUN_005be2d0(local_c[0],local_4);
  uVar4 = FUN_005be5b0(uVar3,uVar2);
  iVar5 = *(int *)(param_1 + 4);
  if (*(float *)(iVar5 + 0x18c) <= 0.0) {
    if ((int)uVar4 < 1) {
      *(uint *)(iVar5 + 0x1e8) = *(uint *)(iVar5 + 0x1e8) & 0xffff7fff;
    }
    else {
      *(uint *)(iVar5 + 0x1e8) = *(uint *)(iVar5 + 0x1e8) | 0x8000;
    }
  }
  else {
    if (((((*(ushort *)(iVar5 + 0x166) & 1) == 0) && ((*(ushort *)(iVar5 + 0x166) & 2) != 0)) ||
        (1.0 < *(float *)(param_1 + 0x1d8))) && (*(float *)(iVar5 + 0x18c) < _DAT_00801c74)) {
      *(uint *)(iVar5 + 0x1e8) =
           *(uint *)(iVar5 + 0x1e8) ^
           (~*(uint *)(iVar5 + 0x1e8) ^ *(uint *)(iVar5 + 0x1e8)) & 0x8000;
      *(float *)(*(int *)(param_1 + 4) + 0x18c) = _DAT_00801c78 + _DAT_00801c74;
    }
    if ((*(uint *)(*(int *)(param_1 + 4) + 0x1e8) & 0x8000) == 0) {
      if (0 < (int)uVar4) {
        local_28 = -0x10000;
      }
    }
    else if ((int)uVar4 < 0) {
      local_28 = 0x10000;
    }
  }
  if (((*(byte *)((int)param_2 + 0x49) & 2) == 0) &&
     (*(float *)(*(int *)(param_1 + 4) + 0x18c) < _DAT_00801c74)) {
    *(float *)(*(int *)(param_1 + 4) + 0x18c) = _DAT_00801c74;
  }
  iVar5 = FUN_005be2d0(param_2[0x10],param_2[0x11]);
  iVar6 = FUN_005be590(uVar2,0);
  if (0x8000 - iVar5 < iVar6) {
LAB_005190cc:
    local_24 = -1.0;
    *(float *)(*(int *)(param_1 + 4) + 0x114) =
         (*(float *)(*(int *)(param_1 + 4) + 0x120) + param_2[0x10]) *
         (float)(&DAT_029899a0)[iVar6 >> 1 & 0x7fff];
    iVar5 = *(int *)(param_1 + 4);
    fVar1 = -(*(float *)(iVar5 + 0x120) + param_2[0x11]);
LAB_0051910a:
    local_1c = 0.0;
    *(float *)(iVar5 + 0x11c) = fVar1;
  }
  else {
    if (iVar5 < iVar6) {
      iVar5 = *(int *)(param_1 + 4);
      local_1c = -1.0;
      fVar1 = *(float *)(iVar5 + 0x120) + param_2[0x10];
    }
    else {
      if (-iVar5 < iVar6) {
        local_24 = 1.0;
        *(float *)(*(int *)(param_1 + 4) + 0x114) =
             (*(float *)(*(int *)(param_1 + 4) + 0x120) + param_2[0x10]) *
             (float)(&DAT_029899a0)[iVar6 >> 1 & 0x7fff];
        iVar5 = *(int *)(param_1 + 4);
        fVar1 = *(float *)(iVar5 + 0x120) + param_2[0x11];
        goto LAB_0051910a;
      }
      if (iVar6 <= iVar5 + -0x8000) goto LAB_005190cc;
      iVar5 = *(int *)(param_1 + 4);
      local_1c = 1.0;
      fVar1 = -(*(float *)(iVar5 + 0x120) + param_2[0x10]);
    }
    local_24 = 0.0;
    *(float *)(iVar5 + 0x114) = fVar1;
    *(float *)(*(int *)(param_1 + 4) + 0x11c) =
         (*(float *)(*(int *)(param_1 + 4) + 0x120) + param_2[0x11]) *
         (float)(&DAT_029899a0)[iVar6 + 0x4000 >> 1 & 0x7fff];
  }
  if ((int)(uVar4 + local_28) < 0) {
    local_24 = -local_24;
    local_1c = -local_1c;
  }
  iVar5 = (uVar4 ^ (int)uVar4 >> 0x1f) - ((int)uVar4 >> 0x1f);
  if (iVar5 < 0x71c) {
    fVar1 = (float)iVar5 / 1820.0;
    local_24 = fVar1 * local_24;
    local_1c = fVar1 * local_1c;
  }
  *(float *)(*(int *)(param_1 + 4) + 0x114) = *(float *)(*(int *)(param_1 + 4) + 0x114) + local_24;
  *(undefined4 *)(*(int *)(param_1 + 4) + 0x118) = 0;
  *(float *)(*(int *)(param_1 + 4) + 0x11c) = local_1c + *(float *)(*(int *)(param_1 + 4) + 0x11c);
  iVar5 = *(int *)(param_1 + 4) + 0x114;
  FUN_005b3620(iVar5,iVar5,param_2[0xe]);
  iVar5 = *(int *)(param_1 + 4) + 0x114;
  FUN_005b37d0(iVar5,iVar5,param_2);
  *(uint *)(param_1 + 0x1fc) = *(uint *)(param_1 + 0x1fc) | 0x40000;
  return;
}

