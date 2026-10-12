/* Ghidra pseudocode, not original source.
 * ev_d0baaaa1d022e9a6bc644bf87cbac2e9d23f713faf88b9587519a457b813b0f8
 * Entry: 0x6a69b0; label: FUN_006a69b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006a69b0(int *param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
                 float *param_7)

{
  float fVar1;
  float fVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  int *piVar6;
  float *pfVar7;
  float *pfVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  float *local_54;
  float *local_50;
  float *local_4c;
  int local_48;
  
  piVar6 = param_1;
  fVar1 = *(float *)(param_1[1] + 0xc + param_4 * 4);
  iVar3 = *param_1;
  fVar2 = (float)param_1[0xc];
  local_48 = 0;
  if (3 < iVar3) {
    iVar9 = param_6 - param_3;
    local_50 = (float *)(param_6 + 0xc);
    iVar10 = param_6 - param_5;
    local_54 = (float *)(param_5 + 8);
    iVar11 = (iVar3 - 4U >> 2) + 1;
    local_48 = iVar11 * 4;
    local_4c = param_7;
    pfVar8 = (float *)(param_3 + 4);
    do {
      param_1 = (int *)(*(float *)((int)pfVar8 + *(int *)(piVar6[3] + param_4 * 4) + -param_3 + -4)
                       + *(float *)((param_2 - (int)param_7) + (int)local_4c));
      if (*(float *)(piVar6[1] + 0x6c) < (float)param_1) {
        param_1 = *(int **)(piVar6[1] + 0x6c);
      }
      fVar4 = pfVar8[-1] + fVar1;
      if (pfVar8[-1] + fVar1 < (float)param_1) {
        fVar4 = (float)param_1;
      }
      local_54[-2] = fVar4;
      if (param_4 == 1) {
        fVar4 = ((float)param_1 - *local_4c) - -17.2;
        if ((float)param_1 - *local_4c <= -17.2) {
          param_1 = (int *)(1.0 - fVar4 * 0.0003 * fVar2);
        }
        else {
          param_1 = (int *)(1.0 - fVar4 * 0.005 * fVar2);
          if ((float)param_1 < 0.0) {
            local_50[-3] = local_50[-3] * 0.0001;
            goto LAB_006a6b7a;
          }
        }
        local_50[-3] = local_50[-3] * (float)param_1;
      }
LAB_006a6b7a:
      param_1 = (int *)(*(float *)((int)pfVar8 + *(int *)(piVar6[3] + param_4 * 4) + -param_3) +
                       *(float *)((param_2 - param_3) + (int)pfVar8));
      if (*(float *)(piVar6[1] + 0x6c) < (float)param_1) {
        param_1 = *(int **)(piVar6[1] + 0x6c);
      }
      fVar4 = *pfVar8 + fVar1;
      if (*pfVar8 + fVar1 < (float)param_1) {
        fVar4 = (float)param_1;
      }
      *(float *)((param_5 - param_3) + (int)pfVar8) = fVar4;
      if (param_4 == 1) {
        fVar5 = (float)param_1 - *(float *)(((int)param_7 - param_3) + (int)pfVar8);
        fVar4 = fVar5 - -17.2;
        if (fVar5 <= -17.2) {
          param_1 = (int *)(1.0 - fVar4 * 0.0003 * fVar2);
        }
        else {
          param_1 = (int *)(1.0 - fVar4 * 0.005 * fVar2);
          if ((float)param_1 < 0.0) {
            *(float *)(iVar9 + (int)pfVar8) = *(float *)(iVar9 + (int)pfVar8) * 0.0001;
            goto LAB_006a6c3f;
          }
        }
        *(float *)(iVar9 + (int)pfVar8) = (float)param_1 * *(float *)(iVar9 + (int)pfVar8);
      }
LAB_006a6c3f:
      param_1 = (int *)(*(float *)(*(int *)(piVar6[3] + param_4 * 4) + (4 - param_3) + (int)pfVar8)
                       + *(float *)((param_2 - param_5) + (int)local_54));
      if (*(float *)(piVar6[1] + 0x6c) < (float)param_1) {
        param_1 = *(int **)(piVar6[1] + 0x6c);
      }
      fVar4 = pfVar8[1] + fVar1;
      if (pfVar8[1] + fVar1 < (float)param_1) {
        fVar4 = (float)param_1;
      }
      *local_54 = fVar4;
      if (param_4 == 1) {
        fVar5 = (float)param_1 - *(float *)(((int)param_7 - param_5) + (int)local_54);
        fVar4 = fVar5 - -17.2;
        if (fVar5 <= -17.2) {
          param_1 = (int *)(1.0 - fVar4 * 0.0003 * fVar2);
        }
        else {
          param_1 = (int *)(1.0 - fVar4 * 0.005 * fVar2);
          if ((float)param_1 < 0.0) {
            *(float *)(iVar10 + (int)local_54) = *(float *)(iVar10 + (int)local_54) * 0.0001;
            goto LAB_006a6d04;
          }
        }
        *(float *)(iVar10 + (int)local_54) = (float)param_1 * *(float *)(iVar10 + (int)local_54);
      }
LAB_006a6d04:
      pfVar7 = (float *)(((int)param_7 - param_6) + (int)local_50);
      param_1 = (int *)(*(float *)(*(int *)(piVar6[3] + param_4 * 4) + (8 - param_3) + (int)pfVar8)
                       + *(float *)((param_2 - (int)param_7) + (int)pfVar7));
      if (*(float *)(piVar6[1] + 0x6c) < (float)param_1) {
        param_1 = *(int **)(piVar6[1] + 0x6c);
      }
      fVar4 = pfVar8[2] + fVar1;
      if (pfVar8[2] + fVar1 < (float)param_1) {
        fVar4 = (float)param_1;
      }
      local_54[1] = fVar4;
      if (param_4 == 1) {
        fVar5 = (float)param_1 - *pfVar7;
        fVar4 = fVar5 - -17.2;
        if (fVar5 <= -17.2) {
          param_1 = (int *)(1.0 - fVar4 * 0.0003 * fVar2);
        }
        else {
          param_1 = (int *)(1.0 - fVar4 * 0.005 * fVar2);
          if ((float)param_1 < 0.0) {
            *local_50 = *local_50 * 0.0001;
            goto LAB_006a6dd8;
          }
        }
        *local_50 = *local_50 * (float)param_1;
      }
LAB_006a6dd8:
      local_4c = local_4c + 4;
      local_54 = local_54 + 4;
      local_50 = local_50 + 4;
      pfVar8 = pfVar8 + 4;
      iVar11 = iVar11 + -1;
    } while (iVar11 != 0);
  }
  if (iVar3 <= local_48) {
    return;
  }
  pfVar8 = (float *)(param_3 + local_48 * 4);
  param_6 = param_6 - param_3;
  do {
    param_1 = (int *)(*(float *)(*(int *)(piVar6[3] + param_4 * 4) + local_48 * 4) +
                     *(float *)((int)pfVar8 + (param_2 - param_3)));
    if (*(float *)(piVar6[1] + 0x6c) < (float)param_1) {
      param_1 = *(int **)(piVar6[1] + 0x6c);
    }
    fVar4 = *pfVar8 + fVar1;
    if (*pfVar8 + fVar1 < (float)param_1) {
      fVar4 = (float)param_1;
    }
    *(float *)((param_5 - param_3) + (int)pfVar8) = fVar4;
    if (param_4 == 1) {
      fVar5 = (float)param_1 - *(float *)(((int)param_7 - param_3) + (int)pfVar8);
      fVar4 = fVar5 - -17.2;
      if (fVar5 <= -17.2) {
        param_1 = (int *)(1.0 - fVar4 * 0.0003 * fVar2);
      }
      else {
        param_1 = (int *)(1.0 - fVar4 * 0.005 * fVar2);
        if ((float)param_1 < 0.0) {
          *(float *)(param_6 + (int)pfVar8) = *(float *)(param_6 + (int)pfVar8) * 0.0001;
          goto LAB_006a6ee2;
        }
      }
      *(float *)(param_6 + (int)pfVar8) = (float)param_1 * *(float *)(param_6 + (int)pfVar8);
    }
LAB_006a6ee2:
    local_48 = local_48 + 1;
    pfVar8 = pfVar8 + 1;
    if (iVar3 <= local_48) {
      return;
    }
  } while( true );
}

