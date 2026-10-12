/* Ghidra pseudocode, not original source.
 * ev_659eea1dc00a859f9d32b97d98369d0a367714cfb07a93b4448bfffc51247c8f
 * Entry: 0x69a940; label: FUN_0069a940
 * Boundary hypotheses: reports/native-supplemental-entry-inspection.json.
 */

uint FUN_0069a940(void)

{
  uint uVar1;
  int iVar2;
  int in_ECX;
  
  if (*(char *)(in_ECX + 0x40) == '\0') {
    uVar1 = FUN_0069a230();
    return uVar1;
  }
  if (*(int *)(in_ECX + 0x318) != 0) {
    iVar2 = FUN_0069c7a0(in_ECX + 0x48,0,0);
    return (-1 < iVar2) - 1 & 0x80004005;
  }
  return 0x80004005;
}

