/* Ghidra analysis pseudocode, not original source.
 * ev_f1a36c6b3ad286842b1ed86bd3c2163f44c7dc63d65997010e74903b0be7db2b
 * Entry: 0x69a330; label: FUN_0069a330
 */

void FUN_0069a330(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0076efac;
  if ((HANDLE)in_ECX[2] != (HANDLE)0x0) {
    CloseHandle((HANDLE)in_ECX[2]);
    in_ECX[2] = 0;
  }
  return;
}

