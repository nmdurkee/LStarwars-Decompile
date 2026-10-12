/* Ghidra pseudocode, not original source.
 * ev_8eef0e367f1a27c7ef4dce890dd1e02a98f2c666b50c9e5dab0b6aeb2e260fd2
 * Entry: 0x6b6e00; label: FUN_006b6e00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

