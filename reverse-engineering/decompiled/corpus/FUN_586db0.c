/* Ghidra analysis pseudocode, not original source.
 * ev_10a52eb163d37e971edce79c1fc8a96922bb2f4e033d0de10a3e0adcd5f651d2
 * Entry: 0x586db0; label: FUN_00586db0
 */

void FUN_00586db0(undefined4 param_1)

{
  float10 fVar1;
  
  fVar1 = (float10)FUN_004f8100(param_1);
  *(float *)(DAT_00954404 + 0x5c) = (float)((fVar1 * (float10)3.1415927410125732) / (float10)180.0);
  return;
}

