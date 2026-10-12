/* Ghidra analysis pseudocode, not original source.
 * ev_d6cfc7f984a94bc477afc350e10de4c03e30e64e3e924293972bd20ad72e1aa6
 * Entry: 0x4c0f70; label: FUN_004c0f70
 */

void FUN_004c0f70(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float *in_EAX;
  int in_ECX;
  
  fVar1 = (float)(&DAT_029899a0)[in_ECX + 0x4000 >> 1 & 0x7fff];
  fVar2 = (float)(&DAT_029899a0)[in_ECX >> 1 & 0x7fff];
  fVar3 = *in_EAX;
  fVar4 = in_EAX[4];
  fVar5 = in_EAX[8];
  fVar6 = in_EAX[0xc];
  *in_EAX = fVar1 * fVar3 - fVar2 * in_EAX[1];
  in_EAX[1] = fVar1 * in_EAX[1] + fVar2 * fVar3;
  in_EAX[4] = fVar4 * fVar1 - in_EAX[5] * fVar2;
  in_EAX[5] = in_EAX[5] * fVar1 + fVar2 * fVar4;
  in_EAX[8] = fVar5 * fVar1 - in_EAX[9] * fVar2;
  in_EAX[9] = in_EAX[9] * fVar1 + fVar2 * fVar5;
  in_EAX[0xc] = fVar6 * fVar1 - fVar2 * in_EAX[0xd];
  in_EAX[0xd] = fVar6 * fVar2 + in_EAX[0xd] * fVar1;
  return;
}

