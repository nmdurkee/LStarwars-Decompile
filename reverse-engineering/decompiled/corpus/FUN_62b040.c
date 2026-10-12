/* Ghidra analysis pseudocode, not original source.
 * ev_93d7dcfdde9a808337523cfea9e371187d945893e914ed56ca2b2926a7aff66e
 * Entry: 0x62b040; label: FUN_0062b040
 */

void FUN_0062b040(int param_1)

{
  float fVar1;
  float10 fVar2;
  float10 fVar3;
  
  if ((*(float *)(param_1 + 0x68) == 0.0) && (*(float *)(param_1 + 0x70) == 0.0)) {
    *(undefined4 *)(param_1 + 0x22c) = 0;
    *(uint *)(param_1 + 0x228) = *(uint *)(param_1 + 0x6c) & 0x7fffffff;
    return;
  }
  fVar1 = *(float *)(param_1 + 0x68) * *(float *)(param_1 + 0x68) +
          *(float *)(param_1 + 0x70) * *(float *)(param_1 + 0x70);
  fVar2 = (float10)FUN_005c0240(fVar1);
  fVar3 = (float10)(float)fVar2;
  *(float *)(param_1 + 0x22c) = (float)fVar2;
  if (*(float *)(param_1 + 0x6c) != 0.0) {
    fVar3 = (float10)FUN_005c0240(*(float *)(param_1 + 0x6c) * *(float *)(param_1 + 0x6c) + fVar1);
  }
  *(float *)(param_1 + 0x228) = (float)fVar3;
  return;
}

