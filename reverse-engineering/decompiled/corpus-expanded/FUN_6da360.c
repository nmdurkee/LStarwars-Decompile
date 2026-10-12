/* Ghidra pseudocode, not original source.
 * ev_65739642fe41f5b8b860334b2741f542947d362cd0074980e50397e4ea9361e6
 * Entry: 0x6da360; label: FUN_006da360
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006da360(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined1 local_a0 [156];
  uint local_4;
  
  uVar1 = DAT_02975144;
  local_4 = DAT_00829570 ^ (uint)local_a0;
  uVar2 = FUN_004f48e0(param_1);
  FUN_006d4070(uVar2,local_a0,0,0,0);
  FUN_006d38f0(uVar1,0x40,local_a0);
  FUN_006d9b10();
  __security_check_cookie(local_4 ^ (uint)local_a0);
  return;
}

