/* Ghidra pseudocode, not original source.
 * ev_6d95b912f1db8f5f9ae5a1d448774b8e294221a9d492d15be8ca5acea434db46
 * Entry: 0x482e30; label: FUN_00482e30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00482e30(void)

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

