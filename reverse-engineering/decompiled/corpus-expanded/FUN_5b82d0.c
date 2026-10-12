/* Ghidra pseudocode, not original source.
 * ev_ef3b2a8ba8bea7724eb7ddbe17370c631fd0c0f4e2170ed1a1745c7d6977e716
 * Entry: 0x5b82d0; label: FUN_005b82d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005b82d0(float *param_1,float *param_2)

{
  float fVar1;
  float10 fVar2;
  
  fVar1 = param_2[2] * param_2[2] +
          param_2[1] * param_2[1] + *param_2 * *param_2 + param_2[3] * param_2[3];
  if (0.0 < fVar1) {
    fVar2 = (float10)FUN_005c0240(fVar1);
    if ((float)fVar2 == 0.0) {
      fVar1 = 0.0;
    }
    else {
      fVar1 = 1.0 / (float)fVar2;
    }
    param_1[3] = fVar1 * param_2[3];
    *param_1 = *param_2 * fVar1;
    param_1[1] = param_2[1] * fVar1;
    param_1[2] = fVar1 * param_2[2];
    return;
  }
  *param_1 = *param_2;
  param_1[1] = param_2[1];
  param_1[2] = param_2[2];
  param_1[3] = param_2[3];
  return;
}

