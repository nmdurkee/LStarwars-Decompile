/* Ghidra pseudocode, not original source.
 * ev_ba19024e936acaebc8caa887b02629c3d2df1b51d473842281df89ce325ba5c8
 * Entry: 0x54a510; label: FUN_0054a510
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0054a510(undefined *param_1)

{
  if (param_1 == (undefined *)0x0) {
    param_1 = PTR_DAT_008021b4;
  }
  return ((int)ROUND(*(float *)(param_1 + 0x218)) & 0xffffU) + *(int *)(param_1 + 0x1fc);
}

