/* Ghidra analysis pseudocode, not original source.
 * ev_0d1e553906e4ac29f0c898728bb3c9cf38177ab98ca2cbcdea8e6b852723dd83
 * Entry: 0x59eac0; label: FUN_0059eac0
 */

void FUN_0059eac0(int param_1)

{
  FUN_004f7fb0(param_1);
  if (*(int *)(param_1 + 0x510) != 0) {
    DAT_00956410 = FUN_00559e20(*DAT_00956420,*(int *)(param_1 + 0x510));
  }
  return;
}

