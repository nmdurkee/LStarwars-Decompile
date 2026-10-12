/* Ghidra analysis pseudocode, not original source.
 * ev_16752497ebe96469e4b3deeac467b7e56d3adcbbd74f32adb05b8515faa59936
 * Entry: 0x5cfb50; label: FUN_005cfb50
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005cfb50(int param_1,undefined4 param_2)

{
  if (param_1 != 0) {
    _DAT_00973898 = _DAT_00973898 | 1;
    _DAT_00806b9c = param_2;
    DAT_00973890 = param_1;
    return;
  }
  _DAT_00973898 = _DAT_00973898 & 0xfffffffe;
  DAT_00973890 = 0;
  return;
}

