/* Ghidra pseudocode, not original source.
 * ev_614da4738c60d4d314f1aae40ed3f18729decbec523d320f83fa909eb3c69e70
 * Entry: 0x6c11f0; label: FUN_006c11f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006c11f0(int param_1,int param_2)

{
  int *in_ECX;
  
  if (param_2 == 0) {
    *(undefined4 *)(param_1 + 4) = 0;
    *(int *)(param_1 + 8) = in_ECX[1];
    if (in_ECX[1] != 0) {
      *(int *)(in_ECX[1] + 4) = param_1;
    }
    in_ECX[1] = param_1;
    if (*in_ECX == 0) {
      *in_ECX = param_1;
    }
    in_ECX[2] = in_ECX[2] + 1;
    return;
  }
  *(int *)(param_1 + 8) = param_2;
  *(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_2 + 4);
  if (*(int *)(param_2 + 4) != 0) {
    *(int *)(*(int *)(param_2 + 4) + 8) = param_1;
    *(int *)(param_2 + 4) = param_1;
    in_ECX[2] = in_ECX[2] + 1;
    return;
  }
  in_ECX[1] = param_1;
  *(int *)(param_2 + 4) = param_1;
  in_ECX[2] = in_ECX[2] + 1;
  return;
}

