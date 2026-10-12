/* Ghidra analysis pseudocode, not original source.
 * ev_374b9498cac1f2764533d2b2425c9906eb7f8dc5d78a775ccd4080d89a8f30aa
 * Entry: 0x6d6170; label: FUN_006d6170
 */

void FUN_006d6170(int param_1)

{
  char cVar1;
  
  cVar1 = *(char *)(DAT_02975144 + 0x67e0);
  *(char *)(DAT_02975144 + 0x67e0) = (char)param_1;
  if (param_1 != cVar1) {
    DAT_029755b0 = 6;
  }
  return;
}

