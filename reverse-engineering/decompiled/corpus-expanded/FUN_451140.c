/* Ghidra pseudocode, not original source.
 * ev_b55b7a309ed021766e38758a92fbc8c97c8db4b0d277f859ab4c7f52da556e16
 * Entry: 0x451140; label: FUN_00451140
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4
FUN_00451140(undefined4 param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6)

{
  char cVar1;
  float *pfVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  int iVar6;
  float10 fVar7;
  float local_84;
  float local_80;
  float local_7c;
  int local_78;
  undefined4 local_74;
  int local_70;
  float *local_6c;
  uint local_68;
  float local_64;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  int local_50;
  float local_4c;
  float local_48;
  float local_44;
  int local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  int local_2c;
  float local_28;
  undefined4 local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  undefined1 local_c [12];
  
  local_34 = 0.0;
  iVar6 = 0;
  local_28 = 1e+09;
  uVar5 = 0;
  local_30 = 0.0;
  local_1c = 0.0;
  local_60 = 0;
  local_38 = 0.0;
  local_40 = 0;
  local_3c = 0.0;
  local_24 = 1;
  local_20 = 0.0;
  local_6c = (float *)0x0;
  local_58 = 0;
  local_4c = 1e+09;
  local_5c = 0;
  local_48 = 1e+09;
  local_54 = 0;
  local_44 = 1e+09;
  local_50 = 0;
  local_84 = 1e+09;
  cVar1 = -1;
  local_80 = 1e+09;
  local_68 = CONCAT31(local_68._1_3_,0xff);
  local_7c = 1e+09;
  local_74 = 0;
  local_78 = 0;
  local_70 = 0;
  local_18 = 0.0;
  local_2c = 0;
  local_14 = 0.0;
  local_10 = 0.0;
  local_64 = 1.0;
  if (param_6 == 0) {
    return 1;
  }
  if (param_5 < 1) {
LAB_004519d8:
    if (((local_4c != 1e+09) && (local_48 != 1e+09)) && (local_44 != 1e+09)) {
      local_6c = &local_4c;
      uVar5 = uVar5 | 0x80;
    }
  }
  else {
    do {
      iVar3 = FUN_004f8b10("use_current_campos",*(undefined4 *)(param_4 + iVar6 * 4));
      if (iVar3 == 0) {
        local_40 = 1;
        uVar5 = uVar5 | 0x100;
      }
      else {
        iVar3 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar6 * 4),"attach_to_spline=");
        if (iVar3 == 0) {
          iVar3 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar6 * 4),"spline_dist_offset=");
          if (iVar3 == 0) {
            iVar3 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar6 * 4),"start_time=");
            if (iVar3 == 0) {
              iVar3 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar6 * 4),"blend_time=");
              if (iVar3 == 0) {
                iVar3 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar6 * 4),"blend_in_time=");
                if (iVar3 == 0) {
                  iVar3 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar6 * 4),"blend_out_time=");
                  if (iVar3 == 0) {
                    iVar3 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar6 * 4),"end_time=");
                    if (iVar3 == 0) {
                      iVar3 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar6 * 4),"max_time=");
                      if (iVar3 == 0) {
                        iVar3 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar6 * 4),"hold_time=");
                        if (iVar3 == 0) {
                          iVar3 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar6 * 4),"tgt_locator=");
                          if (iVar3 == 0) {
                            iVar3 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar6 * 4),
                                                 "tgt_character=");
                            if (iVar3 == 0) {
                              iVar3 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar6 * 4),"tgt_obj=");
                              if (iVar3 == 0) {
                                iVar3 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar6 * 4),
                                                     "cam_locator=");
                                if (iVar3 == 0) {
                                  iVar3 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar6 * 4),"range="
                                                      );
                                  if (iVar3 == 0) {
                                    iVar3 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar6 * 4),
                                                         "cont_roty=");
                                    if (iVar3 == 0) {
                                      iVar3 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar6 * 4),
                                                           "roty=");
                                      if (iVar3 == 0) {
                                        iVar3 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar6 * 4),
                                                             "cont_rotx=");
                                        if (iVar3 == 0) {
                                          iVar3 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar6 * 4),
                                                               "rotx=");
                                          if (iVar3 == 0) {
                                            iVar3 = FUN_004f8a70(*(undefined4 *)
                                                                  (param_4 + iVar6 * 4),"cont_rotz="
                                                                );
                                            if (iVar3 == 0) {
                                              iVar3 = FUN_004f8a70(*(undefined4 *)
                                                                    (param_4 + iVar6 * 4),"rotz=");
                                              if (iVar3 == 0) {
                                                iVar3 = FUN_004f8a70(*(undefined4 *)
                                                                      (param_4 + iVar6 * 4),
                                                                     "campos_x=");
                                                if (iVar3 == 0) {
                                                  iVar3 = FUN_004f8a70(*(undefined4 *)
                                                                        (param_4 + iVar6 * 4),
                                                                       "campos_y=");
                                                  if (iVar3 == 0) {
                                                    iVar3 = FUN_004f8a70(*(undefined4 *)
                                                                          (param_4 + iVar6 * 4),
                                                                         "campos_z=");
                                                    if (iVar3 == 0) {
                                                      iVar3 = FUN_004f8a70(*(undefined4 *)
                                                                            (param_4 + iVar6 * 4),
                                                                           "tgtpos_x=");
                                                      if (iVar3 == 0) {
                                                        iVar3 = FUN_004f8a70(*(undefined4 *)
                                                                              (param_4 + iVar6 * 4),
                                                                             "tgtpos_y=");
                                                        if (iVar3 == 0) {
                                                          iVar3 = FUN_004f8a70(*(undefined4 *)
                                                                                (param_4 + iVar6 * 4
                                                                                ),"tgtpos_z=");
                                                          if (iVar3 == 0) {
                                                            iVar3 = FUN_004f8a70(*(undefined4 *)
                                                                                  (param_4 +
                                                                                  iVar6 * 4),
                                                                                 "dcampos_x=");
                                                            if (iVar3 == 0) {
                                                              iVar3 = FUN_004f8a70(*(undefined4 *)
                                                                                    (param_4 +
                                                                                    iVar6 * 4),
                                                                                   "dcampos_y=");
                                                              if (iVar3 == 0) {
                                                                iVar3 = FUN_004f8a70(*(undefined4 *)
                                                                                      (param_4 +
                                                                                      iVar6 * 4),
                                                                                     "dcampos_z=");
                                                                if (iVar3 == 0) {
                                                                  iVar3 = FUN_004f8b10("no_borders",
                                                                                       *(undefined4
                                                                                         *)(param_4 
                                                  + iVar6 * 4));
                                                  if (iVar3 == 0) {
                                                    local_24 = 0;
                                                  }
                                                  else {
                                                    iVar3 = FUN_004f8b10("mode=follow",
                                                                         *(undefined4 *)
                                                                          (param_4 + iVar6 * 4));
                                                    if (iVar3 == 0) {
                                                      cVar1 = '\0';
                                                    }
                                                    else {
                                                      iVar3 = FUN_004f8b10("mode=static",
                                                                           *(undefined4 *)
                                                                            (param_4 + iVar6 * 4));
                                                      if (iVar3 == 0) {
                                                        cVar1 = '\x01';
                                                      }
                                                      else {
                                                        iVar3 = FUN_004f8b10("linear",*(undefined4 *
                                                                                       )(param_4 +
                                                                                        iVar6 * 4));
                                                        if (iVar3 == 0) {
                                                          local_68 = local_68 & 0xffffff00;
                                                        }
                                                        else {
                                                          iVar3 = FUN_004f8b10("slowfastslow",
                                                                               *(undefined4 *)
                                                                                (param_4 + iVar6 * 4
                                                                                ));
                                                          if (iVar3 == 0) {
                                                            local_68 = CONCAT31(local_68._1_3_,2);
                                                          }
                                                          else {
                                                            iVar3 = FUN_004f8b10("slowfast",
                                                                                 *(undefined4 *)
                                                                                  (param_4 +
                                                                                  iVar6 * 4));
                                                            if (iVar3 == 0) {
                                                              local_68 = CONCAT31(local_68._1_3_,1);
                                                            }
                                                            else {
                                                              iVar3 = FUN_004f8b10("fastslowfast",
                                                                                   *(undefined4 *)
                                                                                    (param_4 +
                                                                                    iVar6 * 4));
                                                              if (iVar3 == 0) {
                                                                local_68 = CONCAT31(local_68._1_3_,4
                                                                                   );
                                                              }
                                                              else {
                                                                iVar3 = FUN_004f8b10("fastslow",
                                                                                     *(undefined4 *)
                                                                                      (param_4 +
                                                                                      iVar6 * 4));
                                                                if (iVar3 == 0) {
                                                                  local_68 = CONCAT31(local_68._1_3_
                                                                                      ,3);
                                                                }
                                                              }
                                                            }
                                                          }
                                                        }
                                                      }
                                                    }
                                                  }
                                                  }
                                                  else {
                                                    fVar7 = (float10)FUN_005147c0(param_2,iVar3 + 10
                                                                                 );
                                                    local_10 = (float)fVar7;
                                                  }
                                                  }
                                                  else {
                                                    fVar7 = (float10)FUN_005147c0(param_2,iVar3 + 10
                                                                                 );
                                                    local_14 = (float)fVar7;
                                                  }
                                                  }
                                                  else {
                                                    fVar7 = (float10)FUN_005147c0(param_2,iVar3 + 10
                                                                                 );
                                                    local_18 = (float)fVar7;
                                                  }
                                                  }
                                                  else {
                                                    fVar7 = (float10)FUN_005147c0(param_2,iVar3 + 9)
                                                    ;
                                                    local_44 = (float)fVar7;
                                                  }
                                                  }
                                                  else {
                                                    fVar7 = (float10)FUN_005147c0(param_2,iVar3 + 9)
                                                    ;
                                                    local_48 = (float)fVar7;
                                                  }
                                                  }
                                                  else {
                                                    fVar7 = (float10)FUN_005147c0(param_2,iVar3 + 9)
                                                    ;
                                                    local_4c = (float)fVar7;
                                                  }
                                                  }
                                                  else {
                                                    fVar7 = (float10)FUN_005147c0(param_2,iVar3 + 9)
                                                    ;
                                                    local_7c = (float)fVar7;
                                                  }
                                                  }
                                                  else {
                                                    fVar7 = (float10)FUN_005147c0(param_2,iVar3 + 9)
                                                    ;
                                                    local_80 = (float)fVar7;
                                                  }
                                                }
                                                else {
                                                  fVar7 = (float10)FUN_005147c0(param_2,iVar3 + 9);
                                                  local_84 = (float)fVar7;
                                                }
                                              }
                                              else {
                                                uVar5 = uVar5 | 8;
                                                FUN_005147c0(param_2,iVar3 + 5);
                                                local_70 = FUN_006e6b90();
                                                local_70 = -local_70;
                                                local_70 = FUN_006e6b90();
                                              }
                                            }
                                            else {
                                              uVar5 = uVar5 | 0x40;
                                              FUN_005147c0(param_2,iVar3 + 10);
                                              local_70 = FUN_006e6b90();
                                              local_70 = FUN_006e6b90();
                                            }
                                          }
                                          else {
                                            uVar5 = uVar5 | 2;
                                            FUN_005147c0(param_2,iVar3 + 5);
                                            local_78 = FUN_006e6b90();
                                            local_78 = -local_78;
                                            local_78 = FUN_006e6b90();
                                          }
                                        }
                                        else {
                                          uVar5 = uVar5 | 0x10;
                                          FUN_005147c0(param_2,iVar3 + 10);
                                          local_78 = FUN_006e6b90();
                                          local_78 = FUN_006e6b90();
                                        }
                                      }
                                      else {
                                        uVar5 = uVar5 | 4;
                                        FUN_005147c0(param_2,iVar3 + 5);
                                        local_74 = FUN_006e6b90();
                                        local_74 = FUN_006e6b90();
                                      }
                                    }
                                    else {
                                      uVar5 = uVar5 | 0x20;
                                      FUN_005147c0(param_2,iVar3 + 10);
                                      local_74 = FUN_006e6b90();
                                      local_74 = FUN_006e6b90();
                                    }
                                  }
                                  else {
                                    uVar5 = uVar5 | 1;
                                    fVar7 = (float10)FUN_005147c0(param_2,iVar3 + 6);
                                    local_64 = (float)fVar7;
                                  }
                                }
                                else {
                                  local_50 = iVar3 + 0xc;
                                }
                              }
                              else {
                                local_54 = iVar3 + 8;
                              }
                            }
                            else {
                              local_5c = iVar3 + 0xe;
                            }
                          }
                          else {
                            local_58 = iVar3 + 0xc;
                          }
                        }
                        else {
                          uVar5 = uVar5 | 0x1000;
                          fVar7 = (float10)FUN_005147c0(param_2,iVar3 + 10);
                          local_1c = (float)fVar7;
                        }
                      }
                      else {
                        fVar7 = (float10)FUN_005147c0(param_2,iVar3 + 9);
                        local_38 = (float)fVar7;
                      }
                    }
                    else {
                      uVar5 = uVar5 | 0x400;
                      fVar7 = (float10)FUN_005147c0(param_2,iVar3 + 9);
                      local_28 = (float)fVar7;
                    }
                  }
                  else {
                    fVar7 = (float10)FUN_005147c0(param_2,iVar3 + 0xf);
                    local_20 = (float)fVar7;
                  }
                }
                else {
                  fVar7 = (float10)FUN_005147c0(param_2,iVar3 + 0xe);
                  local_3c = (float)fVar7;
                }
              }
              else {
                uVar5 = uVar5 | 0x800;
                fVar7 = (float10)FUN_005147c0(param_2,iVar3 + 0xb);
                local_30 = (float)fVar7;
              }
            }
            else {
              uVar5 = uVar5 | 0x200;
              fVar7 = (float10)FUN_005147c0(param_2,iVar3 + 0xb);
              local_34 = (float)fVar7;
            }
          }
          else {
            uVar5 = uVar5 | 0x4000;
            fVar7 = (float10)FUN_005147c0(param_2,iVar3 + 0x11);
            local_64 = (float)fVar7;
          }
        }
        else {
          uVar5 = uVar5 | 0x2000;
          local_2c = FUN_005d0690(*(undefined4 *)(PTR_DAT_00802c54 + 0x13c),iVar3 + 0x11);
        }
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < param_5);
    if (local_58 == 0) {
      if (local_5c == 0) {
        if (local_54 == 0) goto LAB_004519d8;
        iVar6 = FUN_005cf5b0(*(undefined4 *)(PTR_DAT_00802c54 + 0x13c),local_c,local_54,1);
        if (iVar6 != 0) {
          local_6c = (float *)FUN_005cf9e0(local_c);
          goto LAB_004518f7;
        }
      }
      else {
        if (((param_3 == 0) || (*(int *)(param_3 + 0xd0) == 0)) ||
           (iVar6 = FUN_004f8b10(local_5c,"myself"), iVar6 != 0)) {
          if ((DAT_00923904 == (code *)0x0) ||
             (piVar4 = (int *)(*DAT_00923904)(param_1,local_5c), piVar4 == (int *)0x0))
          goto LAB_00451a17;
          iVar6 = *piVar4;
        }
        else {
          iVar6 = **(int **)(param_3 + 0xd0);
        }
        if (iVar6 != 0) {
          local_6c = (float *)(iVar6 + 0x80);
          goto LAB_004518f7;
        }
      }
    }
    else {
      iVar6 = FUN_0051ac10(param_1,local_58);
      if (iVar6 != 0) {
        local_6c = (float *)(iVar6 + 0x10);
LAB_004518f7:
        if (local_6c != (float *)0x0) {
          uVar5 = uVar5 | 0x80;
        }
      }
    }
  }
LAB_00451a17:
  if (local_40 == 0) {
    if (((local_84 != 1e+09) && (local_80 != 1e+09)) && (local_7c != 1e+09)) {
      local_60 = 1;
      goto LAB_00451ab6;
    }
    if ((local_50 == 0) || (iVar6 = FUN_0051ac10(param_1,local_50), iVar6 == 0)) goto LAB_00451ab6;
    local_84 = *(float *)(iVar6 + 0x10);
    local_80 = *(float *)(iVar6 + 0x14);
    local_7c = *(float *)(iVar6 + 0x18);
  }
  else {
    iVar6 = FUN_005d6170();
    if (iVar6 == 0) goto LAB_00451ab6;
    local_84 = *(float *)(iVar6 + 0x30);
    local_80 = *(float *)(iVar6 + 0x34);
    local_7c = *(float *)(iVar6 + 0x38);
  }
  local_60 = 1;
LAB_00451ab6:
  iVar6 = local_2c;
  pfVar2 = local_6c;
  if (local_2c == 0) {
    if (local_60 == 0) {
      if (local_6c != (float *)0x0) {
        local_84 = 0.0;
        local_80 = 0.0;
        local_7c = local_64;
        FUN_005b35a0(&local_84,&local_84,local_78);
        FUN_005b3620(&local_84,&local_84,local_74);
        FUN_005b37d0(&local_84,&local_84,pfVar2);
      }
      if (cVar1 == -1) {
        cVar1 = '\0';
      }
    }
    else {
      uVar5 = uVar5 | 0x100;
      FUN_005b37d0(&local_84,&local_84,&local_18);
      if (cVar1 == -1) {
        cVar1 = '\x01';
      }
    }
  }
  else {
    FUN_00550a20(local_2c,0,&local_84,0,0,0);
    if (cVar1 == -1) {
      cVar1 = '\x02';
    }
  }
  FUN_00578140(uVar5,local_64,local_78,local_74,local_70,local_6c,0,&local_84,local_34,local_3c,
               local_28,local_20,local_30,local_1c,local_38,local_24,iVar6,cVar1,local_68);
  return 1;
}

