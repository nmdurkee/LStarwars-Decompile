/* Ghidra analysis pseudocode, not original source.
 * ev_d2450bc109eaeb7c56e41eff2a553a3360ea1f4e9492b44c9e06060604e12c53
 * Entry: 0x5f3580; label: FUN_005f3580
 */

void FUN_005f3580(undefined4 param_1,char *param_2,va_list param_3)

{
  char local_404 [1024];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_404;
  _vsprintf(local_404,param_2,param_3);
  FUN_005f3510(param_1,local_404);
  __security_check_cookie(local_4 ^ (uint)local_404);
  return;
}

