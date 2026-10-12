/* Ghidra pseudocode, not original source.
 * ev_1b4e61f1467db5c8e431c69a2548c20deac6709d01307c3b7894b5c0724271ef
 * Entry: 0x5236d0; label: FUN_005236d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005236d0(float *param_1,float param_2,undefined4 *param_3,uint param_4,int param_5)

{
  float fVar1;
  float fVar2;
  uint *puVar3;
  int iVar4;
  float10 fVar5;
  float local_78 [2];
  float local_70;
  float local_6c;
  float local_68;
  float local_64;
  undefined4 local_60;
  float local_5c;
  undefined4 local_58;
  float local_54;
  float local_48;
  float local_44;
  float local_40;
  int local_30;
  float local_24;
  float local_20;
  float local_1c;
  int local_c;
  
  if (param_4 != 0) {
    local_6c = *param_1;
    iVar4 = 0;
    local_68 = _DAT_00801cc8 + param_1[1];
    local_64 = param_1[2];
    local_60 = *param_3;
    local_5c = _DAT_00801cc8 + (float)param_3[1];
    local_58 = param_3[2];
    if (0 < DAT_00923914) {
      puVar3 = &DAT_00923918;
      do {
        if ((puVar3[1] != 0) && ((*puVar3 & param_4) != 0)) {
          (*(code *)puVar3[1])(&local_6c,param_2,&local_60,param_4,param_5);
          return;
        }
        iVar4 = iVar4 + 1;
        puVar3 = puVar3 + 0x13;
      } while (iVar4 < DAT_00923914);
    }
    fVar5 = (float10)FUN_005bed80(&local_60,&local_6c,local_78);
    fVar1 = (float)fVar5;
    if (0.0 < fVar1) {
      local_78[0] = local_78[0] / fVar1;
      local_70 = local_70 / fVar1;
    }
    local_48 = local_6c;
    local_24 = (float)local_60;
    local_44 = local_68;
    local_40 = local_64;
    local_30 = param_5;
    local_20 = local_5c;
    local_1c = (float)local_58;
    local_c = param_5;
    FUN_00512b00(&local_48,0,0);
    FUN_005b3830(&local_48,local_78,param_2 * 0.5);
    local_44 = 0.0;
    FUN_005b37d0(&local_48,&local_48,&local_6c);
    local_24 = local_6c + param_2 * local_70 * 0.5;
    local_20 = local_68;
    local_1c = local_64 - local_78[0] * param_2 * 0.5;
    FUN_00512b00(&local_48,0,0);
    local_20 = local_68;
    local_24 = local_6c - param_2 * local_70 * 0.5;
    local_1c = param_2 * local_78[0] * 0.5 + local_64;
    FUN_00512b00(&local_48,0,0);
    fVar2 = local_40;
    fVar1 = local_44;
    if ((param_4 & 0x40000000) != 0) {
      FUN_005b3830(&local_48,local_78,param_2 * 0.5);
      local_44 = 0.0;
      FUN_005b37d0(&local_48,&local_48,&local_6c);
      fVar1 = param_2 * local_70 * 0.5;
      local_20 = local_44;
      fVar2 = local_78[0] * param_2 * 0.5;
      local_24 = local_48 - fVar1;
      local_1c = fVar2 + local_40;
      local_48 = local_48 + fVar1;
      local_40 = local_40 - fVar2;
      FUN_00512b00(&local_48,0,0);
      return;
    }
    if ((int)param_4 < 0) {
      local_24 = local_48 + param_2 * local_70 * 0.25;
      local_30 = param_5 / 2;
      local_54 = local_48;
      local_20 = local_44;
      local_1c = local_40 - local_78[0] * param_2 * 0.25;
      local_c = local_30;
      FUN_00512b00(&local_48,0,0);
      local_20 = fVar1;
      local_24 = local_54 - param_2 * local_70 * 0.25;
      local_1c = param_2 * local_78[0] * 0.25 + fVar2;
      FUN_00512b00(&local_48,0,0);
      return;
    }
    if ((param_4 & 0x20000000) != 0) {
      local_54 = local_48;
      FUN_005b3830(&local_48,local_78,param_2);
      local_44 = 0.0;
      FUN_005b37d0(&local_48,&local_48,param_1);
      local_20 = fVar1;
      local_24 = local_54 + param_2 * local_70 * 0.15;
      local_1c = fVar2 - local_78[0] * param_2 * 0.15;
      FUN_00512b00(&local_48,0,0);
      local_20 = fVar1;
      local_24 = local_54 - param_2 * local_70 * 0.25;
      local_1c = param_2 * local_78[0] * 0.25 + fVar2;
      FUN_00512b00(&local_48,0,0);
      local_20 = fVar1;
      local_24 = local_54 - param_2 * local_70 * 0.35;
      local_1c = param_2 * local_78[0] * 0.35 + fVar2;
      FUN_00512b00(&local_48,0,0);
    }
  }
  return;
}

