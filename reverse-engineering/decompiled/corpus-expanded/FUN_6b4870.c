/* Ghidra pseudocode, not original source.
 * ev_8eef0e367f1a27c7ef4dce890dd1e02a98f2c666b50c9e5dab0b6aeb2e260fd2
 * Entry: 0x6b4870; label: FUN_006b4870
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_006b4870(int param_1,int *param_2,undefined4 param_3,int param_4,int param_5)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int local_18;
  int local_14;
  int *local_10;
  
  iVar1 = *(int *)param_2[4];
  piVar2 = (int *)*param_2;
  iVar3 = piVar2[2];
  iVar4 = *(int *)(param_1 + 0x24) * param_5 >> 1;
  if (piVar2[1] < iVar4) {
    iVar4 = piVar2[1];
  }
  if (0 < iVar4 - *piVar2) {
    iVar4 = (iVar4 - *piVar2) / iVar3;
    piVar5 = (int *)FUN_006a1550(param_1,((iVar4 + -1 + iVar1) / iVar1) * 4);
    iVar6 = 0;
    if (0 < param_5) {
      do {
        if (*(int *)(param_4 + iVar6 * 4) != 0) break;
        iVar6 = iVar6 + 1;
      } while (iVar6 < param_5);
    }
    if ((iVar6 != param_5) && (local_14 = 0, 0 < param_2[2])) {
      do {
        local_18 = 0;
        local_10 = piVar5;
        if (0 < iVar4) {
          do {
            if (local_14 == 0) {
              iVar6 = FUN_006a99e0(param_2[4],param_1 + 4);
              if (iVar6 == -1) {
                return 0;
              }
              iVar6 = *(int *)(param_2[7] + iVar6 * 4);
              *local_10 = iVar6;
              if (iVar6 == 0) {
                return 0;
              }
            }
            iVar6 = 0;
            if (0 < iVar1) {
              iVar8 = local_18 * iVar3;
              do {
                if (iVar4 <= local_18) break;
                iVar7 = *(int *)(*local_10 + iVar6 * 4);
                if ((((piVar2[iVar7 + 5] & 1 << ((byte)local_14 & 0x1f)) != 0) &&
                    (iVar7 = *(int *)(*(int *)(param_2[5] + iVar7 * 4) + local_14 * 4), iVar7 != 0))
                   && (iVar7 = FUN_006a9d90(iVar7,param_3,*piVar2 + iVar8,param_5,param_1 + 4,iVar3)
                      , iVar7 == -1)) {
                  return 0;
                }
                local_18 = local_18 + 1;
                iVar6 = iVar6 + 1;
                iVar8 = iVar8 + iVar3;
              } while (iVar6 < iVar1);
            }
            local_10 = local_10 + 1;
          } while (local_18 < iVar4);
        }
        local_14 = local_14 + 1;
      } while (local_14 < param_2[2]);
    }
  }
  return 0;
}

