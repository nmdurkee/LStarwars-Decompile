/* Ghidra pseudocode, not original source.
 * ev_7b6a9e0312bc8ed55bc8db18c390e5e94b6441153fc53fcf4106026d09190a6c
 * Entry: 0x6be810; label: FUN_006be810
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006be810(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int in_ECX;
  
  if ((((-1 < param_1) && (param_1 < *(int *)(in_ECX + 0x24))) &&
      (iVar1 = *(int *)(in_ECX + 8) + param_1 * 0x18, iVar1 != 0)) && (*(int *)(iVar1 + 0x14) != 0))
  {
    (**(code **)(**(int **)(iVar1 + 0x14) + 0x38))(param_2,param_3);
  }
  return;
}

