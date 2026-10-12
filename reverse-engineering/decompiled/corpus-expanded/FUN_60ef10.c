/* Ghidra pseudocode, not original source.
 * ev_184291d84d57a0e0f71d3c8a05fa8a71135e786a990f62c870cdb26b01607f61
 * Entry: 0x60ef10; label: FUN_0060ef10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0060ef10(undefined4 param_1,int param_2,int param_3,int param_4,undefined4 param_5,
                 int *param_6)

{
  if (param_2 != 0) {
    if (param_4 != param_3 && -1 < param_4 - param_3) {
      param_3 = param_3 + -1;
      FUN_004ef660(param_3 + param_2,&param_5,1);
      *(int *)(param_2 + 0x4b0) = *(int *)(param_2 + 0x4b0) + 1;
      FUN_0060e590(param_1,param_2,param_3,param_4,param_5);
      *(int *)(param_2 + 0x4b0) = *(int *)(param_2 + 0x4b0) + 1;
      (**(code **)(*param_6 + 8))(param_1,param_2,param_3,param_4);
    }
    if (1 < *(uint *)(param_2 + 0x4b0)) {
      *(uint *)(param_2 + 0x4b0) = *(uint *)(param_2 + 0x4b0) - 1;
      return;
    }
    *(undefined4 *)(param_2 + 0x4b0) = 0;
  }
  return;
}

