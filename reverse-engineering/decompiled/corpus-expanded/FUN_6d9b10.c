/* Ghidra pseudocode, not original source.
 * ev_901c6aaecd0b47868ef1d3f758584dfae83b8347f4e0d529523c41e91b06b177
 * Entry: 0x6d9b10; label: FUN_006d9b10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006d9b10(void)

{
  undefined4 uVar1;
  undefined4 in_ECX;
  char local_404 [1024];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_404;
  uVar1 = FUN_006dd420(PTR_s_TTales_00827618,PTR_s_GameTitle_0082761c);
  _sprintf(local_404,"%s\\%s\\%s\\",uVar1);
  FUN_006d9a00(in_ECX,0x40,local_404);
  __security_check_cookie(local_4 ^ (uint)local_404);
  return;
}

