/* Ghidra pseudocode, not original source.
 * ev_2b55f789f1446a783af549e987f50963f158fc34aa4a0a7d53ec4780e4e01d82
 * Entry: 0x5d6db0; label: FUN_005d6db0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005d6db0(float param_1,float param_2)

{
  if ((param_1 != 0.0) && (param_2 != 0.0)) {
    FUN_005c0240(param_1 / param_2);
    return;
  }
  FUN_005c0240(0);
  return;
}

