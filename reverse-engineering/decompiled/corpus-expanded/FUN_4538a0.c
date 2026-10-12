/* Ghidra pseudocode, not original source.
 * ev_b55b7a309ed021766e38758a92fbc8c97c8db4b0d277f859ab4c7f52da556e16
 * Entry: 0x4538a0; label: FUN_004538a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4
FUN_004538a0(int param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int local_10;
  int local_c;
  int local_4;
  
  iVar5 = 0;
  uVar1 = 0xff;
  local_10 = 0;
  local_c = 0;
  local_4 = 0;
  if (param_6 != 0) {
    if ((param_3 != 0) && (*(int **)(param_3 + 0xd0) != (int *)0x0)) {
      local_10 = **(int **)(param_3 + 0xd0);
      uVar1 = *(undefined1 *)(local_10 + 0x28d);
    }
    if (0 < param_5) {
      do {
        iVar2 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar5 * 4),"locator=mylocator");
        if (iVar2 == 0) {
          if (local_10 != 0) {
            local_c = *(int *)(local_10 + 0x36c);
          }
        }
        else {
          iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar5 * 4),"locator");
          if (iVar2 == 0) {
            iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar5 * 4),"character");
            if (iVar2 == 0) {
              iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar5 * 4),&DAT_0075827c);
              if (iVar2 == 0) {
                iVar2 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar5 * 4),"reserve");
                if (iVar2 == 0) {
                  uVar1 = 0x80;
                }
              }
              else {
                iVar3 = FUN_004f1ff0(&DAT_0075827c);
                local_4 = FUN_0051ac70(param_1,iVar2 + 1 + iVar3);
              }
            }
            else {
              iVar3 = FUN_004f1ff0("character");
              if ((DAT_00923904 == (code *)0x0) ||
                 (piVar4 = (int *)(*DAT_00923904)(param_1,iVar2 + 1 + iVar3), piVar4 == (int *)0x0))
              {
                local_10 = 0;
                uVar1 = uRam0000028d;
              }
              else {
                local_10 = *piVar4;
                uVar1 = *(undefined1 *)(local_10 + 0x28d);
              }
            }
          }
          else {
            iVar3 = FUN_004f1ff0("locator");
            local_c = FUN_0051ac10(param_1,iVar2 + 1 + iVar3);
          }
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < param_5);
      if ((local_4 != 0) && (local_c != 0)) {
        iVar5 = 0;
        if (0 < *(char *)(local_4 + 0x10)) {
          do {
            if (*(int *)(param_1 + 0x28) + (uint)*(byte *)(*(int *)(local_4 + 0x14) + iVar5) * 0x3c
                == local_c) break;
            iVar5 = iVar5 + 1;
          } while (iVar5 < *(char *)(local_4 + 0x10));
        }
        *(undefined1 *)(iVar5 + *(int *)(local_4 + 0x18)) = uVar1;
      }
      return 1;
    }
  }
  return 1;
}

