/* Ghidra pseudocode, not original source.
 * ev_0b75f810defb69f43ff4ee181673bf6e816c7d4f879f3f967a03f199d8168922
 * Entry: 0x6ac4f0; label: FUN_006ac4f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006ac4f0(int param_1,int param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  int in_EAX;
  float *pfVar6;
  float *in_ECX;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  float *pfVar11;
  uint uVar12;
  uint in_EDX;
  float *pfVar13;
  float *pfVar14;
  int local_2c;
  float *local_28;
  float *local_24;
  float *local_1c;
  float *local_18;
  float *local_14;
  int local_10;
  int local_c;
  
  iVar7 = in_EDX * param_1;
  iVar8 = 0;
  iVar5 = in_EDX * 2;
  local_2c = 0;
  local_24 = (float *)0x0;
  if (3 < param_1) {
    local_14 = (float *)((param_1 - 4U >> 2) + 1);
    local_24 = (float *)((int)local_14 * 4);
    pfVar11 = in_ECX + iVar7;
    do {
      iVar9 = iVar5 + -1 + local_2c;
      in_ECX[iVar8] = *(float *)(in_EAX + local_2c * 4) + *(float *)(in_EAX + iVar9 * 4);
      iVar8 = iVar8 + in_EDX;
      *pfVar11 = *(float *)(in_EAX + local_2c * 4) - *(float *)(in_EAX + iVar9 * 4);
      pfVar11 = pfVar11 + in_EDX;
      pfVar13 = (float *)(in_EAX + (iVar5 + -1 + iVar8 * 2) * 4);
      in_ECX[iVar8] = *(float *)(in_EAX + iVar8 * 8) + *pfVar13;
      iVar9 = iVar8 + in_EDX;
      *pfVar11 = *(float *)(in_EAX + iVar8 * 8) - *pfVar13;
      pfVar11 = pfVar11 + in_EDX;
      pfVar13 = (float *)(in_EAX + (iVar5 + -1 + iVar9 * 2) * 4);
      in_ECX[iVar9] = *(float *)(in_EAX + iVar9 * 8) + *pfVar13;
      iVar10 = iVar9 + in_EDX;
      *pfVar11 = *(float *)(in_EAX + iVar9 * 8) - *pfVar13;
      pfVar13 = (float *)(in_EAX + (iVar5 + -1 + iVar10 * 2) * 4);
      in_ECX[iVar10] = *(float *)(in_EAX + iVar10 * 8) + *pfVar13;
      iVar8 = iVar10 + in_EDX;
      pfVar11[in_EDX] = *(float *)(in_EAX + iVar10 * 8) - *pfVar13;
      pfVar11 = pfVar11 + in_EDX + in_EDX;
      local_14 = (float *)((int)local_14 + -1);
      local_2c = iVar8 * 2;
    } while (local_14 != (float *)0x0);
  }
  if ((int)local_24 < param_1) {
    local_18 = (float *)(param_1 - (int)local_24);
    local_14 = in_ECX + iVar7 + iVar8;
    do {
      iVar9 = iVar5 + -1 + local_2c;
      in_ECX[iVar8] = *(float *)(in_EAX + local_2c * 4) + *(float *)(in_EAX + iVar9 * 4);
      iVar8 = iVar8 + in_EDX;
      *local_14 = *(float *)(in_EAX + local_2c * 4) - *(float *)(in_EAX + iVar9 * 4);
      local_14 = local_14 + in_EDX;
      local_18 = (float *)((int)local_18 + -1);
      local_2c = iVar8 * 2;
    } while (local_18 != (float *)0x0);
  }
  if (1 < (int)in_EDX) {
    if (in_EDX != 2) {
      iVar8 = 0;
      local_2c = 0;
      if (0 < param_1) {
        local_18 = in_ECX + iVar7;
        local_c = param_1;
        local_14 = in_ECX;
        do {
          if (2 < (int)in_EDX) {
            local_24 = local_18;
            local_1c = local_14;
            local_10 = (in_EDX - 3 >> 1) + 1;
            pfVar11 = (float *)(in_EAX + iVar8 * 4);
            pfVar13 = (float *)(in_EAX + (iVar5 + iVar8) * 4);
            local_28 = (float *)(param_2 + 4);
            do {
              pfVar6 = pfVar11 + 2;
              pfVar14 = pfVar13 + -2;
              local_1c[1] = pfVar11[1] + pfVar13[-3];
              fVar1 = pfVar11[1];
              fVar2 = pfVar13[-3];
              local_1c[2] = *pfVar6 - *pfVar14;
              fVar3 = *pfVar14;
              fVar4 = *pfVar6;
              local_24[1] = local_28[-1] * (fVar1 - fVar2) - *local_28 * (fVar3 + fVar4);
              local_10 = local_10 + -1;
              local_24[2] = (fVar3 + fVar4) * local_28[-1] + *local_28 * (fVar1 - fVar2);
              pfVar11 = pfVar6;
              pfVar13 = pfVar14;
              local_28 = local_28 + 2;
              local_24 = local_24 + 2;
              local_1c = local_1c + 2;
            } while (local_10 != 0);
          }
          local_2c = local_2c + in_EDX;
          local_18 = local_18 + in_EDX;
          local_14 = local_14 + in_EDX;
          iVar8 = local_2c * 2;
          local_c = local_c + -1;
        } while (local_c != 0);
      }
      uVar12 = in_EDX & 0x80000001;
      if ((int)uVar12 < 0) {
        uVar12 = (uVar12 - 1 | 0xfffffffe) + 1;
      }
      if (uVar12 == 1) {
        return;
      }
    }
    iVar8 = in_EDX - 1;
    local_24 = (float *)0x0;
    local_2c = iVar8;
    if (3 < param_1) {
      local_c = (param_1 - 4U >> 2) + 1;
      local_24 = (float *)(local_c * 4);
      pfVar11 = in_ECX + iVar8 + iVar7;
      do {
        fVar1 = *(float *)(in_EAX + iVar8 * 4);
        in_ECX[local_2c] = fVar1 + fVar1;
        fVar1 = *(float *)(in_EAX + 4 + iVar8 * 4);
        iVar8 = iVar8 + iVar5;
        *pfVar11 = -(fVar1 + fVar1);
        pfVar11 = pfVar11 + in_EDX;
        fVar1 = *(float *)(in_EAX + iVar8 * 4);
        in_ECX[local_2c + in_EDX] = fVar1 + fVar1;
        local_2c = local_2c + in_EDX + in_EDX;
        fVar1 = *(float *)(in_EAX + 4 + iVar8 * 4);
        iVar8 = iVar8 + iVar5;
        *pfVar11 = -(fVar1 + fVar1);
        pfVar11 = pfVar11 + in_EDX;
        fVar1 = *(float *)(in_EAX + iVar8 * 4);
        in_ECX[local_2c] = fVar1 + fVar1;
        local_2c = local_2c + in_EDX;
        fVar1 = *(float *)(in_EAX + 4 + iVar8 * 4);
        iVar8 = iVar8 + iVar5;
        *pfVar11 = -(fVar1 + fVar1);
        fVar1 = *(float *)(in_EAX + iVar8 * 4);
        in_ECX[local_2c] = fVar1 + fVar1;
        local_2c = local_2c + in_EDX;
        fVar1 = *(float *)(in_EAX + 4 + iVar8 * 4);
        iVar8 = iVar8 + iVar5;
        pfVar11[in_EDX] = -(fVar1 + fVar1);
        pfVar11 = pfVar11 + in_EDX + in_EDX;
        local_c = local_c + -1;
      } while (local_c != 0);
    }
    if ((int)local_24 < param_1) {
      pfVar11 = in_ECX + local_2c;
      param_1 = param_1 - (int)local_24;
      pfVar13 = in_ECX + local_2c + iVar7;
      pfVar6 = (float *)(in_EAX + iVar8 * 4);
      do {
        *pfVar11 = *pfVar6 + *pfVar6;
        pfVar11 = pfVar11 + in_EDX;
        pfVar14 = pfVar6 + 1;
        pfVar6 = pfVar6 + in_EDX * 2;
        *pfVar13 = -(*pfVar14 + *pfVar14);
        pfVar13 = pfVar13 + in_EDX;
        param_1 = param_1 + -1;
      } while (param_1 != 0);
    }
  }
  return;
}

