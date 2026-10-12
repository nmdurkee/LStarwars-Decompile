/* Ghidra pseudocode, not original source.
 * ev_7b6a9e0312bc8ed55bc8db18c390e5e94b6441153fc53fcf4106026d09190a6c
 * Entry: 0x6be8f0; label: FUN_006be8f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006be8f0(undefined4 param_1)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x34) < *(int *)(in_ECX + 0x30)) {
    *(undefined4 *)(*(int *)(in_ECX + 0x10) + *(int *)(in_ECX + 0x34) * 4) = param_1;
    *(int *)(in_ECX + 0x34) = *(int *)(in_ECX + 0x34) + 1;
  }
  return;
}

