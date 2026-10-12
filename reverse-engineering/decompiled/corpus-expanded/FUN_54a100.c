/* Ghidra pseudocode, not original source.
 * ev_ba19024e936acaebc8caa887b02629c3d2df1b51d473842281df89ce325ba5c8
 * Entry: 0x54a100; label: FUN_0054a100
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0054a100(float *param_1,float *param_2,float *param_3,undefined4 param_4)

{
  float fVar1;
  float10 fVar2;
  float10 fVar3;
  
  fVar2 = (float10)FUN_005becc0(param_4,param_2,0);
  fVar3 = (float10)FUN_005becc0(param_4,param_3,0);
  fVar1 = (float)fVar2 / ((float)fVar3 + (float)fVar2);
  *param_1 = *param_2 + fVar1 * (*param_3 - *param_2);
  param_1[1] = (param_3[1] - param_2[1]) * fVar1 + param_2[1];
  param_1[2] = (param_3[2] - param_2[2]) * fVar1 + param_2[2];
  return;
}

