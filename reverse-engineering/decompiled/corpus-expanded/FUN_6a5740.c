/* Ghidra pseudocode, not original source.
 * ev_d0baaaa1d022e9a6bc644bf87cbac2e9d23f713faf88b9587519a457b813b0f8
 * Entry: 0x6a5740; label: FUN_006a5740
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */

void FUN_006a5740(int param_1,int param_2,int param_3)

{
  float fVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  float *pfVar6;
  int iVar7;
  int iVar8;
  float *pfVar9;
  float afStack_30 [2];
  float *local_c;
  int local_8;
  
  afStack_30[1] = 9.765898e-39;
  pfVar9 = (float *)(&stack0xffffffd8 + param_3 * -8);
  afStack_30[1 - param_3] = 9.765911e-39;
  iVar4 = 0;
  iVar8 = 0;
  local_8 = 0;
  if (0 < param_3) {
    do {
      if ((1 < iVar8) &&
         (fVar1 = *(float *)(param_1 + iVar4 * 4), afStack_30[param_3 * -2 + iVar8 + 1] <= fVar1)) {
        local_c = afStack_30 + (iVar8 - param_3);
        do {
          if (((((int)afStack_30[(iVar8 + 1) - param_3] + param_2 <= iVar4) || (iVar8 < 2)) ||
              (local_c[-param_3] < afStack_30[param_3 * -2 + iVar8 + 1])) ||
             ((int)*local_c + param_2 <= iVar4)) break;
          iVar7 = param_3 * -2 + iVar8;
          local_c = local_c + -1;
          iVar8 = iVar8 + -1;
        } while (afStack_30[iVar7] <= fVar1);
      }
      uVar2 = *(undefined4 *)(param_1 + iVar4 * 4);
      *(int *)(&stack0xffffffd8 + iVar8 * 4 + param_3 * -4) = iVar4;
      *(undefined4 *)(&stack0xffffffd8 + iVar8 * 4 + param_3 * -8) = uVar2;
      iVar4 = iVar4 + 1;
      iVar8 = iVar8 + 1;
    } while (iVar4 < param_3);
  }
  local_c = (float *)0x0;
  if (0 < iVar8) {
    piVar5 = (int *)(&stack0xffffffdc + param_3 * -4);
    do {
      if ((iVar8 + -1 <= (int)local_c) || ((float)piVar5[-param_3] <= *pfVar9)) {
        iVar4 = piVar5[-1] + 1 + param_2;
      }
      else {
        iVar4 = *piVar5;
      }
      if (param_3 < iVar4) {
        iVar4 = param_3;
      }
      if (3 < iVar4 - local_8) {
        iVar7 = local_8 * 4;
        iVar3 = ((iVar4 - local_8) - 4U >> 2) + 1;
        local_8 = local_8 + iVar3 * 4;
        pfVar6 = (float *)(param_1 + 8 + iVar7);
        do {
          iVar3 = iVar3 + -1;
          pfVar6[-2] = *pfVar9;
          pfVar6[-1] = *pfVar9;
          *pfVar6 = *pfVar9;
          pfVar6[1] = *pfVar9;
          pfVar6 = pfVar6 + 4;
        } while (iVar3 != 0);
      }
      if (local_8 < iVar4) {
        fVar1 = *pfVar9;
        pfVar6 = (float *)(param_1 + local_8 * 4);
        for (iVar7 = iVar4 - local_8; iVar7 != 0; iVar7 = iVar7 + -1) {
          *pfVar6 = fVar1;
          pfVar6 = pfVar6 + 1;
        }
        local_8 = local_8 + (iVar4 - local_8);
      }
      piVar5 = piVar5 + 1;
      local_c = (float *)((int)local_c + 1);
      pfVar9 = pfVar9 + 1;
    } while ((int)local_c < iVar8);
  }
  return;
}

