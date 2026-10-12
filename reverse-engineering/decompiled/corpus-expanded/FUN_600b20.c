/* Ghidra pseudocode, not original source.
 * ev_64f3679a1f1e131a29792e896f5cd05cb4870e5bb22e267d9bfafa2e72f365ab
 * Entry: 0x600b20; label: FUN_00600b20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

