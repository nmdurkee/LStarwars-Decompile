/* Ghidra pseudocode, not original source.
 * ev_b393d28c9e9a0ec683edd3b274f1828e861e17aa87a3660c9a4e9e0f17cff856
 * Entry: 0x6cf3b0; label: FUN_006cf3b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_006cf3b0(int param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 unaff_EBX;
  undefined4 uVar3;
  undefined4 uStack_20;
  
  if ((param_1 != 0) && (piVar1 = *(int **)(param_1 + 0x14), piVar1 != (int *)0x0)) {
    uVar3 = 0;
    if (DAT_02973b9c != (code *)0x0) {
      uStack_20 = 0x6cf3dd;
      uVar3 = (*DAT_02973b9c)();
    }
    uStack_20 = 2;
    iVar2 = (**(code **)(*piVar1 + 0x18))(0,4);
    if (iVar2 != 0) {
      (**(code **)(*piVar1 + 0x28))(iVar2,uVar3);
      uStack_20 = unaff_EBX;
      FUN_006c9840(&uStack_20);
      FUN_006be910(iVar2,uStack_20,0,0,0,0);
      FUN_006c9bf0(&uStack_20,0);
      return 1;
    }
  }
  return 0;
}

