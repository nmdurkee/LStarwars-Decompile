/* Ghidra pseudocode, not original source.
 * ev_dd2b431ee7d7df08292740893bb7b99558b7953fea1da99d97b81497b86ab5e2
 * Entry: 0x5e5550; label: FUN_005e5550
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005e5550(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined1 local_28 [36];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_28;
  if (param_1 < 1) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)(DAT_0097157c + -4 + param_1 * 4);
  }
  FUN_004f1f10(param_2,"c:\\temp\\stream\\textures\\");
  FUN_005e54b0(iVar1 + 8,local_28);
  FUN_004f1e80(param_2,local_28);
  FUN_004f1e80(param_2,&DAT_00755ae4);
  __security_check_cookie(local_4 ^ (uint)local_28);
  return;
}

