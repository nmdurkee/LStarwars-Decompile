/* Ghidra pseudocode, not original source.
 * ev_36c2cdffab22dec35ae5154a8d67af88b00f5702395280041def6b77535d68b9
 * Entry: 0x5bfe40; label: FUN_005bfe40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005bfe40(float param_1,float param_2)

{
  float10 fVar1;
  
  if (param_1 == 0.0) {
    return;
  }
  fVar1 = (float10)FUN_005be790(param_1);
  FUN_005be970((float)(fVar1 * (float10)param_2));
  return;
}

