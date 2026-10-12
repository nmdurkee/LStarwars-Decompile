/* Ghidra pseudocode, not original source.
 * ev_0b75f810defb69f43ff4ee181673bf6e816c7d4f879f3f967a03f199d8168922
 * Entry: 0x6ac910; label: FUN_006ac910
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006ac910(float *param_1,int param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float *in_EAX;
  float *pfVar8;
  float *pfVar9;
  int iVar10;
  float *pfVar11;
  float *pfVar12;
  int iVar13;
  float *pfVar14;
  float *pfVar15;
  int iVar16;
  int iVar17;
  int unaff_ESI;
  int unaff_EDI;
  float *local_44;
  float *local_38;
  float *local_34;
  float *local_2c;
  float *local_28;
  int local_24;
  float *local_20;
  int local_1c;
  int local_10;
  
  fVar7 = _DAT_00817048;
  fVar6 = _DAT_00817044;
  iVar16 = unaff_ESI * (int)param_1;
  iVar13 = 0;
  iVar10 = unaff_ESI * 2;
  local_38 = (float *)0x0;
  local_2c = (float *)0x0;
  if (3 < (int)param_1) {
    local_44 = (float *)(unaff_EDI + iVar16 * 8);
    local_1c = ((int)param_1 - 4U >> 2) + 1;
    local_2c = (float *)(local_1c * 4);
    pfVar8 = (float *)(unaff_EDI + iVar16 * 4);
    do {
      fVar1 = in_EAX[iVar10 + -1] + in_EAX[iVar10 + -1];
      fVar2 = fVar1 * fVar6 + in_EAX[(int)local_38];
      *(float *)(unaff_EDI + iVar13 * 4) = in_EAX[(int)local_38] + fVar1;
      fVar1 = (in_EAX[iVar10] + in_EAX[iVar10]) * fVar7;
      *pfVar8 = fVar2 - fVar1;
      *local_44 = fVar1 + fVar2;
      local_44 = local_44 + unaff_ESI;
      pfVar8 = pfVar8 + unaff_ESI;
      iVar10 = iVar10 + unaff_ESI * 3;
      fVar1 = in_EAX[iVar10 + -1] + in_EAX[iVar10 + -1];
      iVar17 = (int)local_38 + unaff_ESI * 3;
      fVar2 = fVar1 * fVar6 + in_EAX[iVar17];
      *(float *)(unaff_EDI + (iVar13 + unaff_ESI) * 4) = in_EAX[iVar17] + fVar1;
      iVar13 = iVar13 + unaff_ESI + unaff_ESI;
      fVar1 = (in_EAX[iVar10] + in_EAX[iVar10]) * fVar7;
      *pfVar8 = fVar2 - fVar1;
      *local_44 = fVar1 + fVar2;
      local_44 = local_44 + unaff_ESI;
      pfVar8 = pfVar8 + unaff_ESI;
      iVar10 = iVar10 + unaff_ESI * 3;
      fVar1 = in_EAX[iVar10 + -1] + in_EAX[iVar10 + -1];
      iVar17 = iVar17 + unaff_ESI * 3;
      fVar2 = fVar1 * fVar6 + in_EAX[iVar17];
      *(float *)(unaff_EDI + iVar13 * 4) = in_EAX[iVar17] + fVar1;
      fVar1 = (in_EAX[iVar10] + in_EAX[iVar10]) * fVar7;
      iVar13 = iVar13 + unaff_ESI;
      *pfVar8 = fVar2 - fVar1;
      *local_44 = fVar1 + fVar2;
      iVar10 = iVar10 + unaff_ESI * 3;
      fVar1 = in_EAX[iVar10 + -1] + in_EAX[iVar10 + -1];
      iVar17 = iVar17 + unaff_ESI * 3;
      fVar2 = fVar1 * fVar6 + in_EAX[iVar17];
      *(float *)(unaff_EDI + iVar13 * 4) = in_EAX[iVar17] + fVar1;
      iVar13 = iVar13 + unaff_ESI;
      fVar1 = (in_EAX[iVar10] + in_EAX[iVar10]) * fVar7;
      pfVar8[unaff_ESI] = fVar2 - fVar1;
      local_44[unaff_ESI] = fVar1 + fVar2;
      local_44 = local_44 + unaff_ESI + unaff_ESI;
      pfVar8 = pfVar8 + unaff_ESI + unaff_ESI;
      local_38 = (float *)(iVar17 + unaff_ESI * 3);
      iVar10 = iVar10 + unaff_ESI * 3;
      local_1c = local_1c + -1;
    } while (local_1c != 0);
  }
  if ((int)local_2c < (int)param_1) {
    local_44 = in_EAX + (int)local_38;
    local_38 = (float *)(unaff_EDI + (iVar16 * 2 + iVar13) * 4);
    pfVar8 = (float *)(unaff_EDI + iVar13 * 4);
    local_34 = (float *)(unaff_EDI + (iVar13 + iVar16) * 4);
    iVar13 = (int)param_1 - (int)local_2c;
    pfVar11 = in_EAX + iVar10;
    do {
      fVar1 = pfVar11[-1] + pfVar11[-1];
      fVar2 = fVar1 * fVar6 + *local_44;
      *pfVar8 = *local_44 + fVar1;
      fVar1 = (*pfVar11 + *pfVar11) * fVar7;
      *local_34 = fVar2 - fVar1;
      *local_38 = fVar1 + fVar2;
      local_34 = local_34 + unaff_ESI;
      local_38 = local_38 + unaff_ESI;
      pfVar8 = pfVar8 + unaff_ESI;
      local_44 = local_44 + unaff_ESI * 3;
      pfVar11 = pfVar11 + unaff_ESI * 3;
      iVar13 = iVar13 + -1;
    } while (iVar13 != 0);
  }
  if ((unaff_ESI != 1) && (0 < (int)param_1)) {
    local_1c = 0;
    local_24 = 0;
    pfVar8 = in_EAX + unaff_ESI * 2;
    local_28 = (float *)(unaff_EDI + iVar16 * 8);
    local_10 = (int)param_1;
    local_20 = in_EAX;
    do {
      if (2 < unaff_ESI) {
        local_38 = local_28;
        param_1 = local_20;
        local_44 = param_3;
        pfVar9 = (float *)(param_2 + 4);
        iVar10 = (unaff_ESI - 3U >> 1) + 1;
        pfVar11 = pfVar8;
        pfVar14 = pfVar8;
        local_34 = (float *)(unaff_EDI + (local_24 - local_1c) * 4);
        local_2c = (float *)(unaff_EDI + ((local_24 - local_1c) + iVar16) * 4);
        do {
          pfVar15 = pfVar14 + -2;
          pfVar12 = pfVar11 + 2;
          fVar3 = (pfVar14[-3] + pfVar11[1]) * fVar6 + param_1[1];
          local_34[1] = pfVar14[-3] + pfVar11[1] + param_1[1];
          fVar1 = param_1[2];
          fVar4 = (*pfVar12 - *pfVar15) * fVar6 + fVar1;
          local_34[2] = fVar1 + (*pfVar12 - *pfVar15);
          fVar5 = (pfVar11[1] - pfVar14[-3]) * fVar7;
          fVar2 = (*pfVar15 + *pfVar12) * fVar7;
          fVar1 = fVar3 - fVar2;
          fVar2 = fVar2 + fVar3;
          fVar3 = fVar4 + fVar5;
          fVar4 = fVar4 - fVar5;
          local_2c[1] = pfVar9[-1] * fVar1 - *pfVar9 * fVar3;
          local_2c[2] = fVar3 * pfVar9[-1] + *pfVar9 * fVar1;
          local_38[1] = *local_44 * fVar2 -
                        *(float *)((int)pfVar9 + ((int)param_3 - param_2)) * fVar4;
          fVar1 = *local_44;
          pfVar11 = (float *)((int)pfVar9 + ((int)param_3 - param_2));
          local_44 = local_44 + 2;
          pfVar9 = pfVar9 + 2;
          iVar10 = iVar10 + -1;
          local_38[2] = fVar4 * fVar1 + *pfVar11 * fVar2;
          pfVar11 = pfVar12;
          pfVar14 = pfVar15;
          param_1 = param_1 + 2;
          local_38 = local_38 + 2;
          local_34 = local_34 + 2;
          local_2c = local_2c + 2;
        } while (iVar10 != 0);
      }
      local_20 = local_20 + unaff_ESI * 3;
      local_28 = local_28 + unaff_ESI;
      local_24 = local_24 + unaff_ESI * 3;
      local_1c = local_1c + unaff_ESI * 2;
      pfVar8 = pfVar8 + unaff_ESI * 3;
      local_10 = local_10 + -1;
    } while (local_10 != 0);
  }
  return;
}

