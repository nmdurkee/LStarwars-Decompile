/* Ghidra analysis pseudocode, not original source.
 * ev_b277bc71922b23f31a72f43f26143bcec8a2b6e78604417b28dcc98660b92d0f
 * Entry: 0x53fc60; label: FUN_0053fc60
 */

void FUN_0053fc60(undefined4 param_1)

{
  float10 fVar1;
  
  fVar1 = (float10)FUN_004f8100(param_1);
  *(float *)(DAT_029838fc + 0xa8) = (float)fVar1;
  fVar1 = (float10)FUN_004f8100(param_1);
  *(float *)(DAT_029838fc + 0xac) = (float)fVar1;
  fVar1 = (float10)FUN_004f8100(param_1);
  *(float *)(DAT_029838fc + 0xb0) = (float)fVar1;
  return;
}

