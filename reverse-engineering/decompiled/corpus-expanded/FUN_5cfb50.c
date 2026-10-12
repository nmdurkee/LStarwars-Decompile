/* Ghidra pseudocode, not original source.
 * ev_f078e74f3672802c4578b8fbf1fdb2968ffe8ab04b5a400d7e6a18af3d5b4204
 * Entry: 0x5cfb50; label: FUN_005cfb50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

