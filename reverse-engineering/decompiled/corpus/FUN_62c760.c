/* Ghidra analysis pseudocode, not original source.
 * ev_c9b97142cd7201cbac3c7782d44a236cba63ddce43dd201cca5febda4b31625e
 * Entry: 0x62c760; label: FUN_0062c760
 */

undefined4 FUN_0062c760(int param_1,int param_2,undefined4 param_3,int param_4,undefined4 *param_5)

{
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  if ((((-1 < param_2) && (param_2 < *(int *)(param_1 + 4))) &&
      (*(int *)(*(int *)(param_1 + 8) + param_2 * 0x14) != -1)) && (0 < param_4)) {
    local_c = 0;
    local_8 = 0;
    local_4 = 0;
    if (param_5 == (undefined4 *)0x0) {
      param_5 = &local_c;
    }
    FUN_00656dc0(*(undefined4 *)(*(int *)(param_1 + 8) + param_2 * 0x14),param_3,param_5,param_4,0,0
                );
    return 1;
  }
  return 0;
}

