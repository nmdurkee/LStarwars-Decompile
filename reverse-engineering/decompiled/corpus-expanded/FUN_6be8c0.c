/* Ghidra pseudocode, not original source.
 * ev_7b6a9e0312bc8ed55bc8db18c390e5e94b6441153fc53fcf4106026d09190a6c
 * Entry: 0x6be8c0; label: FUN_006be8c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006be8c0(int param_1,undefined4 param_2,undefined4 param_3)

{
  if ((param_1 != 0) && (*(int *)(param_1 + 0x14) != 0)) {
    (**(code **)(**(int **)(param_1 + 0x14) + 0x3c))(param_2,param_3);
  }
  return;
}

