/* Ghidra pseudocode, not original source.
 * ev_71ce34dfbc3e25ecc670a7014d4d5fe50c303635112430d697820e3c5a49cfb6
 * Entry: 0x5bbf20; label: FUN_005bbf20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005bbf20(float *param_1,float *param_2,float param_3,float param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  
  fVar6 = (1.0 - param_3) - param_4;
  fVar5 = param_4 * param_4;
  fVar1 = *param_2;
  *param_1 = fVar5 * fVar1;
  fVar2 = param_2[1];
  param_1[1] = fVar2 * fVar5;
  fVar3 = param_2[2];
  param_1[2] = fVar3 * fVar5;
  fVar4 = fVar6 * param_4 * 2.0;
  fVar7 = fVar4 * param_2[3] + fVar5 * fVar1;
  *param_1 = fVar7;
  fVar8 = param_2[4] * fVar4 + fVar2 * fVar5;
  param_1[1] = fVar8;
  fVar2 = fVar3 * fVar5 + param_2[5] * fVar4;
  param_1[2] = fVar2;
  param_4 = param_3 * 2.0 * param_4;
  fVar7 = param_4 * param_2[6] + fVar7;
  *param_1 = fVar7;
  fVar8 = param_2[7] * param_4 + fVar8;
  param_1[1] = fVar8;
  fVar2 = fVar2 + param_2[8] * param_4;
  param_1[2] = fVar2;
  fVar1 = fVar6 * fVar6;
  fVar7 = fVar1 * param_2[9] + fVar7;
  *param_1 = fVar7;
  fVar8 = param_2[10] * fVar1 + fVar8;
  param_1[1] = fVar8;
  fVar2 = fVar2 + param_2[0xb] * fVar1;
  param_1[2] = fVar2;
  fVar1 = fVar6 * 2.0 * param_3;
  param_3 = param_3 * param_3;
  *param_1 = param_3 * param_2[0xf] + fVar1 * param_2[0xc] + fVar7;
  param_1[1] = param_2[0x10] * param_3 + param_2[0xd] * fVar1 + fVar8;
  param_1[2] = param_2[0x11] * param_3 + param_2[0xe] * fVar1 + fVar2;
  return;
}

