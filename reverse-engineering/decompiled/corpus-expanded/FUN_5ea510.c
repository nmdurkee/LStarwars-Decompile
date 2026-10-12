/* Ghidra pseudocode, not original source.
 * ev_bb04fbbbd27a84d29838025e356b4a832b57e1ec23fb072545eb7050db0a5426
 * Entry: 0x5ea510; label: FUN_005ea510
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

