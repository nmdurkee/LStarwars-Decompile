/* Ghidra analysis pseudocode, not original source.
 * ev_63802f60b4285c5edf6c429a3d1e3220ec0e39d2563d3bbc7dd58661d8af5682
 * Entry: 0x5bfae0; label: FUN_005bfae0
 */

float10 FUN_005bfae0(float *param_1,float *param_2,float *param_3,float *param_4)

{
  float fVar1;
  float fVar2;
  float10 fVar3;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  local_18 = *param_2 - *param_1;
  local_14 = param_2[1] - param_1[1];
  local_10 = param_2[2] - param_1[2];
  fVar3 = (float10)FUN_005c0240(local_10 * local_10 + local_14 * local_14 + local_18 * local_18);
  fVar1 = (float)((float10)1 / fVar3);
  local_c = *param_3 - *param_1;
  local_8 = param_3[1] - param_1[1];
  local_4 = param_3[2] - param_1[2];
  fVar2 = fVar1 * local_18 * local_c + local_14 * fVar1 * local_8 + fVar1 * local_10 * local_4;
  local_18 = *param_1 + fVar2 * fVar1 * local_18;
  local_14 = fVar2 * local_14 * fVar1 + param_1[1];
  local_10 = param_1[2] + fVar2 * fVar1 * local_10;
  fVar3 = (float10)FUN_005b3c50(&local_18,param_3,&local_c);
  if (param_4 != (float *)0x0) {
    *param_4 = local_18;
    param_4[1] = local_14;
    param_4[2] = local_10;
  }
  return (float10)(float)fVar3;
}

