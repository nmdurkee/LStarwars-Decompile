/* Ghidra analysis pseudocode, not original source.
 * ev_df641eda8072cee71ca3b2626b4685e3428f565924a572e6fdc3ba5eae4c5d68
 * Entry: 0x57cb10; label: FUN_0057cb10
 */

void FUN_0057cb10(void)

{
  float fVar1;
  uint uVar2;
  int unaff_EDI;
  
  if (((*(int *)(unaff_EDI + 0x148) != -1) &&
      (uVar2 = 1 << ((byte)*(int *)(unaff_EDI + 0x148) & 0x1f), (DAT_0093b0e4 & uVar2) == 0)) &&
     (fVar1 = *(float *)(*(int *)(unaff_EDI + 4) + 0x90),
     *(float *)(unaff_EDI + 0x144) < fVar1 != (*(float *)(unaff_EDI + 0x144) == fVar1))) {
    DAT_0093b0e4 = DAT_0093b0e4 | uVar2;
  }
  if (((*(int *)(unaff_EDI + 0x150) != -1) &&
      (uVar2 = 1 << ((byte)*(int *)(unaff_EDI + 0x150) & 0x1f), (DAT_0093b0e4 & uVar2) == 0)) &&
     (fVar1 = *(float *)(*(int *)(unaff_EDI + 4) + 0x90),
     *(float *)(unaff_EDI + 0x14c) < fVar1 != (*(float *)(unaff_EDI + 0x14c) == fVar1))) {
    DAT_0093b0e4 = DAT_0093b0e4 | uVar2;
  }
  if (((*(int *)(unaff_EDI + 0x158) != -1) &&
      (uVar2 = 1 << ((byte)*(int *)(unaff_EDI + 0x158) & 0x1f), (DAT_0093b0e4 & uVar2) == 0)) &&
     (fVar1 = *(float *)(*(int *)(unaff_EDI + 4) + 0x90),
     *(float *)(unaff_EDI + 0x154) < fVar1 != (*(float *)(unaff_EDI + 0x154) == fVar1))) {
    DAT_0093b0e4 = DAT_0093b0e4 | uVar2;
  }
  if (((*(int *)(unaff_EDI + 0x160) != -1) &&
      (uVar2 = 1 << ((byte)*(int *)(unaff_EDI + 0x160) & 0x1f), (DAT_0093b0e4 & uVar2) == 0)) &&
     (fVar1 = *(float *)(*(int *)(unaff_EDI + 4) + 0x90),
     *(float *)(unaff_EDI + 0x15c) < fVar1 != (*(float *)(unaff_EDI + 0x15c) == fVar1))) {
    DAT_0093b0e4 = DAT_0093b0e4 | uVar2;
  }
  return;
}

