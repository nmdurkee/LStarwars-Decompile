/* Ghidra pseudocode, not original source.
 * ev_e52d6ac25f00059e86c3f4cc44b478706554e879f89108396fea801d3c4db5da
 * Entry: 0x6c58f0; label: FUN_006c58f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006c58f0(int param_1,int param_2)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = *(int **)(in_ECX + 0xc);
  if (piVar1 != (int *)0x0) {
    while (piVar1[2] != param_1) {
      piVar1 = (int *)*piVar1;
      if (piVar1 == (int *)0x0) {
        return;
      }
    }
    piVar1[3] = param_2;
  }
  return;
}

