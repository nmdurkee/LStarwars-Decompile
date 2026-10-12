/* Ghidra pseudocode, not original source.
 * ev_61672b8aee088191725705707427e6d28989067365c008b5a0fbb4fab739a1ee
 * Entry: 0x5ae150; label: FUN_005ae150
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005ae150(undefined4 param_1,undefined4 param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (param_3 != 0) {
    piVar1 = *(int **)(param_3 + 0x5108);
    iVar3 = 0;
    if (0 < piVar1[1]) {
      iVar4 = 0;
      do {
        iVar2 = FUN_004f1ff0(*piVar1 + iVar4);
        if (iVar2 != 0) {
          FUN_00559ee0(param_1,param_2,0,**(int **)(param_3 + 0x5108) + iVar4);
        }
        piVar1 = *(int **)(param_3 + 0x5108);
        iVar3 = iVar3 + 1;
        iVar4 = iVar4 + 0x28;
      } while (iVar3 < piVar1[1]);
    }
  }
  return;
}

