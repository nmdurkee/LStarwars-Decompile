/* Ghidra pseudocode, not original source.
 * ev_f0f87d832dbe8e7fa4eaa2c5681d260c3f1d1a42269eaf7f506f4d6846a5d20b
 * Entry: 0x5485f0; label: FUN_005485f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005485f0(undefined4 param_1,int param_2,int *param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if ((((param_2 != 0) && (param_3 != (int *)0x0)) && (*param_3 < param_4)) &&
     (iVar2 = FUN_00650dc0(param_1), iVar2 != -1)) {
    iVar1 = *param_3;
    iVar3 = 0;
    if (0 < iVar1) {
      do {
        if (*(int *)(param_2 + iVar3 * 4) == iVar2) {
          return;
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < iVar1);
    }
    *(int *)(param_2 + iVar1 * 4) = iVar2;
    *param_3 = *param_3 + 1;
  }
  return;
}

