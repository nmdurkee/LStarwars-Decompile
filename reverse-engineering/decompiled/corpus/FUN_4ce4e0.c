/* Ghidra analysis pseudocode, not original source.
 * ev_074dd20869da91b1b05b19bd1efa0509a9d09e9660d7c7c0c7ca47d053bd121c
 * Entry: 0x4ce4e0; label: FUN_004ce4e0
 */

void FUN_004ce4e0(int param_1)

{
  int iVar1;
  int unaff_ESI;
  int unaff_EDI;
  float10 fVar2;
  float10 fVar3;
  
  if (*(int *)(*(int *)(*(int *)(unaff_ESI + 0x50) + 0xc) + *(short *)(unaff_ESI + 0x7aa) * 4) != 0)
  {
    fVar2 = (float10)FUN_0062f1c0(*(int *)(unaff_ESI + 0x50),(int)*(short *)(unaff_ESI + 0x7aa));
    if ((float)fVar2 != 0.0) {
      iVar1 = *(int *)(*(int *)(*(int *)(unaff_ESI + 0x798) + 0x40) + 8);
      fVar3 = (float10)FUN_005bed80(iVar1 + param_1 * 0xc,iVar1 + unaff_EDI * 0xc,0);
      *(float *)(unaff_ESI + 0x784) = (float)(fVar3 / (float10)ABS((float)fVar2));
      return;
    }
  }
  if ((*(byte *)(*(int *)(unaff_ESI + 0x798) + 0x4c) & 4) == 0) {
    *(undefined4 *)(unaff_ESI + 0x784) = 0x3f800000;
    return;
  }
  *(undefined4 *)(unaff_ESI + 0x784) = 0x40400000;
  return;
}

