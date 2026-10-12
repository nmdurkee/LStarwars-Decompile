/* Ghidra analysis pseudocode, not original source.
 * ev_16752497ebe96469e4b3deeac467b7e56d3adcbbd74f32adb05b8515faa59936
 * Entry: 0x5cfae0; label: FUN_005cfae0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005cfae0(int param_1,undefined4 param_2)

{
  if (param_1 == 0) {
    DAT_009738f4 = param_1;
    _DAT_00973898 = _DAT_00973898 & 0xfffffffb;
    return;
  }
  _DAT_00973898 = _DAT_00973898 | 4;
  DAT_009738f4 = param_2;
  _DAT_009738f8 = param_1;
  return;
}

