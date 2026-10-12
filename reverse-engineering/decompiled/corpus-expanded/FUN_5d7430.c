/* Ghidra pseudocode, not original source.
 * ev_2b55f789f1446a783af549e987f50963f158fc34aa4a0a7d53ec4780e4e01d82
 * Entry: 0x5d7430; label: FUN_005d7430
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005d7430(undefined4 param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  char local_104 [256];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_104;
  FUN_005d7230(&DAT_007648b0);
  if ((param_2 == 0) || (param_3 == 0)) {
    _sprintf(local_104,"<IMG ALIGN=\"left\" SRC=\"%s\">",param_1);
  }
  else {
    _sprintf(local_104,"<IMG ALIGN=\"left\" HEIGHT=\"%d\" WIDTH=\"%d\" SRC=\"%s\">",param_3,param_2,
             param_1);
  }
  FUN_005d7230(local_104);
  if (param_4 != 0) {
    FUN_005d7230(param_4);
  }
  FUN_005d7230("<BR CLEAR=\"all\"> <P>&nbsp;<P>");
  if (param_5 != 0) {
    iVar1 = FUN_004f20f0(param_1,param_5);
    if (iVar1 != 0) {
      FUN_004fd850(param_1,param_5);
    }
  }
  __security_check_cookie(local_4 ^ (uint)local_104);
  return;
}

