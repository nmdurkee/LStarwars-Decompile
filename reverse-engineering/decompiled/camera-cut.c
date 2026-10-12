/* Ghidra pseudocode; not original source. ev_4e96dd5d3ce0e9409c65e7feb28b257dbc14d95b09cc41eb7e967f91619c9d86 */

undefined4
FUN_004509d0(undefined4 param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  float *pfVar4;
  int iVar5;
  int iVar6;
  float10 fVar7;
  float local_64;
  int local_60;
  int local_5c;
  int local_54;
  float local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  undefined1 local_c [12];
  
  local_34 = 0.0;
  iVar5 = 0;
  local_64 = 1e+09;
  local_24 = 1e+09;
  local_20 = 1e+09;
  local_1c = 1e+09;
  local_40 = 0;
  local_30 = 1e+09;
  bVar1 = false;
  local_2c = 1e+09;
  local_44 = 1;
  local_28 = 1e+09;
  local_60 = 0;
  local_5c = 0;
  local_54 = 0;
  local_38 = 0.0;
  local_48 = 0;
  local_3c = 0.0;
  local_4c = 0;
  local_18 = 0.0;
  local_14 = 0.0;
  local_10 = 0.0;
  local_50 = 1.0;
  if (param_6 == 0) {
    return 1;
  }
  iVar6 = 0;
  if (param_5 < 1) {
LAB_00450fee:
    if (local_24 == 1e+09) {
      return 1;
    }
    if (local_20 == 1e+09) {
      return 1;
    }
    if (local_1c == 1e+09) {
      return 1;
    }
    pfVar4 = &local_24;
  }
  else {
    do {
      iVar2 = FUN_004f8b10("Reset",*(undefined4 *)(param_4 + iVar6 * 4));
      if (iVar2 == 0) {
        FUN_00577880(0,0,0,0,0,0,0,0,0,0);
        return 1;
      }
      iVar2 = FUN_004f8b10("use_current_campos",*(undefined4 *)(param_4 + iVar6 * 4));
      if (iVar2 == 0) {
        bVar1 = true;
      }
      else {
        iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar6 * 4),"start_time=");
        if (iVar2 == 0) {
          iVar2 = FUN_004f8b10("end_time=infinite",*(undefined4 *)(param_4 + iVar6 * 4));
          if (iVar2 == 0) {
            local_64 = 1e+09;
          }
          else {
            iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar6 * 4),"end_time=");
            if (iVar2 == 0) {
              iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar6 * 4),"blend_in_time=");
              if (iVar2 == 0) {
                iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar6 * 4),"blend_out_time=");
                if (iVar2 == 0) {
                  iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar6 * 4),"tgt_locator=");
                  if (iVar2 == 0) {
                    iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar6 * 4),"tgt_character=");
                    if (iVar2 == 0) {
                      iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar6 * 4),"tgt_obj=");
                      if (iVar2 == 0) {
                        iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar6 * 4),"cam_locator=");
                        if (iVar2 == 0) {
                          iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar6 * 4),"range=");
                          if (iVar2 == 0) {
                            iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar6 * 4),"roty=");
                            if (iVar2 == 0) {
                              iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar6 * 4),"rotx=");
                              if (iVar2 == 0) {
                                iVar2 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar6 * 4),
                                                     "FollowTgt");
                                if (iVar2 == 0) {
                                  local_40 = 1;
                                }
                                else {
                                  iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar6 * 4),
                                                       "dcampos_x=");
                                  if (iVar2 == 0) {
                                    iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar6 * 4),
                                                         "dcampos_y=");
                                    if (iVar2 == 0) {
                                      iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar6 * 4),
                                                           "dcampos_z=");
                                      if (iVar2 == 0) {
                                        iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar6 * 4),
                                                             "campos_x=");
                                        if (iVar2 == 0) {
                                          iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar6 * 4),
                                                               "campos_y=");
                                          if (iVar2 == 0) {
                                            iVar2 = FUN_004f8a70(*(undefined4 *)
                                                                  (param_4 + iVar6 * 4),"campos_z=")
                                            ;
                                            if (iVar2 == 0) {
                                              iVar2 = FUN_004f8a70(*(undefined4 *)
                                                                    (param_4 + iVar6 * 4),
                                                                   "tgtpos_x=");
                                              if (iVar2 == 0) {
                                                iVar2 = FUN_004f8a70(*(undefined4 *)
                                                                      (param_4 + iVar6 * 4),
                                                                     "tgtpos_y=");
                                                if (iVar2 == 0) {
                                                  iVar2 = FUN_004f8a70(*(undefined4 *)
                                                                        (param_4 + iVar6 * 4),
                                                                       "tgtpos_z=");
                                                  if (iVar2 == 0) {
                                                    iVar2 = FUN_004f8b10("no_borders",
                                                                         *(undefined4 *)
                                                                          (param_4 + iVar6 * 4));
                                                    if (iVar2 == 0) {
                                                      local_44 = 0;
                                                    }
                                                  }
                                                  else {
                                                    fVar7 = (float10)FUN_005147c0(param_2,iVar2 + 9)
                                                    ;
                                                    local_1c = (float)fVar7;
                                                  }
                                                }
                                                else {
                                                  fVar7 = (float10)FUN_005147c0(param_2,iVar2 + 9);
                                                  local_20 = (float)fVar7;
                                                }
                                              }
                                              else {
                                                fVar7 = (float10)FUN_005147c0(param_2,iVar2 + 9);
                                                local_24 = (float)fVar7;
                                              }
                                            }
                                            else {
                                              fVar7 = (float10)FUN_005147c0(param_2,iVar2 + 9);
                                              local_28 = (float)fVar7;
                                            }
                                          }
                                          else {
                                            fVar7 = (float10)FUN_005147c0(param_2,iVar2 + 9);
                                            local_2c = (float)fVar7;
                                          }
                                        }
                                        else {
                                          fVar7 = (float10)FUN_005147c0(param_2,iVar2 + 9);
                                          local_30 = (float)fVar7;
                                        }
                                      }
                                      else {
                                        fVar7 = (float10)FUN_005147c0(param_2,iVar2 + 10);
                                        local_10 = (float)fVar7;
                                      }
                                    }
                                    else {
                                      fVar7 = (float10)FUN_005147c0(param_2,iVar2 + 10);
                                      local_14 = (float)fVar7;
                                    }
                                  }
                                  else {
                                    fVar7 = (float10)FUN_005147c0(param_2,iVar2 + 10);
                                    local_18 = (float)fVar7;
                                  }
                                }
                              }
                              else {
                                FUN_005147c0(param_2,iVar2 + 5);
                                FUN_006e6b90();
                                local_4c = FUN_006e6b90();
                              }
                            }
                            else {
                              FUN_005147c0(param_2,iVar2 + 5);
                              FUN_006e6b90();
                              local_48 = FUN_006e6b90();
                            }
                          }
                          else {
                            fVar7 = (float10)FUN_005147c0(param_2,iVar2 + 6);
                            local_50 = (float)fVar7;
                          }
                        }
                        else {
                          local_54 = iVar2 + 0xc;
                        }
                      }
                      else {
                        local_5c = iVar2 + 8;
                      }
                    }
                    else {
                      local_60 = iVar2 + 0xe;
                    }
                  }
                  else {
                    iVar5 = iVar2 + 0xc;
                  }
                }
                else {
                  fVar7 = (float10)FUN_005147c0(param_2,iVar2 + 0xf);
                  local_3c = (float)fVar7;
                }
              }
              else {
                fVar7 = (float10)FUN_005147c0(param_2,iVar2 + 0xe);
                local_38 = (float)fVar7;
              }
            }
            else {
              fVar7 = (float10)FUN_005147c0(param_2,iVar2 + 9);
              local_64 = (float)fVar7;
            }
          }
        }
        else {
          fVar7 = (float10)FUN_005147c0(param_2,iVar2 + 0xb);
          local_34 = (float)fVar7;
        }
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < param_5);
    if (iVar5 == 0) {
      if (local_60 == 0) {
        if (local_5c == 0) goto LAB_00450fee;
        iVar5 = FUN_005cf5b0(*(undefined4 *)(PTR_DAT_00802c54 + 0x13c),local_c,local_5c,1);
        if (iVar5 == 0) {
          return 1;
        }
        pfVar4 = (float *)FUN_005cf9e0(local_c);
      }
      else {
        if (((param_3 == 0) || (*(int *)(param_3 + 0xd0) == 0)) ||
           (iVar5 = FUN_004f8b10(local_60,"myself"), iVar5 != 0)) {
          if (DAT_00923904 == (code *)0x0) {
            return 1;
          }
          piVar3 = (int *)(*DAT_00923904)(param_1,local_60);
          if (piVar3 == (int *)0x0) {
            return 1;
          }
          iVar5 = *piVar3;
        }
        else {
          iVar5 = **(int **)(param_3 + 0xd0);
        }
        if (iVar5 == 0) {
          return 1;
        }
        pfVar4 = (float *)(iVar5 + 0x80);
      }
    }
    else {
      iVar5 = FUN_0051ac10(param_1,iVar5);
      if (iVar5 == 0) {
        return 1;
      }
      pfVar4 = (float *)(iVar5 + 0x10);
    }
    if (pfVar4 == (float *)0x0) {
      return 1;
    }
  }
  if (bVar1) {
    iVar5 = FUN_005d6170();
    if (iVar5 != 0) {
      local_30 = *(float *)(iVar5 + 0x30);
      local_2c = *(float *)(iVar5 + 0x34);
      local_28 = *(float *)(iVar5 + 0x38);
      FUN_005b37d0(&local_30,&local_30,&local_18);
      goto LAB_00451053;
    }
  }
  else {
    if (((local_30 != 1e+09) && (local_2c != 1e+09)) && (local_28 != 1e+09)) goto LAB_00451053;
    if ((local_54 != 0) && (iVar5 = FUN_0051ac10(param_1,local_54), iVar5 != 0)) {
      local_30 = *(float *)(iVar5 + 0x10);
      local_2c = *(float *)(iVar5 + 0x14);
      local_28 = *(float *)(iVar5 + 0x18);
      goto LAB_00451053;
    }
  }
  local_30 = 0.0;
  local_2c = 0.0;
  local_28 = local_50;
  FUN_005b35a0(&local_30,&local_30,local_4c);
  FUN_005b3620(&local_30,&local_30,local_48);
  FUN_005b37d0(&local_30,&local_30,pfVar4);
LAB_00451053:
  FUN_00577880(&local_30,pfVar4,0,local_34,local_64,local_38,local_3c,local_40,0,local_44);
  return 1;
}

