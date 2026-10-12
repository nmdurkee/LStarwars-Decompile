/* Ghidra pseudocode, not original source.
 * ev_7b6a9e0312bc8ed55bc8db18c390e5e94b6441153fc53fcf4106026d09190a6c
 * Entry: 0x6bea60; label: FUN_006bea60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006bea60(void)

{
  undefined4 *in_ECX;
  
  in_ECX[1] = 0x3f800000;
  *in_ECX = &PTR_FUN_0076f6e0;
  in_ECX[2] = 1;
  return;
}

