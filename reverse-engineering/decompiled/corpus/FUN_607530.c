/* Ghidra analysis pseudocode, not original source.
 * ev_8be49e78861dfe08cca82ea9c09c813f64ee3632778122cedbbea2ab2ea39171
 * Entry: 0x607530; label: FUN_00607530
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00607530(undefined4 *param_1)

{
  _DAT_0098692c = param_1[3];
  _DAT_009716e8 = *param_1;
  _DAT_009716ec = param_1[1];
  _DAT_009716f0 = param_1[2];
  _DAT_009868d8 = *param_1;
  _DAT_009868dc = param_1[1];
  _DAT_009868c0 = _DAT_009868c0 + 1;
  _DAT_009868e0 = param_1[2];
  _DAT_009868c4 = _DAT_009868c4 + 1;
  _DAT_009868d4 = 0;
  return 0;
}

