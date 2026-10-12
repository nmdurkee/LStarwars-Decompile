/* Ghidra pseudocode, not original source.
 * ev_f349b1a9efc39563d2f2ebe5dc458b8d9d47a8328d1b609022bb24691faec82f
 * Entry: 0x5727c0; label: FUN_005727c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005727c0(int param_1)

{
  if ((((*(char *)(param_1 + 0x283) == '\x01') || (*(char *)(param_1 + 0x283) == '\t')) &&
      (*(float *)(param_1 + 0x220) <= *(float *)(param_1 + 0x188))) &&
     (*(float *)(param_1 + 0x17c) <= *(float *)(param_1 + 0x220))) {
    return 1;
  }
  return 0;
}

