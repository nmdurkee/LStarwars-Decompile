/* Ghidra analysis pseudocode, not original source.
 * ev_0d1e553906e4ac29f0c898728bb3c9cf38177ab98ca2cbcdea8e6b852723dd83
 * Entry: 0x59da30; label: FUN_0059da30
 */

void FUN_0059da30(void)

{
  int iVar1;
  int unaff_EDI;
  
  iVar1 = 0;
  if (*(char *)(unaff_EDI + 2) != '\0') {
    do {
      FUN_0059d9d0();
      iVar1 = iVar1 + 1;
    } while (iVar1 < (int)(uint)*(byte *)(unaff_EDI + 2));
  }
  return;
}

