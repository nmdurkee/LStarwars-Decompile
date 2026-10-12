/* Ghidra analysis pseudocode, not original source.
 * ev_63802f60b4285c5edf6c429a3d1e3220ec0e39d2563d3bbc7dd58661d8af5682
 * Entry: 0x5bfc50; label: FUN_005bfc50
 */

float10 FUN_005bfc50(float *param_1,float *param_2,float *param_3,float *param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float10 fVar10;
  
  fVar1 = *param_3;
  fVar2 = *param_1;
  fVar3 = param_3[1];
  fVar4 = param_1[1];
  fVar5 = param_3[2];
  fVar6 = param_1[2];
  fVar8 = (param_2[1] - param_1[1]) * (param_4[2] - param_3[2]) -
          (param_2[2] - param_1[2]) * (param_4[1] - param_3[1]);
  fVar7 = (*param_4 - *param_3) * (param_2[2] - param_1[2]) -
          (*param_2 - *param_1) * (param_4[2] - param_3[2]);
  fVar9 = (param_4[1] - param_3[1]) * (*param_2 - *param_1) -
          (param_2[1] - param_1[1]) * (*param_4 - *param_3);
  fVar10 = (float10)FUN_005c0240(fVar8 * fVar8 + fVar7 * fVar7 + fVar9 * fVar9);
  return (float10)(float)((float10)(fVar9 * (fVar5 - fVar6) +
                                   (fVar3 - fVar4) * fVar7 + (fVar1 - fVar2) * fVar8) / fVar10);
}

