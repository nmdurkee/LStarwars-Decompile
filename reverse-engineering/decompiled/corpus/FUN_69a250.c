/* Ghidra analysis pseudocode, not original source.
 * ev_f1a36c6b3ad286842b1ed86bd3c2163f44c7dc63d65997010e74903b0be7db2b
 * Entry: 0x69a250; label: FUN_0069a250
 */

undefined4 FUN_0069a250(void)

{
  int in_ECX;
  
  if (*(HANDLE *)(in_ECX + 8) != (HANDLE)0x0) {
    CloseHandle(*(HANDLE *)(in_ECX + 8));
    *(undefined4 *)(in_ECX + 8) = 0;
    return 0;
  }
  return 0x80004005;
}

