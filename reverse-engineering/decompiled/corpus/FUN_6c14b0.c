/* Ghidra analysis pseudocode, not original source.
 * ev_c9fa25cc79717ad47e0beb6e0964d9456c9021d00a3c9a64cb36b68ef15e0051
 * Entry: 0x6c14b0; label: FUN_006c14b0
 */

void FUN_006c14b0(int *param_1)

{
  int *in_ECX;
  
  if (*param_1 == 0) {
    in_ECX[1] = param_1[1];
  }
  else {
    *(int *)(*param_1 + 4) = param_1[1];
  }
  if ((int *)param_1[1] == (int *)0x0) {
    *in_ECX = *param_1;
  }
  else {
    *(int *)param_1[1] = *param_1;
  }
  *param_1 = 0;
  param_1[1] = 0;
  in_ECX[2] = in_ECX[2] + -1;
  return;
}

