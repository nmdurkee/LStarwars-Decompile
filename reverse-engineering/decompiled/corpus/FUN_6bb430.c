/* Ghidra analysis pseudocode, not original source.
 * ev_7ed3362792c3ecc1c7f2b3fdd5b033605c88aa142786b47e04128bf45777c493
 * Entry: 0x6bb430; label: FUN_006bb430
 */

void FUN_006bb430(float *param_1,float param_2,int param_3,int param_4,int param_5,
                 undefined4 param_6,int param_7)

{
  int iVar1;
  float fVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  float local_30;
  float local_2c;
  float local_28;
  undefined4 local_24;
  float local_20;
  float local_1c;
  float local_18;
  undefined4 local_14;
  
  if (param_7 == 0) {
    param_7 = 0x10;
  }
  uVar3 = (uint)(0x10000 / (longlong)param_7);
  if (param_4 < param_5) {
    uVar4 = param_5 - param_4 & 0xffff;
    param_5 = param_4;
    if (0x7fff < uVar4) {
      uVar4 = uVar4 - 0x10000;
    }
  }
  else {
    uVar4 = param_4 - param_5 & 0xffff;
    if (0x7fff < uVar4) {
      uVar4 = uVar4 - 0x10000;
    }
  }
  while (0 < (int)uVar4) {
    if ((int)uVar3 < (int)uVar4) {
      uVar5 = uVar4 - uVar3;
      uVar4 = uVar3;
    }
    else {
      uVar5 = 0;
    }
    iVar1 = uVar4 + param_5;
    if (param_3 == 0) {
      local_14 = 0x3f800000;
      fVar2 = param_2 * 0.0;
      local_18 = param_2;
      local_20 = fVar2;
      local_1c = fVar2;
      FUN_005b35a0(&local_20,&local_20,-param_5);
      local_24 = 0x3f800000;
      local_28 = param_2;
      local_30 = fVar2;
      local_2c = fVar2;
      FUN_005b35a0(&local_30,&local_30,-iVar1);
    }
    else if (param_3 == 1) {
      local_14 = 0x3f800000;
      fVar2 = -param_2;
      local_20 = fVar2 * 0.0;
      local_1c = local_20;
      local_18 = fVar2;
      FUN_005b3620(&local_20,&local_20,-param_5);
      local_24 = 0x3f800000;
      local_30 = fVar2 * 0.0;
      local_2c = local_30;
      local_28 = fVar2;
      FUN_005b3620(&local_30,&local_30,-iVar1);
    }
    else if (param_3 == 2) {
      local_14 = 0x3f800000;
      fVar2 = param_2 * 0.0;
      local_1c = param_2;
      local_20 = fVar2;
      local_18 = fVar2;
      FUN_005b3690(&local_20,&local_20,-param_5);
      local_24 = 0x3f800000;
      local_2c = param_2;
      local_30 = fVar2;
      local_28 = fVar2;
      FUN_005b3690(&local_30,&local_30,-iVar1);
    }
    local_20 = *param_1 + local_20;
    local_1c = local_1c + param_1[1];
    local_18 = param_1[2] + local_18;
    local_30 = *param_1 + local_30;
    local_2c = local_2c + param_1[1];
    local_28 = param_1[2] + local_28;
    FUN_006bb310(param_1,&local_20,&local_30,param_6);
    param_5 = iVar1;
    uVar4 = uVar5;
  }
  return;
}

