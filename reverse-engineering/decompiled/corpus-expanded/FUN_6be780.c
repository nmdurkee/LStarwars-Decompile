/* Ghidra pseudocode, not original source.
 * ev_7b6a9e0312bc8ed55bc8db18c390e5e94b6441153fc53fcf4106026d09190a6c
 * Entry: 0x6be780; label: FUN_006be780
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_006be780(int param_1)

{
  int in_ECX;
  
  return (param_1 - *(int *)(in_ECX + 8)) / 0x18;
}

