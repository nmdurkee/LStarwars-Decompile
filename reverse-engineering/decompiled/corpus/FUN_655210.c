/* Ghidra analysis pseudocode, not original source.
 * ev_537f31f6d7a7ebc324951952e862ea8d16fa2be695db959927eb9326274a35d3
 * Entry: 0x655210; label: FUN_00655210
 */

void FUN_00655210(int param_1,int *param_2)

{
  int iVar1;
  
  if (*param_2 != 0) {
    while (iVar1 = *param_2, iVar1 != param_1) {
      param_2 = (int *)(iVar1 + 0x10);
      if (*(int *)(iVar1 + 0x10) == 0) {
        *(undefined4 *)(param_1 + 0x10) = 0;
        return;
      }
    }
    *param_2 = *(int *)(param_1 + 0x10);
  }
  *(undefined4 *)(param_1 + 0x10) = 0;
  return;
}

