/* Ghidra pseudocode, not original source.
 * ev_0a8198a66e8ec6a1eea085c3401beb2c994e6aa9b143cc409d97940c91a3eeae
 * Entry: 0x744890; label: FUN_00744890
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_00744890(void)

{
  int *in_ECX;
  
  if (in_ECX[3] != 0) {
    return 0;
  }
  return *(uint *)(*in_ECX + 0x1b8) >> 0xd & 1;
}

