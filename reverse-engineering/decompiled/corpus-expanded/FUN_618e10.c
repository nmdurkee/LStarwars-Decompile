/* Ghidra pseudocode, not original source.
 * ev_fbd0714d29abf1967b7a59c1140afabe8eda1c53d580ba604e59c833adf58051
 * Entry: 0x618e10; label: FUN_00618e10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00618e10(undefined4 *param_1,undefined4 *param_2)

{
  if ((undefined4 *)param_1[1] == (undefined4 *)0x0) {
    *param_1 = param_2;
  }
  else {
    *(undefined4 *)param_1[1] = param_2;
  }
  param_2[1] = param_1[1];
  *param_2 = 0;
  param_1[1] = param_2;
  param_1[3] = *param_1;
  DAT_02900c84 = param_2;
  param_1[4] = 0;
  return;
}

