/* Ghidra pseudocode, not original source.
 * ev_e5677de9d32ba70c3e7679a2013183581fdac6be8f175158264fecd59db3931d
 * Entry: 0x5d4f30; label: FUN_005d4f30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005d4f30(float param_1,float param_2)

{
  _DAT_00971960 = 0;
  _DAT_0097195c = 3;
  _DAT_00971958 = (param_2 - param_1) * (param_1 / (param_2 + param_1)) + param_1;
  _DAT_00971950 = 0x3f800000;
  _DAT_00971954 = (_DAT_00971958 * param_2) / ((param_2 - _DAT_00971958) + param_2);
  _DAT_0097194c = (uint)(DAT_0097392c == 0);
  return;
}

