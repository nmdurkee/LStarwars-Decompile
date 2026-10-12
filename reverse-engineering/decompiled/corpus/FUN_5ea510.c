/* Ghidra analysis pseudocode, not original source.
 * ev_6d5e80728f20a9db75e52af560e5ebae31a03548301b37a6feef2e83d352f64f
 * Entry: 0x5ea510; label: FUN_005ea510
 */

void FUN_005ea510(int *param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((param_1 != (int *)0x0) && (*param_1 != 0)) {
    if ((param_1[1] == 0) || (iVar1 = *(int *)(param_1[1] + 0x40), iVar1 == 0)) {
      if (param_1[2] != 0) {
        FUN_005dfe80();
        return;
      }
    }
    else {
      uVar2 = *(undefined4 *)(*(int *)(*param_1 + 0x18) + *(short *)(iVar1 + 0x40) * 4);
      if (0 < param_2) {
        do {
          FUN_005fe970(uVar2,param_3);
          param_3 = param_3 + 0x40;
          param_2 = param_2 + -1;
        } while (param_2 != 0);
      }
    }
  }
  return;
}

