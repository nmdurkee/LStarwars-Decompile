/* Ghidra pseudocode, not original source.
 * ev_a2aea1d641189bbcca45d714e231c7fbe07e1298025184ba29836f60d860e436
 * Entry: 0x5e8190; label: FUN_005e8190
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005e8190(int *param_1,int *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  int *in_ECX;
  int iVar7;
  int iVar8;
  int *piVar9;
  float *pfVar10;
  
  piVar9 = in_ECX + 8;
  for (iVar7 = 0x10; iVar7 != 0; iVar7 = iVar7 + -1) {
    *piVar9 = *param_2;
    param_2 = param_2 + 1;
    piVar9 = piVar9 + 1;
  }
  iVar7 = in_ECX[3];
  piVar9 = in_ECX + 0x18;
  for (iVar8 = 0x10; iVar8 != 0; iVar8 = iVar8 + -1) {
    *piVar9 = *param_1;
    param_1 = param_1 + 1;
    piVar9 = piVar9 + 1;
  }
  param_2 = (int *)0x0;
  if (iVar7 != 0) {
    param_1 = (int *)0x0;
    do {
      iVar8 = *in_ECX + (int)param_1;
      iVar7 = 0;
      *(undefined4 *)(iVar8 + 0x80) = 0x49742400;
      pfVar10 = (float *)(iVar8 + 0x40);
      *(undefined4 *)(iVar8 + 0x88) = 0x49742400;
      *(undefined4 *)(iVar8 + 0x90) = 0x49742400;
      *(undefined4 *)(iVar8 + 0x84) = 0xc9742400;
      *(undefined4 *)(iVar8 + 0x8c) = 0xc9742400;
      *(undefined4 *)(iVar8 + 0x94) = 0xc9742400;
      do {
        FUN_005b3ec0(pfVar10,pfVar10 + -0x10,in_ECX + 8);
        if (pfVar10[3] <= 0.0) goto LAB_005e83d7;
        fVar1 = *pfVar10 / pfVar10[3];
        *pfVar10 = fVar1;
        pfVar10[1] = pfVar10[1] / pfVar10[3];
        pfVar10[2] = pfVar10[2] / pfVar10[3];
        if (*(float *)(iVar8 + 0x80) <= fVar1) {
          fVar1 = *(float *)(iVar8 + 0x80);
        }
        *(float *)(iVar8 + 0x80) = fVar1;
        if (*(float *)(iVar8 + 0x88) <= pfVar10[1]) {
          fVar2 = *(float *)(iVar8 + 0x88);
        }
        else {
          fVar2 = pfVar10[1];
        }
        *(float *)(iVar8 + 0x88) = fVar2;
        if (*pfVar10 <= *(float *)(iVar8 + 0x84)) {
          fVar3 = *(float *)(iVar8 + 0x84);
        }
        else {
          fVar3 = *pfVar10;
        }
        *(float *)(iVar8 + 0x84) = fVar3;
        if (pfVar10[1] <= *(float *)(iVar8 + 0x8c)) {
          fVar4 = *(float *)(iVar8 + 0x8c);
        }
        else {
          fVar4 = pfVar10[1];
        }
        *(float *)(iVar8 + 0x8c) = fVar4;
        if (*(float *)(iVar8 + 0x90) <= pfVar10[3]) {
          fVar5 = *(float *)(iVar8 + 0x90);
        }
        else {
          fVar5 = pfVar10[3];
        }
        *(float *)(iVar8 + 0x90) = fVar5;
        if (pfVar10[3] <= *(float *)(iVar8 + 0x94)) {
          fVar6 = *(float *)(iVar8 + 0x94);
        }
        else {
          fVar6 = pfVar10[3];
        }
        iVar7 = iVar7 + 1;
        pfVar10 = pfVar10 + 4;
        *(float *)(iVar8 + 0x94) = fVar6;
      } while (iVar7 != 4);
      if ((((fVar6 < 0.0) || (fVar5 < 0.0)) || (fVar3 < -1.0)) ||
         (((1.0 < fVar1 || (fVar4 < -1.0)) || (1.0 < fVar2)))) {
LAB_005e83d7:
        *(undefined4 *)(in_ECX[1] + (int)param_2 * 4) = 0xffffffff;
      }
      else {
        *(int **)(in_ECX[1] + (int)param_2 * 4) = param_2;
      }
      param_1 = (int *)((int)param_1 + 0xa0);
      param_2 = (int *)((int)param_2 + 1);
    } while (param_2 != (int *)in_ECX[3]);
  }
  _qsort((void *)in_ECX[1],in_ECX[3],4,FUN_005c5420);
  *(undefined1 *)(in_ECX + 4) = 1;
  return;
}

