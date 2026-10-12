/* Ghidra pseudocode, not original source.
 * ev_0a8198a66e8ec6a1eea085c3401beb2c994e6aa9b143cc409d97940c91a3eeae
 * Entry: 0x744760; label: FUN_00744760
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

bool FUN_00744760(void)

{
  int *in_ECX;
  
  if (in_ECX[3] != 0) {
    return false;
  }
  return in_ECX[8] < *(int *)(*in_ECX + 0x48);
}

