/* Ghidra pseudocode, not original source.
 * ev_ba1f842bfa0104f1b5ed7b121d230225c91ad84bbbac79703c0a3e54823fb4da
 * Entry: 0x612f70; label: FUN_00612f70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00612f70(int param_1,int param_2)

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

