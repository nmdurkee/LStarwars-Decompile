/* Ghidra pseudocode, not original source.
 * ev_f078e74f3672802c4578b8fbf1fdb2968ffe8ab04b5a400d7e6a18af3d5b4204
 * Entry: 0x5cfb90; label: FUN_005cfb90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005cfb90(int param_1,undefined4 *param_2)

{
  if (param_1 != 0) {
    DAT_00973894 = param_1;
    _DAT_00806cc0 = *param_2;
    _DAT_00806cc4 = param_2[1];
    _DAT_00973898 = _DAT_00973898 | 2;
    _DAT_00806cc8 = param_2[2];
    return;
  }
  _DAT_00973898 = _DAT_00973898 & 0xfffffffd;
  DAT_00973894 = 0;
  return;
}

