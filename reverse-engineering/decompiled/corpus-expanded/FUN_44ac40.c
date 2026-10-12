/* Ghidra pseudocode, not original source.
 * ev_899eb35a27e8c18144a9bface4dcd684320477ea32232f25bcb19f5ddc9c569a
 * Entry: 0x44ac40; label: FUN_0044ac40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4
FUN_0044ac40(undefined4 param_1,int param_2,float param_3,int param_4,int param_5,int param_6)

{
  int *piVar1;
  int iVar2;
  bool bVar3;
  bool bVar4;
  int iVar5;
  int iVar6;
  float10 fVar7;
  float local_10;
  float local_c;
  float local_8;
  
  local_8 = 1.0;
  bVar3 = false;
  local_10 = 1e+09;
  local_c = 0.0;
  if (((param_3 == 0.0) || (piVar1 = *(int **)((int)param_3 + 0xd0), piVar1 == (int *)0x0)) ||
     (*piVar1 == 0)) {
    return 1;
  }
  iVar2 = *piVar1;
  if (param_6 != 0) {
    param_3 = 1e+09;
    if ((param_5 != 0) && (iVar6 = 0, bVar4 = false, 0 < param_5)) {
      do {
        bVar3 = bVar4;
        iVar5 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar6 * 4),"multiply=");
        if (iVar5 == 0) {
          iVar5 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar6 * 4),"max=default");
          if (iVar5 == 0) {
            local_10 = *(float *)(*(int *)(*(int *)(iVar2 + 0x54) + 0x24) + 0x1c);
          }
          else {
            iVar5 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar6 * 4),"default");
            if (iVar5 == 0) {
              param_3 = *(float *)(*(int *)(*(int *)(iVar2 + 0x54) + 0x24) + 0x1c);
            }
            else {
              iVar5 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar6 * 4),"clear");
              if (iVar5 != 0) {
                iVar5 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar6 * 4),&DAT_00757be8);
                if (iVar5 == 0) {
                  iVar5 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar6 * 4),&DAT_00757be0);
                  if (iVar5 == 0) {
                    iVar5 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar6 * 4),"seek=");
                    if (iVar5 == 0) {
                      iVar5 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar6 * 4),"player_run_speed");
                      if (iVar5 == 0) {
                        fVar7 = (float10)FUN_005147c0(param_2,*(undefined4 *)(param_4 + iVar6 * 4));
                        param_3 = (float)fVar7;
                      }
                      else {
                        param_3 = *(float *)(*(int *)(*(int *)(DAT_0093d810 + 0x54) + 0x24) + 0x1c);
                      }
                    }
                    else {
                      fVar7 = (float10)FUN_005147c0(param_2,iVar5 + 5);
                      *(float *)(param_2 + 0x70) = (float)fVar7;
                    }
                  }
                  else {
                    fVar7 = (float10)FUN_005147c0(param_2,iVar5 + 4);
                    local_c = (float)fVar7;
                  }
                }
                else {
                  fVar7 = (float10)FUN_005147c0(param_2,iVar5 + 4);
                  local_10 = (float)fVar7;
                }
              }
            }
          }
        }
        else {
          fVar7 = (float10)FUN_005147c0(param_2,iVar5 + 9);
          local_8 = (float)fVar7;
          bVar3 = true;
        }
        iVar6 = iVar6 + 1;
        bVar4 = bVar3;
      } while (iVar6 < param_5);
    }
    local_c = ABS(local_c);
    local_10 = ABS(local_10);
    if (*(float *)(param_2 + 0x70) == 0.0) {
      if (!bVar3) {
        *(float *)(iVar2 + 0xed4) = param_3;
        return 1;
      }
      if (*(float *)(iVar2 + 0xed4) == 1e+09) {
        *(undefined4 *)(iVar2 + 0xed4) =
             *(undefined4 *)(*(int *)(*(int *)(iVar2 + 0x54) + 0x24) + 0x1c);
      }
      local_8 = local_8 * *(float *)(iVar2 + 0xed4);
      *(float *)(iVar2 + 0xed4) = local_8;
      if (0.0 <= local_8) {
        if (local_10 < local_8) {
          *(float *)(iVar2 + 0xed4) = local_10;
          return 1;
        }
        if ((local_c < local_10) && (local_8 < local_c)) {
          *(float *)(iVar2 + 0xed4) = local_c;
          return 1;
        }
        return 1;
      }
      if (local_8 < -local_10) {
        *(float *)(iVar2 + 0xed4) = -local_10;
        return 1;
      }
      if (local_10 <= local_c) {
        return 1;
      }
      if (local_8 <= -local_c) {
        return 1;
      }
      *(float *)(iVar2 + 0xed4) = -local_c;
      return 1;
    }
    if (bVar3) {
      if (*(float *)(iVar2 + 0xed4) == 1e+09) {
        *(undefined4 *)(param_2 + 0x74) =
             *(undefined4 *)(*(int *)(*(int *)(iVar2 + 0x54) + 0x24) + 0x1c);
      }
      local_8 = local_8 * *(float *)(param_2 + 0x74);
      *(float *)(param_2 + 0x74) = local_8;
      if (0.0 <= local_8) {
        if (local_8 <= local_10) {
          if ((local_c < local_10) && (local_8 < local_c)) {
            *(float *)(param_2 + 0x74) = local_c;
          }
        }
        else {
          *(float *)(param_2 + 0x74) = local_10;
        }
      }
      else if (-local_10 <= local_8) {
        if ((local_c < local_10) && (-local_c < local_8)) {
          *(float *)(param_2 + 0x74) = -local_c;
        }
      }
      else {
        *(float *)(param_2 + 0x74) = -local_10;
      }
    }
    else {
      *(float *)(param_2 + 0x74) = param_3;
    }
  }
  if ((0.0 < *(float *)(param_2 + 0x70)) && (*(float *)(iVar2 + 0xed4) < 1e+09)) {
    fVar7 = (float10)FUN_0054fb40(*(undefined4 *)(iVar2 + 0xed4),*(undefined4 *)(param_2 + 0x74),
                                  *(undefined4 *)(param_2 + 0x70));
    *(float *)(iVar2 + 0xed4) = (float)fVar7;
    if (ABS((float)fVar7 - *(float *)(param_2 + 0x74)) < 0.01) {
      *(undefined4 *)(iVar2 + 0xed4) = *(undefined4 *)(param_2 + 0x74);
      return 1;
    }
    return 0;
  }
  return 1;
}

