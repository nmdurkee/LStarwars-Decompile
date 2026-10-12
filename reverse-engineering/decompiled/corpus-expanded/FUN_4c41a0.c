/* Ghidra pseudocode, not original source.
 * ev_70591197c926ebc674651557d03c19c52d1cbc8417e398ad949c9ada842aa1a9
 * Entry: 0x4c41a0; label: FUN_004c41a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004c41a0(void)

{
  byte *pbVar1;
  ushort *puVar2;
  char cVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  short sVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  float10 fVar14;
  float10 extraout_ST0;
  float10 fVar15;
  float10 extraout_ST0_00;
  float10 fVar16;
  float10 fVar17;
  float10 fVar18;
  float10 fVar19;
  float10 fVar20;
  float10 extraout_ST1;
  float10 extraout_ST1_00;
  char *pcVar21;
  float local_40;
  float local_3c;
  int local_38;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  undefined4 local_c;
  undefined2 local_8;
  undefined1 local_6;
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_40;
  bVar4 = false;
  bVar7 = false;
  bVar6 = false;
  bVar5 = false;
  local_3c = 0.0;
  local_38 = 0;
  FUN_004c1080();
  fVar20 = (float10)0;
  if (fVar20 <= (float10)_DAT_008800e4) {
    _DAT_008800e4 = (float)((float10)_DAT_008800e4 - (float10)_DAT_00925018);
  }
  fVar14 = (float10)_DAT_008804b8;
  if (fVar20 <= fVar14) {
    _DAT_008804b8 = (float)(fVar14 - (float10)_DAT_00925018);
    fVar14 = (float10)_DAT_008804b8;
  }
  fVar18 = (float10)1;
  _DAT_008804b4 = 0;
  if (DAT_0087bbbc != 0) {
    local_40 = 1.0 - _DAT_008800e4 * 8.0;
    fVar15 = (float10)0;
    fVar20 = fVar14;
    iVar10 = FUN_006e6b90();
    fVar14 = fVar18;
    fVar18 = fVar15;
    local_40 = (float)(extraout_ST0 -
                      ((float10)(float)(&DAT_029899a0)[iVar10 >> 1 & 0x7fff] + extraout_ST0) *
                      (float10)0.5);
    if (DAT_0087bbbc == 1) {
      fVar15 = (float10)local_40;
      if (fVar18 <= fVar15) {
        local_40 = (float)fVar18;
      }
      if (extraout_ST1 <= (float10)local_40) {
        if (fVar15 < fVar18) {
          _DAT_0087bbc4 = (float)(fVar15 + extraout_ST1);
        }
        else {
          local_40 = (float)fVar18;
          _DAT_0087bbc4 = (float)((float10)local_40 + extraout_ST1);
        }
      }
      else {
        local_40 = (float)fVar20;
        _DAT_0087bbc4 = (float)((float10)local_40 + extraout_ST1);
      }
    }
    else if (DAT_0087bbbc == -1) {
      fVar15 = (float10)local_40;
      if (fVar18 <= fVar15) {
        local_40 = (float)fVar18;
      }
      if (extraout_ST1 <= (float10)local_40) {
        if (fVar18 <= fVar15) {
          local_40 = (float)fVar18;
          fVar15 = (float10)local_40;
        }
      }
      else {
        local_40 = (float)fVar20;
        fVar15 = (float10)local_40;
      }
      _DAT_0087bbc4 = (float)(fVar15 * (float10)-1.0 + extraout_ST0);
    }
  }
  if (fVar20 < (float10)_DAT_008800e4) {
    DAT_008804b0 = 0;
  }
  else {
    _DAT_008804a4 = 0;
    DAT_0087bbbc = 0;
    if (local_24 == 0) {
      if (local_20 == 0) {
        if (local_18 == 0) {
          if ((local_1c != 0) && ((fVar14 <= fVar20 || (local_2c != 0)))) {
            bVar5 = true;
          }
        }
        else if ((fVar14 <= fVar20) || (local_28 != 0)) {
          bVar4 = true;
        }
      }
      else {
        bVar7 = true;
      }
    }
    else {
      bVar6 = true;
    }
    if (local_14 == 0) {
      if (local_10 != 0) {
        local_38 = 1;
      }
    }
    else {
      local_3c = 1.4013e-45;
    }
    if (bVar4) {
      DAT_0087befc = DAT_0087befc + -1;
      _DAT_008804b8 = _DAT_007fcc60;
      if (DAT_0087befc < 0) {
        DAT_0087befc = 0x23;
      }
      _DAT_008804a4 = 0;
      (&DAT_007fcbf4)[DAT_0087c544] = s_L_ABCDEFGHIJKLMNOPQRSTUVWXYZ0123_007fcbca[DAT_0087befc + 2];
      DAT_008804b0 = 1;
      FUN_00547930(0x2f,&DAT_00880120,0,0);
      fVar20 = (float10)0;
      fVar18 = (float10)1;
    }
    if (bVar5) {
      DAT_0087befc = DAT_0087befc + 1;
      _DAT_008804b8 = _DAT_007fcc60;
      if (0x23 < DAT_0087befc) {
        DAT_0087befc = 0;
      }
      _DAT_008804a4 = 0;
      (&DAT_007fcbf4)[DAT_0087c544] = s_L_ABCDEFGHIJKLMNOPQRSTUVWXYZ0123_007fcbca[DAT_0087befc + 2];
      DAT_008804b0 = 1;
      FUN_00547930(0x2f,&DAT_00880120,0,0);
      fVar20 = (float10)0;
      fVar18 = (float10)1;
    }
    iVar10 = DAT_0087c544;
    if (bVar6) {
      iVar13 = DAT_0087c544 + -1;
      DAT_00880490 = DAT_0087c544;
      DAT_0087c544 = iVar13;
      if (iVar13 < 0) {
        DAT_0087c544 = 0;
      }
      _DAT_008804a4 = 0;
      if ((&DAT_007fcbf4)[DAT_0087c544] == '\0') {
        DAT_0087befc = 0;
        iVar9 = DAT_0087befc;
      }
      else {
        iVar13 = 0;
        do {
          iVar9 = iVar13;
          if ((&DAT_007fcbf4)[DAT_0087c544] ==
              s_L_ABCDEFGHIJKLMNOPQRSTUVWXYZ0123_007fcbca[iVar13 + 2]) break;
          iVar13 = iVar13 + 1;
          iVar9 = DAT_0087befc;
        } while (iVar13 < 0x24);
      }
      DAT_0087befc = iVar9;
      if ((iVar10 != DAT_0087c544) && (_DAT_008800e4 = 0.125, DAT_008804b0 == 0)) {
        DAT_008804b0 = 1;
        FUN_00547930(0x2f,&DAT_00880120,0,0);
        fVar18 = (float10)1;
        fVar20 = (float10)0;
      }
    }
    iVar10 = DAT_0087c544;
    if (bVar7) {
      DAT_0087c544 = DAT_0087c544 + 1;
      if (5 < DAT_0087c544) {
        DAT_0087c544 = 5;
      }
      _DAT_008804a4 = 0;
      if ((&DAT_007fcbf4)[DAT_0087c544] == '\0') {
        DAT_0087befc = 0;
        iVar9 = DAT_0087befc;
      }
      else {
        iVar13 = 0;
        do {
          iVar9 = iVar13;
          if ((&DAT_007fcbf4)[DAT_0087c544] ==
              s_L_ABCDEFGHIJKLMNOPQRSTUVWXYZ0123_007fcbca[iVar13 + 2]) break;
          iVar13 = iVar13 + 1;
          iVar9 = DAT_0087befc;
        } while (iVar13 < 0x24);
      }
      DAT_0087befc = iVar9;
      DAT_00880490 = iVar10;
      if ((iVar10 != DAT_0087c544) && (_DAT_008800e4 = 0.125, DAT_008804b0 == 0)) {
        DAT_008804b0 = 1;
        FUN_00547930(0x2f,&DAT_00880120,0,0);
        fVar20 = (float10)0;
        fVar18 = (float10)1;
      }
    }
    if (local_38 != 0) {
      _DAT_008800e4 = 0.125;
      _DAT_008804a4 = 0;
      DAT_0087befc = 0;
      DAT_0087bbbc = -1;
      DAT_00880494 = 1;
      FUN_00547930(0x31,0,0,0);
      fVar20 = (float10)0;
      fVar18 = (float10)1;
    }
    if (local_3c != 0.0) {
      (&DAT_007fcbf4)[DAT_0087c544] = s_L_ABCDEFGHIJKLMNOPQRSTUVWXYZ0123_007fcbca[DAT_0087befc + 2];
      local_c = _DAT_007fcbf4;
      local_8 = _DAT_007fcbf8;
      local_6 = 0;
      iVar10 = FUN_00650430(&local_c);
      iVar13 = 0;
      do {
        if (((&DAT_008801d0)[iVar13] != 0) && (iVar10 == (&DAT_008801d0)[iVar13])) {
          _DAT_008804a4 = 1;
          if (iVar13 < 0x90) {
            if (iVar13 < DAT_0087c56c) {
              if ((DAT_0093b288 == 0) ||
                 (puVar2 = (ushort *)(iVar13 * 0x74 + 0x60 + DAT_00880478),
                 (*(byte *)((uint)*puVar2 + DAT_0093b288) & 2) != 0)) {
                FUN_00681f40("Shop_NotEnufMuny",&DAT_00880444);
              }
              else {
                pbVar1 = (byte *)((uint)*puVar2 + DAT_0093b288);
                *pbVar1 = *pbVar1 | 2;
                FUN_0055c820(DAT_0093b2d8);
                FUN_00681f40("Shop_BuyCheat",&DAT_00880444);
              }
              DAT_0087ffe8 = *(undefined4 *)
                              (DAT_00926c20 +
                              *(int *)((uint)*(ushort *)(iVar13 * 0x74 + 0x60 + DAT_00880478) * 0x4c
                                      + DAT_0093b274) * 4);
            }
            else if (iVar13 < DAT_00880008) {
              iVar13 = iVar13 - DAT_0087c56c;
              iVar10 = (int)(iVar13 + (iVar13 >> 0x1f & 0x1fU)) >> 5;
              uVar12 = 1 << ((byte)iVar13 & 0x1f);
              if ((uVar12 & (&DAT_0086e4c8)[iVar10]) == 0) {
                (&DAT_0086e4c8)[iVar10] = (&DAT_0086e4c8)[iVar10] | uVar12;
                *(undefined1 *)(iVar13 * 0x74 + 99 + DAT_00880480) = 1;
                FUN_0055c820(DAT_0093b300);
                cVar3 = (&DAT_007f3da3)[iVar13 * 0x20];
                if ((cVar3 != -1) && ((&DAT_0086e0fa)[cVar3 * 0xc] == '\0')) {
                  (&DAT_0086e0fa)[cVar3 * 0xc] = 1;
                  FUN_0055c820(DAT_0093b2f8);
                }
                uVar12 = __allshl();
                (&DAT_0086e4b8)[iVar10] = (&DAT_0086e4b8)[iVar10] | uVar12;
                pcVar21 = "Shop_BuyCheat";
              }
              else {
                pcVar21 = "Shop_NotEnufMuny";
              }
              FUN_00681f40(pcVar21,&DAT_00880444);
              sVar8 = DAT_008806a0;
              if ((short *)(&PTR_DAT_007f3d9c)[iVar13 * 8] != (short *)0x0) {
                sVar8 = *(short *)(&PTR_DAT_007f3d9c)[iVar13 * 8];
              }
              DAT_0087ffe8 = *(undefined4 *)(DAT_00926c20 + sVar8 * 4);
            }
            _DAT_0088048c = _DAT_007fcb6c;
            _DAT_00880498 = 0x40499999;
            goto LAB_004c4918;
          }
          break;
        }
        iVar13 = iVar13 + 1;
      } while (iVar13 < 0x90);
      FUN_00681f40("Shop_NotEnufMuny",&DAT_00880444);
      DAT_0087ffe8 = 0;
LAB_004c4918:
      fVar18 = (float10)1;
      fVar20 = (float10)0;
    }
  }
  iVar13 = DAT_00880490;
  iVar10 = DAT_0087c544;
  if ((float10)_DAT_008800e4 < fVar20) {
    DAT_00880490 = -1;
  }
  else {
    local_3c = 1.0 - (float)((float10)_DAT_008800e4 * (float10)8.0);
    fVar14 = fVar20;
    iVar11 = FUN_006e6b90();
    fVar20 = fVar18;
    iVar9 = DAT_0087bbbc;
    local_40 = (float)(extraout_ST0_00 -
                      ((float10)(float)(&DAT_029899a0)[iVar11 >> 1 & 0x7fff] + extraout_ST0_00) *
                      (float10)0.5);
    fVar15 = (float10)_DAT_008800a4;
    fVar16 = (float10)_DAT_0087bbb8;
    fVar17 = (float10)local_40;
    if (iVar13 != -1) {
      bVar4 = extraout_ST1_00 <= fVar17;
      local_3c = local_40;
      if (DAT_0087bbbc == 1) {
        if (bVar4) {
          local_3c = (float)extraout_ST1_00;
        }
        if (fVar14 <= (float10)local_3c) {
          if (extraout_ST1_00 <= fVar17) {
            local_40 = (float)extraout_ST1_00;
            fVar17 = (float10)local_40;
          }
        }
        else {
          local_40 = (float)fVar20;
          fVar17 = (float10)local_40;
        }
        (&DAT_0087c52c)[iVar13] =
             (float)(((float10)(float)(&DAT_0087ffb4)[iVar13] -
                     (float10)(float)(&DAT_0087beb8)[iVar13]) * fVar17 +
                    (float10)(float)(&DAT_0087beb8)[iVar13]);
        fVar18 = extraout_ST1_00;
        if (fVar17 < extraout_ST1_00) {
          fVar18 = fVar17;
        }
        local_3c = (float)fVar18;
        if (fVar14 <= (float10)local_3c) {
          if (extraout_ST1_00 <= fVar17) {
            local_40 = (float)extraout_ST1_00;
            fVar17 = (float10)local_40;
          }
          _DAT_00880418 = (float)((fVar16 - fVar15) * fVar17 + fVar15);
        }
        else {
          local_40 = (float)fVar20;
          fVar17 = (float10)local_40;
          _DAT_00880418 = (float)((fVar16 - fVar15) * fVar17 + fVar15);
        }
      }
      else {
        if (DAT_0087bbbc == -1) {
          if (bVar4) {
            local_3c = (float)extraout_ST1_00;
          }
          if (fVar14 <= (float10)local_3c) {
            if (extraout_ST1_00 <= fVar17) {
              local_40 = (float)extraout_ST1_00;
              fVar17 = (float10)local_40;
            }
          }
          else {
            local_40 = (float)fVar20;
            fVar17 = (float10)local_40;
          }
          (&DAT_0087c52c)[iVar13] =
               (float)(((float10)(float)(&DAT_0087beb8)[iVar13] -
                       (float10)(float)(&DAT_0087ffb4)[iVar13]) * fVar17 +
                      (float10)(float)(&DAT_0087ffb4)[iVar13]);
          fVar18 = extraout_ST1_00;
          if (fVar17 < extraout_ST1_00) {
            fVar18 = fVar17;
          }
          local_3c = (float)fVar18;
          fVar18 = (float10)local_3c;
        }
        else {
          if (bVar4) {
            local_3c = (float)extraout_ST1_00;
          }
          if (fVar14 <= (float10)local_3c) {
            if (extraout_ST1_00 <= fVar17) {
              local_40 = (float)extraout_ST1_00;
              fVar17 = (float10)local_40;
            }
          }
          else {
            local_40 = (float)fVar20;
            fVar17 = (float10)local_40;
          }
          (&DAT_0087c52c)[iVar13] =
               (float)(((float10)(float)(&DAT_0087beb8)[iVar13] -
                       (float10)(float)(&DAT_0087ffb4)[iVar13]) * fVar17 +
                      (float10)(float)(&DAT_0087ffb4)[iVar13]);
          if (extraout_ST1_00 <= fVar17) {
            local_3c = (float)extraout_ST1_00;
            fVar18 = (float10)local_3c;
          }
          else {
            local_3c = (float)fVar17;
            fVar18 = (float10)local_3c;
          }
        }
        if (fVar14 <= fVar18) {
          if (extraout_ST1_00 <= fVar17) {
            local_40 = (float)extraout_ST1_00;
            fVar17 = (float10)local_40;
          }
          _DAT_00880418 = (float)((fVar15 - fVar16) * fVar17 + fVar16);
        }
        else {
          local_40 = (float)fVar20;
          fVar17 = (float10)local_40;
          _DAT_00880418 = (float)((fVar15 - fVar16) * fVar17 + fVar16);
        }
      }
    }
    fVar18 = extraout_ST1_00;
    if (iVar10 != -1) {
      bVar4 = fVar17 < extraout_ST1_00;
      if (iVar9 == 1) {
        fVar19 = extraout_ST1_00;
        if (bVar4) {
          fVar19 = fVar17;
        }
        local_3c = (float)fVar19;
        if (fVar14 <= (float10)local_3c) {
          if (extraout_ST1_00 <= fVar17) {
            local_40 = (float)extraout_ST1_00;
            fVar17 = (float10)local_40;
          }
        }
        else {
          local_40 = (float)fVar20;
          fVar17 = (float10)local_40;
        }
        (&DAT_0087c52c)[iVar10] =
             (float)(((float10)(float)(&DAT_0087ffb4)[iVar10] -
                     (float10)(float)(&DAT_0087beb8)[iVar10]) * fVar17 +
                    (float10)(float)(&DAT_0087beb8)[iVar10]);
        if (extraout_ST1_00 <= fVar17) {
          local_3c = (float)extraout_ST1_00;
          fVar19 = (float10)local_3c;
        }
        else {
          local_3c = (float)fVar17;
          fVar19 = (float10)local_3c;
        }
      }
      else {
        if (iVar9 == -1) {
          fVar19 = extraout_ST1_00;
          if (bVar4) {
            fVar19 = fVar17;
          }
          local_3c = (float)fVar19;
          if (fVar14 <= (float10)local_3c) {
            if (extraout_ST1_00 <= fVar17) {
              local_40 = (float)extraout_ST1_00;
              fVar17 = (float10)local_40;
            }
          }
          else {
            local_40 = (float)fVar20;
            fVar17 = (float10)local_40;
          }
          (&DAT_0087c52c)[iVar10] =
               (float)(((float10)(float)(&DAT_0087beb8)[iVar10] -
                       (float10)(float)(&DAT_0087ffb4)[iVar10]) * fVar17 +
                      (float10)(float)(&DAT_0087ffb4)[iVar10]);
          fVar19 = extraout_ST1_00;
          if (fVar17 < extraout_ST1_00) {
            fVar19 = fVar17;
          }
          local_3c = (float)fVar19;
          if (fVar14 <= (float10)local_3c) {
            if (extraout_ST1_00 <= fVar17) {
              local_40 = (float)extraout_ST1_00;
              fVar17 = (float10)local_40;
            }
          }
          else {
            local_40 = (float)fVar20;
            fVar17 = (float10)local_40;
          }
          _DAT_00880414 = (float)(fVar17 * (fVar15 - fVar16) + fVar16);
          goto LAB_004c4d98;
        }
        fVar19 = extraout_ST1_00;
        if (bVar4) {
          fVar19 = fVar17;
        }
        local_3c = (float)fVar19;
        if (fVar14 <= (float10)local_3c) {
          if (extraout_ST1_00 <= fVar17) {
            local_40 = (float)extraout_ST1_00;
            fVar17 = (float10)local_40;
          }
        }
        else {
          local_40 = (float)fVar20;
          fVar17 = (float10)local_40;
        }
        (&DAT_0087c52c)[iVar10] =
             (float)(((float10)(float)(&DAT_0087ffb4)[iVar10] -
                     (float10)(float)(&DAT_0087beb8)[iVar10]) * fVar17 +
                    (float10)(float)(&DAT_0087beb8)[iVar10]);
        fVar19 = extraout_ST1_00;
        if (fVar17 < extraout_ST1_00) {
          fVar19 = fVar17;
        }
        local_3c = (float)fVar19;
        fVar19 = (float10)local_3c;
      }
      if (fVar14 <= fVar19) {
        if (extraout_ST1_00 <= fVar17) {
          local_40 = (float)extraout_ST1_00;
          fVar17 = (float10)local_40;
        }
      }
      else {
        local_40 = (float)fVar20;
        fVar17 = (float10)local_40;
      }
      _DAT_00880414 = (float)(fVar17 * (fVar16 - fVar15) + fVar15);
    }
  }
LAB_004c4d98:
  if ((DAT_00880494 != 0) && ((float10)_DAT_008800e4 < fVar20)) {
    _DAT_00880414 = (float)_DAT_007fcbc8;
    _DAT_008800e4 = 0.125;
    DAT_00880494 = 0;
    _DAT_0087bd78 = (float)fVar20;
    DAT_0087bbbc = 0xffffffff;
    DAT_00880490 = 0xffffffff;
    FUN_0054a3e0(PTR_DAT_008021b4,(float)fVar18,(float)fVar20,1);
    __security_check_cookie(local_4 ^ (uint)&local_40);
    return;
  }
  __security_check_cookie(local_4 ^ (uint)&local_40);
  return;
}

