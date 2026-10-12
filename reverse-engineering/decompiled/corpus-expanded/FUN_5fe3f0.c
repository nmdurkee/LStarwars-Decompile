/* Ghidra pseudocode, not original source.
 * ev_e9e973cc1e732372fb6e3c1361e2c8e184c78a797f94e34f658706f6700bd0dd
 * Entry: 0x5fe3f0; label: FUN_005fe3f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005fe3f0(void)

{
  _DAT_0080e19c = 0x4000;
  _DAT_0080e1a0 = 0x4000;
  _DAT_0080e1a4 = 0x2000;
  _DAT_0080e1b0 = 1;
  _DAT_02854c3c = 0;
  DAT_0080e1a8 = 0xef00;
  DAT_0080e1ac = 0x800;
  _memset(&DAT_027e9a98,0,0x400);
  _DAT_0080e1e4 = 0x2000;
  return;
}

