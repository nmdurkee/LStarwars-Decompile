/* Ghidra pseudocode, not original source.
 * ev_ba19024e936acaebc8caa887b02629c3d2df1b51d473842281df89ce325ba5c8
 * Entry: 0x549bb0; label: FUN_00549bb0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00549bb0(undefined *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  if (param_1 == (undefined *)0x0) {
    param_1 = PTR_DAT_008021b4;
  }
  *(undefined4 *)(param_1 + 0x1d4) = param_2;
  *(undefined4 *)(param_1 + 0x1d8) = param_3;
  *(undefined4 *)(param_1 + 0x1dc) = param_4;
  return;
}

