/* Ghidra pseudocode, not original source.
 * ev_61672b8aee088191725705707427e6d28989067365c008b5a0fbb4fab739a1ee
 * Entry: 0x5ae330; label: FUN_005ae330
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_005ae330(undefined4 param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  piVar1 = *(int **)(param_2 + 0x5108);
  iVar3 = 0;
  if (0 < piVar1[1]) {
    iVar4 = 0;
    do {
      iVar2 = FUN_004f8b10(*piVar1 + iVar4,param_1);
      if (iVar2 == 0) {
        return **(int **)(param_2 + 0x5108) + iVar3 * 0x28;
      }
      piVar1 = *(int **)(param_2 + 0x5108);
      iVar3 = iVar3 + 1;
      iVar4 = iVar4 + 0x28;
    } while (iVar3 < piVar1[1]);
  }
  return 0;
}

