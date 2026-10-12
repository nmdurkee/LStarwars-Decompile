/* Ghidra pseudocode, not original source.
 * ev_caa872c778113341e1df0ccd71c86dbd4a603da626237a6695cd46c57da8fb02
 * Entry: 0x6c0c10; label: FUN_006c0c10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_006c0c10(float *param_1,float *param_2,float *param_3)

{
  float10 fVar1;
  float fVar2;
  float fVar3;
  float10 fVar4;
  float10 fVar5;
  
  fVar2 = param_1[2] * param_3[2] + param_1[1] * param_3[1] + *param_1 * *param_3 + param_3[3];
  fVar3 = (param_2[2] + param_1[2]) * param_3[2] +
          (param_2[1] + param_1[1]) * param_3[1] + *param_3 * (*param_1 + *param_2) + param_3[3];
  fVar1 = (float10)0;
  fVar4 = (float10)fVar2;
  fVar5 = (float10)fVar3;
  if ((fVar4 < fVar1) && (fVar5 < fVar1)) {
    if (fVar5 < fVar4) {
      return (float10)fVar2;
    }
    return (float10)fVar3;
  }
  if (fVar4 <= fVar1) {
    return fVar1;
  }
  if (fVar1 < fVar5) {
    if (fVar4 < fVar5) {
      return (float10)fVar2;
    }
    return (float10)fVar3;
  }
  return fVar1;
}

