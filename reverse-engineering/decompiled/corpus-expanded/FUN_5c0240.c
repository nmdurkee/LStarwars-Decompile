/* Ghidra pseudocode, not original source.
 * ev_36c2cdffab22dec35ae5154a8d67af88b00f5702395280041def6b77535d68b9
 * Entry: 0x5c0240; label: FUN_005c0240
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_005c0240(float param_1)

{
  float10 fVar1;
  
  if ((float10)param_1 < (float10)0) {
    return (float10)0;
  }
  fVar1 = (float10)FUN_006e9530();
  return (float10)(float)fVar1;
}

