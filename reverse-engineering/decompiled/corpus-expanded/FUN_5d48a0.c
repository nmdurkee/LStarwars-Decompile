/* Ghidra pseudocode, not original source.
 * ev_e5677de9d32ba70c3e7679a2013183581fdac6be8f175158264fecd59db3931d
 * Entry: 0x5d48a0; label: FUN_005d48a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005d48a0(float *param_1,undefined4 param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  float10 fVar5;
  
  iVar4 = FUN_005b9e50();
  fVar1 = (float)(iVar4 + -0x8000) * 3.0517578e-05;
  iVar4 = FUN_005b9e50();
  fVar2 = (float)iVar4 - 32768.0;
  iVar4 = FUN_005b9e50();
  fVar3 = (float)iVar4 - 32768.0;
  fVar5 = (float10)FUN_005c0240(fVar2 * fVar2 + fVar3 * fVar3);
  fVar2 = (float)((float10)1 / fVar5) * fVar2;
  fVar3 = (float)((float10)1 / fVar5) * fVar3;
  *param_1 = fVar2 * param_3[6] + fVar1 * param_3[3] + fVar3 * param_3[9] + *param_3;
  param_1[1] = param_3[10] * fVar3 + param_3[4] * fVar1 + param_3[7] * fVar2 + param_3[1];
  param_1[2] = fVar3 * param_3[0xb] + param_3[8] * fVar2 + param_3[5] * fVar1 + param_3[2];
  param_1[3] = 1.0;
  FUN_005c03e0();
  return;
}

