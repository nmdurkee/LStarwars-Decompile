/* Ghidra pseudocode, not original source.
 * ev_d9eb3013c9fda622502628697ce0d7be845892a91a12bfef10a3ae0a3a8d7789
 * Entry: 0x6db940; label: FUN_006db940
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

