/* Ghidra analysis pseudocode, not original source.
 * ev_648e39c5173022307384bd96b6b6d54b0109fbb7542fd197fe89208a1a87d4a6
 * Entry: 0x6b42d0; label: FUN_006b42d0
 */

undefined4
FUN_006b42d0(undefined4 param_1,int param_2,undefined4 param_3,int *param_4,int *param_5,int param_6
            ,int *param_7,undefined4 param_8)

{
  int iVar1;
  int iVar2;
  float *pfVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  float *pfVar7;
  int *piVar8;
  int *piVar9;
  int iVar10;
  int local_10;
  int *local_c;
  
  iVar5 = 0;
  iVar10 = *(int *)(param_2 + 0x24) / 2;
  local_10 = 0;
  if (0 < (int)param_7) {
    param_6 = param_6 - (int)param_5;
    local_c = param_7;
    piVar8 = param_4;
    do {
      piVar9 = (int *)(((int)param_5 - (int)param_4) + (int)piVar8);
      if (*(int *)(param_6 + (int)piVar9) != 0) {
        if (param_5 != (int *)0x0) {
          iVar5 = 0;
          if (3 < iVar10) {
            iVar1 = *piVar8;
            iVar2 = *piVar9;
            iVar6 = (iVar10 - 4U >> 2) + 1;
            iVar5 = iVar6 * 4;
            pfVar3 = (float *)(iVar2 + 4);
            pfVar7 = (float *)(iVar1 + 0xc);
            do {
              iVar6 = iVar6 + -1;
              pfVar3[-1] = pfVar7[-3] + pfVar3[-1];
              *pfVar3 = *(float *)((iVar1 - iVar2) + -0x10 + (int)(pfVar3 + 4)) + *pfVar3;
              pfVar3[1] = pfVar7[-1] + pfVar3[1];
              pfVar3[2] = pfVar3[2] + *pfVar7;
              pfVar3 = pfVar3 + 4;
              pfVar7 = pfVar7 + 4;
            } while (iVar6 != 0);
          }
          if (iVar5 < iVar10) {
            iVar1 = *piVar9;
            iVar2 = *piVar8;
            iVar6 = iVar10 - iVar5;
            pfVar3 = (float *)(iVar1 + iVar5 * 4);
            do {
              iVar6 = iVar6 + -1;
              *pfVar3 = *(float *)((iVar2 - iVar1) + (int)pfVar3) + *pfVar3;
              pfVar3 = pfVar3 + 1;
            } while (iVar6 != 0);
          }
        }
        param_4[local_10] = *piVar8;
        iVar5 = local_10 + 1;
        local_10 = iVar5;
      }
      piVar8 = piVar8 + 1;
      local_c = (int *)((int)local_c + -1);
    } while (local_c != (int *)0x0);
    if (iVar5 != 0) {
      uVar4 = FUN_006b3e30(param_1,param_4,iVar5,param_8,FUN_006b38f0);
      piVar8 = param_5;
      while (piVar8 != (int *)0x0) {
        if (*(int *)(param_6 + (int)param_5) != 0) {
          iVar5 = 0;
          if (3 < iVar10) {
            iVar1 = *param_4;
            iVar2 = *param_5;
            iVar6 = (iVar10 - 4U >> 2) + 1;
            iVar5 = iVar6 * 4;
            pfVar3 = (float *)(iVar2 + 4);
            pfVar7 = (float *)(iVar1 + 0xc);
            do {
              iVar6 = iVar6 + -1;
              pfVar3[-1] = pfVar3[-1] - pfVar7[-3];
              *pfVar3 = *pfVar3 - *(float *)((int)pfVar3 + (iVar1 - iVar2));
              pfVar3[1] = pfVar3[1] - pfVar7[-1];
              pfVar3[2] = pfVar3[2] - *pfVar7;
              pfVar3 = pfVar3 + 4;
              pfVar7 = pfVar7 + 4;
            } while (iVar6 != 0);
          }
          if (iVar5 < iVar10) {
            iVar1 = *param_5;
            iVar2 = *param_4;
            iVar6 = iVar10 - iVar5;
            pfVar3 = (float *)(iVar1 + iVar5 * 4);
            do {
              iVar6 = iVar6 + -1;
              *pfVar3 = *pfVar3 - *(float *)((int)pfVar3 + (iVar2 - iVar1));
              pfVar3 = pfVar3 + 1;
            } while (iVar6 != 0);
          }
          param_4 = param_4 + 1;
        }
        param_5 = param_5 + 1;
        param_7 = (int *)((int)param_7 + -1);
        piVar8 = param_7;
      }
      return uVar4;
    }
  }
  return 0;
}

