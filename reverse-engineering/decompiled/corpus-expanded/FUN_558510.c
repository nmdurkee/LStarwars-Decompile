/* Ghidra pseudocode, not original source.
 * ev_f8ed381e2b466dd5bc773ab3f84ab60966b69e10a49b3e28fcf3f54e00ea1563
 * Entry: 0x558510; label: FUN_00558510
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00558510(int param_1,undefined4 param_2)

{
  *(uint *)(param_1 + 0x94) = *(uint *)(param_1 + 0x94) | 4;
  *(undefined4 *)(param_1 + 0x48) = param_2;
  return;
}

