/* Ghidra analysis pseudocode, not original source.
 * ev_93d7dcfdde9a808337523cfea9e371187d945893e914ed56ca2b2926a7aff66e
 * Entry: 0x62c610; label: FUN_0062c610
 */

undefined4
FUN_0062c610(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  if (((-1 < param_2) && (param_2 < *(int *)(param_1 + 4))) &&
     (iVar1 = param_2 * 0x14, *(int *)(*(int *)(param_1 + 8) + param_2 * 0x14) != -1)) {
    local_c = param_3;
    param_2 = 0xffffffff;
    local_8 = param_4;
    local_4 = param_5;
    FUN_00690460(&param_2,*(undefined4 *)(*(int *)(param_1 + 8) + iVar1),&local_c,1);
    return 1;
  }
  return 0;
}

