/* Ghidra pseudocode, not original source.
 * ev_e1f69031e6043cc462b81551b49e10968fe3225c8e33f0390d991f568fed2298
 * Entry: 0x6b8d70; label: FUN_006b8d70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

bool FUN_006b8d70(int param_1)

{
  int in_ECX;
  
  return *(int *)(in_ECX + 8) == (int)*(short *)(param_1 + 4);
}

