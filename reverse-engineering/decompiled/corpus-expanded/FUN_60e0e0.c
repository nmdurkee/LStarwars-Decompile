/* Ghidra pseudocode, not original source.
 * ev_168b65d5705473c04d5f4e526193e1abf552a66e90d2db36f509f2a3124060c2
 * Entry: 0x60e0e0; label: FUN_0060e0e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0060e0e0(int *param_1)

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

