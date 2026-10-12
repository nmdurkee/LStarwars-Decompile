/* Ghidra pseudocode, not original source.
 * ev_51f4537ed7c57c9a0fa7f304a7a0f3427cc608dfecd65a4b8280241ed2e1f797
 * Entry: 0x5ac080; label: FUN_005ac080
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005ac080(undefined4 param_1,int *param_2,float param_3)

{
  float fVar1;
  char cVar2;
  byte bVar3;
  ushort uVar4;
  float fVar5;
  float fVar6;
  bool bVar7;
  int iVar8;
  int iVar9;
  undefined4 *puVar10;
  uint uVar11;
  undefined4 uVar12;
  uint uVar13;
  float *pfVar14;
  int iVar15;
  undefined4 *puVar16;
  short sVar17;
  int iVar18;
  undefined4 *puVar19;
  undefined4 *puVar20;
  float10 fVar21;
  float10 fVar22;
  float local_15c;
  uint local_158;
  uint local_154;
  undefined4 *local_14c;
  undefined4 *local_148;
  undefined4 *local_144;
  int local_140;
  float local_13c;
  float local_138;
  float local_134;
  undefined4 *local_130;
  undefined8 local_12c;
  int local_124;
  int local_120;
  int local_11c;
  undefined1 local_118 [12];
  uint local_10c;
  uint local_108;
  undefined4 local_100 [16];
  undefined4 local_c0 [12];
  undefined1 local_90 [16];
  undefined4 local_80 [16];
  undefined4 local_40 [16];
  
  if (param_2 != (int *)0x0) {
    iVar15 = *param_2;
    local_11c = 0;
    if ((short)param_2[2] != 0) {
      do {
        uVar4 = *(ushort *)(iVar15 + 0x13a);
        local_12c = (double)(CONCAT44(local_12c._4_4_,(uint)(uVar4 >> 0xb)) & 0xffffffff00000001);
        *(ushort *)(iVar15 + 0x13a) = uVar4 & 0xf77f;
        if ((((uVar4 & 4) != 0) && ((uVar4 & 2) != 0)) && ((uVar4 & 0x20) == 0)) {
          iVar8 = FUN_005806a0((int)*(char *)(iVar15 + 0x12d),param_1);
          sVar17 = 0;
          local_120 = 0;
          bVar7 = false;
          local_124 = iVar8;
          if ((*(int *)(iVar15 + 0x1c) == 0) ||
             (iVar9 = FUN_005cfac0(*(int *)(iVar15 + 0x1c) + 4), iVar9 == 0)) {
            FUN_005b4500(local_80,iVar15 + 0x24);
            FUN_005b4dd0(local_80,*(undefined4 *)(iVar15 + 0x54));
            FUN_005b5060(local_80,*(undefined4 *)(iVar15 + 0x60));
            FUN_005b4500(local_40,iVar15 + 0x24);
            FUN_005b5060(local_40,(int)*(short *)(iVar15 + 0x128));
            sVar17 = *(short *)(iVar15 + 0x128);
            local_144 = local_40;
            local_148 = local_80;
            local_14c = (undefined4 *)0x0;
LAB_005ac21c:
            puVar10 = (undefined4 *)0x0;
            local_130 = (undefined4 *)0x0;
          }
          else {
            local_148 = (undefined4 *)FUN_005d0330(*(int *)(iVar15 + 0x1c) + 4);
            local_14c = (undefined4 *)FUN_005cfa20(*(int *)(iVar15 + 0x1c) + 4);
            local_144 = local_14c;
            if ((*(int *)(iVar15 + 0x20) == 0) ||
               (iVar9 = FUN_005cfac0(*(int *)(iVar15 + 0x20) + 4), iVar9 == 0)) goto LAB_005ac21c;
            local_144 = (undefined4 *)FUN_005cfa20(*(int *)(iVar15 + 0x20) + 4);
            local_130 = local_144;
            puVar10 = (undefined4 *)FUN_005d0330(*(int *)(iVar15 + 0x20) + 4);
          }
          fVar1 = *(float *)(iVar15 + 0xf8) - param_3;
          *(float *)(iVar15 + 0xf8) = fVar1;
          if (fVar1 < 0.0) {
            *(undefined4 *)(iVar15 + 0xf8) = 0;
          }
          iVar9 = *(int *)(iVar15 + 0xe8);
          local_158 = (uint)sVar17;
          local_154 = 0;
          if (iVar9 == 0) {
            iVar9 = 0;
            if ((*(ushort *)(iVar15 + 0x13a) & 8) == 0) {
              if ((*(ushort *)(iVar15 + 0x13a) & 0x10) == 0) {
                if (((byte)*(uint *)(iVar15 + 0x108) & 0xc0) == 0xc0) {
                  if ((((*(uint *)(iVar15 + 0x108) & 0x100) == 0) || (*(int *)(iVar15 + 0x1c) == 0))
                     || ((iVar8 = FUN_005cfac0(*(int *)(iVar15 + 0x1c) + 4), iVar8 == 0 ||
                         (iVar8 = FUN_005cfe70(*(int *)(iVar15 + 0x1c) + 4), iVar8 != 0)))) {
LAB_005ac522:
                    if (*(float *)(iVar15 + 0xf8) == 0.0) {
                      fVar21 = (float10)FUN_005b9dd0();
                      bVar7 = true;
                      *(float *)(iVar15 + 0xf8) =
                           (float)((fVar21 + (float10)0.5) * (float10)*(float *)(iVar15 + 0xfc));
                    }
                  }
                }
                else {
                  iVar18 = *(int *)(iVar15 + 0xe4);
                  if (iVar18 == 0) {
                    uVar11 = FUN_00550070(*(undefined2 *)(iVar15 + 0x54),0,
                                          *(undefined4 *)(iVar15 + 0x100));
                    *(uint *)(iVar15 + 0x54) = uVar11 & 0xffff;
                    uVar11 = FUN_00550070(*(undefined2 *)(iVar15 + 0x60),sVar17,
                                          *(undefined4 *)(iVar15 + 0x104));
                    *(ushort *)(iVar15 + 0x13a) = *(ushort *)(iVar15 + 0x13a) & 0xffbf;
                    *(uint *)(iVar15 + 0x60) = uVar11 & 0xffff;
                  }
                  else {
                    cVar2 = *(char *)(iVar15 + 300);
                    if (cVar2 == '\0') {
                      iVar9 = iVar18 + 0x68;
                      iVar18 = iVar18 + 0x80;
                    }
                    else if (cVar2 == '\x01') {
                      iVar18 = iVar18 + 0x11c;
                    }
                    else if (cVar2 != '\x02') goto LAB_005ac49b;
                    fVar21 = (float10)FUN_005b3c50(iVar18,iVar15 + 0x3c,&local_13c);
                    if (iVar18 != 0) {
                      if ((((*(uint *)(iVar15 + 0x108) & 0x200) == 0) || (iVar9 == 0)) ||
                         (iVar8 == 0)) {
                        FUN_005b3800(local_118,iVar18,local_144 + 0xc);
                      }
                      else {
                        FUN_005abf00(local_144 + 0xc,local_148,iVar18,iVar9,
                                     *(undefined4 *)(iVar8 + 0x10),local_118,0,
                                     *(int *)(iVar15 + 0xe8) != 0);
                      }
                      if (((byte)*(undefined4 *)(iVar15 + 0x108) & 0xc0) != 0xc0) {
                        FUN_005b3470(&local_13c,local_118,local_144);
                        if ((*(byte *)(iVar15 + 0x108) & 0x80) == 0) {
                          FUN_005bfe00(-local_13c,-local_134);
                          uVar12 = FUN_006e6b90();
                          uVar11 = FUN_005be590(uVar12,0);
                          local_158 = *(uint *)(iVar15 + 100);
                          if (((local_158 == 0) || ((int)uVar11 <= (int)local_158)) &&
                             ((uVar13 = *(uint *)(iVar15 + 0x68), local_158 = uVar11, uVar13 != 0 &&
                              ((int)uVar11 < (int)uVar13)))) {
                            local_158 = uVar13;
                          }
                        }
                        if ((*(byte *)(iVar15 + 0x108) & 0x40) == 0) {
                          FUN_005b3620(&local_13c,&local_13c,-local_158);
                          if (local_130 != (undefined4 *)0x0) {
                            local_138 = local_138 - *(float *)(iVar15 + 0xd8);
                            FUN_005b3470(&local_13c,&local_13c,iVar15 + 0xa4);
                            local_138 = local_138 - *(float *)(iVar15 + 0x78);
                          }
                          fVar22 = (float10)FUN_005c0240(local_134 * local_134 +
                                                         local_13c * local_13c);
                          FUN_005bfe00(local_138,(float)fVar22);
                          uVar12 = FUN_006e6b90();
                          local_154 = FUN_005be590(uVar12,0);
                          uVar11 = *(uint *)(iVar15 + 0x58);
                          if (((uVar11 != 0) && ((int)uVar11 < (int)local_154)) ||
                             ((uVar11 = *(uint *)(iVar15 + 0x5c), uVar11 != 0 &&
                              ((int)local_154 < (int)uVar11)))) {
                            local_154 = uVar11;
                          }
                        }
                      }
                      if ((((((*(uint *)(iVar15 + 0x108) & 0x100) == 0) ||
                            (*(int *)(iVar15 + 0x1c) == 0)) ||
                           (iVar8 = FUN_005cfac0(*(int *)(iVar15 + 0x1c) + 4), iVar8 == 0)) ||
                          (iVar8 = FUN_005cfe70(*(int *)(iVar15 + 0x1c) + 4), iVar8 != 0)) &&
                         ((float)fVar21 < *(float *)(iVar15 + 0xf0) * *(float *)(iVar15 + 0xf0)))
                      goto LAB_005ac522;
                    }
                  }
                }
              }
              else {
                local_154 = *(uint *)(iVar15 + 0x6c);
                local_158 = *(uint *)(iVar15 + 0x70);
              }
            }
LAB_005ac49b:
            if ((*(int *)(iVar15 + 0x1c) == 0) ||
               (iVar8 = FUN_005cfac0(*(int *)(iVar15 + 0x1c) + 4), iVar8 == 0)) {
              local_158 = FUN_005be590(local_158,(int)*(short *)(iVar15 + 0x128));
            }
            if ((*(uint *)(iVar15 + 0x108) & 0x400) == 0) {
              uVar11 = FUN_00550070(*(undefined2 *)(iVar15 + 0x54),local_154,
                                    *(undefined4 *)(iVar15 + 0x100));
              *(uint *)(iVar15 + 0x54) = uVar11 & 0xffff;
              uVar11 = FUN_00550070(*(undefined2 *)(iVar15 + 0x60),local_158,
                                    *(undefined4 *)(iVar15 + 0x104));
              *(uint *)(iVar15 + 0x60) = uVar11 & 0xffff;
            }
            else {
              *(uint *)(iVar15 + 0x54) = local_154;
              *(uint *)(iVar15 + 0x60) = local_158;
            }
          }
          else if ((*(int *)(iVar9 + 0xcd0) == 0) || ((*(byte *)(iVar9 + 0x1fc) & 0x80) == 0)) {
            uVar11 = FUN_00550070(*(undefined2 *)(iVar15 + 0x54),0,*(undefined4 *)(iVar15 + 0x100));
            *(uint *)(iVar15 + 0x54) = uVar11 & 0xffff;
            uVar11 = FUN_00550070(*(undefined2 *)(iVar15 + 0x60),local_158,
                                  *(undefined4 *)(iVar15 + 0x104));
            *(ushort *)(iVar15 + 0x13a) = *(ushort *)(iVar15 + 0x13a) & 0xffbf;
            *(uint *)(iVar15 + 0x60) = uVar11 & 0xffff;
          }
          else {
            fVar1 = -*(float *)(*(int *)(iVar9 + 0xca4) + 0x30) * *(float *)(iVar15 + 0x100);
            if (0.0 <= fVar1) {
              if (fVar1 <= 0.0) {
                local_154 = *(uint *)(iVar15 + 0x54);
              }
              else {
                local_154 = *(uint *)(iVar15 + 0x5c);
              }
            }
            else {
              local_154 = *(uint *)(iVar15 + 0x58);
              fVar1 = -fVar1;
            }
            local_15c = -*(float *)(*(int *)(iVar9 + 0xca4) + 0x2c) * *(float *)(iVar15 + 0x104);
            if (0.0 <= local_15c) {
              if (local_15c <= 0.0) {
                local_158 = *(uint *)(iVar15 + 0x60);
              }
              else {
                local_158 = *(uint *)(iVar15 + 0x68);
              }
            }
            else {
              local_158 = *(uint *)(iVar15 + 100);
              local_15c = -local_15c;
            }
            uVar11 = FUN_00550070(*(undefined2 *)(iVar15 + 0x54),local_154,fVar1);
            *(uint *)(iVar15 + 0x54) = uVar11 & 0xffff;
            uVar11 = FUN_00550070(*(undefined2 *)(iVar15 + 0x60),local_158,local_15c);
            *(uint *)(iVar15 + 0x60) = uVar11 & 0xffff;
            if ((0.0 < *(float *)(iVar15 + 0xf8)) &&
               ((*(uint *)(*(int *)(*(int *)(iVar15 + 0xe8) + 0xca4) + 8) & DAT_0080227c) != 0)) {
              fVar1 = *(float *)(iVar15 + 0xfc) * _DAT_00805e30;
              if (fVar1 < *(float *)(iVar15 + 0xf8)) {
                *(float *)(iVar15 + 0xf8) = fVar1;
              }
              *(ushort *)(iVar15 + 0x13a) = *(ushort *)(iVar15 + 0x13a) | 0x40;
            }
            if ((*(float *)(iVar15 + 0xf8) == 0.0) &&
               (((*(uint *)(*(int *)(*(int *)(iVar15 + 0xe8) + 0xca4) + 4) & DAT_0080227c) != 0 ||
                ((*(byte *)(iVar15 + 0x13a) & 0x40) != 0)))) {
              bVar7 = true;
              if ((*(ushort *)(iVar15 + 0x13a) & 0x40) == 0) {
                fVar1 = *(float *)(iVar15 + 0xfc);
              }
              else {
                fVar1 = *(float *)(iVar15 + 0xfc) * _DAT_00805e30;
              }
              *(float *)(iVar15 + 0xf8) = fVar1;
              *(ushort *)(iVar15 + 0x13a) = *(ushort *)(iVar15 + 0x13a) & 0xffbf;
              if ((*(uint *)(iVar15 + 0x108) & 0x200) != 0) {
                local_120 = FUN_005abd80(iVar15,local_148);
              }
            }
          }
          if ((*(int *)(iVar15 + 0x1c) != 0) &&
             (iVar8 = FUN_005cfac0(*(int *)(iVar15 + 0x1c) + 4), iVar8 != 0)) {
            iVar8 = 0x10;
            puVar16 = local_130;
            puVar20 = local_148;
            puVar19 = puVar10;
            if (local_130 == (undefined4 *)0x0) {
              for (; iVar8 != 0; iVar8 = iVar8 + -1) {
                *puVar20 = *local_14c;
                local_14c = local_14c + 1;
                puVar20 = puVar20 + 1;
              }
              if (*(int *)(iVar15 + 0x60) != 0) {
                FUN_005b5060(local_148,*(int *)(iVar15 + 0x60));
              }
              iVar8 = *(int *)(iVar15 + 0x54);
              if (iVar8 != 0) {
                bVar3 = *(byte *)(iVar15 + 0x108);
                goto joined_r0x005ac934;
              }
            }
            else {
              for (; iVar8 != 0; iVar8 = iVar8 + -1) {
                *puVar19 = *puVar16;
                puVar16 = puVar16 + 1;
                puVar19 = puVar19 + 1;
              }
              if (*(int *)(iVar15 + 0x60) != 0) {
                FUN_005b5060(puVar10,*(int *)(iVar15 + 0x60));
              }
              FUN_005b5430(local_148,iVar15 + 0xa4,puVar10);
              iVar8 = *(int *)(iVar15 + 0x54);
              if (iVar8 != 0) {
                bVar3 = *(byte *)(iVar15 + 0x108);
joined_r0x005ac934:
                if ((bVar3 & 0x40) == 0) {
                  FUN_005b4dd0(local_148,iVar8);
                }
              }
            }
          }
          if (*(int *)(iVar15 + 0x1c) != 0) {
            FUN_005ea660(*(int *)(iVar15 + 0x1c) + 4);
          }
          if (*(int *)(iVar15 + 0x20) != 0) {
            FUN_005ea660(*(int *)(iVar15 + 0x20) + 4);
          }
          if (((*(short *)(iVar15 + 0x126) != -1) &&
              (pfVar14 = (float *)(local_144 + 0xc), DAT_0093d810 != 0)) &&
             (((((*(int *)(PTR_DAT_00802c54 + 300) != 0 &&
                 ((*(byte *)(*(int *)(PTR_DAT_00802c54 + 300) + 0x7a) & 1) != 0)) ||
                ((fVar1 = *pfVar14 - *(float *)(DAT_0093d810 + 0x80),
                 fVar5 = (float)local_144[0xd] - *(float *)(DAT_0093d810 + 0x84),
                 fVar6 = (float)local_144[0xe] - *(float *)(DAT_0093d810 + 0x88),
                 fVar6 * fVar6 + fVar1 * fVar1 + fVar5 * fVar5 < 9.0 &&
                 (*(char *)(DAT_0093d810 + 0x288) != '\0')))) ||
               ((DAT_0093d814 != 0 &&
                ((fVar1 = *pfVar14 - *(float *)(DAT_0093d814 + 0x80),
                 fVar5 = (float)local_144[0xd] - *(float *)(DAT_0093d814 + 0x84),
                 fVar6 = (float)local_144[0xe] - *(float *)(DAT_0093d814 + 0x88),
                 fVar6 * fVar6 + fVar1 * fVar1 + fVar5 * fVar5 < 9.0 &&
                 (*(char *)(DAT_0093d814 + 0x288) != '\0')))))) &&
              ((uVar11 = (local_154 & 0xffff) - (uint)*(ushort *)(iVar15 + 0x54),
               uVar13 = (int)uVar11 >> 0x1f,
               (int)(uint)DAT_00805ea0 < (int)((uVar11 ^ uVar13) - uVar13) ||
               (uVar11 = (local_158 & 0xffff) - (uint)*(ushort *)(iVar15 + 0x60),
               uVar13 = (int)uVar11 >> 0x1f,
               (int)(uint)DAT_00805ea0 < (int)((uVar11 ^ uVar13) - uVar13))))))) {
            if (((int)local_12c == 0) ||
               (iVar8 = FUN_00650ef0((int)*(short *)(iVar15 + 0x126)), iVar8 != 0)) {
              FUN_005478a0((int)*(short *)(iVar15 + 0x126),pfVar14,0,0);
            }
            *(ushort *)(iVar15 + 0x13a) = *(ushort *)(iVar15 + 0x13a) | 0x800;
          }
          if ((((bVar7) && (local_124 != 0)) && (DAT_00855de0 == 0)) &&
             ((*(uint *)(iVar15 + 0x108) & 0x4000) == 0)) {
            if (*(short *)(iVar15 + 0x12a) != -1) {
              FUN_005478a0((int)*(short *)(iVar15 + 0x12a),local_144 + 0xc,0,0);
              DAT_009543e8 = 1;
            }
            iVar8 = local_124;
            uVar12 = 0;
            if (*(int *)(local_124 + 0x40) == 0) {
              local_14c = (undefined4 *)0x0;
            }
            else {
              local_12c = (double)*(int *)(local_124 + 0x40);
              FUN_005b9dd0();
              iVar9 = FUN_006e6b90();
              local_12c = (double)*(int *)(iVar8 + 0x40);
              local_14c = (undefined4 *)(iVar9 / 2);
              FUN_005b9dd0();
              uVar12 = FUN_006e6b90();
            }
            bVar3 = *(byte *)(iVar15 + 0x130);
            if (bVar3 == 0) {
              local_15c = 0.0;
            }
            else {
              iVar8 = FUN_0054fa60();
              local_15c = (float)(iVar8 / ((int)(0xffff / (ulonglong)(longlong)(int)(uint)bVar3) + 1
                                          ));
            }
            *(ushort *)(iVar15 + 0x13a) = *(ushort *)(iVar15 + 0x13a) | 0x80;
            local_140 = 0;
            if (bVar3 != 0) {
              pfVar14 = (float *)(iVar15 + 0x74);
              do {
                puVar10 = local_148;
                puVar16 = local_c0;
                for (iVar8 = 0x10; iVar8 != 0; iVar8 = iVar8 + -1) {
                  *puVar16 = *puVar10;
                  puVar10 = puVar10 + 1;
                  puVar16 = puVar16 + 1;
                }
                if (((*pfVar14 != 0.0) || (pfVar14[1] != 0.0)) || (pfVar14[2] != 0.0)) {
                  FUN_005b5060(local_c0,0x8000);
                  FUN_005b4960(local_c0,pfVar14);
                }
                puVar10 = local_148;
                puVar16 = local_100;
                for (iVar8 = 0x10; iVar8 != 0; iVar8 = iVar8 + -1) {
                  *puVar16 = *puVar10;
                  puVar10 = puVar10 + 1;
                  puVar16 = puVar16 + 1;
                }
                if ((*(byte *)(iVar15 + 0x108) & 0x40) != 0) {
                  FUN_005b4dd0(local_100,*(undefined4 *)(iVar15 + 0x54));
                }
                FUN_005b5060(local_100,0x8000);
                iVar8 = local_124;
                if (*(int *)(local_124 + 0x40) != 0) {
                  FUN_005b4dd0(local_100,local_14c);
                  FUN_005b5060(local_100,uVar12);
                }
                if (local_120 != 0) {
                  local_12c = (double)CONCAT44(local_12c._4_4_,*(undefined4 *)(iVar8 + 0x10));
                  FUN_005abf00(local_90,local_148,local_120 + 0x80,local_120 + 0x68,
                               *(undefined4 *)(iVar8 + 0x10),local_118,0,
                               *(int *)(iVar15 + 0xe8) != 0);
                  FUN_0054ff40(local_118,0,0);
                  local_10c = (uint)DAT_0092b0c4;
                  local_108 = (uint)DAT_0093b0c8;
                  FUN_005c0820(local_100,&local_10c);
                }
                if ((float)local_140 != local_15c) {
                  DAT_009543e8 = 1;
                }
                iVar8 = FUN_00582e70(0,local_90,local_100,(int)*(char *)(iVar15 + 0x12d),
                                     (*(int *)(iVar15 + 0xe8) != 0) * '\x02' + '\x02');
                if ((iVar8 != 0) && ((*(uint *)(iVar15 + 0x108) & 0x8000) != 0)) {
                  *(uint *)(iVar8 + 0xf0) = *(uint *)(iVar8 + 0xf0) | 0x10;
                }
                local_140 = local_140 + 1;
                pfVar14 = pfVar14 + 3;
              } while (local_140 < (int)(uint)*(byte *)(iVar15 + 0x130));
            }
          }
        }
        local_11c = local_11c + 1;
        iVar15 = iVar15 + 0x13c;
      } while (local_11c < (int)(uint)*(ushort *)(param_2 + 2));
    }
  }
  return;
}

