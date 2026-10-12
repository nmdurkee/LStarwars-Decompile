/* Ghidra pseudocode, not original source.
 * ev_e9e973cc1e732372fb6e3c1361e2c8e184c78a797f94e34f658706f6700bd0dd
 * Entry: 0x5fe5e0; label: FUN_005fe5e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined * FUN_005fe5e0(int param_1)

{
  DAT_0080e1ac = DAT_0080e1ac - param_1;
  if (DAT_0080e1a8 < 0) {
    FUN_005f7490();
    return (undefined *)0x0;
  }
  return &DAT_0097c230 + DAT_0080e1ac * 4;
}

