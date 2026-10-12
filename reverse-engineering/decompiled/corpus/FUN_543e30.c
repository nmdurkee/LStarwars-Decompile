/* Ghidra analysis pseudocode, not original source.
 * ev_177857cb78ddb8ad13dc6718881af1dfaef05e8a3811f551bff9ab7ba98e27a8
 * Entry: 0x543e30; label: FUN_00543e30
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00543e30(int param_1)

{
  _sprintf((char *)&DAT_009246f8,"SaveGame%d.%s_SavedGame",param_1,PTR_s_GameTitle_0082761c);
  FUN_006e8de2(&DAT_009246f8);
  _DAT_02989558 = param_1;
  if (DAT_00802014 == param_1) {
    DAT_00802014 = -1;
  }
  return;
}

