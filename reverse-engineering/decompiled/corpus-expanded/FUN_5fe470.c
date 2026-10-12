/* Ghidra pseudocode, not original source.
 * ev_e9e973cc1e732372fb6e3c1361e2c8e184c78a797f94e34f658706f6700bd0dd
 * Entry: 0x5fe470; label: FUN_005fe470
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005fe470(uint param_1)

{
  _DAT_0280d818 = param_1 & 0xffffff;
  FUN_006e5340(0x22,param_1);
  _DAT_02854c90 = 0;
  return;
}

