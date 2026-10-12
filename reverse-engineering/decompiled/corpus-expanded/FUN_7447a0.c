/* Ghidra pseudocode, not original source.
 * ev_0a8198a66e8ec6a1eea085c3401beb2c994e6aa9b143cc409d97940c91a3eeae
 * Entry: 0x7447a0; label: FUN_007447a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

bool FUN_007447a0(void)

{
  int in_ECX;
  
  return *(int *)(in_ECX + 0x14) != 0;
}

