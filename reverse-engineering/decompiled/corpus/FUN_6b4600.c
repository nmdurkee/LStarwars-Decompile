/* Ghidra analysis pseudocode, not original source.
 * ev_648e39c5173022307384bd96b6b6d54b0109fbb7542fd197fe89208a1a87d4a6
 * Entry: 0x6b4600; label: FUN_006b4600
 */

undefined4
FUN_006b4600(undefined4 param_1,int param_2,undefined4 param_3,int param_4,int *param_5,int *param_6
            ,int param_7,undefined4 param_8)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  int iVar7;
  float *pfVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  float *pfVar12;
  int iVar13;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_8;
  
  iVar2 = param_7;
  iVar13 = *(int *)(param_2 + 0x24) / 2;
  local_1c = 0;
  local_8 = iVar13;
  iVar3 = FUN_006a1550(param_2,iVar13 * param_7 * 4);
  param_2 = 0;
  if (0 < param_7) {
    local_10 = param_4 - (int)param_6;
    do {
      local_14 = *(int *)(local_10 + (int)param_6);
      if (*param_6 != 0) {
        local_1c = local_1c + 1;
      }
      iVar11 = 0;
      iVar4 = param_2;
      if (3 < iVar13) {
        iVar9 = (iVar13 - 4U >> 2) + 1;
        iVar11 = iVar9 * 4;
        puVar5 = (undefined4 *)(local_14 + 8);
        do {
          *(undefined4 *)(iVar3 + iVar4 * 4) = puVar5[-2];
          *(undefined4 *)(iVar3 + (iVar4 + param_7) * 4) = puVar5[-1];
          iVar4 = iVar4 + param_7 + param_7;
          *(undefined4 *)(iVar3 + iVar4 * 4) = *puVar5;
          iVar4 = iVar4 + param_7;
          *(undefined4 *)(iVar3 + iVar4 * 4) = puVar5[1];
          iVar4 = iVar4 + param_7;
          iVar9 = iVar9 + -1;
          puVar5 = puVar5 + 4;
        } while (iVar9 != 0);
      }
      if (iVar11 < iVar13) {
        puVar5 = (undefined4 *)(iVar3 + iVar4 * 4);
        do {
          iVar4 = iVar11 * 4;
          iVar11 = iVar11 + 1;
          *puVar5 = *(undefined4 *)(local_14 + iVar4);
          puVar5 = puVar5 + param_7;
        } while (iVar11 < iVar13);
      }
      param_2 = param_2 + 1;
      param_6 = param_6 + 1;
    } while (param_2 < param_7);
    if (local_1c != 0) {
      local_18 = iVar3;
      uVar6 = FUN_006b3e30(param_1,&local_18,1,param_8,FUN_006b38f0);
      if (param_5 != (int *)0x0) {
        param_4 = param_4 - (int)param_5;
        param_2 = 0;
        do {
          iVar11 = *(int *)(param_4 + (int)param_5);
          iVar4 = *param_5;
          param_7 = 0;
          iVar9 = param_2;
          if (3 < iVar13) {
            iVar7 = (iVar13 - 4U >> 2) + 1;
            param_7 = iVar7 * 4;
            pfVar8 = (float *)(iVar4 + 4);
            pfVar12 = (float *)(iVar11 + 0xc);
            do {
              pfVar8[-1] = (pfVar12[-3] - *(float *)(iVar3 + iVar9 * 4)) + pfVar8[-1];
              iVar13 = iVar9 + iVar2 + iVar2;
              *pfVar8 = (*(float *)((int)pfVar8 + (iVar11 - iVar4)) -
                        *(float *)(iVar3 + (iVar9 + iVar2) * 4)) + *pfVar8;
              iVar10 = iVar13 + iVar2;
              pfVar8[1] = (pfVar12[-1] - *(float *)(iVar3 + iVar13 * 4)) + pfVar8[1];
              iVar9 = iVar10 + iVar2;
              iVar7 = iVar7 + -1;
              pfVar8[2] = (*pfVar12 - *(float *)(iVar3 + iVar10 * 4)) + pfVar8[2];
              pfVar8 = pfVar8 + 4;
              pfVar12 = pfVar12 + 4;
              iVar13 = local_8;
            } while (iVar7 != 0);
          }
          if (param_7 < iVar13) {
            iVar7 = iVar13 - param_7;
            pfVar8 = (float *)(iVar3 + iVar9 * 4);
            pfVar12 = (float *)(iVar4 + param_7 * 4);
            do {
              fVar1 = *pfVar8;
              pfVar8 = pfVar8 + iVar2;
              iVar7 = iVar7 + -1;
              *pfVar12 = (*(float *)((int)pfVar12 + (iVar11 - iVar4)) - fVar1) + *pfVar12;
              pfVar12 = pfVar12 + 1;
            } while (iVar7 != 0);
          }
          param_2 = param_2 + 1;
          param_5 = param_5 + 1;
        } while (param_2 < iVar2);
      }
      return uVar6;
    }
  }
  return 0;
}

