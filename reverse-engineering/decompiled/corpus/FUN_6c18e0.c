/* Ghidra analysis pseudocode, not original source.
 * ev_51d776bbf7e198208a4486308eec4a97f7acd5ccc3951e1c43c2ae0a52a9ca8f
 * Entry: 0x6c18e0; label: FUN_006c18e0
 */

void FUN_006c18e0(int *param_1,int *param_2)

{
  int *in_ECX;
  
  if (param_2 == (int *)0x0) {
    *param_1 = 0;
    param_1[1] = in_ECX[1];
    if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
      *(undefined4 *)in_ECX[1] = param_1;
    }
    in_ECX[1] = (int)param_1;
    if (*in_ECX == 0) {
      *in_ECX = (int)param_1;
    }
    in_ECX[2] = in_ECX[2] + 1;
    return;
  }
  param_1[1] = (int)param_2;
  *param_1 = *param_2;
  if (*param_2 != 0) {
    *(int **)(*param_2 + 4) = param_1;
    *param_2 = (int)param_1;
    in_ECX[2] = in_ECX[2] + 1;
    return;
  }
  in_ECX[1] = (int)param_1;
  *param_2 = (int)param_1;
  in_ECX[2] = in_ECX[2] + 1;
  return;
}

