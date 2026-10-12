/* Ghidra pseudocode, not original source.
 * ev_0a8198a66e8ec6a1eea085c3401beb2c994e6aa9b143cc409d97940c91a3eeae
 * Entry: 0x7448d0; label: FUN_007448d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_007448d0(void)

{
  undefined4 *in_ECX;
  
  if (((in_ECX[3] == 0) && ((int)*(uint *)*in_ECX < 0)) && ((*(uint *)*in_ECX & 0x800000) == 0)) {
    return 1;
  }
  return 0;
}

