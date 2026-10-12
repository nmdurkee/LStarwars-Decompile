/* Ghidra pseudocode, not original source.
 * ev_d9512b1cdbab5300ab403012014fa5708c5416e00a513842278be36b13b8a77c
 * Entry: 0x46fe50; label: FUN_0046fe50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0046fe50(undefined4 param_1,undefined4 param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (((param_3 != 0) && (piVar1 = *(int **)(param_3 + 0x5100), piVar1 != (int *)0x0)) &&
     (iVar3 = 0, 0 < piVar1[1])) {
    iVar4 = 0;
    do {
      iVar2 = FUN_004f1ff0(*piVar1 + iVar4);
      if (iVar2 != 0) {
        FUN_00559ee0(param_1,param_2,0,**(int **)(param_3 + 0x5100) + iVar4);
      }
      piVar1 = *(int **)(param_3 + 0x5100);
      iVar3 = iVar3 + 1;
      iVar4 = iVar4 + 0x2c;
    } while (iVar3 < piVar1[1]);
  }
  return;
}

