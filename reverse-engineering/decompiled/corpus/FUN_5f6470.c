/* Ghidra analysis pseudocode, not original source.
 * ev_7cb997f3f06904df49554a3614ea3c2031937e13b6d92041b838b169c363bf2a
 * Entry: 0x5f6470; label: FUN_005f6470
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005f6470(undefined4 param_1,int param_2,short *param_3,float param_4,float param_5,
                 undefined4 param_6,float param_7,float param_8,float param_9,float param_10,
                 undefined4 param_11,undefined4 *param_12)

{
  uint uVar1;
  float fVar2;
  short sVar3;
  int iVar4;
  int extraout_EDX;
  undefined4 *puVar5;
  short *psVar6;
  undefined4 *puVar7;
  int iVar8;
  float10 fVar9;
  float10 fVar10;
  float10 fVar11;
  float10 extraout_ST1;
  float10 fVar12;
  float10 fVar13;
  undefined4 uVar14;
  short *local_238;
  float local_234;
  float local_230;
  float local_22c;
  float local_228;
  int local_224;
  int local_220;
  float local_21c;
  int local_218;
  float local_214;
  uint local_210;
  float local_20c;
  undefined4 local_208;
  short local_204 [256];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_238;
  local_214 = _DAT_009738b4;
  local_208 = *(undefined4 *)(param_2 + 0x24);
  local_224 = param_2;
  local_238 = (short *)0x20;
  if (_DAT_009738b4 == 0.0) {
    _DAT_009738b4 = *(float *)(param_2 + 0x1c);
  }
  **(undefined4 **)(param_2 + 0x48) = param_11;
  **(float **)(param_2 + 0x2c) = param_7;
  if (((byte)DAT_009738c4 & 4) == 0) {
    local_21c = param_8 * 0.5;
    **(float **)(param_2 + 0x30) = local_21c;
  }
  else {
    **(float **)(param_2 + 0x30) = param_8;
  }
  local_22c = _DAT_009738b4;
  fVar9 = (float10)FUN_005d0c50(param_2,&local_238);
  local_20c = (float)fVar9;
  local_220 = 0;
  if (param_12 != (undefined4 *)0x0) {
    puVar5 = param_12;
    puVar7 = (undefined4 *)(*(int *)(param_2 + 0x48) + 0x10);
    for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar7 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar7 = puVar7 + 1;
    }
  }
  local_21c = *(float *)(param_2 + 0x14) * **(float **)(param_2 + 0x30) * _DAT_0080b60c;
  iVar4 = FUN_004f5240();
  if (iVar4 == 0) {
    local_210 = 0xfffe;
  }
  else {
    local_210 = FUN_005d0aa0(*(undefined4 *)(param_2 + 0x38),*(undefined4 *)(param_2 + 0x10),0x2d);
    local_210 = local_210 & 0xffff;
  }
  do {
    local_228 = 0.0;
    local_230 = 0.0;
    local_218 = 0;
    *(undefined4 *)(param_2 + 0x24) = local_208;
    **(float **)(param_2 + 0x2c) = param_7;
    psVar6 = param_3;
    if (((byte)DAT_009738c4 & 4) == 0) {
      **(float **)(param_2 + 0x30) = param_8 * 0.5;
    }
    else {
      **(float **)(param_2 + 0x30) = param_8;
    }
    do {
      sVar3 = *psVar6;
      iVar8 = 0;
      iVar4 = 0;
      local_238 = psVar6;
      if (sVar3 != 0) {
        do {
          if (sVar3 == (short)local_210) break;
          if (sVar3 == 0x20) {
            sVar3 = psVar6[1];
            if ((((sVar3 != 0x21) && (sVar3 != 0x3f)) && (sVar3 != 0x2e)) && (sVar3 != 0x2c)) break;
            iVar4 = iVar4 + 1;
          }
          else {
            local_204[iVar8] = sVar3;
            local_204[iVar8 + 1] = 0;
            fVar9 = (float10)FUN_005d0c50(local_224,local_204);
            if ((float10)param_9 < fVar9) {
              local_204[iVar8] = 0;
              break;
            }
            iVar8 = iVar8 + 1;
          }
          sVar3 = psVar6[1];
          psVar6 = psVar6 + 1;
        } while (sVar3 != 0);
        if (0x100 < iVar8) {
          FUN_005c12e0();
        }
      }
      if (*psVar6 == (short)local_210) {
        local_204[iVar8] = (short)local_210;
        iVar8 = iVar8 + 1;
        psVar6 = psVar6 + 1;
      }
      sVar3 = *psVar6;
      while (sVar3 == 0x20) {
        psVar6 = psVar6 + 1;
        sVar3 = *psVar6;
      }
      local_204[iVar8] = 0;
      fVar9 = (float10)FUN_005d0c50(local_224,local_204);
      local_234 = (float)fVar9;
      fVar10 = (float10)local_230;
      fVar9 = (float10)local_234;
      if ((local_228 != 0.0) &&
         (local_234 = (float)(iVar4 + local_218 + (int)local_228),
         fVar13 = fVar9 + fVar10 + (float10)local_20c * (float10)(int)local_234,
         fVar13 < (float10)param_9 * (float10)_DAT_0080b610 ==
         (fVar13 == (float10)param_9 * (float10)_DAT_0080b610))) goto LAB_005f671f;
      local_228 = (float)((int)local_228 + 1);
      local_218 = local_218 + iVar4;
      local_230 = (float)(fVar9 + fVar10);
    } while (*psVar6 != 0);
    fVar10 = (float10)local_230;
    local_238 = psVar6;
LAB_005f671f:
    iVar4 = local_218;
    psVar6 = local_238;
    fVar13 = (float10)param_9;
    fVar9 = (float10)local_20c;
    if (0x200 < (int)((int)local_238 - (int)param_3 & 0xfffffffeU)) {
      fVar10 = (float10)FUN_005c12e0();
      local_228 = (float)extraout_EDX;
      fVar9 = extraout_ST1;
    }
    iVar8 = 0;
    while (param_3 < psVar6) {
      if (*param_3 == 0x20) {
        local_204[iVar8] = 0x20;
        param_3 = param_3 + 1;
        sVar3 = *param_3;
        while (sVar3 == 0x20) {
          param_3 = param_3 + 1;
          sVar3 = *param_3;
        }
      }
      else {
        local_204[iVar8] = *param_3;
        param_3 = param_3 + 1;
      }
      iVar8 = iVar8 + 1;
    }
    sVar3 = *psVar6;
    local_204[iVar8] = 0;
    if (sVar3 == 0) {
      fVar12 = fVar13 / ((float10)(iVar4 + -1 + (int)local_228) * fVar9 + fVar10);
      fVar11 = (float10)1;
      if (fVar12 <= fVar11) {
LAB_005f6810:
        fVar11 = fVar12;
      }
    }
    else if (local_228 == 1.4013e-45) {
      fVar11 = fVar13 / fVar10;
    }
    else {
      fVar12 = fVar13 / ((float10)(iVar4 + -1 + (int)local_228) * fVar9 + fVar10);
      fVar11 = (float10)_DAT_0080b614;
      if (fVar12 <= fVar11) goto LAB_005f6810;
    }
    local_238 = (short *)(float)fVar11;
    fVar11 = (float10)(float)local_238;
    local_234 = (float)(fVar11 * (float10)param_7);
    **(float **)(local_224 + 0x2c) = local_234;
    fVar2 = param_8;
    if (((byte)DAT_009738c4 & 4) == 0) {
      local_234 = param_8 * 0.5;
      fVar2 = local_234;
    }
    **(float **)(local_224 + 0x30) = fVar2;
    local_230 = (float)(fVar11 * fVar10);
    if (*psVar6 == 0) {
      fVar11 = fVar11 * (float10)local_22c;
    }
    else if (local_228 == 1.4013e-45) {
      fVar11 = (float10)local_22c;
    }
    else {
      uVar1 = iVar4 + -1 + (int)local_228;
      local_234 = (float)(((int)uVar1 < 0) - 1 & uVar1);
      fVar11 = ((float10)local_22c * (fVar13 - (float10)local_230)) /
               (fVar11 * fVar9 * (float10)(int)local_234);
    }
    _DAT_009738b4 = (float)fVar11;
    local_228 = param_4;
    local_238 = (short *)((float)local_220 * local_21c * param_10 + param_5);
    if (DAT_009738c0 != 4) {
      local_228 = param_4 * _DAT_0080b600 + _DAT_009738ac;
      local_238 = (short *)(((float)local_238 * _DAT_0080b604 + _DAT_009738b0) -
                           *(float *)(local_224 + 0x18) * **(float **)(local_224 + 0x30));
    }
    *(float *)(*(int *)(local_224 + 0x48) + 4) = local_228;
    *(short **)(*(int *)(local_224 + 0x48) + 8) = local_238;
    *(undefined4 *)(*(int *)(local_224 + 0x48) + 0xc) = param_6;
    if (param_12 == (undefined4 *)0x0) {
      uVar14 = 0;
    }
    else {
      uVar14 = 4;
    }
    FUN_005eb250(local_224,local_204,uVar14);
    local_220 = local_220 + 1;
    param_2 = local_224;
    param_3 = psVar6;
    if (*psVar6 == 0) {
      _DAT_009738b4 = local_214;
      *(undefined4 *)(local_224 + 0x24) = local_208;
      local_214 = (float)local_220 * local_21c * param_10;
      __security_check_cookie(local_4 ^ (uint)&local_238);
      return;
    }
  } while( true );
}

