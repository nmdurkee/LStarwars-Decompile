/* Ghidra pseudocode, not original source.
 * ev_6c7022c87010c6d39f3f3226e46062ec65b94628332be136b3f738ab843f9afe
 * Entry: 0x4cde30; label: FUN_004cde30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004cde30(undefined4 param_1)

{
  float10 fVar1;
  
  fVar1 = (float10)FUN_004f8100(param_1);
  *(float *)(DAT_00880608 + 0x44) = (float)fVar1;
  return;
}

