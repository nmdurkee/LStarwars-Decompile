/* Ghidra analysis pseudocode, not original source.
 * ev_10a52eb163d37e971edce79c1fc8a96922bb2f4e033d0de10a3e0adcd5f651d2
 * Entry: 0x586ed0; label: FUN_00586ed0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00586ed0(undefined4 param_1)

{
  float10 fVar1;
  
  fVar1 = (float10)FUN_004f8100(param_1);
  if (0.0 < (float)fVar1) {
    *(float *)(DAT_00954404 + 0x74) = (float)fVar1;
    _DAT_0095440c = _DAT_0095440c | 4;
    return;
  }
  return;
}

