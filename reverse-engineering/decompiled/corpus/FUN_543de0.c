/* Ghidra analysis pseudocode, not original source.
 * ev_177857cb78ddb8ad13dc6718881af1dfaef05e8a3811f551bff9ab7ba98e27a8
 * Entry: 0x543de0; label: FUN_00543de0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00543de0(void)

{
  DWORD DVar1;
  
  if (DAT_00924828 != 0) {
    DVar1 = GetTickCount();
    if (1000 < (int)(DVar1 - _DAT_009246f0)) {
      DAT_00924828 = 0;
      FUN_00543880();
      DAT_00924800 = 1;
    }
  }
  return;
}

