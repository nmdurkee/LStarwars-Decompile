/* Ghidra analysis pseudocode, not original source.
 * ev_c6c5de14d13fb7351cb00798d8d33f42525c6eb06c0958f12186e2f5ad93dde9
 * Entry: 0x4f9e70; label: FUN_004f9e70
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

