/* Ghidra pseudocode, not original source.
 * ev_e5677de9d32ba70c3e7679a2013183581fdac6be8f175158264fecd59db3931d
 * Entry: 0x5d5170; label: FUN_005d5170
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005d5170(int param_1,undefined4 param_2)

{
  if (param_1 == 0) {
    _DAT_009718ec = param_2;
    return;
  }
  if (param_1 != 1) {
    if (param_1 != 2) {
      FUN_005c12e0();
      return;
    }
    _DAT_009718f4 = param_2;
    return;
  }
  _DAT_009718f0 = param_2;
  return;
}

