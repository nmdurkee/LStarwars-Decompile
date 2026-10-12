/* Ghidra analysis pseudocode, not original source.
 * ev_25f1bb0fd3b13d30151a1bfb26bccad5e839f981975d2103181562bea11eb120
 * Entry: 0x502bb0; label: FUN_00502bb0
 */

void FUN_00502bb0(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  iVar1 = *(int *)(param_1 + 0x58);
  piVar2 = *(int **)(iVar1 + 0x18);
  piVar3 = *(int **)(param_1 + 0xa4);
  if ((DAT_00921388 != (code *)0x0) && (iVar5 = 0, (short)piVar2[1] != 0)) {
    iVar7 = 0;
    iVar6 = 0;
    do {
      piVar4 = (int *)(*piVar3 + iVar6);
      if (*piVar4 != 0) {
        (*DAT_00921388)(param_1,iVar1,piVar4,*piVar2 + iVar7,param_2,param_3);
      }
      iVar5 = iVar5 + 1;
      iVar6 = iVar6 + 0x18;
      iVar7 = iVar7 + 100;
    } while (iVar5 < (int)(uint)*(ushort *)(piVar2 + 1));
  }
  return;
}

