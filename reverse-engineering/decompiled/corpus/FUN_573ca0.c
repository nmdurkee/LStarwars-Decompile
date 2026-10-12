/* Ghidra analysis pseudocode, not original source.
 * ev_9251851307bb379bfc9bcabd13d9f753a758e856e200aa29981eaf91127b618c
 * Entry: 0x573ca0; label: FUN_00573ca0
 */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00573ca0(int param_1,int param_2,undefined4 param_3,short *param_4)

{
  byte bVar1;
  char *pcVar2;
  bool bVar3;
  undefined1 uVar4;
  undefined2 uVar5;
  short sVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined4 uVar10;
  undefined1 *puVar11;
  int local_1414;
  uint local_1410;
  int local_140c;
  undefined4 local_1408;
  int local_1404;
  int local_1400;
  undefined4 local_13fc;
  short *local_13f8;
  undefined1 local_13f4 [480];
  undefined2 auStack_1214 [2];
  byte abStack_1210 [4396];
  undefined1 local_e4 [128];
  undefined2 local_64 [48];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_1414;
  local_1408 = param_3;
  local_13f8 = param_4;
  DAT_00951078 = 0;
  DAT_00951258 = -1;
  DAT_00951284 = 0;
  DAT_00951090 = -1;
  DAT_00951220 = 0;
  DAT_00951158 = -1;
  DAT_00951280 = 0;
  DAT_00951290 = 0xffff;
  DAT_00951018 = 0xffff;
  DAT_0095127c = 0;
  if (param_1 == -1) {
    _DAT_009248d0 = -1;
  }
  else {
    iVar7 = param_1 * 0x9c;
    _DAT_009248d0 = (int)*(short *)(iVar7 + 0x88 + DAT_00951354);
    *(undefined4 *)(iVar7 + 0x80 + DAT_00951354) = 0;
    *(undefined1 *)(iVar7 + 0x7f + DAT_00951354) = 0;
  }
  iVar7 = FUN_0058a900(DAT_009553d4);
  if ((iVar7 != 0) && (*(char *)(DAT_009553d4 + 0x1f) != '\0')) {
    FUN_004ef660(local_64,DAT_009553d4 + 0x20,(uint)*(byte *)(DAT_009553d4 + 0x1f) * 2);
    if (2 < *(byte *)(DAT_009553d4 + 0x1f)) {
      iVar7 = (uint)*(byte *)(DAT_009553d4 + 0x1f) * 3;
      local_1414 = 0;
      if (iVar7 != 0) {
        do {
          iVar8 = FUN_0054fa60();
          iVar8 = iVar8 / ((int)(0xffff / (ulonglong)
                                          (longlong)(int)(uint)*(byte *)(DAT_009553d4 + 0x1f)) + 1);
          bVar1 = *(byte *)(DAT_009553d4 + 0x1f);
          iVar9 = FUN_0054fa60();
          local_1410 = (int)(0xffff / (longlong)(int)(bVar1 - 1)) + 1;
          uVar5 = local_64[iVar8];
          local_64[iVar8] = local_64[(iVar9 / (int)local_1410 + iVar8) % (int)(uint)bVar1];
          local_1414 = local_1414 + 1;
          local_64[(iVar9 / (int)local_1410 + iVar8) % (int)(uint)bVar1] = uVar5;
        } while (local_1414 < iVar7);
      }
    }
    iVar7 = DAT_009553d4;
    local_1414 = 0;
    iVar8 = DAT_00951280;
    if (*(char *)(DAT_009553d4 + 0x1f) != '\0') {
      local_1414 = 0;
      iVar9 = DAT_00951078;
      do {
        if (iVar8 < 0x30) {
          (&DAT_00951290)[iVar8 * 2] = local_64[local_1414];
          (&DAT_00951292)[iVar8 * 2] = 1;
          iVar8 = iVar8 + 1;
          DAT_00951280 = iVar8;
        }
        if (iVar9 < 8) {
          (&DAT_00951258)[iVar9 * 2] = local_64[local_1414];
          (&DAT_0095125a)[iVar9 * 2] = 1;
          iVar9 = iVar9 + 1;
          DAT_00951078 = iVar9;
        }
        local_1414 = local_1414 + 1;
      } while (local_1414 < (int)(uint)*(byte *)(iVar7 + 0x1f));
    }
    if (iVar8 < 0x30) {
      (&DAT_00951290)[iVar8 * 2] = **(undefined2 **)(iVar7 + 4);
      (&DAT_00951292)[iVar8 * 2] = 1;
      iVar8 = iVar8 + 1;
      DAT_00951280 = iVar8;
    }
    (&DAT_00951290)[iVar8 * 2] = 0xffff;
  }
  FUN_004f1f10(local_e4,"levels\\");
  if (param_1 == -1) {
    param_2 = param_2 * 0x130;
    FUN_004f1e80(local_e4,param_2 + DAT_00951b78);
    FUN_004f1e80(local_e4,&DAT_0075a204);
    iVar7 = DAT_00951b78;
  }
  else {
    param_2 = param_1 * 0x9c;
    FUN_004f1e80(local_e4,param_2 + DAT_00951354);
    FUN_004f1e80(local_e4,&DAT_0075a204);
    iVar7 = DAT_00951354;
  }
  FUN_004f1e80(local_e4,param_2 + 0x40 + iVar7);
  FUN_004f1e80(local_e4,&DAT_0075d39c);
  iVar7 = FUN_004fc860(local_e4);
  if (iVar7 == 0) {
    DAT_0095107c = *local_13f8;
    DAT_0095125a = 1;
    DAT_0095107e = local_13f8[1];
    DAT_0095125e = 1;
    DAT_00951260 = 0xffff;
    DAT_00951078 = 2;
    DAT_00951092 = 1;
    _DAT_00951096 = 1;
    _DAT_00951098 = 0xffff;
    DAT_00951284 = 2;
    DAT_00951080 = 0xffff;
    DAT_00951090 = DAT_0095107c;
    DAT_00951094 = DAT_0095107e;
    DAT_00951258 = DAT_0095107c;
    DAT_0095125c = DAT_0095107e;
    goto LAB_00574c38;
  }
  local_1400 = 0;
  local_1404 = 0;
  iVar8 = FUN_004fc5b0(iVar7);
  if (iVar8 != 0) {
    puVar11 = (undefined1 *)0x0;
    do {
      FUN_004f7fb0(iVar7);
      pcVar2 = *(char **)(iVar7 + 0x510);
      if (*pcVar2 != '\0') {
        if (local_1400 == 0) {
          iVar8 = FUN_004f8b10(pcVar2,"supercounter_start");
          if (iVar8 == 0) {
            if (local_1404 < 10) {
              iVar8 = local_1404 * 0x1e8;
              abStack_1210[iVar8 + 3] = abStack_1210[iVar8 + 3] & 0xfe;
              puVar11 = local_13f4 + iVar8;
              auStack_1214[local_1404 * 0xf4] = 0;
              abStack_1210[iVar8] = 0xff;
              abStack_1210[iVar8 + 1] = 0xff;
              abStack_1210[iVar8 + 2] = 0xff;
              local_1400 = 1;
            }
          }
          else {
            iVar8 = FUN_004f8b10(*(undefined4 *)(iVar7 + 0x510),"character");
            if (iVar8 == 0) {
              iVar8 = FUN_004f7fb0(iVar7);
              if (((iVar8 != 0) &&
                  (iVar8 = FUN_0055b1c0(*(undefined4 *)(iVar7 + 0x510)), iVar8 != -1)) &&
                 (iVar9 = FUN_004f7fb0(iVar7), iVar9 != 0)) {
                iVar9 = FUN_004f8b10(*(undefined4 *)(iVar7 + 0x510),"player");
                if (iVar9 == 0) {
                  if (DAT_00951280 == 0) {
                    FUN_00573be0(8,iVar8,1,local_1408);
                  }
                  FUN_00573be0(0x30,iVar8,1,local_1408);
                }
                else {
                  iVar9 = FUN_004f8b10(*(undefined4 *)(iVar7 + 0x510),"resident");
                  if (iVar9 == 0) {
                    FUN_00573be0(0x30,iVar8,1,local_1408);
                    FUN_00573be0(0x30,iVar8,1,local_1408);
                    FUN_00573be0(0x30,iVar8,1,local_1408);
                  }
                  else {
                    iVar9 = FUN_004f8b10(*(undefined4 *)(iVar7 + 0x510),"cutscene");
                    if (((iVar9 == 0) && (DAT_00951284 < 0x30)) &&
                       (iVar9 = FUN_00630680(&DAT_00951090,iVar8,0), iVar9 == 0)) {
                      (&DAT_00951090)[DAT_00951284 * 2] = (short)iVar8;
                      (&DAT_00951092)[DAT_00951284 * 2] = 0;
                      DAT_00951284 = DAT_00951284 + 1;
                      (&DAT_00951090)[DAT_00951284 * 2] = 0xffff;
                    }
                  }
                }
              }
            }
            else {
              iVar8 = FUN_004f8b10(*(undefined4 *)(iVar7 + 0x510),"streaming");
              if (iVar8 == 0) {
                if ((DAT_0095127c < 0xc) && (iVar8 = FUN_004f7fb0(iVar7), iVar8 != 0)) {
                  bVar3 = false;
                  iVar8 = FUN_004f8b10(*(undefined4 *)(iVar7 + 0x510),"story_only");
                  if (iVar8 == 0) {
                    (&DAT_0095101e)[DAT_0095127c * 8] = (&DAT_0095101e)[DAT_0095127c * 8] & 0xfd | 1
                    ;
                    iVar8 = FUN_004f7fb0(iVar7);
                    if (iVar8 != 0) {
                      bVar3 = true;
                    }
                  }
                  iVar8 = FUN_004f8b10(*(undefined4 *)(iVar7 + 0x510),"freeplay_only");
                  if (iVar8 == 0) {
                    (&DAT_0095101e)[DAT_0095127c * 8] = (&DAT_0095101e)[DAT_0095127c * 8] & 0xfe | 2
                    ;
                    iVar8 = FUN_004f7fb0(iVar7);
                    if ((iVar8 == 0) && (!bVar3)) goto LAB_00574acd;
                  }
                  else {
                    (&DAT_0095101e)[DAT_0095127c * 8] = (&DAT_0095101e)[DAT_0095127c * 8] | 3;
                  }
                  FUN_00578da0(*(undefined4 *)(iVar7 + 0x510),&local_140c);
                  if ((local_140c != -1) &&
                     (*(char *)(local_140c * 0x130 + 0xa3 + DAT_00951b78) == param_1)) {
                    iVar8 = 0;
                    local_1414 = 0;
                    if (0 < DAT_0095127c) {
                      do {
                        local_1414 = iVar8;
                        if ((short)(&DAT_00951018)[iVar8 * 4] == local_140c) break;
                        iVar8 = iVar8 + 1;
                        local_1414 = iVar8;
                      } while (iVar8 < DAT_0095127c);
                    }
                    if (local_1414 == DAT_0095127c) {
                      (&DAT_00951018)[DAT_0095127c * 4] = (short)local_140c;
                      iVar8 = FUN_004f7fb0(iVar7);
                      if (((iVar8 != 0) &&
                          (FUN_00578da0(*(undefined4 *)(iVar7 + 0x510),&local_140c),
                          iVar8 = DAT_0095127c, local_140c != -1)) &&
                         (*(char *)(local_140c * 0x130 + 0xa3 + DAT_00951b78) == param_1)) {
                        (&DAT_0095101a)[DAT_0095127c * 4] = (short)local_140c;
                        (&DAT_0095101c)[iVar8 * 4] = 0xffff;
                        iVar8 = FUN_004f7fb0(iVar7);
                        if (((iVar8 != 0) &&
                            (FUN_00578da0(*(undefined4 *)(iVar7 + 0x510),&local_140c),
                            local_140c != -1)) &&
                           (*(char *)(local_140c * 0x130 + 0xa3 + DAT_00951b78) == param_1)) {
                          (&DAT_0095101c)[DAT_0095127c * 4] = (short)local_140c;
                        }
                        if ((&DAT_0095101c)[DAT_0095127c * 4] == -1) {
                          (&DAT_0095101c)[DAT_0095127c * 4] = (&DAT_0095101a)[DAT_0095127c * 4];
                        }
                        DAT_0095127c = DAT_0095127c + 1;
                      }
                    }
                  }
                }
              }
              else if ((param_1 == -1) ||
                      (iVar8 = FUN_004f8b10(*(undefined4 *)(iVar7 + 0x510),"music"), iVar8 != 0)) {
                iVar8 = FUN_004f8b10(*(undefined4 *)(iVar7 + 0x510),"AIMessage");
                if (iVar8 == 0) {
                  iVar8 = FUN_004f7fb0(iVar7);
                  if ((iVar8 != 0) &&
                     (iVar8 = FUN_005aac00(DAT_0095df4c,*(undefined4 *)(iVar7 + 0x510),0),
                     iVar8 != 0)) {
                    *(ushort *)(iVar8 + 0x36) = *(ushort *)(iVar8 + 0x36) | 1;
                    iVar9 = FUN_004f7fb0(iVar7);
                    while (iVar9 != 0) {
                      iVar9 = FUN_004f8a70(*(undefined4 *)(iVar7 + 0x510),"output");
                      if (iVar9 != 0) {
                        local_1410 = FUN_004f29a0(iVar9 + 6);
                        iVar9 = FUN_004f7fb0(iVar7);
                        if ((iVar9 != 0) && (local_1410 < 8)) {
                          uVar4 = FUN_004f29a0(*(undefined4 *)(iVar7 + 0x510));
                          *(undefined1 *)(local_1410 + 0x2c + iVar8) = uVar4;
                          if ((int)*(char *)(iVar8 + 0x34) < (int)(local_1410 + 1)) {
                            *(char *)(iVar8 + 0x34) = (char)local_1410 + '\x01';
                          }
                        }
                      }
                      iVar9 = FUN_004f7fb0(iVar7);
                    }
                  }
                }
                else if (param_1 != -1) {
                  iVar8 = FUN_004f8b10(*(undefined4 *)(iVar7 + 0x510),"story_coins");
                  if (iVar8 == 0) {
                    uVar10 = FUN_004f9e70(iVar7);
                    *(undefined4 *)(param_1 * 0x9c + 0x8c + DAT_00951354) = uVar10;
                  }
                  else {
                    iVar8 = FUN_004f8b10(*(undefined4 *)(iVar7 + 0x510),"freeplay_coins");
                    if (iVar8 == 0) {
                      uVar10 = FUN_004f9e70(iVar7);
                      *(undefined4 *)(param_1 * 0x9c + 0x90 + DAT_00951354) = uVar10;
                    }
                    else {
                      iVar8 = FUN_004f8b10(*(undefined4 *)(iVar7 + 0x510),"timetrial_time");
                      if (iVar8 == 0) {
                        uVar5 = FUN_004f9e70(iVar7);
                        *(undefined2 *)(param_1 * 0x9c + 0x84 + DAT_00951354) = uVar5;
                      }
                    }
                  }
                }
              }
              else {
                iVar8 = FUN_004f7fb0(iVar7);
                if (iVar8 != 0) {
                  iVar8 = param_1 * 0x9c + DAT_00951354;
                  uVar5 = FUN_00548a60(*(undefined4 *)(iVar7 + 0x510),DAT_009248cc,0xffffffff);
                  *(undefined2 *)(iVar8 + 0x88) = uVar5;
                  local_13fc = FUN_00694320(1,*(undefined4 *)(iVar7 + 0x510));
                  local_1410 = FUN_00694320(2,*(undefined4 *)(iVar7 + 0x510));
                  uVar10 = FUN_00694320(0x20,*(undefined4 *)(iVar7 + 0x510));
                  local_1414 = 0;
                  if (*(char *)(iVar8 + 0x7d) != '\0') {
                    do {
                      iVar9 = DAT_00951b78 + *(short *)(iVar8 + 0x60 + local_1414 * 2) * 0x130;
                      if (((byte)*(undefined4 *)(iVar9 + 100) & 0xe2) == 2) {
                        *(undefined2 *)(iVar9 + 0x94) = *(undefined2 *)(iVar8 + 0x88);
                        *(undefined2 *)
                         (*(short *)(iVar8 + 0x60 + local_1414 * 2) * 0x130 + 0x9c + DAT_00951b78) =
                             *(undefined2 *)(iVar8 + 0x88);
                        *(undefined4 *)
                         (*(short *)(iVar8 + 0x60 + local_1414 * 2) * 0x130 + 0x118 + DAT_00951b78)
                             = local_13fc;
                        *(uint *)(*(short *)(iVar8 + 0x60 + local_1414 * 2) * 0x130 + 0x120 +
                                 DAT_00951b78) = local_1410;
                        *(undefined4 *)
                         (*(short *)(iVar8 + 0x60 + local_1414 * 2) * 0x130 + 0x128 + DAT_00951b78)
                             = uVar10;
                        *(undefined4 *)
                         (*(short *)(iVar8 + 0x60 + local_1414 * 2) * 0x130 + 0x11c + DAT_00951b78)
                             = local_13fc;
                        *(uint *)(*(short *)(iVar8 + 0x60 + local_1414 * 2) * 0x130 + 0x124 +
                                 DAT_00951b78) = local_1410;
                        *(undefined4 *)
                         (*(short *)(iVar8 + 0x60 + local_1414 * 2) * 0x130 + 300 + DAT_00951b78) =
                             uVar10;
                      }
                      local_1414 = local_1414 + 1;
                    } while (local_1414 < (int)(uint)*(byte *)(iVar8 + 0x7d));
                  }
                }
              }
            }
          }
        }
        else {
          iVar8 = FUN_004f8b10(pcVar2,"supercounter_end");
          if (iVar8 == 0) {
            if (*(short *)(puVar11 + 0x1e0) != 0) {
              local_1404 = local_1404 + 1;
              local_1400 = 0;
            }
          }
          else {
            iVar8 = FUN_004f8b10(*(undefined4 *)(iVar7 + 0x510),"pickup");
            if (iVar8 == 0) {
              iVar8 = FUN_004f7fb0(iVar7);
              if ((iVar8 != 0) && (iVar8 = FUN_004f1ff0(*(undefined4 *)(iVar7 + 0x510)), iVar8 < 8))
              {
                FUN_004f1f10(puVar11 + (uint)*(ushort *)(puVar11 + 0x1e0) * 0x30 + 0x14,
                             *(undefined4 *)(iVar7 + 0x510));
                *(undefined2 *)(puVar11 + (uint)*(ushort *)(puVar11 + 0x1e0) * 0x30 + 0x2c) = 0xffff
                ;
                puVar11[(uint)*(ushort *)(puVar11 + 0x1e0) * 0x30 + 0x1c] = 0;
                puVar11[(uint)*(ushort *)(puVar11 + 0x1e0) * 0x30 + 0x2e] = 1;
                iVar8 = FUN_004f7fb0(iVar7);
                while (iVar8 != 0) {
                  iVar8 = FUN_004f8b10(*(undefined4 *)(iVar7 + 0x510),"in_level");
                  if (iVar8 == 0) {
                    iVar8 = FUN_004f7fb0(iVar7);
                    if ((iVar8 != 0) &&
                       (iVar8 = FUN_00578da0(*(undefined4 *)(iVar7 + 0x510),&local_1414), iVar8 != 0
                       )) {
                      *(undefined2 *)(puVar11 + (uint)*(ushort *)(puVar11 + 0x1e0) * 0x30 + 0x2c) =
                           (undefined2)local_1414;
                    }
                  }
                  else {
                    iVar8 = FUN_004f8b10(*(undefined4 *)(iVar7 + 0x510),"draw_at_gizmo");
                    if (iVar8 == 0) {
                      iVar8 = FUN_004f7fb0(iVar7);
                      if ((iVar8 != 0) &&
                         (iVar8 = FUN_004f1ff0(*(undefined4 *)(iVar7 + 0x510)), iVar8 < 0x10)) {
                        FUN_004f1f10(puVar11 + (uint)*(ushort *)(puVar11 + 0x1e0) * 0x30 + 0x1c,
                                     *(undefined4 *)(iVar7 + 0x510));
                        puVar11[(uint)*(ushort *)(puVar11 + 0x1e0) * 0x30 + 0x2e] = 0;
                      }
                    }
                    else {
                      iVar8 = FUN_004f8b10(*(undefined4 *)(iVar7 + 0x510),"draw_at_obj");
                      if (((iVar8 == 0) && (iVar8 = FUN_004f7fb0(iVar7), iVar8 != 0)) &&
                         (iVar8 = FUN_004f1ff0(*(undefined4 *)(iVar7 + 0x510)), iVar8 < 0x10)) {
                        FUN_004f1f10(puVar11 + (uint)*(ushort *)(puVar11 + 0x1e0) * 0x30 + 0x1c,
                                     *(undefined4 *)(iVar7 + 0x510));
                        puVar11[(uint)*(ushort *)(puVar11 + 0x1e0) * 0x30 + 0x2e] = 1;
                      }
                    }
                  }
                  iVar8 = FUN_004f7fb0(iVar7);
                }
                if (*(short *)(puVar11 + (uint)*(ushort *)(puVar11 + 0x1e0) * 0x30 + 0x2c) != -1) {
                  *(ushort *)(puVar11 + 0x1e0) = *(ushort *)(puVar11 + 0x1e0) + 1;
                }
              }
            }
            else {
              iVar8 = FUN_004f8b10(*(undefined4 *)(iVar7 + 0x510),"colour");
              if (iVar8 == 0) {
                uVar4 = FUN_004f9e70(iVar7);
                puVar11[0x1e4] = uVar4;
                uVar4 = FUN_004f9e70(iVar7);
                puVar11[0x1e5] = uVar4;
                uVar4 = FUN_004f9e70(iVar7);
                puVar11[0x1e6] = uVar4;
              }
              else {
                iVar8 = FUN_004f8b10(*(undefined4 *)(iVar7 + 0x510),"all_together");
                if (iVar8 == 0) {
                  puVar11[0x1e7] = puVar11[0x1e7] | 1;
                }
              }
            }
          }
        }
      }
LAB_00574acd:
      iVar8 = FUN_004fc5b0(iVar7);
    } while (iVar8 != 0);
  }
  FUN_004fa300(iVar7);
  iVar7 = local_1404;
  if (DAT_00951078 == 0) {
    sVar6 = DAT_00951090;
    if ((DAT_00951090 == -1) && (sVar6 = DAT_00951158, DAT_00951158 == -1)) {
      sVar6 = *local_13f8;
    }
    if (sVar6 != -1) {
      DAT_0095125a = 0;
      DAT_0095125e = 0;
      DAT_00951260 = 0xffff;
      DAT_00951258 = sVar6;
LAB_00574b60:
      DAT_00951078 = 2;
      DAT_0095125c = DAT_00951258;
    }
  }
  else if (DAT_00951078 == 1) {
    DAT_0095125e = 1;
    goto LAB_00574b60;
  }
  iVar8 = DAT_00951078;
  (&DAT_00951090)[DAT_00951284 * 2] = 0xffff;
  (&DAT_00951158)[DAT_00951220 * 2] = 0xffff;
  (&DAT_00951290)[DAT_00951280 * 2] = 0xffff;
  iVar9 = 0;
  (&DAT_00951258)[iVar8 * 2] = 0xffff;
  local_1414 = 0;
  if (0 < iVar8) {
    do {
      (&DAT_0095107c)[iVar9] = (&DAT_00951258)[iVar9 * 2];
      iVar9 = iVar9 + 1;
      local_1414 = iVar9;
    } while (iVar9 < iVar8);
  }
  (&DAT_0095107c)[local_1414] = 0xffff;
  if (0 < local_1404) {
    param_1 = param_1 * 0x9c;
    iVar8 = local_1404 * 0x1e8;
    DAT_00924890 = DAT_00924890 + 3 & 0xfffffffc;
    *(uint *)(param_1 + 0x80 + DAT_00951354) = DAT_00924890;
    FUN_004ef660(*(undefined4 *)(param_1 + 0x80 + DAT_00951354),local_13f4,iVar8);
    *(char *)(param_1 + 0x7f + DAT_00951354) = (char)iVar7;
    DAT_00924890 = DAT_00924890 + iVar8;
  }
LAB_00574c38:
  __security_check_cookie(local_4 ^ (uint)&local_1414);
  return;
}

