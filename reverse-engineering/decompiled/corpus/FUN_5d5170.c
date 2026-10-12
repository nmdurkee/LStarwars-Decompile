/* Ghidra analysis pseudocode, not original source.
 * ev_8e6c58f632ba894c996161736f16e550f9c9cdfbb0c94bd06c2a8d698c289bc5
 * Entry: 0x5d5170; label: FUN_005d5170
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005d5170(int param_1,undefined4 param_2)

{
  if (param_1 == 0) {
    _DAT_009718ec = param_2;
    return;
  }
  if (param_1 != 1) {
    if (param_1 != 2) {
      FUN_005c12e0();
      return;
    }
    _DAT_009718f4 = param_2;
    return;
  }
  _DAT_009718f0 = param_2;
  return;
}

