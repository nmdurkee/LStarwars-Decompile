/* Ghidra analysis pseudocode, not original source.
 * ev_1cd547681849579fe9db2ab86a66300dc334807e6004e2ad8358d218d877a353
 * Entry: 0x6d6870; label: FUN_006d6870
 */

void FUN_006d6870(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined1 local_a0 [156];
  uint local_4;
  
  uVar1 = DAT_02975144;
  local_4 = DAT_00829570 ^ (uint)local_a0;
  FUN_006d4070(param_1,local_a0,1,param_2,param_3);
  FUN_006d38f0(uVar1,0x40,local_a0);
  __security_check_cookie(local_4 ^ (uint)local_a0);
  return;
}

