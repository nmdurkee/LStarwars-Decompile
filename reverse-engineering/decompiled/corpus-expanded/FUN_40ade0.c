/* Ghidra pseudocode, not original source.
 * ev_428398453750e294ede80d9f87d5cfcdf804466d2d70f27e1ba752c78f326fd9
 * Entry: 0x40ade0; label: FUN_0040ade0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0040ade0(undefined4 *param_1)

{
  float fVar1;
  char cVar2;
  bool bVar3;
  undefined2 uVar4;
  ushort uVar5;
  short sVar6;
  int iVar7;
  int *piVar8;
  undefined4 uVar9;
  undefined4 *puVar10;
  float fVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  int iVar15;
  undefined *puVar16;
  float *pfVar17;
  undefined4 *puVar18;
  float fVar19;
  undefined4 *puVar20;
  undefined2 in_FPUControlWord;
  float10 fVar21;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 extraout_ST0_01;
  float local_188 [2];
  undefined4 local_180;
  undefined2 uStack_17c;
  float local_178;
  float local_174;
  float local_170;
  float local_16c;
  uint local_168;
  float local_164;
  float local_160;
  float local_15c;
  float local_158;
  float local_154;
  float local_150;
  float local_14c;
  float local_148;
  float local_144;
  float local_140;
  float local_13c;
  uint local_138;
  float local_134;
  float local_130;
  int local_12c;
  float local_128;
  float local_124;
  float local_120;
  float local_11c;
  float local_118;
  uint local_114;
  uint local_110;
  float local_10c;
  float local_108;
  float local_104;
  undefined4 local_100;
  int local_fc;
  float local_f8 [3];
  int local_ec;
  undefined8 local_e8;
  uint local_e0 [4];
  float local_d0;
  float local_cc;
  float local_c8;
  undefined4 local_c4;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  float local_84;
  float local_80;
  float local_7c;
  float local_78 [2];
  float local_70;
  undefined1 local_6c [4];
  undefined4 local_68 [6];
  undefined4 local_50 [6];
  undefined4 local_38;
  char local_e;
  
  local_100 = 0;
  local_128 = 0.0;
  local_12c = 0;
  local_11c = 0.5;
  local_124 = 0.0;
  local_134 = 0.0;
  local_144 = -1.0;
  local_140 = 0.0;
  _DAT_0080b9c8 = *(undefined4 *)(*(int *)(PTR_DAT_00802c54 + 0x128) + 0x84);
  DAT_00855de0 = 0;
  iVar7 = FUN_00574e20();
  if (_DAT_00950678 < 1.0) {
    puVar10 = param_1 + 0x2e;
    puVar18 = &DAT_00806680;
    puVar20 = puVar10;
    for (iVar7 = 0x10; iVar7 != 0; iVar7 = iVar7 + -1) {
      *puVar20 = *puVar18;
      puVar18 = puVar18 + 1;
      puVar20 = puVar20 + 1;
    }
    puVar18 = puVar10;
    puVar20 = param_1 + 0xe;
    for (iVar7 = 0x10; iVar7 != 0; iVar7 = iVar7 + -1) {
      *puVar20 = *puVar18;
      puVar18 = puVar18 + 1;
      puVar20 = puVar20 + 1;
    }
    puVar18 = DAT_00925164;
    for (iVar7 = 0x10; iVar7 != 0; iVar7 = iVar7 + -1) {
      *puVar18 = *puVar10;
      puVar10 = puVar10 + 1;
      puVar18 = puVar18 + 1;
    }
    FUN_00603cc0(DAT_00925164);
    FUN_005495a0(param_1);
    return;
  }
  if (DAT_00921359 == '\0') {
    if (DAT_00951be0 != 0) goto LAB_0040e60c;
  }
  else if ((DAT_00951be0 != 0) || (DAT_00951c30 != 0)) {
    puVar10 = param_1 + 0x2e;
    puVar18 = &DAT_00921298;
    puVar20 = puVar10;
    for (iVar7 = 0x10; iVar7 != 0; iVar7 = iVar7 + -1) {
      *puVar20 = *puVar18;
      puVar18 = puVar18 + 1;
      puVar20 = puVar20 + 1;
    }
    puVar18 = puVar10;
    puVar20 = param_1 + 0xe;
    for (iVar7 = 0x10; iVar7 != 0; iVar7 = iVar7 + -1) {
      *puVar20 = *puVar18;
      puVar18 = puVar18 + 1;
      puVar20 = puVar20 + 1;
    }
    DAT_00921358 = 0;
    puVar18 = puVar10;
    puVar20 = DAT_00925164;
    for (iVar7 = 0x10; iVar7 != 0; iVar7 = iVar7 + -1) {
      *puVar20 = *puVar18;
      puVar18 = puVar18 + 1;
      puVar20 = puVar20 + 1;
    }
    if (0.0 < DAT_00921360) {
      fVar21 = (float10)FUN_005d6cc0(DAT_00921360);
      local_13c = (float)fVar21;
      pfVar17 = (float *)(DAT_00925164 + 0x10);
      *pfVar17 = local_13c;
      fVar21 = (float10)FUN_0040a520();
      *pfVar17 = (float)((((float10)1 / fVar21) / (float10)0.75) * (float10)local_13c);
    }
    FUN_00603cc0(DAT_00925164);
    puVar18 = &DAT_00855da0;
    for (iVar7 = 0x10; iVar7 != 0; iVar7 = iVar7 + -1) {
      *puVar18 = *puVar10;
      puVar10 = puVar10 + 1;
      puVar18 = puVar18 + 1;
    }
    DAT_00951c34 = 1;
    return;
  }
  if ((DAT_0087658c != 0) || (DAT_00951b80 != 0)) {
LAB_0040e60c:
    FUN_005495a0(param_1);
    return;
  }
  local_fc = (int)*(char *)(param_1 + 0x8b);
  *(char *)((int)param_1 + 0x22d) = *(char *)(param_1 + 0x8b);
  *(undefined1 *)(param_1 + 0x8b) = 0xff;
  puVar10 = param_1;
  puVar18 = &local_38;
  for (iVar15 = 0xe; iVar15 != 0; iVar15 = iVar15 + -1) {
    *puVar18 = *puVar10;
    puVar10 = puVar10 + 1;
    puVar18 = puVar18 + 1;
  }
  if (DAT_007f1138 != (int *)0x0) {
    *(undefined1 *)(param_1 + 0x8b) = 5;
  }
  fVar19 = _DAT_0095191c;
  if ((DAT_0087b738 != 0) &&
     (((_DAT_0087b73c = _DAT_00925018 + _DAT_0087b73c,
       _DAT_007f10f0 < _DAT_0087b73c != (_DAT_007f10f0 == _DAT_0087b73c) ||
       (*(int *)(*(int *)(PTR_DAT_00802c54 + 0x2ac4) + 0x18) == 0)) ||
      (*(int *)(*(int *)(PTR_DAT_00802c54 + 0x2ac4) + 0x1c) == 0)))) {
    DAT_0087b738 = 0;
  }
  if (iVar7 == 0xe) {
    if (DAT_00879b3c == 0) {
LAB_0040b06f:
      if (((DAT_00880474 == 0) || (DAT_0087ffec == (float *)0x0)) || (DAT_0087bf94 == 0)) {
        if ((iVar7 == 0xc) && (*(int *)(*(int *)(PTR_DAT_00802c54 + 0x2ac4) + 0x3c) != 0)) {
          *(undefined1 *)(param_1 + 0x8b) = 7;
        }
        else if ((DAT_009514e4 == 0) || ((_DAT_009514e8 < _DAT_0095191c && (DAT_00951918 == 0)))) {
          if ((DAT_00951420 != 0) && ((DAT_00951424 != 0 && (0.0 < _DAT_0095139c)))) {
            _DAT_0095139c = _DAT_0095139c - _DAT_00925018;
            *(undefined1 *)(param_1 + 0x8b) = 4;
          }
        }
        else {
          local_130 = _DAT_0095191c;
          if (_DAT_0095191c < _DAT_009514e8) {
            _DAT_0095191c = _DAT_0095191c + _DAT_00925018;
          }
          if (_DAT_009514e8 < _DAT_0095191c == (_DAT_009514e8 == _DAT_0095191c)) {
            if ((((_DAT_00951914 < _DAT_0095191c != (_DAT_00951914 == _DAT_0095191c)) &&
                 (_DAT_0095191c < _DAT_009514e8)) &&
                (*(undefined1 *)(param_1 + 0x8b) = 2, 0.0 < _DAT_00951914)) &&
               ((fVar19 < _DAT_00951914 && (_DAT_009514d8 <= 0.0)))) {
              param_1[0x70] = 0;
              *(undefined1 *)((int)param_1 + 0x22d) = 0xff;
              param_1[0x6f] = 0;
              _DAT_00950760 = 0x3f800000;
            }
          }
          else {
            _DAT_0095191c = _DAT_009514e8;
            if (DAT_00951918 == 0) {
              DAT_009514e4 = 0;
              if (_DAT_009514ec < 0.0 == (_DAT_009514ec == 0.0)) {
                local_11c = _DAT_009514ec;
              }
              else {
                FUN_0054a2f0(param_1);
                local_fc = (int)*(char *)(param_1 + 0x8b);
                *(char *)((int)param_1 + 0x22d) = *(char *)(param_1 + 0x8b);
                puVar10 = param_1;
                puVar18 = &local_38;
                for (iVar7 = 0xe; iVar7 != 0; iVar7 = iVar7 + -1) {
                  *puVar18 = *puVar10;
                  puVar10 = puVar10 + 1;
                  puVar18 = puVar18 + 1;
                }
                _DAT_00950760 = 0;
              }
            }
            else {
              *(undefined1 *)(param_1 + 0x8b) = 2;
              for (local_168 = 0; (DAT_00951918 != 0 && ((int)local_168 < 2));
                  local_168 = local_168 + 1) {
                iVar7 = (&DAT_0093d7f0)[local_168];
                if (((iVar7 != 0) && ((*(byte *)(iVar7 + 0x1fc) & 0x80) != 0)) &&
                   (((*(char *)(iVar7 + 0x288) == '\0' ||
                     (0.0 < *(float *)(*(int *)(iVar7 + 0xca4) + 0x28))) ||
                    ((*(uint *)(*(int *)(iVar7 + 0xca4) + 4) &
                     (DAT_0080228c | DAT_00802288 | DAT_00802284 | DAT_00802280 | DAT_0080227c |
                      DAT_00802278 | DAT_00802274)) != 0)))) {
                  DAT_00951918 = 0;
                }
              }
            }
          }
        }
      }
      else {
        *(undefined1 *)(param_1 + 0x8b) = 8;
      }
    }
    else {
      *(undefined1 *)(param_1 + 0x8b) = 9;
    }
  }
  else {
    if ((iVar7 != 8) || (*(int *)(*(int *)(PTR_DAT_00802c54 + 0x2ac4) + 0x60) == 0))
    goto LAB_0040b06f;
    *(undefined1 *)(param_1 + 0x8b) = 6;
  }
  if (*(char *)(param_1 + 0x8b) == -1) {
    *(undefined1 *)(param_1 + 0x8b) = 0;
    if ((DAT_00951420 == 0) || (DAT_00925068 != 0)) {
      if ((*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_00951b88) &&
         (*(int *)(*(int *)(PTR_DAT_00802c54 + 0x2ac4) + 8) != 0)) {
        *(undefined1 *)(param_1 + 0x8b) = 3;
      }
      else if ((0 < DAT_0093d818) && (*(int *)(PTR_DAT_00802c54 + 0x2988) != 0)) {
        if ((DAT_007fffec == 0) ||
           ((*(int *)(PTR_DAT_00802c54 + 0x128) != DAT_0087b0dc ||
            (*(char *)(**(int **)(PTR_DAT_00802c54 + 0x2988) + 0x32) == '\0')))) {
          *(undefined1 *)(param_1 + 0x8b) = 1;
        }
        else {
          *(undefined1 *)(param_1 + 0x8b) = 0xb;
        }
      }
    }
    else {
      *(undefined1 *)(param_1 + 0x8b) = 4;
    }
  }
  cVar2 = *(char *)(param_1 + 0x8b);
  fVar19 = 1.5;
  if (cVar2 != local_fc) {
    if (local_fc == 4) {
      local_13c = _DAT_0095139c;
      if (DAT_00951424 != 0) {
        local_13c = 0.0;
      }
      FUN_0054a3e0(param_1,_DAT_009513ac,local_13c,1);
      DAT_00951420 = 0;
    }
    else if (local_fc != -1) {
      local_158 = _DAT_009514d8;
      if ((((((cVar2 != '\x02') && (local_158 = fVar19, cVar2 != '\t')) && (local_fc != 9)) &&
           (((cVar2 != '\x06' && (local_fc != 6)) &&
            ((local_158 = _DAT_007f10ec, cVar2 != '\b' && (local_fc != 8)))))) &&
          ((cVar2 == '\a' || (local_158 = local_11c, local_fc == 7)))) &&
         (local_158 = fVar19, DAT_0093b338 != 0)) {
        local_158 = 3.0;
      }
      if ((*(char *)((int)param_1 + 0x22d) != -1) && (local_158 != 0.0)) {
        FUN_0054a3e0(param_1,local_158,0,1);
      }
    }
  }
  if ((*(char *)(param_1 + 0x8b) == '\x02') || (*(char *)(param_1 + 0x8b) == '\x04')) {
    if ((float)param_1[0x70] <= (float)param_1[0x6f]) {
      DAT_00855de0 = (DAT_00951918 != 0) + 2;
    }
    else {
      DAT_00855de0 = 1;
    }
  }
  else if (((float)param_1[0x6f] < (float)param_1[0x70]) &&
          ((*(char *)((int)param_1 + 0x22e) == '\x02' || (*(char *)((int)param_1 + 0x22e) == '\x04')
           ))) {
    DAT_00855de0 = 4;
  }
  local_174 = *DAT_0093d5a0;
  local_170 = DAT_0093d5a0[1];
  local_16c = DAT_0093d5a0[2];
  fVar19 = -NAN;
  local_120 = (float)*(byte *)(*(int *)(PTR_DAT_00802c54 + 0x128) + 0xcb);
  local_114 = 0xffffffff;
  local_13c = -NAN;
  local_110 = 0;
  local_14c = DAT_0093b0d4;
  local_118 = (float)*(byte *)(*(int *)(PTR_DAT_00802c54 + 0x128) + 0xcc);
  local_150 = DAT_0093b0d0;
  local_ec = 0;
  local_11c = 0.5;
  local_130 = 0.0;
  local_154 = DAT_0093b0cc;
  piVar8 = DAT_007f1138;
  if (*(char *)(param_1 + 0x8b) != '\x05') {
    piVar8 = &DAT_009253b0;
  }
  iVar7 = *piVar8;
  local_180 = (float)*(byte *)(iVar7 + 0x93) - 127.5;
  if (ABS(local_180) < 34.0) {
    local_180 = 0.0;
  }
  local_180 = local_180 / 127.5;
  local_158 = (float)*(byte *)(iVar7 + 0x92) - 127.5;
  if (ABS(local_158) < 34.0) {
    local_158 = 0.0;
  }
  local_158 = local_158 / 127.5;
  local_148 = (float)*(byte *)(iVar7 + 0x91) - 127.5;
  if (ABS(local_148) < 34.0) {
    local_148 = 0.0;
  }
  local_148 = local_148 / 127.5;
  local_178 = (float)*(byte *)(iVar7 + 0x90) - 127.5;
  local_188[0] = ABS(local_178);
  if (local_188[0] < 34.0) {
    local_178 = 0.0;
  }
  local_178 = local_178 / 127.5;
  switch(*(char *)(param_1 + 0x8b)) {
  case '\x01':
    local_158 = 0.0;
    local_178 = 0.0;
    local_168 = 0;
    local_148 = 0.0;
    uVar12 = DAT_007f3b14;
    do {
      fVar19 = local_148;
      uVar13 = (&DAT_0093d7f0)[local_168];
      if ((((uVar13 != 0) && (((*(byte *)(uVar13 + 0x1fc) & 0x80) != 0 || (DAT_00925398 != 0)))) &&
          ((DAT_00951b58 == 0 || ((*(uint *)(uVar13 + 0x1f8) & 0x40000) == 0)))) &&
         ((uVar12 == 0xffffffff || (local_168 == uVar12)))) {
        uVar12 = *(uint *)(*(int *)(uVar13 + 0x54) + 4) & 0x2000;
        local_e0[local_168 - 2] = uVar12;
        bVar3 = true;
        if ((DAT_0087b234 != 0) &&
           (((*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_0087b234 &&
             (*(short *)(uVar13 + 0x1064) == DAT_007f1948)) && (DAT_009253a4 != 0)))) {
          bVar3 = false;
        }
        if (((uVar12 != 0) && (bVar3)) &&
           (local_178 = (float)((int)local_178 + 1), *(short *)(uVar13 + 0x1064) == DAT_007f1940)) {
          if (local_134 == 0.0) {
            local_188[0] = (float)(uint)*(ushort *)(uVar13 + 0x27a);
            local_134 = *(float *)(uVar13 + 0x22c) * 0.6;
            local_144 = (float)(int)local_188[0];
            local_140 = *(float *)(uVar13 + 0x22c);
          }
          else {
            local_134 = (local_134 + *(float *)(uVar13 + 0x22c) * 0.6) * 0.5;
            local_144 = ((float)*(ushort *)(uVar13 + 0x27a) + local_144) * 0.5;
            local_188[0] = *(float *)(uVar13 + 0x22c) + local_140;
            local_140 = local_188[0] * 0.5;
          }
        }
        if ((DAT_0087b014 == 0) || (*(int *)(PTR_DAT_00802c54 + 300) != DAT_0087b014)) {
          FUN_0040a570(param_1 + 0x47);
        }
        else {
          puVar10 = (undefined4 *)((int)local_50 + (int)local_148);
          *puVar10 = *(undefined4 *)(uVar13 + 0x80);
          *(undefined4 *)((int)local_50 + (int)local_148 + 4) = *(undefined4 *)(uVar13 + 0x84);
          local_160 = 0.0;
          local_164 = 0.0;
          *(undefined4 *)((int)local_50 + (int)local_148 + 8) = *(undefined4 *)(uVar13 + 0x88);
          local_15c = 2.0;
          FUN_004abaa0(local_168);
          local_188[0] = (float)(uint)*(ushort *)((&DAT_0093d7f0)[local_168] + 0x58);
          uVar9 = FUN_006e6b90();
          FUN_005b3620(&local_164,&local_164,uVar9);
          FUN_005b37d0(puVar10,puVar10,&local_164);
        }
        if ((*(char *)(uVar13 + 0x7b5) == '+') && (*(char *)(uVar13 + 0x28b) == '\0')) {
          puVar10 = (undefined4 *)(uVar13 + 0x1c0);
        }
        else {
          if ((*(char *)(uVar13 + 0x7b5) == 'Q') && (*(int *)(uVar13 + 0x798) != 0)) {
            puVar10 = (undefined4 *)FUN_004cda40(*(int *)(uVar13 + 0x798));
            if (puVar10 != (undefined4 *)0x0) goto LAB_0040b947;
          }
          puVar10 = (undefined4 *)(uVar13 + 0x5c);
        }
LAB_0040b947:
        fVar1 = local_158;
        *(undefined4 *)((int)local_68 + (int)fVar19) = *puVar10;
        *(undefined4 *)((int)local_68 + (int)fVar19 + 4) = puVar10[1];
        *(undefined4 *)((int)local_68 + (int)fVar19 + 8) = puVar10[2];
        if ((*(uint *)(*(int *)(uVar13 + 0x54) + 4) & 0x2000) == 0) {
          fVar11 = 0.0;
          local_e0[(int)local_158 + 2] = 0;
        }
        else {
          if ((DAT_0087b014 == 0) || (*(int *)(PTR_DAT_00802c54 + 300) != DAT_0087b014)) {
            uVar12 = FUN_00550040(0,*(undefined2 *)(uVar13 + 0xe18));
          }
          else {
            FUN_004abaa0(local_168);
            uVar12 = FUN_006e6b90();
          }
          uVar4 = *(undefined2 *)(uVar13 + 0xe1c);
          local_e0[(int)fVar1 + 2] = uVar12;
          fVar11 = (float)FUN_00550040(0,uVar4);
        }
        uVar4 = *(undefined2 *)(uVar13 + 0x27a);
        local_188[(int)fVar1] = fVar11;
        *(undefined2 *)((int)&local_180 + (int)fVar1 * 2) = uVar4;
        local_e0[(int)fVar1] = uVar13;
        local_158 = (float)((int)fVar1 + 1);
        local_148 = (float)((int)fVar19 + 0xc);
        uVar12 = DAT_007f3b14;
      }
      fVar19 = local_158;
      local_168 = local_168 + 1;
    } while ((int)local_168 < 2);
    if (0 < (int)local_158) {
      DAT_00801e38 = DAT_007f10f4;
      local_168 = FUN_00541e60(*(undefined4 *)(PTR_DAT_00802c54 + 0x2988),param_1 + 0x47,
                               *(char *)(param_1 + 0x8b) != *(char *)((int)param_1 + 0x22d),local_50
                               ,local_68,local_158,param_1,&local_174,&local_154,&local_11c,
                               &local_120,&local_118,&local_124,local_6c);
      local_11c = local_11c * 1.5;
      local_84 = local_174;
      local_80 = local_170;
      local_7c = local_16c;
      if (0.0 < *(float *)(*(int *)(PTR_DAT_00802c54 + 0x128) + 0xb8)) {
        local_188[0] = local_154 - local_174;
        uVar4 = FUN_005be2d0(local_188[0],local_14c - local_16c);
        FUN_005b3800(local_f8,&local_174,&local_154);
        local_f8[1] = 0.0;
        FUN_005b3b30(local_f8,local_f8);
        fVar19 = local_180;
        if ((int)local_178 < 1) {
          local_148 = 0.0;
        }
        else {
          if (local_158 == 2.8026e-45) {
            if ((int)local_e8 == 0) {
LAB_0040bbda:
              local_138 = (uint)local_180._2_2_;
            }
            else if (local_e8._4_4_ == 0) {
              local_138 = (uint)local_180 & 0xffff;
            }
            else {
              iVar7 = FUN_00550040(local_180,CONCAT22(uStack_17c,local_180._2_2_));
              local_138 = iVar7 / 2 + (int)fVar19 & 0xffff;
            }
          }
          else {
            local_138 = (uint)local_180 & 0xffff;
            if ((int)local_e8 == 0) goto LAB_0040bbda;
          }
          local_168 = FUN_00550040(uVar4,local_138);
          local_148 = 0.0;
          if (((*(char *)((int)param_1 + 1) == -1) ||
              ((*(ushort *)
                 (*(char *)((int)param_1 + 1) * 0x13c + 0x68 + **(int **)(PTR_DAT_00802c54 + 0x2988)
                 ) & 0x1000) == 0)) &&
             (iVar7 = (local_168 ^ (int)local_168 >> 0x1f) - ((int)local_168 >> 0x1f),
             0x4000 < iVar7)) {
            local_188[0] = (float)(iVar7 + -0x4000);
            local_148 = (float)(int)local_188[0] * 6.1035156e-05;
          }
        }
        fVar21 = (float10)FUN_0054fad0(param_1[0x7a],local_148,_DAT_00925018);
        local_188[0] = (float)fVar21;
        param_1[0x7a] = local_188[0];
        fVar21 = (float10)FUN_0054fb40(param_1[0x7b],local_188[0],0x40400000);
        param_1[0x7b] = (float)fVar21;
        local_188[0] = (float)fVar21 * *(float *)(*(int *)(PTR_DAT_00802c54 + 0x128) + 0xb8);
        FUN_005b3830(&local_164,local_f8,local_188[0]);
        FUN_005b37d0(&local_174,&local_174,&local_164);
        FUN_005b37d0(&local_154,&local_154,&local_164);
        local_180 = 0.0;
        if ((0 < (int)local_178) &&
           ((*(char *)((int)param_1 + 1) == -1 ||
            (local_180 = 0.0,
            (*(ushort *)
              (*(char *)((int)param_1 + 1) * 0x13c + 0x68 + **(int **)(PTR_DAT_00802c54 + 0x2988)) &
            0x1000) == 0)))) {
          uVar12 = 0x4000 - ((local_168 ^ (int)local_168 >> 0x1f) - ((int)local_168 >> 0x1f));
          uVar13 = (int)uVar12 >> 0x1f;
          local_188[0] = (float)((uVar12 ^ uVar13) - uVar13);
          local_180 = 1.0 - (float)(int)local_188[0] * 6.1035156e-05;
          if ((int)local_168 < 0) {
            local_180 = -local_180;
          }
        }
        fVar21 = (float10)FUN_0054fad0(param_1[0x7c],local_180,_DAT_00925018);
        local_188[0] = (float)fVar21;
        param_1[0x7c] = local_188[0];
        fVar21 = (float10)FUN_0054fb40(param_1[0x7d],local_188[0],0x40400000);
        param_1[0x7d] = (float)fVar21;
        FUN_005b3620(&local_164,local_f8,0x4000);
        local_188[0] = *(float *)(*(int *)(PTR_DAT_00802c54 + 0x128) + 0xbc) * 0.5 *
                       (float)param_1[0x7d];
        FUN_005b3830(&local_164,&local_164,local_188[0]);
        FUN_005b3800(&local_174,&local_174,&local_164);
        FUN_005b3800(&local_154,&local_154,&local_164);
        fVar19 = local_158;
      }
      iVar7 = *(int *)(PTR_DAT_00802c54 + 300);
      if (iVar7 == 0) {
LAB_0040c357:
        if ((*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_0087b0e0) &&
           (*(char *)((int)param_1 + 1) != -1)) {
          local_174 = local_174 + local_154 * 0.0625;
          local_16c = local_14c * 0.0625 + local_16c;
        }
      }
      else if (iVar7 == DAT_0087b014) {
        if (_DAT_0087b888 < 0.333 == (_DAT_0087b888 == 0.333)) {
          if (1.0 <= _DAT_0087b888) {
            local_178 = 2.0;
          }
          else {
            local_178 = ((_DAT_0087b888 - 0.333) / 0.667) * -1.0 + 3.0;
          }
        }
        else {
          local_178 = 3.0;
        }
        fVar21 = (float10)FUN_0054fad0(_DAT_00881cc0,local_178,_DAT_00925018);
        _DAT_00881cc0 = (float)fVar21;
        uVar12 = 0;
        local_15c = 0.0;
        local_160 = 0.0;
        local_168 = 0;
        local_164 = 0.0;
        if (0 < (int)fVar19) {
          do {
            uVar13 = local_e0[uVar12];
            uVar12 = uVar12 + 1;
            local_164 = (*(float *)(uVar13 + 0x80) -
                        (float)(&DAT_029899a0)[*(ushort *)(uVar13 + 0x58) >> 1] * _DAT_00881cc0) +
                        local_164;
            local_160 = *(float *)(uVar13 + 0x84) + 1.0 + local_160;
            local_15c = (*(float *)(uVar13 + 0x88) -
                        (float)(&DAT_029899a0)
                               [(int)(*(ushort *)(uVar13 + 0x58) + 0x4000) >> 1 & 0x7fff] *
                        _DAT_00881cc0) + local_15c;
            local_168 = uVar12;
          } while ((int)uVar12 < (int)fVar19);
        }
        if (1 < (int)fVar19) {
          local_188[0] = 1.0 / (float)(int)local_158;
          FUN_005b3830(&local_164,&local_164,local_188[0]);
        }
        local_120 = 10.0;
        local_118 = 10.0;
        local_174 = local_164;
        local_170 = local_160;
        local_16c = local_15c;
        fVar21 = (float10)FUN_005506f0(0,&local_174,0x40a00000,0xffffffff);
        local_178 = (float)fVar21;
        if (local_178 != 2e+06) {
          if ((_DAT_02920d84 != 2e+06) && (local_178 < _DAT_02920d84)) {
            local_178 = _DAT_02920d84;
          }
          fVar1 = local_178 + 1.0;
          if (local_170 < fVar1) {
            local_150 = fVar1 - 0.5;
            local_170 = fVar1;
            goto LAB_0040c38f;
          }
        }
        local_150 = local_170 - 0.5;
      }
      else {
        if ((iVar7 == 0) || (iVar7 != DAT_0087af5c)) goto LAB_0040c357;
        fVar21 = (float10)FUN_004dbb60(PTR_DAT_00802c54);
        local_148 = (float)fVar21;
        local_164 = 0.0;
        local_178 = _DAT_007f1100;
        if (0.0 < local_148) {
          local_178 = (local_148 / 3.0) * (_DAT_007f10fc - _DAT_007f1100) + _DAT_007f1100;
        }
        if (fVar19 == 2.8026e-45) {
          local_178 = local_178 * 1.5;
        }
        uVar12 = 0;
        _DAT_00881cc0 = local_178;
        local_168 = 0;
        local_160 = local_164;
        local_15c = local_164;
        if (0 < (int)fVar19) {
          do {
            uVar13 = local_e0[uVar12];
            uVar12 = uVar12 + 1;
            local_164 = *(float *)(uVar13 + 0x5c) + local_164;
            local_160 = *(float *)(uVar13 + 0x17c) + _DAT_007f1104 + local_160;
            local_15c = *(float *)(uVar13 + 100) + local_15c;
            local_168 = uVar12;
          } while ((int)uVar12 < (int)fVar19);
        }
        if (1 < (int)fVar19) {
          local_188[0] = 1.0 / (float)(int)local_158;
          FUN_005b3830(&local_164,&local_164,local_188[0]);
        }
        local_154 = local_164;
        local_150 = local_160;
        local_14c = local_15c;
        local_138 = (uint)*(ushort *)(local_e0[0] + 0x5a);
        fVar1 = local_180;
        if (fVar19 == 2.8026e-45) {
          iVar7 = FUN_00550040(*(undefined2 *)(local_e0[0] + 0x5a),
                               *(undefined2 *)(local_e0[1] + 0x5a));
          local_138 = local_138 + iVar7 / 2;
          fVar1 = local_180;
        }
        local_180._2_2_ = (ushort)((uint)fVar1 >> 0x10);
        local_174 = local_154 - _DAT_00881cc0 * (float)(&DAT_029899a0)[local_138 >> 1 & 0x7fff];
        local_170 = local_150 + _DAT_007f1104;
        local_16c = local_14c -
                    (float)(&DAT_029899a0)[(int)((local_138 & 0xffff) + 0x4000) >> 1 & 0x7fff] *
                    _DAT_00881cc0;
        if (local_148 <= 0.0) {
          local_168 = local_e0[2];
          if (fVar19 == 2.8026e-45) {
            local_180 = fVar1;
            iVar7 = FUN_00550040(local_e0[2],local_e0[3]);
            local_168 = local_168 + iVar7 / 2;
          }
          fVar1 = (float)CONCAT22(local_180._2_2_,in_FPUControlWord);
          local_188[0] = (float)(int)ROUND((float)(int)local_168 * _DAT_007f1108);
          uVar5 = (short)local_138 + local_188[0]._0_2_;
          local_138 = CONCAT22(local_138._2_2_,uVar5);
          local_154 = (float)(&DAT_029899a0)[uVar5 >> 1] * _DAT_00881cc0 + local_174;
          local_14c = _DAT_00881cc0 * (float)(&DAT_029899a0)[(int)(uVar5 + 0x4000) >> 1 & 0x7fff] +
                      local_16c;
        }
        local_164 = local_174;
        local_160 = local_150 - _DAT_007f1104;
        local_15c = local_16c;
        local_180 = fVar1;
        fVar21 = (float10)FUN_005506f0(0,&local_164,0x40a00000,0xffffffff);
        local_178 = (float)fVar21;
        if (local_178 != 2e+06) {
          if ((_DAT_02920d84 != 2e+06) && (local_178 < _DAT_02920d84)) {
            local_178 = _DAT_02920d84;
          }
          if (local_170 < local_178 + _DAT_007f1104) {
            local_170 = local_178 + _DAT_007f1104;
          }
        }
        local_120 = 10.0;
        local_118 = _DAT_007f110c;
      }
LAB_0040c38f:
      if (local_134 == 0.0) {
        if (((DAT_0087b234 == 0) || (*(int *)(PTR_DAT_00802c54 + 0x128) != DAT_0087b234)) &&
           ((DAT_0087b29c == 0 || (*(int *)(PTR_DAT_00802c54 + 0x128) != DAT_0087b29c)))) {
          if (DAT_007f18f4 != -1) {
            iVar7 = FUN_0055cee0(&local_174,0,0,_DAT_007f113c,0,0xffffffff,(int)DAT_007f18f4,
                                 0xffffffff,&local_100,0,0);
            if (iVar7 != 0) {
              bVar3 = false;
              local_168 = 0;
              do {
                if (((&DAT_0093d7f0)[local_168] != 0) && ((&DAT_0093d7f0)[local_168] == iVar7)) {
                  bVar3 = true;
                }
                local_168 = local_168 + 1;
              } while ((int)local_168 < 8);
              local_134 = _DAT_007f1140;
              if (!bVar3) {
                local_134 = _DAT_007f1140 * 0.5;
              }
              fVar21 = (float10)FUN_005c0240(local_100);
              local_180 = (float)((float10)1 - fVar21 / (float10)_DAT_007f113c);
              if (local_180 < 0.0) {
                local_180 = 0.0;
              }
              iVar7 = FUN_006e6b90();
              local_180 = (float)(extraout_ST0_00 -
                                 ((float10)(float)(&DAT_029899a0)[iVar7 >> 1 & 0x7fff] +
                                 extraout_ST0_00) * (float10)0.5);
              FUN_005b3800(&local_164,&local_174,&local_154);
              FUN_005b3b30(&local_164,&local_164);
              local_188[0] = local_180 * local_134;
              local_e8 = (double)local_188[0];
              FUN_005b3830(&local_164,&local_164,local_188[0]);
              local_170 = local_170 + (float)local_e8;
              local_174 = local_174 + local_164;
              local_16c = local_16c + local_15c;
            }
          }
        }
        else {
          FUN_0055e340(local_f8,0);
        }
        if ((local_134 == 0.0) && (DAT_007f193c != -1)) {
          iVar7 = FUN_0055cee0(&local_174,0,0,_DAT_007f113c,0,0xffffffff,(int)DAT_007f193c,
                               0xffffffff,&local_100,0,0);
          if (iVar7 != 0) {
            fVar21 = (float10)FUN_005c0240(local_100);
            local_180 = (float)((float10)1 - fVar21 / (float10)_DAT_007f1144);
            FUN_005b3800(&local_164,&local_174,&local_154);
            FUN_005b3b30(&local_164,&local_164);
            local_188[0] = local_180 * _DAT_007f1148;
            FUN_005b3830(&local_164,&local_164,local_188[0]);
            local_170 = local_180 * _DAT_007f1148 + local_170;
            local_174 = local_174 + local_164;
            local_16c = local_16c + local_15c;
          }
        }
      }
      else {
        local_188[0] = (float)(param_1[0x7f] - 0x8000);
        local_178 = (float)(int)local_188[0];
        if (local_178 < 0.0) {
          local_178 = local_178 + 65536.0;
        }
        FUN_005b3800(&local_164,&local_174,&local_154);
        FUN_005b3b30(&local_164,&local_164);
        FUN_005b3830(&local_164,&local_164,local_134);
        local_170 = local_170 + local_134;
        if ((local_144 <= local_178 - 4096.0) || (local_178 + 4096.0 <= local_144)) {
          iVar7 = param_1[0x7f];
          local_188[0] = (float)(iVar7 - 0x1000);
          if ((local_144 <= (float)(int)local_188[0]) ||
             (local_188[0] = (float)(iVar7 + 0x1000), (float)(int)local_188[0] <= local_144)) {
            local_174 = local_174 + local_164;
            fVar21 = (float10)local_16c + (float10)local_15c;
          }
          else {
            local_140 = local_140 * 0.75;
            local_174 = (float)((float10)local_174 +
                               (float10)local_164 +
                               (float10)local_140 *
                               (float10)(float)(&DAT_029899a0)[iVar7 >> 1 & 0x7fff]);
            fVar21 = (float10)local_140 *
                     (float10)(float)(&DAT_029899a0)[iVar7 + 0x4000 >> 1 & 0x7fff] +
                     (float10)local_15c + (float10)local_16c;
          }
        }
        else {
          local_140 = local_140 * 0.5;
          iVar7 = FUN_006e6b90();
          local_174 = local_174 +
                      local_164 + local_140 * (float)(&DAT_029899a0)[iVar7 >> 1 & 0x7fff];
          iVar7 = FUN_006e6b90();
          fVar21 = extraout_ST0 * (float10)(float)(&DAT_029899a0)[iVar7 >> 1 & 0x7fff] +
                   (float10)local_15c + (float10)local_16c;
        }
        local_16c = (float)fVar21;
        FUN_0054a3e0(PTR_DAT_008021b4,0x3f400000,0,0);
      }
      if (((DAT_0087b18c != 0) && (*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_0087b18c)) &&
         (local_134 == 0.0)) {
        FUN_0055e340(local_f8,0);
        FUN_005b3800(&local_164,&local_84,local_f8);
        fVar21 = (float10)FUN_005b3b00(&local_164);
        local_188[0] = (float)fVar21;
        if (DAT_0093d814 == 0) {
          local_180 = local_188[0] / 125.0;
          if (0.75 < local_180) {
            local_180 = 0.6;
          }
        }
        else {
          local_180 = 0.0;
        }
        iVar7 = FUN_006e6b90();
        local_188[0] = (float)(&DAT_029899a0)[iVar7 >> 1 & 0x7fff] + 1.0;
        FUN_005b3830(&local_164,&local_164,local_188[0]);
        local_160 = 0.0;
        FUN_005b3800(&local_174,&local_174,&local_164);
      }
      if (((*(int *)(PTR_DAT_00802c54 + 300) != 0) &&
          (*(int *)(PTR_DAT_00802c54 + 300) == DAT_00951364)) && (*(char *)((int)param_1 + 1) != -1)
         ) {
        local_170 = *(float *)(*(char *)((int)param_1 + 1) * 0x13c + 0xd4 +
                              **(int **)(PTR_DAT_00802c54 + 0x2988));
      }
      if ((*(float *)(*(int *)(PTR_DAT_00802c54 + 0x128) + 0xa4) != 0.0) &&
         (*(char *)(param_1 + 0x8b) == *(char *)((int)param_1 + 0x22d))) {
        fVar11 = 0.0;
        local_144 = 0.0;
        FUN_005b3620(&local_10c,&DAT_0080250c,param_1[0x7f]);
        local_168 = 0;
        fVar1 = local_144;
        if (0 < (int)fVar19) {
          do {
            iVar7 = FUN_00550040(0,(short)local_e0[local_168 + 2]);
            uVar12 = local_168;
            local_188[0] = (float)-iVar7;
            if (local_e0[local_168] != 0) {
              iVar7 = FUN_006e6b90();
              fVar11 = (float)((int)fVar11 + iVar7);
            }
            local_168 = uVar12 + 1;
            fVar1 = fVar11;
          } while ((int)local_168 < (int)fVar19);
        }
        local_144 = fVar1;
        fVar1 = *(float *)(*(int *)(PTR_DAT_00802c54 + 0x128) + 0xa4);
        if (1 < (int)fVar19) {
          fVar1 = (1.0 / (float)(int)local_158) * fVar1;
        }
        local_180._2_2_ = (ushort)((uint)fVar1 >> 0x10);
        local_180 = (float)CONCAT22(local_180._2_2_,in_FPUControlWord);
        local_110 = 0xffffffff;
        local_ec = 1;
        local_188[0] = (float)(int)ROUND((float)(int)local_144 * fVar1);
        local_130 = (float)((uint)local_188[0] & 0xffff);
        local_128 = 1.0;
      }
      if (DAT_007f3b14 != 0xffffffff) {
        fVar21 = (float10)FUN_005becc0(&local_174,&local_154,&local_164);
        local_180 = (float)fVar21;
        FUN_005b3b30(&local_164,&local_164);
        local_188[0] = local_180 * 0.666;
        FUN_005b3830(&local_164,&local_164,local_188[0]);
        FUN_005b37d0(&local_174,&local_154,&local_164);
      }
    }
    DAT_007f10f4 = 0xffffffff;
    fVar19 = local_13c;
    break;
  case '\x02':
    FUN_00577950();
    if (DAT_00951924 != (undefined4 *)0x0) {
      _DAT_009518fc = *DAT_00951924;
      _DAT_00951900 = DAT_00951924[1];
      _DAT_00951904 = DAT_00951924[2];
    }
    if (DAT_00951920 != (undefined4 *)0x0) {
      _DAT_00951908 = *DAT_00951920;
      _DAT_0095190c = DAT_00951920[1];
      _DAT_00951910 = DAT_00951920[2];
    }
    pfVar17 = *(float **)(DAT_009514e4 + 8);
    local_174 = *pfVar17;
    local_170 = pfVar17[1];
    local_16c = pfVar17[2];
    iVar7 = *(int *)(DAT_009514e4 + 8);
    local_154 = *(float *)(iVar7 + 0xc);
    local_150 = *(float *)(iVar7 + 0x10);
    local_14c = *(float *)(iVar7 + 0x14);
    if (DAT_009514de != '\0') {
      local_120 = 10.0;
      local_118 = 10.0;
    }
    if (DAT_009514dc != 0) {
      local_110 = (uint)DAT_009514dc;
    }
    FUN_005765b0();
    break;
  case '\x03':
    pfVar17 = *(float **)(*(int *)(*(int *)(PTR_DAT_00802c54 + 0x2ac4) + 8) + 8);
    local_174 = *pfVar17;
    local_170 = pfVar17[1];
    local_16c = pfVar17[2];
    iVar7 = *(int *)(*(int *)(*(int *)(PTR_DAT_00802c54 + 0x2ac4) + 8) + 8);
    local_154 = *(float *)(iVar7 + 0xc);
    local_150 = *(float *)(iVar7 + 0x10);
    local_14c = *(float *)(iVar7 + 0x14);
    if (DAT_00876580 != 0) {
      local_114 = 0;
    }
    break;
  case '\x04':
    local_174 = DAT_0095138c;
    local_170 = DAT_00951390;
    local_16c = DAT_00951394;
    local_154 = DAT_009513a0;
    local_150 = DAT_009513a4;
    local_14c = DAT_009513a8;
    if (DAT_00951424 != 0) {
      FUN_0040aa90(&local_174);
    }
    FUN_00541bc0(*(undefined4 *)(PTR_DAT_00802c54 + 0x2988),&local_174,0xffffffff,0xffffffff,param_1
                );
    break;
  case '\x05':
    fVar1 = _DAT_007f10f8 * ABS(_DAT_007f1128) * _DAT_00925018;
    local_188[0] = fVar1;
    if (DAT_007f1138 != (int *)0x0) {
      local_d0 = fVar1 * local_158 * 127.5;
      local_188[0] = (float)(uint)*(byte *)(*DAT_007f1138 + 0x9e);
      local_cc = (float)*(byte *)(*DAT_007f1138 + 0x9c) * fVar1 - (float)(int)local_188[0] * fVar1;
      local_c8 = fVar1 * -local_180 * 127.5;
      FUN_005b3620(&local_d0,&local_d0,param_1[0x7f]);
      FUN_005b37d0(&DAT_007f1118,&DAT_007f1118,&local_d0);
      sVar6 = FUN_006e6b90();
      sVar6 = DAT_007f1124 + sVar6;
      if (sVar6 < 0x4001) {
        DAT_007f1124 = -0x4000;
        if (-0x4001 < sVar6) goto LAB_0040cdd5;
      }
      else {
        sVar6 = 0x4000;
LAB_0040cdd5:
        DAT_007f1124 = sVar6;
      }
      sVar6 = FUN_006e6b90();
      DAT_007f1126 = DAT_007f1126 + sVar6;
      if ((*(uint *)(*DAT_007f1138 + 0x70) & DAT_008022a4) == 0) {
        local_188[0] = (float)(uint)*(byte *)(*DAT_007f1138 + 0x9f);
        _DAT_007f1128 =
             (_DAT_007f1128 - (float)*(byte *)(*DAT_007f1138 + 0x9d) * (0.1 / _DAT_007f1130)) +
             (float)(int)local_188[0] * (0.1 / _DAT_007f1130);
        if (_DAT_007f1128 < 0.1) {
          _DAT_007f1128 = 0.1;
        }
      }
    }
    local_174 = DAT_007f1118;
    local_154 = DAT_007f1118;
    local_150 = _DAT_007f112c + DAT_007f111c;
    local_170 = DAT_007f111c;
    local_16c = DAT_007f1120;
    local_14c = DAT_007f1120;
    FUN_005b35a0(&local_10c,&DAT_0080250c,(int)DAT_007f1124);
    FUN_005b3620(&local_10c,&local_10c,(int)DAT_007f1126);
    local_174 = _DAT_007f1128 * local_10c + local_174;
    local_170 = _DAT_007f1128 * local_108 + local_170;
    local_16c = _DAT_007f1128 * local_104 + local_16c;
    break;
  case '\x06':
    pfVar17 = *(float **)(*(int *)(*(int *)(PTR_DAT_00802c54 + 0x2ac4) + 0x60) + 8);
    local_174 = *pfVar17;
    local_170 = pfVar17[1];
    local_16c = pfVar17[2];
    iVar7 = *(int *)(*(int *)(*(int *)(PTR_DAT_00802c54 + 0x2ac4) + 0x60) + 8);
    local_154 = *(float *)(iVar7 + 0xc);
    local_150 = *(float *)(iVar7 + 0x10);
    local_14c = *(float *)(iVar7 + 0x14);
    fVar21 = (float10)FUN_005b7d30(_DAT_0092505c,0x411522d1);
    local_188[0] = (float)(int)ROUND((fVar21 / (float10)9.321000099182129) * (float10)65536.0);
    local_174 = (float)(&DAT_029899a0)[(uint)local_188[0] >> 1 & 0x7fff] * 0.05 + local_174;
    fVar21 = (float10)FUN_005b7d30(_DAT_0092505c,0x40b95810);
    local_188[0] = (float)(int)ROUND((fVar21 / (float10)5.791999816894531) * (float10)65536.0);
    local_170 = (float)(&DAT_029899a0)[(uint)local_188[0] >> 1 & 0x7fff] * 0.025 + local_170;
    fVar21 = (float10)FUN_005b7d30(_DAT_0092505c,0x40e5db23);
    local_188[0] = (float)(int)ROUND((fVar21 / (float10)7.183000087738037) * (float10)65536.0);
    local_180._0_2_ = in_FPUControlWord;
    goto LAB_0040d11a;
  case '\a':
    pfVar17 = *(float **)(*(int *)(*(int *)(PTR_DAT_00802c54 + 0x2ac4) + 0x3c) + 8);
    local_174 = *pfVar17;
    local_170 = pfVar17[1];
    local_16c = pfVar17[2];
    iVar7 = *(int *)(*(int *)(*(int *)(PTR_DAT_00802c54 + 0x2ac4) + 0x3c) + 8);
    local_154 = *(float *)(iVar7 + 0xc);
    local_150 = *(float *)(iVar7 + 0x10);
    local_14c = *(float *)(iVar7 + 0x14);
    FUN_004246f0(&local_168,&local_12c);
    if (local_12c == 1) {
      if ((&DAT_0087b6ca)[local_168] != '\0') {
        local_168 = (uint)(local_168 == 0);
      }
      local_154 = (float)(&DAT_00856904)[local_168 * 3];
      local_14c = (float)(&DAT_0085690c)[local_168 * 3];
      FUN_005b3800(&local_164,&local_154,&local_174);
      FUN_005b3830(&local_164,&local_164,0x3e800000);
      FUN_005b37d0(&local_174,&local_174,&local_164);
      local_150 = local_150 - 0.075;
    }
    fVar21 = (float10)FUN_005b7d30(_DAT_0092505c,0x411522d1);
    local_188[0] = (float)(int)ROUND((fVar21 / (float10)9.321000099182129) * (float10)65536.0);
    local_174 = (float)(&DAT_029899a0)[(uint)local_188[0] >> 1 & 0x7fff] * 0.05 + local_174;
    fVar21 = (float10)FUN_005b7d30(_DAT_0092505c,0x40b95810);
    local_188[0] = (float)(int)ROUND((fVar21 / (float10)5.791999816894531) * (float10)65536.0);
    local_170 = (float)(&DAT_029899a0)[(uint)local_188[0] >> 1 & 0x7fff] * 0.025 + local_170;
    fVar21 = (float10)FUN_005b7d30(_DAT_0092505c,0x40e5db23);
    local_188[0] = (float)(int)ROUND((fVar21 / (float10)7.183000087738037) * (float10)65536.0);
    local_180._0_2_ = in_FPUControlWord;
LAB_0040d11a:
    local_16c = (float)(&DAT_029899a0)[local_188[0]._0_2_ >> 1] * 0.025 + local_16c;
    in_FPUControlWord = (undefined2)local_180;
    break;
  case '\b':
    local_174 = *DAT_0087ffec;
    local_170 = DAT_0087ffec[1];
    local_16c = DAT_0087ffec[2];
    FUN_004c7820(&local_154);
    fVar21 = (float10)FUN_005b7d30(_DAT_0092505c,0x411522d1);
    local_188[0] = (float)(int)ROUND((fVar21 / (float10)9.321000099182129) * (float10)65536.0);
    local_174 = (float)(&DAT_029899a0)[(uint)local_188[0] >> 1 & 0x7fff] * 0.1 + local_174;
    fVar21 = (float10)FUN_005b7d30(_DAT_0092505c,0x40b95810);
    local_188[0] = (float)(int)ROUND((fVar21 / (float10)5.791999816894531) * (float10)65536.0);
    local_170 = (float)(&DAT_029899a0)[(uint)local_188[0] >> 1 & 0x7fff] * 0.05 + local_170;
    fVar21 = (float10)FUN_005b7d30(_DAT_0092505c,0x40e5db23);
    local_180 = (float)CONCAT22(local_180._2_2_,in_FPUControlWord);
    local_188[0] = (float)(int)ROUND((fVar21 / (float10)7.183000087738037) * (float10)65536.0);
    local_16c = (float)(&DAT_029899a0)[(uint)local_188[0] >> 1 & 0x7fff] * 0.05 + local_16c;
    break;
  case '\t':
    pfVar17 = *(float **)(DAT_00879b3c + 8);
    local_174 = *pfVar17;
    local_170 = pfVar17[1];
    local_16c = pfVar17[2];
    iVar7 = *(int *)(DAT_00879b3c + 8);
    local_154 = *(float *)(iVar7 + 0xc);
    local_150 = _DAT_007f9348 + *(float *)(iVar7 + 0x10);
    local_14c = *(float *)(iVar7 + 0x14);
    local_120 = 10.0;
    local_118 = 10.0;
    break;
  default:
    break;
  case '\v':
    fVar19 = _DAT_007f10e8;
    if (DAT_0087aa20 != '\x02') {
      fVar19 = 6.0;
    }
    local_144 = (_DAT_00924fdc + fVar19) / 100.0;
    local_180 = local_144;
    if (_DAT_007f10d8 < local_144) {
      DAT_0087aa21 = 1;
      local_180 = _DAT_007f10d8;
    }
    FUN_00550a20(*(undefined4 *)(**(int **)(PTR_DAT_00802c54 + 0x2988) + 0x14),local_180,&local_154,
                 &local_138,0,0);
    if (1.0 < local_144) {
      local_144 = 1.0;
    }
    FUN_00550a20(*(undefined4 *)(**(int **)(PTR_DAT_00802c54 + 0x2988) + 0x14),local_144,local_78,0,
                 0,0);
    FUN_005b3620(&local_10c,&DAT_0080250c,local_138 & 0xffff);
    _DAT_00882bc4 = local_10c;
    _DAT_00882bc8 = local_108;
    _DAT_00882bcc = local_104;
    FUN_005b3620(&local_10c,&local_10c,0x4000);
    iVar7 = 0;
    local_15c = 0.0;
    local_164 = 0.0;
    local_168 = 0;
    local_12c = 0;
    do {
      iVar15 = (&DAT_0093d7f0)[local_168];
      if (iVar15 != 0) {
        iVar7 = iVar7 + 1;
        local_f8[0] = *(float *)(iVar15 + 0x80) - local_154;
        local_f8[2] = *(float *)(iVar15 + 0x88) - local_14c;
        local_188[0] = local_10c * local_f8[0] + local_104 * local_f8[2];
        local_164 = local_164 + local_188[0] * local_10c;
        local_15c = local_188[0] * local_104 + local_15c;
        local_12c = iVar7;
      }
      local_168 = local_168 + 1;
    } while ((int)local_168 < 2);
    if (iVar7 == 2) {
      local_164 = local_164 * 0.5;
      local_15c = local_15c * 0.5;
    }
    FUN_005b37d0(&local_174,&local_154,&DAT_007f10dc);
    local_174 = local_164 + local_174;
    local_16c = local_15c + local_16c;
    local_154 = local_78[0] + local_164;
    local_14c = local_15c + local_70;
    FUN_005b3800(&local_164,&local_154,&local_174);
    local_188[0] = local_164 * local_164 + local_15c * local_15c;
    fVar21 = (float10)FUN_005c0240(local_188[0]);
    iVar7 = FUN_005be2d0(local_160,(float)fVar21);
    local_13c = (float)-iVar7;
    local_114 = FUN_005be2d0(local_164,local_15c);
    local_120 = 8.0;
    fVar19 = (float)-iVar7;
  }
  if ((*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_0087b26c) ||
     (*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_0087b274)) {
    fVar21 = (float10)FUN_005b7d30(_DAT_0092505c,0x411522d1);
    local_188[0] = (float)(int)ROUND((fVar21 / (float10)9.321000099182129) * (float10)65536.0);
    local_174 = (float)(&DAT_029899a0)[(uint)local_188[0] >> 1 & 0x7fff] * 0.1 + local_174;
    fVar21 = (float10)FUN_005b7d30(_DAT_0092505c,0x40b95810);
    local_188[0] = (float)(int)ROUND((fVar21 / (float10)5.791999816894531) * (float10)65536.0);
    local_170 = (float)(&DAT_029899a0)[(uint)local_188[0] >> 1 & 0x7fff] * 0.05 + local_170;
    fVar21 = (float10)FUN_005b7d30(_DAT_0092505c,0x40e5db23);
    local_180 = (float)CONCAT22(local_180._2_2_,in_FPUControlWord);
    local_188[0] = (float)(int)ROUND((fVar21 / (float10)7.183000087738037) * (float10)65536.0);
    local_16c = (float)(&DAT_029899a0)[(uint)local_188[0] >> 1 & 0x7fff] * 0.05 + local_16c;
  }
  iVar7 = local_fc;
  if (*(char *)(param_1 + 0x8b) == local_fc) {
    if (((local_38._1_1_ == -1) || (*(char *)((int)param_1 + 1) == -1)) ||
       ((fVar1 = local_11c, *(char *)((int)param_1 + 0x2a) == local_e &&
        (*(char *)((int)param_1 + 1) == local_38._1_1_)))) {
      if ((*(char *)((int)param_1 + 1) == local_38._1_1_) ||
         ((*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_0087b0f8 &&
          ((local_38._1_1_ == -1 || (*(char *)((int)param_1 + 1) == -1)))))) goto LAB_0040d8c4;
      fVar1 = 1.0;
    }
    FUN_0054a3e0(param_1,fVar1,0,1);
  }
LAB_0040d8c4:
  if (*(char *)((int)param_1 + 0x22a) != '\0') {
    param_1[0x56] = local_174;
    param_1[0x57] = local_170;
    param_1[0x58] = local_16c;
    param_1[0x62] = local_154;
    param_1[99] = local_150;
    *(undefined1 *)((int)param_1 + 0x22a) = 0;
    param_1[100] = local_14c;
  }
  if ((float)param_1[0x6f] < (float)param_1[0x70]) {
    if ((float)param_1[0x71] <= 0.0) {
      local_188[0] = (float)param_1[0x6f] + _DAT_00925018;
      param_1[0x6f] = local_188[0];
      if ((float)param_1[0x70] < local_188[0]) {
        param_1[0x6f] = param_1[0x70];
      }
    }
    else {
      param_1[0x71] = (float)param_1[0x71] - _DAT_00925018;
    }
  }
  if ((float)param_1[0x70] <= (float)param_1[0x6f]) {
    local_140 = 0.0;
    fVar1 = 0.0;
  }
  else {
    fVar1 = (float)param_1[0x6f] / (float)param_1[0x70];
    local_140 = fVar1 + fVar1;
    if (1.0 < local_140) {
      local_140 = 1.0;
    }
  }
  if ((float)param_1[0x6f] < (float)param_1[0x70]) {
    param_1[0x4d] = ((float)param_1[0x56] - (float)param_1[0x53]) * fVar1 + (float)param_1[0x53];
    param_1[0x4e] = ((float)param_1[0x57] - (float)param_1[0x54]) * fVar1 + (float)param_1[0x54];
    param_1[0x4f] = ((float)param_1[0x58] - (float)param_1[0x55]) * fVar1 + (float)param_1[0x55];
    param_1[0x59] = ((float)param_1[0x62] - (float)param_1[0x5f]) * fVar1 + (float)param_1[0x5f];
    param_1[0x5a] = ((float)param_1[99] - (float)param_1[0x60]) * fVar1 + (float)param_1[0x60];
    param_1[0x5b] = ((float)param_1[100] - (float)param_1[0x61]) * fVar1 + (float)param_1[0x61];
  }
  param_1[0x78] = local_120;
  param_1[0x79] = local_118;
  if ((*(char *)(param_1 + 0x8b) == iVar7) ||
     ((float)param_1[0x70] < (float)param_1[0x6f] == ((float)param_1[0x70] == (float)param_1[0x6f]))
     ) {
    if ((float)param_1[0x6f] < (float)param_1[0x70]) {
      local_174 = (local_174 - (float)param_1[0x4d]) * fVar1 + (float)param_1[0x4d];
      local_170 = (local_170 - (float)param_1[0x4e]) * fVar1 + (float)param_1[0x4e];
      local_16c = (float)param_1[0x4f] + (local_16c - (float)param_1[0x4f]) * fVar1;
    }
    local_180 = _DAT_00925018 * local_120;
    if (1.0 < local_180) {
      local_180 = 1.0;
    }
    local_180 = local_180 * _DAT_007f10d4;
    param_1[0x47] = (float)param_1[0x47] + local_180 * (local_174 - (float)param_1[0x47]);
    param_1[0x48] = (local_170 - (float)param_1[0x48]) * local_180 + (float)param_1[0x48];
    param_1[0x49] = (local_16c - (float)param_1[0x49]) * local_180 + (float)param_1[0x49];
  }
  else {
    param_1[0x78] = local_120;
    param_1[0x47] = local_174;
    param_1[0x48] = local_170;
    param_1[0x79] = local_118;
    param_1[0x49] = local_16c;
  }
  param_1[0x50] = local_174;
  param_1[0x4a] = local_154;
  param_1[0x51] = local_170;
  param_1[0x4b] = local_150;
  param_1[0x52] = local_16c;
  param_1[0x4c] = local_14c;
  local_178 = (float)param_1[0x4a] - (float)param_1[0x47];
  local_148 = (float)param_1[0x4b] - (float)param_1[0x48];
  local_144 = (float)param_1[0x4c] - (float)param_1[0x49];
  if (fVar19 == -NAN) {
    local_188[0] = local_144 * local_144 + local_178 * local_178;
    fVar21 = (float10)FUN_005c0240(local_188[0]);
    iVar7 = FUN_005be2d0(local_148,(float)fVar21);
    fVar19 = (float)(-iVar7 & 0xffff);
  }
  if (((float)param_1[0x6f] < (float)param_1[0x70]) && (*(char *)((int)param_1 + 0x22b) == '\x02'))
  {
    local_188[0] = (float)FUN_00550040(*(undefined2 *)(param_1 + 0x87),fVar19);
    iVar7 = FUN_006e6b90();
    fVar19 = (float)(iVar7 + (uint)*(ushort *)(param_1 + 0x87));
  }
  *(short *)((int)param_1 + 0x21e) = SUB42(fVar19,0);
  uVar12 = local_114;
  if (local_114 == 0xffffffff) {
    uVar12 = FUN_005be2d0(local_178,local_144);
  }
  if (((float)param_1[0x6f] < (float)param_1[0x70]) && (*(char *)((int)param_1 + 0x22b) == '\x02'))
  {
    local_188[0] = (float)FUN_00550040(*(undefined2 *)(param_1 + 0x88),uVar12);
    iVar7 = FUN_006e6b90();
    uVar12 = iVar7 + (uint)*(ushort *)(param_1 + 0x88);
  }
  *(short *)((int)param_1 + 0x222) = (short)uVar12;
  uVar13 = local_110;
  if (local_110 == 0xffffffff) {
    if (local_ec == 0) {
      uVar13 = 0;
    }
    else {
      uVar13 = (uint)local_130 & 0xffff;
    }
  }
  if (((float)param_1[0x6f] < (float)param_1[0x70]) && (*(char *)((int)param_1 + 0x22b) == '\x02'))
  {
    local_188[0] = (float)FUN_00550040(*(undefined2 *)(param_1 + 0x89),uVar13);
    iVar7 = FUN_006e6b90();
    uVar13 = iVar7 + (uint)*(ushort *)(param_1 + 0x89);
  }
  *(short *)((int)param_1 + 0x226) = (short)uVar13;
  if ((*(char *)(param_1 + 0x8b) == local_fc) ||
     ((float)param_1[0x70] < (float)param_1[0x6f] == ((float)param_1[0x70] == (float)param_1[0x6f]))
     ) {
    if (local_13c == -NAN) {
      uVar14 = param_1[0x7e] - (int)fVar19 & 0xffff;
      if (0x7fff < uVar14) {
        uVar14 = uVar14 - 0x10000;
      }
      if ((int)uVar14 < 0) {
        _DAT_007f10d4 = _DAT_007f10d4 + _DAT_00925018;
        if (1.0 < _DAT_007f10d4) {
          _DAT_007f10d4 = 1.0;
        }
      }
      fVar21 = (float10)FUN_005c0240(_DAT_007f10d4);
      local_188[0] = (float)(fVar21 * (float10)(float)param_1[0x79]);
      uVar14 = FUN_00550070(*(undefined2 *)(param_1 + 0x7e),fVar19,local_188[0]);
      param_1[0x7e] = uVar14 & 0xffff;
    }
    else {
      param_1[0x7e] = local_13c;
    }
    uVar14 = local_114;
    if (local_114 == 0xffffffff) {
      local_188[0] = _DAT_007f10d4 * (float)param_1[0x79];
      uVar14 = FUN_00550070(*(undefined2 *)(param_1 + 0x7f),uVar12,local_188[0]);
      uVar14 = uVar14 & 0xffff;
    }
    param_1[0x7f] = uVar14;
    if (local_110 == 0xffffffff) {
      if (local_128 <= 0.0) {
        local_128 = (float)param_1[0x79];
      }
      local_188[0] = local_128 * _DAT_007f10d4;
      uVar12 = FUN_00550070(*(undefined2 *)(param_1 + 0x80),uVar13,local_188[0]);
      param_1[0x80] = uVar12 & 0xffff;
    }
    else {
      param_1[0x80] = local_110;
    }
  }
  else {
    param_1[0x7e] = fVar19;
    param_1[0x7f] = uVar12;
    param_1[0x80] = uVar13;
  }
  local_128 = (float)param_1[0x7e];
  local_130 = (float)param_1[0x7f];
  local_13c = (float)param_1[0x80];
  _DAT_007f10d4 = _DAT_00925018 * 0.1 + _DAT_007f10d4;
  if (1.0 < _DAT_007f10d4) {
    _DAT_007f10d4 = 1.0;
  }
  FUN_005495e0(param_1);
  local_12c = 0;
  _memset(&local_c4,0,0x40);
  local_168 = 0;
  do {
    iVar7 = (&DAT_0093d7f0)[local_168];
    if (((iVar7 != 0) && ((*(byte *)(iVar7 + 0x1fc) & 0x80) != 0)) &&
       (*(char *)(iVar7 + 0x107a) == '\x04')) {
      FUN_005b37d0(&local_c4,&local_c4,iVar7 + 0xc04);
      FUN_005b37d0(&local_b4,&local_b4,(&DAT_0093d7f0)[local_168] + 0xc14);
      FUN_005b37d0(&local_a4,&local_a4,(&DAT_0093d7f0)[local_168] + 0xc24);
      local_12c = local_12c + 1;
    }
    local_168 = local_168 + 1;
  } while ((int)local_168 < 2);
  puVar10 = param_1 + 0xe;
  if (local_12c < 1) {
    FUN_005b46f0(puVar10,local_13c);
    local_188[0] = (float)(int)ROUND((float)param_1[0x85]);
    FUN_005b4cf0(puVar10,((uint)local_188[0] & 0xffff) + (int)local_128);
    local_188[0] = (float)(int)ROUND((float)param_1[0x86]);
    local_180._0_2_ = in_FPUControlWord;
    FUN_005b4f70(puVar10,((uint)local_188[0] & 0xffff) + (int)local_130);
    FUN_005b4900(puVar10,param_1 + 0x47);
    puVar18 = param_1 + 0x2e;
    for (iVar7 = 0x10; iVar7 != 0; iVar7 = iVar7 + -1) {
      *puVar18 = *puVar10;
      puVar10 = puVar10 + 1;
      puVar18 = puVar18 + 1;
    }
    puVar10 = param_1 + 0x1e;
    FUN_005b46f0(puVar10,local_13c);
    FUN_005b4cf0(puVar10,local_128);
    FUN_005b4f70(puVar10,local_130);
    FUN_005b4900(puVar10,param_1 + 0x47);
  }
  else {
    FUN_005b44e0(puVar10);
    if (1 < local_12c) {
      local_180 = 1.0 / (float)local_12c;
      FUN_005b3830(&local_c4,&local_c4,local_180);
      FUN_005b3830(&local_b4,&local_b4,local_180);
      FUN_005b3830(&local_a4,&local_a4,local_180);
      FUN_005b3b30(&local_c4,&local_c4);
      FUN_005b3b30(&local_b4,&local_b4);
      FUN_005b3b30(&local_a4,&local_a4);
    }
    *puVar10 = local_c4;
    param_1[0xf] = local_c0;
    param_1[0x12] = local_b4;
    param_1[0x13] = local_b0;
    param_1[0x16] = local_a4;
    param_1[0x10] = local_bc;
    param_1[0x17] = local_a0;
    param_1[0x14] = local_ac;
    param_1[0x18] = local_9c;
    FUN_005b4900(puVar10,param_1 + 0x47);
    puVar18 = param_1 + 0x2e;
    puVar20 = puVar18;
    for (iVar7 = 0x10; iVar7 != 0; iVar7 = iVar7 + -1) {
      *puVar20 = *puVar10;
      puVar10 = puVar10 + 1;
      puVar20 = puVar20 + 1;
    }
    FUN_005b5240(puVar18,local_13c);
    FUN_005b3b30(puVar18,puVar18);
    FUN_005b3b30(param_1 + 0x32,param_1 + 0x32);
    FUN_005b3b30(param_1 + 0x36,param_1 + 0x36);
    puVar10 = param_1 + 0x1e;
    for (iVar7 = 0x10; iVar7 != 0; iVar7 = iVar7 + -1) {
      *puVar10 = *puVar18;
      puVar18 = puVar18 + 1;
      puVar10 = puVar10 + 1;
    }
  }
  puVar10 = param_1 + 0x2e;
  if (0.0 < (float)param_1[0x72]) {
    local_188[0] = (float)param_1[0x72] - _DAT_00925018;
    param_1[0x72] = local_188[0];
    if (0.0 < local_188[0]) {
      iVar7 = FUN_006e6b90();
      local_168 = (1 - iVar7) * 0x168;
      local_188[0] = (float)(((1 - iVar7) * 0x1680000) / 0x168);
      iVar7 = FUN_006e6b90();
      fVar19 = (float)((extraout_ST0_01 / (float10)(float)param_1[0x73]) *
                      (float10)((float)(&DAT_029899a0)[iVar7 >> 1 & 0x7fff] *
                               (float)param_1[0x73] * 546.0));
      if (*(char *)(param_1 + 0x8a) != '\0') {
        fVar19 = -fVar19;
      }
      local_180._2_2_ = (ushort)((uint)fVar19 >> 0x10);
      local_180._0_2_ = in_FPUControlWord;
      if (*(char *)((int)param_1 + 0x229) == '\0') {
        local_188[0] = (float)(int)ROUND(fVar19);
        FUN_005b4dd0(puVar10,(uint)local_188[0] & 0xffff);
      }
      else if (*(char *)((int)param_1 + 0x229) == '\x01') {
        local_188[0] = (float)(int)ROUND(fVar19);
        FUN_005b5060(puVar10,(uint)local_188[0] & 0xffff);
      }
      else {
        local_188[0] = (float)(int)ROUND(fVar19);
        FUN_005b5240(puVar10,(uint)local_188[0] & 0xffff);
      }
    }
  }
  piVar8 = (int *)FUN_0055a020(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ac8),DAT_00802f54,
                               "window_frame1");
  iVar7 = FUN_0056e460(0xffffffff);
  if (((iVar7 == 0) &&
      (((iVar7 = *(int *)(PTR_DAT_00802c54 + 0x128), iVar7 != DAT_0087b234 || (DAT_009253a4 != 0))
       || (*(char *)((int)param_1 + 1) != '\x01')))) &&
     (((iVar7 != DAT_0087b228 || (piVar8 == (int *)0x0)) ||
      (((*piVar8 == 0 || ((*(byte *)(*piVar8 + 0x94) & 1) == 0)) ||
       ((*(char *)((int)param_1 + 1) != '\0' && (*(char *)((int)param_1 + 1) != '\x01')))))))) {
    if ((iVar7 == DAT_0087b254) && (DAT_0087aa20 != '\0')) {
      local_124 = 1.5;
    }
    else {
      local_168 = 0;
      puVar16 = PTR_DAT_00802c54;
      do {
        iVar7 = (&DAT_0093d7f0)[local_168];
        if ((iVar7 != 0) && ((*(byte *)(iVar7 + 0x1fc) & 0x80) != 0)) {
          if (*(int *)(puVar16 + 0x128) == DAT_0087b1d4) {
            iVar7 = FUN_0054a240(iVar7,*(undefined4 *)(puVar16 + 0x2988),
                                 *(undefined4 *)(puVar16 + 0x11c));
            puVar16 = PTR_DAT_00802c54;
            if (iVar7 != 0) {
              local_124 = 0.6;
              break;
            }
          }
          if (((0.0 < *(float *)((&DAT_0093d7f0)[local_168] + 0x1038)) &&
              (iVar7 = *(int *)(puVar16 + 300), iVar7 != 0)) &&
             ((iVar7 == DAT_0087b014 || (iVar7 == DAT_0087af5c)))) {
            local_124 = *(float *)((&DAT_0093d7f0)[local_168] + 0x1038) * _DAT_007f1110;
            break;
          }
        }
        local_168 = local_168 + 1;
      } while ((int)local_168 < 2);
    }
  }
  else {
    local_124 = 0.5;
  }
  FUN_00549be0(param_1,local_124);
  param_1[0x3e] = *puVar10;
  param_1[0x3f] = param_1[0x2f];
  param_1[0x40] = param_1[0x30];
  param_1[0x41] = param_1[0x32];
  param_1[0x42] = param_1[0x33];
  param_1[0x43] = param_1[0x34];
  param_1[0x44] = param_1[0x36];
  param_1[0x45] = param_1[0x37];
  param_1[0x46] = param_1[0x38];
  puVar18 = DAT_00925164;
  for (iVar7 = 0x10; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar18 = *puVar10;
    puVar10 = puVar10 + 1;
    puVar18 = puVar18 + 1;
  }
  FUN_00603cc0(DAT_00925164);
  FUN_00549a30(param_1);
  FUN_0040ab20();
  return;
}

