/* Ghidra pseudocode, not original source.
 * ev_55c731fbd74135d460c444c417a3a15a2648f8ead34d22c2fd0b5dd9a411012b
 * Entry: 0x422730; label: FUN_00422730
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00422730(void)

{
  byte bVar1;
  char cVar2;
  byte bVar3;
  undefined4 uVar4;
  int iVar5;
  float fVar6;
  int iVar7;
  int in_ECX;
  undefined1 *puVar8;
  byte *pbVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  int iVar12;
  float10 fVar13;
  ulonglong uVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  undefined4 uVar17;
  undefined4 uVar18;
  undefined4 uVar19;
  float fVar20;
  undefined4 uVar21;
  float fVar22;
  undefined4 uVar23;
  undefined4 uVar24;
  float fStack_14c;
  float fStack_148;
  float local_144;
  float fStack_140;
  float fStack_13c;
  float fStack_138;
  float fStack_134;
  float local_130;
  float fStack_12c;
  int *piStack_128;
  float fStack_124;
  float fStack_120;
  float fStack_11c;
  int iStack_118;
  float fStack_114;
  float fStack_110;
  int iStack_10c;
  float fStack_108;
  float local_104;
  float fStack_100;
  undefined4 uStack_fc;
  int iStack_f8;
  int iStack_f4;
  undefined4 uStack_f0;
  float fStack_ec;
  byte *pbStack_e8;
  float local_e4;
  float local_e0;
  undefined4 uStack_dc;
  float fStack_d8;
  int iStack_d4;
  undefined4 uStack_d0;
  undefined4 local_cc;
  undefined4 local_c8;
  undefined1 auStack_c4 [64];
  undefined1 auStack_84 [128];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&fStack_14c;
  local_e4 = 0.0;
  if (*(char *)(in_ECX + 9) != '\0') {
    local_104 = 0.0;
    local_e0 = 0.0;
    local_cc = _DAT_008015ac;
    local_c8 = _DAT_008015b0;
    _DAT_008015b0 = 0x3f800000;
    _DAT_008015ac = 0x3f800000;
    FUN_0050c770(2);
    if (*(code **)(in_ECX + 0x74) != (code *)0x0) {
      (**(code **)(in_ECX + 0x74))(0,0,*(undefined4 *)(in_ECX + 0x14));
    }
    local_144 = 0.0;
    local_130 = 1.0;
    if (1 < *(int *)(in_ECX + 4)) {
      local_104 = -0.65;
      local_e0 = 0.65;
    }
    if (*(int *)(in_ECX + 0x38) == 0) {
      uStack_f0 = 0xbf266666;
      uStack_fc = 0x3f266666;
    }
    else {
      uStack_f0 = 0x3f266666;
      uStack_fc = 0xbf266666;
    }
    FUN_005d0880(2);
    FUN_005d0a40(3);
    DAT_02854d1c = DAT_02854d1c + 1;
    FUN_00600b20(1);
    iStack_f8 = *(int *)(in_ECX + 0x3c);
    iStack_10c = *(int *)(in_ECX + 0x40);
    if (*(int *)(in_ECX + 4) == 1) {
      local_144 = 0.3;
    }
    FUN_00422340(DAT_00855f98,0,0x3f666666,0,0x40,0x40000000,0x40000000,0x80ff2080,2,0);
    fStack_12c = *(float *)(in_ECX + 0x10) * 0.5 + 0.5;
    fStack_120 = fStack_12c;
    fStack_108 = fStack_12c;
    if (*(char *)(in_ECX + 0x70) != '\0') {
      local_e4 = (float)FUN_00420780(fStack_12c,fStack_12c,0x800000ff);
    }
    fStack_d8 = (float)FUN_00420780(fStack_12c,fStack_120,0x80c0c0c0);
    fStack_110 = (float)FUN_00420780(fStack_12c,fStack_120,0x80c0c000);
    iStack_118 = 0;
    if (0 < *(int *)(in_ECX + 0x1c)) {
      do {
        pbVar9 = *(byte **)(in_ECX + 0xac + iStack_118 * 0xc);
        piStack_128 = (int *)(in_ECX + 0xa4 + iStack_118 * 0xc);
        iVar5 = *(int *)(in_ECX + 0x38);
        fStack_108 = -NAN;
        if (iVar5 == 0) {
          fStack_134 = -1.4751301e-38;
          fStack_11c = -4.42539e-39;
        }
        else {
          fStack_11c = -1.4751301e-38;
          fStack_134 = -4.42539e-39;
        }
        if (*(char *)(in_ECX + 8) != '\0') {
          fStack_134 = -1.4751301e-38;
          fStack_11c = -1.4751301e-38;
        }
        if (*(int *)(in_ECX + 0x24) == 2) {
          if (iVar5 == 0) {
            fStack_134 = fStack_110;
          }
          else {
            fStack_11c = fStack_110;
          }
        }
        uVar10 = 0x80808020;
        uVar11 = 0x80808020;
        pbStack_e8 = pbVar9;
        if (*(char *)(in_ECX + 8) == '\0') {
          if (iVar5 == 0) {
            uVar10 = FUN_00420780(fStack_12c,fStack_120,0x80808020);
          }
          else {
            uVar11 = FUN_00420780(fStack_12c,fStack_120,0x80808020);
          }
        }
        FUN_00420700(*(undefined4 *)(in_ECX + 0xa0),*(undefined4 *)(in_ECX + 0x30),
                     *(undefined4 *)(in_ECX + 0x34),&uStack_d0,&uStack_dc);
        FUN_005d0fe0(*(undefined4 *)(in_ECX + 0xa0),uStack_d0,uStack_dc);
        FUN_005d1530(*(undefined4 *)(in_ECX + 0xa0),uStack_d0,uStack_dc);
        fVar13 = (float10)FUN_005d0e80(*(undefined4 *)(in_ECX + 0xa0));
        fStack_ec = (float)fVar13;
        fStack_13c = (float)FUN_004212e0(piStack_128);
        fStack_148 = 0.06 - fStack_ec * (float)(int)fStack_13c * 0.5;
        fVar6 = fStack_148 - fStack_ec * 1.1;
        fStack_14c = fVar6;
        if (iStack_f8 < 0) {
          if (-1 < iStack_10c) {
LAB_00422b1c:
            if (1 < *(int *)(in_ECX + 4)) {
              uVar24 = 0;
              uVar23 = 0x3f19999a;
              uVar21 = 0x3f800000;
              uVar19 = 0x80208020;
              uVar18 = 0x3f4ccccd;
              uVar17 = 0x3fb33333;
              uVar16 = 0x40;
              uVar15 = 0;
              fVar6 = local_144 + 0.65;
              fVar20 = fStack_14c;
              fStack_13c = fVar6;
              uVar4 = FUN_006d6300(iStack_10c,fVar6,fStack_14c,0,0x40,0x3fb33333,0x3f4ccccd,
                                   0x80208020,0x3f800000,0x3f19999a,0);
              FUN_00421100(uVar4,fVar6,fVar20,uVar15,uVar16,uVar17,uVar18,uVar19,uVar21,uVar23,
                           uVar24);
            }
            goto LAB_00422b8e;
          }
        }
        else {
          uVar24 = 0;
          uVar23 = 0x3f19999a;
          uVar21 = 0x3f800000;
          uVar19 = 0x80208020;
          uVar18 = 0x3f4ccccd;
          uVar17 = 0x3fb33333;
          uVar16 = 0x40;
          uVar15 = 0;
          fVar20 = local_104;
          uVar4 = FUN_006d6300(iStack_f8,local_104,fVar6,0,0x40,0x3fb33333,0x3f4ccccd,0x80208020,
                               0x3f800000,0x3f19999a,0);
          FUN_00421100(uVar4,fVar20,fVar6,uVar15,uVar16,uVar17,uVar18,uVar19,uVar21,uVar23,uVar24);
          if (-1 < iStack_10c) goto LAB_00422b1c;
LAB_00422b8e:
          fStack_14c = fStack_14c - (fStack_ec + fStack_ec);
        }
        if (1 < *(int *)(in_ECX + 4)) {
          FUN_00422340(DAT_00855fec,local_104,fStack_14c,0,0x40,0x40000000,0x3fc00000,uVar10,2,0);
          fStack_13c = local_144 + 0.65;
          FUN_00422340(DAT_00855ff0,fStack_13c,fStack_14c,0,0x40,0x40000000,0x3fc00000,uVar11,2,0);
        }
        FUN_006d66d0(1);
        iStack_d4 = 1;
        fStack_13c = 1.4013e-45;
        iStack_f4 = 0;
        if (0 < *piStack_128) {
          do {
            if ((pbVar9[3] >> 1 & pbVar9[3] & 0x20) == 0) {
              fStack_124 = fStack_134;
              iVar5 = *(int *)(in_ECX + 0x24);
              fStack_140 = 0.0;
              fStack_114 = fStack_11c;
              fStack_14c = (float)((-(uint)(*pbVar9 != 4) & 0x40) + 0x80408040);
              if (((iVar5 != 2) &&
                  (local_130 = *(float *)(pbVar9 + 4) * 0.5 + 1.0,
                  iStack_118 == *(int *)(in_ECX + 0x20))) && (iStack_f4 == piStack_128[1])) {
                if (*(int *)(in_ECX + 0x38) == 0) {
                  fStack_124 = fStack_d8;
                }
                else {
                  fStack_114 = fStack_d8;
                }
                fStack_14c = fStack_d8;
                if (iVar5 == 1) {
                  if (*(int *)(in_ECX + 0x38) == 0) {
                    fStack_124 = fStack_110;
                    fStack_114 = fStack_11c;
                  }
                  else {
                    fStack_114 = fStack_110;
                    fStack_124 = fStack_134;
                  }
                  fStack_140 = 1.4013e-45;
                  fStack_14c = fStack_110;
                }
              }
              if (*pbVar9 == 2) {
                if ((iVar5 == 3) || (iVar5 == 4)) {
                  fStack_14c = fStack_110;
                }
                iVar5 = *(int *)(in_ECX + 4);
                iVar12 = 0;
                if (0 < iVar5) {
                  do {
                    bVar1 = pbVar9[3];
                    bVar3 = bVar1 >> 5;
                    if (iVar12 != 0) {
                      bVar3 = bVar1 >> 6;
                    }
                    if ((-1 < *(int *)(in_ECX + 0x3c + iVar12 * 4)) && ((bVar3 & 1) == 0)) {
                      fStack_138 = 1.0;
                      if ((*(int *)(in_ECX + 0x38) == iVar12) &&
                         ((iStack_118 == *(int *)(in_ECX + 0x20) &&
                          (pbVar9 = pbStack_e8, iStack_f4 == piStack_128[1])))) {
                        fStack_138 = fStack_12c;
                      }
                      if (((char)bVar1 < '\0') || (iVar12 != *(int *)(in_ECX + 0x38))) {
                        fStack_138 = fStack_138 * 0.4;
                      }
                      if (iVar5 == 2) {
                        fStack_100 = local_e0;
                        if (iVar12 == 0) {
                          fStack_100 = local_104;
                        }
                      }
                      else {
                        fStack_100 = local_144 - 0.65;
                      }
                      iVar5 = FUN_006d67a0(*(undefined4 *)(in_ECX + 0x3c + iVar12 * 4));
                      fVar6 = fStack_138;
                      if (iVar5 == 0) {
                        fStack_138 = fStack_ec * 0.7 * local_130 + fStack_148;
                        FUN_00420920(fStack_100,fStack_138,0,0x3e800000,local_130 * 0.02,fVar6,fVar6
                                     ,*(undefined4 *)(in_ECX + 0x78 + iVar12 * 4));
                      }
                    }
                    iVar5 = *(int *)(in_ECX + 4);
                    iVar12 = iVar12 + 1;
                  } while (iVar12 < iVar5);
                }
              }
              if (*pbVar9 == 0) {
                if ((*(char *)(in_ECX + 0x70) != '\0') && (fStack_140 == 0.0)) {
                  iVar5 = FUN_006d68e0(0,pbVar9[1],1,0);
                  if ((iVar5 == 0) && ((pbVar9[3] & 8) == 0)) {
                    fStack_124 = local_e4;
                  }
                  iVar5 = FUN_006d68e0(0,pbVar9[1],1,1);
                  if ((iVar5 == 0) && ((pbVar9[3] & 8) != 0)) {
                    fStack_114 = local_e4;
                  }
                }
                if (iStack_f8 < 0) {
                  if (iStack_d4 != 0) {
                    fVar20 = 1.0;
                    iStack_d4 = 0;
                    fVar6 = 0.0;
                    puVar8 = DAT_00855fa8;
                    fVar22 = fStack_134;
                    goto LAB_00422fb6;
                  }
                }
                else if ((pbVar9[3] & 0x20) == 0) {
                  FUN_006d9670(iStack_f8,pbVar9[1],auStack_c4,1,0,1,0,0);
                  puVar8 = auStack_c4;
                  fVar6 = fStack_148;
                  fVar20 = local_130;
                  fVar22 = fStack_124;
LAB_00422fb6:
                  fStack_140 = local_144 - 0.65;
                  FUN_00422340(puVar8,fStack_140,fVar6,0,0x40,0x40200000,fVar20,fVar22,1,0x3ee66666)
                  ;
                }
                if (*(int *)(in_ECX + 4) == 2) {
                  if (iStack_10c < 0) {
                    if (fStack_13c != 0.0) {
                      fVar20 = 1.0;
                      fStack_13c = 0.0;
                      fVar6 = 0.0;
                      puVar8 = DAT_00855fa8;
                      fVar22 = fStack_11c;
                      goto LAB_004230a6;
                    }
                  }
                  else if ((pbVar9[3] & 0x40) == 0) {
                    FUN_006d9670(iStack_10c,pbVar9[1],auStack_c4,1,1,1,0,0);
                    puVar8 = auStack_c4;
                    fVar6 = fStack_148;
                    fVar20 = local_130;
                    fVar22 = fStack_114;
LAB_004230a6:
                    fStack_140 = local_144 + 0.65;
                    FUN_00422340(puVar8,fStack_140,fVar6,0,0x40,0x40200000,fVar20,fVar22,1,
                                 0x3ee66666);
                  }
                }
              }
              if ((fStack_108 != 5.60519e-45) && (*pbVar9 == 4)) {
                local_144 = 0.0;
                fStack_148 = -0.65;
              }
              uVar14 = (ulonglong)CONCAT14(pbVar9[2],fStack_14c);
              if (pbVar9[2] == 0x2b) {
                iVar5 = FUN_006d6710();
                uVar10 = DAT_00855fec;
                if ((iVar5 != 0) && (uVar10 = DAT_00856040, iVar5 == 1)) {
                  uVar10 = DAT_00855ff0;
                }
                FUN_004f2740(auStack_84,"%s (%s)",(&DAT_00855f90)[pbVar9[2]],uVar10);
                if ((pbVar9[3] & 0x80) == 0) {
                  uVar10 = 0x3f19999a;
                  puVar8 = auStack_84;
                  fVar6 = fStack_14c;
                }
                else {
                  fVar6 = (float)FUN_004208a0(0x3ecccccd,fStack_14c);
                  uVar10 = 0x3f19999a;
                  puVar8 = auStack_84;
                }
              }
              else {
                if ((pbVar9[3] & 0x80) != 0) {
                  uVar14 = FUN_004208a0(0x3ecccccd,fStack_14c);
                }
                fVar6 = (float)uVar14;
                uVar10 = 0x3f333333;
                puVar8 = (undefined1 *)(&DAT_00855f90)[(uint)(uVar14 >> 0x20) & 0xff];
              }
              fVar13 = (float10)FUN_00422340(puVar8,local_144,fStack_148,0,0x40,0x40200000,local_130
                                             ,fVar6,1,uVar10);
              fStack_108 = (float)(uint)*pbVar9;
              fStack_148 = (float)(fVar13 + (float10)fStack_148);
            }
            iStack_f4 = iStack_f4 + 1;
            pbVar9 = pbVar9 + 8;
            pbStack_e8 = pbVar9;
          } while (iStack_f4 < *piStack_128);
        }
        FUN_006d66d0(0);
        iVar5 = 0;
        switch(*(undefined4 *)(in_ECX + 0x24)) {
        case 0:
          iVar5 = 0;
          if (*(char *)(in_ECX + 8) == '\0') {
            iVar5 = DAT_00856014;
          }
          if (-1 < *(int *)(in_ECX + 0x3c + *(int *)(in_ECX + 0x38) * 4)) {
            cVar2 = *(char *)(piStack_128[2] + piStack_128[1] * 8);
            if (cVar2 == '\0') {
              iVar7 = FUN_00420640(piStack_128,piStack_128[1],*(int *)(in_ECX + 0x38));
              iVar12 = DAT_00855ff4;
              if (iVar7 == 0) goto LAB_004232a4;
            }
            else {
              iVar12 = DAT_00855ff8;
              if (cVar2 == '\x02') {
                iVar12 = DAT_00856010;
              }
            }
            if (iVar12 != 0) {
              FUN_00421100(iVar12,uStack_f0,0xbf4ccccd,0,0x40,0x40000000,0x3f800000,0x80c0c0c0,
                           0x3f800000,0x3f0a3d71,0);
            }
          }
LAB_004232a4:
          if (iVar5 == 0) goto switchD_0042320b_default;
          goto LAB_004232f1;
        case 1:
          iVar12 = DAT_00855fa0;
          break;
        case 2:
          iVar12 = DAT_00855fa4;
          break;
        case 3:
          iVar12 = DAT_00856000;
          iVar5 = DAT_00856004;
          break;
        case 4:
          iVar12 = DAT_00856008;
          iVar5 = DAT_0085600c;
          break;
        default:
          goto switchD_0042320b_default;
        }
        if (iVar12 != 0) {
          FUN_00421100(iVar12,uStack_f0,0xbf4ccccd,0,0x40,0x40000000,0x3f800000,0x80c0c0c0,
                       0x3f800000,0x3f0a3d71,0);
        }
        if (iVar5 != 0) {
LAB_004232f1:
          FUN_00421100(iVar5,uStack_fc,0xbf4ccccd,0,0x40,0x40000000,0x3f800000,0x80c0c0c0,0x3f800000
                       ,0x3f0a3d71,0);
        }
switchD_0042320b_default:
        iStack_118 = iStack_118 + 1;
      } while (iStack_118 < *(int *)(in_ECX + 0x1c));
    }
    FUN_004224d0(*(undefined4 *)(in_ECX + 0xeb8));
    FUN_0050c770(0);
    iVar5 = DAT_02854d1c * 4;
    DAT_02854d1c = DAT_02854d1c + -1;
    FUN_00600b20(*(undefined4 *)(&DAT_00981c4c + iVar5));
    FUN_005d0a70();
    FUN_005d08c0();
    _DAT_008015ac = local_cc;
    _DAT_008015b0 = local_c8;
  }
  __security_check_cookie(local_4 ^ (uint)&fStack_14c);
  return;
}

