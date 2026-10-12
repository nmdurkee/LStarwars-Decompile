/* Ghidra pseudocode, not original source.
 * ev_0b75f810defb69f43ff4ee181673bf6e816c7d4f879f3f967a03f199d8168922
 * Entry: 0x6b0070; label: FUN_006b0070
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */

void FUN_006b0070(float *param_1,int param_2,int param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  int *piVar6;
  float *pfVar7;
  float *pfVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  float *pfVar13;
  int iVar14;
  float *pfVar15;
  int iVar16;
  float *pfVar17;
  int iVar18;
  float *pfVar19;
  float *pfVar20;
  float afStack_3c [3];
  float *local_8;
  
  piVar6 = (int *)param_1;
  iVar18 = (int)*param_1;
  iVar9 = iVar18 >> 1;
  iVar10 = iVar18 >> 2;
  iVar16 = iVar18 >> 3;
  afStack_3c[2] = 9.82662e-39;
  iVar5 = iVar18 * -4;
  pfVar19 = (float *)(&stack0xffffffd0 + iVar5);
  iVar14 = iVar9 * 4;
  pfVar8 = (float *)(param_2 + (iVar10 + iVar9) * 4);
  pfVar7 = (float *)((int)param_1[2] + iVar14);
  iVar11 = 0;
  pfVar17 = pfVar7;
  iVar12 = iVar11;
  param_1 = pfVar8;
  local_8 = pfVar8 + 1;
  if (0 < iVar16) {
    do {
      fVar1 = pfVar8[-2];
      pfVar8 = pfVar8 + -4;
      fVar2 = *local_8;
      pfVar7 = pfVar17 + -2;
      iVar11 = iVar12 + 2;
      fVar3 = local_8[2];
      fVar4 = *pfVar8;
      afStack_3c[(iVar9 + iVar12 + 3) - iVar18] =
           pfVar17[-1] * (fVar3 + fVar4) + *pfVar7 * (fVar1 + fVar2);
      afStack_3c[(iVar9 + iVar12 + 4) - iVar18] =
           *pfVar7 * (fVar3 + fVar4) - (fVar1 + fVar2) * pfVar17[-1];
      pfVar17 = pfVar7;
      iVar12 = iVar11;
      param_1 = pfVar8;
      local_8 = local_8 + 4;
    } while (iVar11 < iVar16);
  }
  pfVar8 = (float *)(param_2 + 4);
  for (; iVar11 < iVar9 - iVar16; iVar11 = iVar11 + 2) {
    fVar1 = param_1[-2];
    param_1 = param_1 + -4;
    fVar2 = *pfVar8;
    pfVar17 = pfVar7 + -2;
    fVar3 = *param_1;
    fVar4 = pfVar8[2];
    afStack_3c[(iVar9 + iVar11 + 3) - iVar18] =
         pfVar7[-1] * (fVar3 - fVar4) + *pfVar17 * (fVar1 - fVar2);
    afStack_3c[(iVar9 + iVar11 + 4) - iVar18] =
         *pfVar17 * (fVar3 - fVar4) - (fVar1 - fVar2) * pfVar7[-1];
    pfVar8 = pfVar8 + 4;
    pfVar7 = pfVar17;
  }
  pfVar17 = (float *)(param_2 + iVar18 * 4);
  for (; iVar11 < iVar9; iVar11 = iVar11 + 2) {
    fVar1 = pfVar17[-2];
    pfVar17 = pfVar17 + -4;
    pfVar13 = pfVar7 + -2;
    fVar2 = *pfVar8;
    fVar3 = *pfVar17;
    fVar4 = pfVar8[2];
    afStack_3c[(iVar9 + iVar11 + 3) - iVar18] =
         pfVar7[-1] * (-fVar3 - fVar4) + *pfVar13 * (-fVar1 - fVar2);
    afStack_3c[(iVar9 + iVar11 + 4) - iVar18] =
         *pfVar13 * (-fVar3 - fVar4) - (-fVar1 - fVar2) * pfVar7[-1];
    pfVar8 = pfVar8 + 4;
    pfVar7 = pfVar13;
  }
  afStack_3c[2 - iVar18] = (float)iVar9;
  afStack_3c[1 - iVar18] = (float)(&stack0xffffffd0 + iVar14 + iVar5);
  afStack_3c[-iVar18] = 9.827125e-39;
  FUN_006afb80();
  afStack_3c[2 - iVar18] = 9.827142e-39;
  FUN_006afc90();
  pfVar8 = (float *)(piVar6[2] + iVar14);
  pfVar7 = (float *)(param_3 + iVar14);
  iVar14 = 0;
  if (3 < iVar10) {
    iVar18 = (iVar10 - 4U >> 2) + 1;
    iVar14 = iVar18 * 4;
    pfVar17 = pfVar8;
    pfVar13 = pfVar7;
    pfVar15 = (float *)(param_3 + 8);
    pfVar20 = (float *)(&stack0xffffffd0 + iVar5);
    do {
      pfVar19 = pfVar20 + 8;
      pfVar7 = pfVar13 + -4;
      pfVar8 = pfVar17 + 8;
      iVar18 = iVar18 + -1;
      pfVar15[-2] = (pfVar20[1] * pfVar17[1] + *pfVar17 * *pfVar20) * (float)piVar6[4];
      pfVar13[-1] = (pfVar17[1] * *pfVar20 - pfVar20[1] * *pfVar17) * (float)piVar6[4];
      pfVar15[-1] = (pfVar17[2] * pfVar20[2] + pfVar17[3] * pfVar20[3]) * (float)piVar6[4];
      pfVar13[-2] = (pfVar17[3] * pfVar20[2] - pfVar20[3] * pfVar17[2]) * (float)piVar6[4];
      *pfVar15 = (pfVar17[4] * pfVar20[4] + pfVar17[5] * pfVar20[5]) * (float)piVar6[4];
      pfVar13[-3] = (pfVar20[4] * pfVar17[5] - pfVar17[4] * pfVar20[5]) * (float)piVar6[4];
      pfVar15[1] = (pfVar17[7] * pfVar20[7] + pfVar17[6] * pfVar20[6]) * (float)piVar6[4];
      *pfVar7 = (pfVar20[6] * pfVar17[7] - pfVar17[6] * pfVar20[7]) * (float)piVar6[4];
      pfVar17 = pfVar8;
      pfVar13 = pfVar7;
      pfVar15 = pfVar15 + 4;
      pfVar20 = pfVar19;
    } while (iVar18 != 0);
  }
  while (iVar14 < iVar10) {
    pfVar7 = pfVar7 + -1;
    iVar14 = iVar14 + 1;
    *(float *)(param_3 + -4 + iVar14 * 4) =
         (pfVar19[1] * pfVar8[1] + *pfVar8 * *pfVar19) * (float)piVar6[4];
    *pfVar7 = (pfVar8[1] * *pfVar19 - pfVar19[1] * *pfVar8) * (float)piVar6[4];
    pfVar8 = pfVar8 + 2;
    pfVar19 = pfVar19 + 2;
  }
  return;
}

