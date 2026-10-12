/* Ghidra pseudocode, not original source.
 * ev_20f8c411b4261e575accf39560ead20e25095f356798bee204490bf31a6f5756
 * Entry: 0x445230; label: FUN_00445230
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4
FUN_00445230(undefined4 param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  int iVar5;
  int *piVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  uint local_20;
  int local_1c;
  uint local_8;
  int local_4;
  
  iVar9 = 0;
  iVar8 = 0;
  local_4 = 0;
  local_20 = 0;
  local_1c = 0;
  bVar1 = false;
  bVar4 = false;
  bVar3 = false;
  local_8 = 0;
  bVar2 = false;
  if (param_6 == 0) {
    return 1;
  }
  if (((param_3 != 0) && (piVar6 = *(int **)(param_3 + 0xd0), piVar6 != (int *)0x0)) &&
     (*piVar6 != 0)) {
    iVar8 = *piVar6;
  }
  iVar5 = 0;
  uVar7 = 0;
  if (0 < param_5) {
    do {
      iVar5 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar9 * 4),"character");
      if (iVar5 == 0) {
        iVar5 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar9 * 4),"opponent");
        if (iVar5 == 0) {
          iVar5 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar9 * 4),"respawn");
          if (iVar5 == 0) {
            local_20 = 1;
          }
          else {
            iVar5 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar9 * 4),"respawn_at_origin");
            if (iVar5 == 0) {
              local_20 = 1;
              local_1c = 1;
            }
            else {
              iVar5 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar9 * 4),"all_ai_except");
              if (iVar5 == 0) {
                iVar5 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar9 * 4),"all_ai");
                if (iVar5 == 0) {
                  bVar1 = true;
                }
                else {
                  iVar5 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar9 * 4),"check_if_dead");
                  if (iVar5 == 0) {
                    bVar2 = true;
                  }
                  else {
                    iVar5 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar9 * 4),"debris");
                    if (iVar5 == 0) {
                      bVar4 = true;
                    }
                    else {
                      iVar5 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar9 * 4),"parts_on");
                      if (iVar5 == 0) {
                        bVar3 = true;
                      }
                      else {
                        iVar5 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar9 * 4),&DAT_00757700);
                        if (iVar5 != 0) {
                          FUN_005147c0(param_2,iVar5 + 4);
                          local_8 = FUN_006e6b90();
                          if (((int)local_8 < 0) || (0x10 < (int)local_8)) {
                            local_8 = 0;
                          }
                        }
                      }
                    }
                  }
                }
              }
              else {
                local_4 = FUN_00440120(param_1,iVar5 + 0xe);
                bVar1 = true;
              }
            }
          }
        }
        else if (*(int **)(param_3 + 0xe4) != (int *)0x0) {
          iVar8 = **(int **)(param_3 + 0xe4);
        }
      }
      else if ((DAT_00923904 == (code *)0x0) ||
              (piVar6 = (int *)(*DAT_00923904)(param_1,iVar5 + 10), piVar6 == (int *)0x0)) {
        iVar8 = 0;
      }
      else {
        iVar8 = *piVar6;
      }
      iVar9 = iVar9 + 1;
    } while (iVar9 < param_5);
    if (bVar1) {
      iVar9 = 0;
      iVar8 = DAT_0093d504;
      if (DAT_0093d500 < 1) {
        return 1;
      }
      do {
        if ((((((*(uint *)(iVar8 + 0x1fc) & 1) != 0) && ((*(uint *)(iVar8 + 0x1fc) & 0x1000) != 0))
             && ((*(uint *)(iVar8 + 0x1f8) & 0x400) != 0)) && (iVar8 != local_4)) &&
           ((!bVar2 || ((*(char *)(iVar8 + 0x28b) == '\0' && (*(float *)(iVar8 + 0x1010) <= 0.0)))))
           ) {
          *(uint *)(iVar8 + 0xeec) =
               (local_1c * 2 | local_20) << 0x14 | *(uint *)(iVar8 + 0xeec) & 0xffcfffff;
          if (bVar3) {
            FUN_00437770(iVar8,0xffffffff,0xffffffff,1,0,0,0);
          }
          if (bVar4) {
            FUN_004364e0(iVar8,2,0);
          }
          else {
            FUN_004364e0(iVar8,4,0);
          }
        }
        iVar9 = iVar9 + 1;
        iVar8 = iVar8 + 0x10d8;
      } while (iVar9 < DAT_0093d500);
      return 1;
    }
    iVar5 = local_1c;
    uVar7 = local_20;
    if (local_8 != 0) {
      iVar9 = 0;
      iVar8 = DAT_0093d504;
      if (DAT_0093d500 < 1) {
        return 1;
      }
      do {
        if (((((*(uint *)(iVar8 + 0x1fc) & 1) != 0) && ((*(uint *)(iVar8 + 0x1fc) & 0x1000) != 0))
            && (*(byte *)(iVar8 + 0x378) == local_8)) &&
           ((!bVar2 || ((*(char *)(iVar8 + 0x28b) == '\0' && (*(float *)(iVar8 + 0x1010) <= 0.0)))))
           ) {
          *(uint *)(iVar8 + 0xeec) =
               (local_1c * 2 | local_20) << 0x14 | *(uint *)(iVar8 + 0xeec) & 0xffcfffff;
          if (bVar3) {
            FUN_00437770(iVar8,0xffffffff,0xffffffff,1,0,0,0);
          }
          if (bVar4) {
            FUN_004364e0(iVar8,2,0);
          }
          else {
            FUN_004364e0(iVar8,4,0);
          }
        }
        iVar9 = iVar9 + 1;
        iVar8 = iVar8 + 0x10d8;
      } while (iVar9 < DAT_0093d500);
      return 1;
    }
  }
  if ((iVar8 == 0) ||
     ((bVar2 && ((*(char *)(iVar8 + 0x28b) != '\0' || (0.0 < *(float *)(iVar8 + 0x1010))))))) {
    return 1;
  }
  *(uint *)(iVar8 + 0xeec) = (iVar5 * 2 | uVar7) << 0x14 | *(uint *)(iVar8 + 0xeec) & 0xffcfffff;
  if (bVar3) {
    FUN_00437770(iVar8,0xffffffff,0xffffffff,1,0,0,0);
  }
  if (!bVar4) {
    FUN_004364e0(iVar8,4,0);
    return 1;
  }
  FUN_004364e0(iVar8,2,0);
  return 1;
}

