/* Ghidra pseudocode, not original source.
 * ev_f73a5b0c0434a7d5d731dd250707e0e9320a0ad37df46b92dceb71be55e84b93
 * Entry: 0x5e5690; label: FUN_005e5690
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005e5690(int *param_1)

{
  DAT_00971ab8 = *param_1 + 0xfU & 0xfffffff0;
  *param_1 = (*param_1 + 0xfU & 0xfffffff0) + 0x40;
  return;
}

