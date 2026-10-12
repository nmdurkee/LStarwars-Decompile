/* Ghidra pseudocode, not original source.
 * ev_48d4eb782bac12eedeead3c338e4f978b0df7732be8621fd20cf56d53bd7b1ed
 * Entry: 0x401e10; label: FUN_00401e10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00401e10(int param_1,int param_2)

{
  if ((*(char *)(param_1 + 0x7b5) == 'J') && (*(int *)(param_1 + 0x798) == param_2)) {
    return 1;
  }
  return 0;
}

