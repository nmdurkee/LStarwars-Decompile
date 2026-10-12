/* Ghidra analysis pseudocode, not original source.
 * ev_9251851307bb379bfc9bcabd13d9f753a758e856e200aa29981eaf91127b618c
 * Entry: 0x572b00; label: FUN_00572b00
 */

char * FUN_00572b00(undefined4 param_1,int *param_2,undefined4 param_3,int param_4,int *param_5)

{
  char *pcVar1;
  byte bVar2;
  char cVar3;
  undefined2 uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  undefined4 uVar8;
  short *psVar9;
  uint uVar10;
  char *pcVar11;
  int local_10;
  int local_c;
  int local_8;
  char *local_4;
  
  iVar5 = FUN_004fc860(param_1);
  if (iVar5 == 0) {
    FUN_00572ad0(param_1);
    if (param_5 != (int *)0x0) {
      *param_5 = 0;
    }
    return (char *)0x0;
  }
  pcVar11 = (char *)(*param_2 + 3U & 0xfffffffc);
  *param_2 = (int)pcVar11;
  local_c = 0;
  local_8 = 0;
  local_4 = pcVar11;
  iVar6 = FUN_004fc5b0(iVar5);
  do {
    if (iVar6 == 0) {
      FUN_004fa300(iVar5);
      pcVar1 = local_4;
      if (local_c < 1) {
        FUN_00572ad0(param_1);
        return (char *)0x0;
      }
      *param_2 = (int)pcVar11;
      if (param_5 != (int *)0x0) {
        *param_5 = local_c;
      }
      local_10 = 0;
      if (0 < local_c) {
        do {
          if (*(short *)(pcVar1 + local_10 * 0x9c + 0x84) == 0) {
            if ((*(ushort *)(pcVar1 + local_10 * 0x9c + 0x7a) & 0x104) == 4) {
              *(undefined2 *)(pcVar1 + local_10 * 0x9c + 0x84) = DAT_00803788;
            }
            else if ((*(ushort *)(pcVar1 + local_10 * 0x9c + 0x7a) & 0x10) != 0) {
              *(undefined2 *)(pcVar1 + local_10 * 0x9c + 0x84) = DAT_0080378c;
            }
          }
          if (pcVar1[local_10 * 0x9c + 0x7e] != -1) {
            FUN_0056e580((int)pcVar1[local_10 * 0x9c + 0x7e],local_10);
          }
          if (((*(short *)(pcVar1 + local_10 * 0x9c + 0x84) != 0) &&
              ((*(ushort *)(pcVar1 + local_10 * 0x9c + 0x7a) & 0x104) == 0)) &&
             ((*(ushort *)(pcVar1 + local_10 * 0x9c + 0x7a) & 0x10) != 0)) {
            (pcVar1 + local_10 * 0x9c + 0x84)[0] = -0x50;
            (pcVar1 + local_10 * 0x9c + 0x84)[1] = '\x04';
          }
          local_10 = local_10 + 1;
        } while (local_10 < local_c);
      }
      return pcVar1;
    }
    FUN_004f7fb0(iVar5);
    pcVar1 = *(char **)(iVar5 + 0x510);
    if (*pcVar1 != '\0') {
      if (local_8 == 0) {
        iVar6 = FUN_004f8b10(pcVar1,"area_start");
        if ((iVar6 == 0) && (local_c < param_4)) {
          local_8 = 1;
          *pcVar11 = '\0';
          pcVar11[0x40] = '\0';
          pcVar11[0x60] = -1;
          pcVar11[0x61] = -1;
          pcVar11[0x78] = -1;
          pcVar11[0x79] = -1;
          pcVar11[0x7a] = '\0';
          pcVar11[0x7b] = '\0';
          pcVar11[0x7c] = (char)local_c;
          pcVar11[0x7d] = '\0';
          pcVar11[0x7e] = -1;
          pcVar11[0x7f] = '\0';
          pcVar11[0x80] = '\0';
          pcVar11[0x81] = '\0';
          pcVar11[0x82] = '\0';
          pcVar11[0x83] = '\0';
          pcVar11[0x84] = '\0';
          pcVar11[0x85] = '\0';
          pcVar11[0x86] = -1;
          pcVar11[0x87] = -1;
          pcVar11[0x88] = -1;
          pcVar11[0x89] = -1;
          pcVar11[0x8a] = -1;
          pcVar11[0x8b] = -1;
          pcVar11[0x8c] = '\0';
          pcVar11[0x8d] = '\0';
          pcVar11[0x8e] = '\0';
          pcVar11[0x8f] = '\0';
          pcVar11[0x90] = '\0';
          pcVar11[0x91] = '\0';
          pcVar11[0x92] = '\0';
          pcVar11[0x93] = '\0';
          pcVar11[0x94] = -1;
          pcVar11[0x95] = -1;
          pcVar11[0x96] = '\x01';
          pcVar11[0x98] = '\0';
          pcVar11[0x99] = '\0';
          pcVar11[0x9a] = '\0';
          pcVar11[0x9b] = '\0';
        }
      }
      else {
        iVar6 = FUN_004f8b10(pcVar1,"area_end");
        if (iVar6 == 0) {
          local_8 = 0;
          if ((((*pcVar11 != '\0') && (pcVar11[0x40] != '\0')) && (pcVar11[0x7d] != '\0')) &&
             ((pcVar11[0x7a] & 0x20U) == 0)) {
            local_c = local_c + 1;
            pcVar11 = pcVar11 + 0x9c;
          }
        }
        else {
          iVar6 = FUN_004f8b10(*(undefined4 *)(iVar5 + 0x510),&PTR_DAT_00761cc4);
          if (iVar6 == 0) {
            iVar6 = FUN_004f7fb0(iVar5);
            if ((iVar6 != 0) && (iVar6 = FUN_004f1ff0(*(undefined4 *)(iVar5 + 0x510)), iVar6 < 0x40)
               ) {
              FUN_004f1f10(pcVar11,*(undefined4 *)(iVar5 + 0x510));
            }
          }
          else {
            iVar6 = FUN_004f8b10(*(undefined4 *)(iVar5 + 0x510),&DAT_00761cbc);
            if (iVar6 == 0) {
              iVar6 = FUN_004f7fb0(iVar5);
              if ((iVar6 != 0) &&
                 (iVar6 = FUN_004f1ff0(*(undefined4 *)(iVar5 + 0x510)), iVar6 < 0x20)) {
                FUN_004f1f10(pcVar11 + 0x40,*(undefined4 *)(iVar5 + 0x510));
              }
            }
            else {
              iVar6 = FUN_004f8b10(*(undefined4 *)(iVar5 + 0x510),"level");
              if (iVar6 == 0) {
                if ((((byte)pcVar11[0x7d] < 0xc) && (iVar6 = FUN_004f7fb0(iVar5), iVar6 != 0)) &&
                   (FUN_00578da0(*(undefined4 *)(iVar5 + 0x510),&local_10), local_10 != -1)) {
                  uVar10 = (uint)(byte)pcVar11[0x7d];
                  uVar7 = 0;
                  if (uVar10 != 0) {
                    psVar9 = (short *)(pcVar11 + 0x60);
                    do {
                      if (*psVar9 == local_10) break;
                      uVar7 = uVar7 + 1;
                      psVar9 = psVar9 + 1;
                    } while ((int)uVar7 < (int)(uint)(byte)pcVar11[0x7d]);
                  }
                  if (uVar7 == uVar10) {
                    *(undefined2 *)(pcVar11 + uVar10 * 2 + 0x60) = (undefined2)local_10;
                    pcVar11[0x7d] = pcVar11[0x7d] + '\x01';
                  }
                }
              }
              else {
                iVar6 = FUN_004f8b10(*(undefined4 *)(iVar5 + 0x510),"single_buffer");
                if (iVar6 == 0) {
                  *(ushort *)(pcVar11 + 0x7a) = *(ushort *)(pcVar11 + 0x7a) | 8;
                }
                else {
                  iVar6 = FUN_004f8b10(*(undefined4 *)(iVar5 + 0x510),"minikit");
                  if (iVar6 == 0) {
                    *(ushort *)(pcVar11 + 0x7a) = *(ushort *)(pcVar11 + 0x7a) | 0x10;
                    iVar6 = FUN_004f7fb0(iVar5);
                    if (iVar6 != 0) {
                      uVar4 = FUN_0055b1c0(*(undefined4 *)(iVar5 + 0x510));
                      *(undefined2 *)(pcVar11 + 0x8a) = uVar4;
                    }
                  }
                  else {
                    iVar6 = FUN_004f8b10(*(undefined4 *)(iVar5 + 0x510),"test_area");
                    if (iVar6 == 0) {
                      *(ushort *)(pcVar11 + 0x7a) = *(ushort *)(pcVar11 + 0x7a) | 0x20;
                    }
                    else {
                      iVar6 = FUN_004f8b10(*(undefined4 *)(iVar5 + 0x510),"hub_area");
                      if (iVar6 == 0) {
                        *(ushort *)(pcVar11 + 0x7a) = *(ushort *)(pcVar11 + 0x7a) | 0x40;
                      }
                      else {
                        iVar6 = FUN_004f8b10(*(undefined4 *)(iVar5 + 0x510),"override_things_scene")
                        ;
                        if (iVar6 == 0) {
                          *(ushort *)(pcVar11 + 0x7a) = *(ushort *)(pcVar11 + 0x7a) | 0x400;
                        }
                        else {
                          iVar6 = FUN_004f8b10(*(undefined4 *)(iVar5 + 0x510),"vehicle_area");
                          if (iVar6 == 0) {
                            *(ushort *)(pcVar11 + 0x7a) = *(ushort *)(pcVar11 + 0x7a) | 1;
                          }
                          else {
                            iVar6 = FUN_004f8b10(*(undefined4 *)(iVar5 + 0x510),"ending_area");
                            if (iVar6 == 0) {
                              *(ushort *)(pcVar11 + 0x7a) = *(ushort *)(pcVar11 + 0x7a) | 2;
                            }
                            else {
                              iVar6 = FUN_004f8b10(*(undefined4 *)(iVar5 + 0x510),"bonus_area");
                              if (iVar6 == 0) {
                                *(ushort *)(pcVar11 + 0x7a) = *(ushort *)(pcVar11 + 0x7a) | 4;
                              }
                              else {
                                iVar6 = FUN_004f8b10(*(undefined4 *)(iVar5 + 0x510),
                                                     "super_bonus_area");
                                if (iVar6 == 0) {
                                  *(ushort *)(pcVar11 + 0x7a) = *(ushort *)(pcVar11 + 0x7a) | 0x104;
                                }
                                else {
                                  iVar6 = FUN_004f8b10(*(undefined4 *)(iVar5 + 0x510),
                                                       "nocharactercollision");
                                  if ((((iVar6 == 0) ||
                                       (iVar6 = FUN_004f8b10(*(undefined4 *)(iVar5 + 0x510),
                                                             "nocharactercollisions"), iVar6 == 0))
                                      || (iVar6 = FUN_004f8b10(*(undefined4 *)(iVar5 + 0x510),
                                                               "no_character_collision"), iVar6 == 0
                                         )) || (iVar6 = FUN_004f8b10(*(undefined4 *)(iVar5 + 0x510),
                                                                     "no_character_collisions"),
                                               iVar6 == 0)) {
                                    *(ushort *)(pcVar11 + 0x7a) = *(ushort *)(pcVar11 + 0x7a) | 0x80
                                    ;
                                  }
                                  else {
                                    iVar6 = FUN_004f8b10(*(undefined4 *)(iVar5 + 0x510),
                                                         "nopickupgravity");
                                    if (iVar6 == 0) {
                                      *(ushort *)(pcVar11 + 0x7a) =
                                           *(ushort *)(pcVar11 + 0x7a) | 0x200;
                                    }
                                    else {
                                      iVar6 = FUN_004f8b10(*(undefined4 *)(iVar5 + 0x510),
                                                           "no_gold_brick");
                                      if (iVar6 == 0) {
                                        *(ushort *)(pcVar11 + 0x7a) =
                                             *(ushort *)(pcVar11 + 0x7a) | 0x800;
                                      }
                                      else {
                                        iVar6 = FUN_004f8b10(*(undefined4 *)(iVar5 + 0x510),
                                                             "no_completion_points");
                                        if (iVar6 == 0) {
                                          *(ushort *)(pcVar11 + 0x7a) =
                                               *(ushort *)(pcVar11 + 0x7a) | 0x2000;
                                        }
                                        else {
                                          iVar6 = FUN_004f8b10(*(undefined4 *)(iVar5 + 0x510),
                                                               "no_freeplay");
                                          if (iVar6 == 0) {
                                            *(ushort *)(pcVar11 + 0x7a) =
                                                 *(ushort *)(pcVar11 + 0x7a) | 0x1000;
                                          }
                                          else {
                                            iVar6 = FUN_004f8b10(*(undefined4 *)(iVar5 + 0x510),
                                                                 "name_id");
                                            if (iVar6 == 0) {
                                              uVar4 = FUN_004f9e70(iVar5);
                                              *(undefined2 *)(pcVar11 + 0x78) = uVar4;
                                            }
                                            else {
                                              iVar6 = FUN_004f8b10(*(undefined4 *)(iVar5 + 0x510),
                                                                   "text_id");
                                              if (iVar6 == 0) {
                                                uVar4 = FUN_004f9e70(iVar5);
                                                *(undefined2 *)(pcVar11 + 0x94) = uVar4;
                                                iVar6 = FUN_004f7fb0(iVar5);
                                                if (iVar6 != 0) {
                                                  uVar8 = FUN_004f29a0(*(undefined4 *)
                                                                        (iVar5 + 0x510));
                                                  bVar2 = (byte)((int)uVar8 >> 0x1f);
                                                  pcVar11[0x96] = ((byte)uVar8 ^ bVar2) - bVar2;
                                                }
                                              }
                                              else {
                                                iVar6 = FUN_004f8b10(*(undefined4 *)(iVar5 + 0x510),
                                                                     "timetrial_time");
                                                if (iVar6 == 0) {
                                                  uVar4 = FUN_004f9e70(iVar5);
                                                  *(undefined2 *)(pcVar11 + 0x84) = uVar4;
                                                }
                                                else {
                                                  iVar6 = FUN_004f8b10(*(undefined4 *)
                                                                        (iVar5 + 0x510),
                                                                       "redbrick_cheat");
                                                  if (((iVar6 == 0) ||
                                                      (iVar6 = FUN_004f8b10(*(undefined4 *)
                                                                             (iVar5 + 0x510),
                                                                            "redbrick_extra"),
                                                      iVar6 == 0)) &&
                                                     (iVar6 = FUN_004f7fb0(iVar5), iVar6 != 0)) {
                                                    cVar3 = FUN_0056e030(*(undefined4 *)
                                                                          (iVar5 + 0x510));
                                                    pcVar11[0x7e] = cVar3;
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
    iVar6 = FUN_004fc5b0(iVar5);
  } while( true );
}

