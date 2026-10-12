/* Ghidra analysis pseudocode, not original source.
 * ev_411dd83ba30300d5831318e5e0d5db9024421d970d639e52cbaaaf14146f88dc
 * Entry: 0x6a6f80; label: FUN_006a6f80
 */

void FUN_006a6f80(float param_1,float param_2)

{
  float fVar1;
  float fVar2;
  float *in_ECX;
  float *in_EDX;
  int iVar3;
  
  iVar3 = (uint)(ABS(*in_ECX) < ABS(*in_EDX)) - (uint)(ABS(*in_EDX) < ABS(*in_ECX));
  if (iVar3 == 0) {
    iVar3 = (uint)(ABS(param_2) < ABS(param_1)) * 2 + -1;
  }
  if (iVar3 == 1) {
    if (*in_EDX <= 0.0) {
      *in_ECX = *in_ECX - *in_EDX;
    }
    else {
      *in_ECX = *in_EDX - *in_ECX;
    }
  }
  else {
    fVar1 = *in_ECX;
    if (*in_ECX <= 0.0) {
      fVar2 = *in_ECX - *in_EDX;
    }
    else {
      fVar2 = *in_EDX - *in_ECX;
    }
    *in_ECX = fVar2;
    *in_EDX = fVar1;
  }
  if (ABS(*in_EDX) * 1.9999 < *in_ECX) {
    *in_ECX = ABS(*in_EDX) * -2.0;
    *in_EDX = -*in_EDX;
    return;
  }
  return;
}

