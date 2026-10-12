/* Ghidra pseudocode, not original source.
 * ev_08b01c57e23761db39961ff885ea8d3cae9c908a4b5feb85ed876c23ab277753
 * Entry: 0x611060; label: FUN_00611060
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00611060(int *param_1,int *param_2)

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

