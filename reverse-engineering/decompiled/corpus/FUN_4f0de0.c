/* Ghidra analysis pseudocode, not original source.
 * ev_45a150495450541a978e32c6b8aebbcc21ab633f871105898ebe02d8fbcf8855
 * Entry: 0x4f0de0; label: FUN_004f0de0
 */

int FUN_004f0de0(void)

{
  int iVar1;
  int in_ECX;
  byte *in_EDX;
  
  iVar1 = 0x12345678;
  for (; in_ECX != 0; in_ECX = in_ECX + -1) {
    iVar1 = iVar1 + (uint)*in_EDX;
    in_EDX = in_EDX + 1;
  }
  return iVar1;
}

