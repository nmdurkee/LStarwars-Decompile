/* Ghidra pseudocode, not original source.
 * ev_554bacc3f16b6ba5ba2e9bdc745347cbc06d0daeabfbc4224973a16c83b60b9e
 * Entry: 0x4c0900; label: FUN_004c0900
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004c0900(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  if (0 < *(int *)(param_3 + 0x5094)) {
    iVar3 = 0;
    do {
      iVar1 = FUN_004f1ff0(*(int *)(param_3 + 0x5090) + iVar3);
      if (iVar1 != 0) {
        FUN_00559ee0(param_1,param_2,0,*(int *)(param_3 + 0x5090) + iVar3);
      }
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 0x54;
    } while (iVar2 < *(int *)(param_3 + 0x5094));
  }
  return;
}

