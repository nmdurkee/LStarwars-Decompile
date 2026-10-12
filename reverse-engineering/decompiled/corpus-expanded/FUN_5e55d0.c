/* Ghidra pseudocode, not original source.
 * ev_f73a5b0c0434a7d5d731dd250707e0e9320a0ad37df46b92dceb71be55e84b93
 * Entry: 0x5e55d0; label: FUN_005e55d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005e55d0(undefined4 param_1)

{
  undefined1 local_804 [2048];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_804;
  FUN_005e5550(param_1,local_804);
  FUN_005f8d60(local_804,0,0);
  __security_check_cookie(local_4 ^ (uint)local_804);
  return;
}

