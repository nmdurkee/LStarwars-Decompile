/* Ghidra analysis pseudocode, not original source.
 * ev_142c6a8c6383f125e012f2efba2eadfa5dbe8b6e60e30e9e06bfa3e419522019
 * Entry: 0x619130; label: FUN_00619130
 */

void FUN_00619130(int *param_1,int *param_2)

{
  int iVar1;
  
  if ((int *)*param_1 == param_2) {
    *param_1 = *param_2;
  }
  if ((int *)param_1[1] == param_2) {
    param_1[1] = param_2[1];
  }
  if ((int *)param_1[2] == param_2) {
    iVar1 = *param_2;
    if (iVar1 == 0) {
      iVar1 = param_2[1];
    }
    param_1[2] = iVar1;
  }
  param_1[3] = *param_1;
  param_1[4] = 0;
  if (*param_2 != 0) {
    *(int *)(*param_2 + 4) = param_2[1];
  }
  if ((int *)param_2[1] != (int *)0x0) {
    *(int *)param_2[1] = *param_2;
  }
  param_2[1] = 0;
  *param_2 = 0;
  return;
}

