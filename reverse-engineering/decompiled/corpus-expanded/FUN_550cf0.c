/* Ghidra pseudocode, not original source.
 * ev_9af94503fce638d48c98755f8a4ba03de7c5cdf51e6dce151974c12e75b3fd49
 * Entry: 0x550cf0; label: FUN_00550cf0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4
FUN_00550cf0(float param_1,float param_2,float param_3,float param_4,float param_5,float param_6)

{
  if (0.0 <= (param_2 - param_4) * (param_3 - param_5) + (param_1 - param_3) * (param_6 - param_4))
  {
    return 1;
  }
  return 0;
}

