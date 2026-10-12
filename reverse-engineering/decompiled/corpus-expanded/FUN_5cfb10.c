/* Ghidra pseudocode, not original source.
 * ev_f078e74f3672802c4578b8fbf1fdb2968ffe8ab04b5a400d7e6a18af3d5b4204
 * Entry: 0x5cfb10; label: FUN_005cfb10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005cfb10(int param_1)

{
  if (param_1 != 0) {
    _DAT_00973898 = _DAT_00973898 | 8;
    DAT_009738f0 = param_1;
    return;
  }
  _DAT_00973898 = _DAT_00973898 & 0xfffffff7;
  DAT_009738f0 = 0;
  return;
}

