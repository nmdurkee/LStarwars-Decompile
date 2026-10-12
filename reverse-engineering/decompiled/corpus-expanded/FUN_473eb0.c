/* Ghidra pseudocode, not original source.
 * ev_f56492005d3db2572965d416e35be25a43fb24333701b400d47d471ee6ec09ab
 * Entry: 0x473eb0; label: FUN_00473eb0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00473eb0(undefined4 param_1,undefined4 param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (((param_3 != 0) && (piVar1 = *(int **)(param_3 + 0x5074), piVar1 != (int *)0x0)) &&
     (iVar3 = 0, 0 < *piVar1)) {
    iVar4 = 0;
    do {
      iVar2 = FUN_004f1ff0(piVar1[3] + 0x40 + iVar4);
      if (iVar2 != 0) {
        FUN_00559ee0(param_1,param_2,0,*(int *)(*(int *)(param_3 + 0x5074) + 0xc) + iVar4);
      }
      piVar1 = *(int **)(param_3 + 0x5074);
      iVar3 = iVar3 + 1;
      iVar4 = iVar4 + 0xa0;
    } while (iVar3 < *piVar1);
  }
  return;
}

