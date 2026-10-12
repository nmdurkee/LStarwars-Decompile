/* Ghidra pseudocode, not original source.
 * ev_6ac18c1e3533fe25fc33452ed7d20d92b2d33ecb9fa34638a091e07f32e3aa59
 * Entry: 0x410a10; label: FUN_00410a10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00410a10(undefined4 *param_1,int param_2)

{
  float *pfVar1;
  float fVar2;
  undefined4 uVar3;
  float fVar4;
  bool bVar5;
  short sVar6;
  int iVar7;
  undefined4 *puVar8;
  float *pfVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  float10 fVar12;
  float10 fVar13;
  char *pcVar14;
  float local_78;
  float local_70;
  float local_6c;
  float local_68;
  undefined4 local_64;
  undefined1 local_60 [16];
  undefined1 local_50 [76];
  
  if ((DAT_0093d7f0 != 0) && (435.0 < *(float *)(DAT_0093d7f0 + 0x69c))) {
    _DAT_007f160c = 2.0;
  }
  if (param_1[0x46] != 0) {
    iVar7 = param_1[0x35];
    if ((iVar7 == 0) || ((*(int *)(iVar7 + 0x524) != 0x55 && (*(int *)(iVar7 + 0x524) != 0x54)))) {
      param_1[0x43] = param_1[0x43] + -1;
    }
    else {
      param_1[0x43] = 0;
    }
    param_1[0x46] = param_1[0x46] + -1;
    if (param_1[0x43] == 0) {
      uVar3 = 0x40000000;
      if ((iVar7 != 0) && ((*(int *)(iVar7 + 0x524) == 0x55 || (*(int *)(iVar7 + 0x524) == 0x54))))
      {
        uVar3 = 0x3f800000;
      }
      iVar7 = param_1[0x34];
      param_1[0x39] = uVar3;
      if (iVar7 == 0) {
        local_70 = DAT_00802500;
        local_6c = DAT_00802504;
        local_68 = DAT_00802508;
      }
      else {
        local_70 = (float)param_1[0xc] - *(float *)(iVar7 + 0x30);
        local_6c = (float)param_1[0xd] - *(float *)(iVar7 + 0x34);
        local_68 = (float)param_1[0xe] - *(float *)(iVar7 + 0x38);
        *(undefined4 *)(iVar7 + 0x650) = param_1[0xc];
        *(undefined4 *)(iVar7 + 0x654) = param_1[0xd];
        *(undefined4 *)(iVar7 + 0x658) = param_1[0xe];
        *(undefined4 *)(iVar7 + 0x65c) = param_1[0xf];
      }
      fVar12 = (float10)FUN_005c0240(local_68 * local_68 + local_70 * local_70 + local_6c * local_6c
                                    );
      if ((float)fVar12 != 0.0) {
        iVar7 = FUN_0054fa60();
        fVar2 = (((_DAT_007f15f8 + 1.0) / 65535.0) * (float)iVar7) / (float)fVar12;
        local_70 = fVar2 * local_70;
        local_6c = local_6c * fVar2;
        local_68 = fVar2 * local_68;
      }
      param_1[0x18] = (float)param_1[0x18] + local_70;
      param_1[0x19] = (float)param_1[0x19] + local_6c;
      param_1[0x1a] = (float)param_1[0x1a] + local_68;
      iVar7 = FUN_0054fa60();
      param_1[0x3a] = (float)iVar7 * 1.0000153 - 32768.0;
      iVar7 = FUN_0054fa60();
      param_1[0x3b] = (float)iVar7 * 1.0000153 - 32768.0;
      if ((param_1[0x35] == 0) ||
         ((iVar7 = *(int *)(param_1[0x35] + 0x524), iVar7 != 0x55 && (iVar7 != 0x54)))) {
        FUN_0062c560(*(undefined4 *)(PTR_DAT_00802c54 + 0x134),0x17,param_1 + 0xc);
      }
    }
    if (param_1[0x43] == -2) {
      param_1[0x39] = 0;
    }
  }
  if (((int)param_1[0x43] < 1) &&
     ((param_1[0x35] == 0 ||
      ((iVar7 = *(int *)(param_1[0x35] + 0x524), iVar7 != 0x55 && (iVar7 != 0x54)))))) {
    fVar2 = (float)param_1[0x39] - _DAT_00925018;
    param_1[0x39] = fVar2;
    if (fVar2 < 0.0 != (fVar2 == 0.0)) {
      FUN_0062c560(*(undefined4 *)(PTR_DAT_00802c54 + 0x134),0x17,param_1 + 0xc);
      param_1[0x44] = 0;
      return 0;
    }
    sVar6 = FUN_006e6b90();
    FUN_005b4dd0(param_1,(int)sVar6);
    sVar6 = FUN_006e6b90();
    FUN_005b5240(param_1,(int)sVar6);
    pfVar9 = (float *)(param_1 + 0xc);
    local_70 = _DAT_00925018 * (float)param_1[0x18];
    local_6c = (float)param_1[0x19] * _DAT_00925018;
    local_68 = _DAT_00925018 * (float)param_1[0x1a];
    *pfVar9 = *pfVar9 + local_70;
    param_1[0xd] = (float)param_1[0xd] + local_6c;
    param_1[0xe] = (float)param_1[0xe] + local_68;
    FUN_00684c90(*(undefined4 *)(*(int *)(*(int *)(PTR_DAT_00802c54 + 0x134) + 8) + 0x3c0),pfVar9,1,
                 0,0);
    return 0;
  }
  puVar8 = (undefined4 *)param_1[0x34];
  if (puVar8 != (undefined4 *)0x0) {
    puVar10 = puVar8;
    puVar11 = param_1;
    for (iVar7 = 0x10; iVar7 != 0; iVar7 = iVar7 + -1) {
      *puVar11 = *puVar10;
      puVar10 = puVar10 + 1;
      puVar11 = puVar11 + 1;
    }
    param_1[0x18] = puVar8[0x18c];
    param_1[0x19] = puVar8[0x18d];
    param_1[0x1a] = puVar8[0x18e];
    param_1[0x1b] = puVar8[399];
    FUN_005b30a0(param_1 + 0xc,param_1 + 0x1c,puVar8);
    fVar2 = (float)param_1[0x38] - _DAT_00925018;
    param_1[0x38] = fVar2;
    if (0.0 < fVar2) {
      return 1;
    }
    local_70 = 0.0;
    local_6c = 0.0;
    local_68 = -10.0;
    local_64 = 0x3f800000;
    FUN_005b30a0(&local_70,&local_70,param_1);
    param_1[0x38] = 0x3f800000;
    return 1;
  }
  if (param_1[0x35] == 0) {
    return 0;
  }
  bVar5 = false;
  local_70 = (float)param_1[0x20] - (float)param_1[0xc];
  pfVar1 = (float *)(param_1 + 0x20);
  pfVar9 = (float *)(param_1 + 0xc);
  local_6c = (float)param_1[0x21] - (float)param_1[0xd];
  local_68 = (float)param_1[0x22] - (float)param_1[0xe];
  local_78 = local_68 * local_68 + local_70 * local_70 + local_6c * local_6c;
  if (0.0 < (float)param_1[0x39] != ((float)param_1[0x39] == 0.0)) {
    param_1[0x39] = (float)param_1[0x39] - _DAT_00925018;
  }
  while (local_78 < 25.0) {
    fVar2 = _DAT_007f15dc + (float)param_1[0x36];
    param_1[0x36] = fVar2;
    if (fVar2 <= 1.0) {
      FUN_0040eff0(param_1[0x35],pfVar1,fVar2);
      if (*(short *)((int)param_1 + 0xfe) == -0x133) {
        *pfVar1 = (float)param_1[4] * _DAT_007f160c + *pfVar1;
        param_1[0x21] = (float)param_1[5] * _DAT_007f160c + (float)param_1[0x21];
        param_1[0x22] = (float)param_1[6] * _DAT_007f160c + (float)param_1[0x22];
      }
      local_70 = *pfVar1 - *pfVar9;
      local_6c = (float)param_1[0x21] - (float)param_1[0xd];
      local_68 = (float)param_1[0x22] - (float)param_1[0xe];
      local_78 = local_68 * local_68 + local_70 * local_70 + local_6c * local_6c;
    }
    else {
      bVar5 = true;
      param_1[0x36] = fVar2 - 1.0;
      local_78 = 1e+06;
    }
  }
  fVar2 = ((float)param_1[0xe] - DAT_00973720) * DAT_00973710 +
          (*pfVar9 - DAT_00973718) * DAT_00973708 +
          ((float)param_1[0xd] - DAT_0097371c) * DAT_0097370c;
  if (fVar2 < 0.0) {
    if (-2.0 <= fVar2) goto LAB_00411015;
    fVar2 = 0.5;
  }
  else {
    fVar2 = 1.0;
LAB_00411015:
    fVar2 = fVar2 * 0.25 + 1.0;
  }
  switch(*(undefined2 *)((int)param_1 + 0xfe)) {
  case 0xfed4:
    pcVar14 = "Dog_CloneARC170EngLp";
    break;
  case 0xfed5:
    if ((int)param_1[0x43] < 1) goto switchD_00411036_default;
    pcVar14 = "Dog_TriFighterEngLp";
    break;
  case 0xfed6:
  case 0xfed7:
    if ((int)param_1[0x43] < 1) goto switchD_00411036_default;
    pcVar14 = "Dog_DroidFighterEngLp";
    break;
  default:
    goto switchD_00411036_default;
  }
  FUN_006514b0(pcVar14,pfVar9,fVar2);
switchD_00411036_default:
  if (bVar5) {
    param_1[0x44] = 0;
  }
  else {
    fVar12 = (float10)FUN_005c0240(local_78);
    fVar2 = (float)fVar12;
    if (fVar2 != 0.0) {
      fVar4 = (float)param_1[0x3d] / fVar2;
      param_1[0x18] = fVar4 * local_70;
      param_1[0x19] = local_6c * fVar4;
      param_1[0x1a] = fVar4 * local_68;
      local_70 = _DAT_00925018 * (float)param_1[0x18];
      local_6c = (float)param_1[0x19] * _DAT_00925018;
      local_68 = _DAT_00925018 * (float)param_1[0x1a];
      *pfVar9 = *pfVar9 + local_70;
      param_1[0xd] = (float)param_1[0xd] + local_6c;
      param_1[0xe] = (float)param_1[0xe] + local_68;
      FUN_004102c0(&local_70,fVar2 / 5.0,0.0 < (float)param_1[0x39]);
      param_1[0x24] = local_70;
      param_1[0x25] = local_6c;
      param_1[0x26] = local_68;
      param_1[0x27] = local_64;
    }
  }
  fVar12 = (float10)0;
  param_1[0xf] = 0x3f800000;
  if (param_1[0x48] == 0) {
    if (fVar12 == (float10)(float)param_1[0x37]) {
      if (((*(short *)((int)param_1 + 0x102) != 0) ||
          (fVar12 = (float10)FUN_00410940(), *(short *)((int)param_1 + 0x102) != 0)) &&
         (*(short *)((int)param_1 + 0xfe) != -0x133)) {
        if ((param_1[0x47] != 0) && (fVar12 < (float10)(float)param_1[0x33])) {
          param_1[0x33] = (float)param_1[0x33] - _DAT_007f1600 * _DAT_00925018;
        }
        if (fVar12 < (float10)(float)param_1[0x38]) {
          param_1[0x38] = (float)param_1[0x38] - _DAT_00925018;
          return 1;
        }
        fVar12 = (float10)FUN_005b9dd0();
        param_1[0x38] =
             (float)((float10)0.20000000298023224 + fVar12 * (float10)0.20000000298023224);
        if (param_2 != 0) {
          iVar7 = FUN_004104f0(local_60,local_50,0x42960000);
          if (iVar7 == 0) {
            if (((param_1[0x49] != 0) && (*(int *)(param_1[0x35] + 0x524) != 0x55)) &&
               ((*(int *)(param_1[0x35] + 0x524) != 0x54 &&
                ((fVar12 = (float10)FUN_005b9dd0(), fVar12 < (float10)0.20000000298023224 &&
                 (puVar8 = (undefined4 *)FUN_00410050(), puVar8 != (undefined4 *)0x0)))))) {
              param_1[0x49] = param_1[0x49] + -1;
              puVar10 = param_1;
              puVar11 = puVar8;
              for (iVar7 = 0x4c; iVar7 != 0; iVar7 = iVar7 + -1) {
                *puVar11 = *puVar10;
                puVar10 = puVar10 + 1;
                puVar11 = puVar11 + 1;
              }
              puVar8[0x3d] = (float)puVar8[0x3d] + 10.0;
              *(undefined2 *)((int)puVar8 + 0xfe) = 0xfecd;
              pfVar9 = (float *)(puVar8 + 0xc);
              *pfVar9 = (float)puVar8[4] * _DAT_007f160c + *pfVar9;
              puVar8[0xd] = (float)puVar8[5] * _DAT_007f160c + (float)puVar8[0xd];
              fVar2 = (float)puVar8[6] * _DAT_007f160c + (float)puVar8[0xe];
              puVar8[0xe] = fVar2;
              fVar2 = fVar2 - DAT_00973720;
              if ((*pfVar9 - DAT_00973718) * (*pfVar9 - DAT_00973718) +
                  ((float)puVar8[0xd] - DAT_0097371c) * ((float)puVar8[0xd] - DAT_0097371c) +
                  fVar2 * fVar2 < 40000.0) {
                FUN_00681f40("Ep3_1_ProtoXWingMissile",pfVar9);
              }
            }
            FUN_0040ef00(local_60,0x40200000,*(short *)((int)param_1 + 0xfe) == -300,
                         (int)*(short *)((int)param_1 + 0xfe));
            param_1[0x47] = 1;
            return 1;
          }
          if ((iVar7 == 1) && (param_1[0x47] != 0)) {
            param_1[0x48] = 1;
            return 1;
          }
        }
      }
    }
    else {
      fVar13 = (float10)((float)param_1[0x37] - _DAT_00925018);
      param_1[0x37] = (float)param_1[0x37] - _DAT_00925018;
      if (fVar13 < fVar12 != (fVar13 == fVar12)) {
        param_1[0x37] = (float)fVar12;
        param_1[0x33] = _DAT_007f15fc;
        return 1;
      }
    }
  }
  return 1;
}

