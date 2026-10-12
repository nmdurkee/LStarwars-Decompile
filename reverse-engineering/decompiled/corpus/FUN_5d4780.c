/* Ghidra analysis pseudocode, not original source.
 * ev_8e6c58f632ba894c996161736f16e550f9c9cdfbb0c94bd06c2a8d698c289bc5
 * Entry: 0x5d4780; label: FUN_005d4780
 */

void FUN_005d4780(float *param_1,undefined4 param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  float10 fVar6;
  
  iVar5 = FUN_005b9e50();
  fVar2 = (float)iVar5 - 32768.0;
  iVar5 = FUN_005b9e50();
  fVar3 = (float)iVar5 - 32768.0;
  iVar5 = FUN_005b9e50();
  fVar4 = (float)iVar5 - 32768.0;
  fVar6 = (float10)FUN_005c0240(fVar4 * fVar4 + fVar2 * fVar2 + fVar3 * fVar3);
  fVar1 = (float)((float10)1 / fVar6);
  fVar2 = fVar1 * fVar2;
  fVar3 = fVar1 * fVar3;
  fVar1 = fVar1 * fVar4;
  *param_1 = fVar3 * param_3[6] + fVar2 * param_3[3] + fVar1 * param_3[9] + *param_3;
  param_1[1] = param_3[10] * fVar1 + param_3[4] * fVar2 + param_3[7] * fVar3 + param_3[1];
  param_1[2] = fVar1 * param_3[0xb] + param_3[8] * fVar3 + param_3[5] * fVar2 + param_3[2];
  param_1[3] = 1.0;
  FUN_005c03e0();
  return;
}

