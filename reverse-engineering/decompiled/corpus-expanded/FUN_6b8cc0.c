/* Ghidra pseudocode, not original source.
 * ev_e1f69031e6043cc462b81551b49e10968fe3225c8e33f0390d991f568fed2298
 * Entry: 0x6b8cc0; label: FUN_006b8cc0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006b8cc0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0076f6e0;
  if ((param_1 & 1) != 0) {
    FUN_006e85b0();
  }
  return;
}

