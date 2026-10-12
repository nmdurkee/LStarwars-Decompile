/* Ghidra pseudocode, not original source.
 * ev_92748b398136944cd3b8ebaa69598612f81b868998f444146461847577bf6b2d
 * Entry: 0x6deac0; label: FUN_006deac0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_006deac0(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  DAT_0297ace0 = param_1;
  *param_1 = DAT_008277f0;
  param_1[1] = DAT_008277f4;
  param_1[2] = param_2;
  param_1[3] = param_3;
  _DAT_008277f8 = param_2;
  _DAT_008277fc = param_3;
  return param_1 + 4;
}

