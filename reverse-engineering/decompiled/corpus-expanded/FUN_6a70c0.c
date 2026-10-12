/* Ghidra pseudocode, not original source.
 * ev_d0baaaa1d022e9a6bc644bf87cbac2e9d23f713faf88b9587519a457b813b0f8
 * Entry: 0x6a70c0; label: FUN_006a70c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_006a70c0(float param_1,float param_2)

{
  float10 fVar1;
  
  if (param_1 <= 0.0) {
    if (param_2 < 0.0) {
      fVar1 = (float10)FUN_006e9530();
      return (float10)(float)-fVar1;
    }
    if (param_2 < -param_1) {
      fVar1 = (float10)FUN_006e9530();
      return (float10)(float)-fVar1;
    }
    fVar1 = (float10)FUN_006e9530();
    return (float10)(float)fVar1;
  }
  if (0.0 < param_2) {
    fVar1 = (float10)FUN_006e9530();
    return (float10)(float)fVar1;
  }
  if (-param_2 < param_1) {
    fVar1 = (float10)FUN_006e9530();
    return (float10)(float)fVar1;
  }
  fVar1 = (float10)FUN_006e9530();
  return (float10)(float)-fVar1;
}

