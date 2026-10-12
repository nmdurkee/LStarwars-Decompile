/* Ghidra pseudocode, not original source.
 * ev_e1f69031e6043cc462b81551b49e10968fe3225c8e33f0390d991f568fed2298
 * Entry: 0x6b8c30; label: FUN_006b8c30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006b8c30(undefined4 *param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x30) = *param_1;
  *(undefined4 *)(in_ECX + 0x34) = param_1[1];
  *(undefined4 *)(in_ECX + 0x38) = param_1[2];
  return;
}

