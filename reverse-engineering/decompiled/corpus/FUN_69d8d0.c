/* Ghidra analysis pseudocode, not original source.
 * ev_b9f25343996aedf2297d7d3ade291ed602d662c61207b78e5aec6bfbfbdc583f
 * Entry: 0x69d8d0; label: FUN_0069d8d0
 */

uint FUN_0069d8d0(int param_1,short *param_2,int param_3,int param_4,int param_5,int param_6,
                 undefined4 *param_7)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  short *psVar6;
  short *psVar7;
  int local_30;
  int local_2c;
  uint local_28;
  short *local_24;
  short *local_20;
  double local_1c;
  int local_14;
  double local_10;
  
  if (1 < *(int *)(param_1 + 0x58)) {
    while ((*(int *)(param_1 + 0x58) != 4 ||
           (local_28 = FUN_006a2db0(param_1 + 0x1e0,&local_30), local_28 == 0))) {
      uVar3 = FUN_0069c090(0,1,1);
      if (uVar3 == 0xfffffffe) {
        return 0;
      }
      if ((int)uVar3 < 1) {
        return uVar3;
      }
    }
    if ((int)local_28 < 1) {
      return local_28;
    }
    if ((*(int *)(param_1 + 4) == 0) || (*(int *)(param_1 + 0x58) < 3)) {
      iVar4 = *(int *)(param_1 + 0x48);
    }
    else {
      iVar4 = *(int *)(param_1 + 0x60) * 0x20 + *(int *)(param_1 + 0x48);
    }
    local_2c = *(int *)(iVar4 + 4);
    local_14 = local_2c * param_5;
    uVar3 = local_28;
    if (param_3 / local_14 < (int)local_28) {
      uVar3 = param_3 / local_14;
    }
    if (0 < (int)uVar3) {
      if (param_5 == 1) {
        iVar4 = 0;
        local_28 = uVar3;
        if (0 < (int)uVar3) {
          do {
            iVar5 = 0;
            if (0 < local_2c) {
              do {
                local_1c = (double)(*(float *)(*(int *)(local_30 + iVar5 * 4) + iVar4 * 4) * 128.0);
                local_24 = (short *)(int)ROUND(local_1c);
                if ((int)local_24 < 0x80) {
                  psVar6 = local_24;
                  if ((int)local_24 < -0x80) {
                    psVar6 = (short *)0xffffff80;
                  }
                }
                else {
                  psVar6 = (short *)0x7f;
                }
                *(byte *)param_2 = (-(param_6 != 0) & 0x80U) + 0x80 + (char)psVar6;
                iVar5 = iVar5 + 1;
                param_2 = (short *)((int)param_2 + 1);
              } while (iVar5 < local_2c);
            }
            iVar4 = iVar4 + 1;
          } while (iVar4 < (int)uVar3);
        }
      }
      else if (param_4 == 0) {
        if (param_6 == 0) {
          local_28 = 0;
          if (0 < local_2c) {
            do {
              iVar4 = *(int *)(local_30 + local_28 * 4);
              local_1c = (double)CONCAT44(local_1c._4_4_,iVar4);
              iVar5 = 0;
              psVar6 = param_2;
              if (0 < (int)uVar3) {
                do {
                  local_10 = (double)(*(float *)(iVar4 + iVar5 * 4) * 32768.0);
                  local_20 = (short *)(int)ROUND(local_10);
                  if ((int)local_20 < 0x8000) {
                    psVar7 = local_20;
                    if ((int)local_20 < -0x8000) {
                      psVar7 = (short *)0xffff8000;
                    }
                  }
                  else {
                    psVar7 = (short *)0x7fff;
                  }
                  *psVar6 = (short)psVar7 + -0x8000;
                  iVar5 = iVar5 + 1;
                  psVar6 = psVar6 + local_2c;
                } while (iVar5 < (int)uVar3);
              }
              local_28 = local_28 + 1;
              param_2 = param_2 + 1;
              local_24 = param_2;
            } while ((int)local_28 < local_2c);
          }
        }
        else {
          local_28 = 0;
          if (0 < local_2c) {
            do {
              iVar4 = *(int *)(local_30 + local_28 * 4);
              iVar5 = 0;
              psVar6 = param_2;
              if (0 < (int)uVar3) {
                do {
                  local_1c = (double)(*(float *)(iVar4 + iVar5 * 4) * 32768.0);
                  local_24 = (short *)(int)ROUND(local_1c);
                  if ((int)local_24 < 0x8000) {
                    psVar7 = local_24;
                    if ((int)local_24 < -0x8000) {
                      psVar7 = (short *)0xffff8000;
                    }
                  }
                  else {
                    psVar7 = (short *)0x7fff;
                  }
                  *psVar6 = (short)psVar7;
                  iVar5 = iVar5 + 1;
                  psVar6 = psVar6 + local_2c;
                } while (iVar5 < (int)uVar3);
              }
              local_28 = local_28 + 1;
              param_2 = param_2 + 1;
              local_20 = param_2;
            } while ((int)local_28 < local_2c);
          }
        }
      }
      else {
        local_28 = 0;
        if (0 < (int)uVar3) {
          do {
            iVar4 = 0;
            if (0 < local_2c) {
              do {
                local_10 = (double)(*(float *)(*(int *)(local_30 + iVar4 * 4) + local_28 * 4) *
                                   32768.0);
                local_20 = (short *)(int)ROUND(local_10);
                if ((int)local_20 < 0x8000) {
                  psVar6 = local_20;
                  if ((int)local_20 < -0x8000) {
                    psVar6 = (short *)0xffff8000;
                  }
                }
                else {
                  psVar6 = (short *)0x7fff;
                }
                iVar5 = (int)psVar6 + (-(uint)(param_6 != 0) & 0xffff8000) + 0x8000;
                *(char *)param_2 = (char)((uint)iVar5 >> 8);
                *(char *)((int)param_2 + 1) = (char)iVar5;
                iVar4 = iVar4 + 1;
                param_2 = param_2 + 1;
              } while (iVar4 < local_2c);
            }
            local_28 = local_28 + 1;
          } while ((int)local_28 < (int)uVar3);
        }
      }
      FUN_006a2e10(param_1 + 0x1e0,uVar3);
      puVar1 = (uint *)(param_1 + 0x50);
      uVar2 = *puVar1;
      *puVar1 = *puVar1 + uVar3;
      *(int *)(param_1 + 0x54) =
           *(int *)(param_1 + 0x54) + ((int)uVar3 >> 0x1f) + (uint)CARRY4(uVar2,uVar3);
      if (param_7 != (undefined4 *)0x0) {
        *param_7 = *(undefined4 *)(param_1 + 0x60);
      }
      return local_14 * uVar3;
    }
  }
  return 0xffffff7d;
}

