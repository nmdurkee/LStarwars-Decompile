/* Ghidra pseudocode, not original source.
 * ev_be2e1b76976fde28c062f4f0fb6ba1ce818a6b2c78af6ba8f2a77520ff39bb32
 * Entry: 0x57b2f0; label: FUN_0057b2f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0057b2f0(undefined4 param_1)

{
  float10 fVar1;
  
  fVar1 = (float10)FUN_004f8100(param_1);
  *(float *)(DAT_00951c4c + 0x6c) = (float)fVar1;
  return;
}

