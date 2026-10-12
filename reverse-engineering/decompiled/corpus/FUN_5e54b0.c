/* Ghidra analysis pseudocode, not original source.
 * ev_56bf9e76ab0c031fab8380995f005739ca3b697a310321db3c480b01a4d86e23
 * Entry: 0x5e54b0; label: FUN_005e54b0
 */

void FUN_005e54b0(byte *param_1,char *param_2)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  char *pcVar4;
  char local_18 [20];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_18;
  builtin_strncpy(local_18,"0123456789abcdef",0x11);
  iVar3 = 0x10;
  pcVar4 = param_2;
  do {
    bVar1 = *param_1;
    bVar2 = bVar1 >> 4;
    *pcVar4 = local_18[bVar2];
    pcVar4[1] = local_18[(byte)(bVar1 + bVar2 * -0x10)];
    param_1 = param_1 + 1;
    pcVar4 = pcVar4 + 2;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  param_2[0x20] = '\0';
  __security_check_cookie(local_4 ^ (uint)local_18);
  return;
}

