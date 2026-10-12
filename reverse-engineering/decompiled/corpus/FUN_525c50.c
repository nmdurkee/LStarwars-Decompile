/* Ghidra analysis pseudocode, not original source.
 * ev_45ac563217612fbe2426642b00b9c96cf69ca1c78f087433beffcbe1e9bd0306
 * Entry: 0x525c50; label: FUN_00525c50
 */

void FUN_00525c50(void)

{
  char *pcVar1;
  int unaff_ESI;
  
  if ((unaff_ESI != 0) && (*(int *)(unaff_ESI + 0xb0) != 0)) {
    pcVar1 = (char *)(*(int *)(unaff_ESI + 0xb0) + 8);
    *pcVar1 = *pcVar1 + -1;
    if (*(char *)(*(int *)(unaff_ESI + 0xb0) + 8) < '\x02') {
      FUN_00525b80();
    }
    *(undefined4 *)(unaff_ESI + 0xb0) = 0;
  }
  return;
}

