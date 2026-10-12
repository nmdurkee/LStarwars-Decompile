/* Ghidra analysis pseudocode, not original source.
 * ev_648e39c5173022307384bd96b6b6d54b0109fbb7542fd197fe89208a1a87d4a6
 * Entry: 0x6b3530; label: FUN_006b3530
 */

int FUN_006b3530(int *param_1,float *param_2)

{
  float fVar1;
  float *pfVar2;
  float *pfVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  float *pfVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  float local_24;
  int local_1c;
  int local_14;
  float local_10;
  
  piVar6 = *(int **)(param_1[3] + 0x28);
  iVar11 = *param_1;
  local_1c = 0;
  if (0 < iVar11) {
    iVar9 = piVar6[3];
    iVar10 = *piVar6;
    iVar4 = iVar9 >> 1;
    pfVar3 = param_2 + iVar11;
    local_14 = iVar11;
    do {
      fVar1 = pfVar3[-1];
      pfVar3 = pfVar3 + -1;
      if (*(float *)(iVar10 + iVar4 * 4) <= fVar1) {
        iVar8 = iVar9 + -1;
        iVar5 = iVar4 + 1;
        if (3 < iVar8 - iVar5) {
          pfVar2 = (float *)(iVar10 + 8 + iVar5 * 4);
          do {
            if (fVar1 < pfVar2[-2]) goto LAB_006b36c3;
            if (fVar1 < pfVar2[-1]) {
              iVar5 = iVar5 + 1;
              goto LAB_006b36c3;
            }
            if (fVar1 < *pfVar2) {
              iVar5 = iVar5 + 2;
              goto LAB_006b36c3;
            }
            if (fVar1 < pfVar2[1]) {
              iVar5 = iVar5 + 3;
              goto LAB_006b36c3;
            }
            iVar5 = iVar5 + 4;
            pfVar2 = pfVar2 + 4;
          } while (iVar5 < iVar9 + -4);
        }
        if (iVar5 < iVar8) {
          pfVar2 = (float *)(iVar10 + iVar5 * 4);
          do {
            if (fVar1 < *pfVar2) break;
            iVar5 = iVar5 + 1;
            pfVar2 = pfVar2 + 1;
          } while (iVar5 < iVar8);
        }
      }
      else {
        iVar5 = iVar4;
        if (fVar1 < *(float *)(iVar10 + -4 + iVar4 * 4)) {
          iVar5 = iVar4 + -1;
          if (3 < iVar5) {
            pfVar2 = (float *)(iVar10 + -8 + iVar5 * 4);
            do {
              if (pfVar2[1] < fVar1 != (pfVar2[1] == fVar1)) goto LAB_006b36c3;
              if (*pfVar2 < fVar1 != (*pfVar2 == fVar1)) {
                iVar5 = iVar5 + -1;
                goto LAB_006b36c3;
              }
              if (pfVar2[-1] < fVar1 != (pfVar2[-1] == fVar1)) {
                iVar5 = iVar5 + -2;
                goto LAB_006b36c3;
              }
              if (pfVar2[-2] < fVar1 != (pfVar2[-2] == fVar1)) {
                iVar5 = iVar5 + -3;
                goto LAB_006b36c3;
              }
              iVar5 = iVar5 + -4;
              pfVar2 = pfVar2 + -4;
            } while (3 < iVar5);
          }
          if (0 < iVar5) {
            pfVar2 = (float *)(iVar10 + -4 + iVar5 * 4);
            do {
              if (*pfVar2 < fVar1 != (*pfVar2 == fVar1)) break;
              iVar5 = iVar5 + -1;
              pfVar2 = pfVar2 + -1;
            } while (0 < iVar5);
          }
        }
      }
LAB_006b36c3:
      local_1c = piVar6[2] * local_1c + *(int *)(piVar6[1] + iVar5 * 4);
      local_14 = local_14 + -1;
    } while (local_14 != 0);
  }
  if (*(int *)(*(int *)(param_1[3] + 8) + local_1c * 4) < 1) {
    local_10 = 0.0;
    local_1c = -1;
    local_14 = 0;
    if (param_1[1] < 1) {
      return -1;
    }
    piVar6 = *(int **)(param_1[3] + 8);
    iVar9 = param_1[4] - (int)param_2;
    pfVar3 = (float *)(param_1[4] + 0xc);
    do {
      if (0 < *piVar6) {
        local_24 = 0.0;
        iVar10 = 0;
        if (3 < iVar11) {
          iVar4 = (iVar11 - 4U >> 2) + 1;
          iVar10 = iVar4 * 4;
          pfVar2 = param_2 + 1;
          pfVar7 = pfVar3;
          do {
            iVar4 = iVar4 + -1;
            fVar1 = *(float *)(iVar9 + -0x10 + (int)(pfVar2 + 4)) - *pfVar2;
            local_24 = (*pfVar7 - pfVar2[2]) * (*pfVar7 - pfVar2[2]) +
                       (pfVar7[-1] - pfVar2[1]) * (pfVar7[-1] - pfVar2[1]) +
                       fVar1 * fVar1 +
                       (pfVar7[-3] - pfVar2[-1]) * (pfVar7[-3] - pfVar2[-1]) + local_24;
            pfVar2 = pfVar2 + 4;
            pfVar7 = pfVar7 + 4;
          } while (iVar4 != 0);
        }
        if (iVar10 < iVar11) {
          iVar4 = iVar11 - iVar10;
          pfVar2 = param_2 + iVar10;
          do {
            iVar4 = iVar4 + -1;
            fVar1 = *(float *)(iVar9 + (int)pfVar2) - *pfVar2;
            local_24 = fVar1 * fVar1 + local_24;
            pfVar2 = pfVar2 + 1;
          } while (iVar4 != 0);
        }
        if ((local_1c == -1) || (local_24 < local_10)) {
          local_10 = local_24;
          local_1c = local_14;
        }
      }
      pfVar3 = pfVar3 + iVar11;
      iVar9 = iVar9 + iVar11 * 4;
      local_14 = local_14 + 1;
      piVar6 = piVar6 + 1;
    } while (local_14 < param_1[1]);
  }
  if (-1 < local_1c) {
    pfVar3 = (float *)(param_1[4] + local_1c * iVar11 * 4);
    iVar9 = 0;
    if (3 < iVar11) {
      iVar10 = (iVar11 - 4U >> 2) + 1;
      iVar9 = iVar10 * 4;
      pfVar2 = pfVar3;
      pfVar7 = param_2;
      do {
        param_2 = pfVar7 + 4;
        pfVar3 = pfVar2 + 4;
        iVar10 = iVar10 + -1;
        *pfVar7 = *pfVar7 - *pfVar2;
        pfVar7[1] = pfVar7[1] - pfVar2[1];
        pfVar7[2] = pfVar7[2] - pfVar2[2];
        pfVar7[3] = pfVar7[3] - pfVar2[3];
        pfVar2 = pfVar3;
        pfVar7 = param_2;
      } while (iVar10 != 0);
    }
    if (iVar9 < iVar11) {
      iVar11 = iVar11 - iVar9;
      do {
        fVar1 = *pfVar3;
        pfVar3 = pfVar3 + 1;
        iVar11 = iVar11 + -1;
        *param_2 = *param_2 - fVar1;
        param_2 = param_2 + 1;
      } while (iVar11 != 0);
    }
  }
  return local_1c;
}

