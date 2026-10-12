/* Ghidra analysis pseudocode, not original source.
 * ev_0b4f3bc8b4a39fc427a7fcc8ed3e1304ee3926d0e45102a57071cb05acfa7baa
 * Entry: 0x5a2aa0; label: FUN_005a2aa0
 */

void FUN_005a2aa0(int param_1,undefined4 param_2)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  undefined4 *_Dst;
  undefined4 **ppuVar4;
  float10 fVar5;
  undefined4 *local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  float local_10;
  float local_c;
  float local_8;
  undefined1 local_4 [4];
  
  *(undefined4 *)(param_1 + 0x5050) = 0;
  if ((*(int *)(param_1 + 0x13c) != 0) &&
     (iVar2 = FUN_004fc900("pulses",param_2,0xffff), iVar2 != 0)) {
    _Dst = (undefined4 *)(*(int *)(param_1 + 0x104) + 3U & 0xfffffffc);
    local_10 = 1.0;
    local_c = 0.0;
    local_8 = 0.0;
    *(undefined4 **)(param_1 + 0x104) = _Dst;
    local_1c = 0xffff0000;
    local_18 = 0xffffffff;
    local_14 = 0xffffffff;
    local_4 = (undefined1  [4])0x1ffff;
    local_20 = _Dst;
    while ((iVar3 = FUN_004fc5b0(iVar2), iVar3 != 0 && (iVar3 = FUN_004f7fb0(iVar2), iVar3 != 0))) {
      iVar3 = FUN_004f8b10(*(undefined4 *)(iVar2 + 0x510),"pulses_start");
      if (iVar3 == 0) {
        while (iVar3 = FUN_004fc5b0(iVar2), iVar3 != 0) {
          _memset(_Dst,0,0x34);
          iVar3 = FUN_004f7fb0(iVar2);
          if (iVar3 != 0) {
            iVar3 = FUN_004f8b10(*(undefined4 *)(iVar2 + 0x510),"pulses_end");
            if (iVar3 == 0) goto LAB_005a2f8d;
            iVar3 = FUN_004f8b10(*(undefined4 *)(iVar2 + 0x510),"sfx_onloop");
            if ((iVar3 == 0) && (iVar3 = FUN_004f7fb0(iVar2), iVar3 != 0)) {
              uVar1 = FUN_00650dc0(*(undefined4 *)(iVar2 + 0x510));
              local_18 = CONCAT22(uVar1,(undefined2)local_18);
            }
            else {
              iVar3 = FUN_004f8b10(*(undefined4 *)(iVar2 + 0x510),"sfx_offloop");
              if ((iVar3 == 0) && (iVar3 = FUN_004f7fb0(iVar2), iVar3 != 0)) {
                uVar1 = FUN_00650dc0(*(undefined4 *)(iVar2 + 0x510));
                local_14 = CONCAT22(local_14._2_2_,uVar1);
              }
              else {
                iVar3 = FUN_004f8b10(*(undefined4 *)(iVar2 + 0x510),"sfx_turnon");
                if ((iVar3 == 0) && (iVar3 = FUN_004f7fb0(iVar2), iVar3 != 0)) {
                  uVar1 = FUN_00650dc0(*(undefined4 *)(iVar2 + 0x510));
                  local_1c = CONCAT22(uVar1,(short)local_1c);
                }
                else {
                  iVar3 = FUN_004f8b10(*(undefined4 *)(iVar2 + 0x510),"sfx_turnoff");
                  if ((iVar3 == 0) && (iVar3 = FUN_004f7fb0(iVar2), iVar3 != 0)) {
                    uVar1 = FUN_00650dc0(*(undefined4 *)(iVar2 + 0x510));
                    local_18 = CONCAT22(local_18._2_2_,uVar1);
                  }
                  else {
                    iVar3 = FUN_004f8b10(*(undefined4 *)(iVar2 + 0x510),"sfx_hitplayer");
                    if ((iVar3 == 0) && (iVar3 = FUN_004f7fb0(iVar2), iVar3 != 0)) {
                      uVar1 = FUN_00650dc0(*(undefined4 *)(iVar2 + 0x510));
                      local_14 = CONCAT22(uVar1,(undefined2)local_14);
                    }
                    else {
                      iVar3 = FUN_004f8b10(*(undefined4 *)(iVar2 + 0x510),"collide_radius");
                      if (iVar3 == 0) {
                        fVar5 = (float10)FUN_004f8100(iVar2);
                        local_10 = (float)fVar5;
                      }
                      else {
                        iVar3 = FUN_004f8b10(*(undefined4 *)(iVar2 + 0x510),"hit_direction_line");
                        if (iVar3 == 0) {
                          fVar5 = (float10)FUN_004f8100(iVar2);
                          local_c = (float)fVar5;
                          fVar5 = (float10)FUN_004f8100(iVar2);
                          local_8 = (float)fVar5;
                          local_4[2] = 0;
                        }
                        else {
                          iVar3 = FUN_004f8b10(*(undefined4 *)(iVar2 + 0x510),
                                               "hit_direction_radius_origin");
                          if (iVar3 == 0) {
                            fVar5 = (float10)FUN_004f8100(iVar2);
                            local_c = (float)fVar5;
                            fVar5 = (float10)FUN_004f8100(iVar2);
                            local_8 = (float)fVar5;
                            local_4[2] = 1;
                          }
                          else {
                            iVar3 = FUN_004f8b10(*(undefined4 *)(iVar2 + 0x510),"debris_hitplayer");
                            if ((iVar3 == 0) && (iVar3 = FUN_004f7fb0(iVar2), iVar3 != 0)) {
                              uVar1 = FUN_0062c3b0(*(undefined4 *)(param_1 + 0x134),
                                                   *(undefined4 *)(iVar2 + 0x510));
                              local_4._0_2_ = uVar1;
                            }
                            else {
                              iVar3 = FUN_004f8b10(*(undefined4 *)(iVar2 + 0x510),"pulse");
                              if ((iVar3 == 0) &&
                                 ((iVar3 = FUN_004f7fb0(iVar2), iVar3 != 0 &&
                                  (iVar3 = FUN_005cf5b0(*(undefined4 *)(param_1 + 0x13c),_Dst,
                                                        *(undefined4 *)(iVar2 + 0x510),1),
                                  iVar3 != 0)))) {
                                iVar3 = FUN_004f7fb0(iVar2);
                                while (iVar3 != 0) {
                                  iVar3 = FUN_004f8b10(*(undefined4 *)(iVar2 + 0x510),"gizmo");
                                  if (iVar3 == 0) {
                                    iVar3 = FUN_004f7fb0(iVar2);
                                    if ((iVar3 != 0) &&
                                       (iVar3 = FUN_004f1ff0(*(undefined4 *)(iVar2 + 0x510)),
                                       iVar3 < 0x10)) {
                                      FUN_004f1f10(_Dst + 8,*(undefined4 *)(iVar2 + 0x510));
                                    }
                                  }
                                  else {
                                    iVar3 = FUN_004f8b10(*(undefined4 *)(iVar2 + 0x510),"on_time");
                                    if (iVar3 == 0) {
                                      fVar5 = (float10)FUN_004f8100(iVar2);
                                      _Dst[3] = (float)fVar5;
                                    }
                                    else {
                                      iVar3 = FUN_004f8b10(*(undefined4 *)(iVar2 + 0x510),"off_time"
                                                          );
                                      if (iVar3 == 0) {
                                        fVar5 = (float10)FUN_004f8100(iVar2);
                                        _Dst[4] = (float)fVar5;
                                      }
                                      else {
                                        iVar3 = FUN_004f8b10(*(undefined4 *)(iVar2 + 0x510),
                                                             "start_wait");
                                        if (iVar3 == 0) {
                                          fVar5 = (float10)FUN_004f8100(iVar2);
                                          _Dst[6] = (float)fVar5;
                                        }
                                      }
                                    }
                                  }
                                  iVar3 = FUN_004f7fb0(iVar2);
                                }
                                iVar3 = FUN_005cfac0(_Dst);
                                if (iVar3 != 0) {
                                  if ((float)_Dst[3] < 0.1) {
                                    _Dst[3] = 0x3dcccccd;
                                  }
                                  if ((float)_Dst[4] < 0.1) {
                                    _Dst[4] = 0x3dcccccd;
                                  }
                                  if ((float)_Dst[6] < 0.0) {
                                    _Dst[6] = 0;
                                  }
                                  if (0.1 <= local_10) {
                                    local_1c = CONCAT22(local_1c._2_2_,(short)local_1c + 1);
                                    _Dst = _Dst + 0xd;
                                  }
                                  else {
                                    local_1c = CONCAT22(local_1c._2_2_,(short)local_1c + 1);
                                    local_10 = 0.1;
                                    _Dst = _Dst + 0xd;
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
LAB_005a2f8d:
    FUN_004fa300(iVar2);
    if ((short)local_1c != 0) {
      *(undefined4 **)(param_1 + 0x104) = _Dst;
      *(undefined4 **)(param_1 + 0x5050) = _Dst;
      ppuVar4 = &local_20;
      for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
        *_Dst = *ppuVar4;
        ppuVar4 = ppuVar4 + 1;
        _Dst = _Dst + 1;
      }
      *(uint *)(param_1 + 0x104) = *(int *)(param_1 + 0x104) + 0x23U & 0xfffffffc;
    }
  }
  return;
}

