/* Ghidra pseudocode, not original source.
 * ev_e29f926c447264a3e79b54e28a3bd4babd6a11bd163f218199d416ac4d0e9917
 * Entry: 0x424810; label: FUN_00424810
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00424810(void)

{
  char cVar1;
  bool bVar2;
  undefined *puVar3;
  short sVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  uint uVar9;
  int *piVar10;
  int iVar11;
  uint uVar12;
  uint *puVar13;
  int iVar14;
  undefined4 *puVar15;
  float10 fVar16;
  float local_9c;
  int local_98;
  int local_94;
  uint local_90;
  uint local_8c;
  uint local_88;
  uint local_84;
  undefined4 *local_80;
  uint local_7c;
  uint local_78;
  uint local_74;
  uint local_70;
  uint local_6c;
  uint local_68;
  int local_64;
  int local_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  int local_50 [2];
  undefined4 *local_48;
  uint local_44;
  
  iVar11 = 0;
  local_94 = 0;
  local_60 = 0;
  local_98 = DAT_00856980;
  local_88 = (uint)(DAT_00856980 == 0);
  FUN_004246f0(&local_80,&local_64);
  DAT_00856928 = 0;
  DAT_00856924 = 0;
  bVar2 = false;
  _DAT_00856920 = 0;
  puVar13 = &DAT_009253b8;
  DAT_0085691c = 0;
  _DAT_00856938 = 0;
  DAT_00856934 = 0;
  _DAT_00856874 = 0;
  DAT_00856870 = 0;
  do {
    uVar7 = 0;
    iVar6 = (&DAT_008568f0)[iVar11];
    local_50[iVar11] = 0;
    if (iVar6 == 1) {
      uVar7 = 0x3f800000;
    }
    (&DAT_008568c0)[iVar11] = uVar7;
    local_9c = _DAT_00925018 * 4.0;
    fVar16 = (float10)FUN_0054fad0((&DAT_00856964)[iVar11],uVar7,local_9c);
    (&DAT_00856964)[iVar11] = (float)fVar16;
    local_9c = _DAT_00925018 * 5.0;
    fVar16 = (float10)FUN_0054fad0((&DAT_00856974)[iVar11],0x3f800000,local_9c);
    (&DAT_00856974)[iVar11] = (float)fVar16;
    puVar3 = PTR_DAT_008021b4;
    if ((&DAT_0087b6c8)[iVar11] != '\0') {
      if ((DAT_008022c4 & *puVar13) == 0) {
        if ((DAT_008022c8 & *puVar13) != 0) {
          bVar2 = true;
        }
      }
      else {
        local_50[iVar11] = 1;
      }
    }
    puVar13 = puVar13 + 0x18;
    iVar11 = iVar11 + 1;
  } while ((int)puVar13 < 0x925478);
  if (((bVar2) && (DAT_008568f0 != 1)) && (DAT_008568f4 != 1)) {
    if (DAT_0093b338 == 0) {
      return 1;
    }
    if (DAT_0087b6c8 == '\0') {
      return 1;
    }
    if (DAT_0087b6c9 == '\0') {
      return 1;
    }
    if ((DAT_009253b8 & DAT_008022c8) != 0) {
      DAT_0087b6cc = DAT_0087b6cc == '\0';
    }
    if ((DAT_00925418 & DAT_008022c8) != 0) {
      DAT_0087b6cd = DAT_0087b6cd == '\0';
    }
    if ((DAT_0087b6cc != '\0') && (DAT_0087b6cd != '\0')) {
      return 1;
    }
  }
  else {
    if (((local_50[0] == 0) && (local_50[1] == 0)) ||
       ((local_64 != 1 || ((DAT_008568f0 == 1 || (DAT_008568f4 == 1)))))) {
      local_7c = 0;
      do {
        uVar8 = local_7c;
        if ((&DAT_0087b6c8)[local_7c] != '\0') {
          uVar9 = (&DAT_009253b4)[local_7c * 0x18] | (&DAT_009253bc)[local_7c * 0x18];
          uVar5 = (&DAT_009253c0)[local_7c * 0x18] | (&DAT_009253b8)[local_7c * 0x18];
          uVar12 = local_7c;
          if ((local_64 == 1) && ((&DAT_0087b6ca)[local_7c] != '\0')) {
            uVar12 = (uint)(local_7c == 0);
          }
          iVar11 = (&DAT_008568f0)[uVar12];
          if (((DAT_0080227c & uVar5) == 0) || (iVar11 == 1)) {
            if ((DAT_00802284 & uVar5) == 0) {
              iVar6 = iVar11;
              if ((DAT_00802280 & uVar5) == 0) {
                if ((local_50[local_7c] == 0) || ((DAT_008568f0 != 1 && (DAT_008568f4 != 1)))) {
                  if (iVar11 == 1) {
                    local_94 = 0x3dcccccd;
                  }
                  else {
                    local_94 = 0x3e800000;
                  }
                  puVar15 = (undefined4 *)(&DAT_00856984)[uVar12];
                  local_88 = *(uint *)(local_98 + 0x48 + (int)puVar15 * 4);
                  local_48 = puVar15 + uVar12 * 7;
                  local_84 = (uint)(ushort)(&DAT_0086e4ec)[(int)local_48];
                  local_70 = DAT_00802290 & uVar9;
                  local_6c = DAT_00802294 & uVar9;
                  local_8c = DAT_00802294 & uVar5;
                  local_74 = DAT_00802298 & uVar9;
                  local_90 = DAT_00802298 & uVar5;
                  local_78 = DAT_00802290 & uVar5;
                  local_68 = DAT_0080229c & uVar5;
                  local_9c = (float)(DAT_0080229c & uVar9);
                  if ((local_78 != 0) && (local_8c != 0)) {
                    local_8c = 0;
                    local_78 = 0;
                  }
                  if ((local_90 != 0) && (local_68 != 0)) {
                    local_68 = 0;
                    local_90 = 0;
                  }
                  if ((local_70 != 0) && (local_6c != 0)) {
                    local_6c = 0;
                    local_70 = 0;
                  }
                  if ((local_74 != 0) && (local_9c != 0.0)) {
                    local_9c = 0.0;
                    local_74 = 0;
                  }
                  local_80 = puVar15;
                  local_44 = local_84;
                  FUN_00509ca0(&local_70,&local_78,&DAT_0087b58c + local_7c * 4,
                               &DAT_0087b5b4 + local_7c,0x3dcccccd,_DAT_00925018);
                  FUN_00509ca0(&local_6c,&local_8c,&DAT_0087b584 + uVar8 * 4,&DAT_0087b6d0 + uVar8,
                               0x3dcccccd,_DAT_00925018);
                  FUN_00509ca0(&local_74,&local_90,&DAT_0087b5b8 + uVar8 * 4,&DAT_0087b5a4 + uVar8,
                               local_94,_DAT_00925018);
                  FUN_00509ca0(&local_9c,&local_68,&DAT_0087b570 + uVar8 * 4,&DAT_0087b56c + uVar8,
                               local_94,_DAT_00925018);
                  if ((&DAT_008568f0)[uVar12] == 1) {
                    iVar11 = *(int *)(&DAT_008569b0 + uVar12 * 4);
                    iVar6 = *(int *)(&DAT_008568b8 + uVar12 * 4);
                    if (local_90 == 0) {
                      if (local_68 == 0) {
                        if (local_78 == 0) {
                          if ((local_8c != 0) &&
                             (*(int *)(&DAT_008568b8 + uVar12 * 4) = iVar6 + -1, iVar6 + -1 == -1))
                          {
                            *(undefined4 *)(&DAT_008568b8 + uVar12 * 4) = 0x25;
                          }
                        }
                        else {
                          *(int *)(&DAT_008568b8 + uVar12 * 4) = iVar6 + 1;
                          if (iVar6 + 1 == 0x26) {
                            *(undefined4 *)(&DAT_008568b8 + uVar12 * 4) = 0;
                          }
                        }
                      }
                      else {
                        FUN_004f1ff0(&DAT_0086e500 + uVar12 * 0xe);
                        iVar14 = *(int *)(&DAT_008569b0 + uVar12 * 4);
                        if (iVar14 < 0xe) {
                          *(char *)((int)&DAT_0086e500 + iVar14 + uVar12 * 0x38) =
                               s_ABCDEFGHIJKLMNOPQRSTUVWXYZ__0123_007f37ec
                               [*(int *)(&DAT_008568b8 + uVar12 * 4)];
                          *(int *)(&DAT_008569b0 + uVar12 * 4) = iVar14 + 1;
                          uVar7 = FUN_004238d0();
                          *(undefined4 *)(&DAT_008568b8 + uVar12 * 4) = uVar7;
                        }
                      }
                    }
                    else if (0 < iVar11) {
                      *(char *)((int)&DAT_0086e500 + iVar11 + uVar12 * 0x38) =
                           s_ABCDEFGHIJKLMNOPQRSTUVWXYZ__0123_007f37ec[iVar6];
                      *(int *)(&DAT_008569b0 + uVar12 * 4) = iVar11 + -1;
                      uVar7 = FUN_004238d0();
                      *(undefined4 *)(&DAT_008568b8 + uVar12 * 4) = uVar7;
                    }
                    if ((*(int *)(&DAT_008569b0 + uVar12 * 4) != iVar11) ||
                       (*(int *)(&DAT_008568b8 + uVar12 * 4) != iVar6)) {
                      FUN_00547930(0x2f,0,0,0);
                      (&DAT_00856974)[uVar12] = 0x3fc00000;
                    }
                  }
                  else {
                    if ((local_70 == 0) || ((int)puVar15 < 1)) {
                      if ((local_6c != 0) && ((int)puVar15 < 8)) {
                        (&DAT_00856870)[uVar8] = 0x3f800000;
                      }
                    }
                    else {
                      (&DAT_00856934)[uVar8] = 0x3f800000;
                    }
                    if (local_74 == 0) {
                      if (local_9c != 0.0) {
                        (&DAT_0085691c)[uVar8] = 0x3f800000;
                      }
                    }
                    else {
                      (&DAT_00856924)[uVar8] = 0x3f800000;
                    }
                    uVar8 = local_84;
                    if (local_78 == 0) {
                      if (local_8c == 0) {
                        if (local_90 == 0) {
                          if (local_68 != 0) {
                            uVar8 = FUN_00592940(local_98,local_84,local_88,uVar12,puVar15);
                          }
                        }
                        else {
                          uVar8 = FUN_00592820(local_98,local_84,local_88,uVar12,puVar15);
                        }
                      }
                      else if ((int)puVar15 < 8) {
                        puVar15 = (undefined4 *)((int)puVar15 + 1);
                      }
                    }
                    else if (0 < (int)puVar15) {
                      puVar15 = (undefined4 *)((int)puVar15 + -1);
                    }
                    uVar5 = local_44;
                    (&DAT_0086e4ec)[(int)local_48] = (short)uVar8;
                    (&DAT_00856984)[uVar12] = puVar15;
                    if ((uVar8 != local_44) || (puVar15 != local_80)) {
                      FUN_00547930(0x2f,0,0,0);
                      (&DAT_0085692c)[uVar12] = 0;
                    }
                    if (uVar8 != uVar5) {
                      FUN_00423c30(local_98,uVar12);
                    }
                  }
                  goto LAB_0042523d;
                }
                do {
                  iVar14 = (iVar6 + 1) % 3;
                  iVar6 = 0;
                } while (iVar14 == 0);
              }
              else {
                do {
                  iVar14 = (iVar6 + 1) % 3;
                  iVar6 = 0;
                } while (iVar14 == 0);
                local_60 = 1;
              }
              FUN_00547930(0x30,0,0,0);
              if (iVar14 == -1) goto LAB_0042523d;
            }
            else {
              iVar14 = 1;
            }
            (&DAT_008568f0)[uVar12] = iVar14;
            if (iVar14 == 1) {
              iVar11 = uVar12 * 0x38;
              FUN_004f1f10(&DAT_0086e510 + iVar11,&DAT_0086e500 + uVar12 * 0xe);
              iVar6 = FUN_004f1ff0(&DAT_0086e500 + uVar12 * 0xe);
              if (iVar6 < 0xf) {
                *(undefined1 *)((int)&DAT_0086e500 + iVar11 + iVar6) = 0x20;
              }
              cVar1 = *(char *)((int)&DAT_0086e500 + iVar11 + *(int *)(&DAT_008569b0 + uVar12 * 4));
              iVar11 = 0;
              do {
                if (s_ABCDEFGHIJKLMNOPQRSTUVWXYZ__0123_007f37ec[iVar11] == cVar1) {
LAB_00424fa9:
                  if (iVar11 < 0x26) goto LAB_00424fb0;
                  break;
                }
                if (s_ABCDEFGHIJKLMNOPQRSTUVWXYZ__0123_007f37ec[iVar11 + 1] == cVar1) {
                  iVar11 = iVar11 + 1;
                  goto LAB_00424fa9;
                }
                iVar11 = iVar11 + 2;
              } while (iVar11 < 0x26);
              iVar11 = 0;
LAB_00424fb0:
              *(int *)(&DAT_008568b8 + uVar12 * 4) = iVar11;
              (&DAT_00856974)[uVar12] = 0x3f800000;
            }
            else if (iVar11 == 1) {
              if (local_60 == 0) {
                iVar6 = uVar12 * 0x38;
                *(char *)((int)&DAT_0086e500 + iVar6 + *(int *)(&DAT_008569b0 + uVar12 * 4)) =
                     s_ABCDEFGHIJKLMNOPQRSTUVWXYZ__0123_007f37ec
                     [*(int *)(&DAT_008568b8 + uVar12 * 4)];
                iVar11 = 0xe;
                if ((&DAT_0086e50e)[iVar6] == ' ') {
                  do {
                    iVar11 = iVar11 + -1;
                  } while (*(char *)(iVar11 + (int)(&DAT_0086e500 + uVar12 * 0xe)) == ' ');
                  if (-1 < iVar11) goto LAB_0042504f;
                  sVar4 = DAT_00880874;
                  if (uVar12 != 0) {
                    sVar4 = DAT_00880878;
                  }
                  FUN_004f1f10(&DAT_0086e500 + uVar12 * 0xe,
                               *(undefined4 *)(DAT_00926c20 + sVar4 * 4));
                  FUN_00423900(uVar12);
                }
                else {
LAB_0042504f:
                  *(undefined1 *)(iVar11 + 0x86e501 + iVar6) = 0;
                }
                puVar15 = &DAT_0086e500 + uVar12 * 0xe;
                iVar11 = FUN_004f3730(puVar15,puVar15,"Stranger");
                if (iVar11 == 0) goto LAB_0042509f;
              }
              else {
                puVar15 = &DAT_0086e500 + uVar12 * 0xe;
              }
              FUN_004f1f10(puVar15,&DAT_0086e510 + uVar12 * 0x38);
            }
LAB_0042509f:
            (&DAT_0086e520)[uVar12 * 0x38] = 1;
          }
          else {
            local_80 = &DAT_00856904 + uVar12 * 3;
            FUN_00681f40("ToggleChar",local_80);
            FUN_0054a8d0((&DAT_009253b0)[uVar8 * 0x18],1,0);
            iVar11 = 0;
            piVar10 = (int *)(local_98 + 0x48);
            do {
              if (0 < *piVar10) {
                do {
                  iVar6 = FUN_0054fa60();
                  iVar6 = iVar6 / ((int)(0xffff / (longlong)*piVar10) + 1);
                  iVar14 = (**(code **)(local_98 + 0x170))(piVar10[-9] + iVar6 * 0x28);
                } while (iVar14 == 0);
                (&DAT_0086e4ec)[iVar11 + uVar12 * 0x1c] = (short)iVar6;
              }
              iVar11 = iVar11 + 1;
              piVar10 = piVar10 + 1;
            } while (iVar11 < 9);
            FUN_00423c30(local_98,uVar12);
            uStack_5c = 0;
            uStack_58 = 0x3e570a3d;
            uStack_54 = 0;
            FUN_006e6b90();
            FUN_00423670();
            FUN_006e6b90();
            FUN_00423710();
            FUN_006e6b90();
            uVar7 = FUN_004237f0();
            FUN_005b3200(&uStack_5c,&uStack_5c,uVar7);
            FUN_005b37d0(&uStack_5c,&uStack_5c,local_80);
            FUN_0062c560(*(undefined4 *)(PTR_DAT_00802c54 + 0x134),0x7b,&uStack_5c);
            FUN_0062c560(*(undefined4 *)(PTR_DAT_00802c54 + 0x134),0x5c,&uStack_5c);
          }
        }
LAB_0042523d:
        local_7c = local_7c + 1;
        if (1 < (int)local_7c) {
          return 0;
        }
      } while( true );
    }
    local_94 = 1;
  }
  if (local_88 != 0) {
    return 1;
  }
  if (local_94 != 0) {
    (&DAT_0087b6ca)[(int)local_80] = (&DAT_0087b6ca)[(int)local_80] == '\0';
    FUN_0054a3e0(puVar3,0x3f800000,0,1);
    FUN_0054a8d0(**(undefined4 **)((&DAT_0093d7f0)[(int)local_80] + 0xca4),1,0);
  }
  return 0;
}

