/* Ghidra analysis pseudocode, not original source.
 * ev_4eb19e57a9d3b9beba017312b3b21652588e9c732adfcebbbddaeb757a53089f
 * Entry: 0x401e10; label: FUN_00401e10
 */

undefined4 FUN_00401e10(int param_1,int param_2)

{
  if ((*(char *)(param_1 + 0x7b5) == 'J') && (*(int *)(param_1 + 0x798) == param_2)) {
    return 1;
  }
  return 0;
}

