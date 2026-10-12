/* Ghidra pseudocode, not original source.
 * ev_9af94503fce638d48c98755f8a4ba03de7c5cdf51e6dce151974c12e75b3fd49
 * Entry: 0x54fad0; label: FUN_0054fad0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_0054fad0(float param_1,float param_2,float param_3)

{
  float10 fVar1;
  float10 fVar2;
  
  fVar1 = (float10)param_1;
  fVar2 = (float10)param_2;
  if (fVar1 <= fVar2) {
    if (fVar2 <= fVar1) {
      return fVar1;
    }
    fVar1 = (float10)(float)((float10)param_3 + fVar1);
    if (fVar2 < fVar1) {
      return (float10)param_2;
    }
  }
  else {
    fVar1 = (float10)(float)(fVar1 - (float10)param_3);
    if (fVar1 < fVar2) {
      return (float10)param_2;
    }
  }
  return fVar1;
}

