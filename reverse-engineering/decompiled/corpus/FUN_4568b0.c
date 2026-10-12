/* Ghidra analysis pseudocode, not original source.
 * ev_5f3da693bf096313253939ed49ba5271cfe8862e4a440ae5c9d57980f69a0d69
 * Entry: 0x4568b0; label: FUN_004568b0
 */

void FUN_004568b0(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  if (param_2 != 0) {
    for (iVar1 = FUN_004f1440(param_2); iVar1 != 0; iVar1 = FUN_004f1460(param_2,iVar1)) {
      for (iVar2 = FUN_004f1440(iVar1 + 0x10); iVar2 != 0; iVar2 = FUN_004f1460(iVar1 + 0x10,iVar2))
      {
        for (iVar3 = FUN_004f1440(iVar2 + 0x10); iVar3 != 0;
            iVar3 = FUN_004f1460(iVar2 + 0x10,iVar3)) {
          if (((*(int *)(iVar3 + 0x10) != 0) &&
              (*(code **)(*(int *)(iVar3 + 0x10) + 4) == FUN_004507b0)) &&
             (iVar5 = 0, 0 < *(int *)(iVar3 + 0xc))) {
            do {
              iVar4 = FUN_004f8a70(*(undefined4 *)(*(int *)(iVar3 + 8) + iVar5 * 4),"name=");
              if (iVar4 != 0) {
                FUN_00547bd0(param_1,0,iVar4 + 5,0xffffffff);
              }
              iVar5 = iVar5 + 1;
            } while (iVar5 < *(int *)(iVar3 + 0xc));
          }
        }
      }
    }
  }
  return;
}

