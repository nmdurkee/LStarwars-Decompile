/* Ghidra pseudocode, not original source.
 * ev_8f65dc07aca5ead6ac5de11150d58420913a4b73213f2c7b5665ab54197e4ce2
 * Entry: 0x681f40; label: FUN_00681f40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00681f40(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = FUN_00650dc0(param_1);
  if (iVar1 != -1) {
    FUN_00650f20(iVar1,param_2,0x3f800000,0x3f800000);
  }
  return;
}

