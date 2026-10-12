/* Ghidra analysis pseudocode, not original source.
 * ev_a0c592da085b7a74f005db934e1c866d8df8930552270784c21655c1c3dfc310
 * Entry: 0x6af4d0; label: FUN_006af4d0
 */

void FUN_006af4d0(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float *in_EAX;
  
  fVar1 = in_EAX[6];
  fVar2 = in_EAX[6];
  fVar3 = in_EAX[4];
  fVar4 = *in_EAX;
  in_EAX[6] = fVar1 + in_EAX[2] + *in_EAX + in_EAX[4];
  in_EAX[4] = (fVar1 + in_EAX[2]) - (*in_EAX + in_EAX[4]);
  fVar1 = in_EAX[3];
  *in_EAX = (in_EAX[5] - in_EAX[1]) + (fVar2 - in_EAX[2]);
  in_EAX[2] = (fVar2 - in_EAX[2]) - (in_EAX[5] - in_EAX[1]);
  fVar2 = in_EAX[1];
  fVar5 = in_EAX[7];
  fVar6 = in_EAX[3];
  in_EAX[3] = (in_EAX[7] - fVar1) + (fVar3 - fVar4);
  in_EAX[1] = (in_EAX[7] - fVar1) - (fVar3 - fVar4);
  in_EAX[7] = in_EAX[5] + fVar2 + fVar5 + fVar6;
  in_EAX[5] = (fVar5 + fVar6) - (in_EAX[5] + fVar2);
  return;
}

