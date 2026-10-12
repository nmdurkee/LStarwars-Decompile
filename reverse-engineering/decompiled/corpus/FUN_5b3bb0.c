/* Ghidra analysis pseudocode, not original source.
 * ev_6ec8aea645f94e3276e7ac0037e639f8d50e0230e3ad74bacc489d09a6610266
 * Entry: 0x5b3bb0; label: FUN_005b3bb0
 */

void FUN_005b3bb0(float *param_1,float *param_2,float *param_3,float *param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  
  fVar1 = *param_2;
  fVar2 = *param_3;
  fVar3 = param_2[1];
  fVar4 = param_3[1];
  fVar5 = param_2[2];
  fVar6 = param_3[2];
  fVar7 = *param_2;
  fVar8 = *param_4;
  fVar9 = param_2[1];
  fVar10 = param_4[1];
  fVar11 = param_2[2];
  fVar12 = param_4[2];
  *param_1 = (fVar5 - fVar6) * (fVar9 - fVar10) - (fVar3 - fVar4) * (fVar11 - fVar12);
  param_1[1] = (fVar1 - fVar2) * (fVar11 - fVar12) - (fVar7 - fVar8) * (fVar5 - fVar6);
  param_1[2] = (fVar7 - fVar8) * (fVar3 - fVar4) - (fVar1 - fVar2) * (fVar9 - fVar10);
  FUN_005b3b30(param_1,param_1);
  return;
}

