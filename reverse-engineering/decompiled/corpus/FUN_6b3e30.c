/* Ghidra analysis pseudocode, not original source.
 * ev_648e39c5173022307384bd96b6b6d54b0109fbb7542fd197fe89208a1a87d4a6
 * Entry: 0x6b3e30; label: FUN_006b3e30
 */

undefined4 FUN_006b3e30(undefined4 param_1,int param_2,int param_3,int *param_4,code *param_5)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int *unaff_EBX;
  int *piVar9;
  int iVar10;
  int local_42c;
  int local_428;
  int local_418;
  int local_400 [128];
  int local_200 [128];
  
  piVar1 = (int *)*unaff_EBX;
  iVar2 = piVar1[3];
  iVar3 = *(int *)unaff_EBX[4];
  iVar4 = piVar1[2];
  iVar5 = (piVar1[1] - *piVar1) / iVar4;
  _memset(local_200,0,0x200);
  _memset(local_400,0,0x200);
  local_42c = 0;
  if (0 < unaff_EBX[2]) {
    do {
      iVar10 = 0;
      if (0 < iVar5) {
        do {
          if ((local_42c == 0) && (local_428 = 0, 0 < param_3)) {
            do {
              piVar9 = (int *)(param_4[local_428] + iVar10 * 4);
              iVar6 = *piVar9;
              iVar8 = 1;
              if (1 < iVar3) {
                do {
                  piVar9 = piVar9 + 1;
                  iVar6 = iVar6 * iVar2;
                  if (iVar8 + iVar10 < iVar5) {
                    iVar6 = iVar6 + *piVar9;
                  }
                  iVar8 = iVar8 + 1;
                } while (iVar8 < iVar3);
              }
              if (iVar6 < *(int *)(unaff_EBX[4] + 4)) {
                iVar6 = FUN_006a96a0(unaff_EBX[4],iVar6,param_1);
                unaff_EBX[9] = unaff_EBX[9] + iVar6;
              }
              local_428 = local_428 + 1;
            } while (local_428 < param_3);
          }
          local_418 = 0;
          if (0 < iVar3) {
            iVar6 = iVar10 * iVar4;
            do {
              if (iVar5 <= iVar10) goto LAB_006b405e;
              iVar8 = *piVar1;
              if (0 < param_3) {
                local_428 = param_3;
                piVar9 = param_4;
                do {
                  if (local_42c == 0) {
                    local_400[*(int *)(*piVar9 + iVar10 * 4)] =
                         local_400[*(int *)(*piVar9 + iVar10 * 4)] + iVar4;
                  }
                  iVar7 = *(int *)(*piVar9 + iVar10 * 4);
                  if (((piVar1[iVar7 + 5] & 1 << ((byte)local_42c & 0x1f)) != 0) &&
                     (iVar7 = *(int *)(*(int *)(unaff_EBX[5] + iVar7 * 4) + local_42c * 4),
                     iVar7 != 0)) {
                    iVar7 = (*param_5)(param_1,*(int *)((int)piVar9 + (param_2 - (int)param_4)) +
                                               (iVar8 + iVar6) * 4,iVar4,iVar7,0);
                    unaff_EBX[8] = unaff_EBX[8] + iVar7;
                    local_200[*(int *)(*piVar9 + iVar10 * 4)] =
                         local_200[*(int *)(*piVar9 + iVar10 * 4)] + iVar7;
                  }
                  piVar9 = piVar9 + 1;
                  local_428 = local_428 + -1;
                } while (local_428 != 0);
              }
              iVar6 = iVar6 + iVar4;
              local_418 = local_418 + 1;
              iVar10 = iVar10 + 1;
            } while (local_418 < iVar3);
          }
        } while (iVar10 < iVar5);
      }
LAB_006b405e:
      local_42c = local_42c + 1;
    } while (local_42c < unaff_EBX[2]);
  }
  return 0;
}

