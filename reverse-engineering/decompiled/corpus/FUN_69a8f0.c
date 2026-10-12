/* Ghidra analysis pseudocode, not original source.
 * ev_f1a36c6b3ad286842b1ed86bd3c2163f44c7dc63d65997010e74903b0be7db2b
 * Entry: 0x69a8f0; label: FUN_0069a8f0
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

