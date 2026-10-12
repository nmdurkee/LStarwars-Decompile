/* Ghidra pseudocode, not original source.
 * ev_0b75f810defb69f43ff4ee181673bf6e816c7d4f879f3f967a03f199d8168922
 * Entry: 0x6aa330; label: FUN_006aa330
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006aa330(int param_1,int param_2,int param_3,float *param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  int in_EAX;
  float *pfVar9;
  uint in_ECX;
  float *pfVar10;
  float *in_EDX;
  int iVar11;
  int iVar12;
  float *pfVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  uint uVar18;
  int iVar19;
  int iVar20;
  float *pfVar21;
  float *local_70;
  int local_68;
  float *local_64;
  float *local_5c;
  float *local_58;
  float *local_54;
  float *local_4c;
  float *local_48;
  float *local_44;
  float *local_40;
  int local_34;
  float *local_30;
  
  iVar14 = in_ECX * param_1;
  local_68 = iVar14 * 2;
  iVar15 = 0;
  local_70 = (float *)(iVar14 * 3);
  local_54 = (float *)0x0;
  iVar12 = iVar14;
  if (3 < param_1) {
    local_40 = (float *)((param_1 - 4U >> 2) + 1);
    local_54 = (float *)((int)local_40 * 4);
    do {
      fVar1 = *(float *)(in_EAX + iVar12 * 4) + *(float *)(in_EAX + (int)local_70 * 4);
      fVar2 = *(float *)(in_EAX + local_68 * 4) + *(float *)(in_EAX + iVar15 * 4);
      in_EDX[iVar15 * 4] = fVar1 + fVar2;
      in_EDX[iVar15 * 4 + in_ECX * 4 + -1] = fVar2 - fVar1;
      iVar11 = iVar15 * 4 + in_ECX * 2;
      iVar16 = iVar15 + in_ECX;
      in_EDX[iVar11 + -1] = *(float *)(in_EAX + iVar15 * 4) - *(float *)(in_EAX + local_68 * 4);
      iVar15 = (int)local_70 + in_ECX;
      iVar19 = iVar12 + in_ECX;
      in_EDX[iVar11] = *(float *)(in_EAX + (int)local_70 * 4) - *(float *)(in_EAX + iVar12 * 4);
      local_68 = local_68 + in_ECX;
      fVar1 = *(float *)(in_EAX + iVar19 * 4) + *(float *)(in_EAX + iVar15 * 4);
      fVar2 = *(float *)(in_EAX + local_68 * 4) + *(float *)(in_EAX + iVar16 * 4);
      in_EDX[iVar16 * 4] = fVar1 + fVar2;
      in_EDX[iVar16 * 4 + in_ECX * 4 + -1] = fVar2 - fVar1;
      iVar12 = iVar16 * 4 + in_ECX * 2;
      iVar17 = iVar16 + in_ECX;
      in_EDX[iVar12 + -1] = *(float *)(in_EAX + iVar16 * 4) - *(float *)(in_EAX + local_68 * 4);
      iVar11 = iVar15 + in_ECX;
      iVar20 = iVar19 + in_ECX;
      in_EDX[iVar12] = *(float *)(in_EAX + iVar15 * 4) - *(float *)(in_EAX + iVar19 * 4);
      local_68 = local_68 + in_ECX;
      fVar1 = *(float *)(in_EAX + iVar20 * 4) + *(float *)(in_EAX + iVar11 * 4);
      fVar2 = *(float *)(in_EAX + local_68 * 4) + *(float *)(in_EAX + iVar17 * 4);
      in_EDX[iVar17 * 4] = fVar1 + fVar2;
      in_EDX[iVar17 * 4 + in_ECX * 4 + -1] = fVar2 - fVar1;
      iVar12 = iVar17 * 4 + in_ECX * 2;
      iVar19 = iVar17 + in_ECX;
      in_EDX[iVar12 + -1] = *(float *)(in_EAX + iVar17 * 4) - *(float *)(in_EAX + local_68 * 4);
      iVar16 = iVar11 + in_ECX;
      iVar17 = iVar20 + in_ECX;
      in_EDX[iVar12] = *(float *)(in_EAX + iVar11 * 4) - *(float *)(in_EAX + iVar20 * 4);
      iVar12 = local_68 + in_ECX;
      fVar1 = *(float *)(in_EAX + iVar17 * 4) + *(float *)(in_EAX + iVar16 * 4);
      fVar2 = *(float *)(in_EAX + iVar12 * 4) + *(float *)(in_EAX + iVar19 * 4);
      in_EDX[iVar19 * 4] = fVar1 + fVar2;
      in_EDX[iVar19 * 4 + in_ECX * 4 + -1] = fVar2 - fVar1;
      iVar11 = iVar19 * 4 + in_ECX * 2;
      local_68 = iVar12 + in_ECX;
      iVar15 = iVar19 + in_ECX;
      in_EDX[iVar11 + -1] = *(float *)(in_EAX + iVar19 * 4) - *(float *)(in_EAX + iVar12 * 4);
      local_70 = (float *)(iVar16 + in_ECX);
      iVar12 = iVar17 + in_ECX;
      local_40 = (float *)((int)local_40 + -1);
      in_EDX[iVar11] = *(float *)(in_EAX + iVar16 * 4) - *(float *)(in_EAX + iVar17 * 4);
    } while (local_40 != (float *)0x0);
  }
  if ((int)local_54 < param_1) {
    local_58 = (float *)(in_EAX + local_68 * 4);
    local_44 = (float *)(param_1 - (int)local_54);
    pfVar13 = (float *)(in_EAX + iVar12 * 4);
    local_4c = (float *)(in_EAX + (int)local_70 * 4);
    do {
      fVar1 = *local_4c;
      fVar2 = *pfVar13;
      fVar3 = *(float *)(in_EAX + iVar15 * 4) + *local_58;
      in_EDX[iVar15 * 4] = fVar1 + fVar2 + fVar3;
      in_EDX[in_ECX * 4 + iVar15 * 4 + -1] = fVar3 - (fVar1 + fVar2);
      iVar12 = iVar15 * 4 + in_ECX * 2;
      fVar1 = *local_58;
      local_58 = local_58 + in_ECX;
      in_EDX[iVar12 + -1] = *(float *)(in_EAX + iVar15 * 4) - fVar1;
      iVar15 = iVar15 + in_ECX;
      fVar1 = *pfVar13;
      pfVar13 = pfVar13 + in_ECX;
      local_44 = (float *)((int)local_44 + -1);
      in_EDX[iVar12] = *local_4c - fVar1;
      local_4c = local_4c + in_ECX;
    } while (local_44 != (float *)0x0);
  }
  if (1 < (int)in_ECX) {
    if (in_ECX != 2) {
      local_68 = 0;
      if (0 < param_1) {
        local_40 = (float *)(iVar14 * 4);
        local_30 = (float *)param_1;
        local_44 = in_EDX;
        do {
          iVar12 = in_ECX * 2 + local_68 * 4;
          if (2 < (int)in_ECX) {
            local_58 = local_44;
            local_4c = param_4;
            pfVar21 = (float *)(param_2 + 4);
            local_34 = (in_ECX - 3 >> 1) + 1;
            pfVar13 = local_40;
            local_70 = in_EDX + in_ECX * 2 + local_68 * 4;
            local_5c = in_EDX + iVar12;
            local_54 = (float *)(in_EAX + local_68 * 4);
            local_48 = in_EDX + iVar12 + in_ECX * 2;
            do {
              iVar12 = (int)pfVar13 + 8;
              fVar1 = *(float *)((int)pfVar13 + 4 + in_EAX);
              iVar15 = iVar14 * 4 + iVar12;
              fVar5 = *pfVar21 * *(float *)(iVar12 + in_EAX) + fVar1 * pfVar21[-1];
              fVar4 = *(float *)(iVar12 + in_EAX) * pfVar21[-1] - *pfVar21 * fVar1;
              fVar1 = *(float *)(iVar15 + -4 + in_EAX);
              fVar2 = *(float *)((param_3 - (int)param_4) + (int)local_4c);
              fVar3 = *(float *)((param_3 - param_2) + (int)pfVar21);
              iVar11 = iVar15 + iVar14 * 4;
              fVar7 = fVar2 * fVar1 + fVar3 * *(float *)(iVar15 + in_EAX);
              fVar6 = *(float *)(iVar15 + in_EAX) * fVar2 - fVar3 * fVar1;
              fVar1 = *(float *)(iVar11 + -4 + in_EAX);
              fVar2 = *(float *)(((int)param_4 - param_2) + (int)pfVar21);
              fVar3 = *(float *)(iVar11 + in_EAX);
              fVar8 = *local_4c * fVar1 + fVar2 * fVar3;
              fVar1 = fVar3 * *local_4c - fVar2 * fVar1;
              fVar2 = fVar5 + fVar8;
              fVar8 = fVar8 - fVar5;
              fVar3 = fVar4 + fVar1;
              fVar4 = fVar4 - fVar1;
              fVar1 = local_54[2];
              fVar5 = fVar6 + fVar1;
              fVar1 = fVar1 - fVar6;
              local_4c = local_4c + 2;
              pfVar21 = pfVar21 + 2;
              local_34 = local_34 + -1;
              fVar6 = fVar7 + local_54[1];
              fVar7 = local_54[1] - fVar7;
              local_58[1] = fVar2 + fVar6;
              local_58[2] = fVar3 + fVar5;
              local_5c[-3] = fVar7 - fVar4;
              local_5c[-2] = fVar8 - fVar1;
              local_70[1] = fVar4 + fVar7;
              local_70[2] = fVar1 + fVar8;
              local_48[-3] = fVar6 - fVar2;
              local_48[-2] = fVar3 - fVar5;
              pfVar13 = (float *)iVar12;
              local_70 = local_70 + 2;
              local_5c = local_5c + -2;
              local_58 = local_58 + 2;
              local_54 = local_54 + 2;
              local_48 = local_48 + -2;
            } while (local_34 != 0);
          }
          local_44 = local_44 + in_ECX * 4;
          local_40 = (float *)((int)local_40 + in_ECX * 4);
          local_68 = local_68 + in_ECX;
          local_30 = (float *)((int)local_30 + -1);
        } while (local_30 != (float *)0x0);
      }
      if ((in_ECX & 1) != 0) {
        return;
      }
    }
    fVar1 = _DAT_0081703c;
    local_68 = (in_ECX - 1) + iVar14;
    local_70 = (float *)(local_68 + iVar14 * 2);
    local_54 = (float *)0x0;
    uVar18 = in_ECX;
    local_58 = (float *)in_ECX;
    if (3 < param_1) {
      fVar2 = -_DAT_0081703c;
      local_64 = in_EDX + in_ECX * 3;
      local_5c = (float *)(in_ECX * 4 + -4 + in_EAX);
      local_30 = (float *)((param_1 - 4U >> 2) + 1);
      local_54 = (float *)((int)local_30 * 4);
      pfVar13 = (float *)(in_EAX + (local_68 + iVar14) * 4);
      do {
        fVar3 = *(float *)(in_EAX + (int)local_70 * 4);
        fVar4 = *(float *)(in_EAX + local_68 * 4);
        local_58 = (float *)((int)local_58 + in_ECX * 4);
        fVar5 = (fVar4 + fVar3) * fVar2;
        fVar3 = (fVar4 - fVar3) * fVar1;
        in_EDX[uVar18 - 1] = *local_5c + fVar3;
        local_64[-1] = *local_5c - fVar3;
        in_EDX[uVar18] = fVar5 - *pfVar13;
        pfVar21 = pfVar13 + in_ECX;
        iVar15 = uVar18 + in_ECX * 4;
        *local_64 = fVar5 + *pfVar13;
        local_64 = local_64 + in_ECX * 4;
        local_5c = local_5c + in_ECX;
        fVar3 = *(float *)(in_EAX + ((int)local_70 + in_ECX) * 4);
        fVar4 = *(float *)(in_EAX + (local_68 + in_ECX) * 4);
        iVar12 = (int)local_70 + in_ECX + in_ECX;
        local_68 = local_68 + in_ECX + in_ECX;
        fVar5 = (fVar4 + fVar3) * fVar2;
        fVar3 = (fVar4 - fVar3) * fVar1;
        in_EDX[iVar15 + -1] = *local_5c + fVar3;
        local_64[-1] = *local_5c - fVar3;
        in_EDX[iVar15] = fVar5 - *pfVar21;
        pfVar13 = pfVar21 + in_ECX;
        iVar15 = iVar15 + in_ECX * 4;
        *local_64 = fVar5 + *pfVar21;
        local_64 = local_64 + in_ECX * 4;
        local_5c = local_5c + in_ECX;
        fVar3 = *(float *)(in_EAX + iVar12 * 4);
        fVar4 = *(float *)(in_EAX + local_68 * 4);
        fVar5 = (fVar4 + fVar3) * fVar2;
        iVar12 = iVar12 + in_ECX;
        local_68 = local_68 + in_ECX;
        fVar3 = (fVar4 - fVar3) * fVar1;
        in_EDX[iVar15 + -1] = *local_5c + fVar3;
        local_64[-1] = *local_5c - fVar3;
        in_EDX[iVar15] = fVar5 - *pfVar13;
        pfVar21 = pfVar13 + in_ECX;
        iVar15 = iVar15 + in_ECX * 4;
        *local_64 = fVar5 + *pfVar13;
        local_64 = local_64 + in_ECX * 4;
        local_5c = local_5c + in_ECX;
        fVar3 = *(float *)(in_EAX + iVar12 * 4);
        fVar4 = *(float *)(in_EAX + local_68 * 4);
        local_70 = (float *)(iVar12 + in_ECX);
        local_68 = local_68 + in_ECX;
        fVar5 = (fVar4 + fVar3) * fVar2;
        fVar3 = (fVar4 - fVar3) * fVar1;
        in_EDX[iVar15 + -1] = *local_5c + fVar3;
        local_64[-1] = *local_5c - fVar3;
        in_EDX[iVar15] = fVar5 - *pfVar21;
        pfVar13 = pfVar21 + in_ECX;
        uVar18 = iVar15 + in_ECX * 4;
        *local_64 = fVar5 + *pfVar21;
        local_64 = local_64 + in_ECX * 4;
        local_5c = local_5c + in_ECX;
        local_30 = (float *)((int)local_30 + -1);
      } while (local_30 != (float *)0x0);
    }
    if ((int)local_54 < param_1) {
      local_40 = (float *)(in_EAX + (int)local_70 * 4);
      local_30 = (float *)(in_EAX + local_68 * 4);
      pfVar13 = in_EDX + uVar18 + in_ECX * 2;
      pfVar21 = in_EDX + uVar18;
      pfVar10 = (float *)(in_EAX + (local_68 + iVar14) * 4);
      pfVar9 = (float *)(in_EAX + -4 + (int)local_58 * 4);
      param_1 = param_1 - (int)local_54;
      do {
        fVar2 = *local_40;
        fVar3 = *local_30;
        local_40 = local_40 + in_ECX;
        local_30 = local_30 + in_ECX;
        fVar4 = (fVar3 + fVar2) * -fVar1;
        fVar3 = (fVar3 - fVar2) * fVar1;
        pfVar21[-1] = *pfVar9 + fVar3;
        fVar2 = *pfVar9;
        pfVar9 = pfVar9 + in_ECX;
        pfVar13[-1] = fVar2 - fVar3;
        *pfVar21 = fVar4 - *pfVar10;
        pfVar21 = pfVar21 + in_ECX * 4;
        fVar2 = *pfVar10;
        pfVar10 = pfVar10 + in_ECX;
        *pfVar13 = fVar4 + fVar2;
        pfVar13 = pfVar13 + in_ECX * 4;
        param_1 = param_1 + -1;
      } while (param_1 != 0);
    }
  }
  return;
}

