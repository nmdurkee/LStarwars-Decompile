/* Ghidra pseudocode, not original source.
 * ev_65bfb004178f96b2f9e297a0d063366919d30641ec00bce2a5b47a652ae06e9d
 * Entry: 0x5e5ce0; label: FUN_005e5ce0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

bool FUN_005e5ce0(void)

{
  int in_ECX;
  
  return *(int *)(in_ECX + 0x8c) != 0;
}

