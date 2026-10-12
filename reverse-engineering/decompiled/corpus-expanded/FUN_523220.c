/* Ghidra pseudocode, not original source.
 * ev_1b4e61f1467db5c8e431c69a2548c20deac6709d01307c3b7894b5c0724271ef
 * Entry: 0x523220; label: FUN_00523220
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00523220(int param_1,int param_2,undefined4 param_3)

{
  float *pfVar1;
  float *pfVar2;
  float fVar3;
  short sVar4;
  float10 fVar5;
  float local_60 [2];
  float local_58;
  float afStack_54 [2];
  float fStack_4c;
  float local_48;
  float local_44;
  float local_40;
  undefined4 local_30;
  float local_24;
  float local_20;
  float local_1c;
  undefined4 local_c;
  
  pfVar1 = (float *)(param_2 + 0x18);
  pfVar2 = (float *)(param_1 + 0x18);
  fVar5 = (float10)FUN_005bed80(pfVar2,pfVar1,local_60);
  fVar3 = (float)fVar5;
  if (0.0 < fVar3) {
    local_60[0] = local_60[0] / fVar3;
    local_58 = local_58 / fVar3;
  }
  if (*(float *)(param_2 + 0x24) == *(float *)(param_1 + 0x24)) {
    local_48 = *pfVar2 + local_58 * *(float *)(param_1 + 0x24);
    local_44 = _DAT_00801cc8 + *(float *)(param_1 + 0x1c);
    local_30 = param_3;
    local_c = param_3;
    local_40 = *(float *)(param_1 + 0x20) - local_60[0] * *(float *)(param_1 + 0x24);
    local_24 = *pfVar1 + *(float *)(param_2 + 0x24) * local_58;
    local_20 = _DAT_00801cc8 + *(float *)(param_2 + 0x1c);
    local_1c = *(float *)(param_2 + 0x20) - *(float *)(param_2 + 0x24) * local_60[0];
    FUN_00512b00(&local_48,0,0);
    local_48 = *pfVar2 - local_58 * *(float *)(param_1 + 0x24);
    local_30 = param_3;
    local_44 = _DAT_00801cc8 + *(float *)(param_1 + 0x1c);
    local_40 = *(float *)(param_1 + 0x20) + local_60[0] * *(float *)(param_1 + 0x24);
    local_24 = *pfVar1 - *(float *)(param_2 + 0x24) * local_58;
    local_c = param_3;
    local_20 = _DAT_00801cc8 + *(float *)(param_2 + 0x1c);
    local_1c = local_60[0] * *(float *)(param_2 + 0x24) + *(float *)(param_2 + 0x20);
    FUN_00512b00(&local_48,0,0);
    return;
  }
  sVar4 = FUN_00512900((*(float *)(param_2 + 0x24) - *(float *)(param_1 + 0x24)) / fVar3);
  FUN_005b3620(afStack_54,local_60,(int)(short)(0x4000 - sVar4));
  local_48 = *pfVar2 + afStack_54[0] * *(float *)(param_1 + 0x24);
  local_44 = _DAT_00801cc8 + *(float *)(param_1 + 0x1c);
  local_30 = param_3;
  local_c = param_3;
  local_40 = *(float *)(param_1 + 0x20) + fStack_4c * *(float *)(param_1 + 0x24);
  local_24 = *pfVar1 + *(float *)(param_2 + 0x24) * afStack_54[0];
  local_20 = _DAT_00801cc8 + *(float *)(param_2 + 0x1c);
  local_1c = fStack_4c * *(float *)(param_2 + 0x24) + *(float *)(param_2 + 0x20);
  FUN_00512b00(&local_48,0,0);
  FUN_005b3620(afStack_54,local_60,-(int)(short)(0x4000 - sVar4));
  local_48 = *pfVar2 + afStack_54[0] * *(float *)(param_1 + 0x24);
  local_30 = param_3;
  local_c = param_3;
  local_44 = _DAT_00801cc8 + *(float *)(param_1 + 0x1c);
  local_40 = *(float *)(param_1 + 0x20) + fStack_4c * *(float *)(param_1 + 0x24);
  local_24 = *pfVar1 + *(float *)(param_2 + 0x24) * afStack_54[0];
  local_20 = _DAT_00801cc8 + *(float *)(param_2 + 0x1c);
  local_1c = fStack_4c * *(float *)(param_2 + 0x24) + *(float *)(param_2 + 0x20);
  FUN_00512b00(&local_48,0,0);
  return;
}

