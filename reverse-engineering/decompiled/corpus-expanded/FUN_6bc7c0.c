/* Ghidra pseudocode, not original source.
 * ev_48ff0e80e492cdbcfd6e19b242aa934bd4f134661b9f943047c850011602a6eb
 * Entry: 0x6bc7c0; label: FUN_006bc7c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_006bc7c0(uint param_1)

{
  int in_ECX;
  
  if (param_1 < 10) {
    return param_1 * 0xa8 + 0x2ac + in_ECX;
  }
  return 0;
}

