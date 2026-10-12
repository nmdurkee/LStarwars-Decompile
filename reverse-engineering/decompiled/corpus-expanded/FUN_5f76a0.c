/* Ghidra pseudocode, not original source.
 * ev_051ca52d2d0f5927e6fa186b1b96c133d3b61d010079a76ac2917bb13fe5eb00
 * Entry: 0x5f76a0; label: FUN_005f76a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005f76a0(float *param_1)

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
  float *in_EAX;
  float *in_ECX;
  
  fVar1 = in_EAX[4];
  fVar2 = in_ECX[1];
  fVar3 = *in_ECX;
  fVar4 = *in_EAX;
  fVar5 = in_EAX[8];
  fVar6 = in_ECX[2];
  fVar7 = in_EAX[1];
  fVar8 = *in_ECX;
  fVar9 = in_EAX[5];
  fVar10 = in_ECX[1];
  fVar11 = in_EAX[9];
  fVar12 = in_ECX[2];
  param_1[2] = in_EAX[10] * in_ECX[2] + in_EAX[6] * in_ECX[1] + in_EAX[2] * *in_ECX;
  *param_1 = fVar5 * fVar6 + fVar3 * fVar4 + fVar1 * fVar2;
  param_1[1] = fVar11 * fVar12 + fVar9 * fVar10 + fVar7 * fVar8;
  return;
}

