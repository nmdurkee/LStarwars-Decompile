/* Ghidra pseudocode, not original source.
 * ev_120f2dbe0ae7ec1f4fb84f9bb605c17bea6e5ad9085d38dd392f35fbf38da278
 * Entry: 0x5f3580; label: FUN_005f3580
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

