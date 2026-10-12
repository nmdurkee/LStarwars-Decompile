/* Ghidra pseudocode, not original source.
 * ev_48ff0e80e492cdbcfd6e19b242aa934bd4f134661b9f943047c850011602a6eb
 * Entry: 0x6bc7a0; label: FUN_006bc7a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_006bc7a0(uint param_1)

{
  int in_ECX;
  
  if (param_1 < 10) {
    return *(undefined4 *)(param_1 * 0xa8 + 0x34c + in_ECX);
  }
  return 0;
}

