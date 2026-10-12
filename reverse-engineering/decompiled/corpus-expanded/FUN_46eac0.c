/* Ghidra pseudocode, not original source.
 * ev_da30da9df459bd28e82b339ffdc0f4cd1266c83ded903d656831cff2a8a86063
 * Entry: 0x46eac0; label: FUN_0046eac0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0046eac0(undefined4 param_1,undefined4 param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (((param_3 != 0) && (piVar1 = *(int **)(param_3 + 0x5070), piVar1 != (int *)0x0)) &&
     (iVar3 = 0, 0 < *piVar1)) {
    iVar4 = 0;
    do {
      iVar2 = FUN_004f1ff0(piVar1[1] + 0x40 + iVar4);
      if (iVar2 != 0) {
        FUN_00559ee0(param_1,param_2,0,*(int *)(*(int *)(param_3 + 0x5070) + 4) + iVar4);
      }
      piVar1 = *(int **)(param_3 + 0x5070);
      iVar3 = iVar3 + 1;
      iVar4 = iVar4 + 0x90;
    } while (iVar3 < *piVar1);
  }
  return;
}

