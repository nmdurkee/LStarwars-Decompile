/* Ghidra pseudocode, not original source.
 * ev_a3dc7e4d451c42d041af92cbf24a16255b1dce01fb5c93e82b55e7bce3880be0
 * Entry: 0x511390; label: FUN_00511390
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00511390(void)

{
  undefined4 uVar1;
  
  FUN_004f1f10(&DAT_009213f8,PTR_s_Load_Game_008009f8);
  _DAT_0092143c = (uint)DAT_00921daa;
  _DAT_009213e8 = (uint)DAT_0080099c;
  _DAT_009213f4 = (uint)DAT_0080099d;
  if (((DAT_00921dcc != 0) || (DAT_00921dd0 != 0)) || (uVar1 = 0, 0.0 < _DAT_00921e28)) {
    DAT_00921ee0 = 0;
    FUN_00510c10();
    return;
  }
  if (DAT_00921dd4 != 0) {
    if (DAT_00921ee0 != 0) {
      FUN_00510d10();
      return;
    }
    _DAT_00921d60 = 0;
    DAT_00921ee0 = 1;
    _DAT_00921d5c = uVar1;
    FUN_00510d10();
    return;
  }
  if (DAT_00921dd8 != 0) {
    if (DAT_00921ee0 != 0) {
      FUN_00510d80();
      return;
    }
    _DAT_00921d60 = 0;
    DAT_00921ee0 = 1;
    _DAT_00921d5c = uVar1;
    FUN_00510d80();
    return;
  }
  if (DAT_00921ee0 != 0) {
    FUN_00510c90();
    return;
  }
  _DAT_00921d60 = 0;
  DAT_00921ee0 = 1;
  _DAT_00921d5c = uVar1;
  FUN_00510c90();
  return;
}

