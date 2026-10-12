/* Ghidra pseudocode, not original source.
 * ev_e061930119eb38dbd4d1e45fa45a2093349cae71e0e7104520800438f1f9aa3c
 * Entry: 0x5c1060; label: FUN_005c1060
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005c1060(float *param_1,float *param_2,float *param_3,float param_4)

{
  float fVar1;
  float10 fVar2;
  float10 fVar3;
  float10 fVar4;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  fVar2 = (float10)(param_2[3] * param_3[3] +
                   param_2[2] * param_3[2] + param_2[1] * param_3[1] + *param_2 * *param_3);
  if ((float10)0 <= fVar2) {
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
    fVar2 = (float10)(float)-fVar2;
  }
  if ((float10)1 - fVar2 <= (float10)0.0) {
    fVar4 = (float10)param_4;
    fVar2 = (float10)1 - fVar4;
  }
  else {
    fVar2 = (float10)FUN_005c0e30((float)fVar2);
    fVar1 = (float)((float10)1.5707963705062866 - fVar2);
    fVar3 = (float10)FUN_005c0f20(fVar1);
    fVar2 = (float10)FUN_005c0f20((1.0 - param_4) * fVar1);
    fVar2 = fVar2 / (float10)(float)fVar3;
    fVar4 = (float10)FUN_005c0f20(fVar1 * param_4);
    fVar4 = fVar4 / (float10)(float)fVar3;
  }
  local_14 = (float)fVar2;
  fVar1 = (float)fVar4;
  *param_1 = fVar1 * local_10 + local_14 * *param_2;
  param_1[1] = local_14 * param_2[1] + fVar1 * local_c;
  param_1[2] = fVar1 * local_8 + param_2[2] * local_14;
  param_1[3] = local_14 * param_2[3] + local_4 * fVar1;
  return;
}

