/* Ghidra pseudocode, not original source.
 * ev_bb04fbbbd27a84d29838025e356b4a832b57e1ec23fb072545eb7050db0a5426
 * Entry: 0x5ebd80; label: FUN_005ebd80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005ebd80(uint param_1,undefined4 param_2,undefined4 param_3)

{
  _DAT_009718b0 = param_3;
  _DAT_009718a8 = _DAT_009718a8 | param_1;
  _DAT_009718ac = param_2;
  FUN_005dad10(&DAT_009718b4,&DAT_009718b8);
  _DAT_009718bc = ((float)DAT_00963e18 * 0.0625) / ((float)DAT_00973900 / (float)DAT_0080e694);
  _DAT_009718c0 = ((float)DAT_00963e1c * 0.0625) / ((float)DAT_00973904 / (float)DAT_0080e698);
  return;
}

