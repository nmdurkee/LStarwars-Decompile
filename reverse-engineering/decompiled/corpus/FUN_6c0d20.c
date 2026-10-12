/* Ghidra analysis pseudocode, not original source.
 * ev_c9fa25cc79717ad47e0beb6e0964d9456c9021d00a3c9a64cb36b68ef15e0051
 * Entry: 0x6c0d20; label: FUN_006c0d20
 */

undefined4 FUN_006c0d20(float *param_1,float *param_2,float *param_3,float *param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float local_14;
  
  fVar1 = param_1[2] * param_3[2] + *param_1 * *param_3 + param_1[1] * param_3[1] + param_3[3];
  fVar2 = (param_1[2] + param_2[2]) * param_3[2] +
          (param_1[1] + param_2[1]) * param_3[1] + *param_3 * (*param_1 + *param_2) + param_3[3];
  if (0.0 <= fVar1 * fVar2) {
    return 0;
  }
  if (param_4 != (float *)0x0) {
    fVar4 = -fVar1 / (fVar2 - fVar1);
    fVar1 = *param_2;
    fVar2 = param_2[1];
    fVar3 = param_2[2];
    *param_4 = fVar4 * fVar1;
    param_4[1] = fVar4 * fVar2;
    param_4[2] = fVar4 * fVar3;
    param_4[3] = local_14;
    *param_4 = *param_1 + fVar4 * fVar1;
    param_4[1] = fVar4 * fVar2 + param_1[1];
    param_4[2] = fVar4 * fVar3 + param_1[2];
    return 1;
  }
  return 1;
}

