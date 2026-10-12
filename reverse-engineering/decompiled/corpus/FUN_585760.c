/* Ghidra analysis pseudocode, not original source.
 * ev_798b10c68707b8e82eaac4021b8b987befb8ed65c6c28839f1f848362e912a18
 * Entry: 0x585760; label: FUN_00585760
 */

void FUN_00585760(int param_1)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  int *piVar7;
  uint uVar8;
  short sVar9;
  uint *puVar10;
  uint *puVar11;
  float10 fVar12;
  uint local_78 [2];
  short local_70;
  undefined1 local_6d;
  char local_6c;
  char local_6b;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  undefined2 local_30;
  undefined1 local_2e;
  undefined1 local_2c [40];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_78;
  if (DAT_0095441e < 100) {
    iVar3 = FUN_004f7fb0(param_1);
    if ((iVar3 != 0) && (iVar3 = FUN_004f1ff0(*(undefined4 *)(param_1 + 0x510)), iVar3 < 0x28)) {
      FUN_004f1f10(local_2c,*(undefined4 *)(param_1 + 0x510));
      _memset(local_78,0,0x4c);
      uVar8 = 6;
      local_70 = -1;
      local_78[1] = 6;
      if ((DAT_0095440c & 1) != 0) {
        uVar8 = 0xe;
        local_78[1] = 0xe;
      }
      local_68 = 0.2;
      local_2e = 0xff;
      local_64 = 0.2;
      local_60 = 30.0;
      iVar3 = FUN_004fc5b0(param_1);
      sVar9 = -1;
      if (iVar3 != 0) {
        do {
          iVar3 = FUN_004f7fb0(param_1);
          uVar2 = local_78[1];
          if (iVar3 != 0) {
            iVar3 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),"action");
            if (iVar3 == 0) {
              iVar3 = FUN_004f7fb0(param_1);
              if (iVar3 != 0) {
                local_70 = FUN_00630740(*(undefined4 *)(param_1 + 0x510));
                sVar9 = local_70;
              }
              uVar2 = local_78[1];
              if (sVar9 == -1) break;
            }
            else {
              iVar3 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),&PTR_LAB_00763600);
              if (iVar3 == 0) {
                iVar3 = FUN_004f7fb0(param_1);
                uVar2 = local_78[1];
                if (iVar3 != 0) {
                  iVar3 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),&DAT_007622ac);
                  if (iVar3 == 0) {
                    uVar8 = uVar8 | 8;
                    uVar2 = uVar8;
                  }
                  else {
                    iVar3 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),&DAT_00758e24);
                    uVar2 = local_78[1];
                    if (iVar3 == 0) {
                      uVar8 = uVar8 & 0xfffffff7;
                      uVar2 = uVar8;
                    }
                  }
                }
              }
              else {
                iVar3 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),"cycle");
                if (iVar3 == 0) {
                  iVar3 = FUN_004f7fb0(param_1);
                  uVar2 = local_78[1];
                  if (iVar3 != 0) {
                    iVar3 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),&DAT_007622ac);
                    if (iVar3 == 0) {
                      uVar8 = uVar8 | 2;
                      uVar2 = uVar8;
                    }
                    else {
                      iVar3 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),&DAT_00758e24);
                      uVar2 = local_78[1];
                      if (iVar3 == 0) {
                        uVar8 = uVar8 & 0xfffffffd;
                        uVar2 = uVar8;
                      }
                    }
                  }
                }
                else {
                  iVar3 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),&DAT_0075772c);
                  if (iVar3 == 0) {
                    iVar3 = FUN_004f7fb0(param_1);
                    uVar2 = local_78[1];
                    if (iVar3 != 0) {
                      iVar3 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),&DAT_0075b9a8);
                      if (iVar3 == 0) {
                        uVar8 = uVar8 | 0x10;
                        uVar2 = uVar8;
                      }
                      else {
                        uVar8 = uVar8 & 0xffffffef;
                        uVar2 = uVar8;
                      }
                    }
                  }
                  else {
                    iVar3 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),"fpsec");
                    if (iVar3 == 0) {
                      fVar12 = (float10)FUN_004f8100(param_1);
                      local_60 = (float)fVar12;
                      uVar2 = local_78[1];
                    }
                    else {
                      iVar3 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),"blend_in");
                      if (iVar3 == 0) {
                        fVar12 = (float10)FUN_004f8100(param_1);
                        local_68 = (float)fVar12;
                        uVar2 = local_78[1];
                      }
                      else {
                        iVar3 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),"blend_out");
                        if (iVar3 == 0) {
                          fVar12 = (float10)FUN_004f8100(param_1);
                          local_64 = (float)fVar12;
                          uVar2 = local_78[1];
                        }
                        else {
                          iVar3 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),"speedmul_speed");
                          if (iVar3 == 0) {
                            fVar12 = (float10)FUN_004f8100(param_1);
                            local_5c = (float)fVar12;
                            uVar2 = local_78[1];
                          }
                          else {
                            iVar3 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),"speedmul_maxfps")
                            ;
                            if (iVar3 == 0) {
                              fVar12 = (float10)FUN_004f8100(param_1);
                              local_58 = (float)fVar12;
                              uVar2 = local_78[1];
                            }
                            else {
                              iVar3 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),"translate");
                              if (iVar3 == 0) {
                                FUN_00584db0(param_1);
                                uVar8 = local_78[1];
                                uVar2 = local_78[1];
                              }
                              else {
                                iVar3 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),
                                                     "can_play_backwards");
                                if (iVar3 == 0) {
                                  FUN_00584db0(param_1);
                                  uVar8 = local_78[1];
                                  uVar2 = local_78[1];
                                }
                                else {
                                  iVar3 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),"footsteps")
                                  ;
                                  if (iVar3 == 0) {
                                    uVar8 = uVar8 | 0x100;
                                    local_78[1] = uVar8;
                                    iVar3 = FUN_004f7fb0(param_1);
                                    uVar2 = local_78[1];
                                    while (iVar3 != 0) {
                                      iVar3 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),
                                                           &DAT_00758e24);
                                      if (iVar3 == 0) {
                                        uVar8 = uVar8 & 0xfff8feff;
                                        uVar2 = uVar8;
                                        break;
                                      }
                                      iVar3 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),
                                                           "4frames");
                                      if (iVar3 == 0) {
                                        uVar8 = uVar8 | 0x10000;
                                      }
                                      else {
                                        iVar3 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),
                                                             "judder");
                                        if (iVar3 == 0) {
                                          uVar8 = uVar8 | 0x20000;
                                        }
                                        else {
                                          iVar3 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),
                                                               "shake");
                                          if (iVar3 == 0) {
                                            uVar8 = uVar8 | 0x40000;
                                          }
                                        }
                                      }
                                      iVar3 = FUN_004f7fb0(param_1);
                                      uVar2 = uVar8;
                                    }
                                  }
                                  else {
                                    iVar3 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),
                                                         "no_headturn");
                                    if ((iVar3 == 0) ||
                                       (iVar3 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),
                                                             "headturn_off"), iVar3 == 0)) {
LAB_0058618b:
                                      uVar8 = uVar8 | 0x40;
                                      uVar2 = uVar8;
                                    }
                                    else {
                                      iVar3 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),
                                                           "headturn");
                                      if (iVar3 == 0) {
                                        iVar3 = FUN_004f7fb0(param_1);
                                        if ((iVar3 != 0) &&
                                           (iVar3 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),
                                                                 &DAT_00758e24), iVar3 == 0))
                                        goto LAB_0058618b;
                                        uVar8 = uVar8 & 0xffffffbf;
                                        uVar2 = uVar8;
                                      }
                                      else {
                                        iVar3 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),
                                                             "minreps");
                                        if (iVar3 == 0) {
                                          uVar4 = FUN_004f9e70(param_1);
                                          bVar1 = (byte)((int)uVar4 >> 0x1f);
                                          local_6c = ((byte)uVar4 ^ bVar1) - bVar1;
                                          uVar2 = local_78[1];
                                        }
                                        else {
                                          iVar3 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),
                                                               "maxreps");
                                          if (iVar3 == 0) {
                                            uVar4 = FUN_004f9e70(param_1);
                                            bVar1 = (byte)((int)uVar4 >> 0x1f);
                                            local_6b = ((byte)uVar4 ^ bVar1) - bVar1;
                                            uVar2 = local_78[1];
                                          }
                                          else {
                                            iVar3 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),
                                                                 "speed");
                                            if (iVar3 == 0) {
                                              fVar12 = (float10)FUN_004f8100(param_1);
                                              local_54 = (float)fVar12;
                                              uVar2 = local_78[1];
                                            }
                                            else {
                                              iVar3 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),
                                                                   "frame");
                                              if (((iVar3 == 0) ||
                                                  (iVar3 = FUN_004f8b10(*(undefined4 *)
                                                                         (param_1 + 0x510),"frame1")
                                                  , iVar3 == 0)) ||
                                                 (iVar3 = FUN_004f8b10(*(undefined4 *)
                                                                        (param_1 + 0x510),
                                                                       "frame_hit"), iVar3 == 0)) {
                                                fVar12 = (float10)FUN_004f8100(param_1);
                                                local_50 = (float)fVar12;
                                                uVar2 = local_78[1];
                                              }
                                              else {
                                                iVar3 = FUN_004f8b10(*(undefined4 *)
                                                                      (param_1 + 0x510),"frame2");
                                                if ((iVar3 == 0) ||
                                                   (iVar3 = FUN_004f8b10(*(undefined4 *)
                                                                          (param_1 + 0x510),
                                                                         "frame_end"), iVar3 == 0))
                                                {
                                                  fVar12 = (float10)FUN_004f8100(param_1);
                                                  local_4c = (float)fVar12;
                                                  uVar2 = local_78[1];
                                                }
                                                else {
                                                  iVar3 = FUN_004f8b10(*(undefined4 *)
                                                                        (param_1 + 0x510),"frame3");
                                                  if (iVar3 == 0) {
                                                    fVar12 = (float10)FUN_004f8100(param_1);
                                                    local_48 = (float)fVar12;
                                                    uVar2 = local_78[1];
                                                  }
                                                  else {
                                                    iVar3 = FUN_004f8b10(*(undefined4 *)
                                                                          (param_1 + 0x510),"frame4"
                                                                        );
                                                    if (iVar3 == 0) {
                                                      fVar12 = (float10)FUN_004f8100(param_1);
                                                      local_44 = (float)fVar12;
                                                      uVar2 = local_78[1];
                                                    }
                                                    else {
                                                      iVar3 = FUN_004f8b10(*(undefined4 *)
                                                                            (param_1 + 0x510),
                                                                           "frame_stop");
                                                      if (iVar3 == 0) {
                                                        fVar12 = (float10)FUN_004f8100(param_1);
                                                        local_40 = (float)fVar12;
                                                        uVar2 = local_78[1];
                                                      }
                                                      else {
                                                        iVar3 = FUN_004f8b10(*(undefined4 *)
                                                                              (param_1 + 0x510),
                                                                             "priority");
                                                        if (iVar3 == 0) {
                                                          local_6d = FUN_004f9e70(param_1);
                                                          uVar2 = local_78[1];
                                                        }
                                                        else {
                                                          iVar3 = FUN_004f8b10(*(undefined4 *)
                                                                                (param_1 + 0x510),
                                                                               "gun_off");
                                                          if (iVar3 == 0) {
                                                            uVar8 = uVar8 | 0x400;
                                                            uVar2 = uVar8;
                                                          }
                                                          else {
                                                            iVar3 = FUN_004f8b10(*(undefined4 *)
                                                                                  (param_1 + 0x510),
                                                                                 "gun_on");
                                                            if (iVar3 == 0) {
                                                              uVar8 = uVar8 | 0x800;
                                                              uVar2 = uVar8;
                                                            }
                                                            else {
                                                              iVar3 = FUN_004f8b10(*(undefined4 *)
                                                                                    (param_1 + 0x510
                                                                                    ),&
                                                  PTR_LAB_007546c8);
                                                  if (iVar3 == 0) {
                                                    iVar3 = FUN_004f7fb0(param_1);
                                                    uVar2 = local_78[1];
                                                    if (iVar3 != 0) {
                                                      iVar3 = FUN_004f8b10(*(undefined4 *)
                                                                            (param_1 + 0x510),
                                                                           &DAT_007622ac);
                                                      if (iVar3 == 0) {
                                                        uVar8 = uVar8 | 0x800;
                                                        uVar2 = uVar8;
                                                      }
                                                      else {
                                                        iVar3 = FUN_004f8b10(*(undefined4 *)
                                                                              (param_1 + 0x510),
                                                                             &DAT_00758e24);
                                                        uVar2 = local_78[1];
                                                        if (iVar3 == 0) {
                                                          uVar8 = uVar8 | 0x400;
                                                          uVar2 = uVar8;
                                                        }
                                                      }
                                                    }
                                                  }
                                                  else {
                                                    iVar3 = FUN_004f8b10(*(undefined4 *)
                                                                          (param_1 + 0x510),
                                                                         "locator");
                                                    if (iVar3 == 0) {
                                                      iVar3 = FUN_004f7fb0(param_1);
                                                      uVar2 = local_78[1];
                                                      if ((iVar3 != 0) &&
                                                         (uVar5 = FUN_004f29a0(*(undefined4 *)
                                                                                (param_1 + 0x510)),
                                                         uVar2 = local_78[1], uVar5 < 0x10)) {
                                                        local_2e = (undefined1)uVar5;
                                                      }
                                                    }
                                                    else {
                                                      iVar3 = FUN_004f8b10(*(undefined4 *)
                                                                            (param_1 + 0x510),
                                                                           "is_punch");
                                                      if (iVar3 == 0) {
                                                        FUN_00584df0(param_1);
                                                        uVar8 = local_78[1];
                                                        uVar2 = local_78[1];
                                                      }
                                                      else {
                                                        iVar3 = FUN_004f8b10(*(undefined4 *)
                                                                              (param_1 + 0x510),
                                                                             "is_kick");
                                                        if (iVar3 == 0) {
                                                          FUN_00584df0(param_1);
                                                          uVar8 = local_78[1];
                                                          uVar2 = local_78[1];
                                                        }
                                                        else {
                                                          iVar3 = FUN_004f8b10(*(undefined4 *)
                                                                                (param_1 + 0x510),
                                                                               "is_whip");
                                                          if (iVar3 == 0) {
                                                            FUN_00584df0(param_1);
                                                            uVar8 = local_78[1];
                                                            uVar2 = local_78[1];
                                                          }
                                                          else {
                                                            iVar3 = FUN_004f8b10(*(undefined4 *)
                                                                                  (param_1 + 0x510),
                                                                                                                                                                  
                                                  "extra_character_off");
                                                  if (iVar3 == 0) {
                                                    FUN_00584df0(param_1);
                                                    uVar8 = local_78[1];
                                                    uVar2 = local_78[1];
                                                  }
                                                  else {
                                                    iVar3 = FUN_004f8b10(*(undefined4 *)
                                                                          (param_1 + 0x510),
                                                                         "effect_start");
                                                    if (iVar3 == 0) {
                                                      if (((DAT_0095440c & 0x40) == 0) ||
                                                         ((DAT_0095440c & 0x20) == 0)) {
                                                        iVar3 = FUN_004fc5b0(param_1);
                                                        while ((uVar2 = local_78[1], iVar3 != 0 &&
                                                               ((iVar3 = FUN_004f7fb0(param_1),
                                                                iVar3 == 0 ||
                                                                (iVar3 = FUN_004f8b10(*(undefined4 *
                                                                                       )(param_1 +
                                                                                        0x510),
                                                  "effect_end"), uVar2 = local_78[1], iVar3 != 0))))
                                                  ) {
                                                    iVar3 = FUN_004fc5b0(param_1);
                                                  }
                                                  }
                                                  else {
                                                    uVar2 = local_78[1];
                                                    if (DAT_00954414 < 0x20) {
                                                      FUN_00584e30((int)DAT_0095441c,DAT_00954418,
                                                                   &DAT_00954414);
                                                      uVar2 = local_78[1];
                                                    }
                                                  }
                                                  }
                                                  else {
                                                    iVar3 = FUN_004f8b10(*(undefined4 *)
                                                                          (param_1 + 0x510),
                                                                         "anim_end");
                                                    uVar2 = local_78[1];
                                                    if (iVar3 == 0) {
                                                      if (sVar9 == -1) break;
                                                      if ((DAT_0095440c & 0x20) != 0) {
                                                        FUN_004f1f10(&DAT_00954428 +
                                                                     (uint)DAT_0095441e * 0x28,
                                                                     local_2c);
                                                        puVar10 = local_78;
                                                        puVar11 = (uint *)((uint)DAT_0095441e * 0x4c
                                                                          + *(int *)(DAT_00954400 +
                                                                                    0x10));
                                                        for (iVar3 = 0x13; iVar3 != 0;
                                                            iVar3 = iVar3 + -1) {
                                                          *puVar11 = *puVar10;
                                                          puVar10 = puVar10 + 1;
                                                          puVar11 = puVar11 + 1;
                                                        }
                                                        DAT_0095441e = DAT_0095441e + 1;
                                                        *DAT_00954420 = *DAT_00954420 + 0x4c;
                                                        __security_check_cookie
                                                                  (local_4 ^ (uint)local_78);
                                                        return;
                                                      }
                                                      piVar7 = *(int **)(DAT_00954400 + 0x10);
                                                      if (piVar7 == (int *)0x0) break;
                                                      iVar3 = 0;
                                                      if (*piVar7 == 0) goto LAB_005861fc;
                                                      iVar6 = 0;
                                                      goto LAB_005861d0;
                                                    }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                }
                                              }
                                            }
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
          local_78[1] = uVar2;
          iVar3 = FUN_004fc5b0(param_1);
          sVar9 = local_70;
          if (iVar3 == 0) {
            __security_check_cookie(local_4 ^ (uint)local_78);
            return;
          }
        } while( true );
      }
    }
  }
  else {
    iVar3 = FUN_004fc5b0();
    while( true ) {
      if (iVar3 == 0) {
        FUN_005845b0(100,*(undefined4 *)(DAT_00954400 + 0xc));
        __security_check_cookie(local_4 ^ (uint)local_78);
        return;
      }
      iVar3 = FUN_004f7fb0(param_1);
      if ((iVar3 != 0) &&
         (iVar3 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),"anim_end"), iVar3 == 0)) break;
      iVar3 = FUN_004fc5b0(param_1);
    }
  }
  goto LAB_00586291;
  while( true ) {
    piVar7 = *(int **)(DAT_00954400 + 0x10);
    iVar3 = iVar3 + 1;
    iVar6 = iVar3 * 0x4c;
    if (piVar7[iVar3 * 0x13] == 0) break;
LAB_005861d0:
    iVar6 = FUN_004f8b10(*(undefined4 *)(iVar6 + (int)piVar7),local_2c);
    if (iVar6 == 0) break;
  }
LAB_005861fc:
  if ((iVar3 < (int)(uint)*(ushort *)(DAT_00954400 + 0x14)) &&
     (iVar6 = iVar3 * 0x4c + *(int *)(DAT_00954400 + 0x10),
     *(int *)(iVar3 * 0x4c + *(int *)(DAT_00954400 + 0x10)) != 0)) {
    *(float *)(iVar6 + 0x10) = local_68;
    *(undefined1 *)(iVar6 + 0xb) = local_6d;
    *(float *)(iVar6 + 0x14) = local_64;
    *(float *)(iVar6 + 0x18) = local_60;
    *(char *)(iVar6 + 0xc) = local_6c;
    *(float *)(iVar6 + 0x1c) = local_5c;
    *(char *)(iVar6 + 0xd) = local_6b;
    *(float *)(iVar6 + 0x20) = local_58;
    *(uint *)(iVar6 + 4) = uVar8;
    *(float *)(iVar6 + 0x24) = local_54;
    *(float *)(iVar6 + 0x28) = local_50;
    *(float *)(iVar6 + 0x2c) = local_4c;
    *(float *)(iVar6 + 0x30) = local_48;
    *(float *)(iVar6 + 0x34) = local_44;
    *(float *)(iVar6 + 0x38) = local_40;
    *(undefined2 *)(iVar6 + 0x48) = local_30;
    *(undefined1 *)(iVar6 + 0x4a) = local_2e;
  }
LAB_00586291:
  __security_check_cookie(local_4 ^ (uint)local_78);
  return;
}

