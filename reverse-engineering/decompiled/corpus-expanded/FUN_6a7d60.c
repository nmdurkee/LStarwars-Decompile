/* Ghidra pseudocode, not original source.
 * ev_9aa9869018ecc20f1423d5d8d6944da52d455e1cf8e536d99f80bf4f445d14b5
 * Entry: 0x6a7d60; label: FUN_006a7d60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006a7d60(int param_1,int *param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  int iVar6;
  float *pfVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  
  iVar1 = *param_2;
  iVar5 = FUN_006e6b90();
  iVar2 = *(int *)(param_1 + 0xa0 + *(int *)param_2[1] * 0x3c);
  iVar10 = 0;
  if (0 < *(int *)(param_3 + 0x484)) {
    iVar6 = iVar1 - iVar2;
    do {
      iVar11 = iVar2;
      if (3 < iVar6) {
        fVar3 = (float)iVar6;
        fVar4 = (float)iVar5;
        iVar8 = ((iVar1 - iVar2) - 4U >> 2) + 1;
        param_1 = 2;
        iVar11 = iVar2 + iVar8 * 4;
        pfVar7 = (float *)(*(int *)(param_4 + iVar10 * 4) + 8 + iVar2 * 4);
        do {
          iVar8 = iVar8 + -1;
          pfVar7[-2] = (1.0 - ((float)(param_1 + -2) / fVar3) * fVar4) * pfVar7[-2];
          pfVar7[-1] = (1.0 - ((float)(param_1 + -1) / fVar3) * fVar4) * pfVar7[-1];
          *pfVar7 = (1.0 - ((float)param_1 / fVar3) * fVar4) * *pfVar7;
          pfVar7[1] = (1.0 - ((float)(param_1 + 1) / fVar3) * fVar4) * pfVar7[1];
          pfVar7 = pfVar7 + 4;
          param_1 = param_1 + 4;
        } while (iVar8 != 0);
      }
      if (iVar11 < iVar1) {
        iVar8 = iVar11 - iVar2;
        iVar9 = iVar1 - iVar11;
        pfVar7 = (float *)(*(int *)(param_4 + iVar10 * 4) + iVar11 * 4);
        do {
          fVar3 = (float)iVar8;
          iVar8 = iVar8 + 1;
          iVar9 = iVar9 + -1;
          *pfVar7 = (1.0 - (fVar3 / (float)iVar6) * (float)iVar5) * *pfVar7;
          pfVar7 = pfVar7 + 1;
        } while (iVar9 != 0);
      }
      iVar10 = iVar10 + 1;
    } while (iVar10 < *(int *)(param_3 + 0x484));
  }
  return;
}

