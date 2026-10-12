/* Ghidra pseudocode, not original source.
 * ev_f6678a28cc19d550655313a6a6f4f7bb8e44fc9612bb24799d4de398af21bc4a
 * Entry: 0x4c82e0; label: FUN_004c82e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004c82e0(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  if (0 < *(int *)(param_3 + 0x5064)) {
    iVar3 = 0;
    do {
      iVar1 = FUN_004f1ff0(*(int *)(param_3 + 0x5060) + iVar3);
      if (iVar1 != 0) {
        FUN_00559ee0(param_1,param_2,0,*(int *)(param_3 + 0x5060) + iVar3);
      }
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 0x94;
    } while (iVar2 < *(int *)(param_3 + 0x5064));
  }
  return;
}

