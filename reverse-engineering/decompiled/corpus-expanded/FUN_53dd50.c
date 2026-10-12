/* Ghidra pseudocode, not original source.
 * ev_65ca4a665d596d296f41bb3c37f26e684dc272ec4121c3f4d046db6dd8870575
 * Entry: 0x53dd50; label: FUN_0053dd50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4
FUN_0053dd50(float param_1,float param_2,float param_3,float param_4,float param_5,float param_6)

{
  if (0.0 <= (param_2 - param_4) * (param_3 - param_5) + (param_1 - param_3) * (param_6 - param_4))
  {
    return 1;
  }
  return 0;
}

