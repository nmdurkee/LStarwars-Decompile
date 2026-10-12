/* Ghidra pseudocode, not original source.
 * ev_0b75f810defb69f43ff4ee181673bf6e816c7d4f879f3f967a03f199d8168922
 * Entry: 0x6af580; label: FUN_006af580
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006af580(void)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float *in_EAX;
  
  pfVar1 = in_EAX + 8;
  fVar2 = in_EAX[9];
  fVar3 = *in_EAX;
  fVar4 = *pfVar1;
  *pfVar1 = *pfVar1 + *in_EAX;
  in_EAX[9] = in_EAX[9] + in_EAX[1];
  *in_EAX = ((in_EAX[1] - fVar2) + (fVar3 - fVar4)) * 0.70710677;
  in_EAX[1] = ((in_EAX[1] - fVar2) - (fVar3 - fVar4)) * 0.70710677;
  fVar2 = in_EAX[0xb];
  fVar3 = in_EAX[10];
  fVar4 = in_EAX[2];
  in_EAX[10] = in_EAX[10] + in_EAX[2];
  in_EAX[0xb] = in_EAX[0xb] + in_EAX[3];
  in_EAX[2] = in_EAX[3] - fVar2;
  in_EAX[3] = fVar3 - fVar4;
  fVar2 = in_EAX[0xc];
  fVar3 = in_EAX[4];
  fVar4 = in_EAX[0xd];
  in_EAX[0xc] = in_EAX[0xc] + in_EAX[4];
  in_EAX[0xd] = in_EAX[0xd] + in_EAX[5];
  in_EAX[4] = ((fVar2 - fVar3) - (fVar4 - in_EAX[5])) * 0.70710677;
  in_EAX[5] = ((fVar4 - in_EAX[5]) + (fVar2 - fVar3)) * 0.70710677;
  fVar2 = in_EAX[0xe];
  fVar3 = in_EAX[0xf];
  in_EAX[0xe] = in_EAX[0xe] + in_EAX[6];
  in_EAX[0xf] = in_EAX[0xf] + in_EAX[7];
  in_EAX[6] = fVar2 - in_EAX[6];
  in_EAX[7] = fVar3 - in_EAX[7];
  FUN_006af4d0();
  FUN_006af4d0();
  return;
}

