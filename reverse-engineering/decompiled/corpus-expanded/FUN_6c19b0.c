/* Ghidra pseudocode, not original source.
 * ev_139f76d7dade80e5283f2bbc23e2b9031909e5f7cb36236e0c190b06f1e16beb
 * Entry: 0x6c19b0; label: FUN_006c19b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006c19b0(int param_1,int param_2)

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

