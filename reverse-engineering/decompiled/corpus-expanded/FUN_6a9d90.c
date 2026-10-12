/* Ghidra pseudocode, not original source.
 * ev_9aa9869018ecc20f1423d5d8d6944da52d455e1cf8e536d99f80bf4f445d14b5
 * Entry: 0x6a9d90; label: FUN_006a9d90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4
FUN_006a9d90(int *param_1,int param_2,int param_3,int param_4,undefined4 param_5,int param_6)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  iVar7 = 0;
  if (0 < param_1[2]) {
    iVar4 = param_3 / param_4;
    while (iVar4 < (param_6 + param_3) / param_4) {
      iVar5 = FUN_006a98d0(param_1,param_5);
      if (iVar5 == -1) {
        return 0xffffffff;
      }
      iVar1 = *param_1;
      iVar2 = param_1[4];
      iVar6 = 0;
      if (0 < iVar1) {
        do {
          iVar3 = *(int *)(param_2 + iVar7 * 4);
          iVar7 = iVar7 + 1;
          *(float *)(iVar3 + iVar4 * 4) =
               *(float *)(iVar2 + iVar1 * iVar5 * 4 + iVar6 * 4) + *(float *)(iVar3 + iVar4 * 4);
          if (iVar7 == param_4) {
            iVar7 = 0;
            iVar4 = iVar4 + 1;
          }
          iVar6 = iVar6 + 1;
        } while (iVar6 < *param_1);
      }
    }
  }
  return 0;
}

