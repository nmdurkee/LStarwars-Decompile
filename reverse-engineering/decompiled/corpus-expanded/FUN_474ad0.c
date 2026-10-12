/* Ghidra pseudocode, not original source.
 * ev_82e843d85b8a15ad0c2712a3dca0d893aca885ca51044f6184084df2488405d8
 * Entry: 0x474ad0; label: FUN_00474ad0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00474ad0(void)

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
  *in_EAX = fVar2 * in_EAX[2] + fVar1 * fVar3;
  in_EAX[2] = fVar1 * in_EAX[2] - fVar2 * fVar3;
  in_EAX[4] = fVar4 * fVar1 + in_EAX[6] * fVar2;
  in_EAX[6] = in_EAX[6] * fVar1 - fVar2 * fVar4;
  in_EAX[8] = fVar2 * in_EAX[10] + fVar5 * fVar1;
  in_EAX[10] = fVar1 * in_EAX[10] - fVar2 * fVar5;
  in_EAX[0xc] = fVar6 * fVar1 + in_EAX[0xe] * fVar2;
  in_EAX[0xe] = in_EAX[0xe] * fVar1 - fVar6 * fVar2;
  return;
}

