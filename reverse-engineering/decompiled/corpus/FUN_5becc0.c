/* Ghidra analysis pseudocode, not original source.
 * ev_63802f60b4285c5edf6c429a3d1e3220ec0e39d2563d3bbc7dd58661d8af5682
 * Entry: 0x5becc0; label: FUN_005becc0
 */

void FUN_005becc0(float *param_1,float *param_2,float *param_3)

{
  float fVar1;
  
  if (param_3 != (float *)0x0) {
    *param_3 = *param_1 - *param_2;
    param_3[1] = param_1[1] - param_2[1];
    fVar1 = param_1[2] - param_2[2];
    param_3[2] = fVar1;
    FUN_005c0240(*param_3 * *param_3 + param_3[1] * param_3[1] + fVar1 * fVar1);
    return;
  }
  FUN_005c0240((param_1[2] - param_2[2]) * (param_1[2] - param_2[2]) +
               (param_1[1] - param_2[1]) * (param_1[1] - param_2[1]) +
               (*param_1 - *param_2) * (*param_1 - *param_2));
  return;
}

