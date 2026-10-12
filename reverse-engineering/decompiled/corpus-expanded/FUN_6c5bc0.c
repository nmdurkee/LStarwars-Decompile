/* Ghidra pseudocode, not original source.
 * ev_647b85ee0a7e8e41d889ce710347a98583a3d140d8a364c007ecae69f59044b8
 * Entry: 0x6c5bc0; label: FUN_006c5bc0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006c5bc0(int *param_1)

{
  int in_ECX;
  
  if (*param_1 == 0) {
    *(int *)(in_ECX + 0x10) = param_1[1];
  }
  else {
    *(int *)(*param_1 + 4) = param_1[1];
  }
  if ((int *)param_1[1] == (int *)0x0) {
    *(int *)(in_ECX + 0xc) = *param_1;
  }
  else {
    *(int *)param_1[1] = *param_1;
  }
  *param_1 = 0;
  param_1[1] = 0;
  *(int *)(in_ECX + 0x14) = *(int *)(in_ECX + 0x14) + -1;
  param_1[0x1d] = -2;
  FUN_006c20e0();
  return;
}

