/* Ghidra analysis pseudocode, not original source.
 * ev_7ed3362792c3ecc1c7f2b3fdd5b033605c88aa142786b47e04128bf45777c493
 * Entry: 0x6b9680; label: FUN_006b9680
 */

void FUN_006b9680(int param_1,float param_2,float param_3)

{
  float fVar1;
  char cVar2;
  float fVar3;
  int in_ECX;
  
  if (param_2 == 0.0) {
    cVar2 = *(char *)(param_1 + 0x50 + in_ECX);
    *(undefined1 *)(param_1 + 0x50 + in_ECX) = 0;
    *(bool *)(param_1 + 0xa0 + in_ECX) = cVar2 != '\0';
    *(float *)(in_ECX + 0x118 + param_1 * 4) = param_2;
    *(undefined4 *)(in_ECX + 0x1b8 + param_1 * 4) = 0;
    return;
  }
  cVar2 = *(char *)(param_1 + 0x50 + in_ECX);
  *(undefined1 *)(param_1 + 0x50 + in_ECX) = 1;
  *(bool *)(param_1 + 0x78 + in_ECX) = cVar2 == '\0';
  *(float *)(in_ECX + 0x118 + param_1 * 4) = param_2;
  fVar1 = *(float *)(in_ECX + 0x1b8 + param_1 * 4);
  fVar3 = *(float *)(in_ECX + 0x4c) + *(float *)(in_ECX + 0x48);
  if ((NAN(fVar3) || NAN(fVar1)) || fVar3 < fVar1 == (fVar3 == fVar1)) {
    if (*(float *)(in_ECX + 0x1b8 + param_1 * 4) != 0.0) goto LAB_006b96e9;
  }
  else {
    *(undefined4 *)(in_ECX + 0x1b8 + param_1 * 4) = *(undefined4 *)(in_ECX + 0x48);
  }
  *(undefined1 *)(param_1 + 200 + in_ECX) = 1;
LAB_006b96e9:
  *(float *)(in_ECX + 0x1b8 + param_1 * 4) = *(float *)(in_ECX + 0x1b8 + param_1 * 4) + param_3;
  return;
}

