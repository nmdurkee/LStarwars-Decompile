/* Ghidra analysis pseudocode, not original source.
 * ev_b277bc71922b23f31a72f43f26143bcec8a2b6e78604417b28dcc98660b92d0f
 * Entry: 0x53f990; label: FUN_0053f990
 */

void FUN_0053f990(undefined4 param_1)

{
  float fVar1;
  float10 fVar2;
  
  fVar2 = (float10)FUN_004f8100(param_1);
  fVar1 = (float)fVar2;
  if ((fVar1 < 0.0) || (fVar1 <= *(float *)(DAT_029838fc + 0x74))) {
    fVar1 = *(float *)(DAT_029838fc + 0x74);
  }
  *(float *)(DAT_029838fc + 0x78) = fVar1;
  return;
}

