/* Ghidra analysis pseudocode, not original source.
 * ev_6bac4da6f4ce0ce73312601f89fbd0303a514d0896ac0cebe3875471fcd2a12c
 * Entry: 0x6db990; label: FUN_006db990
 */

void FUN_006db990(void)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  char *pcVar4;
  int in_ECX;
  char local_108 [12];
  char local_fc [248];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_108;
  iVar3 = FUN_004fc860(in_ECX + 4);
  if (iVar3 == 0) {
    FUN_004f6900(local_108);
    pcVar2 = &stack0xfffffef7;
    do {
      pcVar4 = pcVar2;
      pcVar2 = pcVar4 + 1;
    } while (pcVar4[1] != '\0');
    builtin_strncpy(pcVar4 + 1,"pcconfig.txt",0xd);
    iVar3 = FUN_004fc860(local_108);
    if (iVar3 == 0) {
      FUN_006db0c0();
      FUN_006db1c0();
      __security_check_cookie(local_4 ^ (uint)local_108);
      return;
    }
  }
  FUN_004f10e0(iVar3,&PTR_s_FileVersion_00825f20);
  FUN_004fc5b0(iVar3);
  cVar1 = **(char **)(iVar3 + 0x50c);
  while (cVar1 != '\0') {
    FUN_004f7fb0(iVar3);
    FUN_004fa020(iVar3);
    FUN_004fc5b0(iVar3);
    cVar1 = **(char **)(iVar3 + 0x50c);
  }
  FUN_004fa300(iVar3);
  if (*(char *)(in_ECX + 0x458) != *(char *)(in_ECX + 0x457)) {
    *(char *)(in_ECX + 0x457) = *(char *)(in_ECX + 0x458);
  }
  FUN_006db7a0();
  __security_check_cookie(local_4 ^ (uint)local_108);
  return;
}

