/* Ghidra pseudocode, not original source.
 * ev_35392dc412ffe2b2a558f5a6ba3fa7479ff279a31c4c87c94d67c76968103d24
 * Entry: 0x615a80; label: FUN_00615a80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00615a80(int param_1)

{
  int iVar1;
  int in_ECX;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined1 local_19;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  undefined4 local_8;
  int local_4;
  
  if (((*(int *)(DAT_028572e0 + 4) == 4) || (*(int *)(DAT_028572e0 + 4) == 3)) &&
     (*(char *)(param_1 + 0xc) == '\0')) {
    local_18 = 0;
    do {
      if (*(int *)(in_ECX + 0x20 + local_18 * 4) == 0) {
        if (local_18 < 2) {
          *(int *)(in_ECX + 0x20 + local_18 * 4) = param_1;
          local_14 = in_ECX;
          FUN_0053d5d0(0x20);
          iVar3 = local_4;
          iVar7 = local_c;
          iVar1 = local_10;
          local_19 = 0;
          if (local_c != 0) {
            FUN_004ef660(local_4 + local_c,&local_19,1);
            iVar4 = iVar3 + 1 + iVar7;
            FUN_004ef660(iVar4,&local_18,4);
            if (iVar1 != 0) {
              FUN_00621190(iVar4);
            }
            iVar3 = iVar3 + 5;
            in_ECX = local_14;
          }
          uVar10 = 0;
          uVar9 = 0;
          uVar8 = 3;
          iVar4 = iVar7;
          uVar5 = local_8;
          iVar6 = param_1;
          if (iVar7 == 0) {
            FUN_0060f2d0(iVar1,0,local_8,iVar3,3,param_1,0,0);
          }
          else {
            *(int *)(iVar7 + 0x4b0) = *(int *)(iVar7 + 0x4b0) + 1;
          }
          FUN_0060efd0(iVar1,iVar4,uVar5,iVar3,uVar8,iVar6,uVar9,uVar10);
          if (iVar7 != 0) {
            if (*(uint *)(iVar7 + 0x4b0) < 2) {
              *(undefined4 *)(iVar7 + 0x4b0) = 0;
            }
            else {
              *(uint *)(iVar7 + 0x4b0) = *(uint *)(iVar7 + 0x4b0) - 1;
            }
          }
          goto LAB_00615acc;
        }
        break;
      }
      local_18 = local_18 + 1;
    } while (local_18 < 2);
    FUN_00611890();
  }
LAB_00615acc:
  if (*(char *)(param_1 + 0xc) == '\0') {
    if (*(int *)(in_ECX + 0xc) != 0) {
      FUN_0053d5d0(0x20);
      local_19 = 9;
      if (local_c != 0) {
        FUN_004ef660(local_4 + local_c,&local_19,1);
        FUN_004ef660(local_4 + 1 + local_c,in_ECX + 0x10,0x10);
        local_4 = local_4 + 0x11;
      }
      uVar9 = 0;
      uVar8 = 0;
      uVar5 = 3;
      iVar1 = local_c;
      iVar7 = param_1;
      if (local_c == 0) {
        FUN_0060f2d0(local_10,0,local_8,local_4,3,param_1,0,0);
      }
      else {
        *(int *)(local_c + 0x4b0) = *(int *)(local_c + 0x4b0) + 1;
      }
      FUN_0060efd0(local_10,iVar1,local_8,local_4,uVar5,iVar7,uVar8,uVar9);
      if (local_c != 0) {
        if (*(uint *)(local_c + 0x4b0) < 2) {
          *(undefined4 *)(local_c + 0x4b0) = 0;
        }
        else {
          *(uint *)(local_c + 0x4b0) = *(uint *)(local_c + 0x4b0) - 1;
        }
      }
    }
    iVar1 = 0;
    piVar2 = (int *)(in_ECX + 0xd838);
    while (*piVar2 != 0) {
      iVar1 = iVar1 + 1;
      piVar2 = piVar2 + 5;
      if (7 < iVar1) {
        return;
      }
    }
    piVar2 = (int *)(in_ECX + 0xd838 + iVar1 * 0x14);
    *piVar2 = param_1;
    piVar2[4] = 0;
    piVar2[3] = 0;
  }
  return;
}

