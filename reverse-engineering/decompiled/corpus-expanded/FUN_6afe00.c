/* Ghidra pseudocode, not original source.
 * ev_0b75f810defb69f43ff4ee181673bf6e816c7d4f879f3f967a03f199d8168922
 * Entry: 0x6afe00; label: FUN_006afe00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006afe00(int *param_1,float *param_2,int param_3)

{
  float fVar1;
  int iVar2;
  float *pfVar3;
  float *pfVar4;
  float *pfVar5;
  float *pfVar6;
  float *pfVar7;
  float *pfVar8;
  float *pfVar9;
  int iVar10;
  float *pfVar11;
  
  iVar2 = *param_1 >> 2;
  iVar10 = *param_1 >> 1;
  pfVar5 = (float *)(param_3 + (iVar2 + iVar10) * 4);
  iVar2 = iVar2 * 4;
  pfVar3 = (float *)(param_1[2] + iVar2);
  pfVar4 = param_2 + iVar10 + -7;
  pfVar6 = pfVar5;
  do {
    pfVar9 = pfVar4 + -8;
    pfVar6[-4] = -pfVar4[2] * pfVar3[3] - *pfVar4 * pfVar3[2];
    pfVar6[-3] = *pfVar4 * pfVar3[3] - pfVar3[2] * pfVar4[2];
    pfVar6[-2] = -pfVar4[6] * pfVar3[1] - *pfVar3 * pfVar4[4];
    pfVar6[-1] = pfVar3[1] * pfVar4[4] - pfVar4[6] * *pfVar3;
    pfVar3 = pfVar3 + 4;
    pfVar4 = pfVar9;
    pfVar6 = pfVar6 + -4;
  } while (param_2 <= pfVar9);
  pfVar3 = (float *)(param_1[2] + iVar2);
  pfVar4 = param_2 + iVar10 + -8;
  pfVar6 = pfVar5;
  do {
    pfVar9 = pfVar3 + -4;
    pfVar11 = pfVar4 + -8;
    *pfVar6 = pfVar3[-1] * pfVar4[4] + pfVar3[-2] * pfVar4[6];
    pfVar6[1] = pfVar3[-2] * pfVar4[4] - pfVar4[6] * pfVar3[-1];
    pfVar6[2] = *pfVar9 * pfVar4[2] + *pfVar4 * pfVar3[-3];
    pfVar6[3] = *pfVar4 * *pfVar9 - pfVar3[-3] * pfVar4[2];
    pfVar3 = pfVar9;
    pfVar4 = pfVar11;
    pfVar6 = pfVar6 + 4;
  } while (param_2 <= pfVar11);
  pfVar3 = (float *)(param_3 + iVar10 * 4);
  FUN_006afb80(pfVar3,iVar10);
  FUN_006afc90();
  pfVar4 = (float *)(param_1[2] + iVar10 * 4);
  pfVar6 = (float *)(param_3 + 0xc);
  pfVar9 = pfVar5;
  pfVar11 = pfVar5;
  do {
    pfVar8 = pfVar9 + -4;
    pfVar7 = pfVar6 + 5;
    pfVar9[-1] = pfVar4[1] * pfVar6[-3] - pfVar6[-2] * *pfVar4;
    *pfVar11 = -(*pfVar4 * pfVar6[-3] + pfVar6[-2] * pfVar4[1]);
    pfVar9[-2] = pfVar6[-1] * pfVar4[3] - pfVar4[2] * *pfVar6;
    pfVar11[1] = -(pfVar4[3] * *pfVar6 + pfVar6[-1] * pfVar4[2]);
    pfVar9[-3] = pfVar6[1] * pfVar4[5] - pfVar6[2] * pfVar4[4];
    pfVar11[2] = -(pfVar6[1] * pfVar4[4] + pfVar6[2] * pfVar4[5]);
    *pfVar8 = pfVar6[3] * pfVar4[7] - pfVar4[6] * pfVar6[4];
    pfVar11[3] = -(pfVar6[4] * pfVar4[7] + pfVar4[6] * pfVar6[3]);
    pfVar4 = pfVar4 + 8;
    pfVar6 = pfVar6 + 8;
    pfVar9 = pfVar8;
    pfVar11 = pfVar11 + 4;
  } while (pfVar7 < pfVar8);
  pfVar4 = pfVar5;
  pfVar6 = (float *)(iVar2 + 8 + param_3);
  pfVar9 = pfVar5 + (2 - iVar10);
  do {
    fVar1 = pfVar4[-1];
    pfVar8 = pfVar4 + -4;
    pfVar9[-3] = fVar1;
    pfVar11 = pfVar6 + 2;
    pfVar6[-2] = -fVar1;
    fVar1 = pfVar4[-2];
    pfVar9[-4] = fVar1;
    pfVar6[-1] = -fVar1;
    fVar1 = pfVar4[-3];
    pfVar9[-5] = fVar1;
    *pfVar6 = -fVar1;
    fVar1 = *pfVar8;
    pfVar9[-6] = fVar1;
    pfVar6[1] = -fVar1;
    pfVar4 = pfVar8;
    pfVar7 = pfVar5;
    pfVar6 = pfVar6 + 4;
    pfVar9 = pfVar9 + -4;
  } while (pfVar11 < pfVar8);
  do {
    pfVar4 = pfVar5 + -4;
    *pfVar4 = pfVar7[3];
    pfVar5[-3] = pfVar7[2];
    pfVar5[-2] = pfVar7[1];
    pfVar5[-1] = *pfVar7;
    pfVar5 = pfVar4;
    pfVar7 = pfVar7 + 4;
  } while (pfVar3 < pfVar4);
  return;
}

