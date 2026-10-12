/* Ghidra analysis pseudocode, not original source.
 * ev_b6d8a17c6b3263d4647da1f5b2d8de4c4a67e85657c53f6d05a13f18932cfd90
 * Entry: 0x5c1810; label: FUN_005c1810
 */

void FUN_005c1810(float *param_1,float param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float *in_ECX;
  float *in_EDX;
  
  fVar1 = in_ECX[1];
  fVar2 = in_ECX[2];
  fVar3 = in_ECX[3];
  fVar4 = in_EDX[1];
  fVar5 = in_EDX[2];
  fVar6 = in_EDX[3];
  *param_1 = (*in_EDX - *in_ECX) * param_2 + *in_ECX;
  param_1[1] = (fVar4 - fVar1) * param_2 + fVar1;
  param_1[2] = (fVar5 - fVar2) * param_2 + fVar2;
  param_1[3] = (fVar6 - fVar3) * param_2 + fVar3;
  return;
}

