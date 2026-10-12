/* Ghidra analysis pseudocode, not original source.
 * ev_7c9627a116e74c10f7e1ba5a6ebe852fd25b4abb6a97a0a4eb0abdf2e857683f
 * Entry: 0x6b6e00; label: FUN_006b6e00
 */

undefined4 FUN_006b6e00(int param_1,undefined4 *param_2,int param_3,void *param_4)

{
  int iVar1;
  
  iVar1 = param_2[5];
  FUN_006b6b10(iVar1);
  if (param_3 != 0) {
    FUN_006b6fe0(param_4,*(undefined4 *)(param_2[2] + *(int *)(param_1 + 0x1c) * 4),
                 param_2[*(int *)(param_1 + 0x1c) + 3],*param_2,param_3,param_2[1],
                 *(undefined4 *)(param_3 + param_2[1] * 4),(float)*(int *)(iVar1 + 0x10));
    return 1;
  }
  _memset(param_4,0,param_2[*(int *)(param_1 + 0x1c) + 3] * 4);
  return 0;
}

