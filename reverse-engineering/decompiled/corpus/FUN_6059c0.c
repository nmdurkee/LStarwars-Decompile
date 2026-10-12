/* Ghidra analysis pseudocode, not original source.
 * ev_8be49e78861dfe08cca82ea9c09c813f64ee3632778122cedbbea2ab2ea39171
 * Entry: 0x6059c0; label: FUN_006059c0
 */

void FUN_006059c0(void)

{
  int unaff_ESI;
  int unaff_EDI;
  
  if (unaff_EDI != 0) {
    if (((&DAT_0097f9b8)[unaff_ESI * 2] != *(int *)(unaff_EDI + 0x20)) ||
       ((&DAT_0097f9bc)[unaff_ESI * 2] != *(int *)(unaff_EDI + 0x24))) {
      FUN_005fa540();
    }
    FUN_006e5630();
    return;
  }
  FUN_006e5630();
  return;
}

