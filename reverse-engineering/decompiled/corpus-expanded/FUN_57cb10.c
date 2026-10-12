/* Ghidra pseudocode, not original source.
 * ev_608779b64e90f57b93ecbf13df65bed39f2d483d8cb24d2405739ebf49354e95
 * Entry: 0x57cb10; label: FUN_0057cb10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

