/* Ghidra analysis pseudocode, not original source.
 * ev_82613852739bd66c0ef0ae4a5b7138b98fa59042d44f2c612a65801f1499c980
 * Entry: 0x627bc0; label: FUN_00627bc0
 */

void FUN_00627bc0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  int iVar1;
  
  iVar1 = FUN_00627a80(param_1,param_2,param_3,param_4,param_5,param_6);
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 8) = 3;
    *(code **)(iVar1 + 0x3c) = FUN_00624590;
    *(code **)(iVar1 + 0x40) = FUN_00619a40;
  }
  return;
}

