/* Ghidra pseudocode, not original source.
 * ev_5bc2cffe930f75cca3d7b3a74e2b00ef78f9b6b1aa332ee39fd35bfa060f9fa0
 * Entry: 0x6b1580; label: FUN_006b1580
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */

float10 FUN_006b1580(int param_1,int param_2,int param_3,int param_4)

{
  float fVar1;
  double dVar2;
  float10 fVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  double *pdVar7;
  float *pfVar8;
  float *pfVar9;
  double *pdVar10;
  float *pfVar11;
  uint uVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  uint uVar16;
  bool bVar17;
  float10 fVar18;
  float10 fVar19;
  int aiStack_30 [2];
  undefined8 uStack_28;
  uint local_10;
  double *local_c;
  double *local_8;
  
  uStack_28._4_4_ = 0x6b159b;
  iVar4 = -(param_4 * 8 + 8);
  local_c = (double *)(&stack0xffffffe0 + iVar4);
  *(undefined4 *)((int)&uStack_28 + iVar4 + 4) = 0x6b15a5;
  iVar5 = param_4 * -8;
  fVar3 = (float10)0;
  iVar14 = param_4 + 1;
  if (iVar14 != 0) {
    local_8 = (double *)(param_3 - iVar14);
    pfVar8 = (float *)(param_1 + 8 + iVar14 * 4);
    do {
      local_8 = (double *)((int)local_8 + 1);
      iVar14 = iVar14 + -1;
      pfVar8 = pfVar8 + -1;
      iVar13 = iVar14;
      fVar19 = fVar3;
      if (3 < (int)local_8) {
        iVar6 = ((param_3 - iVar14) - 4U >> 2) + 1;
        iVar13 = iVar14 + iVar6 * 4;
        pfVar9 = pfVar8;
        pfVar11 = (float *)(param_1 + 8);
        do {
          iVar6 = iVar6 + -1;
          fVar19 = (float10)pfVar11[1] * (float10)pfVar9[1] +
                   (float10)*pfVar11 * (float10)*pfVar9 +
                   (float10)pfVar11[-1] * (float10)pfVar9[-1] +
                   (float10)pfVar11[-2] * (float10)pfVar9[-2] + fVar19;
          pfVar9 = pfVar9 + 4;
          pfVar11 = pfVar11 + 4;
        } while (iVar6 != 0);
      }
      if (iVar13 < param_3) {
        pfVar9 = (float *)(param_1 + (iVar13 - iVar14) * 4);
        do {
          iVar6 = iVar13 * 4;
          iVar13 = iVar13 + 1;
          fVar1 = *pfVar9;
          pfVar9 = pfVar9 + 1;
          fVar19 = (float10)*(float *)(param_1 + iVar6) * (float10)fVar1 + fVar19;
        } while (iVar13 < param_3);
      }
      local_c[iVar14] = (double)fVar19;
    } while (iVar14 != 0);
  }
  fVar19 = (float10)*local_c;
  local_10 = 0;
  if (0 < param_4) {
    local_8 = local_c + -2;
    iVar14 = (iVar5 + iVar4) - (int)local_c;
    do {
      uVar16 = local_10;
      fVar18 = -(float10)local_8[3];
      if (fVar3 == fVar19) {
        *(int *)((int)&uStack_28 + iVar5 + iVar4 + 4) = param_4 * 4;
        *(undefined4 *)((int)&uStack_28 + iVar5 + iVar4) = 0;
        *(int *)((int)aiStack_30 + iVar5 + iVar4 + 4) = param_2;
        *(undefined4 *)((int)aiStack_30 + iVar5 + iVar4) = 0x6b1874;
        _memset(*(void **)((int)aiStack_30 + iVar5 + iVar4 + 4),
                *(int *)((int)&uStack_28 + iVar5 + iVar4),
                *(size_t *)((int)&uStack_28 + iVar5 + iVar4 + 4));
        return (float10)0;
      }
      iVar13 = 0;
      if (3 < (int)local_10) {
        iVar6 = (local_10 - 4 >> 2) + 1;
        iVar13 = iVar6 * 4;
        pdVar7 = (double *)((int)&local_10 + iVar5 + iVar4);
        pdVar10 = local_8;
        do {
          iVar6 = iVar6 + -1;
          fVar18 = (((fVar18 - (float10)pdVar10[2] * (float10)pdVar7[-2]) -
                    (float10)pdVar10[1] * (float10)pdVar7[-1]) -
                   (float10)*pdVar10 * (float10)*pdVar7) - (float10)pdVar10[-1] * (float10)pdVar7[1]
          ;
          pdVar7 = pdVar7 + 4;
          pdVar10 = pdVar10 + -4;
        } while (iVar6 != 0);
      }
      if (iVar13 < (int)local_10) {
        pdVar7 = local_c + (local_10 - iVar13);
        do {
          iVar6 = iVar13 * 8;
          iVar13 = iVar13 + 1;
          dVar2 = *pdVar7;
          pdVar7 = pdVar7 + -1;
          fVar18 = fVar18 - (float10)*(double *)(&stack0xffffffe0 + iVar6 + iVar5 + iVar4) *
                            (float10)dVar2;
        } while (iVar13 < (int)local_10);
      }
      fVar18 = fVar18 / fVar19;
      iVar6 = (int)local_10 / 2;
      iVar13 = 0;
      *(double *)(&stack0xffffffe0 + local_10 * 8 + iVar5 + iVar4) = (double)fVar18;
      if (3 < iVar6) {
        iVar15 = (iVar6 - 4U >> 2) + 1;
        iVar13 = iVar15 * 4;
        pdVar7 = (double *)((int)&local_10 + iVar5 + iVar4);
        pdVar10 = (double *)(&stack0xffffffe0 + iVar14 + (int)local_8);
        do {
          dVar2 = pdVar7[-2];
          iVar15 = iVar15 + -1;
          pdVar7[-2] = (double)(fVar18 * (float10)pdVar10[1] + (float10)pdVar7[-2]);
          pdVar10[1] = (double)((float10)dVar2 * fVar18 + (float10)pdVar10[1]);
          dVar2 = pdVar7[-1];
          pdVar7[-1] = (double)((float10)*pdVar10 * fVar18 + (float10)pdVar7[-1]);
          *pdVar10 = (double)((float10)dVar2 * fVar18 + (float10)*pdVar10);
          dVar2 = *pdVar7;
          *pdVar7 = (double)((float10)pdVar10[-1] * fVar18 + (float10)*pdVar7);
          pdVar10[-1] = (double)((float10)dVar2 * fVar18 + (float10)pdVar10[-1]);
          dVar2 = pdVar7[1];
          pdVar7[1] = (double)((float10)pdVar10[-2] * fVar18 + (float10)pdVar7[1]);
          pdVar10[-2] = (double)((float10)dVar2 * fVar18 + (float10)pdVar10[-2]);
          pdVar7 = pdVar7 + 4;
          pdVar10 = pdVar10 + -4;
          uVar16 = local_10;
        } while (iVar15 != 0);
      }
      if (iVar13 < iVar6) {
        pdVar7 = (double *)((int)&uStack_28 + (uVar16 - iVar13) * 8 + iVar5 + iVar4);
        do {
          dVar2 = *(double *)(&stack0xffffffe0 + iVar13 * 8 + iVar5 + iVar4);
          iVar13 = iVar13 + 1;
          *(double *)((int)&uStack_28 + iVar13 * 8 + iVar5 + iVar4) =
               (double)(fVar18 * (float10)*pdVar7 +
                       (float10)*(double *)((int)&uStack_28 + iVar13 * 8 + iVar5 + iVar4));
          *pdVar7 = (double)((float10)dVar2 * fVar18 + (float10)*pdVar7);
          pdVar7 = pdVar7 + -1;
        } while (iVar13 < iVar6);
      }
      uVar12 = uVar16 & 0x80000001;
      bVar17 = uVar12 == 0;
      if ((int)uVar12 < 0) {
        bVar17 = (uVar12 - 1 | 0xfffffffe) == 0xffffffff;
      }
      if (!bVar17) {
        *(double *)(&stack0xffffffe0 + iVar13 * 8 + iVar5 + iVar4) =
             (double)((float10)*(double *)(&stack0xffffffe0 + iVar13 * 8 + iVar5 + iVar4) * fVar18 +
                     (float10)*(double *)(&stack0xffffffe0 + iVar13 * 8 + iVar5 + iVar4));
      }
      local_8 = local_8 + 1;
      local_10 = uVar16 + 1;
      fVar19 = ((float10)1 - fVar18 * fVar18) * fVar19;
    } while ((int)(uVar16 + 1) < param_4);
  }
  iVar14 = 0;
  if (3 < param_4) {
    iVar13 = (param_4 - 4U >> 2) + 1;
    iVar14 = iVar13 * 4;
    pdVar7 = (double *)((int)&local_10 + iVar5 + iVar4);
    pfVar8 = (float *)(param_2 + 8);
    do {
      pfVar8[-2] = (float)pdVar7[-2];
      iVar13 = iVar13 + -1;
      pfVar8[-1] = (float)pdVar7[-1];
      *pfVar8 = (float)*pdVar7;
      pfVar8[1] = (float)pdVar7[1];
      pdVar7 = pdVar7 + 4;
      pfVar8 = pfVar8 + 4;
    } while (iVar13 != 0);
  }
  for (; iVar14 < param_4; iVar14 = iVar14 + 1) {
    *(float *)(param_2 + iVar14 * 4) =
         (float)*(double *)(&stack0xffffffe0 + iVar14 * 8 + iVar5 + iVar4);
  }
  return (float10)(float)fVar19;
}

