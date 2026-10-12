/* Ghidra analysis pseudocode, not original source.
 * ev_f0b2ce2d5885583ae7420409f057ba3a395d2cbd12cd318b48692f86b50c0045
 * Entry: 0x6561d0; label: FUN_006561d0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006561d0(int param_1,undefined4 *param_2,undefined4 *param_3,int param_4,int param_5,
                 float param_6,undefined4 *param_7,undefined4 *param_8,undefined2 param_9,
                 undefined1 param_10)

{
  float fVar1;
  undefined4 uVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  short sVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  short *psVar11;
  int *piVar12;
  int iVar13;
  undefined4 *puVar14;
  int iVar15;
  int iVar16;
  bool bVar17;
  float10 fVar18;
  float10 extraout_ST0;
  float local_48;
  int local_44;
  uint local_34;
  short local_30;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  iVar15 = 0;
  if ((((DAT_02962050 == 0) && (DAT_008104b4 != 0)) && (param_1 != -1)) &&
     (((param_1 != 0 && (param_1 < DAT_02962098)) &&
      ((iVar3 = *(int *)(DAT_0296209c + param_1 * 4), iVar3 != 0 &&
       ((*(char *)(iVar3 + 0x13) == '\0' && (0 < param_5)))))))) {
    if (*(char *)(iVar3 + 0x2f1) != '\x04') {
      local_10 = *param_2;
      local_c = param_2[1];
      local_8 = param_2[2];
      local_18 = 0x3f800000;
      local_1c = 0x3f800000;
      local_20 = 0x3f800000;
      iVar8 = FUN_005d69a0(&local_10,&local_20,*(undefined4 *)(iVar3 + 0x38));
      if (iVar8 == 0) {
        return;
      }
    }
    fVar1 = _DAT_00810908;
    if ((DAT_029620b8 == 0) && (*(float *)(iVar3 + 0x2f4) < _DAT_00810908)) {
      fVar1 = *(float *)(iVar3 + 0x2f4);
    }
    fVar18 = (float10)FUN_0064fde0((float)param_5,fVar1);
    fVar18 = (float10)FUN_0064fde0(0x3f800000,(float)fVar18);
    fVar1 = (float)fVar18;
    if (param_7 == (undefined4 *)0x0) {
      param_7 = &DAT_00806680;
    }
    if (param_8 == (undefined4 *)0x0) {
      param_8 = &DAT_00806680;
    }
    bVar17 = *(char *)(iVar3 + 0x2f1) == '\x04';
    fVar6 = _DAT_0296205c;
    if (bVar17) {
      fVar6 = _DAT_02962060;
    }
    local_34 = (uint)bVar17;
    param_6 = fVar6 + param_6;
    FUN_0064fde0(fVar6,fVar1);
    iVar8 = FUN_006e6b90();
    iVar9 = 0;
    iVar10 = 0;
    fVar4 = fVar1 * (float)iVar8 + fVar1;
    fVar5 = fVar4;
    if (fVar4 < param_6 != (fVar4 == param_6)) {
      do {
        iVar10 = iVar10 + 1;
        if (99 < iVar10) break;
        fVar5 = fVar5 + fVar1;
        iVar9 = iVar9 + 1;
      } while (fVar5 < param_6 != (fVar5 == param_6));
      if (iVar9 != 0) {
        iVar9 = (*(char *)(iVar3 + 0x410) + 1) * iVar9;
        iVar10 = 0;
        local_44 = -1;
        psVar11 = (short *)(iVar3 + 0x3d0);
LAB_006563f2:
        iVar16 = iVar15;
        if (*psVar11 == -1) {
          if (DAT_029211e8 < DAT_02962094) {
            sVar7 = FUN_006550b0();
            *(short *)(iVar3 + 0x3d0 + iVar15 * 2) = sVar7;
            iVar10 = sVar7 * 0x330 + DAT_029620a4;
            *(undefined2 *)(iVar10 + 0x182) = (undefined2)param_1;
            *(undefined4 *)(iVar10 + 0x1d4) = 0;
            *(undefined **)(iVar10 + 0x1c0) = (&PTR_FUN_00810910)[*(char *)(iVar3 + 0x2c)];
            *(undefined4 *)(iVar10 + 0x1c4) =
                 *(undefined4 *)(&DAT_00810944 + *(char *)(iVar3 + 0x2d) * 4);
            puVar14 = (undefined4 *)(iVar10 + 0x40);
            for (iVar13 = 0x10; iVar13 != 0; iVar13 = iVar13 + -1) {
              *puVar14 = *param_8;
              param_8 = param_8 + 1;
              puVar14 = puVar14 + 1;
            }
            *(float *)(iVar10 + 0x70) = (float)extraout_ST0;
            *(float *)(iVar10 + 0x74) = (float)extraout_ST0;
            *(float *)(iVar10 + 0x78) = (float)extraout_ST0;
            FUN_00655940((int)*(short *)(iVar3 + 0x3d0 + iVar15 * 2),(float)extraout_ST0,
                         (float)extraout_ST0,(float)extraout_ST0);
            *(undefined2 *)(iVar10 + 0x328) = param_9;
            *(undefined1 *)(iVar10 + 0x2f8) = param_10;
LAB_0065650b:
            local_44 = iVar16;
            if (iVar10 == 0) {
              return;
            }
            if (*(char *)(iVar3 + 0x2e) == '\a') {
              iVar15 = iVar9 + *(short *)(iVar10 + 0x186);
              if (*(short *)(iVar10 + 0x180) * 0xc < iVar15) {
                if (*(short *)(iVar10 + 0x180) < 0) {
                  *(undefined2 *)(iVar10 + 0x180) = 0;
                }
                iVar15 = (iVar15 + 0xb) / 0xc;
                iVar16 = iVar15 - *(short *)(iVar10 + 0x180);
                if (DAT_008108ec <= DAT_02947d84 + iVar16) {
                  return;
                }
                if (0x20 < iVar15) {
                  return;
                }
                local_48 = (float)iVar16;
                if (0 < iVar16) {
                  do {
                    *(undefined4 *)(iVar10 + 0x100 + *(short *)(iVar10 + 0x180) * 4) =
                         *(undefined4 *)(DAT_029211fc + DAT_02947d84 * 4);
                    DAT_02947d84 = DAT_02947d84 + 1;
                    iVar13 = 0;
                    do {
                      iVar13 = iVar13 + 0xc0;
                      *(undefined4 *)
                       (*(int *)(iVar10 + 0x100 + *(short *)(iVar10 + 0x180) * 4) + -0x94 + iVar13)
                           = 0;
                      *(undefined4 *)
                       (*(int *)(iVar10 + 0x100 + *(short *)(iVar10 + 0x180) * 4) + -0x84 + iVar13)
                           = 0x47000000;
                      *(undefined4 *)
                       (*(int *)(iVar10 + 0x100 + *(short *)(iVar10 + 0x180) * 4) + -0x74 + iVar13)
                           = 0;
                      *(undefined4 *)
                       (*(int *)(iVar10 + 0x100 + *(short *)(iVar10 + 0x180) * 4) + -100 + iVar13) =
                           0x47000000;
                      *(undefined4 *)
                       (*(int *)(iVar10 + 0x100 + *(short *)(iVar10 + 0x180) * 4) + -0x54 + iVar13)
                           = 0;
                      *(undefined4 *)
                       (*(int *)(iVar10 + 0x100 + *(short *)(iVar10 + 0x180) * 4) + -0x44 + iVar13)
                           = 0x47000000;
                      *(undefined4 *)
                       (*(int *)(iVar10 + 0x100 + *(short *)(iVar10 + 0x180) * 4) + -0x34 + iVar13)
                           = 0;
                      *(undefined4 *)
                       (*(int *)(iVar10 + 0x100 + *(short *)(iVar10 + 0x180) * 4) + -0x24 + iVar13)
                           = 0x47000000;
                      *(undefined4 *)
                       (*(int *)(iVar10 + 0x100 + *(short *)(iVar10 + 0x180) * 4) + -0x14 + iVar13)
                           = 0;
                      *(undefined4 *)
                       (*(int *)(iVar10 + 0x100 + *(short *)(iVar10 + 0x180) * 4) + -4 + iVar13) =
                           0x47000000;
                      *(undefined4 *)
                       (*(int *)(iVar10 + 0x100 + *(short *)(iVar10 + 0x180) * 4) + 0xc + iVar13) =
                           0;
                      *(undefined4 *)
                       (*(int *)(iVar10 + 0x100 + *(short *)(iVar10 + 0x180) * 4) + 0x1c + iVar13) =
                           0x47000000;
                    } while (iVar13 < 0x180);
                    *(short *)(iVar10 + 0x180) = *(short *)(iVar10 + 0x180) + 1;
                    local_48 = (float)((int)local_48 + -1);
                  } while (local_48 != 0.0);
                }
                *(short *)(iVar10 + 0x180) = (short)iVar15;
                FUN_005ffea0(iVar10 + 0x100,iVar15);
                if (iVar15 == iVar16) {
                  iVar15 = 0;
                  piVar12 = DAT_02961fec;
                  if (0 < DAT_008108ec + DAT_008108e8) {
                    do {
                      if (*piVar12 == 0) goto LAB_00656994;
                      iVar15 = iVar15 + 1;
                      piVar12 = piVar12 + 0x19;
                    } while (iVar15 < DAT_008108ec + DAT_008108e8);
                  }
                }
              }
            }
            else {
              iVar15 = iVar9 + *(short *)(iVar10 + 0x186);
              if (*(short *)(iVar10 + 0x180) * 0x20 < iVar15) {
                if (*(short *)(iVar10 + 0x180) < 0) {
                  *(undefined2 *)(iVar10 + 0x180) = 0;
                }
                iVar15 = iVar15 + 0x1f;
                iVar15 = (int)(iVar15 + (iVar15 >> 0x1f & 0x1fU)) >> 5;
                iVar16 = iVar15 - *(short *)(iVar10 + 0x180);
                if (DAT_008108e8 <= DAT_02948e98 + iVar16) {
                  return;
                }
                if (0x20 < iVar15) {
                  return;
                }
                local_48 = (float)iVar16;
                if (0 < iVar16) {
                  do {
                    *(undefined4 *)(iVar10 + 0x100 + *(short *)(iVar10 + 0x180) * 4) =
                         *(undefined4 *)(DAT_02921200 + DAT_02948e98 * 4);
                    DAT_02948e98 = DAT_02948e98 + 1;
                    iVar13 = 0;
                    do {
                      iVar13 = iVar13 + 0x100;
                      *(undefined4 *)
                       (*(int *)(iVar10 + 0x100 + *(short *)(iVar10 + 0x180) * 4) + -0xd4 + iVar13)
                           = 0;
                      *(undefined4 *)
                       (*(int *)(iVar10 + 0x100 + *(short *)(iVar10 + 0x180) * 4) + -0xc4 + iVar13)
                           = 0x47000000;
                      *(undefined4 *)
                       (*(int *)(iVar10 + 0x100 + *(short *)(iVar10 + 0x180) * 4) + -0xb4 + iVar13)
                           = 0;
                      *(undefined4 *)
                       (*(int *)(iVar10 + 0x100 + *(short *)(iVar10 + 0x180) * 4) + -0xa4 + iVar13)
                           = 0x47000000;
                      *(undefined4 *)
                       (*(int *)(iVar10 + 0x100 + *(short *)(iVar10 + 0x180) * 4) + -0x94 + iVar13)
                           = 0;
                      *(undefined4 *)
                       (*(int *)(iVar10 + 0x100 + *(short *)(iVar10 + 0x180) * 4) + -0x84 + iVar13)
                           = 0x47000000;
                      *(undefined4 *)
                       (*(int *)(iVar10 + 0x100 + *(short *)(iVar10 + 0x180) * 4) + -0x74 + iVar13)
                           = 0;
                      *(undefined4 *)
                       (*(int *)(iVar10 + 0x100 + *(short *)(iVar10 + 0x180) * 4) + -100 + iVar13) =
                           0x47000000;
                      *(undefined4 *)
                       (*(int *)(iVar10 + 0x100 + *(short *)(iVar10 + 0x180) * 4) + -0x54 + iVar13)
                           = 0;
                      *(undefined4 *)
                       (*(int *)(iVar10 + 0x100 + *(short *)(iVar10 + 0x180) * 4) + -0x44 + iVar13)
                           = 0x47000000;
                      *(undefined4 *)
                       (*(int *)(iVar10 + 0x100 + *(short *)(iVar10 + 0x180) * 4) + -0x34 + iVar13)
                           = 0;
                      *(undefined4 *)
                       (*(int *)(iVar10 + 0x100 + *(short *)(iVar10 + 0x180) * 4) + -0x24 + iVar13)
                           = 0x47000000;
                      *(undefined4 *)
                       (*(int *)(iVar10 + 0x100 + *(short *)(iVar10 + 0x180) * 4) + -0x14 + iVar13)
                           = 0;
                      *(undefined4 *)
                       (*(int *)(iVar10 + 0x100 + *(short *)(iVar10 + 0x180) * 4) + -4 + iVar13) =
                           0x47000000;
                      *(undefined4 *)
                       (*(int *)(iVar10 + 0x100 + *(short *)(iVar10 + 0x180) * 4) + 0xc + iVar13) =
                           0;
                      *(undefined4 *)
                       (*(int *)(iVar10 + 0x100 + *(short *)(iVar10 + 0x180) * 4) + 0x1c + iVar13) =
                           0x47000000;
                    } while (iVar13 < 0x400);
                    *(short *)(iVar10 + 0x180) = *(short *)(iVar10 + 0x180) + 1;
                    local_48 = (float)((int)local_48 + -1);
                  } while (local_48 != 0.0);
                }
                *(short *)(iVar10 + 0x180) = (short)iVar15;
                FUN_005ffea0(iVar10 + 0x100,iVar15);
                if (iVar15 == iVar16) {
                  iVar15 = 0;
                  piVar12 = DAT_02961fec;
                  if (0 < DAT_008108ec + DAT_008108e8) {
                    do {
                      if (*piVar12 == 0) goto LAB_00656994;
                      iVar15 = iVar15 + 1;
                      piVar12 = piVar12 + 0x19;
                    } while (iVar15 < DAT_008108ec + DAT_008108e8);
                  }
                }
              }
            }
            goto LAB_006569e6;
          }
        }
        else {
          iVar13 = *psVar11 * 0x330;
          iVar10 = iVar13 + DAT_029620a4;
          iVar13 = *(short *)(iVar13 + 0x186 + DAT_029620a4) + iVar9;
          if (*(char *)(iVar3 + 0x2e) == '\a') {
            if (iVar13 < 0x181) goto LAB_0065650b;
          }
          else if (iVar13 < 0x401) goto LAB_0065650b;
        }
        iVar15 = iVar15 + 1;
        psVar11 = psVar11 + 1;
        iVar16 = local_44;
        if (7 < iVar15) goto LAB_0065650b;
        goto LAB_006563f2;
      }
    }
  }
  return;
LAB_00656994:
  DAT_02961fec[iVar15 * 0x19] = *(int *)(iVar10 + 0x100);
  DAT_02961fec[iVar15 * 0x19 + 1] = iVar3;
  DAT_02961fec[iVar15 * 0x19 + 2] = iVar10;
  *(undefined2 *)(DAT_02961fec + iVar15 * 0x19 + 0x18) = param_9;
  FUN_00654e00(DAT_02961fec + iVar15 * 0x19,&DAT_0292fd30 + *(char *)(iVar3 + 0x2f1));
LAB_006569e6:
  uVar2 = 0;
  local_30 = (short)iVar9;
  *(short *)(iVar10 + 0x186) = *(short *)(iVar10 + 0x186) + local_30;
  if (param_3 == (undefined4 *)0x0) {
    *(undefined4 *)(iVar10 + 0x1a8) = 0;
    *(undefined4 *)(iVar10 + 0x1ac) = 0;
  }
  else {
    *(undefined4 *)(iVar10 + 0x1a8) = *param_3;
    *(undefined4 *)(iVar10 + 0x1ac) = param_3[1];
    uVar2 = param_3[2];
  }
  *(undefined4 *)(iVar10 + 0x1b0) = uVar2;
  FUN_00655b30((int)*(short *)(iVar3 + 0x3d0 + local_44 * 2),param_7);
  iVar15 = 0;
  *(float *)(iVar10 + 0x324) = fVar1 * (float)iVar8;
  local_48 = fVar4;
  if (fVar4 < param_6 != (fVar4 == param_6)) {
    do {
      iVar15 = iVar15 + 1;
      if (99 < iVar15) break;
      if (param_4 == 0) {
        *(undefined4 *)(iVar10 + 0x19c) = *param_2;
        *(undefined4 *)(iVar10 + 0x1a0) = param_2[1];
        *(undefined4 *)(iVar10 + 0x1a4) = param_2[2];
      }
      else {
        FUN_005b3860(iVar10 + 0x19c,param_2,param_4,local_48 - param_6);
      }
      *(float *)(iVar10 + 0x1e0) = local_48;
      iVar8 = (**(code **)(iVar10 + 0x1c0))(iVar10,iVar3,local_48);
      if (((*(char *)(iVar3 + 0x2f0) != '\0') && (iVar15 == 1)) && (iVar8 != 0)) {
        FUN_00656080(iVar8,local_48,iVar3,iVar10,1);
      }
      local_48 = fVar1 + *(float *)(iVar10 + 0x324);
    } while (local_48 < param_6 != (local_48 == param_6));
  }
  FUN_00653940();
  if ((*(short *)(iVar10 + 0x188) < *(short *)(iVar10 + 0x180)) &&
     (iVar15 = (int)*(short *)(iVar10 + 0x188), iVar15 < *(short *)(iVar10 + 0x180))) {
    puVar14 = (undefined4 *)(iVar10 + 0x100 + iVar15 * 4);
    iVar8 = DAT_02947b70;
    do {
      if (iVar8 < (DAT_008108e8 + DAT_008108ec) * 2) {
        **(undefined4 **)(DAT_02923198 + iVar8 * 4) = *puVar14;
        *(float *)(*(int *)(DAT_02923198 + DAT_02947b70 * 4) + 4) =
             *(float *)(iVar3 + 0xa4) + fVar6 +
             (float)(int)*(char *)(iVar3 + 0x410) * *(float *)(iVar3 + 0x414);
        *(undefined4 *)(*(int *)(DAT_02923198 + DAT_02947b70 * 4) + 8) = 1;
        *(int *)(*(int *)(DAT_02923198 + DAT_02947b70 * 4) + 0xc) = iVar10;
        FUN_006551d0(*(undefined4 *)(DAT_02923198 + DAT_02947b70 * 4),&DAT_0292fbfc + local_34);
        DAT_02947b70 = DAT_02947b70 + 1;
        *(short *)(iVar10 + 0x188) = *(short *)(iVar10 + 0x188) + 1;
        iVar8 = DAT_02947b70;
      }
      iVar15 = iVar15 + 1;
      puVar14 = puVar14 + 1;
    } while (iVar15 < *(short *)(iVar10 + 0x180));
  }
  if (*(short *)(iVar10 + 0x188) == *(short *)(iVar10 + 0x180)) {
    piVar12 = (int *)(&DAT_0292fbfc)[local_34];
    if (piVar12 != (int *)0x0) {
      do {
        if (*piVar12 == *(int *)(iVar10 + 0xfc + *(short *)(iVar10 + 0x180) * 4)) {
          FUN_00655210(piVar12,&DAT_0292fbfc + local_34);
          piVar12[1] = (int)(*(float *)(iVar3 + 0xa4) + fVar6 +
                            (float)(int)*(char *)(iVar3 + 0x410) * *(float *)(iVar3 + 0x414));
          FUN_006551d0(piVar12,&DAT_0292fbfc + local_34);
          break;
        }
        piVar12 = (int *)piVar12[4];
      } while (piVar12 != (int *)0x0);
    }
  }
  *(undefined2 *)(iVar10 + 0x18e) = *(undefined2 *)(iVar10 + 0x186);
  *(undefined2 *)(iVar10 + 0x18c) = *(undefined2 *)(iVar10 + 0x180);
  DAT_02962058 = 0;
  return;
}

