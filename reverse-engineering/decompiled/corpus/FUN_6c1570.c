/* Ghidra analysis pseudocode, not original source.
 * ev_51d776bbf7e198208a4486308eec4a97f7acd5ccc3951e1c43c2ae0a52a9ca8f
 * Entry: 0x6c1570; label: FUN_006c1570
 */

void FUN_006c1570(int *param_1,int param_2)

{
  int *in_ECX;
  
  if (param_2 == 0) {
    *param_1 = *in_ECX;
    param_1[1] = 0;
    if (*in_ECX != 0) {
      *(int **)(*in_ECX + 4) = param_1;
    }
    if (in_ECX[1] == 0) {
      in_ECX[1] = (int)param_1;
    }
    in_ECX[2] = in_ECX[2] + 1;
    *in_ECX = (int)param_1;
    return;
  }
  *param_1 = param_2;
  param_1[1] = *(int *)(param_2 + 4);
  if (*(undefined4 **)(param_2 + 4) != (undefined4 *)0x0) {
    **(undefined4 **)(param_2 + 4) = param_1;
    *(int **)(param_2 + 4) = param_1;
    in_ECX[2] = in_ECX[2] + 1;
    return;
  }
  *in_ECX = (int)param_1;
  *(int **)(param_2 + 4) = param_1;
  in_ECX[2] = in_ECX[2] + 1;
  return;
}

