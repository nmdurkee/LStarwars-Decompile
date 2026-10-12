/* Ghidra pseudocode, not original source.
 * ev_64ab134b4afd9c8d0a163dd8f67d256d98012891aab565beeb69ac94b847fa54
 * Entry: 0x5db150; label: FUN_005db150
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005db150(float param_1,float param_2,float param_3,float param_4)

{
  _DAT_0080c010 = param_1;
  _DAT_0080c014 = param_2;
  _DAT_0080c018 = param_3 - param_1;
  _DAT_0080c01c = param_4 - param_2;
  FUN_005daf30(&DAT_0080c010);
  FUN_005ff390();
  return;
}

