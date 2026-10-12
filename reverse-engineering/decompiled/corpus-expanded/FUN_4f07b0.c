/* Ghidra pseudocode, not original source.
 * ev_2eacd74f46b42f047692015e667debd6c21dbe0f18f3288a1bcbfaeff2ef0d47
 * Entry: 0x4f07b0; label: FUN_004f07b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004f07b0(int param_1,char *param_2)

{
  char cVar1;
  char *pcVar2;
  char local_404 [1024];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_404;
  _vsprintf(local_404,param_2,&stack0x0000000c);
  pcVar2 = local_404;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  if (0xfff < param_1) {
    FUN_006dee60(param_1 + -0x1000,local_404,(int)pcVar2 - (int)(local_404 + 1),0);
    __security_check_cookie(local_4 ^ (uint)local_404);
    return;
  }
  if (0x3ff < param_1) {
    FUN_004f0380(param_1,local_404);
    __security_check_cookie(local_4 ^ (uint)local_404);
    return;
  }
  FUN_004ff3f0(param_1 + -1,local_404,(int)pcVar2 - (int)(local_404 + 1));
  __security_check_cookie(local_4 ^ (uint)local_404);
  return;
}

