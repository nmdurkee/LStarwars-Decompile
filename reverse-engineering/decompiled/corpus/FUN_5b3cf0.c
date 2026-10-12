/* Ghidra analysis pseudocode, not original source.
 * ev_6ec8aea645f94e3276e7ac0037e639f8d50e0230e3ad74bacc489d09a6610266
 * Entry: 0x5b3cf0; label: FUN_005b3cf0
 */

float10 FUN_005b3cf0(float *param_1,float *param_2,float *param_3)

{
  float fVar1;
  
  if (param_3 != (float *)0x0) {
    *param_3 = *param_1 - *param_2;
    param_3[1] = 0.0;
    fVar1 = param_1[2] - param_2[2];
    param_3[2] = fVar1;
    return (float10)(*param_3 * *param_3 + 0.0 + fVar1 * fVar1);
  }
  return (float10)((param_1[2] - param_2[2]) * (param_1[2] - param_2[2]) +
                  (*param_1 - *param_2) * (*param_1 - *param_2) + 0.0);
}

