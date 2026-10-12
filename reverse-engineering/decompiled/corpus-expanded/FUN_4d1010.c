/* Ghidra pseudocode, not original source.
 * ev_1794ca22652287671530b7d2e638694f2898180de05a8f26cc5ace6b6aa326ae
 * Entry: 0x4d1010; label: FUN_004d1010
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004d1010(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  if (0 < *(int *)(param_3 + 0x505c)) {
    iVar3 = 0;
    do {
      iVar1 = FUN_004f1ff0(*(int *)(param_3 + 0x5058) + iVar3);
      if (iVar1 != 0) {
        FUN_00559ee0(param_1,param_2,0,*(int *)(param_3 + 0x5058) + iVar3);
      }
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 0x48;
    } while (iVar2 < *(int *)(param_3 + 0x505c));
  }
  return;
}

