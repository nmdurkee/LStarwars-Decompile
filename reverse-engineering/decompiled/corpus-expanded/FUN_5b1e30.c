/* Ghidra pseudocode, not original source.
 * ev_f229a78d5de0bf17b480d7e9a60f462b055d08f1d682cbbe42c93314af3c723e
 * Entry: 0x5b1e30; label: FUN_005b1e30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005b1e30(int param_1)

{
  int iVar1;
  char local_104 [256];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_104;
  _sprintf(local_104,"%s.sfx",param_1 + 0x80);
  iVar1 = thunk_FUN_004fa610(local_104);
  if (iVar1 != 0) {
    FUN_005b1810(local_104,param_1);
  }
  __security_check_cookie(local_4 ^ (uint)local_104);
  return;
}

