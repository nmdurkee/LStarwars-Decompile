/* Ghidra pseudocode, not original source.
 * ev_f56492005d3db2572965d416e35be25a43fb24333701b400d47d471ee6ec09ab
 * Entry: 0x471650; label: FUN_00471650
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00471650(int param_1)

{
  float fVar1;
  char cVar2;
  byte bVar3;
  undefined4 *puVar4;
  short *psVar5;
  bool bVar6;
  undefined4 uVar7;
  undefined2 uVar8;
  int iVar9;
  float *pfVar10;
  undefined4 *puVar11;
  float *pfVar12;
  uint uVar13;
  uint uVar14;
  undefined4 *puVar15;
  uint *puVar16;
  undefined4 *puVar17;
  bool bVar18;
  undefined2 in_FPUControlWord;
  float10 fVar19;
  float10 fVar20;
  float10 extraout_ST0;
  float10 extraout_ST1;
  int local_80;
  int local_7c;
  float local_78;
  float local_74;
  float local_70;
  undefined8 local_6c;
  float local_64;
  float *local_60;
  float local_5c;
  float local_58;
  float local_54;
  int local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40 [12];
  float local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  puVar4 = *(undefined4 **)(param_1 + 0x46ec);
  local_7c = 0;
  local_80 = 0;
  if (puVar4 == (undefined4 *)0x0) {
    return;
  }
  iVar9 = puVar4[0x145];
  if ((iVar9 != 0) &&
     ((((*(uint *)(iVar9 + 0x1fc) & 1) == 0 || ((*(uint *)(iVar9 + 0x1fc) & 0x1000) == 0)) ||
      (*(char *)(iVar9 + 0x28b) != '\0')))) {
    puVar4[0x145] = 0;
  }
  if (0.0 < (float)puVar4[0x155]) {
    puVar4[0x155] = (float)puVar4[0x155] - _DAT_00925018;
  }
  local_78 = (float)puVar4[0x123];
  pfVar12 = (float *)(puVar4 + 0x123);
  local_74 = (float)puVar4[0x124];
  local_70 = (float)puVar4[0x125];
  puVar4[299] = 0;
  local_5c = *pfVar12;
  puVar4[0x12a] = 0;
  local_58 = (float)puVar4[0x124];
  puVar4[0x129] = 0;
  local_54 = (float)puVar4[0x125];
  local_50 = 0;
  local_60 = pfVar12;
  local_80 = FUN_0055ce20((int)DAT_007f1974,0,0,1,0);
  if (DAT_007f1978 == -1) {
LAB_0047175f:
    if (local_80 != 0) goto LAB_00471792;
    if (DAT_007f39e4 == 0) {
      FUN_004cd9a0(puVar4 + 0x13f,&local_7c,&local_80);
      goto LAB_0047179c;
    }
LAB_004718b6:
    iVar9 = puVar4[0x147];
    if (((iVar9 == 0) || ((*(byte *)(iVar9 + 0x94) & 2) == 0)) ||
       (*(int *)(*(int *)(iVar9 + 0x34) + 0xc) != 2)) {
      bVar18 = false;
    }
    else {
      bVar18 = true;
    }
    iVar9 = puVar4[0x148];
    if (((iVar9 == 0) || ((*(byte *)(iVar9 + 0x94) & 2) == 0)) ||
       (*(int *)(*(int *)(iVar9 + 0x34) + 0xc) != 2)) {
      bVar6 = false;
    }
    else {
      bVar6 = true;
    }
    if (bVar18) {
      if (!bVar6) {
        fVar1 = -(float)puVar4[0x14d];
LAB_0047191a:
        puVar4[0x129] = fVar1;
      }
    }
    else if (bVar6) {
      fVar1 = (float)puVar4[0x14d];
      goto LAB_0047191a;
    }
    iVar9 = puVar4[0x149];
    if (((iVar9 == 0) || ((*(byte *)(iVar9 + 0x94) & 2) == 0)) ||
       (*(int *)(*(int *)(iVar9 + 0x34) + 0xc) != 2)) {
      bVar18 = false;
    }
    else {
      bVar18 = true;
    }
    iVar9 = puVar4[0x14a];
    if (((iVar9 == 0) || ((*(byte *)(iVar9 + 0x94) & 2) == 0)) ||
       (*(int *)(*(int *)(iVar9 + 0x34) + 0xc) != 2)) {
      bVar6 = false;
    }
    else {
      bVar6 = true;
    }
    if (bVar18) {
      if (!bVar6) {
        fVar1 = (float)puVar4[0x14d];
LAB_00471984:
        puVar4[299] = fVar1;
      }
    }
    else if (bVar6) {
      fVar1 = -(float)puVar4[0x14d];
      goto LAB_00471984;
    }
    iVar9 = FUN_005cfd60(puVar4 + 0x13f);
    if (iVar9 == 0) {
      puVar4[299] = 0;
      puVar4[0x129] = 0;
    }
  }
  else {
    if (local_80 == 0) {
      if (DAT_007f39e4 != 0) {
        FUN_0055ce20((int)DAT_007f1978,0,0,1,0);
      }
      goto LAB_0047175f;
    }
LAB_00471792:
    local_7c = *(int *)(local_80 + 0xca4);
LAB_0047179c:
    if (((local_80 == 0) || ((*(int *)(local_80 + 0xcd0) == 0 && (DAT_007f39e4 != 0)))) ||
       ((*(byte *)(local_80 + 0x1fc) & 0x80) == 0)) goto LAB_004718b6;
    if (0.0 < *(float *)(local_7c + 0x28)) {
      if (*(char *)(DAT_00879468 + 0x562) == '\0') {
        uVar14 = FUN_0054b3d0(local_80,local_7c);
        uVar14 = uVar14 & 0xffff;
        if (*(char *)(DAT_00879468 + 0x563) == '\0') {
          fVar1 = (float)(&DAT_029899a0)[uVar14 >> 1] * (float)puVar4[0x14d];
        }
        else {
          fVar1 = (float)(&DAT_029899a0)[uVar14 >> 1] * (float)puVar4[0x14d] * -1.0;
        }
        puVar4[0x129] = fVar1;
        puVar4[299] = (float)(&DAT_029899a0)[(int)(uVar14 + 0x4000) >> 1 & 0x7fff] *
                      (float)puVar4[0x14d];
      }
      else {
        puVar4[0x129] = 0;
        puVar4[0x12a] = *(float *)(local_7c + 0x30) * (float)puVar4[0x14d];
        if (*(char *)(DAT_00879468 + 0x563) == '\0') {
          puVar4[299] = *(float *)(local_7c + 0x2c) * (float)puVar4[0x14d];
        }
        else {
          puVar4[299] = *(float *)(local_7c + 0x2c) * (float)puVar4[0x14d] * -1.0;
        }
      }
    }
  }
  pfVar10 = (float *)(puVar4 + 0x126);
  fVar19 = (float10)FUN_0054fb40(*pfVar10,puVar4[0x129],0x40a00000);
  *pfVar10 = (float)fVar19;
  fVar19 = (float10)FUN_0054fb40(puVar4[0x127],puVar4[0x12a],0x40a00000);
  puVar4[0x127] = (float)fVar19;
  fVar19 = (float10)FUN_0054fb40(puVar4[0x128],puVar4[299],0x40a00000);
  puVar4[0x128] = (float)fVar19;
  if (((*(byte *)((int)puVar4 + 0x559) & 8) != 0) &&
     (((float)puVar4[0x129] != 0.0 || ((float)puVar4[299] != 0.0)))) {
    uVar8 = FUN_005be2d0(puVar4[0x129],puVar4[299]);
    *(undefined2 *)(puVar4 + 0x157) = uVar8;
  }
  fVar19 = (float10)0;
  local_78 = local_78 + _DAT_00925018 * *pfVar10;
  local_74 = (float)puVar4[0x127] * _DAT_00925018 + local_74;
  local_70 = _DAT_00925018 * (float)puVar4[0x128] + local_70;
  if (*(int *)(param_1 + 0x128) == DAT_0087b1bc) {
    if (local_70 < 11.84) {
      fVar1 = 10.125;
      if (local_70 < 10.125) goto LAB_00471af2;
    }
    else {
      fVar1 = 11.84;
LAB_00471af2:
      puVar4[299] = (float)fVar19;
      puVar4[0x128] = (float)fVar19;
      local_70 = fVar1;
    }
    if (-4.85 <= local_74) {
      if (local_74 <= -3.9) goto LAB_00471c77;
      local_74 = -3.9;
    }
    else {
      local_74 = -4.85;
    }
    puVar4[0x12a] = (float)fVar19;
    puVar4[0x127] = (float)fVar19;
  }
  else if (*(int *)(param_1 + 0x128) == DAT_0087b284) {
    fVar19 = (float10)FUN_005bec80(pfVar10);
    fVar1 = (float)((fVar19 / (float10)(float)puVar4[0x14d]) * (float10)0.25 + (float10)0.5);
    if (1.0 < fVar1) {
      local_6c._0_4_ = 1.0;
      fVar1 = (float)local_6c;
    }
    local_6c = (double)CONCAT44(local_6c._4_4_,fVar1);
    FUN_006514b0("env_hover_box_lp",&local_78,fVar1);
    fVar19 = (float10)FUN_005b7d30(_DAT_0092505c,0x40000000);
    fVar20 = (float10)0.5;
    local_6c = (double)CONCAT62(local_6c._2_6_,in_FPUControlWord);
    local_74 = (float)(&DAT_029899a0)
                      [(uint)(int)ROUND(fVar19 * fVar20 * (float10)65536.0) >> 1 & 0x7fff] * 0.0125
               + (float)puVar4[0x121];
    fVar19 = (float10)0;
    puVar4[0x12a] = (float)fVar19;
    puVar4[0x127] = (float)fVar19;
    if (fVar19 < (float10)(float)puVar4[0x155]) {
      iVar9 = FUN_006e6b90();
      local_74 = (float)(fVar20 - ((float10)1 - (float10)(float)(&DAT_029899a0)[iVar9 >> 1 & 0x7fff]
                                  ) * extraout_ST1 * (float10)0.019999999552965164);
      fVar19 = extraout_ST0;
    }
  }
LAB_00471c77:
  if (((*pfVar12 != local_78) || ((float)puVar4[0x124] != local_74)) ||
     ((float)puVar4[0x125] != local_70)) {
    if ((*(int *)(param_1 + 0x128) != DAT_0087b284) &&
       (((fVar19 != (float10)(float)puVar4[0x129] || (fVar19 != (float10)(float)puVar4[0x12a])) ||
        (fVar19 != (float10)(float)puVar4[299])))) {
      if (*(int *)(param_1 + 0x128) == DAT_0087b224) {
        FUN_00681f40("CarbonFreezeCraneLp",pfVar12);
      }
      else {
        FUN_00681f40("env_crane_mvt_lp",pfVar12);
      }
    }
    iVar9 = FUN_00470630();
    if (iVar9 == 0) {
      puVar4[0x129] = DAT_0093b0cc;
      puVar4[0x12a] = DAT_0093b0d0;
      uVar7 = DAT_0093b0d4;
      puVar4[299] = DAT_0093b0d4;
      *pfVar10 = (float)puVar4[0x129];
      puVar4[0x127] = puVar4[0x12a];
      puVar4[0x128] = uVar7;
      if (*(int *)(param_1 + 0x128) == DAT_0087b284) {
        puVar4[0x124] = local_74;
      }
    }
    else {
      local_50 = 1;
      *pfVar12 = local_78;
      puVar4[0x124] = local_74;
      puVar4[0x125] = local_70;
      if (((((float)puVar4[0x129] != 0.0) || ((float)puVar4[0x12a] != 0.0)) ||
          ((float)puVar4[299] != 0.0)) && (iVar9 = FUN_0056e460(0xffffffff), iVar9 == 0)) {
        fVar19 = (float10)FUN_005bec80(pfVar10);
        local_6c = (double)(fVar19 / (float10)(float)puVar4[0x14d]);
        iVar9 = FUN_0054fa60(0x3e19999a);
        FUN_0054ac00(0,(float)iVar9 * 1.5259022e-05 * 0.4 * (float)local_6c);
      }
    }
  }
  if ((*(byte *)((int)puVar4 + 0x559) & 8) != 0) {
    uVar8 = FUN_00550070(*(undefined2 *)((int)puVar4 + 0x55a),*(undefined2 *)(puVar4 + 0x157),
                         0x40400000);
    *(undefined2 *)((int)puVar4 + 0x55a) = uVar8;
  }
  puVar11 = puVar4;
  puVar15 = local_40;
  for (iVar9 = 0x10; iVar9 != 0; iVar9 = iVar9 + -1) {
    *puVar15 = *puVar11;
    puVar11 = puVar11 + 1;
    puVar15 = puVar15 + 1;
  }
  if ((*(byte *)((int)puVar4 + 0x559) & 8) != 0) {
    FUN_005b5060(local_40,*(undefined2 *)((int)puVar4 + 0x55a));
  }
  if ((float)puVar4[0x14c] != 1.0) {
    local_4c = puVar4[0x14c];
    local_48 = local_4c;
    local_44 = local_4c;
    FUN_005b4c30(local_40,&local_4c);
  }
  local_10 = *pfVar12;
  local_c = puVar4[0x124];
  local_8 = puVar4[0x125];
  FUN_005ea570(puVar4 + 0x13f,local_40);
  FUN_005ea660(puVar4 + 0x13f);
  switch(*(undefined1 *)(puVar4 + 0x156)) {
  case 0:
    if (local_7c == 0) {
      if ((*(byte *)((int)puVar4 + 0x559) & 4) != 0) {
        iVar9 = puVar4[0x146];
        if (((iVar9 != 0) && ((*(byte *)(iVar9 + 0x94) & 2) != 0)) &&
           (iVar9 = FUN_005a0f10(*(undefined4 *)(iVar9 + 0x34)), iVar9 != 0)) {
          *(byte *)((int)puVar4 + 0x559) = *(byte *)((int)puVar4 + 0x559) & 0xfb;
        }
        if ((*(byte *)((int)puVar4 + 0x559) & 4) != 0) break;
      }
      iVar9 = puVar4[0x146];
      if (((iVar9 == 0) || ((*(byte *)(iVar9 + 0x94) & 2) == 0)) ||
         ((*(byte *)(*(int *)(iVar9 + 0x34) + 10) & 1) != 0)) break;
    }
    else if ((*(uint *)(local_7c + 8) & (DAT_00802280 | DAT_0080227c)) == 0) break;
    psVar5 = (short *)puVar4[300];
    if ((psVar5 == (short *)0x0) || (*(int *)(*(int *)(psVar5 + 6) + 0x198) == 0)) {
      if (*(short *)((int)puVar4 + 0x55e) == DAT_007f1984) {
        if (((psVar5 == (short *)0x0) || ((*(byte *)((int)puVar4 + 0x559) & 1) == 0)) ||
           (pfVar10 = (float *)(puVar4 + 0x1c), *(int *)(psVar5 + 10) == 0)) {
          pfVar10 = pfVar12;
        }
        iVar9 = FUN_0055cee0(pfVar10,0,0x10,0x3f000000,0,0xffffffff,0xffffffff,0xffffffff,0,1,
                             FUN_00470920);
        puVar4[0x145] = iVar9;
        if (iVar9 != 0) {
          FUN_00470710();
          puVar4[0x14f] = 0;
          *(undefined1 *)(puVar4 + 0x156) = 2;
          if (local_80 == 0) {
            *(byte *)((int)puVar4 + 0x559) = *(byte *)((int)puVar4 + 0x559) | 4;
          }
        }
      }
    }
    else {
      *(undefined1 *)(puVar4 + 0x156) = 1;
      fVar19 = (float10)FUN_0062e040((int)*psVar5,0x66,0,0,1);
      *(byte *)((int)puVar4 + 0x559) = *(byte *)((int)puVar4 + 0x559) & 0xfd;
      puVar4[0x154] = (float)fVar19;
      if (local_80 == 0) {
        *(byte *)((int)puVar4 + 0x559) = *(byte *)((int)puVar4 + 0x559) | 4;
      }
      FUN_0054a910(0,0,2,0);
    }
    if (((puVar4[300] == 0) || ((*(byte *)((int)puVar4 + 0x559) & 1) == 0)) ||
       (pfVar10 = (float *)(puVar4 + 0x1c), *(int *)(puVar4[300] + 0x14) == 0)) {
      pfVar10 = pfVar12;
    }
    FUN_00681f40("env_grabber_pickup",pfVar10);
    break;
  case 1:
    pfVar10 = (float *)FUN_0062f150(puVar4 + 0x12d,0x66,1,0);
    if (pfVar10 == (float *)0x0) break;
    fVar1 = (float)puVar4[0x154] - _DAT_00925018;
    local_6c = (double)CONCAT44(local_6c._4_4_,fVar1);
    puVar4[0x154] = fVar1;
    if (fVar1 <= 0.0) {
      if ((puVar4[0x145] == 0) && (puVar4[0x14b] == 0)) {
        *(undefined1 *)(puVar4 + 0x156) = 0;
      }
      else {
        puVar4[0x14f] = 0;
        *(undefined1 *)(puVar4 + 0x156) = 2;
      }
      break;
    }
    if ((*(byte *)((int)puVar4 + 0x559) & 2) != 0) break;
    fVar19 = (float10)FUN_0062f1f0(puVar4[300],0x66,0);
    fVar1 = (float)fVar19;
    local_6c = (double)CONCAT44(local_6c._4_4_,fVar1);
    if ((fVar1 <= 0.0) || (*pfVar10 < fVar1)) break;
    *(byte *)((int)puVar4 + 0x559) = *(byte *)((int)puVar4 + 0x559) | 2;
    if ((puVar4[300] != 0) &&
       (((*(byte *)((int)puVar4 + 0x559) & 1) != 0 && (*(int *)(puVar4[300] + 0x14) != 0)))) {
      pfVar12 = (float *)(puVar4 + 0x1c);
    }
    local_5c = *pfVar12 + 0.5;
    local_6c = (double)CONCAT44(pfVar12[1] - 0.5,*pfVar12 - 0.5);
    local_58 = pfVar12[1] + 0.5;
    local_64 = pfVar12[2] - 0.5;
    local_54 = pfVar12[2] + 0.5;
    iVar9 = FUN_00570130(param_1,4,&local_6c,&local_5c);
    if (iVar9 == 0) {
      iVar9 = FUN_0055cee0(pfVar12,0,0,0x3f000000,0,0xffffffff,0xffffffff,0xffffffff,0,0,
                           FUN_00470920);
      puVar4[0x145] = iVar9;
      if (iVar9 != 0) {
        FUN_00470710();
        goto LAB_0047218e;
      }
      puVar11 = (undefined4 *)FUN_0056aab0(param_1,pfVar12,0x3e800000);
      puVar4[0x14b] = puVar11;
      if (puVar11 != (undefined4 *)0x0) {
        puVar15 = puVar11;
        puVar17 = puVar4 + 0x110;
        for (iVar9 = 0x10; iVar9 != 0; iVar9 = iVar9 + -1) {
          *puVar17 = *puVar15;
          puVar15 = puVar15 + 1;
          puVar17 = puVar17 + 1;
        }
        FUN_00567800(puVar11,0,0xffffffff,0xffffffff,0,1);
        puVar4[0x151] = *(float *)(puVar4[0x14b] + 0x34) - *(float *)(puVar4[0x14b] + 0x50);
        goto LAB_00472166;
      }
    }
    else {
      bVar3 = *(byte *)(iVar9 + 0x17);
      *(byte *)(iVar9 + 0x17) = bVar3 & 0xf9 | 8;
      if ((bVar3 & 0x40) == 0) {
        FUN_0046b750(iVar9 + 8,"m_pup1",1);
      }
      else {
        FUN_0046ca80(param_1,iVar9,2,local_80);
      }
LAB_00472166:
      FUN_0054a910(0,0x3dcccccd,0,0);
      FUN_00576960(0x28b);
LAB_0047218e:
      FUN_00681f40("env_grabber_down",pfVar12);
    }
    FUN_00681f40("env_grabber_up",pfVar12);
    break;
  case 2:
    if (((local_50 == 0) && (puVar4[0x145] != 0)) &&
       ((*(byte *)(puVar4[0x145] + 0x1fc) & 0x80) != 0)) {
      fVar1 = (float)puVar4[0x14f] + _DAT_00925018;
      puVar4[0x14f] = fVar1;
      if (fVar1 < 3.0) goto LAB_004722ac;
    }
    else {
      puVar4[0x14f] = 0;
LAB_004722ac:
      if (local_80 == 0) {
        if ((((*(byte *)((int)puVar4 + 0x559) & 4) != 0) && (iVar9 = puVar4[0x146], iVar9 != 0)) &&
           (((*(byte *)(iVar9 + 0x94) & 2) != 0 &&
            (iVar9 = FUN_005a0f10(*(undefined4 *)(iVar9 + 0x34)), iVar9 != 0)))) {
          *(byte *)((int)puVar4 + 0x559) = *(byte *)((int)puVar4 + 0x559) & 0xfb;
        }
        if ((puVar4[0x145] == 0) && (puVar4[0x14b] == 0)) {
          *(undefined1 *)(puVar4 + 0x156) = 0;
          break;
        }
        if (((*(byte *)((int)puVar4 + 0x559) & 4) != 0) ||
           (((iVar9 = puVar4[0x146], iVar9 == 0 || ((*(byte *)(iVar9 + 0x94) & 2) == 0)) ||
            ((*(byte *)(*(int *)(iVar9 + 0x34) + 10) & 1) != 0)))) break;
      }
      else {
        if ((puVar4[0x145] == 0) && (puVar4[0x14b] == 0)) {
          *(undefined1 *)(puVar4 + 0x156) = 0;
          break;
        }
        if ((*(uint *)(local_7c + 8) & (DAT_00802280 | DAT_0080227c)) == 0) break;
      }
    }
    psVar5 = (short *)puVar4[300];
    if ((psVar5 == (short *)0x0) || (*(int *)(*(int *)(psVar5 + 6) + 0x19c) == 0)) {
      FUN_004713e0(puVar4,&local_5c);
      if (local_80 == 0) {
        *(byte *)((int)puVar4 + 0x559) = *(byte *)((int)puVar4 + 0x559) | 4;
      }
    }
    else {
      *(undefined1 *)(puVar4 + 0x156) = 3;
      fVar19 = (float10)FUN_0062e040((int)*psVar5,0x67,0,0,1);
      *(byte *)((int)puVar4 + 0x559) = *(byte *)((int)puVar4 + 0x559) & 0xfd;
      puVar4[0x154] = (float)fVar19;
      if (local_80 == 0) {
        *(byte *)((int)puVar4 + 0x559) = *(byte *)((int)puVar4 + 0x559) | 4;
      }
      FUN_0054a910(0,0,2,0);
    }
    if (((puVar4[300] == 0) || ((*(byte *)((int)puVar4 + 0x559) & 1) == 0)) ||
       (pfVar10 = (float *)(puVar4 + 0x1c), *(int *)(puVar4[300] + 0x14) == 0)) {
      pfVar10 = pfVar12;
    }
    FUN_00681f40("env_grabber_down",pfVar10);
    break;
  case 3:
    pfVar12 = (float *)FUN_0062f150(puVar4 + 0x12d,0x67,1,0);
    if (pfVar12 != (float *)0x0) {
      fVar1 = (float)puVar4[0x154] - _DAT_00925018;
      local_6c = (double)CONCAT44(local_6c._4_4_,fVar1);
      puVar4[0x154] = fVar1;
      if (0.0 < fVar1) {
        if ((*(byte *)((int)puVar4 + 0x559) & 2) != 0) break;
        fVar19 = (float10)FUN_0062f1f0(puVar4[300],0x67,0);
        fVar1 = (float)fVar19;
        local_6c = (double)CONCAT44(local_6c._4_4_,fVar1);
        if (fVar1 <= 0.0) break;
        bVar18 = fVar1 <= *pfVar12;
      }
      else {
        bVar18 = (*(byte *)((int)puVar4 + 0x559) & 2) == 0;
        *(undefined1 *)(puVar4 + 0x156) = 0;
      }
      if (bVar18) {
        FUN_004713e0(puVar4,&local_5c);
      }
    }
  }
  if (puVar4[300] != 0) {
    cVar2 = *(char *)(puVar4 + 0x156);
    *(undefined2 *)(puVar4 + 0x13b) = *(undefined2 *)((int)puVar4 + 0x4ea);
    if (cVar2 == '\x01') {
      *(undefined2 *)((int)puVar4 + 0x4ee) = 0x66;
    }
    else if (cVar2 == '\x02') {
      *(undefined2 *)((int)puVar4 + 0x4ee) = 0xf;
    }
    else if (cVar2 == '\x03') {
      *(undefined2 *)((int)puVar4 + 0x4ee) = 0x67;
    }
    else {
      *(undefined2 *)((int)puVar4 + 0x4ee) = 1;
    }
    FUN_0062e9b0(puVar4[300],puVar4 + 0x12d,_DAT_00925018 * 30.0,puVar4[0x14d],_DAT_00925018,0);
  }
  iVar9 = puVar4[0x145];
  if (iVar9 != 0) {
    *(float *)(iVar9 + 0x77c) = *(float *)(iVar9 + 0x77c) + _DAT_00925018;
    FUN_00470e60();
    *(undefined4 *)(puVar4[0x145] + 0x70) = 0;
    *(undefined4 *)(puVar4[0x145] + 0x68) = 0;
    *(undefined4 *)(puVar4[0x145] + 0x6c) = 0xbdcccccd;
    *(undefined1 *)(puVar4[0x145] + 0x281) = 0;
  }
  if (*(short *)((int)puVar4 + 0x55e) == DAT_007f1980) {
    uVar14 = 0;
    bVar18 = false;
    if (0 < DAT_0093d500) {
      puVar16 = (uint *)(DAT_0093d504 + 0x1fc);
      iVar9 = DAT_0093d500;
      do {
        if (((*puVar16 & 1) != 0) && ((*puVar16 & 0x1000) != 0)) {
          if ((*(uint *)(*(int *)(puVar16[-0x6a] + 0x24) + 0x90) & 0x8000) == 0) {
            uVar13 = __allshl();
            uVar14 = uVar14 | uVar13;
          }
          else {
            bVar18 = true;
          }
        }
        puVar16 = puVar16 + 0x436;
        iVar9 = iVar9 + -1;
      } while (iVar9 != 0);
      if ((bVar18) && (iVar9 = FUN_005185e0(local_60,0x3e800000), iVar9 != 0)) {
        *(uint *)(iVar9 + 0x50) = uVar14;
        *(int *)(iVar9 + 0x54) = (int)uVar14 >> 0x1f;
        *(float *)(iVar9 + 0x10) = *(float *)(iVar9 + 4) - 4.0;
      }
    }
  }
  return;
}

