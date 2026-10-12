/* Ghidra pseudocode, not original source.
 * ev_334294c16a8347b4bc11d90e134269a6e2c30475b5c30bcaa57a53f4585ea308
 * Entry: 0x6d5970; label: FUN_006d5970
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

bool FUN_006d5970(void)

{
  int in_ECX;
  
  return *(int *)(in_ECX + 0x20) != 0;
}

