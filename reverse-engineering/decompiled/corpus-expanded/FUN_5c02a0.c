/* Ghidra pseudocode, not original source.
 * ev_36c2cdffab22dec35ae5154a8d67af88b00f5702395280041def6b77535d68b9
 * Entry: 0x5c02a0; label: FUN_005c02a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_005c02a0(float param_1,float param_2)

{
  if (param_2 < param_1) {
    return (float10)param_1;
  }
  return (float10)param_2;
}

