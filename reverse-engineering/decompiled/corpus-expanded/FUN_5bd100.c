/* Ghidra pseudocode, not original source.
 * ev_71ce34dfbc3e25ecc670a7014d4d5fe50c303635112430d697820e3c5a49cfb6
 * Entry: 0x5bd100; label: FUN_005bd100
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_005bd100(char *param_1,float param_2,int param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  char cVar9;
  float10 fVar10;
  float10 fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  int iVar17;
  int iVar18;
  float *pfVar19;
  float10 fVar20;
  float local_64;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_20;
  float local_14;
  
  fVar10 = (float10)1;
  local_58 = (float)fVar10;
  fVar11 = (float10)0;
  local_54 = (float)fVar11;
  iVar18 = (int)param_1[1];
  fVar1 = (float)fVar11;
  fVar2 = (float)fVar11;
  local_64 = 0.5;
  param_2 = param_2 / (*(float *)(param_1 + 0x4c) * *(float *)(param_1 + 0x44)) -
            *(float *)(param_1 + 0x54);
  fVar20 = (float10)param_2;
  if (fVar20 <= fVar10) {
    if (fVar20 < fVar11) {
      param_2 = (float)fVar11;
      fVar20 = (float10)param_2;
    }
  }
  else {
    param_2 = (float)fVar10;
    fVar20 = (float10)param_2;
  }
  if (param_3 < 1) {
    param_3 = 3;
  }
  iVar17 = 1;
  if (1 < iVar18) {
    pfVar19 = (float *)(param_1 + 8);
    do {
      if (fVar20 <= (float10)*pfVar19) {
        cVar9 = *param_1;
        if (cVar9 == '\0') {
          return (float10)((*(float *)(param_1 + iVar17 * 4 + 0x24) -
                           *(float *)(param_1 + iVar17 * 4 + 0x20)) *
                           (float)((fVar20 - (float10)*(float *)(param_1 + iVar17 * 4)) /
                                  ((float10)*(float *)(param_1 + iVar17 * 4 + 4) -
                                  (float10)*(float *)(param_1 + iVar17 * 4))) +
                          *(float *)(param_1 + iVar17 * 4 + 0x20));
        }
        if (cVar9 == '\x01') {
          if (iVar17 < 2) {
            local_14 = (*(float *)(param_1 + 4) - *(float *)(param_1 + 8)) * 0.1 +
                       *(float *)(param_1 + 4);
            fVar3 = (*(float *)(param_1 + 0x24) - *(float *)(param_1 + 0x28)) * 0.1 +
                    *(float *)(param_1 + 0x24);
          }
          else {
            local_14 = *(float *)(param_1 + iVar17 * 4 + -4);
            fVar3 = *(float *)(param_1 + iVar17 * 4 + 0x1c);
          }
          fVar4 = *(float *)(param_1 + iVar17 * 4);
          fVar5 = *(float *)(param_1 + iVar17 * 4 + 0x20);
          fVar6 = *(float *)(param_1 + iVar17 * 4 + 4);
          fVar7 = *(float *)(param_1 + iVar17 * 4 + 0x24);
          if (iVar18 + -2 < iVar17) {
            local_20 = (*(float *)(param_1 + iVar18 * 4) - *(float *)(param_1 + iVar18 * 4 + -4)) *
                       0.1 + *(float *)(param_1 + iVar18 * 4);
            fVar8 = (*(float *)(param_1 + iVar18 * 4 + 0x20) -
                    *(float *)(param_1 + iVar18 * 4 + 0x1c)) * 0.1 +
                    *(float *)(param_1 + iVar18 * 4 + 0x20);
          }
          else {
            local_20 = *(float *)(param_1 + iVar17 * 4 + 8);
            fVar8 = *(float *)(param_1 + iVar17 * 4 + 0x28);
          }
          iVar18 = 0;
          local_5c = fVar4;
          local_50 = fVar6;
          local_4c = fVar4;
          if (3 < param_3) {
            iVar17 = (param_3 - 4U >> 2) + 1;
            iVar18 = iVar17 * 4;
            fVar15 = (fVar6 * 4.0 + (local_14 * 2.0 - fVar4 * 5.0)) - local_20;
            fVar14 = fVar6 - local_14;
            fVar16 = fVar4 * 2.0;
            fVar12 = local_20 + ((fVar4 * 3.0 - local_14) - fVar6 * 3.0);
            do {
              if (param_2 <= local_5c) {
                local_50 = local_5c;
                fVar2 = fVar1 - local_64;
                local_58 = fVar1;
              }
              else {
                local_4c = local_5c;
                fVar2 = local_64 + fVar1;
                local_54 = fVar1;
              }
              local_64 = local_64 * 0.5;
              fVar1 = (fVar2 * fVar2 * fVar2 * fVar12 +
                      fVar2 * fVar2 * fVar15 + fVar2 * fVar14 + fVar16) * 0.5;
              if (param_2 <= fVar1) {
                fVar13 = fVar2 - local_64;
                local_58 = fVar2;
                local_50 = fVar1;
              }
              else {
                fVar13 = local_64 + fVar2;
                local_54 = fVar2;
                local_4c = fVar1;
              }
              local_64 = local_64 * 0.5;
              fVar1 = (fVar13 * fVar13 * fVar13 * fVar12 +
                      fVar13 * fVar13 * fVar15 + fVar13 * fVar14 + fVar16) * 0.5;
              if (param_2 <= fVar1) {
                fVar2 = fVar13 - local_64;
                local_58 = fVar13;
                local_50 = fVar1;
              }
              else {
                fVar2 = local_64 + fVar13;
                local_54 = fVar13;
                local_4c = fVar1;
              }
              local_64 = local_64 * 0.5;
              fVar13 = (fVar2 * fVar2 * fVar15 + fVar2 * fVar14 + fVar16 +
                       fVar2 * fVar2 * fVar2 * fVar12) * 0.5;
              if (param_2 <= fVar13) {
                fVar1 = fVar2 - local_64;
                local_58 = fVar2;
                local_50 = fVar13;
              }
              else {
                fVar1 = local_64 + fVar2;
                local_54 = fVar2;
                local_4c = fVar13;
              }
              iVar17 = iVar17 + -1;
              local_64 = local_64 * 0.5;
              fVar2 = fVar1 * fVar1;
              local_5c = (fVar2 * fVar15 + fVar1 * fVar14 + fVar16 + fVar2 * fVar1 * fVar12) * 0.5;
            } while (iVar17 != 0);
          }
          if (iVar18 < param_3) {
            param_3 = param_3 - iVar18;
            do {
              if (param_2 <= local_5c) {
                local_50 = local_5c;
                fVar2 = fVar1 - local_64;
                local_58 = fVar1;
              }
              else {
                local_4c = local_5c;
                fVar2 = local_64 + fVar1;
                local_54 = fVar1;
              }
              fVar1 = fVar2;
              param_3 = param_3 + -1;
              local_64 = local_64 * 0.5;
              fVar2 = fVar1 * fVar1;
              local_5c = (fVar2 * fVar1 * (((fVar4 * 3.0 - local_14) - fVar6 * 3.0) + local_20) +
                         ((fVar6 * 4.0 + ((local_14 + local_14) - fVar4 * 5.0)) - local_20) * fVar2
                         + (fVar6 - local_14) * fVar1 + fVar4 + fVar4) * 0.5;
            } while (param_3 != 0);
          }
          fVar6 = (fVar7 * 4.0 + ((fVar3 + fVar3) - fVar5 * 5.0)) - fVar8;
          fVar4 = fVar7 - fVar3;
          fVar12 = fVar5 + fVar5;
          fVar8 = fVar8 + ((fVar5 * 3.0 - fVar3) - fVar7 * 3.0);
          fVar1 = (fVar2 * fVar1 * fVar8 + fVar2 * fVar6 + fVar1 * fVar4 + fVar12) * 0.5;
          if (local_5c < param_2) {
            return (float10)(fVar1 + (((local_58 * fVar4 + fVar12 + local_58 * local_58 * fVar6 +
                                       local_58 * local_58 * local_58 * fVar8) * 0.5 - fVar1) *
                                     (param_2 - local_5c)) / (local_50 - local_5c));
          }
          return (float10)(fVar1 + (((local_54 * fVar4 + fVar12 + local_54 * local_54 * fVar6 +
                                     local_54 * local_54 * local_54 * fVar8) * 0.5 - fVar1) *
                                   (param_2 - local_5c)) / (local_4c - local_5c));
        }
        if (cVar9 == '\x02') {
          return fVar11;
        }
      }
      iVar17 = iVar17 + 1;
      pfVar19 = pfVar19 + 1;
    } while (iVar17 < iVar18);
  }
  return fVar11;
}

