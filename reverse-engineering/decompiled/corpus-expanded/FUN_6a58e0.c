/* Ghidra pseudocode, not original source.
 * ev_d0baaaa1d022e9a6bc644bf87cbac2e9d23f713faf88b9587519a457b813b0f8
 * Entry: 0x6a58e0; label: FUN_006a58e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006a58e0(int param_1,int param_2)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *unaff_EDI;
  
  iVar3 = unaff_EDI[9];
  iVar4 = 0;
  FUN_006a5740(param_1,iVar3,unaff_EDI[10]);
  iVar3 = (*(int *)unaff_EDI[5] - (iVar3 >> 1)) - unaff_EDI[7];
  if (1 < *unaff_EDI) {
    do {
      fVar1 = *(float *)(param_1 + iVar3 * 4);
      iVar2 = iVar3;
      if (*(float *)(unaff_EDI[1] + 0x20) < fVar1) {
        fVar1 = *(float *)(unaff_EDI[1] + 0x20);
      }
      while (iVar2 = iVar2 + 1,
            iVar2 <= (*(int *)(unaff_EDI[5] + 4 + iVar4 * 4) + *(int *)(unaff_EDI[5] + iVar4 * 4) >>
                     1) - unaff_EDI[7]) {
        iVar3 = iVar3 + 1;
        if (((-9999.0 < *(float *)(param_1 + iVar3 * 4)) &&
            (*(float *)(param_1 + iVar3 * 4) < fVar1)) || (fVar1 == -9999.0)) {
          fVar1 = *(float *)(param_1 + iVar3 * 4);
        }
      }
      iVar2 = unaff_EDI[7];
      if (iVar4 < *unaff_EDI) {
        do {
          if (iVar2 + iVar3 < *(int *)(unaff_EDI[5] + iVar4 * 4)) break;
          if (*(float *)(param_2 + iVar4 * 4) < fVar1) {
            *(float *)(param_2 + iVar4 * 4) = fVar1;
          }
          iVar4 = iVar4 + 1;
        } while (iVar4 < *unaff_EDI);
      }
    } while (iVar4 + 1 < *unaff_EDI);
  }
  fVar1 = *(float *)(param_1 + -4 + unaff_EDI[10] * 4);
  if (iVar4 < *unaff_EDI) {
    do {
      if (*(float *)(param_2 + iVar4 * 4) < fVar1) {
        *(float *)(param_2 + iVar4 * 4) = fVar1;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < *unaff_EDI);
  }
  return;
}

