/* Ghidra analysis pseudocode, not original source.
 * ev_411dd83ba30300d5831318e5e0d5db9024421d970d639e52cbaaaf14146f88dc
 * Entry: 0x6a8f60; label: FUN_006a8f60
 */

int * FUN_006a8f60(int *param_1,int param_2,int param_3)

{
  int iVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  float *pfVar7;
  float *pfVar8;
  int iVar9;
  int iVar10;
  float10 fVar11;
  int local_18;
  float local_14;
  
  iVar10 = param_1[3];
  piVar6 = *(int **)(iVar10 + 0x28);
  iVar3 = *param_1;
  if (piVar6 != (int *)0x0) {
    local_18 = 0;
    if (0 < iVar3) {
      iVar10 = piVar6[3];
      iVar4 = *piVar6;
      iVar9 = iVar10 >> 1;
      pfVar8 = (float *)(param_2 + (iVar3 + -1) * param_3 * 4);
      local_14 = (float)iVar3;
      do {
        fVar2 = *pfVar8;
        if (*(float *)(iVar4 + iVar9 * 4) <= fVar2) {
          iVar1 = iVar10 + -1;
          iVar5 = iVar9 + 1;
          if (3 < iVar1 - iVar5) {
            pfVar7 = (float *)(iVar4 + 8 + iVar5 * 4);
            do {
              if (fVar2 < pfVar7[-2]) goto LAB_006a90d6;
              if (fVar2 < pfVar7[-1]) {
                iVar5 = iVar5 + 1;
                goto LAB_006a90d6;
              }
              if (fVar2 < *pfVar7) {
                iVar5 = iVar5 + 2;
                goto LAB_006a90d6;
              }
              if (fVar2 < pfVar7[1]) {
                iVar5 = iVar5 + 3;
                goto LAB_006a90d6;
              }
              iVar5 = iVar5 + 4;
              pfVar7 = pfVar7 + 4;
            } while (iVar5 < iVar10 + -4);
          }
          if (iVar5 < iVar1) {
            pfVar7 = (float *)(iVar4 + iVar5 * 4);
            do {
              if (fVar2 < *pfVar7) break;
              iVar5 = iVar5 + 1;
              pfVar7 = pfVar7 + 1;
            } while (iVar5 < iVar1);
          }
        }
        else {
          iVar5 = iVar9;
          if (3 < iVar9) {
            pfVar7 = (float *)(iVar4 + -8 + iVar9 * 4);
            do {
              if (pfVar7[1] < fVar2 != (pfVar7[1] == fVar2)) goto LAB_006a90d6;
              if (*pfVar7 < fVar2 != (*pfVar7 == fVar2)) {
                iVar5 = iVar5 + -1;
                goto LAB_006a90d6;
              }
              if (pfVar7[-1] < fVar2 != (pfVar7[-1] == fVar2)) {
                iVar5 = iVar5 + -2;
                goto LAB_006a90d6;
              }
              if (pfVar7[-2] < fVar2 != (pfVar7[-2] == fVar2)) {
                iVar5 = iVar5 + -3;
                goto LAB_006a90d6;
              }
              iVar5 = iVar5 + -4;
              pfVar7 = pfVar7 + -4;
            } while (3 < iVar5);
          }
          if (0 < iVar5) {
            pfVar7 = (float *)(iVar4 + -4 + iVar5 * 4);
            do {
              if (*pfVar7 < fVar2 != (*pfVar7 == fVar2)) break;
              iVar5 = iVar5 + -1;
              pfVar7 = pfVar7 + -1;
            } while (0 < iVar5);
          }
        }
LAB_006a90d6:
        local_18 = piVar6[2] * local_18 + *(int *)(piVar6[1] + iVar5 * 4);
        pfVar8 = pfVar8 + -param_3;
        local_14 = (float)((int)local_14 + -1);
      } while (local_14 != 0.0);
    }
    iVar10 = param_1[3];
    if (0 < *(int *)(*(int *)(iVar10 + 8) + local_18 * 4)) {
      return (int *)local_18;
    }
  }
  iVar4 = param_1[1];
  iVar9 = param_1[4];
  local_14 = 0.0;
  param_1 = (int *)0xffffffff;
  if (0 < iVar4) {
    piVar6 = *(int **)(iVar10 + 8);
    iVar10 = 0;
    do {
      iVar1 = (int)param_1;
      fVar2 = local_14;
      if (0 < *piVar6) {
        fVar11 = (float10)FUN_006a8e30(iVar3,iVar9,param_2);
        fVar2 = (float)fVar11;
        iVar1 = iVar10;
        if ((param_1 != (int *)0xffffffff) && (local_14 <= fVar2)) {
          iVar1 = (int)param_1;
          fVar2 = local_14;
        }
      }
      local_14 = fVar2;
      param_1 = (int *)iVar1;
      iVar10 = iVar10 + 1;
      piVar6 = piVar6 + 1;
      iVar9 = iVar9 + iVar3 * 4;
    } while (iVar10 < iVar4);
  }
  return param_1;
}

