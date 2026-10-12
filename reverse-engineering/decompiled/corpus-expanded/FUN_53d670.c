/* Ghidra pseudocode, not original source.
 * ev_65ca4a665d596d296f41bb3c37f26e684dc272ec4121c3f4d046db6dd8870575
 * Entry: 0x53d670; label: FUN_0053d670
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0053d670(undefined4 param_1,int param_2)

{
  if (param_2 != 0) {
    if (1 < *(uint *)(param_2 + 0x4b0)) {
      *(uint *)(param_2 + 0x4b0) = *(uint *)(param_2 + 0x4b0) - 1;
      return;
    }
    *(undefined4 *)(param_2 + 0x4b0) = 0;
  }
  return;
}

