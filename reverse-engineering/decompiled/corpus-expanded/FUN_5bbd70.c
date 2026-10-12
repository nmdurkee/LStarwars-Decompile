/* Ghidra pseudocode, not original source.
 * ev_71ce34dfbc3e25ecc670a7014d4d5fe50c303635112430d697820e3c5a49cfb6
 * Entry: 0x5bbd70; label: FUN_005bbd70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005bbd70(float *param_1,float *param_2,float param_3,float param_4,float param_5)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  
  fVar5 = param_3 * param_3;
  fVar1 = *param_2;
  *param_1 = fVar5 * fVar1;
  fVar2 = param_2[1];
  param_1[1] = fVar2 * fVar5;
  fVar3 = param_2[2];
  param_1[2] = fVar3 * fVar5;
  fVar4 = param_4 * (param_3 + param_3);
  fVar6 = fVar4 * param_2[3] + fVar5 * fVar1;
  *param_1 = fVar6;
  fVar7 = param_2[4] * fVar4 + fVar2 * fVar5;
  param_1[1] = fVar7;
  fVar2 = param_2[5] * fVar4 + fVar3 * fVar5;
  param_1[2] = fVar2;
  fVar1 = param_5 * (param_3 + param_3);
  fVar6 = fVar1 * param_2[6] + fVar6;
  *param_1 = fVar6;
  fVar7 = param_2[7] * fVar1 + fVar7;
  param_1[1] = fVar7;
  fVar2 = param_2[8] * fVar1 + fVar2;
  param_1[2] = fVar2;
  fVar1 = param_4 * param_4;
  fVar6 = fVar1 * param_2[9] + fVar6;
  *param_1 = fVar6;
  fVar7 = param_2[10] * fVar1 + fVar7;
  param_1[1] = fVar7;
  fVar2 = param_2[0xb] * fVar1 + fVar2;
  param_1[2] = fVar2;
  fVar1 = (param_4 + param_4) * param_5;
  param_5 = param_5 * param_5;
  *param_1 = param_5 * param_2[0xf] + fVar1 * param_2[0xc] + fVar6;
  param_1[1] = param_2[0x10] * param_5 + param_2[0xd] * fVar1 + fVar7;
  param_1[2] = param_2[0x11] * param_5 + param_2[0xe] * fVar1 + fVar2;
  return;
}

