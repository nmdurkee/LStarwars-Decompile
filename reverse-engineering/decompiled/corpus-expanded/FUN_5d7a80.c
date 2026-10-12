/* Ghidra pseudocode, not original source.
 * ev_2b55f789f1446a783af549e987f50963f158fc34aa4a0a7d53ec4780e4e01d82
 * Entry: 0x5d7a80; label: FUN_005d7a80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005d7a80(float param_1,float param_2)

{
  _DAT_00971870 = param_1;
  _DAT_0096637c = (param_1 - _DAT_0096e538) / param_2;
  DAT_0096e4ec = FUN_006e6b90();
  return;
}

