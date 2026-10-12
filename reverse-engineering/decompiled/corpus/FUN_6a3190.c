/* Ghidra analysis pseudocode, not original source.
 * ev_84e5cb8303fa38d748e4458d34c9d4265893eb5844f058a0a1436ec0ce38dbe0
 * Entry: 0x6a3190; label: FUN_006a3190
 */

undefined4 FUN_006a3190(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(*(int *)(param_1 + 0x68) + 4 + param_2 * 4);
  if (iVar1 + -1 < 0) {
    return 0;
  }
  uVar2 = FUN_006b19c0(iVar1 - *(int *)(*(int *)(*(int *)(param_1 + 4) + 0x1c) + 0xe48));
  return uVar2;
}

