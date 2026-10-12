/* Ghidra pseudocode, not original source.
 * ev_9dff45b5f0eb52bcd65f8627f4ae852e719fa42162b45a2265e4036e2ee04965
 * Entry: 0x74e930; label: FUN_0074e930
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0074e930(float param_1,float param_2,float param_3,float param_4)

{
  _DAT_008546d8 = param_1 * 0.00390625;
  _DAT_008546dc = param_2 * 0.00390625;
  _DAT_008546e0 = param_3 * 0.00390625;
  _DAT_008546e4 = (param_4 + param_2) * 0.001953125;
  _DAT_008546ec = _DAT_008546e4;
  _DAT_008546e8 = param_1 * 0.00390625;
  _DAT_008546f0 = param_3 * 0.00390625;
  _DAT_008546f4 = (param_4 - param_2) * 0.00048828125;
  return;
}

