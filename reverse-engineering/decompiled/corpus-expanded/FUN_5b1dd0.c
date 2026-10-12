/* Ghidra pseudocode, not original source.
 * ev_f229a78d5de0bf17b480d7e9a60f462b055d08f1d682cbbe42c93314af3c723e
 * Entry: 0x5b1dd0; label: FUN_005b1dd0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005b1dd0(int param_1,int *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (((param_3 != 0) && (0 < *(int *)(param_3 + 0x46d4))) &&
     (iVar3 = 0, 0 < *(int *)(param_3 + 0x46d4))) {
    iVar2 = 0;
    do {
      iVar1 = (int)*(short *)(*(int *)(param_3 + 0x46d8) + 6 + iVar2);
      if (iVar1 != -1) {
        *(int *)(param_1 + *param_2 * 4) = iVar1;
        *param_2 = *param_2 + 1;
      }
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 0x10;
    } while (iVar3 < *(int *)(param_3 + 0x46d4));
  }
  return;
}

