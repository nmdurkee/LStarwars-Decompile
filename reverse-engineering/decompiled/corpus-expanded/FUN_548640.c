/* Ghidra pseudocode, not original source.
 * ev_f0f87d832dbe8e7fa4eaa2c5681d260c3f1d1a42269eaf7f506f4d6846a5d20b
 * Entry: 0x548640; label: FUN_00548640
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00548640(int param_1,int param_2,int *param_3,int param_4)

{
  int iVar1;
  int iVar2;
  
  if ((((param_2 != 0) && (param_3 != (int *)0x0)) && (iVar1 = *param_3, iVar1 < param_4)) &&
     (param_1 != -1)) {
    iVar2 = 0;
    if (0 < iVar1) {
      do {
        if (*(int *)(param_2 + iVar2 * 4) == param_1) {
          return;
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < iVar1);
    }
    *(int *)(param_2 + iVar1 * 4) = param_1;
    *param_3 = *param_3 + 1;
  }
  return;
}

