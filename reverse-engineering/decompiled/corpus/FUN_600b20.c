/* Ghidra analysis pseudocode, not original source.
 * ev_17b66c49ee27a79138b1f69ed50983bbb8f85fa72fbf9f24d2924e74b686a814
 * Entry: 0x600b20; label: FUN_00600b20
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00600b20(int param_1)

{
  *(int *)(&DAT_00981c50 + DAT_02854d1c * 4) = param_1;
  if (param_1 == 0) {
    _DAT_0080e2b0 = 0x3b4ccccd;
    _DAT_0080e2b4 = 0xbc124925;
  }
  else {
    if (param_1 == 1) {
      _DAT_0080e2b0 = 0x3f800000;
      _DAT_0080e2b4 = 0xbf800000;
      _DAT_02854d20 = 0;
      _DAT_02854d24 = 0;
      return;
    }
    if (param_1 != 2) {
      return;
    }
    _DAT_0080e2b0 = 0x40000000;
    _DAT_0080e2b4 = 0xc0000000;
  }
  _DAT_02854d24 = 0x3f800000;
  _DAT_02854d20 = 0xbf800000;
  return;
}

