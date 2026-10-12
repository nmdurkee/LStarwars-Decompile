/* Ghidra pseudocode, not original source.
 * ev_f078e74f3672802c4578b8fbf1fdb2968ffe8ab04b5a400d7e6a18af3d5b4204
 * Entry: 0x5cfae0; label: FUN_005cfae0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

