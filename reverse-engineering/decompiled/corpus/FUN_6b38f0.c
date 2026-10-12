/* Ghidra analysis pseudocode, not original source.
 * ev_648e39c5173022307384bd96b6b6d54b0109fbb7542fd197fe89208a1a87d4a6
 * Entry: 0x6b38f0; label: FUN_006b38f0
 */

int FUN_006b38f0(undefined4 param_1,int param_2,int param_3,int *param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 local_4;
  
  iVar1 = *param_4;
  param_3 = param_3 / iVar1;
  local_4 = 0;
  if (0 < param_3) {
    do {
      uVar2 = FUN_006b3530(param_4,param_2);
      iVar3 = FUN_006a96a0(param_4,uVar2,param_1);
      local_4 = local_4 + iVar3;
      param_2 = param_2 + iVar1 * 4;
      param_3 = param_3 + -1;
    } while (param_3 != 0);
    return local_4;
  }
  return 0;
}

