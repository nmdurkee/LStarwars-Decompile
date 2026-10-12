/* Ghidra pseudocode, not original source.
 * ev_ef3b2a8ba8bea7724eb7ddbe17370c631fd0c0f4e2170ed1a1745c7d6977e716
 * Entry: 0x5b7c50; label: FUN_005b7c50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005b7c50(float param_1,float param_2)

{
  if (ABS(param_1 - param_2) < _DAT_008065b8) {
    return 1;
  }
  return 0;
}

