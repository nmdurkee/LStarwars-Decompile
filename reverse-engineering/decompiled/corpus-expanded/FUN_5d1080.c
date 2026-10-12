/* Ghidra pseudocode, not original source.
 * ev_80f10280a68e27d1163faa95206013e039612dceeee316e4395f60ba03bc283c
 * Entry: 0x5d1080; label: FUN_005d1080
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

