/* Ghidra pseudocode, not original source.
 * ev_9aa9869018ecc20f1423d5d8d6944da52d455e1cf8e536d99f80bf4f445d14b5
 * Entry: 0x6a9cf0; label: FUN_006a9cf0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_006a9cf0(int *param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  if (param_1[2] < 1) {
    iVar6 = 0;
    if (0 < param_4) {
      iVar4 = *param_1;
      do {
        while (0 < iVar4) {
          *(undefined4 *)(param_2 + iVar6 * 4) = 0;
          iVar6 = iVar6 + 1;
          iVar4 = *param_1;
        }
      } while (iVar6 < param_4);
    }
  }
  else if (0 < param_4) {
    iVar6 = 0;
    do {
      iVar4 = FUN_006a98d0(param_1,param_3);
      if (iVar4 == -1) {
        return 0xffffffff;
      }
      iVar2 = *param_1;
      iVar3 = param_1[4];
      iVar5 = 0;
      if (0 < iVar2) {
        do {
          iVar1 = iVar5 * 4;
          iVar5 = iVar5 + 1;
          *(undefined4 *)(param_2 + iVar6 * 4) = *(undefined4 *)(iVar3 + iVar2 * iVar4 * 4 + iVar1);
          iVar6 = iVar6 + 1;
        } while (iVar5 < *param_1);
      }
    } while (iVar6 < param_4);
    return 0;
  }
  return 0;
}

