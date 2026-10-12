/* Ghidra pseudocode, not original source.
 * ev_3bb2d5213416039971b6dd1caa939c59b1318a27f895c0ebb43a5b863f1b474b
 * Entry: 0x5b9e70; label: FUN_005b9e70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005b9e70(undefined4 *param_1,undefined4 param_2)

{
  if (param_1 == (undefined4 *)0x0) {
    DAT_008066c0 = param_2;
    return;
  }
  *param_1 = param_2;
  return;
}

