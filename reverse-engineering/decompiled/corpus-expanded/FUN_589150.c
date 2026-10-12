/* Ghidra pseudocode, not original source.
 * ev_ebb7262bcf4e9a2f6ce5c4899044ae4c8e0a5d5c0ddeff4eaa1e0a5d9d7a0639
 * Entry: 0x589150; label: FUN_00589150
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00589150(undefined4 param_1)

{
  float10 fVar1;
  
  fVar1 = (float10)FUN_004f8100(param_1);
  *(float *)(DAT_00954404 + 0x8c) = ABS((float)fVar1);
  return;
}

