/* Ghidra pseudocode, not original source.
 * ev_139f76d7dade80e5283f2bbc23e2b9031909e5f7cb36236e0c190b06f1e16beb
 * Entry: 0x6c1ba0; label: FUN_006c1ba0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006c1ba0(int param_1,int param_2)

{
  int *in_ECX;
  
  if (param_2 == 0) {
    *(undefined4 *)(param_1 + 0x2c) = 0;
    *(int *)(param_1 + 0x30) = in_ECX[1];
    if (in_ECX[1] != 0) {
      *(int *)(in_ECX[1] + 0x2c) = param_1;
    }
    in_ECX[1] = param_1;
    if (*in_ECX == 0) {
      *in_ECX = param_1;
    }
    in_ECX[2] = in_ECX[2] + 1;
    return;
  }
  *(int *)(param_1 + 0x30) = param_2;
  *(undefined4 *)(param_1 + 0x2c) = *(undefined4 *)(param_2 + 0x2c);
  if (*(int *)(param_2 + 0x2c) != 0) {
    *(int *)(*(int *)(param_2 + 0x2c) + 0x30) = param_1;
    *(int *)(param_2 + 0x2c) = param_1;
    in_ECX[2] = in_ECX[2] + 1;
    return;
  }
  in_ECX[1] = param_1;
  *(int *)(param_2 + 0x2c) = param_1;
  in_ECX[2] = in_ECX[2] + 1;
  return;
}

