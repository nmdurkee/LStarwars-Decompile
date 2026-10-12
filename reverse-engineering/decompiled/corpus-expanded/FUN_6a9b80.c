/* Ghidra pseudocode, not original source.
 * ev_9aa9869018ecc20f1423d5d8d6944da52d455e1cf8e536d99f80bf4f445d14b5
 * Entry: 0x6a9b80; label: FUN_006a9b80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_006a9b80(int *param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  int iVar2;
  float *pfVar3;
  float *pfVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
  if (0 < param_1[2]) {
    iVar9 = 0;
    if (*param_1 < 9) {
      if (0 < param_4) {
        do {
          iVar7 = FUN_006a98d0(param_1,param_3);
          if (iVar7 == -1) {
            return 0xffffffff;
          }
          pfVar3 = (float *)(param_1[4] + *param_1 * iVar7 * 4);
          iVar7 = 0;
          switch(*param_1) {
          case 8:
            iVar7 = 1;
            *(float *)(param_2 + iVar9 * 4) = *pfVar3 + *(float *)(param_2 + iVar9 * 4);
            iVar9 = iVar9 + 1;
          case 7:
            pfVar4 = pfVar3 + iVar7;
            iVar7 = iVar7 + 1;
            iVar5 = iVar9 * 4;
            iVar9 = iVar9 + 1;
            *(float *)(param_2 + -4 + iVar9 * 4) = *pfVar4 + *(float *)(param_2 + iVar5);
          case 6:
            pfVar4 = pfVar3 + iVar7;
            iVar7 = iVar7 + 1;
            iVar5 = iVar9 * 4;
            iVar9 = iVar9 + 1;
            *(float *)(param_2 + -4 + iVar9 * 4) = *pfVar4 + *(float *)(param_2 + iVar5);
          case 5:
            pfVar4 = pfVar3 + iVar7;
            iVar7 = iVar7 + 1;
            iVar5 = iVar9 * 4;
            iVar9 = iVar9 + 1;
            *(float *)(param_2 + -4 + iVar9 * 4) = *pfVar4 + *(float *)(param_2 + iVar5);
          case 4:
            pfVar4 = pfVar3 + iVar7;
            iVar7 = iVar7 + 1;
            iVar5 = iVar9 * 4;
            iVar9 = iVar9 + 1;
            *(float *)(param_2 + -4 + iVar9 * 4) = *pfVar4 + *(float *)(param_2 + iVar5);
          case 3:
            pfVar4 = pfVar3 + iVar7;
            iVar7 = iVar7 + 1;
            iVar5 = iVar9 * 4;
            iVar9 = iVar9 + 1;
            *(float *)(param_2 + -4 + iVar9 * 4) = *pfVar4 + *(float *)(param_2 + iVar5);
          case 2:
            pfVar4 = pfVar3 + iVar7;
            iVar7 = iVar7 + 1;
            iVar5 = iVar9 * 4;
            iVar9 = iVar9 + 1;
            *(float *)(param_2 + -4 + iVar9 * 4) = *pfVar4 + *(float *)(param_2 + iVar5);
          case 1:
            iVar9 = iVar9 + 1;
            *(float *)(param_2 + -4 + iVar9 * 4) =
                 pfVar3[iVar7] + *(float *)(param_2 + -4 + iVar9 * 4);
          }
        } while (iVar9 < param_4);
      }
    }
    else if (0 < param_4) {
      do {
        iVar7 = FUN_006a98d0(param_1,param_3);
        if (iVar7 == -1) {
          return 0xffffffff;
        }
        iVar5 = *param_1;
        iVar6 = param_1[4];
        iVar8 = 0;
        if (0 < iVar5) {
          do {
            iVar1 = iVar8 * 4;
            iVar8 = iVar8 + 1;
            iVar2 = iVar9 * 4;
            iVar9 = iVar9 + 1;
            *(float *)(param_2 + -4 + iVar9 * 4) =
                 *(float *)(iVar6 + iVar5 * iVar7 * 4 + iVar1) + *(float *)(param_2 + iVar2);
          } while (iVar8 < *param_1);
        }
      } while (iVar9 < param_4);
      return 0;
    }
  }
  return 0;
}

