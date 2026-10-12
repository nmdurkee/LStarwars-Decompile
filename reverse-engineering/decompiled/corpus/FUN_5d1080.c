/* Ghidra analysis pseudocode, not original source.
 * ev_7d8e2999f2f8a3752dbaff0aac6d4e5497e59d04af9d3c1072d39c32106cee2b
 * Entry: 0x5d1080; label: FUN_005d1080
 */

void FUN_005d1080(undefined4 param_1,char *param_2,va_list param_3)

{
  char local_404 [1024];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_404;
  _vsprintf(local_404,param_2,param_3);
  FUN_005d0d60(param_1,local_404);
  __security_check_cookie(local_4 ^ (uint)local_404);
  return;
}

