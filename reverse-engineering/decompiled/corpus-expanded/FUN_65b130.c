/* Ghidra pseudocode, not original source.
 * ev_36c567c8b03fa9be6305a90618e5976b2395159d59c428aaf9f1abc99d465ca0
 * Entry: 0x65b130; label: FUN_0065b130
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0065b130(undefined4 param_1,int param_2)

{
  int iVar1;
  char *pcVar2;
  char local_24 [32];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_24;
  iVar1 = FUN_00543c30(*(undefined4 *)(param_2 + 0xc),local_24,0x20);
  if (iVar1 == 0) {
    pcVar2 = "Load Error";
  }
  else {
    pcVar2 = local_24;
  }
  FUN_00628d80(param_1,pcVar2,iVar1 != 0);
  __security_check_cookie(local_4 ^ (uint)local_24);
  return;
}

