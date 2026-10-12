/* Ghidra pseudocode, not original source.
 * ev_c8c236b59c094db138f75ad711126508fb50275f6e5d8f12ab0ad6308e4435ce
 * Entry: 0x496e60; label: FUN_00496e60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00496e60(void)

{
  _DAT_0087a9d8 = 0x3f19999a;
  DAT_0087a92b = 1;
  FUN_005097d0(&DAT_00921440 + DAT_00800944 * 0x38);
  FUN_00509760();
  FUN_00548fb0(&DAT_00925044,0);
  return;
}

