/* Ghidra pseudocode, not original source.
 * ev_b55b7a309ed021766e38758a92fbc8c97c8db4b0d277f859ab4c7f52da556e16
 * Entry: 0x453aa0; label: FUN_00453aa0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00453aa0(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  int iVar8;
  int *piVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  float10 fVar13;
  int local_38;
  float local_34;
  float local_2c;
  int local_18;
  int local_14;
  undefined4 local_c;
  undefined4 local_8;
  
  local_34 = 0.0;
  local_2c = 0.0;
  iVar12 = 0;
  bVar6 = false;
  bVar1 = false;
  bVar2 = false;
  bVar3 = false;
  bVar7 = false;
  bVar4 = false;
  local_8 = 0;
  local_c = 0;
  local_38 = -1;
  bVar5 = false;
  local_14 = 0;
  local_18 = 0;
  if (param_6 == 0) {
    return 1;
  }
  if (((param_3 != 0) && (piVar9 = *(int **)(param_3 + 0xd0), piVar9 != (int *)0x0)) &&
     (*piVar9 != 0)) {
    iVar12 = *piVar9;
  }
  iVar10 = *(int *)(param_2 + 0xa8);
  iVar11 = 0;
  if (0 < param_5) {
    do {
      iVar8 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar11 * 4),"character=");
      if (iVar8 == 0) {
        iVar8 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar11 * 4),"max_range=");
        if (iVar8 == 0) {
          iVar8 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar11 * 4),"max_player_range=");
          if (iVar8 == 0) {
            iVar8 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar11 * 4),"max_opponent_range=");
            if (iVar8 == 0) {
              iVar8 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar11 * 4),"off_screen_radius=");
              if (iVar8 == 0) {
                iVar8 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar11 * 4),"name=");
                if (iVar8 == 0) {
                  iVar8 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar11 * 4),"random");
                  if (iVar8 == 0) {
                    bVar6 = true;
                  }
                  else {
                    iVar8 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar11 * 4),&DAT_00758330);
                    if (iVar8 == 0) {
                      bVar1 = true;
                    }
                    else {
                      iVar8 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar11 * 4),"first");
                      if (iVar8 == 0) {
                        bVar5 = true;
                      }
                      else {
                        iVar8 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar11 * 4),"looping");
                        if (iVar8 == 0) {
                          local_8 = 1;
                        }
                        else {
                          iVar8 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar11 * 4),"finish_at_end"
                                              );
                          if (iVar8 == 0) {
                            local_c = 1;
                          }
                          else {
                            iVar8 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar11 * 4),
                                                 "ignore_assigned=TRUE");
                            if (iVar8 == 0) {
                              local_38 = 1;
                            }
                            else {
                              iVar8 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar11 * 4),
                                                   "ignore_assigned=FALSE");
                              if (iVar8 == 0) {
                                local_38 = 0;
                              }
                              else {
                                iVar8 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar11 * 4),
                                                     "furthest_from_opponent");
                                if (iVar8 == 0) {
                                  bVar3 = true;
                                  bVar7 = true;
                                }
                                else {
                                  iVar8 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar11 * 4),
                                                       "furthest_from_either_player");
                                  if (iVar8 == 0) {
                                    bVar7 = true;
                                  }
                                  else {
                                    iVar8 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar11 * 4),
                                                         "nearest_either_player");
                                    if (iVar8 != 0) goto LAB_00453d99;
                                  }
                                  bVar2 = true;
                                  bVar4 = true;
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
                else {
                  local_14 = iVar8 + 5;
                }
              }
              else {
                fVar13 = (float10)FUN_005147c0(param_2,iVar8 + 0x12);
                local_2c = (float)fVar13;
              }
            }
            else {
              fVar13 = (float10)FUN_005147c0(param_2,iVar8 + 0x13);
              local_34 = (float)fVar13;
              bVar3 = true;
            }
          }
          else {
            fVar13 = (float10)FUN_005147c0(param_2,iVar8 + 0x11);
            local_34 = (float)fVar13;
            bVar2 = true;
          }
        }
        else {
          fVar13 = (float10)FUN_005147c0(param_2,iVar8 + 10);
          local_34 = (float)fVar13;
        }
      }
      else if ((DAT_00923904 == (code *)0x0) ||
              (piVar9 = (int *)(*DAT_00923904)(param_1,iVar8 + 10), piVar9 == (int *)0x0)) {
        iVar12 = 0;
      }
      else {
        iVar12 = *piVar9;
      }
LAB_00453d99:
      iVar11 = iVar11 + 1;
    } while (iVar11 < param_5);
    if (local_38 != -1) goto LAB_00453dcb;
    if (bVar1) {
      local_38 = 0;
      goto LAB_00453dcb;
    }
  }
  local_38 = 1;
LAB_00453dcb:
  if (iVar12 != 0) {
    if (local_14 != 0) {
      iVar10 = FUN_0051ac70(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ae8),local_14);
    }
    if (iVar10 != 0) {
      if (bVar2) {
        iVar11 = DAT_0093d810 + 0x5c;
      }
      else if ((bVar3) && (*(int *)(iVar12 + 0x3ac) != 0)) {
        iVar11 = *(int *)(iVar12 + 0x3ac) + 0x5c;
      }
      else {
        iVar11 = iVar12 + 0x5c;
      }
      if ((bVar4) && (DAT_0093d814 != 0)) {
        local_18 = DAT_0093d814 + 0x5c;
      }
      if (bVar5) {
        if (*(char *)(iVar10 + 0x10) != '\0') {
          *(uint *)(*(int *)(iVar12 + 4) + 0xa4) =
               *(int *)(param_1 + 0x28) + (uint)**(byte **)(iVar10 + 0x14) * 0x3c;
          **(undefined1 **)(iVar10 + 0x18) = *(undefined1 *)(iVar12 + 0x28d);
          return 1;
        }
      }
      else {
        if (bVar1) {
          FUN_00440660(param_1,iVar10,local_8,local_c);
          return 1;
        }
        if (bVar6) {
          FUN_00520220(param_1,iVar10,iVar12,local_34,iVar11);
          return 1;
        }
        if (bVar7) {
          FUN_00520080();
          return 1;
        }
        FUN_0051fef0(param_1,iVar10,iVar12,local_34,iVar11,local_18,local_2c,local_38);
      }
    }
  }
  return 1;
}

