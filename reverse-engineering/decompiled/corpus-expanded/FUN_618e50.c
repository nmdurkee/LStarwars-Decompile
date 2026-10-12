/* Ghidra pseudocode, not original source.
 * ev_fbd0714d29abf1967b7a59c1140afabe8eda1c53d580ba604e59c833adf58051
 * Entry: 0x618e50; label: FUN_00618e50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00618e50(int *param_1,int *param_2)

{
  if (*param_1 == 0) {
    param_1[1] = (int)param_2;
  }
  else {
    *(int **)(*param_1 + 4) = param_2;
  }
  param_2[1] = 0;
  *param_2 = *param_1;
  *param_1 = (int)param_2;
  param_1[3] = (int)param_2;
  DAT_02900c84 = param_2;
  param_1[4] = 0;
  return;
}

