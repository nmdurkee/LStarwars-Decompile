/* Ghidra pseudocode, not original source.
 * ev_6ff60c7644817ef8ef03e73cfdcec4dc91928e5367edba007261837c31d60754
 * Entry: 0x4b1ab0; label: FUN_004b1ab0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004b1ab0(void)

{
  float fVar1;
  char cVar2;
  char cVar3;
  short sVar4;
  bool bVar5;
  bool bVar6;
  int iVar7;
  uint uVar8;
  undefined4 uVar9;
  int iVar10;
  int iVar11;
  float *pfVar12;
  int iVar13;
  float *pfVar14;
  undefined4 *puVar15;
  undefined4 **ppuVar16;
  int *piVar17;
  undefined4 *puVar18;
  float10 fVar19;
  float *local_188;
  int iStack_184;
  int iStack_17c;
  float local_170;
  float local_16c;
  float local_168;
  float local_164;
  float local_160;
  float local_15c;
  undefined4 local_158;
  float local_154;
  float local_150;
  int local_14c;
  float fStack_148;
  float fStack_144;
  float fStack_140;
  float fStack_13c;
  float fStack_138;
  float fStack_134;
  int iStack_130;
  int iStack_12c;
  undefined4 local_128 [12];
  undefined4 local_f8;
  undefined4 local_f4;
  undefined4 local_f0;
  undefined4 *local_e8 [3];
  int local_dc;
  undefined4 uStack_d8;
  undefined4 local_d4;
  undefined4 local_d0;
  undefined4 local_cc;
  int local_c4;
  undefined4 local_c0;
  undefined4 local_bc;
  code *local_b4;
  code *local_b0;
  code *local_ac;
  code *local_a8;
  code *local_a4;
  code *local_a0;
  code *local_9c;
  code *local_94;
  undefined4 local_5c;
  uint local_58;
  float local_44;
  undefined1 local_20 [12];
  undefined1 auStack_14 [16];
  
  local_14c = 0;
  iVar13 = DAT_0093d504;
  if (0 < DAT_0093d500) {
    do {
      if (((((*(uint *)(iVar13 + 0x1fc) & 1) != 0) && ((*(uint *)(iVar13 + 0x1fc) & 0x1000) != 0))
          && (*(char *)(iVar13 + 0x28b) == '\0')) && (*(char *)(iVar13 + 0x28c) != '\0')) {
        if (*(char *)(iVar13 + 0x288) == '\0') {
          bVar5 = false;
          bVar6 = false;
          if ((*(byte *)(iVar13 + 0x1044) & 4) != 0) goto LAB_004b1b35;
        }
        else {
          bVar5 = true;
          bVar6 = true;
LAB_004b1b35:
          if ((*(int *)(iVar13 + 0xea0) != 0) &&
             ((*(byte *)(*(int *)(iVar13 + 0xea0) + 0x1fc) & 1) == 0)) {
            *(undefined4 *)(iVar13 + 0xea0) = 0;
          }
          if (*(char *)(iVar13 + 0xe3f) != -1) {
            if (*(short *)(iVar13 + 0x1064) == DAT_007f1930) {
              FUN_005478a0((int)*(short *)(*(int *)(*(int *)(iVar13 + 0x54) + 0x24) + 0xe4),
                           (undefined4 *)(iVar13 + 0x80),0,0);
              if (((bVar5) &&
                  (iVar7 = (int)*(char *)(*(int *)(*(int *)(iVar13 + 0x54) + 0x24) + 0xfc),
                  iVar7 != -1)) && (*(int *)(*(int *)(iVar13 + 0x50) + 0x14 + iVar7 * 4) != 0)) {
                puVar15 = (undefined4 *)(iVar7 * 0x40 + 0x804 + iVar13);
                puVar18 = local_128;
                for (iVar11 = 0x10; iVar11 != 0; iVar11 = iVar11 + -1) {
                  *puVar18 = *puVar15;
                  puVar15 = puVar15 + 1;
                  puVar18 = puVar18 + 1;
                }
              }
              else {
                puVar15 = (undefined4 *)(iVar13 + 0xb8);
                puVar18 = local_128;
                for (iVar7 = 0x10; iVar7 != 0; iVar7 = iVar7 + -1) {
                  *puVar18 = *puVar15;
                  puVar15 = puVar15 + 1;
                  puVar18 = puVar18 + 1;
                }
                local_f8 = *(undefined4 *)(iVar13 + 0x80);
                local_f4 = *(undefined4 *)(iVar13 + 0x84);
                local_f0 = *(undefined4 *)(iVar13 + 0x88);
              }
              local_158 = 0;
              iVar7 = FUN_0054fa60();
              local_154 = (float)iVar7 * 1.5259022e-05 + (float)iVar7 * 1.5259022e-05;
              iVar7 = FUN_0054fa60();
              local_150 = -((float)iVar7 * 1.5259022e-05 + (float)iVar7 * 1.5259022e-05 + 3.0);
              FUN_005b3200(&local_158,&local_158,local_128);
              puVar15 = &DAT_00810210;
              ppuVar16 = local_e8;
              for (iVar7 = 0x32; iVar7 != 0; iVar7 = iVar7 + -1) {
                *ppuVar16 = (undefined4 *)*puVar15;
                puVar15 = puVar15 + 1;
                ppuVar16 = ppuVar16 + 1;
              }
              local_cc = 0xc1200000;
              local_d0 = 0x3d4ccccd;
              local_d4 = 0x3d4ccccd;
              local_e8[0] = local_128;
              local_e8[2] = &local_158;
              local_c0 = 0x5a;
              local_c4 = *(int *)(PTR_DAT_00802c54 + 0x2ac0) + 0x5a0;
              local_5c = _DAT_00925018;
              local_bc = 0x10;
              local_a0 = FUN_004a5b30;
              local_ac = FUN_004a5bb0;
              local_9c = FUN_00571c50;
              local_94 = FUN_00571c80;
              FUN_0064d270(local_e8);
              bVar5 = bVar6;
            }
            else {
              FUN_00583af0(iVar13,(int)*(char *)(iVar13 + 0xe3f),*(undefined1 *)(iVar13 + 0xe30));
              if (*(char *)(iVar13 + 0xe3f) == '\x1d') {
                *(uint *)(iVar13 + 0x7bc) = *(uint *)(iVar13 + 0x7bc) | 0x40;
              }
            }
          }
          if ((*(uint *)(iVar13 + 0xe20) & 0x4000000) != 0) {
            FUN_004d3690(iVar13);
          }
          if ((bVar5) &&
             ((((*(byte *)(*(int *)(iVar13 + 0x54) + 4) & 8) != 0 ||
               (*(short *)(iVar13 + 0x1064) == DAT_007f187c)) ||
              (*(short *)(iVar13 + 0x1064) == DAT_007f1878)))) {
            if (*(char *)(iVar13 + 0xe43) == -1) {
              iVar7 = -1;
            }
            else {
              iVar7 = (int)*(short *)(&DAT_007fb0ec + *(char *)(iVar13 + 0xe43) * 0x10);
            }
            FUN_004a0900(iVar7);
          }
        }
        if (*(char *)(iVar13 + 0xe3e) != -1) {
          FUN_0062c560(*(undefined4 *)(PTR_DAT_00802c54 + 0x134),
                       (*(uint *)(iVar13 + 0xe24) & 0x100 | 0x8a00) >> 8,
                       *(char *)(iVar13 + 0xe3e) * 0x40 + 0x834 + iVar13);
        }
        if (((*(char *)(iVar13 + 0x7b5) == '&') &&
            (iVar7 = *(int *)(*(int *)(iVar13 + 0x50) + 8),
            *(int *)(iVar7 + *(short *)(iVar13 + 0x7aa) * 4) != 0)) &&
           ((iVar7 = (int)*(char *)(*(int *)(iVar7 + *(short *)(iVar13 + 0x7aa) * 4) + 0x4a),
            iVar7 != -1 &&
            (((*(byte *)(iVar13 + 0x7bc) & 0x40) == 0 || (*(char *)(iVar13 + 0xe3e) != -1)))))) {
          iVar7 = iVar7 * 0x40;
          local_170 = *(float *)(iVar7 + 0x834 + iVar13);
          iVar7 = iVar7 + 0x834 + iVar13;
          local_160 = *(float *)(iVar7 + 4);
          local_168 = *(float *)(iVar7 + 8);
          local_16c = local_160 + 0.075;
          local_160 = local_160 - 0.075;
          local_164 = local_170;
          local_15c = local_168;
          FUN_005a3730(&local_170,0x3e800000,0xffffffff,iVar13 + 0xcd8,0,iVar13);
        }
        if (*(char *)(iVar13 + 0xe40) != -1) {
          FUN_0042f9d0(iVar13);
        }
        if (*(char *)(iVar13 + 0xe3d) != '\0') {
          FUN_00404620(iVar13,*(char *)(iVar13 + 0xe3d));
        }
        if ((*(uint *)(iVar13 + 0xe20) & 0x800000) != 0) {
          FUN_005980c0(iVar13,0);
        }
        if ((*(byte *)(iVar13 + 0xe20) & 0x10) != 0) {
          if (((bVar6) &&
              (iVar7 = (int)*(char *)(*(int *)(*(int *)(iVar13 + 0x54) + 0x24) + 0x10c), iVar7 != -1
              )) && (*(int *)(*(int *)(iVar13 + 0x50) + 0x14 + iVar7 * 4) != 0)) {
            puVar15 = (undefined4 *)(iVar7 * 0x40 + 0x804 + iVar13);
            puVar18 = local_128;
            for (iVar11 = 0x10; iVar11 != 0; iVar11 = iVar11 + -1) {
              *puVar18 = *puVar15;
              puVar15 = puVar15 + 1;
              puVar18 = puVar18 + 1;
            }
          }
          else {
            FUN_005b45f0(local_128,0x1555);
            FUN_005b4f70(local_128,*(ushort *)(iVar13 + 0x27a) + 0x8000);
            local_f8 = *(undefined4 *)(iVar13 + 0x80);
            local_f4 = *(undefined4 *)(iVar13 + 0x84);
            local_f0 = *(undefined4 *)(iVar13 + 0x88);
          }
          local_158 = 0;
          local_154 = 0.0;
          local_150 = -1.0;
          FUN_005b3200(&local_158,&local_158,local_128);
          puVar15 = &DAT_00810210;
          ppuVar16 = local_e8;
          for (iVar7 = 0x32; iVar7 != 0; iVar7 = iVar7 + -1) {
            *ppuVar16 = (undefined4 *)*puVar15;
            puVar15 = puVar15 + 1;
            ppuVar16 = ppuVar16 + 1;
          }
          local_d4 = 0x3dcccccd;
          local_d0 = 0x3dcccccd;
          local_e8[0] = local_128;
          local_e8[2] = &local_158;
          local_c0 = 0xe8;
          local_c4 = *(int *)(PTR_DAT_00802c54 + 0x2ac0) + 0xe80;
          local_bc = 0xc11b;
          if ((*(byte *)(iVar13 + 0x1fc) & 0x80) == 0) {
            local_bc = 0xc31b;
          }
          local_58 = (uint)*(byte *)(iVar13 + 0x28d);
          local_5c = _DAT_00925018;
          local_cc = 0;
          local_a4 = FUN_004a5a90;
          local_b4 = FUN_004a56a0;
          local_b0 = FUN_004a5b00;
          local_a8 = FUN_0042cf20;
          local_dc = iVar13;
          if ((*(byte *)(iVar13 + 0x1fc) & 0x80) == 0) {
            local_44 = 10.0;
          }
          else {
            iVar7 = FUN_0054fa60();
            local_44 = (float)iVar7 * 1.5259022e-05 + (float)iVar7 * 1.5259022e-05 + 4.0;
          }
          (**(code **)(PTR_PTR_008040bc + 0x14))(iVar13,local_20);
          fVar1 = local_44 * _DAT_007fc078;
          uStack_d8 = FUN_00433df0(iVar13,iVar13 + 0x80,local_20,fVar1,fVar1 * fVar1,0,1,0,
                                   0xffffffff);
          iVar7 = FUN_0064d270(local_e8);
          if (iVar7 != 0) {
            uVar8 = FUN_0058b720(iVar13);
            *(uint *)(iVar7 + 0x218) = uVar8 & 0xffff;
          }
        }
        if ((*(uint *)(iVar13 + 0xe24) & 0x4000) != 0) {
          FUN_004cfbb0(iVar13);
        }
        if (((*(uint *)(iVar13 + 0xe20) & 0x2000000) != 0) &&
           (iVar7 = *(int *)(iVar13 + 0x790), iVar7 != 0)) {
          uVar9 = FUN_004a6050(iVar13);
          fVar19 = (float10)FUN_005becc0(iVar7 + 0x80,uVar9,&fStack_13c);
          FUN_006018c0(DAT_0087b8c4,_DAT_007fb0a8,_DAT_007fb0ac,_DAT_007fb0b0,uVar9,&fStack_13c,
                       (-(uint)(*(short *)(iVar13 + 0x1064) != DAT_007f1a18) & 0x605fc0) - 0xdfdf80,
                       _DAT_007fb0b4,(float)fVar19);
        }
        if (((bVar6) && ((*(byte *)(*(int *)(iVar13 + 0x54) + 4) & 8) != 0)) &&
           (*(float *)(iVar13 + 0xd3c) == 1.0)) {
          local_188 = &local_170;
          iStack_17c = 0;
          do {
            iVar7 = FUN_0049f780(iVar13);
            if (iVar7 != 0) {
              local_170 = *(float *)(iStack_130 * 0x40 + 0x834 + iVar13);
              iVar7 = iStack_130 * 0x40 + 0x834 + iVar13;
              local_16c = *(float *)(iVar7 + 4);
              local_168 = *(float *)(iVar7 + 8);
              local_164 = *(float *)(iStack_12c * 0x40 + 0x834 + iVar13);
              iVar7 = iStack_12c * 0x40 + 0x834 + iVar13;
              local_160 = *(float *)(iVar7 + 4);
              local_15c = *(float *)(iVar7 + 8);
              cVar2 = *(char *)(iStack_17c + 0xe44 + iVar13);
              if ((((cVar2 != -1) && (*(char *)(iVar13 + 0x7b5) == '\x05')) &&
                  ((*(byte *)(iVar13 + 0x7bc) & 0x1c) == 0)) &&
                 ((cVar3 = *(char *)(iVar13 + 0x7ae), cVar3 == '\x02' || (cVar3 == '\x06')))) {
                if (cVar3 == '\x06') {
                  sVar4 = *(short *)(&DAT_007fb0ec + cVar2 * 0x10);
                }
                else {
                  sVar4 = *(short *)(&DAT_007fb0ee + cVar2 * 0x10);
                }
                iVar7 = *(int *)(*(int *)(*(int *)(PTR_DAT_00802c54 + 0x134) + 8) + sVar4 * 0x14);
                if ((iVar7 != -1) && (iVar11 = FUN_0062c350(0x42c80000,_DAT_00925018), 0 < iVar11))
                {
                  iVar10 = FUN_0054fa60();
                  fVar1 = (float)iVar10 * 1.5259022e-05;
                  fStack_148 = fVar1 * (local_164 - local_170) + local_170;
                  fStack_144 = local_16c + fVar1 * (local_160 - local_16c);
                  fStack_140 = local_168 + (local_15c - local_168) * fVar1;
                  FUN_00684c90(iVar7,&fStack_148,iVar11,0,0);
                }
              }
              if ((*(byte *)(iVar13 + 0x1fc) & 0x80) != 0) {
                bVar5 = false;
                pfVar14 = &local_170;
                pfVar12 = &local_164;
                iStack_184 = 2;
                do {
                  FUN_005b3800(auStack_14,pfVar12,pfVar14);
                  iVar7 = FUN_0067b430(pfVar14,auStack_14,0,0x3f800000,0,DAT_008034c4 | 0x1f);
                  if (iVar7 != 0) {
                    fVar19 = (float10)FUN_0067b200();
                    fVar1 = (float)fVar19;
                    fStack_148 = *pfVar14 + fVar1 * (*pfVar12 - *pfVar14);
                    fStack_144 = (pfVar12[1] - pfVar14[1]) * fVar1 + pfVar14[1];
                    fStack_140 = (pfVar12[2] - pfVar14[2]) * fVar1 + pfVar14[2];
                    if (((*(short *)(iVar13 + 0x1064) == DAT_007f1968) &&
                        ((iStack_17c == 1 || (iStack_17c == 2)))) &&
                       ((*(char *)(iVar13 + 0x280) == -1 ||
                        ((iVar7 = FUN_0056e160(0x19), iVar7 == 0 &&
                         ((*(char *)(iVar13 + 0x280) == -1 ||
                          (iVar7 = FUN_0041af30(iVar13), iVar7 == 0)))))))) {
                      iVar7 = 0x41;
LAB_004b24b0:
                      iVar7 = *(int *)(*(int *)(*(int *)(PTR_DAT_00802c54 + 0x134) + 8) +
                                      iVar7 * 0x14);
                      if ((iVar7 != -1) &&
                         (iVar11 = FUN_0062c350(0x42480000,_DAT_00925018), 0 < iVar11)) {
                        FUN_00684c90(iVar7,&fStack_148,iVar11,0,0);
                      }
                    }
                    else if ((*(char *)(iVar13 + 0xe43) != -1) &&
                            (iVar7 = (int)*(short *)(&DAT_007fb0f0 +
                                                    *(char *)(iVar13 + 0xe43) * 0x10), iVar7 != -1))
                    goto LAB_004b24b0;
                    bVar5 = true;
                  }
                  pfVar12 = pfVar12 + -3;
                  pfVar14 = pfVar14 + 3;
                  iStack_184 = iStack_184 + -1;
                } while (iStack_184 != 0);
                if (((((bVar5) && (_DAT_0087b8c0 <= 0.0)) && (*(char *)(iVar13 + 0x39) == '\0')) &&
                    (((cVar2 = *(char *)(iVar13 + 0x7b5), cVar2 != '\x05' && (cVar2 != '\x10')) &&
                     ((cVar2 != '\r' &&
                      ((cVar2 != '\x0e' &&
                       ((*(uint *)(PTR_PTR_007fb0e4 + cVar2 * 0x10 + 8) & 0x4000000) == 0)))))))) &&
                   (((*(uint *)(PTR_PTR_007fb0e4 + cVar2 * 0x10 + 8) & 0x8000000) == 0 ||
                    ((*(uint *)(iVar13 + 0x7bc) & 0x20000) == 0)))) {
                  FUN_00548540("SaberSparks",iVar13,local_188,1);
                  iVar7 = FUN_0054fa60();
                  _DAT_0087b8c0 = (float)iVar7 * 1.5259022e-05 * 0.3 + 0.3;
                  iVar7 = FUN_00574e20();
                  if (iVar7 == -1) {
                    iVar7 = FUN_0054fa60(0);
                    FUN_0054a850(**(undefined4 **)(iVar13 + 0xca4),
                                 (float)iVar7 * 1.5259022e-05 * 0.2 + 0.2);
                  }
                }
              }
            }
            local_188 = local_188 + 3;
            iStack_17c = iStack_17c + 1;
          } while (iStack_17c < 4);
        }
        if ((*(short *)(iVar13 + 0x1064) == DAT_007f1940) && (bVar6)) {
          iVar7 = *(int *)(*(int *)(*(int *)(PTR_DAT_00802c54 + 0x134) + 8) + 0x834);
          if (iVar7 != -1) {
            FUN_00684be0(iVar7,iVar13 + 0x19c,0x3c,_DAT_00925018,0,0,0);
          }
          iVar7 = *(int *)(*(int *)(*(int *)(PTR_DAT_00802c54 + 0x134) + 8) + 0x820);
          if (iVar7 != -1) {
            piVar17 = &DAT_007fc258;
            do {
              iVar11 = *piVar17;
              if ((*(int *)(*(int *)(iVar13 + 0x50) + 0x14 + iVar11 * 4) != 0) &&
                 (iVar10 = FUN_006e6b90(), 0 < iVar10)) {
                FUN_00684be0(iVar7,iVar11 * 0x40 + 0x834 + iVar13,iVar10,_DAT_00925018,0,0,0);
              }
              piVar17 = piVar17 + 1;
            } while ((int)piVar17 < 0x7fc264);
          }
          iVar7 = *(int *)(*(int *)(*(int *)(PTR_DAT_00802c54 + 0x134) + 8) + 0x80c);
          if ((iVar7 != -1) && (*(float *)(iVar13 + 0x21c) != 2e+06)) {
            piVar17 = &DAT_007fc258;
            do {
              if (*(int *)(*(int *)(iVar13 + 0x50) + 0x14 + *piVar17 * 4) != 0) {
                iVar10 = *piVar17 * 0x40;
                iVar11 = iVar10 + iVar13;
                fVar1 = *(float *)(iVar10 + 0x838 + iVar13) - *(float *)(iVar13 + 0x21c);
                if (((0.0 < fVar1) && (fVar1 < 0.2 != (fVar1 == 0.2))) &&
                   (iVar10 = FUN_006e6b90(), 0 < iVar10)) {
                  local_170 = *(float *)(iVar11 + 0x834);
                  local_16c = *(float *)(iVar13 + 0x21c);
                  local_168 = *(float *)(iVar11 + 0x83c);
                  FUN_00684be0(iVar7,&local_170,0x3c,_DAT_00925018,0,0,0);
                }
              }
              piVar17 = piVar17 + 1;
            } while ((int)piVar17 < 0x7fc264);
          }
        }
        if ((DAT_00951288 != 0) &&
           ((cVar2 = *(char *)(iVar13 + 0x280), cVar2 == '\0' || (cVar2 == '\x01')))) {
          iVar7 = (int)cVar2;
          if ((*(short *)(iVar13 + 0x1064) == DAT_007f19a4) &&
             ((((*(byte *)(iVar13 + 0x1fc) & 0x80) != 0 && ((*(byte *)(iVar13 + 0xe24) & 8) != 0))
              && ((*(int *)(*(int *)(iVar13 + 0x50) + 0x1c) != 0 &&
                  (*(float *)(iVar13 + 0xa8) == 1.0)))))) {
            if (*(int *)(&DAT_007f5dc4 + iVar7 * 4) == -1) {
              FUN_00684ee0(&DAT_007f5dc4 + iVar7 * 4,
                           *(undefined4 *)(*(int *)(*(int *)(PTR_DAT_00802c54 + 0x134) + 8) + 0xaa0)
                           ,0,0,0);
            }
            else {
              puVar15 = (undefined4 *)(iVar13 + 0x884);
              puVar18 = local_128;
              for (iVar11 = 0x10; iVar11 != 0; iVar11 = iVar11 + -1) {
                *puVar18 = *puVar15;
                puVar15 = puVar15 + 1;
                puVar18 = puVar18 + 1;
              }
              FUN_005b4dd0(local_128,0x4000);
              FUN_00655a40(*(undefined4 *)(&DAT_007f5dc4 + iVar7 * 4),local_128);
            }
          }
          else {
            FUN_00684400(&DAT_007f5dc4 + iVar7 * 4);
          }
        }
        if ((0.0 < *(float *)(iVar13 + 0xdec)) && (*(char *)(iVar13 + 0x28b) == '\0')) {
          iVar7 = FUN_0054fa60();
          fVar1 = ((float)iVar7 * 1.5259022e-05 * 0.5 + 0.5) * *(float *)(iVar13 + 0x1dc);
          uVar8 = FUN_0054fa60();
          fStack_13c = *(float *)(iVar13 + 0x5c) +
                       fVar1 * (float)(&DAT_029899a0)[(uVar8 & 0xffff) >> 1];
          fStack_138 = *(float *)(iVar13 + 0xff0) * *(float *)(iVar13 + 0xa8) +
                       *(float *)(iVar13 + 0x60) + 0.05;
          fStack_134 = fVar1 * (float)(&DAT_029899a0)
                                      [(int)((uVar8 & 0xffff) + 0x4000) >> 1 & 0x7fff] +
                       *(float *)(iVar13 + 100);
          FUN_0046a8d0(PTR_DAT_00802c54,&fStack_13c);
        }
      }
      local_14c = local_14c + 1;
      iVar13 = iVar13 + 0x10d8;
    } while (local_14c < DAT_0093d500);
  }
  return;
}

