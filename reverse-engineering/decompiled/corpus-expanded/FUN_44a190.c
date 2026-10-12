/* Ghidra pseudocode, not original source.
 * ev_899eb35a27e8c18144a9bface4dcd684320477ea32232f25bcb19f5ddc9c569a
 * Entry: 0x44a190; label: FUN_0044a190
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0044a190(undefined4 param_1,int param_2,float param_3,int param_4,int param_5,int param_6)

{
  char cVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  float10 fVar8;
  int local_16c;
  undefined2 local_168 [2];
  int local_164;
  float local_160;
  int local_15c;
  undefined4 local_158;
  int local_154;
  undefined4 local_150;
  undefined4 local_14c;
  undefined4 local_148;
  int local_144;
  int local_140;
  int local_13c;
  int local_138;
  float local_134;
  float local_130;
  uint local_12c;
  float local_128;
  undefined4 local_124;
  int local_120;
  undefined4 local_11c;
  undefined4 local_118;
  float local_114;
  float local_110;
  float local_10c;
  undefined1 local_108 [4];
  undefined1 local_104 [12];
  undefined4 local_f8 [8];
  int aiStack_d8 [32];
  short asStack_58 [10];
  char local_44 [64];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_16c;
  local_124 = param_1;
  local_160 = param_3;
  local_140 = -1;
  local_138 = -1;
  local_154 = 1;
  local_164 = 0;
  local_15c = 0;
  local_158 = 0;
  local_120 = 0;
  builtin_strncpy(local_44,"default",8);
  _memset(local_44 + 8,0,0x38);
  local_134 = 0.0;
  local_130 = 1e+09;
  local_13c = 0;
  local_128 = 1e+09;
  local_16c = 0;
  local_12c = 0;
  local_144 = 0;
  local_114 = 0.0;
  local_110 = 0.0;
  local_10c = 0.0;
  if (param_6 == 0) {
    __security_check_cookie(local_4 ^ (uint)&local_16c);
    return;
  }
  iVar5 = 0;
  if (0 < param_5) {
    do {
      iVar3 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar5 * 4),"mingroupsize");
      if (iVar3 == 0) {
        iVar3 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar5 * 4),"maxgroupsize");
        if (iVar3 == 0) {
          iVar3 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar5 * 4),"groupsize");
          if (iVar3 == 0) {
            iVar3 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar5 * 4),&DAT_0075772c);
            if (iVar3 == 0) {
              iVar3 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar5 * 4),"script");
              if (iVar3 == 0) {
                iVar3 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar5 * 4),"mindistance");
                if (iVar3 == 0) {
                  iVar3 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar5 * 4),"maxdistance");
                  if (iVar3 == 0) {
                    iVar3 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar5 * 4),"distance");
                    if (iVar3 == 0) {
                      if ((DAT_00876d94 == 0) ||
                         (iVar3 = FUN_004f8b10("use_selected_spline",
                                               *(undefined4 *)(param_4 + iVar5 * 4)), iVar3 != 0)) {
                        iVar3 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar5 * 4),"splines=");
                        if (iVar3 == 0) {
                          iVar3 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar5 * 4),
                                               "spline=myspline");
                          if (iVar3 == 0) {
                            iVar3 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar5 * 4),"spline=");
                            if (iVar3 == 0) {
                              iVar3 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar5 * 4),"x_offset=")
                              ;
                              if (iVar3 == 0) {
                                iVar3 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar5 * 4),
                                                     "y_offset=");
                                if (iVar3 == 0) {
                                  iVar3 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar5 * 4),
                                                       "z_offset=");
                                  if (iVar3 == 0) {
                                    iVar3 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar5 * 4),
                                                         "looping");
                                    if (iVar3 == 0) {
                                      local_158 = 1;
                                    }
                                    else {
                                      iVar3 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar5 * 4),
                                                           "addtoset=myset");
                                      if (iVar3 == 0) {
                                        iVar3 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar5 * 4),
                                                             "addtoset=");
                                        if (iVar3 == 0) {
                                          iVar3 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar5 * 4),
                                                               "relative_to_player");
                                          if (iVar3 == 0) {
                                            local_120 = 1;
                                          }
                                          else {
                                            iVar3 = FUN_004f8a70(*(undefined4 *)
                                                                  (param_4 + iVar5 * 4),
                                                                 "relative_to_locator=");
                                            if (iVar3 == 0) {
                                              iVar3 = FUN_004f8a70(*(undefined4 *)
                                                                    (param_4 + iVar5 * 4),
                                                                   "ridden_by=myself");
                                              if (iVar3 == 0) {
                                                iVar3 = FUN_004f8a70(*(undefined4 *)
                                                                      (param_4 + iVar5 * 4),
                                                                     "ridden_by=");
                                                if (iVar3 != 0) {
                                                  local_13c = FUN_00440120(local_124,iVar3 + 10);
                                                }
                                              }
                                              else if ((local_160 != 0.0) &&
                                                      (*(int **)((int)local_160 + 0xd0) !=
                                                       (int *)0x0)) {
                                                local_13c = **(int **)((int)local_160 + 0xd0);
                                              }
                                            }
                                            else {
                                              local_144 = FUN_0051ac10(local_124,iVar3 + 0x14);
                                            }
                                          }
                                        }
                                        else {
                                          FUN_005147c0(param_2,iVar3 + 9);
                                          local_12c = FUN_006e6b90();
                                        }
                                      }
                                      else {
                                        local_12c = (uint)*(byte *)(param_2 + 0xb0);
                                      }
                                    }
                                  }
                                  else {
                                    fVar8 = (float10)FUN_005147c0(param_2,iVar3 + 9);
                                    local_10c = (float)fVar8;
                                  }
                                }
                                else {
                                  fVar8 = (float10)FUN_005147c0(param_2,iVar3 + 9);
                                  local_110 = (float)fVar8;
                                }
                              }
                              else {
                                fVar8 = (float10)FUN_005147c0(param_2,iVar3 + 9);
                                local_114 = (float)fVar8;
                              }
                            }
                            else {
                              iVar3 = FUN_005d0690(*(undefined4 *)(PTR_DAT_00802c54 + 0x13c),
                                                   iVar3 + 7);
                              if ((iVar3 != 0) && (local_16c < 0x20)) {
                                aiStack_d8[local_16c] = iVar3;
                                local_16c = local_16c + 1;
                              }
                            }
                          }
                          else if (*(int *)(param_2 + 0xac) != 0) {
                            aiStack_d8[local_16c] = *(int *)(param_2 + 0xac);
                            local_16c = local_16c + 1;
                          }
                        }
                        else {
                          iVar3 = FUN_005d0740(*(undefined4 *)(PTR_DAT_00802c54 + 0x13c),iVar3 + 8,
                                               aiStack_d8 + local_16c,0x20 - local_16c);
                          local_16c = local_16c + iVar3;
                        }
                      }
                      else {
                        local_15c = 1;
                      }
                    }
                    else {
                      fVar8 = (float10)FUN_005147c0(param_2,iVar3 + 9);
                      local_134 = (float)fVar8;
                    }
                  }
                  else {
                    fVar8 = (float10)FUN_005147c0(param_2,iVar3 + 0xc);
                    local_128 = (float)fVar8;
                  }
                }
                else {
                  fVar8 = (float10)FUN_005147c0(param_2,iVar3 + 0xc);
                  local_130 = (float)fVar8;
                }
              }
              else {
                FUN_004f1f10(local_44,iVar3 + 7);
              }
            }
            else if ((((DAT_00923884 != (code *)0x0) && (DAT_00923894 != (code *)0x0)) &&
                     (cVar1 = (*DAT_00923884)(iVar3 + 5), cVar1 != -1)) &&
                    ((sVar2 = (*DAT_00923894)(cVar1), sVar2 != -1 && (local_164 < 10)))) {
              asStack_58[local_164] = sVar2;
              local_164 = local_164 + 1;
            }
          }
          else {
            FUN_005147c0(param_2,iVar3 + 10);
            local_154 = FUN_006e6b90();
          }
        }
        else {
          FUN_005147c0(param_2,iVar3 + 0xd);
          local_138 = FUN_006e6b90();
        }
      }
      else {
        FUN_005147c0(param_2,iVar3 + 0xd);
        local_140 = FUN_006e6b90();
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < param_5);
    if ((-1 < local_140) && (local_140 < local_138)) {
      iVar5 = FUN_005b9e90(0);
      local_154 = iVar5 % ((local_138 - local_140) + 1) + local_140;
    }
  }
  if ((local_130 != 1e+09) && (local_128 != 1e+09)) {
    fVar8 = (float10)FUN_005b9dd0();
    local_160 = (float)fVar8;
    local_134 = (1.0 - local_160) * local_130 + local_128 * local_160;
  }
  if ((((local_15c != 0) || (local_16c != 0)) && (local_164 != 0)) && (0 < local_154)) {
    iVar5 = DAT_00876d94;
    if (local_15c == 0) {
      iVar5 = FUN_0054fa60();
      iVar5 = aiStack_d8[iVar5 / ((int)(0xffff / (longlong)local_16c) + 1)];
    }
    iVar3 = FUN_005b9e90(0);
    if (0 < local_154) {
      local_160 = (float)(int)asStack_58[iVar3 % local_164];
      local_15c = local_154;
      do {
        iVar4 = FUN_0043d890(local_160,0,0,local_44,0,0,0,iVar5,&local_114,local_158,local_12c);
        iVar3 = local_120;
        if (iVar4 != 0) {
          if ((local_120 != 0) || (local_144 != 0)) {
            local_11c = 0xffffffff;
            local_118 = 0xffffffff;
            if (*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_0087b0a0) {
              FUN_004dca00(iVar5,&local_11c,&local_118);
            }
            if (iVar3 == 0) {
              if (local_144 == 0) goto LAB_0044a89c;
              iVar3 = local_144 + 0x10;
            }
            else {
              iVar3 = DAT_0093d810 + 0x80;
            }
            FUN_00551c40(iVar3,local_f8,iVar5,local_158,local_11c,local_118);
            puVar6 = local_f8;
            puVar7 = (undefined4 *)(iVar4 + 0xe64);
            for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
              *puVar7 = *puVar6;
              puVar6 = puVar6 + 1;
              puVar7 = puVar7 + 1;
            }
          }
LAB_0044a89c:
          if (local_134 != 0.0) {
            FUN_005518a0((undefined4 *)(iVar4 + 0xe64),local_134);
            FUN_00550a20(*(undefined4 *)(iVar4 + 0xe64),*(undefined4 *)(iVar4 + 0xe80),&local_150,
                         local_168,local_108,(int)*(char *)(iVar4 + 0xe6a));
            *(undefined2 *)(iVar4 + 0x5a) = local_168[0];
            *(undefined2 *)(iVar4 + 0x58) = local_168[0];
            *(undefined2 *)(iVar4 + 0x27a) = local_168[0];
            *(short *)(iVar4 + 0x278) = -local_108._0_2_;
            if (((*(float *)(iVar4 + 0xe84) != 0.0) || (*(float *)(iVar4 + 0xe88) != 0.0)) ||
               (*(float *)(iVar4 + 0xe8c) != 0.0)) {
              FUN_005b35a0(local_104,iVar4 + 0xe84,-local_108._0_2_);
              FUN_005b3620(local_104,local_104,*(undefined2 *)(iVar4 + 0x27a));
              FUN_005b37d0(&local_150,&local_150,local_104);
            }
            *(undefined4 *)(iVar4 + 0x5c) = local_150;
            *(undefined4 *)(iVar4 + 0x60) = local_14c;
            *(undefined4 *)(iVar4 + 100) = local_148;
            *(undefined4 *)(iVar4 + 0x98) = local_150;
            *(undefined4 *)(iVar4 + 0x9c) = local_14c;
            *(undefined4 *)(iVar4 + 0xa0) = local_148;
            *(undefined4 *)(iVar4 + 0x80) = local_150;
            *(undefined4 *)(iVar4 + 0x84) = local_14c;
            *(undefined4 *)(iVar4 + 0x88) = local_148;
            DAT_0093d624 = local_14c;
            _DAT_0093d620 = local_150;
            DAT_0093d628 = local_148;
            *(undefined4 *)(iVar4 + 0x8c) = local_150;
            *(undefined4 *)(iVar4 + 0x90) = DAT_0093d624;
            *(undefined4 *)(iVar4 + 0x94) = DAT_0093d628;
            FUN_0055d2b0(iVar4);
            *(undefined4 *)(iVar4 + 0x1b4) = *(undefined4 *)(iVar4 + 0x5c);
            *(undefined4 *)(iVar4 + 0x10bc) = *(undefined4 *)(iVar4 + 0x5c);
            *(undefined4 *)(iVar4 + 0x1b8) = *(undefined4 *)(iVar4 + 0x60);
            *(undefined4 *)(iVar4 + 0x10c0) = *(undefined4 *)(iVar4 + 0x60);
            *(undefined4 *)(iVar4 + 0x1bc) = *(undefined4 *)(iVar4 + 100);
            *(undefined4 *)(iVar4 + 0x10c4) = *(undefined4 *)(iVar4 + 100);
          }
          if (local_13c != 0) {
            FUN_00488730(local_13c,iVar4,0,1);
          }
        }
        local_15c = local_15c + -1;
      } while (local_15c != 0);
    }
  }
  __security_check_cookie(local_4 ^ (uint)&local_16c);
  return;
}

