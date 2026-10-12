/* Ghidra pseudocode, not original source.
 * ev_621a163f2f4eeffab67db0a5a6d80d4261cbfd10193b5f3a01bc1d3544017af8
 * Entry: 0x4f3db0; label: FUN_004f3db0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004f3db0(void)

{
  _memset(&DAT_0297dbc0,0,0x90);
  _DAT_0297dbe0 = 0x42700000;
  DAT_0297dbc8 = 2;
  DAT_0297dbcc = 5;
  DAT_0297dbc0 = 1;
  DAT_0297dbd0 = 0;
  _DAT_0297dc48 = 0;
  _DAT_0297dc18 = DAT_008004e0;
  DAT_0297dc24 = 0;
  DAT_0297dc28 = 0;
  FUN_005ddb90(DAT_0297dc38);
  return;
}

