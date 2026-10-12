/* Ghidra analysis pseudocode, not original source.
 * ev_93d7dcfdde9a808337523cfea9e371187d945893e914ed56ca2b2926a7aff66e
 * Entry: 0x62c680; label: FUN_0062c680
 */

undefined4
FUN_0062c680(int param_1,int param_2,undefined4 param_3,int param_4,undefined4 param_5,
            undefined4 param_6)

{
  int iVar1;
  
  if ((((-1 < param_2) && (param_2 < *(int *)(param_1 + 4))) &&
      (iVar1 = *(int *)(*(int *)(param_1 + 8) + param_2 * 0x14), iVar1 != -1)) && (0 < param_4)) {
    FUN_00684c90(iVar1,param_3,param_4,param_5,param_6);
    return 1;
  }
  return 0;
}

