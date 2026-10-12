/* Ghidra analysis pseudocode, not original source.
 * ev_a56cd9785cea8d5ba50d25e7433193a9772fbb2aad70e3222a3c6b4dc2863d32
 * Entry: 0x6dfa20; label: FUN_006dfa20
 */

void FUN_006dfa20(void)

{
  int iVar1;
  
  iVar1 = 0;
  if (DAT_02976668 != 0) {
    do {
      FUN_006e54e0(iVar1,5,2);
      FUN_006e54e0(iVar1,6,2);
      FUN_006e54e0(iVar1,7,2);
      FUN_006e54e0(iVar1,9,0);
      iVar1 = iVar1 + 1;
    } while (iVar1 != DAT_02976668);
  }
  return;
}

