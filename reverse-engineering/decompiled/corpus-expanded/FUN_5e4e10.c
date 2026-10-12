/* Ghidra pseudocode, not original source.
 * ev_dd2b431ee7d7df08292740893bb7b99558b7953fea1da99d97b81497b86ab5e2
 * Entry: 0x5e4e10; label: FUN_005e4e10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005e4e10(int *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  if (*param_1 == 0) {
    return 0;
  }
  iVar1 = *(int *)(*param_1 + 0x110);
  piVar2 = *(int **)(param_1[2] + 0xb0);
  iVar4 = 0;
  if (0 < *piVar2) {
    do {
      iVar3 = *(int *)(*(int *)(iVar1 + 0x50) + *(int *)(piVar2[1] + iVar4 * 4) * 4);
      if (iVar3 == 0) {
        return 0;
      }
      do {
        FUN_00601210(iVar3,0,param_2,param_3);
        iVar3 = *(int *)(iVar3 + 0x30);
      } while (iVar3 != 0);
      iVar4 = iVar4 + 1;
    } while (iVar4 < *piVar2);
    return 0;
  }
  return 0;
}

