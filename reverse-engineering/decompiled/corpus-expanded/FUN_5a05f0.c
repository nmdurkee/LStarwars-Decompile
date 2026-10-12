/* Ghidra pseudocode, not original source.
 * ev_1b30ab9bd7d518785b9e88881958deca55ff5b776c2bbdcc158b73c997cdcb1d
 * Entry: 0x5a05f0; label: FUN_005a05f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_005a05f0(undefined4 param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  
  iVar1 = 0;
  if (param_3 != 0) {
    iVar1 = FUN_00552670(param_1,param_2,0x1c);
    if (iVar1 != 0) {
      *(int *)(iVar1 + 0x10) = param_3;
      *(int *)(iVar1 + 0x14) = param_4;
      if (*(int *)(param_4 + 8) < DAT_00956618) {
        *(int *)(*(int *)(param_4 + 0xc) + *(int *)(param_4 + 8) * 4) = iVar1;
        *(int *)(param_4 + 8) = *(int *)(param_4 + 8) + 1;
      }
    }
  }
  return iVar1;
}

