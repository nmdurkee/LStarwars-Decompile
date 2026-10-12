/* Ghidra pseudocode, not original source.
 * ev_6fa6af6f6c20542b4b3f476ed9727be59ab920ff8cd58abbde73c8c49552840b
 * Entry: 0x5ca550; label: FUN_005ca550
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_005ca550(int param_1,int param_2)

{
  int iVar1;
  char *pcVar2;
  
  iVar1 = param_2 + 1;
  if (iVar1 < *(int *)(param_1 + 0x168)) {
    pcVar2 = (char *)(iVar1 * 0x60 + 0x50 + *(int *)(param_1 + 0x16c));
    do {
      if (*pcVar2 == *(char *)(param_2 * 0x60 + 0x50 + *(int *)(param_1 + 0x16c))) break;
      iVar1 = iVar1 + 1;
      pcVar2 = pcVar2 + 0x60;
    } while (iVar1 < *(int *)(param_1 + 0x168));
  }
  return iVar1 + -1;
}

