/* Ghidra analysis pseudocode, not original source.
 * ev_537f31f6d7a7ebc324951952e862ea8d16fa2be695db959927eb9326274a35d3
 * Entry: 0x654ea0; label: FUN_00654ea0
 */

void FUN_00654ea0(int param_1,int *param_2)

{
  int iVar1;
  
  if (*param_2 == param_1) {
    iVar1 = *(int *)(param_1 + 0x5c);
    *param_2 = iVar1;
    if (iVar1 != 0) {
      *(undefined4 *)(iVar1 + 0x58) = 0;
      *(undefined4 *)(param_1 + 0x58) = 0;
      *(undefined4 *)(param_1 + 0x5c) = 0;
      return;
    }
  }
  else if (*(int *)(param_1 + 0x58) != 0) {
    *(undefined4 *)(*(int *)(param_1 + 0x58) + 0x5c) = *(undefined4 *)(param_1 + 0x5c);
    if (*(int *)(param_1 + 0x5c) != 0) {
      *(undefined4 *)(*(int *)(param_1 + 0x5c) + 0x58) = *(undefined4 *)(param_1 + 0x58);
    }
  }
  *(undefined4 *)(param_1 + 0x58) = 0;
  *(undefined4 *)(param_1 + 0x5c) = 0;
  return;
}

