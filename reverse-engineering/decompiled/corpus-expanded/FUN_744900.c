/* Ghidra pseudocode, not original source.
 * ev_0a8198a66e8ec6a1eea085c3401beb2c994e6aa9b143cc409d97940c91a3eeae
 * Entry: 0x744900; label: FUN_00744900
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00744900(void)

{
  int *in_ECX;
  
  return CONCAT31((int3)((uint)*in_ECX >> 8),0 < *(int *)(*in_ECX + 0x1e4));
}

