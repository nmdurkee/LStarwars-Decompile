/* Ghidra pseudocode, not original source.
 * ev_bef7beff20bbab7c70650c6f9f545113d8e67786c96c5ee03f6ff15c7c5049ec
 * Entry: 0x7486e0; label: FUN_007486e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_007486e0(undefined4 param_1)

{
  char cVar1;
  char *pcVar2;
  char local_44 [64];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_44;
  _sprintf(local_44,"%d",param_1);
  pcVar2 = local_44;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  FUN_00748530(local_44,(int)pcVar2 - (int)(local_44 + 1));
  __security_check_cookie(local_4 ^ (uint)local_44);
  return;
}

