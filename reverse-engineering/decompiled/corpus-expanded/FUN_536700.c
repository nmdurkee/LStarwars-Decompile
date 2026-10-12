/* Ghidra pseudocode, not original source.
 * ev_b6e394b5e6447b25b30eeb5758ac1a35d86131e46c625f62ba009b62f4fc19bf
 * Entry: 0x536700; label: FUN_00536700
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00536700(float param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
                 float param_7)

{
  char cVar1;
  int iVar2;
  int iVar3;
  float10 fVar4;
  undefined4 uVar5;
  int iStack_6c;
  float local_68;
  float local_64;
  float local_60;
  int local_5c;
  float local_58;
  int local_54;
  undefined1 local_50 [12];
  char acStack_44 [64];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&iStack_6c;
  local_58 = 0.0;
  local_60 = 0.0;
  iVar3 = 0;
  local_64 = param_1;
  local_68 = 0.0;
  local_54 = 0;
  local_5c = 0;
  if ((((param_3 != 0) && (*(int **)(param_3 + 0xd0) != (int *)0x0)) &&
      (**(int **)(param_3 + 0xd0) != 0)) &&
     ((*(int *)(param_3 + 0x158) != 0 && (*(int *)(param_3 + 0x15c) != 0)))) {
    if (param_6 == 0) {
      iVar3 = *(int *)(param_2 + 0x6c);
      if (iVar3 != 0) {
        iVar2 = iVar3 + 0x10;
        if ((*(byte *)(param_2 + 0x68) & 8) == 0) {
          uVar5 = 1;
        }
        else {
          uVar5 = 7;
        }
        FUN_0052fcb0(param_3,iVar2,0,iVar3 + 0x20,uVar5,*(undefined4 *)(param_3 + 0x180));
        if (((*(byte *)(param_2 + 0x68) & 4) != 0) && (*(int *)(param_3 + 0xe4) != 0)) {
          *(int *)(param_3 + 0x1e4) = *(int *)(param_3 + 0xe4) + 0x5c;
        }
        if (((*(byte *)(param_2 + 0x68) & 1) != 0) &&
           (*(char *)(*(int *)(param_3 + 0xd0) + 0x281) == '\0')) {
LAB_00536d9e:
          __security_check_cookie(local_4 ^ (uint)&iStack_6c);
          return;
        }
        if ((*(byte *)(param_2 + 0x68) & 2) == 0) {
          fVar4 = (float10)FUN_005b3c50(param_3 + 0x14c,iVar2,local_50);
        }
        else {
          fVar4 = (float10)FUN_005b3cf0(param_3 + 0x14c,iVar2,local_50);
        }
        local_68 = (float)fVar4;
        local_64 = param_7 * *(float *)(*(int *)(param_3 + 0xd0) + 0x22c) +
                   *(float *)(param_3 + 0x180) + _DAT_00801c6c;
        if (local_64 * local_64 <= local_68) {
          if (((((*(uint *)(param_3 + 0x1e8) & 0x400000) == 0) ||
               ((*(byte *)(param_2 + 0x68) & 0x10) == 0)) || (DAT_009238b8 == (code *)0x0)) ||
             (iVar3 = (*DAT_009238b8)(*(int *)(param_3 + 0xd0),iVar2), iVar3 == 0))
          goto LAB_00536d9e;
        }
        else {
          if (((*(byte *)(param_2 + 0x68) & 4) == 0) || (*(int *)(param_3 + 0xe4) == 0)) {
            *(int *)(param_3 + 0x1e4) = param_2 + 0x78;
          }
          if (0.0 < *(float *)(param_2 + 0x9c)) {
            local_64 = *(float *)(param_2 + 0x9c) - param_7;
            *(float *)(param_2 + 0x9c) = local_64;
            if (local_64 < 0.0) {
              *(undefined4 *)(param_2 + 0x9c) = 0;
              __security_check_cookie(local_4 ^ (uint)&iStack_6c);
              return;
            }
            goto LAB_00536d9e;
          }
        }
      }
    }
    else {
      *(undefined1 *)(param_2 + 0x68) = 0;
      *(undefined4 *)(param_2 + 0x6c) = *(undefined4 *)(param_2 + 0xa4);
      if (0 < param_5) {
        do {
          if ((DAT_009238b0 == (code *)0x0) ||
             (iVar2 = (*DAT_009238b0)(*(undefined4 *)(param_4 + iVar3 * 4),param_3 + 0x13f),
             iVar2 == 0)) {
            iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar3 * 4),&DAT_0075782c);
            if ((iVar2 == 0) &&
               (iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar3 * 4),"teleport"), iVar2 == 0))
            {
              iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar3 * 4),"personal");
              if (iVar2 == 0) {
                iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar3 * 4),"indexed");
                if (iVar2 == 0) {
                  iStack_6c = FUN_004f8a70(*(undefined4 *)(param_4 + iVar3 * 4),"random");
                  if (iStack_6c == 0) {
                    iStack_6c = FUN_004f8a70(*(undefined4 *)(param_4 + iVar3 * 4),"waittime");
                    if (iStack_6c == 0) {
                      iStack_6c = FUN_004f8a70(*(undefined4 *)(param_4 + iVar3 * 4),"mintime");
                      if (iStack_6c == 0) {
                        iStack_6c = FUN_004f8a70(*(undefined4 *)(param_4 + iVar3 * 4),"maxtime");
                        if (iStack_6c == 0) {
                          iStack_6c = FUN_004f8a70(*(undefined4 *)(param_4 + iVar3 * 4),"goalrange")
                          ;
                          if (iStack_6c == 0) {
                            iVar2 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar3 * 4),"on_ground");
                            if (iVar2 == 0) {
                              *(byte *)(param_2 + 0x68) = *(byte *)(param_2 + 0x68) | 1;
                            }
                            else {
                              iVar2 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar3 * 4),
                                                   "xz_rangecheck");
                              if (iVar2 == 0) {
                                *(byte *)(param_2 + 0x68) = *(byte *)(param_2 + 0x68) | 2;
                              }
                              else {
                                iVar2 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar3 * 4),
                                                     "face_opponent");
                                if (iVar2 == 0) {
                                  *(byte *)(param_2 + 0x68) = *(byte *)(param_2 + 0x68) | 4;
                                }
                                else {
                                  iVar2 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar3 * 4),
                                                       "ignore_path");
                                  if (iVar2 == 0) {
                                    *(byte *)(param_2 + 0x68) = *(byte *)(param_2 + 0x68) | 8;
                                  }
                                  else {
                                    iVar2 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar3 * 4),
                                                         "must_reach_destination");
                                    if (iVar2 == 0) {
                                      *(byte *)(param_2 + 0x68) = *(byte *)(param_2 + 0x68) | 0x10;
                                    }
                                    else {
                                      fVar4 = (float10)FUN_00514920(param_3,param_2,
                                                                    *(undefined4 *)
                                                                     (param_4 + iVar3 * 4));
                                      *(float *)(param_3 + 0x180) = (float)fVar4;
                                    }
                                  }
                                }
                              }
                            }
                          }
                          else {
                            iVar2 = FUN_004f1ff0("goalrange");
                            fVar4 = (float10)FUN_00514920(param_3,param_2,iStack_6c + 1 + iVar2);
                            *(float *)(param_3 + 0x180) = (float)fVar4;
                          }
                        }
                        else {
                          iVar2 = FUN_004f1ff0("maxtime");
                          fVar4 = (float10)FUN_00514920(param_3,param_2,iStack_6c + 1 + iVar2);
                          local_60 = (float)fVar4;
                        }
                      }
                      else {
                        iVar2 = FUN_004f1ff0("mintime");
                        fVar4 = (float10)FUN_00514920(param_3,param_2,iStack_6c + 1 + iVar2);
                        local_58 = (float)fVar4;
                      }
                    }
                    else {
                      iVar2 = FUN_004f1ff0("waittime");
                      fVar4 = (float10)FUN_00514920(param_3,param_2,iStack_6c + 1 + iVar2);
                      *(float *)(param_2 + 0x9c) = (float)fVar4;
                    }
                  }
                  else {
                    iVar2 = FUN_004f1ff0("random");
                    FUN_00514920(param_3,param_2,iStack_6c + 1 + iVar2);
                    local_5c = FUN_006e6b90();
                  }
                }
                else {
                  local_54 = 1;
                }
              }
              else {
                local_68 = 1.4013e-45;
              }
            }
            else {
              iVar3 = iVar3 + 1;
              if (iVar3 < param_5) {
                if ((local_54 == 0) ||
                   (cVar1 = *(char *)(*(int *)(param_3 + 0xd0) + 0x280), cVar1 == -1)) {
                  if ((local_68 == 0.0) ||
                     (iVar2 = *(int *)(*(int *)(param_3 + 0xd0) + 0x54), iVar2 == 0)) {
                    if (local_5c == 0) {
                      _sprintf(acStack_44,*(char **)(param_4 + iVar3 * 4));
                    }
                    else {
                      iVar2 = FUN_005b9e90(0);
                      _sprintf(acStack_44,"%s_%d",*(undefined4 *)(param_4 + iVar3 * 4),
                               iVar2 % local_5c);
                    }
                  }
                  else {
                    _sprintf(acStack_44,"%s_%s",*(undefined4 *)(param_4 + iVar3 * 4),
                             *(undefined4 *)(iVar2 + 0xc));
                  }
                }
                else {
                  _sprintf(acStack_44,"%s_%d",*(undefined4 *)(param_4 + iVar3 * 4),(int)cVar1);
                }
                uVar5 = FUN_0051ac10(local_64,acStack_44);
                *(undefined4 *)(param_2 + 0x6c) = uVar5;
              }
              iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + -4 + iVar3 * 4),"teleport");
              if (iVar2 != 0) {
                iVar3 = *(int *)(param_2 + 0x6c);
                if (iVar3 != 0) {
                  iVar2 = *(int *)(param_3 + 0xd0);
                  *(undefined4 *)(iVar2 + 0x5c) = *(undefined4 *)(iVar3 + 0x10);
                  *(undefined4 *)(iVar2 + 0x60) = *(undefined4 *)(iVar3 + 0x14);
                  *(undefined4 *)(iVar2 + 100) = *(undefined4 *)(iVar3 + 0x18);
                }
                goto LAB_00536d5a;
              }
            }
          }
          iVar3 = iVar3 + 1;
        } while (iVar3 < param_5);
      }
      if (*(float *)(param_2 + 0x9c) == 0.0) {
        if (local_60 <= local_58) {
          *(undefined4 *)(param_2 + 0x9c) = 0x3c23d70a;
        }
        else {
          fVar4 = (float10)FUN_005b9dd0();
          *(float *)(param_2 + 0x9c) =
               (float)(fVar4 * ((float10)local_60 - (float10)local_58) + (float10)local_58);
        }
      }
      iVar3 = *(int *)(param_2 + 0x6c);
      if (iVar3 != 0) {
        local_68 = (float)(iVar3 + 0x10);
        if ((*(byte *)(param_2 + 0x68) & 8) == 0) {
          uVar5 = 1;
        }
        else {
          uVar5 = 7;
        }
        FUN_0052fcb0(param_3,local_68,0,iVar3 + 0x20,uVar5,*(undefined4 *)(param_3 + 0x180));
        *(undefined4 *)(param_2 + 0x78) = 0;
        iVar2 = param_2 + 0x78;
        *(undefined4 *)(param_2 + 0x7c) = 0;
        *(undefined4 *)(param_2 + 0x80) = 0x3f800000;
        FUN_005b3620(iVar2,iVar2,*(undefined4 *)(iVar3 + 0x1c));
        FUN_005b37d0(iVar2,iVar2,local_68);
        __security_check_cookie(local_4 ^ (uint)&iStack_6c);
        return;
      }
    }
  }
LAB_00536d5a:
  __security_check_cookie(local_4 ^ (uint)&iStack_6c);
  return;
}

