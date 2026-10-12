/* Ghidra analysis pseudocode, not original source.
 * ev_63802f60b4285c5edf6c429a3d1e3220ec0e39d2563d3bbc7dd58661d8af5682
 * Entry: 0x5bee20; label: FUN_005bee20
 */

undefined4
FUN_005bee20(float *param_1,float *param_2,float *param_3,float *param_4,float *param_5,
            float *param_6)

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
  float fVar10;
  float10 fVar11;
  
  fVar7 = param_2[1] * param_4[2] - param_2[2] * param_4[1];
  fVar8 = param_2[2] * *param_4 - *param_2 * param_4[2];
  fVar9 = *param_2 * param_4[1] - *param_4 * param_2[1];
  fVar11 = (float10)FUN_005c0240(fVar9 * fVar9 + fVar7 * fVar7 + fVar8 * fVar8);
  fVar10 = 0.0;
  if ((float)fVar11 != 0.0) {
    fVar10 = 1.0 / (float)fVar11;
  }
  fVar10 = fVar10 * fVar10;
  fVar1 = *param_3;
  fVar2 = *param_1;
  fVar3 = param_3[1];
  fVar4 = param_1[1];
  fVar5 = param_3[2];
  fVar6 = param_1[2];
  *param_5 = fVar10 * (((param_4[1] * fVar9 - param_4[2] * fVar8) * (fVar1 - fVar2) -
                       (fVar3 - fVar4) * (fVar9 * *param_4 - fVar7 * param_4[2])) +
                      (fVar5 - fVar6) * (fVar8 * *param_4 - fVar7 * param_4[1]));
  *param_6 = (((fVar9 * param_2[1] - fVar8 * param_2[2]) * (fVar1 - fVar2) -
              (*param_2 * fVar9 - fVar7 * param_2[2]) * (fVar3 - fVar4)) +
             (fVar5 - fVar6) * (fVar8 * *param_2 - param_2[1] * fVar7)) * fVar10;
  if (fVar10 == 0.0) {
    return 0;
  }
  return 1;
}

