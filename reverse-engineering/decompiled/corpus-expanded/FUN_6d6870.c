/* Ghidra pseudocode, not original source.
 * ev_3b3808edeffc7046af602211c0d6f30bd8b518f734faefbc322523a0a631579d
 * Entry: 0x6d6870; label: FUN_006d6870
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

