/* Ghidra pseudocode, not original source.
 * ev_ef3b2a8ba8bea7724eb7ddbe17370c631fd0c0f4e2170ed1a1745c7d6977e716
 * Entry: 0x5b7c20; label: FUN_005b7c20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_005b7c20(uint param_1)

{
  if ((param_1 & 0x80000000) != 0) {
    return (float10)-1.0;
  }
  return (float10)1.0;
}

