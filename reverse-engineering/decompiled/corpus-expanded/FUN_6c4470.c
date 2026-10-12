/* Ghidra pseudocode, not original source.
 * ev_e52d6ac25f00059e86c3f4cc44b478706554e879f89108396fea801d3c4db5da
 * Entry: 0x6c4470; label: FUN_006c4470
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006c4470(void)

{
  int *piVar1;
  int in_ECX;
  
  for (piVar1 = *(int **)(in_ECX + 0x93c); piVar1 != (int *)0x0; piVar1 = (int *)piVar1[1]) {
    (**(code **)(*piVar1 + 0x1c))();
  }
  *(undefined4 *)(in_ECX + 0x2a8) = 0;
  _memset((void *)(in_ECX + 0x2ac),0,0x690);
  return;
}

