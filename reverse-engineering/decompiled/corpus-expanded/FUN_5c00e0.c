/* Ghidra pseudocode, not original source.
 * ev_36c2cdffab22dec35ae5154a8d67af88b00f5702395280041def6b77535d68b9
 * Entry: 0x5c00e0; label: FUN_005c00e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4
FUN_005c00e0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            float *param_5,float *param_6,float *param_7,float *param_8,float *param_9)

{
  int iVar1;
  float10 fVar2;
  float10 fVar3;
  float local_c;
  float local_8;
  float local_4;
  
  iVar1 = FUN_005b9150(param_1,param_5,param_6,param_7);
  if ((iVar1 == 0) || (iVar1 = FUN_005bf770(param_7,param_2,param_3,param_4,param_1), iVar1 == 0)) {
    return 0;
  }
  if ((param_8 != (float *)0x0) || (param_9 != (float *)0x0)) {
    fVar2 = (float10)FUN_005c0240((param_7[2] - param_5[2]) * (param_7[2] - param_5[2]) +
                                  (param_7[1] - param_5[1]) * (param_7[1] - param_5[1]) +
                                  (*param_7 - *param_5) * (*param_7 - *param_5));
    if (param_8 != (float *)0x0) {
      *param_8 = (float)fVar2;
    }
    if (param_9 != (float *)0x0) {
      local_c = *param_6 - *param_5;
      local_8 = param_6[1] - param_5[1];
      local_4 = param_6[2] - param_5[2];
      fVar3 = (float10)FUN_005bec80(&local_c);
      *param_9 = (float)((float10)(float)fVar2 / fVar3);
      return 1;
    }
  }
  return 1;
}

