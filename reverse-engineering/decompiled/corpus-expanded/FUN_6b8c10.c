/* Ghidra pseudocode, not original source.
 * ev_e1f69031e6043cc462b81551b49e10968fe3225c8e33f0390d991f568fed2298
 * Entry: 0x6b8c10; label: FUN_006b8c10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_006b8c10(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x20) != 0) {
    return *(undefined4 *)(*(int *)(in_ECX + 0x20) + 0x10);
  }
  return 0;
}

