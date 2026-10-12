/* Ghidra pseudocode, not original source.
 * ev_1c43a4838a2574475d6c9682bec7b0db8a67988369837137b0115a570ceb3a0a
 * Entry: 0x4f9f60; label: FUN_004f9f60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004f9f60(int param_1)

{
  char *pcVar1;
  char cVar2;
  char *pcVar3;
  undefined1 local_58 [8];
  char *local_50;
  undefined4 local_4c;
  undefined4 local_48;
  char local_44 [64];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_58;
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
  if (local_44[0] != '\0') {
    local_50 = local_44;
    local_4c = 0;
    local_48 = 0;
    FUN_004f8420();
    FUN_004f8880(local_58);
    __security_check_cookie(local_4 ^ (uint)local_58);
    return;
  }
  __security_check_cookie(local_4 ^ (uint)local_58);
  return;
}

