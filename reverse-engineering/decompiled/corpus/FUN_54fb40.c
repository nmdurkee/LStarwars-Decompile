/* Ghidra analysis pseudocode, not original source.
 * ev_ec07135468de31ab5fb92b99d3a0e31a017920018520f35a1e7400fac21801d6
 * Entry: 0x54fb40; label: FUN_0054fb40
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_0054fb40(float param_1,float param_2,float param_3)

{
  param_3 = _DAT_00925018 * param_3;
  if (1.0 < param_3) {
    param_3 = 1.0;
  }
  return (float10)(param_1 + param_3 * (param_2 - param_1));
}

