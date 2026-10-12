/* Ghidra pseudocode, not original source.
 * ev_d9512b1cdbab5300ab403012014fa5708c5416e00a513842278be36b13b8a77c
 * Entry: 0x46fa90; label: FUN_0046fa90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0046fa90(int param_1)

{
  byte *pbVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  if ((((param_1 != 0) && (piVar2 = *(int **)(param_1 + 0x5100), piVar2 != (int *)0x0)) &&
      (*piVar2 != 0)) && (iVar3 = 0, 0 < piVar2[1])) {
    iVar4 = 0;
    do {
      param_1 = *piVar2;
      pbVar1 = (byte *)(param_1 + 0x2b + iVar4);
      *pbVar1 = *pbVar1 | 3;
      param_1 = param_1 + iVar4;
      iVar3 = iVar3 + 1;
      iVar4 = iVar4 + 0x2c;
    } while (iVar3 < piVar2[1]);
  }
  return param_1;
}

