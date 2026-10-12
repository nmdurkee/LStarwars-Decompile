/* Ghidra pseudocode, not original source.
 * ev_9aa9869018ecc20f1423d5d8d6944da52d455e1cf8e536d99f80bf4f445d14b5
 * Entry: 0x6a9450; label: FUN_006a9450
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_006a9450(undefined4 param_1,int *param_2)

{
  int iVar1;
  void *pvVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  _memset(param_2,0,0x34);
  param_2[0xc] = 1;
  iVar1 = FUN_006a3bb0(param_1,0x18);
  if (iVar1 == 0x564342) {
    iVar1 = FUN_006a3bb0(param_1,0x10);
    *param_2 = iVar1;
    iVar1 = FUN_006a3bb0(param_1,0x18);
    param_2[1] = iVar1;
    if (iVar1 != -1) {
      iVar1 = FUN_006a3bb0(param_1,1);
      if (iVar1 == 0) {
        pvVar2 = _malloc(param_2[1] * 4);
        param_2[2] = (int)pvVar2;
        iVar1 = FUN_006a3bb0(param_1,1);
        iVar6 = 0;
        if (iVar1 == 0) {
          if (0 < param_2[1]) {
            do {
              iVar1 = FUN_006a3bb0(param_1,5);
              if (iVar1 == -1) goto LAB_006a9684;
              *(int *)(param_2[2] + iVar6 * 4) = iVar1 + 1;
              iVar6 = iVar6 + 1;
            } while (iVar6 < param_2[1]);
          }
        }
        else if (0 < param_2[1]) {
          do {
            iVar1 = FUN_006a3bb0(param_1,1);
            if (iVar1 == 0) {
              *(undefined4 *)(param_2[2] + iVar6 * 4) = 0;
            }
            else {
              iVar1 = FUN_006a3bb0(param_1,5);
              if (iVar1 == -1) goto LAB_006a9684;
              *(int *)(param_2[2] + iVar6 * 4) = iVar1 + 1;
            }
            iVar6 = iVar6 + 1;
          } while (iVar6 < param_2[1]);
        }
      }
      else {
        if (iVar1 != 1) {
          return 0xffffffff;
        }
        iVar1 = FUN_006a3bb0(param_1,5);
        pvVar2 = _malloc(param_2[1] * 4);
        iVar6 = 0;
        param_2[2] = (int)pvVar2;
        if (0 < param_2[1]) {
          do {
            iVar1 = iVar1 + 1;
            uVar3 = FUN_006a7ed0(param_2[1] - iVar6);
            iVar4 = FUN_006a3bb0(param_1,uVar3);
            if (iVar4 == -1) goto LAB_006a9684;
            iVar5 = 0;
            if (0 < iVar4) {
              do {
                if (param_2[1] <= iVar6) break;
                *(int *)(param_2[2] + iVar6 * 4) = iVar1;
                iVar5 = iVar5 + 1;
                iVar6 = iVar6 + 1;
              } while (iVar5 < iVar4);
            }
          } while (iVar6 < param_2[1]);
        }
      }
      iVar1 = FUN_006a3bb0(param_1,4);
      param_2[3] = iVar1;
      if (iVar1 == 0) {
        return 0;
      }
      if (iVar1 - 1U < 2) {
        iVar1 = FUN_006a3bb0(param_1,0x20);
        param_2[4] = iVar1;
        iVar1 = FUN_006a3bb0(param_1,0x20);
        param_2[5] = iVar1;
        iVar1 = FUN_006a3bb0(param_1,4);
        param_2[6] = iVar1 + 1;
        iVar1 = FUN_006a3bb0(param_1,1);
        param_2[7] = iVar1;
        iVar1 = 0;
        if (param_2[3] == 1) {
          iVar1 = FUN_006a8150(param_2);
        }
        else if (param_2[3] == 2) {
          iVar1 = *param_2 * param_2[1];
        }
        pvVar2 = _malloc(iVar1 * 4);
        iVar6 = 0;
        param_2[8] = (int)pvVar2;
        if (0 < iVar1) {
          do {
            uVar3 = FUN_006a3bb0(param_1,param_2[6]);
            *(undefined4 *)(param_2[8] + iVar6 * 4) = uVar3;
            iVar6 = iVar6 + 1;
          } while (iVar6 < iVar1);
        }
        if (iVar1 == 0) {
          return 0;
        }
        if (*(int *)(param_2[8] + -4 + iVar1 * 4) != -1) {
          return 0;
        }
      }
    }
  }
LAB_006a9684:
  FUN_006a86f0(param_2);
  return 0xffffffff;
}

