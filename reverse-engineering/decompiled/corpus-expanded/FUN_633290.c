/* Ghidra pseudocode, not original source.
 * ev_11aaf33bc566dbb5337d0358c8c7e7b90799e20019d0aefa05560726d7209bd1
 * Entry: 0x633290; label: FUN_00633290
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00633290(int param_1)

{
  if (param_1 == 0) {
    return;
  }
  if (*(int *)(param_1 + 0x20) != 0) {
    FUN_00633000();
    return;
  }
  FUN_00632a60();
  return;
}

