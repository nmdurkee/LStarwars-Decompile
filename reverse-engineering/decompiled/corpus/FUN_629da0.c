/* Ghidra analysis pseudocode, not original source.
 * ev_93d7dcfdde9a808337523cfea9e371187d945893e914ed56ca2b2926a7aff66e
 * Entry: 0x629da0; label: FUN_00629da0
 */

void FUN_00629da0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = FUN_00629d00(param_1,param_2,param_3,param_4);
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 8) = 8;
  }
  return;
}

