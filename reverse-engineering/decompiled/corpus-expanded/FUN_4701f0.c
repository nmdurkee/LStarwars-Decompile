/* Ghidra pseudocode, not original source.
 * ev_d9512b1cdbab5300ab403012014fa5708c5416e00a513842278be36b13b8a77c
 * Entry: 0x4701f0; label: FUN_004701f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004701f0(undefined4 param_1)

{
  float10 fVar1;
  
  fVar1 = (float10)FUN_004f8100(param_1);
  *(float *)(DAT_00879468 + 0x534) = (float)fVar1;
  return;
}

