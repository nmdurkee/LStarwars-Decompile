/* Ghidra pseudocode, not original source.
 * ev_f814ac66c7176acc11aba85969a47ad0d72f6a74214126b9ee26f1e14042bc0b
 * Entry: 0x5c1880; label: FUN_005c1880
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005c1880(float *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float *in_ECX;
  float *in_EDX;
  
  fVar1 = *in_EDX;
  fVar2 = in_EDX[1];
  fVar3 = in_EDX[2];
  fVar4 = in_EDX[3];
  fVar5 = *in_ECX;
  fVar6 = in_ECX[1];
  fVar7 = in_ECX[2];
  fVar8 = in_ECX[3];
  *param_1 = (fVar4 * fVar5 + fVar3 * fVar6 + fVar1 * fVar8) - fVar2 * fVar7;
  param_1[1] = (fVar1 * fVar7 + fVar4 * fVar6 + fVar2 * fVar8) - fVar3 * fVar5;
  param_1[2] = (fVar2 * fVar5 + fVar3 * fVar8 + fVar4 * fVar7) - fVar1 * fVar6;
  param_1[3] = ((0.0 - fVar1 * fVar5) + (0.0 - fVar2 * fVar6) + (0.0 - fVar3 * fVar7)) -
               (0.0 - fVar4 * fVar8);
  return;
}

