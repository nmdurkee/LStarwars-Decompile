/* Ghidra pseudocode, not original source.
 * ev_8d558f2b7d37f7c2d88d0d36eae1cf7a4b5788ac1ea6cb26aea78645de7b2f49
 * Entry: 0x60bf70; label: FUN_0060bf70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0060bf70(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  for (; param_1 != param_2; param_1 = param_1 + 2) {
    *param_1 = *param_3;
    param_1[1] = param_3[1];
  }
  return;
}

