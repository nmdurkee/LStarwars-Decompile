/* Ghidra pseudocode, not original source.
 * ev_34a04326d91df5bb42d5c22e728fef19b8a2cbdf7cdfa233c070a8d9e179de50
 * Entry: 0x7440e0; label: FUN_007440e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_007440e0(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  if (-1 < *(short *)(param_1 + 0x1c + param_2 * 0xc)) {
    switch((*(int *)(param_1 + param_2 * 0xc + 0x20) << 4) >> 0x1c) {
    case 1:
      FUN_00741f90(param_3,param_4,param_5);
      return;
    case 2:
      FUN_00741fd0(param_3,param_4,param_5);
      return;
    case 3:
      FUN_00743bf0(param_3,param_4,param_5);
    }
  }
  return;
}

