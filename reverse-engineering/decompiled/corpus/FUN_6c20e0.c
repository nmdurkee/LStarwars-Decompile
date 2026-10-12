/* Ghidra analysis pseudocode, not original source.
 * ev_51d776bbf7e198208a4486308eec4a97f7acd5ccc3951e1c43c2ae0a52a9ca8f
 * Entry: 0x6c20e0; label: FUN_006c20e0
 */

void FUN_006c20e0(undefined4 *param_1)

{
  int *piVar1;
  int *in_ECX;
  
  piVar1 = (int *)*in_ECX;
  if (piVar1 != (int *)0x0) {
    do {
      if ((int)param_1[0x1d] < piVar1[0x1d]) {
        FUN_006c1570(param_1,piVar1);
        return;
      }
      piVar1 = (int *)*piVar1;
    } while (piVar1 != (int *)0x0);
  }
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

