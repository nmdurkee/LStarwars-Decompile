/* Ghidra pseudocode, not original source.
 * ev_7c9e2fd09ef4356063d4f7ede11dcf0cb8ee7ae4cb5477b37f94e678ab5e53c2
 * Entry: 0x6df050; label: FUN_006df050
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

bool FUN_006df050(void)

{
  int in_ECX;
  
  return *(int *)(in_ECX + 0x638) != 0;
}

