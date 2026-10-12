/* Ghidra pseudocode, not original source.
 * ev_fb4a243913288e8884e4b26b9d3f1b2cc90d3774ba2cd7b272b490162dad9d99
 * Entry: 0x46aec0; label: FUN_0046aec0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0046aec0(undefined4 param_1,int param_2)

{
  if (((*(byte *)(param_2 + 0x17) & 0x10) != 0) && ((*(byte *)(param_2 + 0x17) & 0x20) != 0)) {
    FUN_0046ae30(param_2 + 8);
  }
  return;
}

