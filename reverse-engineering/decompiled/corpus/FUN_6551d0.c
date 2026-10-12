/* Ghidra analysis pseudocode, not original source.
 * ev_537f31f6d7a7ebc324951952e862ea8d16fa2be695db959927eb9326274a35d3
 * Entry: 0x6551d0; label: FUN_006551d0
 */

void FUN_006551d0(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *param_2;
  while ((iVar1 != 0 && (iVar2 = *param_2, *(float *)(iVar2 + 4) < *(float *)(param_1 + 4)))) {
    iVar1 = *(int *)(iVar2 + 0x10);
    param_2 = (int *)(iVar2 + 0x10);
  }
  *(int *)(param_1 + 0x10) = *param_2;
  *param_2 = param_1;
  return;
}

