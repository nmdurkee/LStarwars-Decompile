/* Ghidra analysis pseudocode, not original source.
 * ev_82613852739bd66c0ef0ae4a5b7138b98fa59042d44f2c612a65801f1499c980
 * Entry: 0x6279b0; label: FUN_006279b0
 */

undefined4 FUN_006279b0(int param_1,int param_2)

{
  int iVar1;
  
  if (*(int *)(param_2 + 0x40) != 0) {
    return 0;
  }
  iVar1 = *(int *)(param_1 + 0x3c);
  while (iVar1 != 0) {
    param_1 = *(int *)(param_1 + 0x3c);
    iVar1 = *(int *)(param_1 + 0x3c);
  }
  *(int *)(param_2 + 0x40) = param_1;
  *(int *)(param_1 + 0x3c) = param_2;
  FUN_006271a0(param_2);
  return 1;
}

