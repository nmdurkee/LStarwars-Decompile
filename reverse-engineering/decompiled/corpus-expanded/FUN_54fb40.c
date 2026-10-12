/* Ghidra pseudocode, not original source.
 * ev_9af94503fce638d48c98755f8a4ba03de7c5cdf51e6dce151974c12e75b3fd49
 * Entry: 0x54fb40; label: FUN_0054fb40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

