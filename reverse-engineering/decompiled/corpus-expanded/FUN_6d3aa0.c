/* Ghidra pseudocode, not original source.
 * ev_c1426acf87a342a1866e519dab13ac5b40d9f4eac6e37fcdd4b99f9d53dd1e8b
 * Entry: 0x6d3aa0; label: FUN_006d3aa0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006d3aa0(void)

{
  undefined4 uVar1;
  void *in_ECX;
  char local_404 [1024];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_404;
  uVar1 = FUN_006dd420(PTR_s_TTales_00827618,PTR_s_GameTitle_0082761c);
  _sprintf(local_404,"%s\\%s\\%s\\",uVar1);
  _memset(in_ECX,0,0x2700);
  FUN_006d3990(in_ECX,local_404);
  __security_check_cookie(local_4 ^ (uint)local_404);
  return;
}

