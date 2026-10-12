/* Ghidra pseudocode, not original source.
 * ev_08b01c57e23761db39961ff885ea8d3cae9c908a4b5feb85ed876c23ab277753
 * Entry: 0x6110c0; label: FUN_006110c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006110c0(int *param_1)

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

