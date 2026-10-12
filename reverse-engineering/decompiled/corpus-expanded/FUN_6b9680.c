/* Ghidra pseudocode, not original source.
 * ev_53ad6b1d8bb34752a747640de0a0339f355d943428ba011e4ade8e8202156388
 * Entry: 0x6b9680; label: FUN_006b9680
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

