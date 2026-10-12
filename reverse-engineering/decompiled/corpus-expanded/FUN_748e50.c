/* Ghidra pseudocode, not original source.
 * ev_80517fb4f192ecd2851e0fd4e2a7dbbf5e68bec5ed1b7e7e17e8e9bcd800f2e9
 * Entry: 0x748e50; label: FUN_00748e50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00748e50(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int in_ECX;
  char local_104 [256];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_104;
  _sprintf(local_104,"%s\\%s%s",in_ECX + 4,param_2,param_1);
  iVar1 = FUN_004fa5f0(local_104,1);
  if (iVar1 != 0) {
    FUN_004f03d0(iVar1,param_3,param_4);
    FUN_004f99e0(iVar1);
  }
  __security_check_cookie(local_4 ^ (uint)local_104);
  return;
}

