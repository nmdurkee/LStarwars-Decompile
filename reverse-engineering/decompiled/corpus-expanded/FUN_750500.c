/* Ghidra pseudocode, not original source.
 * ev_a82e4e6157b5c05da4bf77128515088d4cb411e5fed9ff2f8222b3280f1d1bd7
 * Entry: 0x750500; label: FUN_00750500
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00750500(void)

{
  if (DAT_02856bf8 != 0) {
    FUN_006e85b0(DAT_02856bf8);
  }
  DAT_02856bf8 = 0;
  DAT_02856bfc = 0;
  _DAT_02856c00 = 0;
  return;
}

