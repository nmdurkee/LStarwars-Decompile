/* Ghidra analysis pseudocode, not original source.
 * ev_074dd20869da91b1b05b19bd1efa0509a9d09e9660d7c7c0c7ca47d053bd121c
 * Entry: 0x4cf0f0; label: FUN_004cf0f0
 */

void FUN_004cf0f0(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  if (((param_3 != 0) && (*(int *)(param_3 + 0x4680) != 0)) &&
     (iVar2 = 0, 0 < *(int *)(param_3 + 0x4684))) {
    iVar1 = 0;
    do {
      FUN_00559ee0(param_1,param_2,0,*(int *)(param_3 + 0x4680) + iVar1);
      iVar2 = iVar2 + 1;
      iVar1 = iVar1 + 0xfc;
    } while (iVar2 < *(int *)(param_3 + 0x4684));
  }
  return;
}

