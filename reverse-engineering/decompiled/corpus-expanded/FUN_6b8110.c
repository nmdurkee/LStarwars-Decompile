/* Ghidra pseudocode, not original source.
 * ev_4ce08863d5da0fee7b6d57af0905edeb9afe2ef672ddcc937a67468fc554aef4
 * Entry: 0x6b8110; label: FUN_006b8110
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006b8110(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  int in_EAX;
  int in_ECX;
  
  fVar1 = (float)(&DAT_029899a0)[in_ECX + 0x4000 >> 1 & 0x7fff];
  fVar2 = (float)(&DAT_029899a0)[in_ECX >> 1 & 0x7fff];
  fVar3 = *(float *)(in_EAX + 4);
  fVar4 = *(float *)(in_EAX + 0x14);
  fVar5 = *(float *)(in_EAX + 0x24);
  fVar6 = *(float *)(in_EAX + 0x34);
  *(float *)(in_EAX + 4) = fVar1 * fVar3 - fVar2 * *(float *)(in_EAX + 8);
  *(float *)(in_EAX + 8) = *(float *)(in_EAX + 8) * fVar1 + fVar2 * fVar3;
  *(float *)(in_EAX + 0x14) = fVar4 * fVar1 - *(float *)(in_EAX + 0x18) * fVar2;
  *(float *)(in_EAX + 0x18) = *(float *)(in_EAX + 0x18) * fVar1 + fVar2 * fVar4;
  *(float *)(in_EAX + 0x24) = fVar5 * fVar1 - fVar2 * *(float *)(in_EAX + 0x28);
  *(float *)(in_EAX + 0x28) = fVar1 * *(float *)(in_EAX + 0x28) + fVar5 * fVar2;
  *(float *)(in_EAX + 0x34) = fVar6 * fVar1 - *(float *)(in_EAX + 0x38) * fVar2;
  *(float *)(in_EAX + 0x38) = fVar6 * fVar2 + *(float *)(in_EAX + 0x38) * fVar1;
  return;
}

