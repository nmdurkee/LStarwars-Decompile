/* Ghidra pseudocode, not original source.
 * ev_9f880a640db7021abf6bd9453b6c2d9d41a7c75291a178dd1542c0e98d960678
 * Entry: 0x6b9250; label: FUN_006b9250
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006b9250(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  if (0 < DAT_02973bac) {
    iVar2 = 0;
    iVar1 = DAT_02973b90;
    do {
      if (*(int *)(iVar2 + 0x14 + iVar1) != 0) {
        (**(code **)(**(int **)(iVar2 + 0x14 + iVar1) + 4))(param_1);
        iVar1 = DAT_02973b90;
      }
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 0x18;
    } while (iVar3 < DAT_02973bac);
  }
  return;
}

