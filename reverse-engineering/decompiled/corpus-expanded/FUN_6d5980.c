/* Ghidra pseudocode, not original source.
 * ev_334294c16a8347b4bc11d90e134269a6e2c30475b5c30bcaa57a53f4585ea308
 * Entry: 0x6d5980; label: FUN_006d5980
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

bool FUN_006d5980(void)

{
  int in_ECX;
  
  return *(int *)(in_ECX + 0x24) != 0;
}

