/* Ghidra analysis pseudocode, not original source.
 * ev_89b7b842136f36149785ae3176f422ef77993aed8671c7148cbe0781c54fcb17
 * Entry: 0x476250; label: FUN_00476250
 */

void FUN_00476250(int param_1,int param_2)

{
  if ((DAT_0093b324 != 0) && ((param_1 == 0 || (param_1 == 1)))) {
    if ((param_2 == 0) || (param_2 == 1)) {
      FUN_00475fb0();
      return;
    }
    if (param_2 == -1) {
      FUN_00476010(param_1);
    }
  }
  return;
}

