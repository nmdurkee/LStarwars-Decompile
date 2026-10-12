/* Ghidra pseudocode, not original source.
 * ev_e52d6ac25f00059e86c3f4cc44b478706554e879f89108396fea801d3c4db5da
 * Entry: 0x6c43e0; label: FUN_006c43e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006c43e0(int param_1)

{
  int in_ECX;
  
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = *(undefined4 *)(in_ECX + 0x940);
  if (*(int *)(in_ECX + 0x940) != 0) {
    *(int *)(*(int *)(in_ECX + 0x940) + 4) = param_1;
  }
  *(int *)(in_ECX + 0x944) = *(int *)(in_ECX + 0x944) + 1;
  *(int *)(in_ECX + 0x940) = param_1;
  if (*(int *)(in_ECX + 0x93c) == 0) {
    *(int *)(in_ECX + 0x93c) = param_1;
  }
  return;
}

