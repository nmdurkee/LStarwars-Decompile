/* Ghidra pseudocode, not original source.
 * ev_01c84f1d9d20bf940b93d5cccd5d039a55498943f529f614c2585109312f1f15
 * Entry: 0x5769b0; label: FUN_005769b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005769b0(int param_1)

{
  if ((param_1 != 0) && (*(char *)(param_1 + 0x14) == '\0')) {
    *(undefined1 *)(param_1 + 0x14) = 1;
    FUN_005766e0();
    return;
  }
  return;
}

