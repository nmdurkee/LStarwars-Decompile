/* Ghidra analysis pseudocode, not original source.
 * ev_3de2cf7b8df928d729538760151df11dfb76bb55f80af3b4d4d063063f9aa6a2
 * Entry: 0x57af60; label: FUN_0057af60
 */

void FUN_0057af60(undefined4 param_1)

{
  int iVar1;
  float10 fVar2;
  
  fVar2 = (float10)FUN_004f8100(param_1);
  iVar1 = DAT_00951c4c;
  *(uint *)(DAT_00951c4c + 0x50) = *(uint *)(DAT_00951c4c + 0x50) | 0x80;
  *(float *)(iVar1 + 100) = (float)fVar2;
  return;
}

