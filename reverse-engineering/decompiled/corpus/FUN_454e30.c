/* Ghidra analysis pseudocode, not original source.
 * ev_8c5b0e575cc3a77a31b08f4844e5d8b5ee6e8018ce9d45deeeec0b9133723e57
 * Entry: 0x454e30; label: FUN_00454e30
 */

undefined4
FUN_00454e30(undefined4 param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int local_8;
  int local_4;
  
  iVar4 = 0;
  local_8 = 0;
  local_4 = 0;
  if (param_6 != 0) {
    if (((param_3 != 0) && (piVar2 = *(int **)(param_3 + 0xd0), piVar2 != (int *)0x0)) &&
       (*piVar2 != 0)) {
      iVar4 = *piVar2;
    }
    iVar5 = 0;
    iVar1 = 0;
    iVar3 = 0;
    if (0 < param_5) {
      do {
        iVar1 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar5 * 4),"character=");
        if (iVar1 == 0) {
          iVar1 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar5 * 4),"value=");
          if (iVar1 == 0) {
            iVar1 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar5 * 4),"torpedo=");
            if (iVar1 != 0) {
              FUN_005147c0(param_2,iVar1 + 8);
              local_4 = FUN_006e6b90();
            }
          }
          else {
            FUN_005147c0(param_2,iVar1 + 6);
            local_8 = FUN_006e6b90();
          }
        }
        else if ((DAT_00923904 == (code *)0x0) ||
                (piVar2 = (int *)(*DAT_00923904)(param_1,iVar1 + 10), piVar2 == (int *)0x0)) {
          iVar4 = 0;
        }
        else {
          iVar4 = *piVar2;
        }
        iVar5 = iVar5 + 1;
        iVar1 = local_4;
        iVar3 = local_8;
      } while (iVar5 < param_5);
    }
    if (((iVar4 != 0) && (iVar4 + 0x80 != 0)) && ((iVar3 != 0 || (iVar1 != 0)))) {
      FUN_0046d780(iVar4 + 0x80,0xffffffff,iVar3,iVar1);
    }
  }
  return 1;
}

