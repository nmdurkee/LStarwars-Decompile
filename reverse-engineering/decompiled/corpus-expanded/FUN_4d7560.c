/* Ghidra pseudocode, not original source.
 * ev_7cce3243898a12dda79e95a496780a4d79cb1010b8a976b902fd46336e9989b6
 * Entry: 0x4d7560; label: FUN_004d7560
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004d7560(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  if (0 < *(int *)(param_3 + 0x468c)) {
    iVar3 = 0;
    do {
      iVar1 = FUN_004f1ff0(*(int *)(param_3 + 0x4688) + iVar3);
      if (iVar1 != 0) {
        FUN_00559ee0(param_1,param_2,0,*(int *)(param_3 + 0x4688) + iVar3);
      }
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 0x7c;
    } while (iVar2 < *(int *)(param_3 + 0x468c));
  }
  return;
}

