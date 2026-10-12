/* Ghidra pseudocode, not original source.
 * ev_e52d6ac25f00059e86c3f4cc44b478706554e879f89108396fea801d3c4db5da
 * Entry: 0x6c45b0; label: FUN_006c45b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006c45b0(void)

{
  int *piVar1;
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x10ac) = 0;
  FUN_0061efd0(0);
  if (*(int *)(in_ECX + 0x10a8) != 0) {
    for (piVar1 = *(int **)(in_ECX + 0x93c); piVar1 != (int *)0x0; piVar1 = (int *)piVar1[1]) {
      (**(code **)(*piVar1 + 0x24))();
    }
    *(undefined4 *)(in_ECX + 0x10a8) = 0;
  }
  return;
}

