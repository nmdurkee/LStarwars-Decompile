/* Ghidra analysis pseudocode, not original source.
 * ev_537f31f6d7a7ebc324951952e862ea8d16fa2be695db959927eb9326274a35d3
 * Entry: 0x654a00; label: FUN_00654a00
 */

void FUN_00654a00(undefined4 param_1,int param_2,float *param_3)

{
  float fVar1;
  int iVar2;
  float10 fVar3;
  
  param_3[4] = param_3[4] - *param_3 * 0.6;
  param_3[6] = param_3[6] - param_3[2] * 0.6;
  fVar1 = param_3[1];
  fVar3 = (float10)FUN_005c0240(*param_3 * *param_3 + param_3[2] * param_3[2]);
  param_3[1] = (float)((float10)fVar1 - fVar3 * (float10)0.4000000059604645);
  iVar2 = _rand();
  param_3[7] = 64.0 / (((float)iVar2 * *(float *)(param_2 + 0xa4)) / 1.5032385e+09 +
                      *(float *)(param_2 + 0xa4));
  return;
}

