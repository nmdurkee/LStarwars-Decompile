/* Ghidra pseudocode, not original source.
 * ev_a3dc7e4d451c42d041af92cbf24a16255b1dce01fb5c93e82b55e7bce3880be0
 * Entry: 0x5110d0; label: FUN_005110d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005110d0(void)

{
  if (((DAT_00921e10 != 0) || (DAT_00921e0c != 0)) || (0.0 < _DAT_00921e30)) {
    DAT_00921ed4 = 0;
    FUN_00510df0();
    return;
  }
  if (DAT_00921e14 == 0) {
    if (DAT_00921ed4 != 0) {
      FUN_00510e70();
      return;
    }
    _DAT_00921d60 = 0;
    DAT_00921ed4 = 1;
    _DAT_00921d5c = 0;
    FUN_00510e70();
    return;
  }
  if (DAT_00921ed4 != 0) {
    return;
  }
  _DAT_00921d5c = 0;
  _DAT_00921d60 = 0;
  DAT_00921ed4 = 1;
  return;
}

