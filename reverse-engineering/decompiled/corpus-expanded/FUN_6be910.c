/* Ghidra pseudocode, not original source.
 * ev_7b6a9e0312bc8ed55bc8db18c390e5e94b6441153fc53fcf4106026d09190a6c
 * Entry: 0x6be910; label: FUN_006be910
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006be910(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  int in_ECX;
  int iVar1;
  
  iVar1 = 0;
  if (0 < *(int *)(in_ECX + 0x34)) {
    do {
      (**(code **)**(undefined4 **)(*(int *)(in_ECX + 0x10) + iVar1 * 4))
                (param_1,param_2,param_3,param_4,param_5,param_6);
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(int *)(in_ECX + 0x34));
  }
  return;
}

