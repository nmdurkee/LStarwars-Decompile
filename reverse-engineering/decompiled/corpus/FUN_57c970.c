/* Ghidra analysis pseudocode, not original source.
 * ev_df641eda8072cee71ca3b2626b4685e3428f565924a572e6fdc3ba5eae4c5d68
 * Entry: 0x57c970; label: FUN_0057c970
 */

undefined4 FUN_0057c970(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  if (((param_1 != (int *)0x0) && (param_2 != 0)) && (iVar2 = 0, 0 < param_1[1])) {
    do {
      iVar1 = FUN_004f8b10(*(int *)(*param_1 + iVar2 * 4) + 8,param_2);
      if (iVar1 == 0) {
        return *(undefined4 *)(*param_1 + iVar2 * 4);
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < param_1[1]);
  }
  return 0;
}

