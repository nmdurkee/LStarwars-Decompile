/* Ghidra analysis pseudocode, not original source.
 * ev_c9fa25cc79717ad47e0beb6e0964d9456c9021d00a3c9a64cb36b68ef15e0051
 * Entry: 0x6c0e40; label: FUN_006c0e40
 */

undefined4
FUN_006c0e40(float *param_1,float *param_2,float *param_3,float param_4,float *param_5,
            float *param_6)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float10 fVar7;
  float local_24;
  
  fVar2 = (*param_1 + *param_2) - *param_1;
  fVar3 = (param_1[1] + param_2[1]) - param_1[1];
  fVar1 = (param_1[2] + param_2[2]) - param_1[2];
  fVar4 = fVar2 * fVar2 + fVar3 * fVar3 + fVar1 * fVar1;
  fVar2 = fVar1 * (param_1[2] - param_3[2]) +
          fVar2 * (*param_1 - *param_3) + (param_1[1] - param_3[1]) * fVar3;
  fVar2 = fVar2 + fVar2;
  fVar3 = fVar2 * fVar2 -
          fVar4 * 4.0 *
          (((param_3[1] * param_3[1] + *param_3 * *param_3 + param_3[2] * param_3[2] +
            *param_1 * *param_1 + param_1[1] * param_1[1] + param_1[2] * param_1[2]) -
           (param_3[2] * param_1[2] + param_3[1] * param_1[1] + *param_1 * *param_3) * 2.0) -
          param_4 * param_4);
  if (ABS(fVar4) < 1.1920929e-07) {
    return 0;
  }
  if (0.0 <= fVar3) {
    fVar7 = (float10)FUN_005c0240(fVar3);
    fVar1 = (float)((fVar7 - (float10)fVar2) / (float10)(fVar4 * 2.0));
    fVar7 = (float10)FUN_005c0240(fVar3);
    fVar2 = (float)(((float10)(float)-(float10)fVar2 - fVar7) / (float10)(fVar4 * 2.0));
    if (param_5 != (float *)0x0) {
      fVar3 = param_2[1];
      fVar4 = param_2[2];
      fVar5 = param_1[1];
      fVar6 = param_1[2];
      *param_5 = *param_1 + fVar1 * *param_2;
      param_5[1] = fVar1 * fVar3 + fVar5;
      param_5[2] = fVar6 + fVar1 * fVar4;
      param_5[3] = local_24;
    }
    if (param_6 != (float *)0x0) {
      fVar3 = param_2[1];
      fVar1 = param_2[2];
      fVar4 = param_1[1];
      fVar5 = param_1[2];
      *param_6 = *param_1 + fVar2 * *param_2;
      param_6[1] = fVar2 * fVar3 + fVar4;
      param_6[2] = fVar5 + fVar2 * fVar1;
      param_6[3] = local_24;
    }
    return 1;
  }
  return 0;
}

