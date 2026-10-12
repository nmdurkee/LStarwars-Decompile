/* Ghidra pseudocode, not original source.
 * ev_36c567c8b03fa9be6305a90618e5976b2395159d59c428aaf9f1abc99d465ca0
 * Entry: 0x65b070; label: FUN_0065b070
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0065b070(undefined4 param_1)

{
  undefined4 uVar1;
  char local_24 [32];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_24;
  uVar1 = FUN_00543990();
  _sprintf(local_24,"Slots Used = %02d",uVar1);
  FUN_00628d80(param_1,local_24,1);
  __security_check_cookie(local_4 ^ (uint)local_24);
  return;
}

