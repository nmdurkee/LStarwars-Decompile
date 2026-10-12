/* Ghidra analysis pseudocode, not original source.
 * ev_d2450bc109eaeb7c56e41eff2a553a3360ea1f4e9492b44c9e06060604e12c53
 * Entry: 0x5f3510; label: FUN_005f3510
 */

void FUN_005f3510(int param_1,int param_2)

{
  undefined1 local_804 [2048];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_804;
  if (((param_1 != 0) || (param_1 = DAT_009738b8, DAT_009738b8 != 0)) && (param_2 != 0)) {
    FUN_005d0bc0(param_1,param_2,local_804);
    FUN_005eb250(param_1,local_804,DAT_009738c4);
  }
  __security_check_cookie(local_4 ^ (uint)local_804);
  return;
}

