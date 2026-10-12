/* Ghidra pseudocode, not original source.
 * ev_a3dc7e4d451c42d041af92cbf24a16255b1dce01fb5c93e82b55e7bce3880be0
 * Entry: 0x511160; label: FUN_00511160
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00511160(void)

{
  FUN_004f1f10(&DAT_009213f8,PTR_s_Delete_Game_008009fc);
  _DAT_0092143c = (uint)DAT_00921daa;
  _DAT_009213e8 = (uint)DAT_0080099c;
  _DAT_009213f4 = (uint)DAT_0080099d;
  if (((DAT_00921e00 != 0) || (DAT_00921e04 != 0)) || (0.0 < _DAT_00921e38)) {
    DAT_00921ed8 = 0;
    FUN_00510ee0();
    return;
  }
  if (DAT_00921e08 == 0) {
    if (DAT_00921ed8 != 0) {
      FUN_00510f60();
      return;
    }
    _DAT_00921d60 = 0;
    DAT_00921ed8 = 1;
    _DAT_00921d5c = 0;
    FUN_00510f60();
    return;
  }
  if (DAT_00921ed8 != 0) {
    return;
  }
  _DAT_00921d5c = 0;
  _DAT_00921d60 = 0;
  DAT_00921ed8 = 1;
  return;
}

