/* Ghidra analysis pseudocode, not original source.
 * ev_6bac4da6f4ce0ce73312601f89fbd0303a514d0896ac0cebe3875471fcd2a12c
 * Entry: 0x6db940; label: FUN_006db940
 */

void FUN_006db940(void)

{
  char *pcVar1;
  char *pcVar2;
  int in_ECX;
  
  FUN_006dd8c0(in_ECX + 4);
  pcVar1 = (char *)(in_ECX + 3);
  do {
    pcVar2 = pcVar1;
    pcVar1 = pcVar2 + 1;
  } while (pcVar2[1] != '\0');
  builtin_strncpy(pcVar2 + 1,"pcconfig.txt",0xd);
  FUN_006db0c0();
  return;
}

