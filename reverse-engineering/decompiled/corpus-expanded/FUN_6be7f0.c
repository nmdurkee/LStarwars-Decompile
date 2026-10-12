/* Ghidra pseudocode, not original source.
 * ev_7b6a9e0312bc8ed55bc8db18c390e5e94b6441153fc53fcf4106026d09190a6c
 * Entry: 0x6be7f0; label: FUN_006be7f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_006be7f0(int param_1)

{
  int in_ECX;
  
  if ((-1 < param_1) && (param_1 < *(int *)(in_ECX + 0x24))) {
    return *(int *)(in_ECX + 8) + param_1 * 0x18;
  }
  return 0;
}

