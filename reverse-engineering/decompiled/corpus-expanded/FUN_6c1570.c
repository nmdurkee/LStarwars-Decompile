/* Ghidra pseudocode, not original source.
 * ev_614da4738c60d4d314f1aae40ed3f18729decbec523d320f83fa909eb3c69e70
 * Entry: 0x6c1570; label: FUN_006c1570
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006c1570(int *param_1,int param_2)

{
  int *in_ECX;
  
  if (param_2 == 0) {
    *param_1 = *in_ECX;
    param_1[1] = 0;
    if (*in_ECX != 0) {
      *(int **)(*in_ECX + 4) = param_1;
    }
    if (in_ECX[1] == 0) {
      in_ECX[1] = (int)param_1;
    }
    in_ECX[2] = in_ECX[2] + 1;
    *in_ECX = (int)param_1;
    return;
  }
  *param_1 = param_2;
  param_1[1] = *(int *)(param_2 + 4);
  if (*(undefined4 **)(param_2 + 4) != (undefined4 *)0x0) {
    **(undefined4 **)(param_2 + 4) = param_1;
    *(int **)(param_2 + 4) = param_1;
    in_ECX[2] = in_ECX[2] + 1;
    return;
  }
  *in_ECX = (int)param_1;
  *(int **)(param_2 + 4) = param_1;
  in_ECX[2] = in_ECX[2] + 1;
  return;
}

