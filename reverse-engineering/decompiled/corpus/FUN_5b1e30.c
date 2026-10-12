/* Ghidra analysis pseudocode, not original source.
 * ev_9de9052a7a74906b1fb5570bf9c5ea7426c8a6fcab6dcccf13cbc82c1ebad988
 * Entry: 0x5b1e30; label: FUN_005b1e30
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

