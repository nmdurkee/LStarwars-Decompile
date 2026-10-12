/* Ghidra analysis pseudocode, not original source.
 * ev_6ec8aea645f94e3276e7ac0037e639f8d50e0230e3ad74bacc489d09a6610266
 * Entry: 0x5b3b30; label: FUN_005b3b30
 */

void FUN_005b3b30(float *param_1,float *param_2)

{
  float fVar1;
  float10 fVar2;
  
  fVar2 = (float10)FUN_005c0240(param_2[2] * param_2[2] +
                                *param_2 * *param_2 + param_2[1] * param_2[1]);
  if ((float)fVar2 <= 0.0) {
    fVar1 = 0.0;
  }
  else {
    fVar1 = 1.0 / (float)fVar2;
  }
  *param_1 = fVar1 * *param_2;
  param_1[1] = fVar1 * param_2[1];
  param_1[2] = fVar1 * param_2[2];
  return;
}

