/* Ghidra pseudocode, not original source.
 * ev_89fddb9d43176fe460e635fa694f7b202ecc9b6cc52422bc9fe5e2fbe10c5c63
 * Entry: 0x44d900; label: FUN_0044d900
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0044d900(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5,
                 int param_6)

{
  uint uVar1;
  int iVar2;
  undefined1 *puVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  bool bVar7;
  undefined4 local_84;
  int local_80;
  uint local_7c;
  uint local_78;
  undefined4 local_74;
  uint local_70;
  int local_6c;
  uint local_68;
  uint local_64;
  uint *local_60;
  uint local_5c;
  undefined4 local_58;
  undefined4 local_54;
  int local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined1 local_44 [64];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_84;
  uVar5 = 0;
  local_48 = param_1;
  local_74 = param_2;
  local_80 = 0;
  local_50 = 0;
  local_6c = 0;
  local_5c = 0;
  local_68 = 0;
  local_64 = 0;
  local_78 = 0;
  local_70 = 0;
  local_7c = 0;
  local_4c = 0xffffffff;
  local_54 = 0;
  local_84 = 0;
  local_58 = 0;
  if (param_6 != 0) {
    iVar6 = 0;
    if (0 < param_5) {
      do {
        iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar6 * 4),"on_frames");
        if (iVar2 == 0) {
          iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar6 * 4),"from=");
          if (iVar2 == 0) {
            iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar6 * 4),&DAT_00757c50);
            if (iVar2 == 0) {
              iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar6 * 4),"pathname=");
              if (iVar2 == 0) {
                iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar6 * 4),"CheckVisible");
                if (iVar2 == 0) {
                  iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar6 * 4),"bothways");
                  if (iVar2 == 0) {
                    iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar6 * 4),"on_flag");
                    if ((iVar2 == 0) &&
                       (iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar6 * 4),"off_flag"),
                       iVar2 == 0)) {
                      iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar6 * 4),&DAT_00757dfc);
                      if (iVar2 == 0) {
                        iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar6 * 4),"cutscene=");
                        if (iVar2 == 0) {
                          iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar6 * 4),"buildit=");
                          if (iVar2 == 0) {
                            iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar6 * 4),"fakeanimid=")
                            ;
                            if (iVar2 == 0) {
                              iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar6 * 4),
                                                   "gizmo_output=");
                              if (iVar2 == 0) {
                                iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar6 * 4),"gizmo=");
                                if (iVar2 == 0) {
                                  iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar6 * 4),
                                                       "flowbox=");
                                  if (iVar2 == 0) {
                                    iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar6 * 4),
                                                         "blowup=");
                                    if (iVar2 == 0) {
                                      iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar6 * 4),
                                                           "force=");
                                      if (iVar2 == 0) {
                                        iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar6 * 4),
                                                             "obstacle=");
                                        if (iVar2 == 0) {
                                          iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar6 * 4),
                                                               "zipup=");
                                          if (iVar2 != 0) {
                                            local_80 = iVar2 + 6;
                                            local_84 = 9;
                                          }
                                        }
                                        else {
                                          local_80 = iVar2 + 9;
                                          local_84 = 8;
                                        }
                                      }
                                      else {
                                        local_80 = iVar2 + 6;
                                        local_84 = 7;
                                      }
                                    }
                                    else {
                                      local_80 = iVar2 + 7;
                                      local_84 = 4;
                                    }
                                  }
                                  else {
                                    local_80 = FUN_004f1ff0("flowbox=");
                                    local_80 = local_80 + iVar2;
                                    local_84 = 6;
                                  }
                                }
                                else {
                                  local_80 = iVar2 + 6;
                                  local_84 = 3;
                                }
                              }
                              else {
                                FUN_005147c0(local_74,iVar2 + 0xd);
                                local_54 = FUN_006e6b90();
                              }
                            }
                            else {
                              FUN_005147c0(local_74,iVar2 + 0xb);
                              local_4c = FUN_006e6b90();
                              local_84 = 5;
                            }
                          }
                          else {
                            local_80 = iVar2 + 8;
                            local_84 = 2;
                          }
                        }
                        else {
                          local_80 = iVar2 + 9;
                          local_84 = 1;
                        }
                      }
                      else {
                        local_80 = iVar2 + 4;
                        local_84 = 0;
                      }
                    }
                    else {
                      iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar6 * 4),"on_flag");
                      bVar7 = iVar2 == 0;
                      if (bVar7) {
                        local_60 = &local_64;
                      }
                      else {
                        local_60 = &local_68;
                      }
                      iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar6 * 4),"OBSTACLE_OPEN");
                      if (iVar2 == 0) {
                        iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar6 * 4),"OBSTACLE_CLOSED")
                        ;
                        if (iVar2 == 0) {
                          uVar5 = FUN_0044d870();
                          *local_60 = *local_60 | uVar5;
                          uVar5 = local_7c;
                        }
                        else if (bVar7) {
                          local_7c = 0;
                          uVar5 = local_7c;
                        }
                        else {
                          local_70 = 0;
                          uVar5 = local_7c;
                        }
                      }
                      else if (bVar7) {
                        local_7c = 1;
                        uVar5 = local_7c;
                      }
                      else {
                        local_70 = 1;
                        uVar5 = local_7c;
                      }
                    }
                  }
                  else {
                    local_78 = 1;
                  }
                }
                else {
                  local_5c = 1;
                }
              }
              else {
                local_58 = FUN_0051ad20(local_48,iVar2 + 9);
              }
            }
            else {
              local_6c = iVar2 + 3;
            }
          }
          else {
            local_50 = iVar2 + 5;
          }
        }
        iVar6 = iVar6 + 1;
      } while (iVar6 < param_5);
    }
    uVar1 = local_70;
    iVar6 = FUN_0043cca0(*(undefined4 *)(PTR_DAT_00802c54 + 0x4670),
                         *(undefined4 *)(PTR_DAT_00802c54 + 0x2ae8),local_58,local_50,local_6c,
                         local_84,local_80,local_4c,local_54);
    if (iVar6 != 0) {
      *(uint *)(iVar6 + 0x1c) = local_68;
      *(uint *)(iVar6 + 0x20) = local_64;
      *(ushort *)(iVar6 + 0xa6) =
           (ushort)(((((uVar5 & 1) * 2 | uVar1 & 1) * 2 | local_5c & 1) * 2 | local_78 & 1) * 2) |
           *(ushort *)(iVar6 + 0xa6) & 0xffe1;
      local_78 = 0;
      if (0 < param_5) {
        do {
          iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + local_78 * 4),"on_frames");
          if (iVar2 != 0) {
            FUN_004f1f10(local_44,iVar2 + 10);
            puVar3 = (undefined1 *)FUN_004f8a70(local_44,&DAT_00757d6c);
            if (puVar3 != (undefined1 *)0x0) {
              *puVar3 = 0;
              puVar3 = puVar3 + 2;
              iVar2 = FUN_004f8b10(local_44,"lastframe-1");
              if (iVar2 == 0) {
                iVar2 = -2;
              }
              else {
                iVar2 = FUN_004f8b10(local_44,"lastframe");
                if (iVar2 == 0) {
                  iVar2 = -1;
                }
                else {
                  FUN_005147c0(local_74,local_44);
                  iVar2 = FUN_006e6b90();
                }
              }
              iVar4 = FUN_004f8b10(puVar3,"lastframe-1");
              if (iVar4 == 0) {
                iVar4 = -2;
              }
              else {
                iVar4 = FUN_004f8b10(puVar3,"lastframe");
                if (iVar4 == 0) {
                  iVar4 = -1;
                }
                else {
                  FUN_005147c0(local_74,puVar3);
                  iVar4 = FUN_006e6b90();
                }
              }
              if (((iVar2 <= iVar4) || (iVar4 == -1)) || (iVar4 == -2)) {
                FUN_0043cfb0(iVar6,iVar2,iVar4);
              }
            }
          }
          local_78 = local_78 + 1;
        } while ((int)local_78 < param_5);
      }
    }
    __security_check_cookie(local_4 ^ (uint)&local_84);
    return;
  }
  __security_check_cookie(local_4 ^ (uint)&local_84);
  return;
}

