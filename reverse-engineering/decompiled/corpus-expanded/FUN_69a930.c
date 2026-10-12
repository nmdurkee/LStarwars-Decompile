/* Ghidra pseudocode, not original source.
 * ev_4cbe307265f31e413c5f7cc9b7da0764bbafe6907e0e37f5fb37c4e62049af07
 * Entry: 0x69a930; label: FUN_0069a930
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0069a930(void)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = in_ECX + 0x18;
  if (*(char *)(in_ECX + 0x40) != '\0') {
    iVar1 = in_ECX + 800;
  }
  return iVar1;
}

