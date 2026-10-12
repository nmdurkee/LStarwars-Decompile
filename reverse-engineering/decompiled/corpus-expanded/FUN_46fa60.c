/* Ghidra pseudocode, not original source.
 * ev_d9512b1cdbab5300ab403012014fa5708c5416e00a513842278be36b13b8a77c
 * Entry: 0x46fa60; label: FUN_0046fa60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0046fa60(int *param_1,int param_2)

{
  byte *pbVar1;
  
  if (param_1 != (int *)0x0) {
    pbVar1 = (byte *)(*param_1 + 0x2b);
    *pbVar1 = *pbVar1 ^ (param_2 != 0 ^ *(byte *)(*param_1 + 0x2b)) & 1;
  }
  return;
}

