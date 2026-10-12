/* Ghidra analysis pseudocode, not original source.
 * ev_5f3da693bf096313253939ed49ba5271cfe8862e4a440ae5c9d57980f69a0d69
 * Entry: 0x456c10; label: FUN_00456c10
 */

void FUN_00456c10(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  short sVar2;
  ushort uVar3;
  char cVar4;
  undefined2 uVar5;
  short sVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  float10 fVar11;
  float fVar12;
  int local_2a0;
  int local_29c;
  int local_298;
  float local_294;
  int local_290;
  int local_28c;
  int local_288;
  int local_284;
  int local_280;
  int local_27c;
  float local_278;
  undefined4 local_274;
  int local_270;
  float local_26c;
  undefined4 local_268;
  int local_264;
  float local_260;
  int local_25c;
  int local_258;
  undefined4 local_254;
  undefined4 local_250;
  undefined4 local_24c;
  float local_248;
  int local_244;
  float local_240;
  float local_23c;
  float local_238;
  uint local_234;
  uint local_230;
  uint local_22c;
  float local_228;
  uint local_224;
  uint local_220;
  float local_21c;
  float local_218;
  int local_214;
  int local_210;
  float local_20c;
  int local_208;
  float local_204;
  float local_200;
  undefined4 local_1fc;
  int local_1f8;
  undefined4 local_1f4;
  int local_1f0;
  int local_1ec;
  int local_1e8;
  float local_1e4;
  int local_1e0;
  int local_1dc;
  int local_1d8;
  undefined1 local_1d4 [252];
  int local_d8 [32];
  short asStack_58 [10];
  char local_44 [64];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_2a0;
  local_288 = param_1;
  local_2a0 = param_2;
  local_258 = param_3;
  local_27c = -1;
  local_280 = -1;
  local_29c = 0;
  local_210 = 1;
  local_28c = 1;
  local_244 = 0;
  local_274 = 1;
  local_268 = 0;
  local_1e0 = 0;
  local_1e8 = 0;
  local_1f0 = 0;
  local_264 = 0;
  local_1d8 = 0;
  _memset(local_1d4,0,0xfc);
  local_290 = 0;
  local_234 = 0;
  builtin_strncpy(local_44,"default",8);
  _memset(local_44 + 8,0,0x38);
  local_204 = 0.8;
  local_20c = 0.8;
  local_1dc = 0;
  local_240 = 0.0;
  local_284 = 0;
  local_23c = 0.0;
  local_1fc = 2;
  local_238 = 0.0;
  local_270 = 0;
  local_200 = 0.0;
  local_294 = 0.0;
  local_1e4 = 0.0;
  local_25c = 0;
  local_228 = 0.0;
  local_1f8 = 0;
  local_21c = 0.0;
  local_214 = 0;
  local_1ec = 0;
  local_218 = 1e+09;
  local_208 = 1;
  local_260 = 1e+09;
  local_298 = 0;
  local_248 = 1e+09;
  local_230 = 0;
  local_22c = 0;
  local_224 = 0;
  local_220 = 0;
  if (param_6 != 0) {
    if ((param_3 != 0) && (iVar9 = *(int *)(param_3 + 0xd0), iVar9 != 0)) {
      local_254 = *(undefined4 *)(iVar9 + 0x5c);
      local_250 = *(undefined4 *)(iVar9 + 0x60);
      local_24c = *(undefined4 *)(iVar9 + 100);
      local_294 = (float)(uint)*(ushort *)(iVar9 + 0x27a);
      local_270 = param_3 + 0x158;
    }
    iVar9 = 0;
    if (0 < param_5) {
      do {
        iVar7 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar9 * 4),"mingroupsize");
        if (iVar7 == 0) {
          iVar7 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar9 * 4),"maxgroupsize");
          if (iVar7 == 0) {
            iVar7 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar9 * 4),"groupsize");
            if (iVar7 == 0) {
              iVar7 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar9 * 4),"start_locator_set=");
              if (iVar7 == 0) {
                iVar7 = FUN_004f8b10("dont_inherit_locator_set",*(undefined4 *)(param_4 + iVar9 * 4)
                                    );
                if (iVar7 == 0) {
                  local_208 = 0;
                }
                else {
                  iVar7 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar9 * 4),"locator_set=");
                  if (iVar7 == 0) {
                    iVar7 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar9 * 4),"locator=");
                    if (iVar7 == 0) {
                      iVar7 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar9 * 4),
                                           "max_range_to_player=");
                      if (iVar7 == 0) {
                        iVar7 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar9 * 4),"mindy=");
                        if (iVar7 == 0) {
                          iVar7 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar9 * 4),"maxdy=");
                          if (iVar7 == 0) {
                            iVar7 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar9 * 4),"zipup");
                            if (iVar7 == 0) {
                              iVar7 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar9 * 4),
                                                   "type=randommap");
                              if (iVar7 == 0) {
                                iVar7 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar9 * 4),
                                                     "type=generic_goon");
                                if (iVar7 == 0) {
                                  iVar7 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar9 * 4),
                                                       &DAT_0075772c);
                                  if (iVar7 == 0) {
                                    iVar7 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar9 * 4),
                                                         "state=");
                                    if (iVar7 == 0) {
                                      iVar7 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar9 * 4),
                                                           "script");
                                      if (iVar7 == 0) {
                                        iVar7 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar9 * 4),
                                                             "xspacing");
                                        if (iVar7 == 0) {
                                          iVar7 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar9 * 4),
                                                               "zspacing");
                                          if (iVar7 == 0) {
                                            iVar7 = FUN_004f8a70(*(undefined4 *)
                                                                  (param_4 + iVar9 * 4),"xoffset");
                                            if (iVar7 == 0) {
                                              iVar7 = FUN_004f8a70(*(undefined4 *)
                                                                    (param_4 + iVar9 * 4),"yoffset")
                                              ;
                                              if (iVar7 == 0) {
                                                iVar7 = FUN_004f8a70(*(undefined4 *)
                                                                      (param_4 + iVar9 * 4),
                                                                     "zoffset");
                                                if (iVar7 == 0) {
                                                  iVar7 = FUN_004f8a70(*(undefined4 *)
                                                                        (param_4 + iVar9 * 4),
                                                                       "nacross");
                                                  if (iVar7 == 0) {
                                                    iVar7 = FUN_004f8a70(*(undefined4 *)
                                                                          (param_4 + iVar9 * 4),
                                                                         "addtoset=myset");
                                                    if (iVar7 == 0) {
                                                      iVar7 = FUN_004f8a70(*(undefined4 *)
                                                                            (param_4 + iVar9 * 4),
                                                                           "addtoset=");
                                                      if (iVar7 == 0) {
                                                        iVar7 = FUN_004f8a70(*(undefined4 *)
                                                                              (param_4 + iVar9 * 4),
                                                                             "crate_height=");
                                                        if (iVar7 == 0) {
                                                          iVar7 = FUN_004f8a70(*(undefined4 *)
                                                                                (param_4 + iVar9 * 4
                                                                                ),"crate_delay=");
                                                          if (iVar7 == 0) {
                                                            iVar7 = FUN_004f8b10("not_grouped",
                                                                                 *(undefined4 *)
                                                                                  (param_4 +
                                                                                  iVar9 * 4));
                                                            if (iVar7 == 0) {
                                                              local_210 = 0;
                                                            }
                                                            else {
                                                              iVar7 = FUN_004f8b10(
                                                  "dont_set_on_surface",
                                                  *(undefined4 *)(param_4 + iVar9 * 4));
                                                  if (iVar7 == 0) {
                                                    local_274 = 0;
                                                  }
                                                  else {
                                                    iVar7 = FUN_004f8b10("zipdown",
                                                                         *(undefined4 *)
                                                                          (param_4 + iVar9 * 4));
                                                    if (iVar7 == 0) {
                                                      local_1f8 = 1;
                                                      local_274 = 0;
                                                    }
                                                    else {
                                                      iVar7 = FUN_004f8b10("nearest_player",
                                                                           *(undefined4 *)
                                                                            (param_4 + iVar9 * 4));
                                                      if (iVar7 == 0) {
                                                        local_214 = 1;
                                                      }
                                                      else {
                                                        iVar7 = FUN_004f8b10("off_screen",
                                                                             *(undefined4 *)
                                                                              (param_4 + iVar9 * 4))
                                                        ;
                                                        if ((iVar7 == 0) ||
                                                           (iVar7 = FUN_004f8b10("offscreen",
                                                                                 *(undefined4 *)
                                                                                  (param_4 +
                                                                                  iVar9 * 4)),
                                                           iVar7 == 0)) {
                                                          local_1ec = 1;
                                                        }
                                                        else {
                                                          iVar7 = FUN_004f8b10("on_screen",
                                                                               *(undefined4 *)
                                                                                (param_4 + iVar9 * 4
                                                                                ));
                                                          if (iVar7 == 0) {
                                                            local_268 = 1;
                                                          }
                                                          else {
                                                            iVar7 = FUN_004f8a70(*(undefined4 *)
                                                                                  (param_4 +
                                                                                  iVar9 * 4),
                                                                                 "fall_chance=");
                                                            if (iVar7 == 0) {
                                                              iVar7 = FUN_004f8b10("CheapAsChips",
                                                                                   *(undefined4 *)
                                                                                    (param_4 +
                                                                                    iVar9 * 4));
                                                              if (iVar7 == 0) {
                                                                local_1e0 = 1;
                                                              }
                                                              else {
                                                                iVar7 = FUN_004f8a70(*(undefined4 *)
                                                                                      (param_4 +
                                                                                      iVar9 * 4),
                                                                                                                                                                          
                                                  "ridden_by=myself");
                                                  if (iVar7 == 0) {
                                                    iVar7 = FUN_004f8a70(*(undefined4 *)
                                                                          (param_4 + iVar9 * 4),
                                                                         "ridden_by=");
                                                    if (iVar7 == 0) {
                                                      iVar7 = FUN_004f8b10("no_gun",*(undefined4 *)
                                                                                     (param_4 +
                                                                                     iVar9 * 4));
                                                      if (iVar7 == 0) {
                                                        local_1e8 = 1;
                                                      }
                                                      else {
                                                        iVar7 = FUN_004f8b10("ballooning",
                                                                             *(undefined4 *)
                                                                              (param_4 + iVar9 * 4))
                                                        ;
                                                        if (iVar7 == 0) {
                                                          local_1f0 = 1;
                                                          local_274 = 0;
                                                        }
                                                        else {
                                                          iVar7 = FUN_004f8a70(*(undefined4 *)
                                                                                (param_4 + iVar9 * 4
                                                                                ),"lose_capability="
                                                                              );
                                                          if (iVar7 == 0) {
                                                            iVar7 = FUN_004f8a70(*(undefined4 *)
                                                                                  (param_4 +
                                                                                  iVar9 * 4),
                                                                                 "capability=");
                                                            if (iVar7 != 0) {
                                                              FUN_004f1ff0("capability=");
                                                              uVar8 = FUN_0044d870();
                                                              local_230 = local_230 | uVar8;
                                                              local_22c = local_22c |
                                                                          (int)uVar8 >> 0x1f;
                                                            }
                                                          }
                                                          else {
                                                            FUN_004f1ff0("lose_capability=");
                                                            uVar8 = FUN_0044d870();
                                                            local_224 = local_224 | uVar8;
                                                            local_220 = local_220 |
                                                                        (int)uVar8 >> 0x1f;
                                                          }
                                                        }
                                                      }
                                                    }
                                                    else {
                                                      local_284 = FUN_00440120(local_288,iVar7 + 10)
                                                      ;
                                                    }
                                                  }
                                                  else if ((local_258 != 0) &&
                                                          (*(int **)(local_258 + 0xd0) != (int *)0x0
                                                          )) {
                                                    local_284 = **(int **)(local_258 + 0xd0);
                                                  }
                                                  }
                                                  }
                                                  else {
                                                    fVar11 = (float10)FUN_005147c0(local_2a0,
                                                                                   iVar7 + 0xc);
                                                    local_21c = (float)fVar11;
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  else {
                                                    fVar11 = (float10)FUN_005147c0(local_2a0,
                                                                                   iVar7 + 0xc);
                                                    local_1e4 = (float)fVar11;
                                                  }
                                                  }
                                                  else {
                                                    fVar11 = (float10)FUN_005147c0(local_2a0,
                                                                                   iVar7 + 0xd);
                                                    local_200 = (float)fVar11;
                                                  }
                                                  }
                                                  else {
                                                    FUN_005147c0(local_2a0,iVar7 + 9);
                                                    local_234 = FUN_006e6b90();
                                                  }
                                                  }
                                                  else {
                                                    local_234 = (uint)*(byte *)(local_2a0 + 0xb0);
                                                  }
                                                  }
                                                  else {
                                                    FUN_005147c0(local_2a0,iVar7 + 8);
                                                    local_1fc = FUN_006e6b90();
                                                  }
                                                }
                                                else {
                                                  fVar11 = (float10)FUN_005147c0(local_2a0,iVar7 + 8
                                                                                );
                                                  local_238 = (float)fVar11;
                                                }
                                              }
                                              else {
                                                fVar11 = (float10)FUN_005147c0(local_2a0,iVar7 + 8);
                                                local_23c = (float)fVar11;
                                              }
                                            }
                                            else {
                                              fVar11 = (float10)FUN_005147c0(local_2a0,iVar7 + 8);
                                              local_240 = (float)fVar11;
                                            }
                                          }
                                          else {
                                            fVar11 = (float10)FUN_005147c0(local_2a0,iVar7 + 9);
                                            local_20c = (float)fVar11;
                                          }
                                        }
                                        else {
                                          fVar11 = (float10)FUN_005147c0(local_2a0,iVar7 + 9);
                                          local_204 = (float)fVar11;
                                        }
                                      }
                                      else {
                                        FUN_004f1f10(local_44,iVar7 + 7);
                                      }
                                    }
                                    else {
                                      local_1dc = iVar7 + 6;
                                    }
                                  }
                                  else {
                                    iVar7 = iVar7 + 5;
                                    if ((DAT_00923884 != (code *)0x0) &&
                                       (DAT_00923894 != (code *)0x0)) {
                                      if (*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_00951b94) {
                                        iVar10 = FUN_004f8b10("Barman");
                                        sVar6 = DAT_007f18fc;
                                        if (((iVar10 == 0) ||
                                            (iVar10 = FUN_004f8b10("JABBA",iVar7),
                                            sVar6 = DAT_007f1958, iVar10 == 0)) ||
                                           (iVar7 = FUN_004f8b10("CANTINABAND",iVar7),
                                           sVar6 = DAT_007f1a74, iVar7 == 0)) {
                                          sVar2 = *(short *)(*(int *)(DAT_029130e4 + 0x1c) +
                                                            sVar6 * 2);
                                          goto LAB_00457284;
                                        }
                                      }
                                      else {
                                        cVar4 = (*DAT_00923884)(iVar7);
                                        if (cVar4 != -1) {
                                          sVar6 = (*DAT_00923894)(cVar4);
                                          sVar2 = sVar6;
LAB_00457284:
                                          if ((sVar2 != -1) && (local_29c < 10)) {
                                            asStack_58[local_29c] = sVar6;
                                            local_29c = local_29c + 1;
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                                else if ((local_29c < 10) && (sVar6 = FUN_00440030(0), sVar6 != -1))
                                {
                                  asStack_58[local_29c] = sVar6;
                                  local_29c = local_29c + 1;
                                }
                              }
                              else if (*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_00951b94) {
                                sVar6 = FUN_00491800();
                                sVar2 = sVar6;
                                goto LAB_00457284;
                              }
                            }
                            else if ((local_290 < 0x20) &&
                                    (iVar7 = FUN_00449ee0(iVar7 + 6), iVar7 != 0)) {
                              local_d8[local_25c] = iVar7;
                              local_25c = local_25c + 1;
                            }
                          }
                          else {
                            fVar11 = (float10)FUN_005147c0(local_2a0,iVar7 + 6);
                            local_248 = (float)fVar11;
                          }
                        }
                        else {
                          fVar11 = (float10)FUN_005147c0(local_2a0,iVar7 + 6);
                          local_260 = (float)fVar11;
                        }
                      }
                      else {
                        fVar11 = (float10)FUN_005147c0(local_2a0,iVar7 + 0x14);
                        local_218 = (float)fVar11;
                      }
                    }
                    else if (local_290 < 0x40) {
                      iVar10 = FUN_004f8b10("mylocator",iVar7 + 8);
                      if (iVar10 == 0) {
                        iVar7 = *(int *)(local_2a0 + 0xa4);
                      }
                      else {
                        iVar7 = FUN_0051ac10(local_288,iVar7 + 8);
                      }
                      if (iVar7 != 0) {
                        *(int *)(local_1d4 + local_290 * 4 + -4) = iVar7;
                        local_290 = local_290 + 1;
                      }
                    }
                  }
                  else {
                    iVar10 = FUN_004f8b10("myset",iVar7 + 0xc);
                    if (iVar10 == 0) {
                      iVar7 = *(int *)(local_2a0 + 0xa8);
                    }
                    else {
                      iVar7 = FUN_0051ac70(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ae8),iVar7 + 0xc);
                    }
                    local_298 = iVar7;
                    if (iVar7 != 0) {
                      FUN_0051fe60(local_288,iVar7);
                      cVar4 = *(char *)(iVar7 + 0x10);
                      iVar10 = 0;
                      if (0 < cVar4) {
                        do {
                          if (0x3f < local_290) break;
                          if (*(char *)(iVar10 + *(int *)(iVar7 + 0x18)) == -1) {
                            *(uint *)(local_1d4 + local_290 * 4 + -4) =
                                 *(int *)(local_288 + 0x28) +
                                 (uint)*(byte *)(*(int *)(iVar7 + 0x14) + iVar10) * 0x3c;
                            local_290 = local_290 + 1;
                          }
                          iVar10 = iVar10 + 1;
                        } while (iVar10 < cVar4);
                      }
                    }
                  }
                }
              }
              else {
                iVar10 = FUN_004f8b10("myset",iVar7 + 0x12);
                if (iVar10 == 0) {
                  local_298 = *(int *)(local_2a0 + 0xa8);
                }
                else {
                  local_298 = FUN_0051ac70(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ae8),iVar7 + 0x12);
                }
                if (local_298 != 0) {
                  local_264 = 1;
                }
              }
            }
            else {
              FUN_005147c0(local_2a0,iVar7 + 10);
              local_28c = FUN_006e6b90();
            }
          }
          else {
            FUN_005147c0(local_2a0,iVar7 + 0xd);
            local_280 = FUN_006e6b90();
          }
        }
        else {
          FUN_005147c0(local_2a0,iVar7 + 0xd);
          local_27c = FUN_006e6b90();
        }
        iVar10 = local_27c;
        iVar7 = local_280;
        iVar9 = iVar9 + 1;
      } while (iVar9 < param_5);
      if (-1 < local_27c) {
        if (local_27c < local_280) {
          iVar9 = FUN_005b9e90(0);
          local_28c = iVar9 % ((iVar7 - iVar10) + 1) + iVar10;
        }
        else if (local_280 == local_27c) {
          local_28c = local_27c;
        }
      }
      if (local_28c == 0) goto LAB_00457e76;
    }
    do {
      if (((((local_290 == 0) && (local_25c == 0)) && (local_284 == 0)) && (local_264 == 0)) ||
         (local_29c == 0)) break;
      iVar9 = FUN_005b9e90(0);
      iVar7 = 0;
      local_2a0 = 0;
      sVar6 = asStack_58[iVar9 % local_29c];
      if (local_290 == 0) {
        if (local_264 != 0) {
LAB_004578d1:
          if (local_298 == 0) goto LAB_004578e7;
          iVar7 = FUN_00440640();
          goto LAB_004579de;
        }
        if (local_25c == 0) {
          if (local_284 != 0) {
            local_254 = *(undefined4 *)(local_284 + 0x438);
            local_270 = local_284 + 0x420;
            local_250 = *(undefined4 *)(local_284 + 0x43c);
            local_24c = *(undefined4 *)(local_284 + 0x440);
            local_294 = (float)(uint)*(ushort *)(local_284 + 0x27a);
          }
        }
        else {
          local_2a0 = FUN_00449e60(local_25c);
          if (local_2a0 == 0) break;
          local_254 = *(undefined4 *)(local_2a0 + 0x10);
          local_250 = *(undefined4 *)(local_2a0 + 0x14);
          local_24c = *(undefined4 *)(local_2a0 + 0x18);
          local_270 = 0;
          local_274 = 0;
        }
        if (local_244 == 0) goto LAB_0045785a;
      }
      else {
        if (local_264 != 0) goto LAB_004578d1;
LAB_004578e7:
        if (local_1ec == 0) {
          local_294 = 0.0;
        }
        else {
          local_294 = *(float *)(sVar6 * 0x4c + 0x30 + *(int *)(DAT_029130e4 + 0x20)) + 0.5;
        }
        if (local_214 == 0) {
          if (local_218 == 1e+09) {
            iVar9 = 0;
            fVar12 = 1e+09;
          }
          else {
            iVar9 = DAT_0093d810 + 0x80;
            fVar12 = local_218;
          }
          iVar7 = FUN_00440290(&local_1d8,local_290,local_294,iVar9,fVar12,local_268,local_248,
                               local_260);
        }
        else {
          iVar7 = FUN_00440470(&local_1d8,local_290,local_294,DAT_0093d810 + 0x5c,local_218,
                               local_268,local_248,local_260);
        }
LAB_004579de:
        if (iVar7 == 0) break;
        local_254 = *(undefined4 *)(iVar7 + 0x10);
        local_250 = *(undefined4 *)(iVar7 + 0x14);
        local_270 = iVar7 + 0x20;
        local_24c = *(undefined4 *)(iVar7 + 0x18);
        local_294 = *(float *)(iVar7 + 0x1c);
        local_244 = 0;
LAB_0045785a:
        if (((local_240 != 0.0) || (local_23c != 0.0)) || (local_238 != 0.0)) {
          FUN_005b3620(&local_240,&local_240,local_294);
          FUN_005b37d0(&local_254,&local_254,&local_240);
          local_244 = 1;
        }
      }
      if (0 < local_28c) {
        local_1f4 = 0;
        local_27c = local_28c;
        if (local_210 == 0) {
          local_27c = 1;
        }
        local_28c = local_28c - local_27c;
        local_280 = 0;
        if (0 < local_27c) {
          local_258 = (int)sVar6;
          do {
            if ((local_280 == 0) && (1 < local_27c)) {
              local_1f4 = FUN_00517fd0(local_288,local_1fc,local_204,local_20c,
                                       *(undefined4 *)
                                        (*(int *)(local_258 * 0x4c + 0x24 +
                                                 *(int *)(DAT_029130e4 + 0x20)) + 0x1c));
            }
            iVar9 = FUN_0043d890(local_258,&local_254,local_294,local_44,local_270,local_1f4,
                                 local_274,0,0,0,local_234);
            if (iVar9 != 0) {
              if (local_1dc != 0) {
                FUN_0052c790(iVar9 + 0x2c8,local_1dc);
              }
              *(int *)(iVar9 + 0x36c) = iVar7;
              if (local_208 != 0) {
                *(int *)(iVar9 + 0x370) = local_298;
              }
              if (local_1e8 != 0) {
                *(uint *)(iVar9 + 0xeec) = *(uint *)(iVar9 + 0xeec) & 0xfffffffb;
              }
              if (local_200 != 0.0) {
                FUN_004302e0(iVar9,local_200,local_228);
              }
              local_228 = local_228 + local_1e4;
              if ((local_298 != 0) && (*(int *)(iVar9 + 0x36c) != 0)) {
                iVar10 = 0;
                if (0 < *(char *)(local_298 + 0x10)) {
                  do {
                    if ((uint)*(byte *)(*(int *)(local_298 + 0x14) + iVar10) ==
                        (*(int *)(iVar9 + 0x36c) - *(int *)(local_288 + 0x28)) / 0x3c) {
                      *(undefined1 *)(iVar10 + *(int *)(local_298 + 0x18)) =
                           *(undefined1 *)(iVar9 + 0x28d);
                      break;
                    }
                    iVar10 = iVar10 + 1;
                  } while (iVar10 < *(char *)(local_298 + 0x10));
                }
              }
              if (local_2a0 == 0) {
                if ((local_1f8 != 0) &&
                   ((local_21c <= 0.0 ||
                    (fVar11 = (float10)FUN_005b9dd0(), (float10)local_21c <= fVar11)))) {
                  *(undefined4 *)(iVar9 + 0x748) = *(undefined4 *)(iVar9 + 400);
                  *(undefined4 *)(iVar9 + 0x74c) = *(undefined4 *)(iVar9 + 0x194);
                  *(undefined1 *)(iVar9 + 0x7b5) = 0x35;
                  *(undefined2 *)(iVar9 + 0x7aa) = 0x2a;
                  *(undefined4 *)(iVar9 + 0x750) = *(undefined4 *)(iVar9 + 0x198);
                  FUN_0058d430(iVar9);
                }
              }
              else {
                *(int *)(iVar9 + 0x798) = local_2a0;
                *(ushort *)(local_2a0 + 0x68) = *(ushort *)(local_2a0 + 0x68) | 0x100;
                iVar10 = *(int *)(iVar9 + 0x798);
                *(uint *)(iVar9 + 0x7bc) = *(uint *)(iVar9 + 0x7bc) | 0x20;
                *(undefined1 *)(iVar9 + 0x7b5) = 0x47;
                *(undefined2 *)(iVar9 + 0x7aa) = 0x2a;
                local_26c = *(float *)(iVar10 + 0x28) - *(float *)(iVar10 + 0x10);
                uVar5 = FUN_005be2d0(local_26c,*(float *)(iVar10 + 0x30) - *(float *)(iVar10 + 0x18)
                                    );
                *(uint *)(iVar9 + 0xe20) = *(uint *)(iVar9 + 0xe20) | 0x10000;
                *(undefined4 *)(iVar9 + 0x6c) = 0;
                *(undefined2 *)(iVar9 + 0x5a) = uVar5;
                if (1.0 <= *(float *)(iVar9 + 0xd3c)) {
                  *(undefined1 *)(iVar9 + 0xe33) = 0;
                }
                else {
                  *(undefined1 *)(iVar9 + 0xe33) = 1;
                }
                *(undefined4 *)(iVar9 + 0x77c) = 0;
                FUN_00681f40("ZipUp",iVar9 + 0x80);
                FUN_00547f30(iVar9,0);
                iVar1 = *(int *)(iVar9 + 0x798);
                *(undefined1 *)(iVar9 + 0xe32) = 0;
                fVar12 = *(float *)(iVar1 + 0x1c) - *(float *)(iVar10 + 0x10);
                local_26c = *(float *)(iVar1 + 0x24) - *(float *)(iVar10 + 0x18);
                local_278 = fVar12 * fVar12 + local_26c * local_26c;
                fVar11 = (float10)FUN_005c0240(local_278);
                local_278 = *(float *)(iVar1 + 0x20) - *(float *)(iVar10 + 0x14);
                iVar10 = FUN_005be2d0(local_278,(float)fVar11);
                uVar3 = (ushort)(iVar10 >> 0x1f);
                sVar6 = 0x4000 - (((ushort)iVar10 ^ uVar3) - uVar3);
                if (iVar10 < 0) {
                  sVar6 = -sVar6;
                }
                *(short *)(iVar9 + 0x7a4) = sVar6;
              }
              if (local_1e0 != 0) {
                *(uint *)(iVar9 + 0x1fc) = *(uint *)(iVar9 + 0x1fc) | 0x420;
              }
              if (local_284 == 0) {
                if ((local_1f0 != 0) && (FUN_0049d4d0(iVar9,0), iVar7 != 0)) {
                  FUN_0049d520(iVar9,*(undefined4 *)(iVar7 + 0x14));
                }
              }
              else {
                FUN_00488730(local_284,iVar9,0,1);
              }
              if (local_230 != 0 || local_22c != 0) {
                *(uint *)(iVar9 + 0x4bc) = *(uint *)(iVar9 + 0x4bc) | local_230;
              }
              if (local_224 != 0 || local_220 != 0) {
                *(uint *)(iVar9 + 0x4bc) = *(uint *)(iVar9 + 0x4bc) & ~local_224;
              }
            }
            local_280 = local_280 + 1;
          } while (local_280 < local_27c);
        }
      }
    } while (local_28c != 0);
  }
LAB_00457e76:
  __security_check_cookie(local_4 ^ (uint)&local_2a0);
  return;
}

