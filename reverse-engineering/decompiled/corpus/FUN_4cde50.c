/* Ghidra analysis pseudocode, not original source.
 * ev_074dd20869da91b1b05b19bd1efa0509a9d09e9660d7c7c0c7ca47d053bd121c
 * Entry: 0x4cde50; label: FUN_004cde50
 */

void FUN_004cde50(undefined4 param_1)

{
  int iVar1;
  float10 fVar2;
  
  fVar2 = (float10)FUN_004f8100(param_1);
  iVar1 = DAT_00880608;
  *(ushort *)(DAT_00880608 + 0x4c) = *(ushort *)(DAT_00880608 + 0x4c) | 2;
  *(float *)(iVar1 + 0x48) = (float)fVar2 * (float)fVar2;
  return;
}

