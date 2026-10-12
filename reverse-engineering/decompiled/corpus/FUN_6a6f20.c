/* Ghidra analysis pseudocode, not original source.
 * ev_411dd83ba30300d5831318e5e0d5db9024421d970d639e52cbaaaf14146f88dc
 * Entry: 0x6a6f20; label: FUN_006a6f20
 */

float10 FUN_006a6f20(float param_1,int param_2)

{
  int iVar1;
  float10 fVar2;
  
  iVar1 = *(int *)(*(int *)(param_2 + 4) + 0x1c);
  fVar2 = (float10)(((float)(*(int *)(iVar1 + *(int *)(param_2 + 0x28) * 4) / 2) /
                    (float)*(int *)(*(int *)(param_2 + 4) + 8)) * *(float *)(iVar1 + 0xb78) +
                   param_1);
  if (fVar2 < (float10)-9999.0) {
    return (float10)(float)(float10)-9999.0;
  }
  return fVar2;
}

