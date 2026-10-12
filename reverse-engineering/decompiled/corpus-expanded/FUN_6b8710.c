/* Ghidra pseudocode, not original source.
 * ev_6e4df963812b3a1824100f136853f234100848169b29b7b6e42d47a7916e68c6
 * Entry: 0x6b8710; label: FUN_006b8710
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

bool FUN_006b8710(uint param_1)

{
  int in_ECX;
  
  return (*(uint *)(in_ECX + 4) & param_1) != 0;
}

