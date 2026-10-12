/* Ghidra analysis pseudocode, not original source.
 * ev_c620959d101751dfad3e645b6324ffe52b1a2e87d0642b2a26c15ecb61f6256d
 * Entry: 0x6bbec0; label: FUN_006bbec0
 */

void FUN_006bbec0(float *param_1,float *param_2,undefined4 param_3,undefined4 param_4,float param_5,
                 float param_6,float param_7,float param_8)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float10 fVar5;
  float local_b4;
  float local_80;
  float local_7c;
  float local_78;
  float local_70;
  float local_6c;
  float local_68;
  int local_5c;
  int local_58;
  undefined4 local_54;
  undefined1 local_50 [76];
  
  fVar2 = *param_2 - *param_1;
  fVar3 = param_2[1] - param_1[1];
  fVar4 = param_2[2] - param_1[2];
  fVar5 = (float10)FUN_005c0240(fVar4 * fVar4 + fVar3 * fVar3 + fVar2 * fVar2);
  fVar1 = (float)fVar5;
  if (0.0 < fVar1) {
    local_68 = 1.0 / fVar1;
    local_70 = local_68 * fVar2;
    local_6c = local_68 * fVar3;
    local_68 = local_68 * fVar4;
    fVar1 = fVar1 * 0.4;
    local_b4 = fVar1 * param_7 + param_8;
    if ((local_70 == 0.0) && (local_68 == 0.0)) {
      local_5c = -0x4000;
      local_58 = 0;
    }
    else {
      local_58 = FUN_005be2d0(local_70,local_68);
      FUN_005b3620(&local_70,&local_70,-local_58);
      local_5c = FUN_005be2d0(local_6c,local_68);
      local_5c = -local_5c;
    }
    local_54 = 0;
    if (local_b4 < param_5) {
      local_b4 = param_5;
    }
    if (param_6 < local_b4) {
      local_b4 = param_6;
    }
    local_80 = fVar2 * 0.4 + *param_1;
    local_7c = fVar3 * 0.4 + param_1[1];
    local_78 = param_1[2] + fVar4 * 0.4;
    thunk_FUN_005b5300(local_50,&local_5c);
    FUN_005b4900(local_50,&local_80);
    FUN_006bb6b0(local_50,fVar1,local_b4,local_b4,param_3,param_4,1,0);
    FUN_005b4930(local_50,&local_80);
    local_80 = *param_2 - fVar2 * 0.1;
    local_7c = param_2[1] - fVar3 * 0.1;
    local_78 = param_2[2] - fVar4 * 0.1;
    FUN_005b4900(local_50,&local_80);
    FUN_006bb6b0(local_50,fVar1 * 0.25,local_b4 * 1.6,0,param_3,param_4,1,0);
    return;
  }
  return;
}

