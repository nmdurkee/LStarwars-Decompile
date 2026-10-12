/* Ghidra analysis pseudocode, not original source.
 * ev_f1a36c6b3ad286842b1ed86bd3c2163f44c7dc63d65997010e74903b0be7db2b
 * Entry: 0x69a210; label: FUN_0069a210
 */

int FUN_0069a210(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 8) != 0) {
    return (*(int *)(in_ECX + 0x30) - *(int *)(in_ECX + 0x2c)) * (uint)*(ushort *)(in_ECX + 0x24);
  }
  return 0;
}

