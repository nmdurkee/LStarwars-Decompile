/* Ghidra pseudocode, not original source.
 * ev_1c43a4838a2574475d6c9682bec7b0db8a67988369837137b0115a570ceb3a0a
 * Entry: 0x4f9e70; label: FUN_004f9e70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004f9e70(int param_1)

{
  char *pcVar1;
  char cVar2;
  char *pcVar3;
  char local_44 [64];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_44;
  FUN_004f7fb0(param_1);
  pcVar3 = local_44;
  if (*(char *)(param_1 + 0x578) == '\0') {
    pcVar1 = *(char **)(param_1 + 0x510);
    if ((pcVar1 != (char *)0x0) && (cVar2 = *pcVar1, cVar2 != '\0')) {
      do {
        *pcVar3 = cVar2;
        cVar2 = pcVar3[(int)(pcVar1 + (1 - (int)local_44))];
        pcVar3 = pcVar3 + 1;
      } while (cVar2 != '\0');
    }
    *pcVar3 = '\0';
  }
  else {
    FUN_004f2dc0(pcVar3,*(undefined4 *)(param_1 + 0x510));
  }
  if (local_44[0] == '\0') {
    __security_check_cookie(local_4 ^ (uint)local_44);
    return;
  }
  if (local_44[0] == '$') {
    FUN_004f8cb0(local_44 + 1);
    __security_check_cookie(local_4 ^ (uint)local_44);
    return;
  }
  if ((local_44[0] == '0') && ((local_44[1] == 'x' || (local_44[1] == 'X')))) {
    FUN_004f8cb0(local_44 + 2);
    __security_check_cookie(local_4 ^ (uint)local_44);
    return;
  }
  FUN_004f29a0(local_44);
  __security_check_cookie(local_4 ^ (uint)local_44);
  return;
}

