/* Ghidra pseudocode, not original source.
 * ev_7b6a9e0312bc8ed55bc8db18c390e5e94b6441153fc53fcf4106026d09190a6c
 * Entry: 0x6be710; label: FUN_006be710
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_006be710(int param_1)

{
  int in_ECX;
  
  if ((-1 < param_1) && (param_1 < *(int *)(in_ECX + 0x1c))) {
    return *(int *)(in_ECX + 4) + param_1 * 0xc;
  }
  return 0;
}

