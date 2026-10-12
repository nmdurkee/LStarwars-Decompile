/* Ghidra pseudocode, not original source.
 * ev_6e4df963812b3a1824100f136853f234100848169b29b7b6e42d47a7916e68c6
 * Entry: 0x6b85c0; label: FUN_006b85c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_006b85c0(int param_1)

{
  return (((int)(param_1 + -1 + (param_1 + -1 >> 0x1f & 0x1fU)) >> 5) + 1) * 0x20;
}

