/* Ghidra pseudocode, not original source.
 * ev_614da4738c60d4d314f1aae40ed3f18729decbec523d320f83fa909eb3c69e70
 * Entry: 0x6c1450; label: FUN_006c1450
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006c1450(int *param_1,int *param_2)

{
  int *in_ECX;
  
  if (param_2 == (int *)0x0) {
    *param_1 = 0;
    param_1[1] = in_ECX[1];
    if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
      *(undefined4 *)in_ECX[1] = param_1;
    }
    in_ECX[1] = (int)param_1;
    if (*in_ECX == 0) {
      *in_ECX = (int)param_1;
    }
    in_ECX[2] = in_ECX[2] + 1;
    return;
  }
  param_1[1] = (int)param_2;
  *param_1 = *param_2;
  if (*param_2 != 0) {
    *(int **)(*param_2 + 4) = param_1;
    *param_2 = (int)param_1;
    in_ECX[2] = in_ECX[2] + 1;
    return;
  }
  in_ECX[1] = (int)param_1;
  *param_2 = (int)param_1;
  in_ECX[2] = in_ECX[2] + 1;
  return;
}

