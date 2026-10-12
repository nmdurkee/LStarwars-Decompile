/* Ghidra pseudocode, not original source.
 * ev_a103ceaacd7b90633bbc7eb873f3b3a614efe51f7b7d408a5131b98d70731c28
 * Entry: 0x440640; label: FUN_00440640
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00440640(void)

{
  int iVar1;
  int in_ECX;
  int in_EDX;
  
  iVar1 = 0;
  if ((in_ECX != 0) && (*(char *)(in_ECX + 0x10) != '\0')) {
    iVar1 = *(int *)(in_EDX + 0x28) + (uint)**(byte **)(in_ECX + 0x14) * 0x3c;
  }
  return iVar1;
}

