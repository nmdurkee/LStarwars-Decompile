/* Ghidra pseudocode, not original source.
 * ev_77fef26266fe5967585df020e38eccd49263e70128ef006db684616fa6a4691c
 * Entry: 0x4851b0; label: FUN_004851b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004851b0(float param_1,float param_2,float param_3,undefined4 param_4,undefined4 param_5,
                 int param_6,int param_7)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined *puVar5;
  int *piVar6;
  int *piVar7;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 extraout_ST0_01;
  float10 fVar8;
  int *local_6c;
  float local_64;
  float local_60;
  float local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  int local_40 [12];
  float local_10;
  float local_c;
  float local_8;
  
  fVar1 = DAT_0093b0d4;
  local_60 = DAT_0093b0d0;
  local_64 = DAT_0093b0cc;
  puVar5 = PTR_DAT_00802c54;
  if (*(int *)(PTR_DAT_00802c54 + 0x2968) == 0) {
    return;
  }
  if (*(int *)(PTR_DAT_00802c54 + 0x296c) == 0) {
    return;
  }
  local_44 = param_4;
  local_48 = param_4;
  local_4c = param_4;
  local_50 = param_5;
  local_54 = param_5;
  local_58 = param_5;
  local_5c = DAT_0093b0d4;
  switch(*(undefined1 *)(DAT_0087a1a0 * 0x68 + 100 + *(int *)(PTR_DAT_00802c54 + 0x296c))) {
  case 0:
    iVar3 = FUN_006e6b90();
    local_64 = (float)(&DAT_029899a0)[iVar3 >> 1 & 0x7fff] * _DAT_007fa4e4 + local_64;
    break;
  case 1:
    iVar3 = FUN_006e6b90();
    local_64 = (float)(extraout_ST0 -
                      (float10)(float)(&DAT_029899a0)[iVar3 >> 1 & 0x7fff] * (float10)_DAT_007fa4e4)
    ;
    break;
  case 2:
    iVar3 = FUN_006e6b90();
    local_60 = (float)(&DAT_029899a0)[iVar3 >> 1 & 0x7fff] * _DAT_007fa4e4 + local_60;
    break;
  case 3:
    iVar3 = FUN_006e6b90();
    local_60 = (float)(extraout_ST0_00 -
                      (float10)(float)(&DAT_029899a0)[iVar3 >> 1 & 0x7fff] * (float10)_DAT_007fa4e4)
    ;
    break;
  case 4:
    iVar3 = FUN_006e6b90();
    fVar8 = extraout_ST0_01 -
            (float10)(float)(&DAT_029899a0)[iVar3 >> 1 & 0x7fff] * (float10)_DAT_007fa4e4;
    goto LAB_0048535f;
  case 5:
    iVar3 = FUN_006e6b90();
    fVar8 = (float10)(float)(&DAT_029899a0)[iVar3 >> 1 & 0x7fff] * (float10)_DAT_007fa4e4 +
            (float10)fVar1;
LAB_0048535f:
    local_5c = (float)fVar8;
  }
  iVar3 = 0;
  if (*(char *)(param_7 + 0xb6) != '\0') {
    iVar4 = 0;
    local_6c = &DAT_0087a370;
    do {
      if ((int)(uint)(byte)puVar5[0x2970] <= iVar3) {
        return;
      }
      if (param_6 <= iVar3) {
        return;
      }
      piVar6 = (int *)(*(int *)(puVar5 + 0x296c) + 0xc + iVar4);
      piVar7 = local_40;
      for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
        *piVar7 = *piVar6;
        piVar6 = piVar6 + 1;
        piVar7 = piVar7 + 1;
      }
      if (iVar3 < DAT_0087a1a0) {
        FUN_005b4a50(local_40,&local_4c);
      }
      else {
        FUN_005b4a50(local_40,&local_58);
        iVar2 = FUN_006e6b90();
        fVar1 = (float)(&DAT_029899a0)[iVar2 >> 1 & 0x7fff];
        iVar2 = *(int *)(PTR_DAT_00802c54 + 0x296c) + iVar4;
        switch(*(undefined1 *)(*(int *)(PTR_DAT_00802c54 + 0x296c) + 100 + iVar4)) {
        case 0:
          local_10 = local_10 - ((float)*(byte *)(iVar2 + 0x67) * 0.025 + 0.25) * fVar1;
          break;
        case 1:
          local_10 = ((float)*(byte *)(iVar2 + 0x67) * 0.025 + 0.25) * fVar1 + local_10;
          break;
        case 2:
          local_c = local_c - ((float)*(byte *)(iVar2 + 0x67) * 0.025 + 0.25) * fVar1;
          break;
        case 3:
          local_c = ((float)*(byte *)(iVar2 + 0x67) * 0.025 + 0.25) * fVar1 + local_c;
          break;
        case 4:
          local_8 = ((float)*(byte *)(iVar2 + 0x67) * 0.025 + 0.25) * fVar1 + local_8;
          break;
        case 5:
          local_8 = local_8 - ((float)*(byte *)(iVar2 + 0x67) * 0.025 + 0.25) * fVar1;
        }
      }
      if (iVar3 <= DAT_0087a1a0) {
        local_10 = local_10 + local_64;
        local_c = local_c + local_60;
        local_8 = local_8 + local_5c;
      }
      FUN_005b7d30(_DAT_0092505c,0x40000000);
      FUN_00482d50();
      FUN_005b7d30(_DAT_0092505c,0x400f5c29);
      FUN_00482e30();
      FUN_005b7d30(_DAT_0092505c,0x3fef5c29);
      FUN_00482c70();
      puVar5 = PTR_DAT_00802c54;
      local_10 = _DAT_0087b938 * param_1 + local_10;
      local_c = _DAT_0087b998 * param_2 + local_c;
      local_8 = local_8 + param_3;
      if (iVar3 < 10) {
        piVar6 = local_40;
        piVar7 = local_6c + -0x10;
        for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
          *piVar7 = *piVar6;
          piVar6 = piVar6 + 1;
          piVar7 = piVar7 + 1;
        }
        *local_6c = *(int *)(puVar5 + 0x296c) + iVar4;
        local_6c[1] = 1;
      }
      if (*(char *)(*(int *)(puVar5 + 0x2ac0) + 0xcee) != '\0') {
        FUN_00552e50(*(int *)(puVar5 + 0x296c) + iVar4,local_40);
      }
      local_6c = local_6c + 0x12;
      iVar3 = iVar3 + 1;
      iVar4 = iVar4 + 0x68;
      puVar5 = PTR_DAT_00802c54;
    } while (iVar3 < (int)(uint)*(byte *)(param_7 + 0xb6));
  }
  return;
}

