/* Ghidra pseudocode, not original source.
 * ev_5bc2cffe930f75cca3d7b3a74e2b00ef78f9b6b1aa332ee39fd35bfa060f9fa0
 * Entry: 0x6b3b50; label: FUN_006b3b50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int * FUN_006b3b50(int *param_1,int *param_2,int param_3)

{
  float fVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  void *_Dst;
  int *piVar7;
  int iVar8;
  float *pfVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  float local_24;
  int local_20;
  int local_14;
  int local_c;
  
  piVar2 = (int *)*param_1;
  iVar10 = piVar2[1];
  iVar11 = *piVar2;
  iVar3 = piVar2[2];
  iVar4 = piVar2[3];
  iVar5 = (iVar10 - iVar11) / iVar3;
  piVar6 = (int *)FUN_006a1550();
  _Dst = (void *)FUN_006a1550();
  *piVar6 = (int)_Dst;
  _memset(_Dst,0,(((iVar10 - iVar11) * param_3) / iVar3) * 4);
  local_20 = *piVar2 / param_3;
  local_c = 0;
  if (0 < iVar5) {
    iVar10 = iVar4 + -1;
    do {
      local_24 = 0.0;
      local_14 = 0;
      fVar1 = 0.0;
      if (0 < iVar3) {
        iVar11 = local_20 * 4;
        do {
          if (local_24 < ABS(*(float *)(iVar11 + *param_2))) {
            local_24 = ABS(*(float *)(iVar11 + *param_2));
          }
          iVar12 = 1;
          if (3 < param_3 + -1) {
            iVar8 = (param_3 - 5U >> 2) + 1;
            piVar7 = param_2 + 3;
            iVar12 = iVar8 * 4 + 1;
            do {
              if (fVar1 < ABS(*(float *)(piVar7[-2] + iVar11))) {
                fVar1 = ABS(*(float *)(piVar7[-2] + iVar11));
              }
              if (fVar1 < ABS(*(float *)(piVar7[-1] + iVar11))) {
                fVar1 = ABS(*(float *)(piVar7[-1] + iVar11));
              }
              if (fVar1 < ABS(*(float *)(iVar11 + *piVar7))) {
                fVar1 = ABS(*(float *)(iVar11 + *piVar7));
              }
              if (fVar1 < ABS(*(float *)(piVar7[1] + iVar11))) {
                fVar1 = ABS(*(float *)(piVar7[1] + iVar11));
              }
              piVar7 = piVar7 + 4;
              iVar8 = iVar8 + -1;
            } while (iVar8 != 0);
          }
          for (; iVar12 < param_3; iVar12 = iVar12 + 1) {
            if (fVar1 < ABS(*(float *)(param_2[iVar12] + iVar11))) {
              fVar1 = ABS(*(float *)(param_2[iVar12] + iVar11));
            }
          }
          local_20 = local_20 + 1;
          local_14 = local_14 + param_3;
          iVar11 = iVar11 + 4;
        } while (local_14 < iVar3);
      }
      iVar11 = 0;
      if (3 < iVar10) {
        pfVar9 = (float *)(piVar2 + 0x185);
        do {
          if ((local_24 <= pfVar9[-0x40]) && (fVar1 <= *pfVar9)) goto LAB_006b3dfc;
          if ((local_24 <= pfVar9[-0x3f]) && (fVar1 <= pfVar9[1])) {
            iVar11 = iVar11 + 1;
            goto LAB_006b3dfc;
          }
          if ((local_24 <= pfVar9[-0x3e]) && (fVar1 <= pfVar9[2])) {
            iVar11 = iVar11 + 2;
            goto LAB_006b3dfc;
          }
          if ((local_24 <= pfVar9[-0x3d]) && (fVar1 <= pfVar9[3])) {
            iVar11 = iVar11 + 3;
            goto LAB_006b3dfc;
          }
          iVar11 = iVar11 + 4;
          pfVar9 = pfVar9 + 4;
        } while (iVar11 < iVar4 + -4);
      }
      if (iVar11 < iVar10) {
        pfVar9 = (float *)(piVar2 + iVar11 + 0x185);
        do {
          if ((local_24 <= pfVar9[-0x40]) && (fVar1 <= *pfVar9)) break;
          iVar11 = iVar11 + 1;
          pfVar9 = pfVar9 + 1;
        } while (iVar11 < iVar10);
      }
LAB_006b3dfc:
      *(int *)(*piVar6 + local_c * 4) = iVar11;
      local_c = local_c + 1;
    } while (local_c < iVar5);
  }
  param_1[10] = param_1[10] + 1;
  return piVar6;
}

