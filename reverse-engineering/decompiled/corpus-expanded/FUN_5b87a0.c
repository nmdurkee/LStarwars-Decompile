/* Ghidra pseudocode, not original source.
 * ev_ef3b2a8ba8bea7724eb7ddbe17370c631fd0c0f4e2170ed1a1745c7d6977e716
 * Entry: 0x5b87a0; label: FUN_005b87a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005b87a0(float *param_1,float *param_2,float *param_3,float param_4)

{
  float fVar1;
  float *pfVar2;
  int iVar3;
  float10 fVar4;
  float10 extraout_ST0;
  float10 extraout_ST1;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  pfVar2 = param_2;
  fVar4 = (float10)(param_2[3] * param_3[3] +
                   param_2[2] * param_3[2] + param_2[1] * param_3[1] + *param_2 * *param_3);
  if ((float10)0 <= fVar4) {
    local_10 = *param_3;
    local_c = param_3[1];
    local_8 = param_3[2];
    local_4 = param_3[3];
  }
  else {
    local_10 = -*param_3;
    local_c = -param_3[1];
    local_8 = -param_3[2];
    local_4 = -param_3[3];
    fVar4 = (float10)(float)-fVar4;
  }
  if ((float10)1 - fVar4 <= (float10)9.999999747378752e-06) {
    fVar4 = (float10)param_4;
    param_2 = (float *)(float)((float10)1 - fVar4);
  }
  else {
    FUN_005b2e20((float)fVar4);
    iVar3 = FUN_006e6b90();
    fVar1 = (float)(&DAT_029899a0)[iVar3 >> 1 & 0x7fff];
    iVar3 = FUN_006e6b90();
    if (((float)(&DAT_029899a0)[iVar3 >> 1 & 0x7fff] == 0.0) || (fVar1 == 0.0)) {
      param_2 = (float *)0x0;
    }
    else {
      param_2 = (float *)((float)(&DAT_029899a0)[iVar3 >> 1 & 0x7fff] / fVar1);
    }
    iVar3 = FUN_006e6b90();
    fVar4 = extraout_ST0;
    if (((float10)(float)(&DAT_029899a0)[iVar3 >> 1 & 0x7fff] != extraout_ST0) &&
       (extraout_ST0 != extraout_ST1)) {
      fVar4 = (float10)(float)(&DAT_029899a0)[iVar3 >> 1 & 0x7fff] / extraout_ST1;
    }
  }
  fVar1 = (float)fVar4;
  *param_1 = fVar1 * local_10 + (float)param_2 * *pfVar2;
  param_1[1] = (float)param_2 * pfVar2[1] + fVar1 * local_c;
  param_1[2] = fVar1 * local_8 + pfVar2[2] * (float)param_2;
  param_1[3] = (float)param_2 * pfVar2[3] + local_4 * fVar1;
  return;
}

