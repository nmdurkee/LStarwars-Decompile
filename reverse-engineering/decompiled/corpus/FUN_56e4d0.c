/* Ghidra analysis pseudocode, not original source.
 * ev_c11631b0b0a1045a7d98640a93ba67d08ac61cae21ea073376eab243577db9e4
 * Entry: 0x56e4d0; label: FUN_0056e4d0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0056e4d0(void)

{
  int iVar1;
  
  if ((DAT_008032cc == 0) && (0.0 < _DAT_00950d90)) {
    _DAT_00950d90 = _DAT_00950d90 - _DAT_00925018;
    if (0.0 < _DAT_00950d90) {
      FUN_00547930(0x51,0,0,0);
      iVar1 = FUN_0054fa60(0);
      FUN_0054ac00(0,(float)iVar1 * 1.5259022e-05 * 0.5);
      return;
    }
    FUN_00547930(0x52,0,0,0);
    return;
  }
  return;
}

