/* Ghidra pseudocode, not original source.
 * ev_0e84ad542db3be7599677a500db2c2fcd5f6f463504cd13a52c31f7d7facbfa7
 * Entry: 0x63dcd0; label: FUN_0063dcd0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0063dcd0(float param_1)

{
  undefined2 local_4;
  
  local_4 = (short)(int)ROUND(_DAT_0080fea0 * param_1);
  DAT_02913990._0_2_ = (short)DAT_02913990 + local_4;
  FUN_005d8370(0,6);
  return;
}

