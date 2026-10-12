/* Ghidra pseudocode, not original source.
 * ev_1c43a4838a2574475d6c9682bec7b0db8a67988369837137b0115a570ceb3a0a
 * Entry: 0x4fa880; label: FUN_004fa880
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_004fa880(undefined4 param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  short *psVar3;
  int iVar4;
  int iVar5;
  
  iVar2 = FUN_004fa3f0(param_1,1,DAT_0091ee88,0);
  if (iVar2 == 0) {
    return 0;
  }
  iVar5 = (*(int *)(param_2 + 0x28) - param_2) + *(int *)(param_2 + 0x20);
  FUN_004f1d90();
  if (iVar2 < 0x1000) {
    if (iVar2 < 0x400) {
      FUN_004ff3f0(iVar2 + -1,param_2,iVar5);
    }
    else {
      FUN_004f0380(iVar2);
    }
  }
  else {
    FUN_006dee60(iVar2 + -0x1000,param_2,iVar5,0);
  }
  *(int *)(param_2 + 0x14) = *(int *)(param_2 + 0x14) + param_2;
  *(int *)(param_2 + 0x20) = *(int *)(param_2 + 0x20) + param_2;
  iVar5 = 0;
  if (0 < *(int *)(param_2 + 0x18)) {
    iVar4 = 0;
    do {
      psVar3 = (short *)(*(int *)(param_2 + 0x14) + iVar4);
      if (0 < *psVar3) {
        piVar1 = (int *)(psVar3 + 2);
        *piVar1 = *piVar1 + param_2;
      }
      iVar5 = iVar5 + 1;
      iVar4 = iVar4 + 0xc;
    } while (iVar5 < *(int *)(param_2 + 0x18));
  }
  FUN_004f99e0(iVar2);
  return 1;
}

