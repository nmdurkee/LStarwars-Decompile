/* Ghidra pseudocode, not original source.
 * ev_b8f4d44f892ded82cd7ffb9ce06d4ee71453c0b8ed59e2b020606927ce90ab67
 * Entry: 0x575a30; label: FUN_00575a30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00575a30(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (((param_3 != 0) && (*(int *)(param_3 + 0x4698) != 0)) &&
     (iVar2 = 0, 0 < *(int *)(param_3 + 0x469c))) {
    iVar3 = 0;
    do {
      iVar1 = *(int *)(param_3 + 0x4698) + iVar3;
      FUN_0055aa60(*(undefined4 *)(param_3 + 0x2ac8),"Door_",iVar1,iVar1 + 0x40,0x40);
      FUN_00559ee0(param_1,param_2,0,*(int *)(param_3 + 0x4698) + iVar3);
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 0x128;
    } while (iVar2 < *(int *)(param_3 + 0x469c));
  }
  return;
}

