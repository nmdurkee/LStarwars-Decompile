/* Ghidra pseudocode, not original source.
 * ev_01c84f1d9d20bf940b93d5cccd5d039a55498943f529f614c2585109312f1f15
 * Entry: 0x5787d0; label: FUN_005787d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005787d0(int param_1,undefined2 param_2)

{
  if (param_1 != 0) {
    *(undefined1 *)(param_1 + 0x7b5) = (undefined1)DAT_008028b0;
    *(undefined2 *)(param_1 + 0x7aa) = param_2;
  }
  return;
}

