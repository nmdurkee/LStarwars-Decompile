/* Ghidra pseudocode, not original source.
 * ev_a87fd181e19a595ed696a9e48a76c3177ea695d31392ba84c3867c15109a72c3
 * Entry: 0x5e0a30; label: FUN_005e0a30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005e0a30(int param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  if (param_1 != 0) {
    if ((param_2 & 3) == 0) {
      FUN_005e09a0(param_2,param_3,param_4,0);
      return;
    }
    iVar1 = 0;
    if (0 < *(int *)(param_1 + 0x60)) {
      do {
        FUN_005e09a0(param_2 | 2,param_3,param_4,0);
        iVar1 = iVar1 + 1;
      } while (iVar1 < *(int *)(param_1 + 0x60));
    }
  }
  return;
}

