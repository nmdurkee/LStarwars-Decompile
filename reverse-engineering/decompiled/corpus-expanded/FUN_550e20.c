/* Ghidra pseudocode, not original source.
 * ev_9af94503fce638d48c98755f8a4ba03de7c5cdf51e6dce151974c12e75b3fd49
 * Entry: 0x550e20; label: FUN_00550e20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_00550e20(float *param_1,float *param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  float10 fVar6;
  float10 fVar7;
  
  fVar1 = *param_3;
  fVar2 = *param_2;
  fVar3 = param_3[2];
  fVar4 = param_2[2];
  iVar5 = FUN_005be2d0(fVar1 - fVar2,fVar3 - fVar4);
  fVar7 = (float10)0;
  fVar6 = (float10)((float)(&DAT_029899a0)[(int)((-iVar5 & 0xffffU) + 0x4000) >> 1 & 0x7fff] *
                    (param_1[2] - param_2[2]) -
                   (float)(&DAT_029899a0)[(-iVar5 & 0xffffU) >> 1] * (*param_1 - *param_2));
  if (fVar6 < fVar7 != (fVar6 == fVar7)) {
    return fVar7;
  }
  fVar7 = (float10)((fVar3 - fVar4) *
                    (float)(&DAT_029899a0)[(int)((-iVar5 & 0xffffU) + 0x4000) >> 1 & 0x7fff] -
                   (fVar1 - fVar2) * (float)(&DAT_029899a0)[(-iVar5 & 0xffffU) >> 1]);
  if (fVar7 < fVar6 != (fVar7 == fVar6)) {
    return (float10)1;
  }
  return (float10)(float)(fVar6 / fVar7);
}

