/* Ghidra analysis pseudocode, not original source.
 * ev_f48dedfde503d95163bfd3eb2ed6449a9a2f0083b079fa518a64f4b7b72b2f93
 * Entry: 0x444490; label: FUN_00444490
 */

undefined4
FUN_00444490(undefined4 param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  iVar3 = 0;
  uVar4 = 0;
  if (param_6 != 0) {
    if (((param_3 != 0) && (piVar2 = *(int **)(param_3 + 0xd0), piVar2 != (int *)0x0)) &&
       (*piVar2 != 0)) {
      iVar3 = *piVar2;
    }
    iVar5 = 0;
    if (0 < param_5) {
      do {
        iVar1 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar5 * 4),"character=");
        if (iVar1 == 0) {
          iVar1 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar5 * 4),&DAT_00757700);
          if (iVar1 != 0) {
            FUN_005147c0(param_2,iVar1 + 4);
            uVar4 = FUN_006e6b90();
            if (((int)uVar4 < 0) || (0x10 < (int)uVar4)) {
              uVar4 = 0;
            }
          }
        }
        else if ((DAT_00923904 == (code *)0x0) ||
                (piVar2 = (int *)(*DAT_00923904)(param_1,iVar1 + 10), piVar2 == (int *)0x0)) {
          iVar3 = 0;
        }
        else {
          iVar3 = *piVar2;
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < param_5);
      if (uVar4 != 0) {
        if (DAT_0093d500 < 1) {
          return 1;
        }
        iVar5 = 0;
        iVar3 = DAT_0093d504;
        do {
          if ((((*(uint *)(iVar3 + 0x1fc) & 1) != 0) && ((*(uint *)(iVar3 + 0x1fc) & 0x1000) != 0))
             && (*(byte *)(iVar3 + 0x378) == uVar4)) {
            FUN_00414bb0(iVar3);
          }
          iVar5 = iVar5 + 1;
          iVar3 = iVar3 + 0x10d8;
        } while (iVar5 < DAT_0093d500);
        return 1;
      }
    }
    if (iVar3 != 0) {
      FUN_00414bb0(iVar3);
    }
  }
  return 1;
}

