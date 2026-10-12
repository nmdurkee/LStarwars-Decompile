/* Ghidra analysis pseudocode, not original source.
 * ev_b9f25343996aedf2297d7d3ade291ed602d662c61207b78e5aec6bfbfbdc583f
 * Entry: 0x69dcd0; label: FUN_0069dcd0
 */

void FUN_0069dcd0(int *param_1,int param_2,int param_3,int param_4,int param_5)

{
  float fVar1;
  int iVar2;
  int in_EAX;
  int *piVar3;
  float *pfVar4;
  int in_ECX;
  float *pfVar5;
  int in_EDX;
  int iVar6;
  float *pfVar7;
  int iVar8;
  int iVar9;
  int local_10;
  
  if (in_EAX < in_ECX) {
    in_ECX = in_EAX;
    param_4 = param_5;
  }
  local_10 = 0;
  if (0 < param_2) {
    piVar3 = param_1;
    do {
      if (param_3 <= local_10) {
        return;
      }
      iVar9 = *(int *)((in_EDX - (int)param_1) + (int)piVar3);
      iVar2 = *piVar3;
      iVar6 = 0;
      if (3 < in_ECX) {
        pfVar4 = (float *)(iVar2 + 4);
        pfVar5 = (float *)(iVar9 + 8);
        do {
          fVar1 = *(float *)(param_4 + iVar6 * 4);
          pfVar7 = (float *)((iVar9 - iVar2) + (int)pfVar4);
          fVar1 = fVar1 * fVar1;
          iVar6 = iVar6 + 4;
          pfVar4[-1] = (1.0 - fVar1) * pfVar5[-2] + pfVar4[-1] * fVar1;
          fVar1 = *(float *)((param_4 - iVar9) + (int)pfVar7);
          fVar1 = fVar1 * fVar1;
          *pfVar4 = (1.0 - fVar1) * *pfVar7 + *pfVar4 * fVar1;
          fVar1 = *(float *)((param_4 - iVar9) + -0x10 + (int)(pfVar5 + 4));
          fVar1 = fVar1 * fVar1;
          pfVar4[1] = (1.0 - fVar1) * *pfVar5 + pfVar4[1] * fVar1;
          fVar1 = *(float *)(param_4 + -4 + iVar6 * 4);
          fVar1 = fVar1 * fVar1;
          pfVar4[2] = (1.0 - fVar1) * pfVar5[1] + pfVar4[2] * fVar1;
          pfVar4 = pfVar4 + 4;
          pfVar5 = pfVar5 + 4;
        } while (iVar6 < in_ECX + -3);
      }
      if (iVar6 < in_ECX) {
        iVar2 = *piVar3;
        iVar8 = in_ECX - iVar6;
        pfVar4 = (float *)(iVar2 + iVar6 * 4);
        do {
          pfVar5 = (float *)((int)pfVar4 + (iVar9 - iVar2));
          fVar1 = *(float *)((param_4 - iVar9) + (int)pfVar5);
          iVar8 = iVar8 + -1;
          fVar1 = fVar1 * fVar1;
          *pfVar4 = (1.0 - fVar1) * *pfVar5 + *pfVar4 * fVar1;
          pfVar4 = pfVar4 + 1;
        } while (iVar8 != 0);
      }
      local_10 = local_10 + 1;
      piVar3 = piVar3 + 1;
    } while (local_10 < param_2);
  }
  if (param_3 <= local_10) {
    return;
  }
  do {
    iVar2 = param_1[local_10];
    iVar9 = 0;
    if (3 < in_ECX) {
      iVar6 = (in_ECX - 4U >> 2) + 1;
      iVar9 = iVar6 * 4;
      pfVar4 = (float *)(iVar2 + 4);
      pfVar5 = (float *)(param_4 + 0xc);
      do {
        iVar6 = iVar6 + -1;
        pfVar4[-1] = pfVar5[-3] * pfVar5[-3] * pfVar4[-1];
        fVar1 = *(float *)((int)pfVar4 + (param_4 - iVar2));
        *pfVar4 = fVar1 * fVar1 * *pfVar4;
        pfVar4[1] = pfVar5[-1] * pfVar5[-1] * pfVar4[1];
        pfVar4[2] = *pfVar5 * *pfVar5 * pfVar4[2];
        pfVar4 = pfVar4 + 4;
        pfVar5 = pfVar5 + 4;
      } while (iVar6 != 0);
    }
    if (iVar9 < in_ECX) {
      iVar6 = in_ECX - iVar9;
      pfVar4 = (float *)(iVar2 + iVar9 * 4);
      do {
        fVar1 = *(float *)((param_4 - iVar2) + (int)pfVar4);
        iVar6 = iVar6 + -1;
        *pfVar4 = fVar1 * fVar1 * *pfVar4;
        pfVar4 = pfVar4 + 1;
      } while (iVar6 != 0);
    }
    local_10 = local_10 + 1;
  } while (local_10 < param_3);
  return;
}

