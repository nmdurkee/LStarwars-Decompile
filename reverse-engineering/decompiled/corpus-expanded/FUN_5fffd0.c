/* Ghidra pseudocode, not original source.
 * ev_64f3679a1f1e131a29792e896f5cd05cb4870e5bb22e267d9bfafa2e72f365ab
 * Entry: 0x5fffd0; label: FUN_005fffd0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005fffd0(undefined4 param_1,int param_2,float *param_3,float param_4,float *param_5,
                 undefined4 param_6,float param_7,int param_8)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  uint local_44;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  iVar6 = param_2;
  param_2 = 0x20;
  do {
    fVar2 = param_4 - param_3[0xb];
    local_44 = (uint)(longlong)ROUND(fVar2 * param_3[0xf]);
    if (local_44 < 0x3f) {
      fVar3 = (float)(int)local_44;
      if ((int)local_44 < 0) {
        fVar3 = fVar3 + 4.2949673e+09;
      }
      fVar3 = fVar2 * param_3[0xf] - fVar3;
      pfVar1 = (float *)(iVar6 + 0x4c + local_44 * 0x28);
      fVar5 = param_3[0xc] * fVar2 + param_3[8];
      fVar4 = *(float *)(iVar6 + 0x10) * fVar2 * fVar2 * 0.945 + param_3[0xd] * fVar2 + param_3[9];
      fVar2 = fVar2 * param_3[0xe] + param_3[10];
      _DAT_0097f9a8 = param_5[0xc] + fVar4 * param_5[4] + fVar5 * *param_5 + fVar2 * param_5[8];
      _DAT_0097f9ac = param_5[0xd] + param_5[9] * fVar2 + param_5[1] * fVar5 + param_5[5] * fVar4;
      _DAT_0097f9b0 = param_5[0xe] + fVar2 * param_5[10] + param_5[6] * fVar4 + param_5[2] * fVar5;
      if ((param_8 == 6) || (param_8 == 7)) {
        FUN_005ffee0(&DAT_0097f9a8);
      }
      if (param_7 <=
          _DAT_00987508 * _DAT_0097f9b0 +
          _DAT_00987500 * _DAT_0097f9a8 + _DAT_00987504 * _DAT_0097f9ac + _DAT_0098750c) {
        fVar2 = 1.0 - fVar3;
        local_24 = *pfVar1 * fVar2 + pfVar1[10] * fVar3;
        local_20 = pfVar1[1] * fVar2 + pfVar1[0xb] * fVar3;
        local_1c = pfVar1[2] * fVar2 + pfVar1[0xc] * fVar3;
        local_18 = pfVar1[6] * fVar2 + pfVar1[0x10] * fVar3;
        local_14 = pfVar1[7] * fVar2 + pfVar1[0x11] * fVar3;
        local_10 = pfVar1[8] * fVar2 + pfVar1[0x12] * fVar3;
        local_c = pfVar1[3] * fVar2 + pfVar1[0xd] * fVar3;
        local_8 = pfVar1[4] * fVar2 + pfVar1[0xe] * fVar3;
        local_4 = fVar2 * pfVar1[5] + pfVar1[0xf] * fVar3;
        FUN_005b30a0(&local_24,&local_24,&DAT_0097f978);
        FUN_005b30a0(&local_18,&local_18,&DAT_0097f978);
        FUN_005b30a0(&local_c,&local_c,&DAT_0097f978);
      }
    }
    param_2 = param_2 + -1;
    param_3 = param_3 + 8;
  } while (param_2 != 0);
  return;
}

