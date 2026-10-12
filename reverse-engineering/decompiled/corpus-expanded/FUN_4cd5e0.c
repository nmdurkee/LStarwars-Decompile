/* Ghidra pseudocode, not original source.
 * ev_8be83d5a314ed06484cc1a00e0611cd4a1346ac66c548b102291ab30b68096a0
 * Entry: 0x4cd5e0; label: FUN_004cd5e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004cd5e0(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  if (0 < *(int *)(param_3 + 0x507c)) {
    iVar3 = 0;
    do {
      iVar1 = FUN_004f1ff0(*(int *)(param_3 + 0x5078) + iVar3);
      if (iVar1 != 0) {
        FUN_00559ee0(param_1,param_2,0,*(int *)(param_3 + 0x5078) + iVar3);
      }
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 0x70;
    } while (iVar2 < *(int *)(param_3 + 0x507c));
  }
  return;
}

