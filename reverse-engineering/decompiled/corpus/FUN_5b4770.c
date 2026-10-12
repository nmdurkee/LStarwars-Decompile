/* Ghidra analysis pseudocode, not original source.
 * ev_6ec8aea645f94e3276e7ac0037e639f8d50e0230e3ad74bacc489d09a6610266
 * Entry: 0x5b4770; label: FUN_005b4770
 */

void FUN_005b4770(float *param_1,int param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  
  fVar1 = (float)(&DAT_029899a0)[param_2 >> 2 & 0x7fff];
  fVar2 = (float)(&DAT_029899a0)[(param_2 >> 1) + 0x4000 >> 1 & 0x7fff];
  fVar3 = fVar1 * *param_3;
  fVar4 = param_3[1] * fVar1;
  fVar8 = fVar4 + fVar4;
  fVar1 = param_3[2] * fVar1;
  fVar5 = fVar1 + fVar1;
  fVar6 = fVar2 * (fVar3 + fVar3);
  fVar7 = fVar3 * (fVar3 + fVar3);
  *param_1 = 1.0 - (fVar8 * fVar4 + fVar5 * fVar1);
  param_1[5] = 1.0 - (fVar7 + fVar5 * fVar1);
  param_1[10] = 1.0 - (fVar8 * fVar4 + fVar7);
  param_1[0xf] = 1.0;
  param_1[1] = fVar8 * fVar3 + fVar5 * fVar2;
  param_1[2] = fVar5 * fVar3 - fVar8 * fVar2;
  param_1[3] = 0.0;
  param_1[4] = fVar8 * fVar3 - fVar5 * fVar2;
  param_1[6] = fVar6 + fVar5 * fVar4;
  param_1[7] = 0.0;
  param_1[8] = fVar5 * fVar3 + fVar8 * fVar2;
  param_1[9] = fVar5 * fVar4 - fVar6;
  param_1[0xb] = 0.0;
  param_1[0xe] = 0.0;
  param_1[0xd] = 0.0;
  param_1[0xc] = 0.0;
  return;
}

