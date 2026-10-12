/* Ghidra pseudocode, not original source.
 * ev_8a909e0f7cdee8f131d9fa101a03e4afa99ad6c03186a84914f93ab3f48399ec
 * Entry: 0x6204f0; label: FUN_006204f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006204f0(int param_1,float param_2,float param_3)

{
  undefined1 uVar1;
  undefined1 uVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  float10 fVar6;
  float local_20;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  iVar5 = (int)param_3;
  local_10 = 0.0;
  local_14 = 0.0;
  local_18 = 0.0;
  if ((*(byte *)((int)param_3 + 0x80) & 4) == 0) {
    return;
  }
  param_2 = param_2 / 0.016666668;
  if (*(float *)(param_1 + 0x84) == 0.0) {
    local_20 = 1.0;
  }
  else {
    local_20 = *(float *)(param_1 + 0x84) * ABS(*(float *)(param_1 + 0x14)) +
               *(float *)(param_1 + 0x80);
  }
  if (*(float *)(param_1 + 0x8c) == 0.0) {
    param_3 = 1.0;
  }
  else {
    param_3 = *(float *)(param_1 + 0x8c) * ABS(*(float *)(param_1 + 0x14)) +
              *(float *)(param_1 + 0x88);
  }
  fVar3 = param_3;
  uVar1 = *(undefined1 *)(iVar5 + 0x91);
  uVar2 = *(undefined1 *)(iVar5 + 0x90);
  if ((*(uint *)(param_1 + 0x90) & 0x20) != 0) {
    param_3 = param_3 * (float)*(byte *)(iVar5 + 0x9d) * *(float *)(param_1 + 0x6c);
    if (1.0 < param_3) {
      param_3 = 1.0;
    }
    *(float *)(param_1 + 0x14) = param_3 * param_2 + *(float *)(param_1 + 0x14);
    param_3 = (float)*(byte *)(iVar5 + 0x9f) * *(float *)(param_1 + 0x6c) * fVar3;
    if (1.0 < param_3) {
      param_3 = 1.0;
    }
    fVar3 = *(float *)(param_1 + 0x14) - param_3 * param_2;
    *(float *)(param_1 + 0x14) = fVar3;
    if (fVar3 <= -*(float *)(param_1 + 0x70)) {
      *(float *)(param_1 + 0x14) = fVar3;
    }
    else {
      *(float *)(param_1 + 0x14) = -*(float *)(param_1 + 0x70);
    }
  }
  if ((*(uint *)(param_1 + 0x90) & 8) != 0) {
    FUN_006dec10(uVar1,0x20);
    iVar4 = FUN_006e6b90();
    *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + iVar4;
    iVar4 = *(int *)(param_1 + 0xc);
    if (0x4000 < iVar4) {
      iVar4 = 0x4000;
    }
    *(int *)(param_1 + 0xc) = iVar4;
    if (iVar4 < -0x4000) {
      iVar4 = -0x4000;
    }
    *(int *)(param_1 + 0xc) = iVar4;
  }
  if ((*(byte *)(param_1 + 0x90) & 0x10) != 0) {
    FUN_006dec10(uVar2,0x20);
    iVar4 = FUN_006e6b90();
    *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + iVar4;
  }
  if ((*(uint *)(param_1 + 0x90) & 2) != 0) {
    local_14 = (local_14 +
               (float)*(byte *)(iVar5 + 0x9c) * *(float *)(param_1 + 0x5c) * local_20 * param_2 *
               0.5) - (float)*(byte *)(iVar5 + 0x9e) * *(float *)(param_1 + 0x5c) * local_20 *
                      param_2 * 0.5;
  }
  if ((*(uint *)(param_1 + 0x90) & 4) != 0) {
    iVar4 = FUN_006dec10(*(undefined1 *)(iVar5 + 0x93),0x20);
    local_10 = -(float)iVar4 * *(float *)(param_1 + 0x5c) * local_20 * param_2;
  }
  if ((*(byte *)(param_1 + 0x90) & 1) != 0) {
    iVar5 = FUN_006dec10(*(undefined1 *)(iVar5 + 0x92),0x20);
    local_18 = (float)iVar5 * *(float *)(param_1 + 0x5c) * local_20 * param_2;
  }
  FUN_005b3620(&local_18,&local_18,*(undefined4 *)(param_1 + 0x10));
  FUN_005b37d0(param_1,param_1,&local_18);
  FUN_005b3800(&local_c,param_1,(float *)(param_1 + 0x24));
  local_c = local_c / *(float *)(param_1 + 0x30);
  local_8 = local_8 / *(float *)(param_1 + 0x34);
  local_4 = local_4 / *(float *)(param_1 + 0x38);
  fVar6 = (float10)FUN_005b7cc0(local_c);
  *(float *)(param_1 + 0x44) =
       (float)(fVar6 * (float10)*(float *)(param_1 + 0x30) + (float10)*(float *)(param_1 + 0x24));
  fVar6 = (float10)FUN_005b7cc0(local_8);
  *(float *)(param_1 + 0x48) =
       (float)(fVar6 * (float10)*(float *)(param_1 + 0x34) + (float10)*(float *)(param_1 + 0x28));
  fVar6 = (float10)FUN_005b7cc0(local_4);
  *(float *)(param_1 + 0x4c) =
       (float)(fVar6 * (float10)*(float *)(param_1 + 0x38) + (float10)*(float *)(param_1 + 0x2c));
  return;
}

