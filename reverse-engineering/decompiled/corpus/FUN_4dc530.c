/* Ghidra analysis pseudocode, not original source.
 * ev_d881831d71d8ed35fa38d5b5eaee7ca2bcae4cde952964886fd1c7ddf43d442a
 * Entry: 0x4dc530; label: FUN_004dc530
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004dc530(void)

{
  undefined4 uVar1;
  float10 fVar2;
  
  uVar1 = 0;
  if (((_DAT_00950780 != 0.0) || (DAT_00855de0 != 0)) || (DAT_00951be0 != 0)) {
    _DAT_00882a5c = 0.0;
    _DAT_00882a50 = 0;
    _DAT_00882a54 = 0.0;
    return;
  }
  if (_DAT_0088249c <= 0.0) {
    if ((DAT_0093b328 != 0) || (_DAT_008824a0 < 6.0)) {
      uVar1 = 0x3f800000;
    }
    fVar2 = (float10)FUN_0054fad0(_DAT_00882a5c,uVar1,_DAT_00925018 + _DAT_00925018);
    _DAT_00882a5c = (float)fVar2;
    return;
  }
  if (((DAT_0093b328 == 0) && (_DAT_00882a54 < 1.0)) &&
     (_DAT_00882a54 = _DAT_00925018 + _DAT_00925018 + _DAT_00882a54, 1.0 < _DAT_00882a54)) {
    _DAT_00882a54 = 1.0;
    _DAT_00882a5c = 0.0;
    return;
  }
  _DAT_00882a5c = 0.0;
  return;
}

