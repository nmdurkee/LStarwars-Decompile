/* Ghidra pseudocode, not original source.
 * ev_80517fb4f192ecd2851e0fd4e2a7dbbf5e68bec5ed1b7e7e17e8e9bcd800f2e9
 * Entry: 0x7487c0; label: FUN_007487c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

bool FUN_007487c0(void)

{
  int in_ECX;
  
  return *(int *)(in_ECX + 0xc) != 0;
}

