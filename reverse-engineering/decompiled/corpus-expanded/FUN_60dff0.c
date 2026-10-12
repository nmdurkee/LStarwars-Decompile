/* Ghidra pseudocode, not original source.
 * ev_168b65d5705473c04d5f4e526193e1abf552a66e90d2db36f509f2a3124060c2
 * Entry: 0x60dff0; label: FUN_0060dff0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0060dff0(int param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined1 *)(in_ECX + 0xc) = *(undefined1 *)(param_1 + 0xc);
  return;
}

