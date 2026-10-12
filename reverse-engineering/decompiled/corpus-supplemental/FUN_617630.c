/* Ghidra pseudocode, not original source.
 * ev_659eea1dc00a859f9d32b97d98369d0a367714cfb07a93b4448bfffc51247c8f
 * Entry: 0x617630; label: FUN_00617630
 * Boundary hypotheses: reports/native-supplemental-entry-inspection.json.
 */

void FUN_00617630(undefined4 param_1,int param_2)

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

