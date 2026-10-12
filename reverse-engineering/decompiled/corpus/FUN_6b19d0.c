/* Ghidra analysis pseudocode, not original source.
 * ev_648e39c5173022307384bd96b6b6d54b0109fbb7542fd197fe89208a1a87d4a6
 * Entry: 0x6b19d0; label: FUN_006b19d0
 */

void FUN_006b19d0(undefined4 *param_1,int param_2,int param_3,uint param_4,int param_5,uint param_6)

{
  float fVar1;
  undefined *puVar2;
  undefined *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  float *pfVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  float *pfVar11;
  int iVar12;
  int iVar13;
  undefined4 *puVar14;
  
  param_4 = -(uint)(param_5 != 0) & param_4;
  param_6 = -(uint)(param_5 != 0) & param_6;
  puVar2 = (&PTR_DAT_0081efd8)[*(int *)(param_2 + param_6 * 4)];
  puVar3 = (&PTR_DAT_0081efd8)[*(int *)(param_2 + param_4 * 4)];
  iVar4 = *(int *)(param_3 + param_4 * 4);
  iVar9 = *(int *)(param_3 + param_5 * 4);
  iVar13 = *(int *)(param_3 + param_6 * 4);
  iVar8 = (int)(iVar9 + (iVar9 >> 0x1f & 3U)) >> 2;
  iVar10 = iVar8 - ((int)(iVar4 + (iVar4 >> 0x1f & 3U)) >> 2);
  iVar8 = (iVar9 / 2 - ((int)(iVar13 + (iVar13 >> 0x1f & 3U)) >> 2)) + iVar8;
  iVar12 = iVar4 / 2 + iVar10;
  iVar4 = iVar13 / 2 + iVar8;
  iVar5 = 0;
  iVar6 = iVar10;
  puVar14 = param_1;
  if (0 < iVar10) {
    for (; iVar5 = iVar10, iVar6 != 0; iVar6 = iVar6 + -1) {
      *puVar14 = 0;
      puVar14 = puVar14 + 1;
    }
  }
  param_2 = 0;
  if (3 < iVar12 - iVar5) {
    iVar10 = ((iVar12 - iVar5) - 4U >> 2) + 1;
    iVar6 = iVar5 + 2;
    param_2 = iVar10 * 4;
    iVar5 = iVar5 + param_2;
    pfVar7 = (float *)(param_1 + iVar6);
    pfVar11 = (float *)(puVar3 + 8);
    do {
      iVar10 = iVar10 + -1;
      pfVar7[-2] = pfVar11[-2] * pfVar7[-2];
      pfVar7[-1] = pfVar11[-1] * pfVar7[-1];
      *pfVar7 = *pfVar7 * *pfVar11;
      pfVar7[1] = pfVar11[1] * pfVar7[1];
      pfVar7 = pfVar7 + 4;
      pfVar11 = pfVar11 + 4;
    } while (iVar10 != 0);
  }
  if (iVar5 < iVar12) {
    pfVar7 = (float *)(puVar3 + param_2 * 4);
    do {
      fVar1 = *pfVar7;
      iVar6 = iVar5 + 1;
      pfVar7 = pfVar7 + 1;
      param_1[iVar5] = fVar1 * (float)param_1[iVar5];
      iVar5 = iVar6;
    } while (iVar6 < iVar12);
  }
  iVar13 = iVar13 / 2 + -1;
  if (3 < iVar4 - iVar8) {
    iVar10 = ((iVar4 - iVar8) - 4U >> 2) + 1;
    iVar6 = iVar8 + 2;
    iVar5 = iVar13 * 4;
    iVar8 = iVar8 + iVar10 * 4;
    iVar13 = iVar13 + iVar10 * -4;
    pfVar7 = (float *)(param_1 + iVar6);
    pfVar11 = (float *)(puVar2 + iVar5 + -8);
    do {
      iVar10 = iVar10 + -1;
      pfVar7[-2] = pfVar11[2] * pfVar7[-2];
      pfVar7[-1] = pfVar11[1] * pfVar7[-1];
      *pfVar7 = *pfVar7 * *pfVar11;
      pfVar7[1] = pfVar11[-1] * pfVar7[1];
      pfVar7 = pfVar7 + 4;
      pfVar11 = pfVar11 + -4;
    } while (iVar10 != 0);
  }
  if (iVar8 < iVar4) {
    pfVar7 = (float *)(puVar2 + iVar13 * 4);
    iVar13 = iVar8;
    do {
      fVar1 = *pfVar7;
      iVar8 = iVar13 + 1;
      pfVar7 = pfVar7 + -1;
      param_1[iVar13] = fVar1 * (float)param_1[iVar13];
      iVar13 = iVar8;
    } while (iVar8 < iVar4);
  }
  if (iVar8 < iVar9) {
    puVar14 = param_1 + iVar8;
    for (iVar9 = iVar9 - iVar8; iVar9 != 0; iVar9 = iVar9 + -1) {
      *puVar14 = 0;
      puVar14 = puVar14 + 1;
    }
  }
  return;
}

