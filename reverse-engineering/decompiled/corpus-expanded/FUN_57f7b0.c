/* Ghidra pseudocode, not original source.
 * ev_148a09dc694c3f4e6090ec8593a8f5c40e6398f75b0d17d245a3886ccb65c6ec
 * Entry: 0x57f7b0; label: FUN_0057f7b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0057f7b0(void)

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

