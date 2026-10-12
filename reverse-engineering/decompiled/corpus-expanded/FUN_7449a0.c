/* Ghidra pseudocode, not original source.
 * ev_0a8198a66e8ec6a1eea085c3401beb2c994e6aa9b143cc409d97940c91a3eeae
 * Entry: 0x7449a0; label: FUN_007449a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_007449a0(undefined4 param_1)

{
  undefined1 *in_ECX;
  
  in_ECX[1] = (char)((uint)param_1 >> 8);
  *in_ECX = (char)param_1;
  in_ECX[2] = (char)((uint)param_1 >> 0x10);
  in_ECX[3] = (char)((uint)param_1 >> 0x18);
  return;
}

