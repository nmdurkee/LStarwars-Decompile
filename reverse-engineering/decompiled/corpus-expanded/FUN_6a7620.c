/* Ghidra pseudocode, not original source.
 * ev_d0baaaa1d022e9a6bc644bf87cbac2e9d23f713faf88b9587519a457b813b0f8
 * Entry: 0x6a7620; label: FUN_006a7620
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006a7620(int *param_1,int param_2,float *param_3,int param_4)

{
  int *piVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  float *pfVar8;
  int *piVar9;
  int iVar10;
  int iVar11;
  float10 fVar12;
  float local_6c;
  int local_60;
  int *local_58;
  float *local_50;
  int *local_4c;
  
  iVar6 = *param_1;
  iVar3 = param_1[1];
  iVar4 = *(int *)(iVar3 + 0x200);
  local_60 = 0;
  iVar7 = *(int *)(iVar3 + 0x1fc);
  if (iVar6 < *(int *)(iVar3 + 0x1fc)) {
    iVar7 = iVar6;
  }
  iVar11 = 0;
  if (*(int *)(iVar3 + 500) != 0) {
    if (0 < iVar7) {
      pfVar8 = param_3;
      local_4c = (int *)iVar7;
      do {
        fVar12 = (float10)FUN_006eafc0((double)(*(float *)((param_2 - (int)param_3) + (int)pfVar8) +
                                               0.5));
        *pfVar8 = (float)fVar12;
        pfVar8 = pfVar8 + 1;
        local_4c = (int *)((int)local_4c + -1);
        local_60 = iVar7;
      } while (local_4c != (int *)0x0);
    }
    iVar10 = iVar4 + local_60;
    iVar11 = local_60;
    if (iVar10 <= iVar6) {
      local_4c = (int *)(param_4 + (local_60 - iVar7) * 4);
      local_50 = (float *)(param_2 + 8 + local_60 * 4);
      do {
        local_6c = 0.0;
        iVar11 = local_60;
        if (3 < iVar10 - local_60) {
          iVar5 = ((iVar10 - local_60) - 4U >> 2) + 1;
          iVar11 = local_60 + iVar5 * 4;
          pfVar8 = local_50;
          do {
            iVar5 = iVar5 + -1;
            local_6c = pfVar8[1] * pfVar8[1] +
                       *pfVar8 * *pfVar8 +
                       local_6c + pfVar8[-2] * pfVar8[-2] + pfVar8[-1] * pfVar8[-1];
            pfVar8 = pfVar8 + 4;
          } while (iVar5 != 0);
        }
        for (; iVar11 < iVar10; iVar11 = iVar11 + 1) {
          fVar2 = *(float *)(param_2 + iVar11 * 4);
          local_6c = fVar2 * fVar2 + local_6c;
        }
        iVar11 = 0;
        if (0 < iVar4) {
          local_58 = local_4c;
          do {
            iVar5 = *local_58;
            fVar2 = *(float *)(param_2 + iVar5 * 4);
            if (fVar2 * fVar2 < 0.25) {
              if (local_6c < (float)*(double *)(iVar3 + 0x208)) break;
              param_3[iVar5] = (float)(*(uint *)(param_2 + iVar5 * 4) & 0xbf800000 | 0x3f800000);
              local_6c = local_6c - 1.0;
            }
            else {
              fVar12 = (float10)FUN_006eafc0((double)(*(float *)(param_2 + iVar5 * 4) + 0.5));
              param_3[iVar5] = (float)fVar12;
              fVar2 = *(float *)(param_2 + iVar5 * 4);
              local_6c = local_6c - fVar2 * fVar2;
            }
            local_58 = local_58 + 1;
            iVar11 = iVar11 + 1;
          } while (iVar11 < iVar4);
        }
        if (3 < iVar4 - iVar11) {
          iVar5 = ((iVar4 - iVar11) - 4U >> 2) + 1;
          piVar9 = (int *)(param_4 + 8 + ((iVar11 - iVar7) + local_60) * 4);
          iVar11 = iVar11 + iVar5 * 4;
          do {
            param_3[piVar9[-2]] = 0.0;
            param_3[piVar9[-1]] = 0.0;
            param_3[*piVar9] = 0.0;
            piVar1 = piVar9 + 1;
            piVar9 = piVar9 + 4;
            param_3[*piVar1] = 0.0;
            iVar5 = iVar5 + -1;
          } while (iVar5 != 0);
        }
        if (iVar11 < iVar4) {
          piVar9 = (int *)(param_4 + ((iVar11 - iVar7) + local_60) * 4);
          iVar11 = iVar4 - iVar11;
          do {
            iVar5 = *piVar9;
            piVar9 = piVar9 + 1;
            param_3[iVar5] = 0.0;
            iVar11 = iVar11 + -1;
          } while (iVar11 != 0);
        }
        iVar11 = local_60 + iVar4;
        iVar10 = iVar10 + iVar4;
        local_50 = local_50 + iVar4;
        local_4c = local_4c + iVar4;
        local_60 = iVar11;
      } while (iVar10 <= iVar6);
    }
  }
  if (iVar11 < iVar6) {
    iVar6 = iVar6 - iVar11;
    pfVar8 = param_3 + iVar11;
    do {
      fVar12 = (float10)FUN_006eafc0((double)(*(float *)((int)pfVar8 + (param_2 - (int)param_3)) +
                                             0.5));
      *pfVar8 = (float)fVar12;
      pfVar8 = pfVar8 + 1;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
  }
  return;
}

