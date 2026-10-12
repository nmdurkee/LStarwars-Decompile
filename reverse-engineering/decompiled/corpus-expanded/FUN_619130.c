/* Ghidra pseudocode, not original source.
 * ev_fbd0714d29abf1967b7a59c1140afabe8eda1c53d580ba604e59c833adf58051
 * Entry: 0x619130; label: FUN_00619130
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00619130(int *param_1,int *param_2)

{
  int iVar1;
  
  if ((int *)*param_1 == param_2) {
    *param_1 = *param_2;
  }
  if ((int *)param_1[1] == param_2) {
    param_1[1] = param_2[1];
  }
  if ((int *)param_1[2] == param_2) {
    iVar1 = *param_2;
    if (iVar1 == 0) {
      iVar1 = param_2[1];
    }
    param_1[2] = iVar1;
  }
  param_1[3] = *param_1;
  param_1[4] = 0;
  if (*param_2 != 0) {
    *(int *)(*param_2 + 4) = param_2[1];
  }
  if ((int *)param_2[1] != (int *)0x0) {
    *(int *)param_2[1] = *param_2;
  }
  param_2[1] = 0;
  *param_2 = 0;
  return;
}

