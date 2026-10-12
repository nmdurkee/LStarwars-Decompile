/* Ghidra pseudocode, not original source.
 * ev_0a8198a66e8ec6a1eea085c3401beb2c994e6aa9b143cc409d97940c91a3eeae
 * Entry: 0x744550; label: FUN_00744550
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

bool FUN_00744550(int param_1)

{
  int *in_ECX;
  
  if ((in_ECX[3] != 0) && (*(char *)(*in_ECX + 0x1b4) == '\0')) {
    return false;
  }
  return param_1 <= (int)(*(uint *)(*in_ECX + 0x13c) >> 9 & 3);
}

