/* Ghidra pseudocode, not original source.
 * ev_d287e844ea66f87c3c60c812c2454ec5cd238ea97f1ed9ffb4b19045dfabbd11
 * Entry: 0x4816b0; label: FUN_004816b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004816b0(void)

{
  DAT_00950d58 = 1;
  DAT_00950d60 = 0x100;
  _DAT_00950d64 = 0x200;
  DAT_00950d68 = 4;
  _DAT_00950d70 = 0x20;
  DAT_00950d74 = 0x40;
  DAT_00950d78 = 0x80;
  _DAT_00950d48 = 0x10;
  FUN_00520440(&LAB_004813d0);
  FUN_00520450(FUN_00481500);
  DAT_00879b48 = FUN_00491380;
  DAT_00879b4c = FUN_00491570;
  DAT_00879b50 = FUN_00491aa0;
  DAT_0095dfd0 = FUN_00481570;
  return;
}

