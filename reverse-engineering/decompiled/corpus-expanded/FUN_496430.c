/* Ghidra pseudocode, not original source.
 * ev_c8c236b59c094db138f75ad711126508fb50275f6e5d8f12ab0ad6308e4435ce
 * Entry: 0x496430; label: FUN_00496430
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00496430(void)

{
  DAT_0087a9cc = 0x3f19999a;
  _DAT_0087b940 = 0x40000000;
  DAT_0087a928 = 1;
  FUN_005097d0(&DAT_00921440 + DAT_00800944 * 0x38);
  FUN_00509760();
  FUN_0042b080();
  return;
}

