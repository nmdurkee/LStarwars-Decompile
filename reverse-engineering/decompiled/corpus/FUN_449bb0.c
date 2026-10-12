/* Ghidra analysis pseudocode, not original source.
 * ev_f70dbfb4dc55c21d9a8b2990429bfe298595e1ea041c5f65e2960caacde39e05
 * Entry: 0x449bb0; label: FUN_00449bb0
 */

undefined4
FUN_00449bb0(undefined4 param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar4 = 0;
  iVar3 = 1;
  if (param_6 != 0) {
    if (((param_3 != 0) && (piVar1 = *(int **)(param_3 + 0xd0), piVar1 != (int *)0x0)) &&
       (*piVar1 != 0)) {
      iVar4 = *piVar1;
    }
    iVar6 = 0;
    iVar5 = iVar4;
    if (0 < param_5) {
      do {
        iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar6 * 4),"player1");
        iVar5 = DAT_0093d810;
        if (((iVar2 == 0) &&
            (iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar6 * 4),"player"),
            iVar5 = DAT_0093d810, iVar2 == 0)) &&
           ((iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar6 * 4),"player2"),
            iVar5 = DAT_0093d814, iVar2 == 0 &&
            (iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar6 * 4),"FALSE"), iVar5 = iVar4,
            iVar2 != 0)))) {
          iVar3 = 0;
        }
        iVar6 = iVar6 + 1;
        iVar4 = iVar5;
      } while (iVar6 < param_5);
    }
    if (iVar5 != 0) {
      *(uint *)(iVar5 + 0x4b0) =
           *(uint *)(iVar5 + 0x4b0) ^ (iVar3 << 0x12 ^ *(uint *)(iVar5 + 0x4b0)) & 0x40000;
      return 1;
    }
  }
  return 1;
}

