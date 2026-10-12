/* Ghidra pseudocode, not original source.
 * ev_d7259de4d528e446adcf31e3fd20dda0be8e8c3eebc020039674bf2429a30a4e
 * Entry: 0x476da0; label: FUN_00476da0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00476da0(void)

{
  int *piVar1;
  ushort uVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  float *pfVar8;
  int *piVar9;
  uint uVar10;
  float10 fVar11;
  undefined4 uVar12;
  int local_4c;
  int local_48;
  uint local_3c;
  uint local_38;
  uint local_34;
  uint local_30;
  uint local_2c;
  uint local_28;
  uint local_24;
  int *local_20;
  uint local_1c;
  int local_18;
  int local_14;
  uint local_10;
  int local_c;
  int local_8;
  float local_4;
  
  uVar2 = *(ushort *)(DAT_00879afc * 0x9c + 0x7a + DAT_00951354);
  if ((uVar2 & 1) == 0) {
    piVar9 = &DAT_00855ea4;
  }
  else if ((uVar2 & 4) == 0) {
    piVar9 = &DAT_00855ed0;
  }
  else {
    piVar9 = &DAT_00855f24;
  }
  if (0.0 < DAT_00879b0c) {
    DAT_00879b0c = DAT_00879b0c - _DAT_00925018;
  }
  if (0.0 < DAT_00879b10) {
    DAT_00879b10 = DAT_00879b10 - _DAT_00925018;
  }
  FUN_00476ba0();
  switch(DAT_00879564) {
  case 0:
    DAT_00879540 = DAT_00879540 + _DAT_00925018;
    if (_DAT_00879504 < DAT_00879540 != (_DAT_00879504 == DAT_00879540)) {
      DAT_00879540 = 0.0;
      DAT_00879564 = 1;
      _DAT_00879504 = 0.0;
      iVar5 = 0;
      do {
        iVar4 = FUN_00594250((int)(&DAT_0087b6c4)[iVar5],*piVar9,*(undefined2 *)((int)piVar9 + 6));
        (&DAT_0087958c)[iVar5] = iVar4;
        if (((iVar4 == -1) && ((&DAT_0087958c)[iVar5] = iVar5, iVar5 == 1)) && (DAT_0087958c == 1))
        {
          _DAT_00879590 = 0;
        }
        (&DAT_0087955c)[iVar5] = 0;
        iVar5 = iVar5 + 1;
      } while (iVar5 < 2);
    }
    break;
  case 1:
    local_4 = 0.0;
    local_14 = 0;
    local_18 = 0;
    local_4c = 0;
    local_1c = 0xffffffff;
    local_20 = &DAT_009253b0;
    do {
      uVar6 = local_1c & 1;
      iVar5 = (&DAT_0087958c)[local_4c];
      local_c = 0;
      local_8 = 0;
      if ((&DAT_0087b6c8)[local_4c] != '\0') {
        local_48 = iVar5;
        if ((DAT_008022c4 & *(uint *)(*local_20 + 0x78)) == 0) {
          if ((DAT_008022c8 & *(uint *)(*local_20 + 0x78)) == 0) {
            if ((&DAT_0087955c)[local_4c] == 0) {
              local_10 = local_20[3] | local_20[1];
              local_24 = local_20[4] | local_20[2];
              local_38 = DAT_00802294 & local_10;
              local_3c = DAT_00802290 & local_10;
              local_34 = DAT_00802298 & local_10;
              local_10 = DAT_0080229c & local_10;
              local_30 = DAT_00802290 & local_24;
              local_2c = DAT_00802294 & local_24;
              local_28 = DAT_00802298 & local_24;
              local_24 = DAT_0080229c & local_24;
              if ((local_30 != 0) && (local_2c != 0)) {
                local_2c = 0;
                local_30 = 0;
              }
              if ((local_28 != 0) && (local_24 != 0)) {
                local_24 = 0;
                local_28 = 0;
              }
              if ((local_3c != 0) && (local_38 != 0)) {
                local_38 = 0;
                local_3c = 0;
              }
              if ((local_34 != 0) && (local_10 != 0)) {
                local_10 = 0;
                local_34 = 0;
              }
              FUN_00509ca0(&local_3c,&local_30,&DAT_0087b58c + local_4c * 4,&DAT_0087b5b4 + local_4c
                           ,0x3dcccccd,_DAT_00925018);
              FUN_00509ca0(&local_38,&local_2c,&DAT_0087b584 + local_4c * 4,&DAT_0087b6d0 + local_4c
                           ,0x3dcccccd,_DAT_00925018);
              FUN_00509ca0(&local_34,&local_28,&DAT_0087b5b8 + local_4c * 4,&DAT_0087b5a4 + local_4c
                           ,0x3dcccccd,_DAT_00925018);
              FUN_00509ca0(&local_10,&local_24,&DAT_0087b570 + local_4c * 4,&DAT_0087b56d + local_1c
                           ,0x3dcccccd,_DAT_00925018);
              if (local_30 == 0) {
                if (local_2c == 0) {
                  if (local_28 == 0) {
                    if (local_24 != 0) {
                      uVar10 = (uint)*(ushort *)(piVar9 + 1);
                      do {
                        iVar4 = local_48 % (int)uVar10 + 1;
                        if ((int)uVar10 <= iVar4) {
                          iVar4 = iVar4 - uVar10;
                        }
                        iVar7 = (local_48 / (int)uVar10) * uVar10;
                        local_48 = iVar7 + iVar4;
                        if ((int)(uint)*(ushort *)((int)piVar9 + 6) <= local_48) {
                          local_48 = iVar7;
                        }
                      } while (*(short *)(*piVar9 + local_48 * 0x1c) == (&DAT_0087b6c4)[uVar6]);
                    }
                  }
                  else {
                    uVar10 = (uint)*(ushort *)(piVar9 + 1);
                    do {
                      iVar4 = local_48 % (int)uVar10 + -1;
                      if (iVar4 < 0) {
                        iVar4 = iVar4 + uVar10;
                      }
                      local_48 = (local_48 / (int)uVar10) * uVar10 + iVar4;
                      if ((int)(uint)*(ushort *)((int)piVar9 + 6) <= local_48) {
                        local_48 = *(ushort *)((int)piVar9 + 6) - 1;
                      }
                    } while (*(short *)(*piVar9 + local_48 * 0x1c) == (&DAT_0087b6c4)[uVar6]);
                  }
                }
                else {
                  uVar10 = (uint)*(ushort *)(piVar9 + 1);
                  do {
                    local_48 = local_48 + uVar10;
                    if ((int)(uint)*(ushort *)((int)piVar9 + 6) <= local_48) {
                      iVar4 = ((int)((ulonglong)*(ushort *)((int)piVar9 + 6) /
                                    (ulonglong)(longlong)(int)uVar10) + 1) * uVar10;
                      if (local_48 < iVar4) {
                        local_48 = local_48 + uVar10;
                      }
                      local_48 = local_48 - iVar4;
                    }
                  } while (*(short *)(*piVar9 + local_48 * 0x1c) == (&DAT_0087b6c4)[uVar6]);
                }
              }
              else {
                local_48 = FUN_00476c80(0,iVar5);
              }
            }
          }
          else {
            local_8 = 1;
          }
        }
        else {
          local_c = 1;
        }
        iVar4 = (&DAT_0087955c)[local_4c];
        piVar1 = &DAT_0087955c + local_4c;
        local_18 = local_18 + 1;
        if (1 < iVar4) {
          local_14 = local_14 + 1;
        }
        if (local_c != 0) {
          if (iVar4 == 0) {
            if ((&DAT_00879b0c)[local_4c] <= 0.0) {
              iVar4 = FUN_00594960((int)*(short *)(*piVar9 + (&DAT_0087958c)[local_4c] * 0x1c));
              fVar3 = _DAT_007fa1cc;
              if (iVar4 == 0) {
                uVar12 = 0x32;
              }
              else {
                *piVar1 = 1;
                (&DAT_00879b0c)[local_4c] = fVar3;
                uVar12 = 0x30;
              }
              goto LAB_004772ea;
            }
          }
          else if ((iVar4 == 1) && ((&DAT_00879b0c)[local_4c] <= 0.0)) {
            *piVar1 = 2;
            uVar12 = 0x30;
LAB_004772ea:
            FUN_00547930(uVar12,0,0,0);
          }
        }
        if (local_8 != 0) {
          iVar4 = *piVar1;
          if (iVar4 == 0) {
            if ((&DAT_00879b0c)[local_4c] <= 0.0) {
              local_4 = 1.4013e-45;
            }
          }
          else if (iVar4 == 1) {
            if ((&DAT_00879b0c)[local_4c] <= 0.0) {
              (&DAT_00879538)[local_4c] = 0;
              *piVar1 = 0;
              (&DAT_00879b0c)[local_4c] = _DAT_007fa1cc;
              goto LAB_00477322;
            }
          }
          else if (((iVar4 == 2) && ((&DAT_0087b6c8)[uVar6] != '\0')) &&
                  ((int)(&DAT_0087955c)[uVar6] < 2)) {
            *piVar1 = 1;
LAB_00477322:
            FUN_00547930(0x31,0,0,0);
          }
        }
        if (local_48 != iVar5) {
          (&DAT_0087958c)[local_4c] = local_48;
          (&DAT_0087b6c4)[local_4c] = *(undefined2 *)(*piVar9 + local_48 * 0x1c);
          FUN_00547930(0x2f,0,0,0);
          (&DAT_00879538)[local_4c] = 0;
        }
      }
      local_20 = local_20 + 0x18;
      local_4c = local_4c + 1;
      local_1c = local_1c + 1;
    } while ((int)local_20 < 0x925470);
    if (local_14 == local_18) {
      if (DAT_00951b50 == 0) {
        FUN_00476840((int)DAT_0087b6c4);
      }
      else {
        iVar5 = FUN_00476a50();
        if (iVar5 == 0) break;
      }
      DAT_00879564 = 3;
      DAT_00879540 = 0.0;
      _DAT_00879504 = 1.0;
    }
    else if (local_4 != 0.0) {
      DAT_00879540 = 0.0;
      _DAT_00879504 = 0.6;
      DAT_00879564 = 2;
      DAT_00879598 = 0;
      FUN_00547930(0x31,0,0,0);
    }
    break;
  case 2:
    DAT_00879540 = DAT_00879540 + _DAT_00925018;
    if (_DAT_00879504 < DAT_00879540 != (_DAT_00879504 == DAT_00879540)) {
      FUN_00474fd0();
    }
    break;
  case 3:
    DAT_00879540 = DAT_00879540 + _DAT_00925018;
    if (_DAT_00879504 < DAT_00879540 != (_DAT_00879504 == DAT_00879540)) {
      DAT_00879564 = 4;
      DAT_00879540 = 0.0;
      _DAT_00879504 = 1.5;
    }
    break;
  case 4:
    DAT_00879540 = DAT_00879540 + _DAT_00925018;
    if (_DAT_00879504 < DAT_00879540 != (_DAT_00879504 == DAT_00879540)) {
      DAT_00951b80 = DAT_00879588 * 0x130 + DAT_00951b78;
      DAT_00855f7c = 1;
      DAT_0093b29c = 1;
      DAT_0093b2a4 = 1;
      DAT_00951b80 = FUN_005735a0((int)*(short *)(DAT_00951b80 + 0x62));
      _DAT_00950780 = 0x3f800000;
      DAT_0087b2c0 = 1;
      DAT_00802e14 = 0;
      if (DAT_008795a4 == 0) {
        if (DAT_0087951c == 2) {
          FUN_0042b4c0((int)*(char *)(DAT_00951b80 + 0xa3));
        }
      }
      else if ((DAT_008795a4 == 1) && (DAT_0087950c != 0)) {
        DAT_0093b324 = 1;
        DAT_00879544 = 0;
        DAT_00879548 = 0;
      }
    }
  }
  pfVar8 = (float *)&DAT_00879538;
  do {
    if (DAT_00879564 == 1) {
      local_4 = _DAT_00925018 + _DAT_00925018;
      fVar11 = (float10)FUN_0054fad0(*pfVar8,0x3f800000,local_4);
    }
    else {
      fVar11 = (float10)0;
    }
    *pfVar8 = (float)fVar11;
    pfVar8 = pfVar8 + 1;
  } while ((int)pfVar8 < 0x879540);
  return;
}

