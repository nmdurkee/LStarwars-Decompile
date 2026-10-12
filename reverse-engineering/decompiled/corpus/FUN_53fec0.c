/* Ghidra analysis pseudocode, not original source.
 * ev_3c859e02b972a8e60701cf54913e5d4895bfb87c225b3b379a359b744e8ff688
 * Entry: 0x53fec0; label: FUN_0053fec0
 */

void FUN_0053fec0(undefined4 param_1)

{
  float fVar1;
  float10 fVar2;
  
  fVar2 = (float10)FUN_004f8100(param_1);
  fVar1 = (float)fVar2;
  *(ushort *)(DAT_029838fc + 0x68) = *(ushort *)(DAT_029838fc + 0x68) | 0x80;
  *(float *)(DAT_029838fc + 0x9c) = fVar1;
  *(float *)(DAT_029838fc + 0xa0) = fVar1;
  *(float *)(DAT_029838fc + 0xa4) = fVar1;
  return;
}

