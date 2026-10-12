/* Ghidra analysis pseudocode, not original source.
 * ev_b8d156e74790e07078a260599393ca89d6d858c624833fd21a4e8cf1d6239801
 * Entry: 0x6d0fe0; label: FUN_006d0fe0
 */

void FUN_006d0fe0(int *param_1,int param_2)

{
  int *piVar1;
  uint uVar2;
  uint *puVar3;
  int iVar4;
  int iVar5;
  undefined4 *in_ECX;
  int iVar6;
  code *pcVar7;
  int unaff_EBX;
  int iVar8;
  undefined4 uStack_1d4;
  int *piStack_1d0;
  uint uStack_1cc;
  uint uStack_1c8;
  int iStack_1c4;
  uint uStack_1c0;
  undefined4 uStack_1bc;
  int *piStack_1b8;
  undefined1 auStack_1b4 [8];
  int local_1ac;
  int local_1a8;
  undefined4 *local_1a4;
  uint *puStack_1a0;
  undefined1 auStack_19c [256];
  undefined1 auStack_9c [136];
  uint local_14;
  
  local_14 = DAT_00829570 ^ (uint)&uStack_1d4;
  local_1a8 = param_2;
  local_1a4 = in_ECX;
  if (param_1[2] == 2) {
    iVar6 = in_ECX[9];
    local_1ac = 0;
    if (0 < iVar6) {
      puVar3 = (uint *)(in_ECX[2] + 4);
      do {
        if (puVar3[4] != 0) {
          if ((param_1[7] & 0x400000U) == 0) {
            uVar2 = *puVar3 & 0x10000000;
          }
          else {
            uVar2 = *puVar3 & 0x400000;
          }
          if (uVar2 == 0) {
            local_1ac = local_1ac + 1;
          }
        }
        puVar3 = puVar3 + 6;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
    }
    (**(code **)(*param_1 + 8))(&local_1ac,4,1);
    iStack_1c4 = 0;
    if (0 < (int)in_ECX[9]) {
      uStack_1cc = 0;
      do {
        iVar6 = in_ECX[2] + uStack_1cc;
        if (*(int *)(iVar6 + 0x14) != 0) {
          if ((param_1[7] & 0x400000U) == 0) {
            uVar2 = *(uint *)(iVar6 + 4) & 0x10000000;
          }
          else {
            uVar2 = *(uint *)(iVar6 + 4) & 0x400000;
          }
          if (uVar2 == 0) {
            (**(code **)(*param_1 + 0x18))("ObjectList");
            (**(code **)(*param_1 + 0x10))(iVar6);
            uStack_1c8 = 0;
            for (iVar8 = (**(code **)(**(int **)(iVar6 + 0x14) + 0x14))(0); iVar8 != 0;
                iVar8 = (**(code **)(**(int **)(iVar6 + 0x14) + 0x14))(iVar8)) {
              iVar5 = FUN_006cd5c0(param_1,iVar6);
              if (iVar5 != 0) {
                uStack_1cc = uStack_1cc + 1;
              }
            }
            (**(code **)(*param_1 + 8))(&uStack_1cc,4,1);
            for (iVar8 = (**(code **)(**(int **)(iVar6 + 0x14) + 0x14))(0); iVar8 != 0;
                iVar8 = (**(code **)(**(int **)(iVar6 + 0x14) + 0x14))(iVar8)) {
              iVar4 = FUN_006cd5c0(param_1,iVar6);
              iVar5 = DAT_02973ab0;
              if (iVar4 != 0) {
                uStack_1cc = 0;
                iVar4 = FUN_006c6a10(&uStack_1d4,iVar8,1,1);
                if ((iVar4 != 0) && ((*(byte *)(piStack_1d0 + 7) & 1) != 0)) {
                  (**(code **)(*piStack_1d0 + 4))(uStack_1d4,iVar5,&uStack_1cc,0);
                }
                (**(code **)(*param_1 + 8))(&uStack_1cc,4,1);
                iVar4 = DAT_02973ac4;
                if (((uStack_1cc & 0x2000000) != 0) ||
                   (unaff_EBX = iVar5, (*(uint *)(iVar6 + 4) & 0x4000000) != 0)) {
                  iVar5 = FUN_006c6a10(&uStack_1bc,iVar8,4,1);
                  if ((iVar5 != 0) && ((*(byte *)(piStack_1b8 + 7) & 4) != 0)) {
                    (**(code **)(*piStack_1b8 + 4))(uStack_1bc,iVar4,auStack_1b4,0x100);
                  }
                  (**(code **)(*param_1 + 0x14))(auStack_1b4,0x100);
                  unaff_EBX = iVar4;
                }
                FUN_006c6540(param_1,iVar8);
              }
            }
            (**(code **)(*param_1 + 0x1c))();
            in_ECX = local_1a4;
          }
        }
        uStack_1cc = uStack_1cc + 0x18;
        iStack_1c4 = iStack_1c4 + 1;
      } while (iStack_1c4 < (int)in_ECX[9]);
    }
  }
  if (param_1[2] == 1) {
    if (param_1[1] < 4) {
      iVar6 = *(int *)(local_1a8 + 0x24);
      iStack_1c4 = 0;
      if (0 < iVar6) {
        piStack_1b8 = (int *)0x0;
LAB_006d159b:
        if ((iStack_1c4 < 0) || (iVar6 <= iStack_1c4)) {
          puStack_1a0 = (uint *)0x0;
        }
        else {
          puStack_1a0 = (uint *)(*(int *)(local_1a8 + 8) + (int)piStack_1b8);
        }
        uStack_1cc = *puStack_1a0;
        iVar6 = 0;
        if (0 < (int)in_ECX[0xb]) {
          do {
            iVar8 = FUN_004f8b10(*(undefined4 *)(in_ECX[3] + iVar6 * 8),uStack_1cc);
            if (iVar8 == 0) {
              uStack_1c8 = *(uint *)(in_ECX[3] + 4 + iVar6 * 8);
              goto LAB_006d15ef;
            }
            iVar6 = iVar6 + 1;
          } while (iVar6 < (int)in_ECX[0xb]);
        }
        uStack_1c8 = uStack_1cc;
LAB_006d15ef:
        iVar6 = 0;
        if (0 < (int)in_ECX[9]) {
          uStack_1cc = 0;
          do {
            iVar8 = FUN_004f8b10(*(undefined4 *)(uStack_1cc + in_ECX[2]),uStack_1c8);
            if (iVar8 == 0) {
              uStack_1c8 = in_ECX[2] + iVar6 * 0x18;
              if ((uStack_1c8 != 0) && (*(int *)(uStack_1c8 + 0x14) != 0)) {
                iVar6 = (**(code **)(*param_1 + 0x18))("ObjectList");
                if (iVar6 == 0) goto LAB_006d17ed;
                (**(code **)(*param_1 + 8))(&iStack_1c4,4,1);
                piStack_1d0 = (int *)0x0;
                if (iStack_1c4 < 1) goto LAB_006d17ed;
                goto LAB_006d1695;
              }
              break;
            }
            uStack_1cc = uStack_1cc + 0x18;
            iVar6 = iVar6 + 1;
          } while (iVar6 < (int)in_ECX[9]);
        }
        goto LAB_006d17fa;
      }
    }
    else {
      (**(code **)(*param_1 + 8))(&local_1ac,4,1);
      iStack_1c4 = 0;
      if (0 < local_1ac) {
LAB_006d1297:
        iVar6 = (**(code **)(*param_1 + 0x18))("ObjectList");
        if (iVar6 != 0) {
          (**(code **)(*param_1 + 0x14))(auStack_9c,0x80);
          iVar6 = local_1ac;
          iVar8 = 0;
          if (0 < *(int *)(local_1ac + 0x24)) {
            piStack_1d0 = (int *)0x0;
            do {
              iVar5 = FUN_004f8b10(*(undefined4 *)(*(int *)(iVar6 + 8) + (int)piStack_1d0),
                                   auStack_9c);
              if (iVar5 == 0) {
                local_1a4 = (undefined4 *)(*(int *)(iVar6 + 8) + iVar8 * 0x18);
                goto LAB_006d1304;
              }
              piStack_1d0 = piStack_1d0 + 6;
              iVar8 = iVar8 + 1;
            } while (iVar8 < *(int *)(iVar6 + 0x24));
          }
          local_1a4 = (undefined4 *)0x0;
LAB_006d1304:
          iVar6 = local_1a8;
          uStack_1bc = *local_1a4;
          iVar8 = 0;
          if (0 < *(int *)(local_1a8 + 0x2c)) {
            do {
              iVar5 = FUN_004f8b10(*(undefined4 *)(*(int *)(iVar6 + 0xc) + iVar8 * 8),uStack_1bc);
              if (iVar5 == 0) {
                uStack_1bc = *(undefined4 *)(*(int *)(iVar6 + 0xc) + 4 + iVar8 * 8);
                break;
              }
              iVar8 = iVar8 + 1;
            } while (iVar8 < *(int *)(iVar6 + 0x2c));
          }
          iVar8 = 0;
          if (0 < *(int *)(iVar6 + 0x24)) {
            piStack_1d0 = (int *)0x0;
            do {
              iVar5 = FUN_004f8b10(*(undefined4 *)((int)piStack_1d0 + *(int *)(iVar6 + 8)),
                                   uStack_1bc);
              if (iVar5 == 0) {
                uStack_1cc = *(int *)(iVar6 + 8) + iVar8 * 0x18;
                if ((uStack_1cc != 0) && (*(int *)(uStack_1cc + 0x14) != 0)) {
                  (**(code **)(*param_1 + 8))(&iStack_1c4,4,1);
                  piStack_1d0 = (int *)0x0;
                  if (0 < iStack_1c4) goto LAB_006d13f0;
                }
                break;
              }
              piStack_1d0 = piStack_1d0 + 6;
              iVar8 = iVar8 + 1;
            } while (iVar8 < *(int *)(iVar6 + 0x24));
          }
        }
        goto LAB_006d154d;
      }
    }
  }
LAB_006d1819:
  __security_check_cookie(local_14 ^ (uint)&uStack_1d4);
  return;
  while( true ) {
    FUN_006cd9e0(param_1,iVar6,local_1a4,local_1ac);
    if ((iVar6 != 0) && (iVar8 = 0, 0 < DAT_02973bbc)) {
      do {
        (**(code **)**(undefined4 **)(DAT_02973b98 + iVar8 * 4))(iVar6,uStack_1cc,0,0,0,0);
        iVar8 = iVar8 + 1;
      } while (iVar8 < DAT_02973bbc);
    }
    piStack_1d0 = (int *)((int)piStack_1d0 + 1);
    if (iStack_1c4 <= (int)piStack_1d0) break;
LAB_006d1695:
    (**(code **)(*param_1 + 8))(auStack_1b4,4,1);
    if ((uStack_1c0 & 0x2000000) == 0) {
      if ((*(uint *)(unaff_EBX + 4) & 0x4000000) == 0) {
        piVar1 = *(int **)(unaff_EBX + 0x14);
        uStack_1cc = 0;
        if (DAT_02973b9c != (code *)0x0) {
          uStack_1cc = (*DAT_02973b9c)();
        }
        iVar6 = (**(code **)(*piVar1 + 0x18))(0,4,2);
        if (iVar6 != 0) {
          pcVar7 = *(code **)(*piVar1 + 0x28);
LAB_006d1782:
          (*pcVar7)(iVar6,uStack_1c0);
        }
      }
      else {
        (**(code **)(*param_1 + 0x14))(&local_1a8,0x100);
        iVar6 = FUN_006cdc60(auStack_19c);
        if (iVar6 == 0) {
          iVar6 = 0;
        }
        else {
          piVar1 = *(int **)(unaff_EBX + 0x14);
          uStack_1c0 = 0;
          if (DAT_02973b9c != (code *)0x0) {
            uStack_1c0 = (*DAT_02973b9c)();
          }
          iVar6 = (**(code **)(*piVar1 + 0x18))(iVar6,4,2);
          if (iVar6 != 0) {
            pcVar7 = *(code **)(*piVar1 + 0x28);
            goto LAB_006d1782;
          }
        }
      }
    }
    else {
      (**(code **)(*param_1 + 0x14))(&local_1a8,0x100);
      iVar6 = FUN_006cdc60(auStack_19c);
    }
  }
LAB_006d17ed:
  (**(code **)(*param_1 + 0x1c))();
  in_ECX = local_1a4;
LAB_006d17fa:
  iVar6 = *(int *)(local_1a8 + 0x24);
  piStack_1b8 = piStack_1b8 + 6;
  iStack_1c4 = iStack_1c4 + 1;
  if (iVar6 <= iStack_1c4) goto LAB_006d1819;
  goto LAB_006d159b;
  while( true ) {
    FUN_006cd9e0(param_1,iVar6,local_1a4,local_1ac);
    if ((iVar6 != 0) && (iVar8 = 0, 0 < DAT_02973bbc)) {
      do {
        (**(code **)**(undefined4 **)(DAT_02973b98 + iVar8 * 4))(iVar6,uStack_1cc,0,0,0,0);
        iVar8 = iVar8 + 1;
      } while (iVar8 < DAT_02973bbc);
    }
    piStack_1d0 = (int *)((int)piStack_1d0 + 1);
    if (iStack_1c4 <= (int)piStack_1d0) break;
LAB_006d13f0:
    (**(code **)(*param_1 + 8))(auStack_1b4,4,1);
    if ((uStack_1c0 & 0x2000000) == 0) {
      if ((*(uint *)(unaff_EBX + 4) & 0x4000000) == 0) {
        piVar1 = *(int **)(unaff_EBX + 0x14);
        uStack_1c8 = 0;
        if (DAT_02973b9c != (code *)0x0) {
          uStack_1c8 = (*DAT_02973b9c)();
        }
        iVar6 = (**(code **)(*piVar1 + 0x18))(0,4,2);
        if (iVar6 != 0) {
          pcVar7 = *(code **)(*piVar1 + 0x28);
LAB_006d14dd:
          (*pcVar7)(iVar6,uStack_1bc);
        }
      }
      else {
        (**(code **)(*param_1 + 0x14))(&local_1a8,0x100);
        iVar6 = FUN_006cdc60(auStack_19c);
        if (iVar6 == 0) {
          iVar6 = 0;
        }
        else {
          piVar1 = *(int **)(unaff_EBX + 0x14);
          uStack_1bc = 0;
          if (DAT_02973b9c != (code *)0x0) {
            uStack_1bc = (*DAT_02973b9c)();
          }
          iVar6 = (**(code **)(*piVar1 + 0x18))(iVar6,4,2);
          if (iVar6 != 0) {
            pcVar7 = *(code **)(*piVar1 + 0x28);
            goto LAB_006d14dd;
          }
        }
      }
    }
    else {
      (**(code **)(*param_1 + 0x14))(&local_1a8,0x100);
      iVar6 = FUN_006cdc60(auStack_19c);
    }
  }
LAB_006d154d:
  (**(code **)(*param_1 + 0x1c))();
  iStack_1c4 = iStack_1c4 + 1;
  if (local_1ac <= iStack_1c4) {
    __security_check_cookie(local_14 ^ (uint)&uStack_1d4);
    return;
  }
  goto LAB_006d1297;
}

