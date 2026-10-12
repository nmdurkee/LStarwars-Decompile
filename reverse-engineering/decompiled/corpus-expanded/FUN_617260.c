/* Ghidra pseudocode, not original source.
 * ev_35392dc412ffe2b2a558f5a6ba3fa7479ff279a31c4c87c94d67c76968103d24
 * Entry: 0x617260; label: FUN_00617260
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00617260(void)

{
  int in_ECX;
  
  return *(int *)(in_ECX + 0x8c) - *(int *)(in_ECX + 0x98);
}

