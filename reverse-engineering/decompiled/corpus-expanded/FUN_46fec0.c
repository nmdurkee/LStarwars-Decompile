/* Ghidra pseudocode, not original source.
 * ev_d9512b1cdbab5300ab403012014fa5708c5416e00a513842278be36b13b8a77c
 * Entry: 0x46fec0; label: FUN_0046fec0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0046fec0(int *param_1)

{
  int iVar1;
  
  if ((param_1 == (int *)0x0) || (iVar1 = *param_1, iVar1 == 0)) {
    iVar1 = 0;
  }
  return iVar1;
}

