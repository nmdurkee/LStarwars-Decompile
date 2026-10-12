/* Ghidra analysis pseudocode, not original source.
 * ev_a0c592da085b7a74f005db934e1c866d8df8930552270784c21655c1c3dfc310
 * Entry: 0x6aa000; label: FUN_006aa000
 */

void FUN_006aa000(int param_1,int param_2)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float *in_EAX;
  float *pfVar5;
  uint in_ECX;
  int iVar6;
  int iVar7;
  int iVar8;
  float *pfVar9;
  uint uVar10;
  float *pfVar11;
  float *pfVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  float *unaff_EDI;
  float *local_2c;
  float *local_28;
  float *local_24;
  float *local_20;
  float *local_1c;
  float *local_18;
  int local_10;
  int local_c;
  
  iVar14 = in_ECX * param_1;
  iVar6 = 0;
  local_2c = (float *)0x0;
  iVar8 = iVar14;
  if (3 < param_1) {
    iVar13 = (param_1 - 4U >> 2) + 1;
    local_2c = (float *)(iVar13 * 4);
    pfVar12 = unaff_EDI + in_ECX * 2 + -1;
    do {
      unaff_EDI[iVar6 * 2] = in_EAX[iVar6] + in_EAX[iVar8];
      iVar7 = iVar6 + in_ECX;
      iVar15 = iVar8 + in_ECX;
      *pfVar12 = in_EAX[iVar6] - in_EAX[iVar8];
      pfVar12 = pfVar12 + in_ECX * 2;
      unaff_EDI[iVar7 * 2] = in_EAX[iVar7] + in_EAX[iVar15];
      iVar8 = iVar7 + in_ECX;
      iVar6 = iVar15 + in_ECX;
      *pfVar12 = in_EAX[iVar7] - in_EAX[iVar15];
      pfVar12 = pfVar12 + in_ECX * 2;
      unaff_EDI[iVar8 * 2] = in_EAX[iVar8] + in_EAX[iVar6];
      iVar7 = iVar8 + in_ECX;
      iVar15 = iVar6 + in_ECX;
      *pfVar12 = in_EAX[iVar8] - in_EAX[iVar6];
      unaff_EDI[iVar7 * 2] = in_EAX[iVar7] + in_EAX[iVar15];
      iVar6 = iVar7 + in_ECX;
      iVar8 = iVar15 + in_ECX;
      pfVar12[in_ECX * 2] = in_EAX[iVar7] - in_EAX[iVar15];
      pfVar12 = pfVar12 + in_ECX * 2 + in_ECX * 2;
      iVar13 = iVar13 + -1;
    } while (iVar13 != 0);
  }
  if ((int)local_2c < param_1) {
    pfVar12 = unaff_EDI + iVar6 * 2;
    pfVar5 = in_EAX + iVar6;
    local_28 = unaff_EDI + in_ECX * 2 + iVar6 * 2 + -1;
    local_18 = (float *)(param_1 - (int)local_2c);
    pfVar11 = in_EAX + iVar8;
    do {
      *pfVar12 = *pfVar5 + *pfVar11;
      *local_28 = *pfVar5 - *pfVar11;
      local_28 = local_28 + in_ECX * 2;
      pfVar12 = pfVar12 + in_ECX * 2;
      pfVar5 = pfVar5 + in_ECX;
      pfVar11 = pfVar11 + in_ECX;
      local_18 = (float *)((int)local_18 + -1);
    } while (local_18 != (float *)0x0);
  }
  if (1 < (int)in_ECX) {
    if (in_ECX != 2) {
      if (0 < param_1) {
        local_18 = in_EAX + iVar14;
        local_20 = unaff_EDI + in_ECX * 2;
        local_10 = param_1;
        local_1c = in_EAX;
        pfVar12 = unaff_EDI;
        do {
          if (2 < (int)in_ECX) {
            local_2c = local_18;
            local_28 = (float *)(param_2 + 4);
            iVar8 = (in_ECX - 3 >> 1) + 1;
            pfVar5 = local_1c;
            pfVar11 = local_20;
            local_24 = pfVar12;
            do {
              pfVar1 = local_28 + -1;
              fVar2 = *local_28;
              fVar3 = local_2c[2];
              pfVar9 = pfVar5 + 2;
              local_28 = local_28 + 2;
              iVar8 = iVar8 + -1;
              fVar4 = *pfVar1 * local_2c[1] + fVar3 * fVar2;
              fVar2 = fVar3 * *pfVar1 - fVar2 * local_2c[1];
              local_24[2] = *pfVar9 + fVar2;
              pfVar11[-2] = fVar2 - *pfVar9;
              local_24[1] = pfVar5[1] + fVar4;
              pfVar11[-3] = pfVar5[1] - fVar4;
              pfVar5 = pfVar9;
              pfVar11 = pfVar11 + -2;
              local_2c = local_2c + 2;
              local_24 = local_24 + 2;
            } while (iVar8 != 0);
          }
          local_20 = local_20 + in_ECX * 2;
          pfVar12 = pfVar12 + in_ECX * 2;
          local_1c = local_1c + in_ECX;
          local_18 = local_18 + in_ECX;
          local_10 = local_10 + -1;
        } while (local_10 != 0);
      }
      uVar10 = in_ECX & 0x80000001;
      if ((int)uVar10 < 0) {
        uVar10 = (uVar10 - 1 | 0xfffffffe) + 1;
      }
      if (uVar10 == 1) {
        return;
      }
    }
    iVar8 = in_ECX - 1;
    iVar14 = iVar8 + iVar14;
    local_2c = (float *)0x0;
    uVar10 = in_ECX;
    if (3 < param_1) {
      local_c = (param_1 - 4U >> 2) + 1;
      local_2c = (float *)(local_c * 4);
      do {
        iVar6 = in_ECX * 2;
        unaff_EDI[uVar10] = -in_EAX[iVar14];
        unaff_EDI[uVar10 - 1] = in_EAX[iVar8];
        iVar13 = uVar10 + iVar6;
        iVar7 = iVar14 + in_ECX + in_ECX;
        unaff_EDI[iVar13] = -in_EAX[iVar14 + in_ECX];
        iVar14 = iVar8 + in_ECX + in_ECX;
        unaff_EDI[iVar13 + -1] = in_EAX[iVar8 + in_ECX];
        iVar13 = iVar13 + iVar6;
        iVar8 = iVar7 + in_ECX;
        unaff_EDI[iVar13] = -in_EAX[iVar7];
        iVar7 = iVar14 + in_ECX;
        unaff_EDI[iVar13 + -1] = in_EAX[iVar14];
        iVar13 = iVar13 + iVar6;
        iVar14 = iVar8 + in_ECX;
        unaff_EDI[iVar13] = -in_EAX[iVar8];
        iVar8 = iVar7 + in_ECX;
        unaff_EDI[iVar13 + -1] = in_EAX[iVar7];
        uVar10 = iVar13 + iVar6;
        local_c = local_c + -1;
      } while (local_c != 0);
    }
    if ((int)local_2c < param_1) {
      pfVar12 = in_EAX + iVar8;
      pfVar5 = in_EAX + iVar14;
      param_1 = param_1 - (int)local_2c;
      pfVar11 = unaff_EDI + uVar10;
      do {
        fVar2 = *pfVar5;
        pfVar5 = pfVar5 + in_ECX;
        *pfVar11 = -fVar2;
        fVar2 = *pfVar12;
        pfVar12 = pfVar12 + in_ECX;
        pfVar11[-1] = fVar2;
        pfVar11 = pfVar11 + in_ECX * 2;
        param_1 = param_1 + -1;
      } while (param_1 != 0);
    }
  }
  return;
}

