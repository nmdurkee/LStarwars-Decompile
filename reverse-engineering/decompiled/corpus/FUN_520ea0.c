/* Ghidra analysis pseudocode, not original source.
 * ev_7e6f21d847db13540c188bfca3b16bfe9d42e9ab138b0a2487dfabbe836b8541
 * Entry: 0x520ea0; label: FUN_00520ea0
 */

void FUN_00520ea0(void)

{
  void *unaff_ESI;
  
  if (unaff_ESI != (void *)0x0) {
    FUN_004f1410(DAT_009238e4 + 0x383c0);
    _memset(unaff_ESI,0,0x48);
    FUN_004f1310(DAT_009238e4 + 0x383b8);
  }
  return;
}

