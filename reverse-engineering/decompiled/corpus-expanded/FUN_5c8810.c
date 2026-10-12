/* Ghidra pseudocode, not original source.
 * ev_506f2ef4e11b68e7edff25e0427d0f13a0f8158f7d3b962ea2de52b74731d8d7
 * Entry: 0x5c8810; label: FUN_005c8810
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005c8810(float *param_1,float param_2,float param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  undefined4 uVar8;
  float *in_ECX;
  float *in_EDX;
  uint local_28;
  uint local_24;
  
  fVar1 = *in_EDX - *param_1;
  fVar2 = in_EDX[1] - param_1[1];
  fVar3 = in_EDX[2] - param_1[2];
  fVar4 = fVar2 * fVar2 + fVar1 * fVar1 + fVar3 * fVar3;
  fVar5 = *in_ECX - *param_1;
  fVar6 = in_ECX[1] - param_1[1];
  fVar7 = in_ECX[2] - param_1[2];
  fVar1 = fVar5 * fVar1 + fVar6 * fVar2 + fVar7 * fVar3;
  fVar2 = fVar1 * (1.0 / fVar4);
  local_28 = (uint)(0.0 < fVar2);
  fVar2 = fVar2 * (float)local_28;
  local_24 = (uint)(1.0 < fVar2);
  local_28 = (uint)(fVar2 < 1.0 != (fVar2 == 1.0));
  fVar2 = fVar2 * (float)local_28 + (float)local_24;
  fVar1 = (fVar6 * fVar6 + fVar5 * fVar5 + fVar7 * fVar7 + fVar2 * fVar2 * fVar4) -
          (fVar1 + fVar1) * fVar2;
  if ((param_3 + param_2) * (param_3 + param_2) < fVar1) {
    return 0;
  }
  uVar8 = 1;
  if ((param_2 - param_3) * (param_2 - param_3) <= fVar1) {
    uVar8 = 2;
  }
  return uVar8;
}

