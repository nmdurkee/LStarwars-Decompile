/* Ghidra analysis pseudocode, not original source.
 * ev_2c014b146e9258db07d80d50b3912bad4b2773c74b3e67189abd65c219d7972f
 * Entry: 0x5ab050; label: FUN_005ab050
 */

void FUN_005ab050(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = FUN_005aac00(param_1,param_2,param_4);
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 0x28) = param_3;
  }
  return;
}

