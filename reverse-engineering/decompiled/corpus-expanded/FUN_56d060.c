/* Ghidra pseudocode, not original source.
 * ev_312b56a8c21479f8c96fd7dc1d322c1a4486fb258981ae7e1dc00f07a4c49ce9
 * Entry: 0x56d060; label: FUN_0056d060
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0056d060(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  if (0 < *(int *)(param_3 + 0x50a4)) {
    iVar3 = 0;
    do {
      iVar1 = FUN_004f1ff0(*(int *)(param_3 + 0x50a0) + iVar3);
      if (iVar1 != 0) {
        FUN_00559ee0(param_1,param_2,0,*(int *)(param_3 + 0x50a0) + iVar3);
      }
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 0x24;
    } while (iVar2 < *(int *)(param_3 + 0x50a4));
  }
  return;
}

