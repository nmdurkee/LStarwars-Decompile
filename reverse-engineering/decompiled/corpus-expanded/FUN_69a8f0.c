/* Ghidra pseudocode, not original source.
 * ev_4cbe307265f31e413c5f7cc9b7da0764bbafe6907e0e37f5fb37c4e62049af07
 * Entry: 0x69a8f0; label: FUN_0069a8f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0069a8f0(void)

{
  int iVar1;
  int in_ECX;
  
  if (*(char *)(in_ECX + 0x40) == '\0') {
    iVar1 = FUN_0069a210();
    return iVar1;
  }
  if (*(int *)(in_ECX + 0x318) != 0) {
    iVar1 = FUN_0069c6b0(in_ECX + 0x48,0xffffffff);
    return iVar1 * (uint)*(ushort *)(in_ECX + 0x32c);
  }
  return 0;
}

