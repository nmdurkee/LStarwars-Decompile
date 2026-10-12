/* Ghidra pseudocode, not original source.
 * ev_d0baaaa1d022e9a6bc644bf87cbac2e9d23f713faf88b9587519a457b813b0f8
 * Entry: 0x6a5490; label: FUN_006a5490
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006a5490(int param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5)

{
  float fVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  float *pfVar7;
  int unaff_EDI;
  float10 extraout_ST0;
  
  uVar3 = FUN_006e6b90();
  uVar3 = uVar3 & ((int)uVar3 < 1) - 1;
  if (6 < (int)uVar3) {
    uVar3 = 7;
  }
  iVar2 = *(int *)(param_1 + uVar3 * 4);
  iVar4 = FUN_006e6b90();
  iVar5 = FUN_006e6b90();
  iVar6 = FUN_006e6b90();
  if (3 < iVar4 - iVar6) {
    pfVar7 = (float *)(iVar2 + 0x10 + iVar6 * 4);
    do {
      if ((0 < iVar5) &&
         (*(float *)(unaff_EDI + iVar5 * 4) < (float)((float10)pfVar7[-2] + extraout_ST0))) {
        *(float *)(unaff_EDI + iVar5 * 4) = (float)((float10)pfVar7[-2] + extraout_ST0);
      }
      iVar5 = iVar5 + param_5;
      if (param_4 <= iVar5) {
        return;
      }
      if ((0 < iVar5) &&
         (*(float *)(unaff_EDI + iVar5 * 4) < (float)((float10)pfVar7[-1] + extraout_ST0))) {
        *(float *)(unaff_EDI + iVar5 * 4) = (float)((float10)pfVar7[-1] + extraout_ST0);
      }
      iVar5 = iVar5 + param_5;
      if (param_4 <= iVar5) {
        return;
      }
      if ((0 < iVar5) &&
         (*(float *)(unaff_EDI + iVar5 * 4) < (float)((float10)*pfVar7 + extraout_ST0))) {
        *(float *)(unaff_EDI + iVar5 * 4) = (float)((float10)*pfVar7 + extraout_ST0);
      }
      iVar5 = iVar5 + param_5;
      if (param_4 <= iVar5) {
        return;
      }
      if ((0 < iVar5) &&
         (*(float *)(unaff_EDI + iVar5 * 4) < (float)((float10)pfVar7[1] + extraout_ST0))) {
        *(float *)(unaff_EDI + iVar5 * 4) = (float)((float10)pfVar7[1] + extraout_ST0);
      }
      iVar5 = iVar5 + param_5;
      if (param_4 <= iVar5) {
        return;
      }
      iVar6 = iVar6 + 4;
      pfVar7 = pfVar7 + 4;
    } while (iVar6 < iVar4 + -3);
  }
  while( true ) {
    if (iVar4 <= iVar6) {
      return;
    }
    if ((0 < iVar5) &&
       (fVar1 = (float)((float10)*(float *)(iVar2 + 8 + iVar6 * 4) + extraout_ST0),
       *(float *)(unaff_EDI + iVar5 * 4) < fVar1)) {
      *(float *)(unaff_EDI + iVar5 * 4) = fVar1;
    }
    iVar5 = iVar5 + param_5;
    if (param_4 <= iVar5) break;
    iVar6 = iVar6 + 1;
  }
  return;
}

