/* Ghidra analysis pseudocode, not original source.
 * ev_3c859e02b972a8e60701cf54913e5d4895bfb87c225b3b379a359b744e8ff688
 * Entry: 0x53fd40; label: FUN_0053fd40
 */

void FUN_0053fd40(undefined4 param_1)

{
  float fVar1;
  float10 fVar2;
  
  fVar2 = (float10)FUN_004f8100(param_1);
  fVar1 = (float)fVar2;
  *(float *)(DAT_029838fc + 0xc0) = fVar1;
  *(float *)(DAT_029838fc + 0xbc) = fVar1;
  *(float *)(DAT_029838fc + 0xb8) = fVar1;
  return;
}

