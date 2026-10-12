/* Ghidra analysis pseudocode, not original source.
 * ev_b11735056f517841e68fc69c6a59e9f65c2ea93b1b22364b6a9fa70acd21d770
 * Entry: 0x6c63b0; label: FUN_006c63b0
 */

void FUN_006c63b0(int *param_1,int param_2,undefined4 param_3,uint param_4)

{
  DAT_02973e91 = 1;
  if (param_2 != 0) {
    if ((param_4 & 2) == 0) {
      FUN_006be960(param_2,param_1[1],param_3,param_4);
    }
    (**(code **)(*param_1 + 0x1c))(param_2,param_4);
  }
  DAT_02973e91 = 0;
  return;
}

