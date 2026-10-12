/* Ghidra pseudocode, not original source.
 * ev_0a8198a66e8ec6a1eea085c3401beb2c994e6aa9b143cc409d97940c91a3eeae
 * Entry: 0x7447f0; label: FUN_007447f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_007447f0(void)

{
  int *in_ECX;
  
  if (((in_ECX[3] == 0) && ((*(byte *)(*in_ECX + 0x1b8) & 2) != 0)) &&
     (in_ECX[8] < *(int *)(*in_ECX + 0x38))) {
    return 1;
  }
  return 0;
}

