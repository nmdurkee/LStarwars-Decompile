/* Ghidra pseudocode, not original source.
 * ev_f9aef5a40e02ce8ca7a9836408264f920f991102075b72e653cbe4eaab14c8b7
 * Entry: 0x584780; label: FUN_00584780
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00584780(undefined4 param_1)

{
  float10 fVar1;
  
  fVar1 = (float10)FUN_004f8100(param_1);
  *(float *)(DAT_00954400 + 0x30) = (float)fVar1;
  return;
}

