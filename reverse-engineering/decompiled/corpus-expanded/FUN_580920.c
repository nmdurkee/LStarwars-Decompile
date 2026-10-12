/* Ghidra pseudocode, not original source.
 * ev_c772dacde58c2298bb9853679eadc775f76d2c3f9befd22496ec5bd64ba1d43a
 * Entry: 0x580920; label: FUN_00580920
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00580920(int param_1,undefined4 *param_2)

{
  *param_2 = *(undefined4 *)(param_1 + 0x80);
  param_2[1] = *(undefined4 *)(param_1 + 0x84);
  param_2[2] = *(undefined4 *)(param_1 + 0x88);
  return;
}

