/* Ghidra analysis pseudocode, not original source.
 * ev_df641eda8072cee71ca3b2626b4685e3428f565924a572e6fdc3ba5eae4c5d68
 * Entry: 0x57cec0; label: FUN_0057cec0
 */

void FUN_0057cec0(int *param_1)

{
  int iVar1;
  int iVar2;
  
  if ((param_1 != (int *)0x0) && (iVar2 = 0, 0 < param_1[1])) {
    do {
      iVar1 = *(int *)(*(int *)(*param_1 + iVar2 * 4) + 4);
      if (iVar1 != 0) {
        FUN_00505e10(iVar1);
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < param_1[1]);
  }
  return;
}

