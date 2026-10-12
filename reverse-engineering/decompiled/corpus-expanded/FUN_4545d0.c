/* Ghidra pseudocode, not original source.
 * ev_b55b7a309ed021766e38758a92fbc8c97c8db4b0d277f859ab4c7f52da556e16
 * Entry: 0x4545d0; label: FUN_004545d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4
FUN_004545d0(undefined4 param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 0;
  if (param_6 != 0) {
    if (((param_3 != 0) && (piVar2 = *(int **)(param_3 + 0xd0), piVar2 != (int *)0x0)) &&
       (*piVar2 != 0)) {
      iVar4 = *piVar2;
    }
    iVar3 = 0;
    if (0 < param_5) {
      do {
        iVar1 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar3 * 4),"character=");
        if (iVar1 != 0) {
          if ((DAT_00923904 == (code *)0x0) ||
             (piVar2 = (int *)(*DAT_00923904)(param_1,iVar1 + 10), piVar2 == (int *)0x0)) {
            iVar4 = 0;
          }
          else {
            iVar4 = *piVar2;
          }
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < param_5);
    }
    if ((iVar4 != 0) && (*(int *)(iVar4 + 0xcd0) != 0)) {
      FUN_004882d0(iVar4,0);
    }
  }
  return 1;
}

