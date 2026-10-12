/* Ghidra pseudocode, not original source.
 * ev_e1f69031e6043cc462b81551b49e10968fe3225c8e33f0390d991f568fed2298
 * Entry: 0x6b8c60; label: FUN_006b8c60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_006b8c60(int param_1)

{
  int in_ECX;
  
  if ((*(int *)(in_ECX + 0x34) == *(int *)(param_1 + 4)) &&
     (*(int *)(in_ECX + 0x38) == *(int *)(param_1 + 8))) {
    return 1;
  }
  return 0;
}

