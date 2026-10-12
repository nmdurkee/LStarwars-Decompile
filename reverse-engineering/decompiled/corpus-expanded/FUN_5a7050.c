/* Ghidra pseudocode, not original source.
 * ev_1147004b9dc166d1e84637369286a2c1a549644e29d4b7aad5b4a967d59cac62
 * Entry: 0x5a7050; label: FUN_005a7050
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005a7050(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  if (0 < *(int *)(param_3 + 0x46c0)) {
    iVar3 = 0;
    do {
      iVar1 = FUN_004f1ff0(*(int *)(param_3 + 0x46bc) + 0x44 + iVar3);
      if (iVar1 != 0) {
        FUN_00559ee0(param_1,param_2,0,*(int *)(param_3 + 0x46bc) + iVar3);
      }
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 0xd4;
    } while (iVar2 < *(int *)(param_3 + 0x46c0));
  }
  return;
}

