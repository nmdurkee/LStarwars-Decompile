/* Ghidra pseudocode, not original source.
 * ev_4c4127be7d58e8981fbef62e7b9304e5f7a8f47caff33366593b2d257bcf3f12
 * Entry: 0x59eaf0; label: FUN_0059eaf0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0059eaf0(int param_1)

{
  FUN_004f7fb0(param_1);
  if (*(int *)(param_1 + 0x510) != 0) {
    FUN_004f1f40(&DAT_009562c8,*(int *)(param_1 + 0x510),0x20);
  }
  return;
}

