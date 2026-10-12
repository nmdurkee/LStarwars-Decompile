/* Ghidra analysis pseudocode, not original source.
 * ev_c620959d101751dfad3e645b6324ffe52b1a2e87d0642b2a26c15ecb61f6256d
 * Entry: 0x6bbc30; label: FUN_006bbc30
 */

void FUN_006bbc30(float *param_1,float *param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,float param_6,float param_7,float param_8)

{
  float fVar1;
  float fVar2;
  int iVar3;
  float10 fVar4;
  float local_a8;
  float local_a0;
  float local_9c;
  float local_98;
  float local_90;
  float local_8c;
  float local_88;
  float local_80;
  float local_7c;
  float local_78;
  undefined4 local_74;
  float local_70;
  float local_6c;
  float local_68;
  float local_60;
  float local_5c;
  float local_58;
  undefined4 local_54;
  undefined1 local_50 [76];
  
  local_a0 = *param_2 - *param_1;
  local_9c = param_2[1] - param_1[1];
  local_98 = param_2[2] - param_1[2];
  local_90 = local_a0;
  local_8c = local_9c;
  local_88 = local_98;
  fVar4 = (float10)FUN_005c0240(local_a0 * local_a0 + local_9c * local_9c + local_98 * local_98);
  fVar1 = (float)fVar4;
  if (0.0 < fVar1) {
    fVar2 = 1.0 / fVar1;
    local_a0 = fVar2 * local_a0;
    local_9c = fVar2 * local_9c;
    local_98 = fVar2 * local_98;
    if ((local_a0 == 0.0) && (local_98 == 0.0)) {
      local_90 = 1.14794e-41;
      local_8c = 0.0;
    }
    else {
      local_8c = (float)FUN_005be2d0(local_a0,local_98);
      FUN_005b3620(&local_a0,&local_a0,-(int)local_8c);
      iVar3 = FUN_005be2d0(local_9c,local_98);
      local_90 = (float)-iVar3;
    }
    local_70 = *param_2 + *param_1;
    local_88 = 0.0;
    local_6c = param_1[1] + param_2[1];
    local_68 = param_1[2] + param_2[2];
    local_80 = local_70 * 0.5;
    local_7c = local_6c * 0.5;
    local_78 = local_68 * 0.5;
    local_54 = local_74;
    local_60 = local_80;
    local_5c = local_7c;
    local_58 = local_78;
    thunk_FUN_005b5300(local_50,&local_90);
    FUN_005b4900(local_50,&local_60);
    param_6 = fVar1 * 0.5 * param_6;
    local_a8 = param_6 * 0.1;
    if (param_6 < param_7) {
      param_6 = param_7;
    }
    if (param_8 < param_6) {
      param_6 = param_8;
    }
    if (local_a8 < param_7) {
      local_a8 = param_7;
    }
    if (param_8 < local_a8) {
      local_a8 = param_8;
    }
    FUN_006bb6b0(local_50,fVar1 * 0.5,param_6,local_a8,param_3,param_4,1,1);
    return;
  }
  return;
}

