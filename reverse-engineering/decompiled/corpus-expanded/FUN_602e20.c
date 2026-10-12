/* Ghidra pseudocode, not original source.
 * ev_57ca11fd66234800334e5f23d40b47e1bf5f9001c22ff37fd2f45222df4b5a02
 * Entry: 0x602e20; label: FUN_00602e20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00602e20(int param_1,int param_2,undefined4 param_3)

{
  if ((param_2 == 0) || (*(int *)(param_1 + 0x20) == 0)) {
    if (*(int *)(param_1 + 0x48) != 0) {
      FUN_006e5b90(0,0,&param_2,param_3,*(int *)(param_1 + 0x48));
    }
    *(int *)(param_1 + 0x1c) = param_2 + *(int *)(param_1 + 0x18) * 0x24;
  }
  return;
}

