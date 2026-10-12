/* Ghidra pseudocode, not original source.
 * ev_6c7022c87010c6d39f3f3226e46062ec65b94628332be136b3f738ab843f9afe
 * Entry: 0x4ce4e0; label: FUN_004ce4e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

