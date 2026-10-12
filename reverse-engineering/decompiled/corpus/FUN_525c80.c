/* Ghidra analysis pseudocode, not original source.
 * ev_45ac563217612fbe2426642b00b9c96cf69ca1c78f087433beffcbe1e9bd0306
 * Entry: 0x525c80; label: FUN_00525c80
 */

void FUN_00525c80(void)

{
  int in_EAX;
  int unaff_EDI;
  
  if ((unaff_EDI != 0) && (in_EAX != 0)) {
    if (*(int *)(in_EAX + 0xb0) != 0) {
      if (*(int *)(in_EAX + 0xb0) == unaff_EDI) {
        return;
      }
      FUN_00525c50();
    }
    *(int *)(in_EAX + 0xb0) = unaff_EDI;
    *(char *)(unaff_EDI + 8) = *(char *)(unaff_EDI + 8) + '\x01';
  }
  return;
}

