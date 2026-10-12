/* Ghidra analysis pseudocode, not original source.
 * ev_6ec8aea645f94e3276e7ac0037e639f8d50e0230e3ad74bacc489d09a6610266
 * Entry: 0x5b3920; label: FUN_005b3920
 */

void FUN_005b3920(float *param_1,float *param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  
  fVar1 = *param_3;
  fVar2 = param_2[2];
  fVar3 = param_3[2];
  fVar4 = *param_2;
  fVar5 = *param_2;
  fVar6 = param_3[1];
  fVar7 = param_2[1];
  fVar8 = *param_3;
  *param_1 = param_2[1] * param_3[2] - param_2[2] * param_3[1];
  param_1[1] = fVar1 * fVar2 - fVar3 * fVar4;
  param_1[2] = fVar5 * fVar6 - fVar7 * fVar8;
  return;
}

