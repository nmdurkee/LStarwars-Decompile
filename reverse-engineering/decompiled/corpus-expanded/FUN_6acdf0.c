/* Ghidra pseudocode, not original source.
 * ev_0b75f810defb69f43ff4ee181673bf6e816c7d4f879f3f967a03f199d8168922
 * Entry: 0x6acdf0; label: FUN_006acdf0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006acdf0(int param_1,int param_2,int param_3,float *param_4)

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
  int in_ECX;
  float *pfVar9;
  uint in_EDX;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  float *pfVar16;
  int iVar17;
  uint uVar18;
  uint local_64;
  int local_60;
  int local_54;
  int local_48;
  float *local_44;
  float *local_40;
  float *local_3c;
  float *local_34;
  int local_30;
  float *local_2c;
  int local_28;
  float *local_24;
  int local_c;
  float *local_8;
  
  iVar10 = in_EDX * param_1;
  local_64 = 0;
  iVar14 = in_EDX * 4;
  local_60 = 0;
  local_34 = (float *)0x0;
  if (3 < param_1) {
    iVar17 = in_EDX * 8;
    local_48 = iVar10 * 4;
    local_24 = (float *)((param_1 - 4U >> 2) + 1);
    local_34 = (float *)((int)local_24 * 4);
    iVar15 = iVar17;
    do {
      fVar1 = *(float *)(in_ECX + -4 + iVar15);
      fVar1 = fVar1 + fVar1;
      fVar4 = *(float *)(iVar15 + in_ECX) + *(float *)(iVar15 + in_ECX);
      fVar2 = *(float *)(in_ECX + local_60 * 4);
      fVar3 = *(float *)(in_ECX + -4 + iVar17 + iVar15);
      fVar5 = fVar2 - fVar3;
      fVar3 = fVar3 + fVar2;
      *(float *)(in_EAX + local_64 * 4) = fVar1 + fVar3;
      *(float *)(in_EAX + local_48) = fVar5 - fVar4;
      iVar13 = local_48 + iVar10 * 4;
      *(float *)(in_EAX + iVar13) = fVar3 - fVar1;
      *(float *)(iVar10 * 4 + iVar13 + in_EAX) = fVar5 + fVar4;
      local_48 = local_48 + in_EDX * 4;
      iVar15 = iVar15 + in_EDX * 0x10;
      fVar1 = *(float *)(in_ECX + -4 + iVar15);
      fVar1 = fVar1 + fVar1;
      fVar4 = *(float *)(iVar15 + in_ECX) + *(float *)(iVar15 + in_ECX);
      fVar2 = *(float *)(in_ECX + (local_60 + iVar14) * 4);
      fVar3 = *(float *)(in_ECX + -4 + iVar17 + iVar15);
      fVar5 = fVar2 - fVar3;
      fVar3 = fVar3 + fVar2;
      *(float *)(in_EAX + (local_64 + in_EDX) * 4) = fVar1 + fVar3;
      iVar13 = local_60 + iVar14 + iVar14;
      *(float *)(local_48 + in_EAX) = fVar5 - fVar4;
      iVar11 = local_48 + iVar10 * 4;
      iVar12 = local_64 + in_EDX + in_EDX;
      *(float *)(iVar11 + in_EAX) = fVar3 - fVar1;
      *(float *)(iVar11 + iVar10 * 4 + in_EAX) = fVar5 + fVar4;
      local_48 = local_48 + in_EDX * 4;
      iVar15 = iVar15 + in_EDX * 0x10;
      fVar1 = *(float *)(in_ECX + -4 + iVar15);
      fVar1 = fVar1 + fVar1;
      fVar4 = *(float *)(iVar15 + in_ECX) + *(float *)(iVar15 + in_ECX);
      iVar11 = iVar13 + iVar14;
      fVar2 = *(float *)(in_ECX + iVar13 * 4);
      fVar3 = *(float *)(in_ECX + -4 + iVar17 + iVar15);
      iVar13 = iVar12 + in_EDX;
      fVar5 = fVar2 - fVar3;
      fVar3 = fVar3 + fVar2;
      *(float *)(in_EAX + iVar12 * 4) = fVar1 + fVar3;
      *(float *)(local_48 + in_EAX) = fVar5 - fVar4;
      iVar12 = local_48 + iVar10 * 4;
      *(float *)(iVar12 + in_EAX) = fVar3 - fVar1;
      *(float *)(iVar12 + iVar10 * 4 + in_EAX) = fVar5 + fVar4;
      local_48 = local_48 + in_EDX * 4;
      iVar15 = iVar15 + in_EDX * 0x10;
      fVar1 = *(float *)(in_ECX + -4 + iVar15);
      fVar1 = fVar1 + fVar1;
      fVar4 = *(float *)(iVar15 + in_ECX) + *(float *)(iVar15 + in_ECX);
      local_60 = iVar11 + iVar14;
      fVar2 = *(float *)(in_ECX + iVar11 * 4);
      fVar3 = *(float *)(in_ECX + -4 + iVar17 + iVar15);
      local_64 = iVar13 + in_EDX;
      fVar5 = fVar2 - fVar3;
      fVar3 = fVar3 + fVar2;
      *(float *)(in_EAX + iVar13 * 4) = fVar1 + fVar3;
      *(float *)(local_48 + in_EAX) = fVar5 - fVar4;
      iVar13 = local_48 + iVar10 * 4;
      *(float *)(iVar13 + in_EAX) = fVar3 - fVar1;
      *(float *)(iVar13 + iVar10 * 4 + in_EAX) = fVar5 + fVar4;
      local_48 = local_48 + in_EDX * 4;
      iVar15 = iVar15 + in_EDX * 0x10;
      local_24 = (float *)((int)local_24 + -1);
    } while (local_24 != (float *)0x0);
  }
  if ((int)local_34 < param_1) {
    local_30 = (local_64 + iVar10) * 4;
    local_3c = (float *)((local_60 + in_EDX * 2) * 4);
    local_24 = (float *)(in_EAX + local_64 * 4);
    local_2c = (float *)(param_1 - (int)local_34);
    local_40 = (float *)(in_ECX + local_60 * 4);
    do {
      fVar1 = *(float *)((int)local_3c + -4 + in_ECX);
      fVar1 = fVar1 + fVar1;
      fVar3 = *(float *)((int)local_3c + in_ECX) + *(float *)((int)local_3c + in_ECX);
      fVar2 = *(float *)((int)local_3c + in_EDX * 8 + -4 + in_ECX);
      fVar4 = *local_40 - fVar2;
      fVar2 = fVar2 + *local_40;
      *local_24 = fVar1 + fVar2;
      *(float *)(local_30 + in_EAX) = fVar4 - fVar3;
      iVar17 = local_30 + iVar10 * 4;
      *(float *)(iVar17 + in_EAX) = fVar2 - fVar1;
      *(float *)(iVar17 + iVar10 * 4 + in_EAX) = fVar4 + fVar3;
      local_30 = local_30 + in_EDX * 4;
      local_24 = local_24 + in_EDX;
      local_3c = (float *)((int)local_3c + in_EDX * 0x10);
      local_40 = local_40 + in_EDX * 4;
      local_2c = (float *)((int)local_2c + -1);
    } while (local_2c != (float *)0x0);
  }
  if (1 < (int)in_EDX) {
    if (in_EDX != 2) {
      local_64 = 0;
      if (0 < param_1) {
        local_24 = (float *)0x0;
        local_8 = (float *)param_1;
        do {
          iVar17 = local_64 * 4 + in_EDX * 2;
          if (2 < (int)in_EDX) {
            local_44 = (float *)(in_ECX + iVar17 * 4);
            local_34 = param_4;
            iVar15 = local_64 * 4 - (int)local_24;
            local_28 = (iVar15 + iVar10) * 4;
            local_c = (in_EDX - 3 >> 1) + 1;
            pfVar16 = (float *)(param_2 + 4);
            local_60 = in_ECX + (iVar17 + in_EDX * 2) * 4;
            local_40 = local_44;
            local_3c = (float *)(in_ECX + local_64 * 0x10);
            local_2c = (float *)(in_EAX + iVar15 * 4);
            do {
              local_28 = local_28 + 8;
              fVar1 = local_3c[2];
              fVar4 = fVar1 + *(float *)(local_60 + -8);
              fVar1 = fVar1 - *(float *)(local_60 + -8);
              fVar2 = local_40[2];
              fVar3 = local_44[-2];
              fVar5 = fVar2 - fVar3;
              fVar3 = fVar3 + fVar2;
              fVar6 = local_3c[1] - *(float *)(local_60 + -0xc);
              fVar2 = *(float *)(local_60 + -0xc) + local_3c[1];
              fVar8 = local_40[1] - local_44[-3];
              fVar7 = local_44[-3] + local_40[1];
              local_2c[1] = fVar7 + fVar2;
              fVar2 = fVar2 - fVar7;
              local_2c[2] = fVar1 + fVar5;
              fVar1 = fVar1 - fVar5;
              fVar5 = fVar6 - fVar3;
              fVar3 = fVar3 + fVar6;
              fVar6 = fVar4 + fVar8;
              fVar4 = fVar4 - fVar8;
              *(float *)(in_EAX + -4 + local_28) = pfVar16[-1] * fVar5 - *pfVar16 * fVar6;
              iVar17 = local_28 + iVar10 * 4;
              *(float *)(in_EAX + local_28) = fVar6 * pfVar16[-1] + *pfVar16 * fVar5;
              *(float *)(iVar17 + -4 + in_EAX) =
                   *(float *)((int)local_34 + (param_3 - (int)param_4)) * fVar2 -
                   *(float *)((param_3 - param_2) + (int)pfVar16) * fVar1;
              *(float *)(iVar17 + in_EAX) =
                   fVar1 * *(float *)((int)local_34 + (param_3 - (int)param_4)) +
                   *(float *)((param_3 - param_2) + (int)pfVar16) * fVar2;
              iVar17 = iVar17 + iVar10 * 4;
              *(float *)(in_EAX + -4 + iVar17) =
                   *local_34 * fVar3 - *(float *)((int)pfVar16 + ((int)param_4 - param_2)) * fVar4;
              local_c = local_c + -1;
              *(float *)(in_EAX + iVar17) =
                   fVar4 * *local_34 + *(float *)((int)pfVar16 + ((int)param_4 - param_2)) * fVar3;
              pfVar16 = pfVar16 + 2;
              local_60 = local_60 + -8;
              local_44 = local_44 + -2;
              local_40 = local_40 + 2;
              local_3c = local_3c + 2;
              local_34 = local_34 + 2;
              local_2c = local_2c + 2;
            } while (local_c != 0);
          }
          local_64 = local_64 + in_EDX;
          local_24 = (float *)((int)local_24 + in_EDX * 3);
          local_8 = (float *)((int)local_8 + -1);
        } while (local_8 != (float *)0x0);
      }
      uVar18 = in_EDX & 0x80000001;
      if ((int)uVar18 < 0) {
        uVar18 = (uVar18 - 1 | 0xfffffffe) + 1;
      }
      if (uVar18 == 1) {
        return;
      }
    }
    fVar1 = _DAT_0081704c;
    local_60 = in_EDX - 1;
    local_54 = in_EDX * 3;
    local_34 = (float *)0x0;
    local_64 = in_EDX;
    if (3 < param_1) {
      fVar2 = -_DAT_0081704c;
      local_8 = (float *)((param_1 - 4U >> 2) + 1);
      iVar17 = (local_60 + iVar10) * 4;
      local_34 = (float *)((int)local_8 * 4);
      do {
        fVar3 = *(float *)(in_ECX + local_54 * 4);
        fVar4 = *(float *)(in_ECX + local_64 * 4);
        iVar12 = local_64 + iVar14;
        fVar6 = fVar4 + fVar3;
        fVar3 = fVar3 - fVar4;
        fVar4 = *(float *)(in_ECX + -4 + local_64 * 4);
        fVar5 = *(float *)(in_ECX + -4 + local_54 * 4);
        fVar7 = fVar4 - fVar5;
        fVar5 = fVar5 + fVar4;
        *(float *)(in_EAX + local_60 * 4) = fVar5 + fVar5;
        iVar15 = iVar17 + iVar10 * 4;
        *(float *)(iVar17 + in_EAX) = (fVar7 - fVar6) * fVar1;
        *(float *)(in_EAX + iVar15) = fVar3 + fVar3;
        *(float *)(in_EAX + iVar15 + iVar10 * 4) = (fVar6 + fVar7) * fVar2;
        iVar17 = iVar17 + in_EDX * 4;
        local_54 = local_54 + iVar14;
        fVar3 = *(float *)(in_ECX + local_54 * 4);
        fVar4 = *(float *)(in_ECX + iVar12 * 4);
        fVar6 = fVar4 + fVar3;
        fVar3 = fVar3 - fVar4;
        fVar4 = *(float *)(in_ECX + -4 + iVar12 * 4);
        fVar5 = *(float *)(in_ECX + -4 + local_54 * 4);
        iVar13 = local_60 + in_EDX + in_EDX;
        fVar7 = fVar4 - fVar5;
        fVar5 = fVar5 + fVar4;
        *(float *)(in_EAX + (local_60 + in_EDX) * 4) = fVar5 + fVar5;
        iVar15 = iVar17 + iVar10 * 4;
        *(float *)(iVar17 + in_EAX) = (fVar7 - fVar6) * fVar1;
        *(float *)(in_EAX + iVar15) = fVar3 + fVar3;
        *(float *)(in_EAX + iVar15 + iVar10 * 4) = (fVar6 + fVar7) * fVar2;
        iVar17 = iVar17 + in_EDX * 4;
        iVar12 = iVar12 + iVar14;
        local_54 = local_54 + iVar14;
        fVar3 = *(float *)(in_ECX + local_54 * 4);
        fVar4 = *(float *)(in_ECX + iVar12 * 4);
        fVar6 = fVar4 + fVar3;
        iVar11 = iVar12 + iVar14;
        fVar3 = fVar3 - fVar4;
        fVar4 = *(float *)(in_ECX + -4 + iVar12 * 4);
        fVar5 = *(float *)(in_ECX + -4 + local_54 * 4);
        local_60 = iVar13 + in_EDX;
        fVar7 = fVar4 - fVar5;
        fVar5 = fVar5 + fVar4;
        *(float *)(in_EAX + iVar13 * 4) = fVar5 + fVar5;
        iVar15 = iVar17 + iVar10 * 4;
        *(float *)(iVar17 + in_EAX) = (fVar7 - fVar6) * fVar1;
        *(float *)(in_EAX + iVar15) = fVar3 + fVar3;
        *(float *)(in_EAX + iVar15 + iVar10 * 4) = (fVar6 + fVar7) * fVar2;
        iVar17 = iVar17 + in_EDX * 4;
        local_54 = local_54 + iVar14;
        fVar3 = *(float *)(in_ECX + local_54 * 4);
        fVar4 = *(float *)(in_ECX + iVar11 * 4);
        fVar6 = fVar4 + fVar3;
        fVar3 = fVar3 - fVar4;
        fVar4 = *(float *)(in_ECX + -4 + iVar11 * 4);
        fVar5 = *(float *)(in_ECX + -4 + local_54 * 4);
        fVar7 = fVar4 - fVar5;
        fVar5 = fVar5 + fVar4;
        *(float *)(in_EAX + local_60 * 4) = fVar5 + fVar5;
        iVar15 = iVar17 + iVar10 * 4;
        *(float *)(iVar17 + in_EAX) = (fVar7 - fVar6) * fVar1;
        *(float *)(in_EAX + iVar15) = fVar3 + fVar3;
        local_60 = local_60 + in_EDX;
        local_64 = iVar11 + iVar14;
        *(float *)(in_EAX + iVar15 + iVar10 * 4) = (fVar6 + fVar7) * fVar2;
        local_54 = local_54 + iVar14;
        iVar17 = iVar17 + in_EDX * 4;
        local_8 = (float *)((int)local_8 + -1);
      } while (local_8 != (float *)0x0);
    }
    if ((int)local_34 < param_1) {
      local_8 = (float *)(in_EAX + local_60 * 4);
      pfVar16 = (float *)(in_ECX + local_54 * 4);
      iVar14 = (local_60 + iVar10) * 4;
      local_c = param_1 - (int)local_34;
      pfVar9 = (float *)(in_ECX + local_64 * 4);
      do {
        fVar2 = *pfVar9 + *pfVar16;
        fVar3 = *pfVar16 - *pfVar9;
        iVar17 = iVar14 + iVar10 * 4;
        fVar5 = pfVar9[-1] - pfVar16[-1];
        fVar4 = pfVar16[-1] + pfVar9[-1];
        *local_8 = fVar4 + fVar4;
        *(float *)(iVar14 + in_EAX) = (fVar5 - fVar2) * fVar1;
        *(float *)(iVar17 + in_EAX) = fVar3 + fVar3;
        *(float *)(iVar17 + iVar10 * 4 + in_EAX) = (fVar2 + fVar5) * -fVar1;
        local_8 = local_8 + in_EDX;
        iVar14 = iVar14 + in_EDX * 4;
        pfVar16 = pfVar16 + in_EDX * 4;
        pfVar9 = pfVar9 + in_EDX * 4;
        local_c = local_c + -1;
      } while (local_c != 0);
    }
  }
  return;
}

