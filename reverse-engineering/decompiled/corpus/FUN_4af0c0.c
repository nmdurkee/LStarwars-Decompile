/* Ghidra analysis pseudocode, not original source.
 * ev_d01615a5a43d674e3d5304a49d42c1316108bf7c3b83d91b26d188fd5d83afac
 * Entry: 0x4af0c0; label: FUN_004af0c0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004af0c0(float param_1)

{
  short sVar1;
  ushort uVar2;
  float fVar3;
  bool bVar4;
  undefined *puVar5;
  float fVar6;
  char cVar7;
  undefined2 uVar8;
  short sVar9;
  int iVar10;
  undefined4 uVar11;
  uint uVar12;
  int iVar13;
  int iVar14;
  float fVar15;
  uint uVar16;
  float *pfVar17;
  undefined4 *puVar18;
  ushort in_FPUControlWord;
  float10 fVar19;
  float10 fVar20;
  float local_64;
  int local_60;
  float local_5c;
  uint local_58;
  float local_54;
  float local_50;
  float local_4c;
  int local_48;
  float local_44;
  int local_40;
  float local_3c [2];
  float local_34;
  float local_30 [2];
  float local_28;
  float local_24 [2];
  float local_1c;
  float local_18 [2];
  float local_10;
  float local_c [2];
  float local_4;
  
  fVar6 = param_1;
  local_44 = 10.0;
  local_60 = *(int *)((int)param_1 + 0xca4);
  local_4c = param_1;
  local_50 = 0.0;
  local_40 = 0;
  if ((((DAT_00889614 == 0.0) && (*(short *)((int)param_1 + 0x1064) == DAT_007f1940)) &&
      (*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_0087b194)) &&
     (iVar10 = FUN_005cfac0(&DAT_0087aad8), iVar10 != 0)) {
    uVar11 = FUN_005cf9e0(&DAT_0087aad8);
    fVar19 = (float10)FUN_005b3cf0(uVar11,(int)fVar6 + 0x80,local_18);
    if (((fVar19 < (float10)0.36) &&
        (DAT_00889614 = fVar6, iVar10 = *(int *)(*(int *)((int)fVar6 + 0x54) + 0x24),
        (*(float *)(iVar10 + 0x1c) + *(float *)(iVar10 + 0x18)) * 0.5 < *(float *)(local_60 + 0x28))
        ) && ((DAT_0087a908 == 0 ||
              ((*(int *)(DAT_0087a908 + 0x34) == 0 ||
               ((*(byte *)(*(int *)(DAT_0087a908 + 0x34) + 10) & 1) == 0)))))) {
      DAT_00889614 = 0.0;
    }
  }
  if ((*(short *)((int)fVar6 + 0x1064) == DAT_007f1a64) && (*(char *)((int)fVar6 + 0x7b5) == '\x17')
     ) {
    FUN_004abac0(fVar6,0,0,0x41200000,0);
  }
  *(uint *)((int)fVar6 + 0xe20) = *(uint *)((int)fVar6 + 0xe20) & 0xefffffff;
  cVar7 = FUN_0054a240(fVar6,*(undefined4 *)(PTR_DAT_00802c54 + 0x2988),
                       *(undefined4 *)(PTR_DAT_00802c54 + 0x11c));
  *(char *)((int)fVar6 + 0xe3c) = cVar7;
  if (cVar7 == '\0') {
    uVar16 = 0;
  }
  else {
    uVar16 = (uint)*(ushort *)((int)fVar6 + 0x696);
  }
  cVar7 = *(char *)((int)fVar6 + 0x7b5);
  if (cVar7 != '*') {
    *(uint *)((int)fVar6 + 0xe24) = *(uint *)((int)fVar6 + 0xe24) & 0xfffffffd;
  }
  *(undefined2 *)((int)fVar6 + 0xe10) = 0xffff;
  if ((((0.0 < *(float *)((int)fVar6 + 0xd48)) && (cVar7 != '*')) && (cVar7 != '6')) &&
     (cVar7 != ':')) {
    *(float *)((int)fVar6 + 0xd48) = *(float *)((int)fVar6 + 0xd48) - _DAT_00925018;
  }
  local_58 = uVar16;
  if (((DAT_0087af5c == 0) || (*(int *)(PTR_DAT_00802c54 + 300) != DAT_0087af5c)) ||
     (((*(byte *)((int)fVar6 + 0x1fc) & 0x80) == 0 ||
      (iVar10 = FUN_0056d800(PTR_DAT_00802c54,fVar6,1), iVar10 == 0)))) {
    local_48 = 0;
  }
  else {
    local_48 = 1;
    iVar10 = FUN_0054fa60(0);
    param_1 = (float)iVar10 * 1.5259022e-05;
    FUN_0054a850(**(undefined4 **)((int)fVar6 + 0xca4),param_1);
  }
  FUN_004cd9a0(fVar6,&local_60,&local_4c);
  if ((DAT_0087af5c == 0) || (*(int *)(PTR_DAT_00802c54 + 300) != DAT_0087af5c)) {
    local_54 = (*(float *)(local_60 + 0x28) /
               *(float *)(*(int *)(*(int *)((int)local_4c + 0x54) + 0x24) + 0x1c)) *
               *(float *)(*(int *)(*(int *)((int)fVar6 + 0x54) + 0x24) + 0x1c);
  }
  else {
    local_54 = (*(float *)(local_60 + 0x28) /
               *(float *)(*(int *)(*(int *)((int)local_4c + 0x54) + 0x24) + 0x1c)) * _DAT_007fb0c8;
  }
  if ((((*(byte *)((int)fVar6 + 0xe20) & 0x20) == 0) || (*(char *)((int)fVar6 + 0x7b5) == '#')) ||
     (*(char *)((int)fVar6 + 0x7b5) == '$')) {
    uVar8 = FUN_0054b3d0(fVar6,local_60);
    *(uint *)((int)fVar6 + 0xe20) = *(uint *)((int)fVar6 + 0xe20) | 0x200000;
    *(undefined4 *)((int)fVar6 + 0xf1c) = 0;
    *(undefined2 *)((int)fVar6 + 0xe0c) = uVar8;
    if (0.0 < *(float *)((int)fVar6 + 0xddc)) {
      *(float *)((int)fVar6 + 0xddc) = *(float *)((int)fVar6 + 0xddc) - _DAT_00925018;
    }
    local_5c = 0.0;
    if ((*(uint *)((int)fVar6 + 0xef0) & 0x400) == 0) {
      if (fVar6 == DAT_00889614) {
        *(undefined2 *)((int)fVar6 + 0x5a) = 0x4000;
        local_44 = 3.0;
        goto LAB_004af8a9;
      }
      if (((((local_54 <= 0.0) || (cVar7 = *(char *)((int)fVar6 + 0x7b5), cVar7 == '*')) ||
           ((cVar7 == '6' || ((cVar7 == ':' || (cVar7 == '#')))))) || (cVar7 == '$')) ||
         ((cVar7 == '\x17' && ((*(byte *)((int)fVar6 + 0xef8) & 1) == 0)))) {
LAB_004af7e6:
        if ((*(char *)((int)fVar6 + 0xe3c) != '\0') &&
           ((((local_54 == 0.0 || (cVar7 = *(char *)((int)fVar6 + 0x7b5), cVar7 == '*')) ||
             (cVar7 == '6')) || (cVar7 == ':')))) {
          uVar12 = FUN_00550040(uVar16,*(undefined2 *)((int)fVar6 + 0x5a));
          if (0x4000 < (int)((uVar12 ^ (int)uVar12 >> 0x1f) - ((int)uVar12 >> 0x1f))) {
            uVar16 = uVar16 + 0x8000;
          }
          if ((DAT_0087af5c == 0) ||
             (param_1 = _DAT_007fb0d8, *(int *)(PTR_DAT_00802c54 + 300) != DAT_0087af5c)) {
            param_1 = *(float *)(*(int *)(*(int *)((int)fVar6 + 0x54) + 0x24) + 0x74);
          }
          cVar7 = *(char *)((int)fVar6 + 0x7b5);
          if (((cVar7 != '*') && (cVar7 != '6')) && (cVar7 != ':')) {
            param_1 = param_1 * 0.25;
          }
          uVar11 = FUN_006e6b90(0);
          sVar9 = FUN_00550100(*(undefined2 *)((int)fVar6 + 0x5a),uVar16 & 0xffff,uVar11);
LAB_004af8a5:
          *(short *)((int)fVar6 + 0x5a) = sVar9;
        }
      }
      else {
        iVar10 = FUN_0062f150((int)fVar6 + 8,0xc,1,1);
        if ((iVar10 != 0) || (iVar10 = FUN_0062f150((int)fVar6 + 8,6,1,1), iVar10 != 0))
        goto LAB_004af7e6;
        if ((((*(char *)((int)fVar6 + 0xe3c) == '\0') ||
             ((*(byte *)((int)fVar6 + 0x1fc) & 0x80) == 0)) ||
            (*(int *)(PTR_DAT_00802c54 + 0x128) != DAT_0087b1d4)) ||
           (iVar10 = FUN_0054a240(fVar6,*(undefined4 *)(PTR_DAT_00802c54 + 0x2988),
                                  *(undefined4 *)(PTR_DAT_00802c54 + 0x11c)), iVar10 == 0)) {
          if ((*(char *)((int)fVar6 + 0xe3c) == '\0') ||
             (((iVar10 = *(int *)(PTR_DAT_00802c54 + 0x128), iVar10 != DAT_0087b258 &&
               (iVar10 != DAT_0087b25c)) && (iVar10 != DAT_0087b260)))) {
            if ((*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_0087b234) && (DAT_009253a4 == 0)) {
              local_5c = 0.75;
            }
            else if ((((*(byte *)((int)fVar6 + 0x1fc) & 0x80) != 0) && (DAT_0087af5c != 0)) &&
                    (*(int *)(PTR_DAT_00802c54 + 300) == DAT_0087af5c)) {
              local_5c = 0.25;
            }
          }
          else {
            local_5c = 0.5;
          }
        }
        else {
          local_5c = 0.5;
        }
        iVar10 = *(int *)((int)fVar6 + 0x54);
        iVar13 = *(int *)(iVar10 + 0x24);
        param_1 = *(float *)((int)fVar6 + 0x68) * *(float *)((int)fVar6 + 0x68) +
                  *(float *)((int)fVar6 + 0x70) * *(float *)((int)fVar6 + 0x70);
        fVar19 = (float10)FUN_005c0240(param_1);
        fVar15 = (float)((fVar19 - (float10)*(float *)(iVar13 + 0x14)) /
                        ((float10)*(float *)(iVar13 + 0x1c) - (float10)*(float *)(iVar13 + 0x14)));
        fVar3 = 0.0;
        if ((0.0 <= fVar15) && (fVar3 = fVar15, 1.0 < fVar15)) {
          fVar3 = 1.0;
        }
        if ((DAT_0087af5c == 0) || (*(int *)(PTR_DAT_00802c54 + 300) != DAT_0087af5c)) {
          iVar10 = *(int *)(iVar10 + 0x24);
          param_1 = (*(float *)(iVar10 + 0x78) - *(float *)(iVar10 + 0x74)) * fVar3 +
                    *(float *)(iVar10 + 0x74);
        }
        else {
          param_1 = _DAT_007fb0d8 + (_DAT_007fb0dc - _DAT_007fb0d8) * fVar3;
        }
        if (((*(char *)((int)fVar6 + 0xe3c) != '\0') &&
            (param_1 = (*(float *)((int)fVar6 + 0xdc8) * -0.25 + 1.0) * param_1, local_5c != 0.0))
           && (((*(byte *)((int)fVar6 + 0x1fc) & 0x80) == 0 ||
               ((DAT_0087af5c == 0 || (*(int *)(PTR_DAT_00802c54 + 300) != DAT_0087af5c)))))) {
          param_1 = local_5c * param_1;
        }
        uVar11 = FUN_006e6b90(0);
        uVar11 = FUN_00550100(*(undefined2 *)((int)fVar6 + 0x5a),uVar8,uVar11);
        *(short *)((int)fVar6 + 0x5a) = (short)uVar11;
        if (*(char *)((int)fVar6 + 0xe3c) != '\0') {
          uVar16 = FUN_00550040(local_58,uVar11);
          param_1 = (float)FUN_006e6b90();
          if ((int)param_1 < 0) {
            param_1 = 0.0;
          }
          if ((((*(byte *)((int)fVar6 + 0x1fc) & 0x80) == 0) || (DAT_0087af5c == 0)) ||
             (*(int *)(PTR_DAT_00802c54 + 300) != DAT_0087af5c)) {
            fVar15 = param_1;
            if (local_5c != 0.0) {
              fVar15 = (float)FUN_006e6b90();
            }
          }
          else {
            fVar15 = 0.0;
          }
          sVar9 = (short)local_58;
          if ((int)((uVar16 ^ (int)uVar16 >> 0x1f) - ((int)uVar16 >> 0x1f)) < 0x4001) {
            iVar10 = (int)fVar15 * 0x10000;
            if ((int)uVar16 < ((int)fVar15 * -0x10000) / 0x168) {
              sVar9 = sVar9 - ((short)((ulonglong)((longlong)iVar10 * 0xb60b60b7) >> 0x28) -
                              ((short)(char)((char)(iVar10 / 0x1680000) + (char)(iVar10 >> 0x1f)) >>
                              0xf));
            }
            else {
LAB_004af7c5:
              if ((int)uVar16 <= iVar10 / 0x168) goto LAB_004af8a9;
              sVar9 = (short)(iVar10 / 0x168) + sVar9;
            }
          }
          else {
            if (((int)uVar16 < 1) ||
               (iVar10 = ((0xb4 - (int)fVar15) * 0x10000) / 0x168, iVar10 <= (int)uVar16)) {
              if ((int)uVar16 < 0) {
                iVar10 = ((int)fVar15 + -0xb4) * 0x10000;
                goto LAB_004af7c5;
              }
              goto LAB_004af8a9;
            }
            sVar9 = (short)iVar10 + sVar9;
          }
          goto LAB_004af8a5;
        }
      }
LAB_004af8a9:
      if (((*(char *)((int)fVar6 + 0x7b5) != -1) || (*(char *)((int)fVar6 + 0x1078) == '\0')) ||
         (param_1 = ABS(*(float *)((int)fVar6 + 0x6b8)), DAT_02998448 <= param_1)) {
        if ((((*(byte *)((int)fVar6 + 0x1fc) & 0x80) != 0) &&
            ((*(uint *)(*(int *)(*(int *)((int)fVar6 + 0x54) + 0x24) + 0x90) & 0x10000) == 0)) &&
           ((*(uint *)((int)fVar6 + 0xef4) & 0x80000000) == 0)) {
          iVar10 = FUN_00552020((int)fVar6 + 0x80,
                                *(undefined4 *)(*(int *)(PTR_DAT_00802c54 + 0x2ac4) + 0x40),local_30
                                ,local_3c,0);
          if (iVar10 == 0) {
            local_50 = (float)FUN_00552020((int)fVar6 + 0x80,
                                           *(undefined4 *)
                                            (*(int *)(PTR_DAT_00802c54 + 0x2ac4) + 0x44),local_30,
                                           local_3c,1);
          }
          if ((((*(uint *)((int)fVar6 + 0x1f8) & 0x400) == 0) &&
              ((*(byte *)((int)fVar6 + 0xe24) & 2) == 0)) && ((iVar10 != 0 || (local_50 != 0.0)))) {
            local_24[0] = -(local_34 - local_28);
            local_1c = local_3c[0] - local_30[0];
            uVar8 = FUN_005be2d0(local_24[0],local_1c);
            *(uint *)((int)fVar6 + 0xe24) = *(uint *)((int)fVar6 + 0xe24) | 2;
            *(undefined2 *)((int)fVar6 + 0x5a) = uVar8;
            goto LAB_004afb87;
          }
        }
      }
      else if (((((*(byte *)((int)fVar6 + 0x1fc) & 0x80) != 0) &&
                ((DAT_0087af5c == 0 || (*(int *)(PTR_DAT_00802c54 + 300) != DAT_0087af5c)))) &&
               ((*(uint *)(*(int *)(*(int *)((int)fVar6 + 0x54) + 0x24) + 0x90) & 0x10000) == 0)) &&
              (*(int *)(PTR_DAT_00802c54 + 0x128) != DAT_0087b234)) {
        sVar9 = FUN_005be2d0(*(undefined4 *)((int)fVar6 + 0x6b4),*(undefined4 *)((int)fVar6 + 0x6bc)
                            );
        if (((local_54 == 0.0) ||
            (uVar16 = FUN_00550040(sVar9,*(undefined2 *)((int)fVar6 + 0xe0c)),
            0x4000 < (int)((uVar16 ^ (int)uVar16 >> 0x1f) - ((int)uVar16 >> 0x1f)))) &&
           (uVar16 = FUN_00550040(sVar9,*(undefined2 *)((int)fVar6 + 0x27a)),
           0x4000 < (int)((uVar16 ^ (int)uVar16 >> 0x1f) - ((int)uVar16 >> 0x1f)))) {
          if ((int)uVar16 < 0) {
            sVar1 = sVar9 + -0x4000;
          }
          else {
            sVar1 = sVar9 + 0x4000;
          }
          if (((*(float *)((int)fVar6 + 0xddc) <= 0.0) ||
              (iVar10 = FUN_00550040(*(undefined2 *)((int)fVar6 + 0xe0e),sVar9), iVar10 < 0x2aab))
             || (uVar16 = FUN_00550040(*(undefined2 *)((int)fVar6 + 0x27a),sVar9),
                (int)((uVar16 ^ (int)uVar16 >> 0x1f) - ((int)uVar16 >> 0x1f)) < 0x4000)) {
            *(short *)((int)fVar6 + 0x5a) = sVar1;
            *(short *)((int)fVar6 + 0xe0e) = sVar9;
          }
          else {
            iVar10 = FUN_00550040(*(undefined2 *)((int)fVar6 + 0xe0e),sVar9);
            param_1 = (float)(uint)in_FPUControlWord;
            *(uint *)((int)fVar6 + 0xe24) = *(uint *)((int)fVar6 + 0xe24) | 2;
            local_50 = (float)(int)ROUND((double)*(ushort *)((int)fVar6 + 0xe0e) +
                                         (double)iVar10 * 0.5 + 32768.0);
            *(undefined2 *)((int)fVar6 + 0x5a) = local_50._0_2_;
          }
LAB_004afb87:
          *(undefined4 *)((int)fVar6 + 0xddc) = 0x3dcccccd;
        }
      }
      if (((*(uint *)(PTR_PTR_007fb0e4 + *(char *)((int)fVar6 + 0x7b5) * 0x10 + 8) & 1) == 0) ||
         ((*(short *)((int)fVar6 + 0x1064) != DAT_007f19b8 &&
          (*(short *)((int)fVar6 + 0x1064) != DAT_007f19bc)))) {
        uVar8 = FUN_00550070(*(undefined2 *)((int)fVar6 + 0x58),*(undefined2 *)((int)fVar6 + 0x5a),
                             local_44);
        *(undefined2 *)((int)fVar6 + 0x58) = uVar8;
      }
      else {
        uVar8 = *(undefined2 *)((int)fVar6 + 0x58);
        *(undefined2 *)((int)fVar6 + 0x5a) = uVar8;
      }
      *(undefined2 *)((int)fVar6 + 0x27a) = uVar8;
    }
    else {
      *(undefined2 *)((int)fVar6 + 0x5a) = uVar8;
      *(undefined2 *)((int)fVar6 + 0x58) = uVar8;
      *(undefined2 *)((int)fVar6 + 0x27a) = uVar8;
    }
    if ((DAT_0087af5c == 0) ||
       (local_58 = _DAT_007fb0d4, *(int *)(PTR_DAT_00802c54 + 300) != DAT_0087af5c)) {
      local_58 = *(uint *)(*(int *)(*(int *)((int)fVar6 + 0x54) + 0x24) + 0x44);
    }
    iVar10 = *(int *)(*(int *)((int)fVar6 + 0x54) + 0x24);
    if (((*(byte *)(iVar10 + 0x90) & 0x40) != 0) && (*(int *)((int)fVar6 + 0xcd0) == 0)) {
      local_58 = 0x40a00000;
    }
    if ((*(float *)((int)fVar6 + 0x200) == 0.0) && (*(float *)((int)fVar6 + 0x208) == 0.0)) {
      if (fVar6 == DAT_00889614) {
        *(float *)((int)fVar6 + 0xf18) = local_18[0] * 3.0;
        *(float *)((int)fVar6 + 0xf20) = local_10 * 3.0;
        local_58 = 0x40a00000;
      }
      else {
        cVar7 = *(char *)((int)fVar6 + 0x7b5);
        if (cVar7 == ':') {
          fVar19 = (float10)1;
          local_64 = (float)fVar19;
LAB_004afe75:
          *(float *)((int)fVar6 + 0xdc8) = (float)fVar19;
        }
        else if (cVar7 == '6') {
          iVar10 = FUN_006e6b90();
          *(undefined4 *)((int)fVar6 + 0xdc8) = (&DAT_029899a0)[iVar10 >> 1 & 0x7fff];
          local_64 = 1.0;
        }
        else {
          if (cVar7 != '*') {
            local_64 = 1.0;
            if (((*(char *)((int)fVar6 + 0x280) != -1) && (0.0 < _DAT_00950780)) &&
               ((DAT_00855de0 == 0 || ((*(uint *)((int)fVar6 + 0x1fc) & 0x100) == 0)))) {
              fVar19 = (float10)_DAT_0087b8b8;
              goto LAB_004afe75;
            }
            if ((DAT_0087af5c == 0) ||
               (local_50 = _DAT_007fb0d0, *(int *)(PTR_DAT_00802c54 + 300) != DAT_0087af5c)) {
              local_50 = *(float *)(iVar10 + 0x80);
            }
            iVar13 = *(int *)(PTR_DAT_00802c54 + 300);
            if ((iVar13 == DAT_0087b014) && (*(float *)((int)fVar6 + 0xed4) != 1e+09)) {
LAB_004afdfa:
              fVar15 = *(float *)((int)fVar6 + 0xed4);
LAB_004afe02:
              fVar19 = (float10)FUN_004999e0(fVar6,fVar15);
              param_1 = (float)fVar19;
            }
            else {
              uVar16 = *(uint *)((int)fVar6 + 0x1fc) >> 7 & 1;
              if ((uVar16 == 0) ||
                 (((DAT_0087af5c == 0 || (iVar13 != DAT_0087af5c)) ||
                  (*(char *)((int)fVar6 + 0xe3c) == '\0')))) {
                if (((local_54 <= 0.0) || (cVar7 == '#')) || (cVar7 == '$')) {
                  if (*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_0087b234) {
                    if (uVar16 != 0) {
                      if (DAT_009253a4 == 0) {
                        fVar15 = *(float *)(iVar10 + 0x1c) * 0.75;
                        param_1 = fVar15;
                        goto LAB_004afe02;
                      }
                      goto LAB_004b015e;
                    }
                  }
                  else {
LAB_004b015e:
                    if (((uVar16 != 0) && (DAT_0087af5c != 0)) && (iVar13 == DAT_0087af5c)) {
                      param_1 = _DAT_007fb0c4;
                      goto LAB_004afe1c;
                    }
                  }
                  param_1 = 0.0;
                  if (((DAT_0087b8bc == 0) || (*(char *)((int)fVar6 + 0xe3c) != '\0')) &&
                     ((uVar16 != 0 && ((*(uint *)((int)fVar6 + 0xef4) & 0x2000000) == 0)))) {
                    iVar10 = *(int *)(*(int *)((int)fVar6 + 0x54) + 0x24);
                    param_1 = *(float *)(iVar10 + 0x10) / *(float *)(iVar10 + 0x1c);
                  }
                }
                else {
                  if ((*(char *)((int)fVar6 + 0x287) != '\0') &&
                     (fVar15 = (*(float *)((int)fVar6 + 0x220) - *(float *)((int)fVar6 + 0x17c)) /
                               *(float *)((int)fVar6 + 0x1e0), local_64 = 0.0, 0.0 <= fVar15)) {
                    if (fVar15 <= 0.5) {
                      local_64 = 1.0 - (fVar15 + fVar15) * (1.0 - _DAT_007fb080);
                    }
                    else {
                      local_64 = _DAT_007fb080;
                    }
                  }
                  if (*(float *)((int)fVar6 + 0xed4) != 1e+09) goto LAB_004afdfa;
                  fVar15 = local_54;
                  if (((*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_0087b234) && (uVar16 != 0)) &&
                     (DAT_009253a4 == 0)) {
                    iVar10 = *(int *)(*(int *)((int)fVar6 + 0x54) + 0x24);
                    param_1 = *(float *)(iVar10 + 0x1c) * 0.75 +
                              *(float *)(iVar10 + 0x1c) * 0.25 *
                              (*(float *)(local_60 + 0x28) / *(float *)(iVar10 + 0x1c));
                    fVar15 = param_1;
                  }
                  fVar19 = (float10)FUN_004999e0(fVar6,fVar15);
                  param_1 = (float)fVar19;
                  if (*(float *)((int)fVar6 + 0xdc8) < param_1) {
                    if ((DAT_0087af5c == 0) || (*(int *)(PTR_DAT_00802c54 + 300) != DAT_0087af5c)) {
                      local_50 = *(float *)(*(int *)(*(int *)((int)fVar6 + 0x54) + 0x24) + 0x7c);
                    }
                    else {
                      local_50 = _DAT_007fb0cc;
                    }
                  }
                }
              }
              else {
                fVar20 = (float10)FUN_004dbb60(PTR_DAT_00802c54);
                param_1 = _DAT_007fb0c8;
                fVar3 = _DAT_007fb0c4;
                fVar15 = _DAT_007fb0c0;
                fVar19 = (float10)0;
                if (fVar20 <= fVar19) {
                  if (fVar19 == (float10)*(float *)(local_60 + 0x28)) {
LAB_004aff30:
                    *(undefined2 *)((int)fVar6 + 0xe10) = 0;
                    param_1 = fVar3 / param_1;
                    local_64 = 1.0;
                  }
                  else {
                    uVar2 = *(ushort *)(local_60 + 0x26);
                    if ((uVar2 < 0x3555) || (0xcaaa < uVar2)) {
                      *(undefined2 *)((int)fVar6 + 0xe10) = 3;
                      param_1 = param_1 / param_1;
                      local_64 = 1.0;
                    }
                    else {
                      if ((uVar2 < 0x4aab) || (0xb554 < uVar2)) goto LAB_004aff30;
                      *(undefined2 *)((int)fVar6 + 0xe10) = 4;
                      param_1 = fVar15 / param_1;
                      local_64 = 1.0;
                    }
                  }
                }
                else {
                  *(undefined2 *)((int)fVar6 + 0xe10) = 1;
                  param_1 = (float)fVar19 / param_1;
                  local_64 = 1.0;
                }
              }
            }
LAB_004afe1c:
            local_50 = (1.0 / local_50) * _DAT_00925018;
            if ((DAT_0087af5c != 0) && (*(int *)(PTR_DAT_00802c54 + 300) == DAT_0087af5c)) {
              param_1 = *(float *)((int)fVar6 + 0xc44) * param_1;
            }
            fVar19 = (float10)FUN_0054fad0(*(undefined4 *)((int)fVar6 + 0xdc8),param_1,local_50);
            goto LAB_004afe75;
          }
          fVar15 = *(float *)((int)fVar6 + 0x784) * 0.5;
          if (fVar15 < *(float *)((int)fVar6 + 0x77c) == (fVar15 == *(float *)((int)fVar6 + 0x77c)))
          {
            fVar15 = -(1.0 - *(float *)((int)fVar6 + 0x77c) / fVar15);
          }
          else {
            fVar15 = 1.0 - (*(float *)((int)fVar6 + 0x784) - *(float *)((int)fVar6 + 0x77c)) /
                           fVar15;
          }
          *(float *)((int)fVar6 + 0xdc8) = fVar15;
          local_64 = 1.0;
        }
        if ((DAT_0087af5c == 0) || (*(int *)(PTR_DAT_00802c54 + 300) != DAT_0087af5c)) {
          param_1 = *(float *)(*(int *)(*(int *)((int)fVar6 + 0x54) + 0x24) + 0x1c) *
                    *(float *)((int)fVar6 + 0xdc8);
        }
        else {
          param_1 = *(float *)((int)fVar6 + 0xdc8) * _DAT_007fb0c8;
        }
        if ((*(byte *)((int)fVar6 + 0x1fc) & 0x80) == 0) {
LAB_004b0254:
          if (*(short *)((int)fVar6 + 0x1064) == DAT_007f1948) {
            if ((*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_0087b234) && (DAT_009253a4 != 0)) {
              fVar19 = (float10)param_1 * (float10)0.3330000042915344;
              goto LAB_004b0298;
            }
          }
          else if (local_48 != 0) {
            fVar19 = (float10)param_1 * (float10)0.25;
            goto LAB_004b0298;
          }
        }
        else {
          if ((*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_0087b1d4) &&
             (iVar10 = FUN_0054a240(fVar6,*(undefined4 *)(PTR_DAT_00802c54 + 0x2988),
                                    *(undefined4 *)(PTR_DAT_00802c54 + 0x11c)), iVar10 != 0)) {
            fVar19 = (float10)param_1 + (float10)param_1;
          }
          else {
            if (((*(byte *)((int)fVar6 + 0x1fc) & 0x80) == 0) ||
               (((iVar10 = *(int *)(PTR_DAT_00802c54 + 0x128), iVar10 != DAT_0087b258 &&
                 (iVar10 != DAT_0087b25c)) && (iVar10 != DAT_0087b260)))) goto LAB_004b0254;
            fVar19 = (float10)FUN_004ea8e0(fVar6);
            fVar19 = fVar19 * (float10)1.5 * (float10)param_1;
          }
LAB_004b0298:
          param_1 = (float)fVar19;
        }
        if (((*(char *)((int)fVar6 + 0xe3c) != '\0') && (iVar10 = FUN_0041a4d0(fVar6), iVar10 != 0))
           && (*(char *)(iVar10 + 0xe3c) != '\0')) {
          iVar13 = FUN_0040e690(fVar6);
          iVar14 = FUN_0040e690(iVar10);
          if (iVar13 == iVar14) {
            FUN_005b3620(local_24,&DAT_0080250c,*(undefined2 *)((int)fVar6 + 0x696));
            FUN_005b3800(local_c,iVar10 + 0x5c,(int)fVar6 + 0x5c);
            fVar15 = local_24[0] * local_c[0] + local_1c * local_4;
            fVar3 = *(float *)(iVar10 + 0x1dc) + *(float *)((int)fVar6 + 0x1dc);
            local_44 = ABS(fVar15);
            local_50 = fVar3 + fVar3;
            if (local_50 < local_44) {
              fVar3 = fVar3 * 5.0 + 0.1;
              if (local_44 <= fVar3) {
                local_50 = (local_44 - local_50) / (fVar3 - local_50);
              }
              else {
                local_50 = 1.0;
              }
              if (iVar13 == 0) {
                if (0.0 <= fVar15) goto LAB_004b03a6;
LAB_004b03ba:
                bVar4 = true;
              }
              else {
                if (0.0 < fVar15) goto LAB_004b03ba;
LAB_004b03a6:
                bVar4 = false;
              }
              if (*(char *)(iVar10 + 0x28b) == '\0') {
                local_44 = 0.75;
              }
              else {
                local_44 = 1.0;
              }
              if (!bVar4) {
                param_1 = (1.0 - local_44 * local_50) * param_1;
              }
            }
          }
        }
        *(float *)((int)fVar6 + 0xf20) = local_64 * param_1;
        puVar5 = PTR_DAT_00802c54;
        if (*(char *)((int)fVar6 + 0x7b5) == ':') {
          pfVar17 = (float *)((int)fVar6 + 0xf18);
          if (*(char *)((int)fVar6 + 0x7b3) == '\0') {
            fVar15 = 0.4;
          }
          else {
            fVar15 = -0.4;
          }
          *pfVar17 = fVar15;
          if ((DAT_0087af5c == 0) || (*(int *)(PTR_DAT_00802c54 + 300) != DAT_0087af5c)) {
            fVar15 = *(float *)(*(int *)(*(int *)((int)fVar6 + 0x54) + 0x24) + 0x1c) * *pfVar17;
          }
          else {
            param_1 = *pfVar17 * 0.4;
            fVar15 = param_1 * _DAT_007fb0c8;
          }
        }
        else {
          if (((((*(byte *)((int)fVar6 + 0x1fc) & 0x80) != 0) && (DAT_0087af5c != 0)) &&
              (*(int *)(PTR_DAT_00802c54 + 300) == DAT_0087af5c)) &&
             (*(char *)((int)fVar6 + 0xe3c) != '\0')) {
            local_40 = FUN_006e6b90();
            fVar20 = (float10)FUN_004dbb60(puVar5);
            fVar19 = (float10)0;
            pfVar17 = (float *)((int)fVar6 + 0xf18);
            if (fVar20 <= fVar19) {
              fVar19 = (float10)*(float *)(local_60 + 0x2c) * (float10)_DAT_007fb0c8 * (float10)0.25
              ;
            }
            *pfVar17 = (float)fVar19;
            FUN_005b3620(pfVar17,pfVar17,*(undefined2 *)((int)fVar6 + 0x696));
            goto LAB_004b053a;
          }
          fVar15 = 0.0;
        }
        pfVar17 = (float *)((int)fVar6 + 0xf18);
        *pfVar17 = fVar15;
        FUN_005b3620(pfVar17,pfVar17,*(undefined2 *)((int)fVar6 + 0x58));
      }
    }
    else {
      *(uint *)((int)fVar6 + 0xe20) = *(uint *)((int)fVar6 + 0xe20) | 0x10000000;
      *(undefined4 *)((int)fVar6 + 0xf18) = *(undefined4 *)((int)fVar6 + 0x200);
      *(undefined4 *)((int)fVar6 + 0xf20) = *(undefined4 *)((int)fVar6 + 0x208);
      *(undefined4 *)((int)fVar6 + 0x208) = 0;
      *(undefined4 *)((int)fVar6 + 0x200) = 0;
    }
LAB_004b053a:
    puVar18 = (undefined4 *)((int)fVar6 + 0xf18);
    if ((*(byte *)((int)fVar6 + 0x1fc) & 0x80) != 0) {
      FUN_005a83c0(fVar6,puVar18);
    }
    if (((*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_0087b234) &&
        (*(short *)((int)fVar6 + 0x1064) == DAT_007f1948)) &&
       ((DAT_00855de0 != 0 ||
        ((((DAT_009253a4 == 0 && ((*(byte *)((int)fVar6 + 0x1fc) & 0x80) != 0)) &&
          (iVar10 = FUN_0041a4d0(fVar6), iVar10 != 0)) && (*(char *)(iVar10 + 0x28b) != '\0')))))) {
      *puVar18 = 0;
      *(undefined4 *)((int)fVar6 + 0xf20) = 0;
    }
    fVar19 = (float10)FUN_0054fb40(*(undefined4 *)((int)fVar6 + 0x68),*puVar18,local_58);
    *(float *)((int)fVar6 + 0x68) = (float)fVar19;
    fVar19 = (float10)FUN_0054fb40(*(undefined4 *)((int)fVar6 + 0x70),
                                   *(undefined4 *)((int)fVar6 + 0xf20),local_58);
    *(float *)((int)fVar6 + 0x70) = (float)fVar19;
    fVar15 = _DAT_007fb0bc;
    if (local_48 == 0) {
      iVar10 = *(int *)(*(int *)((int)fVar6 + 0x54) + 0x24);
      uVar16 = *(uint *)(iVar10 + 0x94) >> 5 & 1;
      if ((uVar16 != 0) && ((*(uint *)(local_60 + 4) & DAT_00802278) != 0)) {
        param_1 = *(float *)(iVar10 + 0x1c);
LAB_004b06a4:
        param_1 = param_1 * 0.7;
        *(float *)((int)fVar6 + 0xf1c) = param_1;
        uVar11 = 0x40400000;
        fVar15 = param_1;
        goto LAB_004b06b0;
      }
      if (*(char *)((int)fVar6 + 0x7b5) == 'K') {
        param_1 = (*(float *)((int)fVar6 + 0x220) -
                  ((*(float *)((int)fVar6 + 0x188) - *(float *)((int)fVar6 + 0x17c)) * _DAT_007fb07c
                  + *(float *)((int)fVar6 + 0x17c))) * 3.0;
        *(float *)((int)fVar6 + 0xf1c) = param_1;
        uVar11 = 0x41200000;
        fVar15 = param_1;
        goto LAB_004b06b0;
      }
      if ((uVar16 != 0) && ((*(uint *)(local_60 + 4) & DAT_00802278) == 0)) {
        param_1 = -*(float *)(iVar10 + 0x1c);
        goto LAB_004b06a4;
      }
    }
    else {
      *(float *)((int)fVar6 + 0xf1c) = _DAT_007fb0bc;
      uVar11 = 0x41200000;
LAB_004b06b0:
      fVar19 = (float10)FUN_0054fb40(*(undefined4 *)((int)fVar6 + 0x6c),fVar15,uVar11);
      *(float *)((int)fVar6 + 0x6c) = (float)fVar19;
    }
    if (local_40 == 0) {
      if ((*(byte *)(*(int *)(*(int *)((int)fVar6 + 0x54) + 0x24) + 0x90) & 1) == 0) {
        uVar8 = *(undefined2 *)((int)fVar6 + 0xe18);
        fVar15 = 10.0;
        iVar10 = 0;
      }
      else {
        cVar7 = *(char *)((int)fVar6 + 0x7b5);
        local_50 = 8.0;
        if (((cVar7 == '*') || (cVar7 == '6')) || (cVar7 == ':')) {
          param_1 = 0.0;
        }
        else {
          param_1 = (float)FUN_00550040(*(undefined2 *)((int)fVar6 + 0x1060),
                                        *(undefined2 *)((int)fVar6 + 0x27a));
          param_1 = (float)FUN_006e6b90();
        }
        if ((*(uint *)(*(int *)(*(int *)((int)fVar6 + 0x54) + 0x24) + 0x90) & 0x10000) == 0) {
          fVar15 = param_1;
          if (local_5c != 0.0) {
            fVar15 = (float)FUN_006e6b90();
          }
        }
        else {
          local_50 = 4.0;
          fVar15 = (float)((int)((int)param_1 + ((int)param_1 >> 0x1f & 3U)) >> 2);
        }
        if ((int)fVar15 < -0x10000) {
          fVar15 = -NAN;
        }
        else if (0x10000 < (int)fVar15) {
          fVar15 = 9.18355e-41;
        }
        iVar10 = (int)((int)fVar15 + ((int)fVar15 >> 0x1f & 3U)) >> 2;
        if (iVar10 < -0x2000) {
          iVar10 = -0x2000;
        }
        else if (0x2000 < iVar10) {
          iVar10 = 0x2000;
        }
        uVar8 = *(undefined2 *)((int)fVar6 + 0xe18);
        fVar15 = local_50;
      }
    }
    else {
      uVar8 = *(undefined2 *)((int)fVar6 + 0xe18);
      iVar10 = local_40;
      fVar15 = 3.0;
    }
    uVar8 = FUN_00550070(uVar8,iVar10,fVar15);
    *(undefined2 *)((int)fVar6 + 0xe18) = uVar8;
    if (*(short *)((int)fVar6 + 0x1064) != DAT_007f1a64) goto LAB_004b0864;
    uVar11 = 0;
    if (*(char *)((int)fVar6 + 0x7b5) != '\x17') {
      uVar11 = FUN_006e6b90();
    }
    uVar8 = FUN_00550070(*(undefined2 *)((int)fVar6 + 0xe1a),uVar11,0x40a00000);
  }
  else {
    FUN_00499170(fVar6,0,&param_1);
    if (param_1 == 0.0) goto LAB_004b0864;
    uVar8 = *(undefined2 *)((int)param_1 + 0x27a);
    *(undefined2 *)((int)fVar6 + 0x27a) = uVar8;
    *(undefined2 *)((int)fVar6 + 0x5a) = uVar8;
    *(undefined2 *)((int)fVar6 + 0x58) = uVar8;
    *(undefined4 *)((int)fVar6 + 0x68) = *(undefined4 *)((int)param_1 + 0x68);
    *(undefined4 *)((int)fVar6 + 0x6c) = *(undefined4 *)((int)param_1 + 0x6c);
    *(undefined4 *)((int)fVar6 + 0x70) = *(undefined4 *)((int)param_1 + 0x70);
    uVar8 = 0;
    uVar11 = *(undefined4 *)((int)param_1 + 0xdc8);
    *(undefined2 *)((int)fVar6 + 0xe18) = 0;
    *(undefined4 *)((int)fVar6 + 0xdc8) = uVar11;
    *(undefined2 *)((int)fVar6 + 0xe1c) = 0;
  }
  *(undefined2 *)((int)fVar6 + 0xe1a) = uVar8;
LAB_004b0864:
  FUN_0056a5b0(PTR_DAT_00802c54,fVar6);
  if (((DAT_00951288 != 0) ||
      ((*(int *)(PTR_DAT_00802c54 + 300) == DAT_0087afd4 &&
       (*(short *)((int)fVar6 + 0x1064) == DAT_007f1948)))) &&
     ((*(int *)(PTR_DAT_00802c54 + 300) == 0 || (*(int *)(PTR_DAT_00802c54 + 300) != DAT_0087af5c)))
     ) {
    FUN_00499610(fVar6);
  }
  return;
}

