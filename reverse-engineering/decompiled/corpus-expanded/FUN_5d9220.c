/* Ghidra pseudocode, not original source.
 * ev_bd8f422ab2bc288e381e81a075ad63116995ee03e48e3608bccd82f55c6aad54
 * Entry: 0x5d9220; label: FUN_005d9220
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005d9220(void)

{
  float fVar1;
  int in_EAX;
  int iVar2;
  float *pfVar3;
  float *in_ECX;
  short sVar4;
  
  sVar4 = 0;
  if (*(byte *)(in_EAX + 0xe) != 0) {
    iVar2 = 0;
    do {
      pfVar3 = (float *)(iVar2 * 0x10 + *(int *)(in_EAX + 4));
      fVar1 = pfVar3[2] * in_ECX[2] +
              *pfVar3 * *in_ECX + *(float *)(iVar2 * 0x10 + 4 + *(int *)(in_EAX + 4)) * in_ECX[1] +
              pfVar3[3];
      if (0.0 < fVar1) break;
      sVar4 = sVar4 + 1;
      iVar2 = (int)sVar4;
    } while (iVar2 < (int)(uint)*(byte *)(in_EAX + 0xe));
    if (fVar1 < 0.0 == (fVar1 == 0.0)) {
      return 0;
    }
  }
  return 1;
}

