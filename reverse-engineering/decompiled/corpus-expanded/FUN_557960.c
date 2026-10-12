/* Ghidra pseudocode, not original source.
 * ev_b0367b6b7ea93641fa3f234a6a49c94b930ee723d26ca433ffbeb1a06357d05a
 * Entry: 0x557960; label: FUN_00557960
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00557960(int param_1)

{
  if (param_1 != 0) {
    FUN_005a11b0(*(undefined4 *)(param_1 + 0x34),*(char *)(param_1 + 0x90) == '\x02');
    if (*(float *)(param_1 + 0x48) < 0.0) {
      FUN_005a1030(*(undefined4 *)(param_1 + 0x34),
                   *(float *)(param_1 + 0x50) * *(float *)(param_1 + 0x48),0);
      return;
    }
    FUN_005a1030(*(undefined4 *)(param_1 + 0x34),
                 *(float *)(param_1 + 0x4c) * *(float *)(param_1 + 0x48),0);
  }
  return;
}

