/* Ghidra analysis pseudocode, not original source.
 * ev_a56cd9785cea8d5ba50d25e7433193a9772fbb2aad70e3222a3c6b4dc2863d32
 * Entry: 0x6dffc0; label: FUN_006dffc0
 */

void FUN_006dffc0(void)

{
  char *pcVar1;
  char *pcVar2;
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x14) = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x10) = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x18) = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x1c) = 0xc;
  pcVar1 = (char *)(in_ECX + 0x1f);
  do {
    pcVar2 = pcVar1;
    pcVar1 = pcVar2 + 1;
  } while (pcVar2[1] != '\0');
  builtin_strncpy(pcVar2 + 1,"Arial",6);
  *(undefined4 *)(in_ECX + 0xa0) = 0xff;
  *(undefined4 *)(in_ECX + 0xa4) = 0xff4c5844;
  *(undefined4 *)(in_ECX + 0xa8) = 0xff889180;
  *(undefined4 *)(in_ECX + 0xac) = 0xff2d3128;
  *(undefined4 *)(in_ECX + 0xb0) = 0xff3e4637;
  return;
}

