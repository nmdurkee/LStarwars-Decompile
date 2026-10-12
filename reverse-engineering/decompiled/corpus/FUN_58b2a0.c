/* Ghidra analysis pseudocode, not original source.
 * ev_ac6eb4b39bdf1aa97860dd7a32d700b8b6252d0c8ecf493d0278bc767f8ce849
 * Entry: 0x58b2a0; label: FUN_0058b2a0
 */

void FUN_0058b2a0(int param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
  if (*(char *)(param_1 + 0x7b7) == -1) {
    fVar1 = 0.0;
  }
  else {
    fVar1 = *(float *)(*(char *)(param_1 + 0x7b7) * 0x10 + 0xc + DAT_009553dc);
  }
  fVar2 = (float)(&DAT_029899a0)[(int)(*(ushort *)(param_1 + 0x5a) + 0x4000) >> 1 & 0x7fff];
  fVar3 = *(float *)(*(int *)(param_1 + 0x790) + 100);
  fVar4 = ((*(float *)(*(int *)(param_1 + 0x790) + 0x5c) -
           fVar1 * (float)(&DAT_029899a0)[*(ushort *)(param_1 + 0x5a) >> 1]) -
          *(float *)(param_1 + 0x5c)) * 10.0;
  *(float *)(param_1 + 0xf18) = fVar4;
  *(float *)(param_1 + 0x68) = fVar4;
  fVar1 = ((fVar3 - fVar2 * fVar1) - *(float *)(param_1 + 100)) * 10.0;
  *(float *)(param_1 + 0xf20) = fVar1;
  *(float *)(param_1 + 0x70) = fVar1;
  return;
}

