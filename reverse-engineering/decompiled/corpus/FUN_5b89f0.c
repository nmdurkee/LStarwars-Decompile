/* Ghidra analysis pseudocode, not original source.
 * ev_379977b8d9e5873865d2e50b4d7e474067c4ddbccc47084b5a50182ca7f5b25f
 * Entry: 0x5b89f0; label: FUN_005b89f0
 */

void FUN_005b89f0(float *param_1,float *param_2,float *param_3,float param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float *pfVar4;
  float10 fVar5;
  float10 fVar6;
  float10 fVar7;
  float10 fVar8;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  pfVar4 = param_2;
  param_2 = (float *)(param_2[3] * param_3[3] +
                     param_2[2] * param_3[2] + param_2[1] * param_3[1] + *param_2 * *param_3);
  if ((float)param_2 < 0.0) {
    param_2 = (float *)-(float)param_2;
    local_10 = -*param_3;
    local_c = -param_3[1];
    local_8 = -param_3[2];
    local_4 = -param_3[3];
    param_3 = &local_10;
  }
  if ((float)param_2 <= 0.85) {
    if (0.995 <= (float)param_2) {
      param_2 = (float *)0x3f7eb852;
    }
    fVar1 = (float)param_2 * 0.22340366 * (float)param_2 + 2.2184808;
    fVar5 = (float10)FUN_005c0240(fVar1 - (float)param_2 * 2.4418843);
    fVar6 = (float10)FUN_005c0240((float)param_2 * 2.4418843 + fVar1);
    fVar7 = (float10)(float)param_2;
    fVar8 = (float10)FUN_005c0240((float)((float10)1 - fVar7 * fVar7));
    fVar1 = (float)((float10)1 / fVar8);
    fVar5 = (float10)(float)((float10)0.6391287446022034 * fVar7 +
                            ((float10)(double)fVar5 - fVar6) + (float10)1.5707963705062866);
    fVar2 = (float)(fVar5 * ((float10)1 - (float10)param_4) - (float10)1.5707963705062866);
    fVar2 = fVar2 * fVar2;
    fVar3 = (float)(fVar5 * (float10)param_4 - (float10)1.5707963705062866);
    fVar3 = fVar3 * fVar3;
    fVar2 = fVar1 * ((fVar2 * (fVar2 * (fVar2 * 2.3154014e-05 - 0.0013853709) + 0.041663583) -
                     0.49999905) * fVar2 + 0.99999994);
    fVar1 = fVar1 * (((fVar3 * (fVar3 * 2.3154014e-05 - 0.0013853709) + 0.041663583) * fVar3 -
                     0.49999905) * fVar3 + 0.99999994);
    *param_1 = fVar1 * *param_3 + fVar2 * *pfVar4;
    param_1[1] = fVar2 * pfVar4[1] + param_3[1] * fVar1;
    param_1[2] = pfVar4[2] * fVar2 + param_3[2] * fVar1;
    param_1[3] = fVar1 * param_3[3] + pfVar4[3] * fVar2;
    return;
  }
  fVar1 = 1.0 - param_4;
  *param_1 = *param_3 * param_4 + fVar1 * *pfVar4;
  param_1[1] = fVar1 * pfVar4[1] + param_3[1] * param_4;
  param_1[2] = pfVar4[2] * fVar1 + param_3[2] * param_4;
  param_1[3] = fVar1 * pfVar4[3] + param_3[3] * param_4;
  FUN_005b82d0(param_1,param_1);
  return;
}

