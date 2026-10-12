/* Ghidra pseudocode, not original source.
 * ev_fbd0714d29abf1967b7a59c1140afabe8eda1c53d580ba604e59c833adf58051
 * Entry: 0x618f50; label: FUN_00618f50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00618f50(undefined4 *param_1,int *param_2,int param_3)

{
  if (param_3 == 0) {
    if ((undefined4 *)param_1[1] == (undefined4 *)0x0) {
      *param_1 = param_2;
    }
    else {
      *(undefined4 *)param_1[1] = param_2;
    }
    *param_2 = 0;
    param_2[1] = param_1[1];
    param_1[1] = param_2;
    param_1[3] = param_2;
    DAT_02900c84 = param_2;
    param_1[4] = 0;
    return;
  }
  *param_2 = param_3;
  param_2[1] = *(int *)(param_3 + 4);
  *(int **)(param_3 + 4) = param_2;
  if (param_2[1] == 0) {
    *param_1 = param_2;
  }
  param_1[3] = *param_1;
  param_1[4] = 0;
  DAT_02900c84 = param_2;
  return;
}

