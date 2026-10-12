/* Ghidra pseudocode, not original source.
 * ev_a82e4e6157b5c05da4bf77128515088d4cb411e5fed9ff2f8222b3280f1d1bd7
 * Entry: 0x750540; label: FUN_00750540
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00750540(void)

{
  _DAT_028572e8 = &PTR_FUN_0076a9c0;
  _DAT_028572f8 = &PTR_FUN_0076a98c;
  FUN_00612730();
  FUN_00617930();
  FUN_0060e9e0();
  FUN_00633540();
  _DAT_028572e8 = &PTR_LAB_0076a94c;
  return;
}

