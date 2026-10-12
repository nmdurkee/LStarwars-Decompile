/* Ghidra pseudocode, not original source.
 * ev_614da4738c60d4d314f1aae40ed3f18729decbec523d320f83fa909eb3c69e70
 * Entry: 0x6c1630; label: FUN_006c1630
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006c1630(int *param_1)

{
  int *in_ECX;
  
  if (*param_1 == 0) {
    in_ECX[1] = param_1[1];
  }
  else {
    *(int *)(*param_1 + 4) = param_1[1];
  }
  if ((int *)param_1[1] == (int *)0x0) {
    *in_ECX = *param_1;
  }
  else {
    *(int *)param_1[1] = *param_1;
  }
  *param_1 = 0;
  param_1[1] = 0;
  in_ECX[2] = in_ECX[2] + -1;
  return;
}

