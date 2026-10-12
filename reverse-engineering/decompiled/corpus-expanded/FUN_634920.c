/* Ghidra pseudocode, not original source.
 * ev_1103904689436dd579d46533c258b0710963d6b5b648a9f295784d5cea761bb8
 * Entry: 0x634920; label: FUN_00634920
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00634920(float *param_1,int param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  float10 fVar6;
  float local_a0;
  float local_9c;
  float local_98;
  undefined4 local_94;
  float local_90;
  float local_8c;
  float local_88;
  float local_80;
  float local_7c;
  float local_78;
  float local_74;
  float local_70;
  float local_6c;
  float local_68;
  float local_60;
  float local_5c;
  float local_58;
  float local_50;
  float local_4c;
  float local_48;
  float local_40;
  float local_3c;
  undefined4 local_38;
  float local_30;
  float local_2c;
  undefined4 local_28;
  float local_20;
  float local_1c;
  undefined4 local_18;
  
  fVar6 = (float10)FUN_006b97c0(0x16);
  if (fVar6 == (float10)0.0) {
    DAT_02913950 = 0;
    return;
  }
  fVar2 = param_1[1];
  fVar3 = *param_1;
  fVar4 = param_1[2];
  local_7c = DAT_0097370c;
  local_80 = DAT_00973708;
  local_78 = DAT_00973710;
  local_74 = -(fVar4 * DAT_00973710 + fVar3 * DAT_00973708 + fVar2 * DAT_0097370c);
  iVar5 = FUN_006c0d20(param_2 + 0x20,param_2 + 0x30,&local_80,&local_50);
  if (iVar5 == 0) {
    return;
  }
  local_90 = local_50 - fVar3;
  local_8c = local_4c - fVar2;
  local_88 = local_48 - fVar4;
  fVar6 = (float10)FUN_006b9770(0x19);
  if ((fVar6 == (float10)0.0) && (fVar6 = (float10)FUN_006b97c0(0x19), fVar6 != (float10)0.0)) {
    fVar6 = (float10)FUN_006b97c0(0x19);
    if (fVar6 == (float10)0.0) {
      return;
    }
    if (DAT_02913950 == 1) {
      fVar6 = (float10)FUN_00634170();
      fVar2 = (float)fVar6;
      param_1[0xf] = fVar2;
      if (param_1[0x10] < fVar2) {
        param_1[0x10] = fVar2;
      }
    }
    if (DAT_02913950 != 2) {
      return;
    }
    fVar6 = (float10)FUN_00634170();
  }
  else {
    local_a0 = local_50 - fVar3;
    local_9c = local_4c - fVar2;
    local_98 = local_48 - fVar4;
    FUN_005b3b30(&local_a0,&local_a0);
    local_94 = 0x3f800000;
    fVar1 = param_1[0xf];
    local_60 = fVar3 + fVar1 * local_a0;
    local_5c = fVar2 + local_9c * fVar1;
    local_58 = fVar4 + local_98 * fVar1;
    fVar1 = param_1[0x10];
    local_70 = fVar1 * local_a0 + fVar3;
    local_6c = fVar2 + fVar1 * local_9c;
    local_68 = fVar4 + local_98 * fVar1;
    FUN_005d6430(&local_40,&local_50,1,0);
    FUN_005d6430(&local_30,&local_60,1,0);
    FUN_005d6430(&local_20,&local_70,1,0);
    local_18 = 0;
    local_28 = 0;
    local_38 = 0;
    fVar2 = (local_40 - local_30) * (local_40 - local_30) +
            (local_3c - local_2c) * (local_3c - local_2c) + 0.0;
    fVar3 = (local_40 - local_20) * (local_40 - local_20) +
            (local_3c - local_1c) * (local_3c - local_1c) + 0.0;
    if (fVar3 <= fVar2) {
      iVar5 = 2;
    }
    else {
      iVar5 = 1;
      fVar3 = fVar2;
    }
    DAT_02913950 = 0;
    if (fVar3 < _DAT_0080fd94 * _DAT_0080fd94) {
      DAT_02913950 = iVar5;
    }
    fVar6 = (float10)FUN_006b97c0(0x19);
    if (fVar6 == (float10)0.0) {
      return;
    }
    if (DAT_02913950 == 1) {
      fVar6 = (float10)FUN_00634170();
      fVar2 = (float)fVar6;
      param_1[0xf] = fVar2;
      if (param_1[0x10] < fVar2) {
        param_1[0x10] = fVar2;
      }
    }
    if (DAT_02913950 != 2) {
      return;
    }
    fVar6 = (float10)FUN_00634170();
  }
  fVar2 = (float)fVar6;
  param_1[0x10] = fVar2;
  if (param_1[0xf] <= fVar2) {
    return;
  }
  param_1[0xf] = fVar2;
  return;
}

