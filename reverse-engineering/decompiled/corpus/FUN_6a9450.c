/* Ghidra analysis pseudocode, not original source.
 * ev_411dd83ba30300d5831318e5e0d5db9024421d970d639e52cbaaaf14146f88dc
 * Entry: 0x6a9450; label: FUN_006a9450
 */

undefined4 FUN_006a9450(undefined4 param_1,int *param_2)

{
  undefined1 *puVar1;
  int iVar2;
  void *pvVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  _memset(param_2,0,0x34);
  param_2[0xc] = 1;
  puVar1 = (undefined1 *)FUN_006a3bb0(param_1,0x18);
  if (puVar1 == &LAB_00564342) {
    iVar2 = FUN_006a3bb0(param_1,0x10);
    *param_2 = iVar2;
    iVar2 = FUN_006a3bb0(param_1,0x18);
    param_2[1] = iVar2;
    if (iVar2 != -1) {
      iVar2 = FUN_006a3bb0(param_1,1);
      if (iVar2 == 0) {
        pvVar3 = _malloc(param_2[1] * 4);
        param_2[2] = (int)pvVar3;
        iVar2 = FUN_006a3bb0(param_1,1);
        iVar7 = 0;
        if (iVar2 == 0) {
          if (0 < param_2[1]) {
            do {
              iVar2 = FUN_006a3bb0(param_1,5);
              if (iVar2 == -1) goto LAB_006a9684;
              *(int *)(param_2[2] + iVar7 * 4) = iVar2 + 1;
              iVar7 = iVar7 + 1;
            } while (iVar7 < param_2[1]);
          }
        }
        else if (0 < param_2[1]) {
          do {
            iVar2 = FUN_006a3bb0(param_1,1);
            if (iVar2 == 0) {
              *(undefined4 *)(param_2[2] + iVar7 * 4) = 0;
            }
            else {
              iVar2 = FUN_006a3bb0(param_1,5);
              if (iVar2 == -1) goto LAB_006a9684;
              *(int *)(param_2[2] + iVar7 * 4) = iVar2 + 1;
            }
            iVar7 = iVar7 + 1;
          } while (iVar7 < param_2[1]);
        }
      }
      else {
        if (iVar2 != 1) {
          return 0xffffffff;
        }
        iVar2 = FUN_006a3bb0(param_1,5);
        pvVar3 = _malloc(param_2[1] * 4);
        iVar7 = 0;
        param_2[2] = (int)pvVar3;
        if (0 < param_2[1]) {
          do {
            iVar2 = iVar2 + 1;
            uVar4 = FUN_006a7ed0(param_2[1] - iVar7);
            iVar5 = FUN_006a3bb0(param_1,uVar4);
            if (iVar5 == -1) goto LAB_006a9684;
            iVar6 = 0;
            if (0 < iVar5) {
              do {
                if (param_2[1] <= iVar7) break;
                *(int *)(param_2[2] + iVar7 * 4) = iVar2;
                iVar6 = iVar6 + 1;
                iVar7 = iVar7 + 1;
              } while (iVar6 < iVar5);
            }
          } while (iVar7 < param_2[1]);
        }
      }
      iVar2 = FUN_006a3bb0(param_1,4);
      param_2[3] = iVar2;
      if (iVar2 == 0) {
        return 0;
      }
      if (iVar2 - 1U < 2) {
        iVar2 = FUN_006a3bb0(param_1,0x20);
        param_2[4] = iVar2;
        iVar2 = FUN_006a3bb0(param_1,0x20);
        param_2[5] = iVar2;
        iVar2 = FUN_006a3bb0(param_1,4);
        param_2[6] = iVar2 + 1;
        iVar2 = FUN_006a3bb0(param_1,1);
        param_2[7] = iVar2;
        iVar2 = 0;
        if (param_2[3] == 1) {
          iVar2 = FUN_006a8150(param_2);
        }
        else if (param_2[3] == 2) {
          iVar2 = *param_2 * param_2[1];
        }
        pvVar3 = _malloc(iVar2 * 4);
        iVar7 = 0;
        param_2[8] = (int)pvVar3;
        if (0 < iVar2) {
          do {
            uVar4 = FUN_006a3bb0(param_1,param_2[6]);
            *(undefined4 *)(param_2[8] + iVar7 * 4) = uVar4;
            iVar7 = iVar7 + 1;
          } while (iVar7 < iVar2);
        }
        if (iVar2 == 0) {
          return 0;
        }
        if (*(int *)(param_2[8] + -4 + iVar2 * 4) != -1) {
          return 0;
        }
      }
    }
  }
LAB_006a9684:
  FUN_006a86f0(param_2);
  return 0xffffffff;
}

