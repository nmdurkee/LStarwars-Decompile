/* Ghidra pseudocode, not original source.
 * ev_0a8198a66e8ec6a1eea085c3401beb2c994e6aa9b143cc409d97940c91a3eeae
 * Entry: 0x7442d0; label: FUN_007442d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_007442d0(void)

{
  int *in_ECX;
  
  return *(uint *)(*in_ECX + 0x13c) >> 0x19 & 1;
}

