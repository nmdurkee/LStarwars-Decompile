/* Ghidra pseudocode, not original source.
 * ev_168b65d5705473c04d5f4e526193e1abf552a66e90d2db36f509f2a3124060c2
 * Entry: 0x60e010; label: FUN_0060e010
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0060e010(int param_1)

{
  int in_ECX;
  
  if ((*(int *)(in_ECX + 8) == *(int *)(param_1 + 8)) &&
     (*(char *)(in_ECX + 0xc) == *(char *)(param_1 + 0xc))) {
    return 1;
  }
  return 0;
}

