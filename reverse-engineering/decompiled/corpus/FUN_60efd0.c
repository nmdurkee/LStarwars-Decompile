/* Ghidra analysis pseudocode, not original source.
 * ev_52657a7e1db53538daec051130af6184911435fe99c383e1c36de6367d35a487
 * Entry: 0x60efd0; label: FUN_0060efd0
 */

void FUN_0060efd0(undefined4 param_1,int param_2,int param_3,int param_4,undefined4 param_5,
                 int *param_6,undefined4 param_7,undefined4 param_8)

{
  if (param_2 != 0) {
    if (param_4 != param_3 && -1 < param_4 - param_3) {
      param_3 = param_3 + -1;
      FUN_004ef660(param_3 + param_2,&param_5,1);
      *(int *)(param_2 + 0x4b0) = *(int *)(param_2 + 0x4b0) + 1;
      FUN_0060e590(param_1,param_2,param_3,param_4,param_5);
      *(int *)(param_2 + 0x4b0) = *(int *)(param_2 + 0x4b0) + 1;
      (**(code **)(*param_6 + 0xc))(param_1,param_2,param_3,param_4,param_7,param_8);
    }
    if (1 < *(uint *)(param_2 + 0x4b0)) {
      *(uint *)(param_2 + 0x4b0) = *(uint *)(param_2 + 0x4b0) - 1;
      return;
    }
    *(undefined4 *)(param_2 + 0x4b0) = 0;
  }
  return;
}

