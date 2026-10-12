/* Ghidra pseudocode, not original source.
 * ev_80517fb4f192ecd2851e0fd4e2a7dbbf5e68bec5ed1b7e7e17e8e9bcd800f2e9
 * Entry: 0x748a60; label: FUN_00748a60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_00748a60(void)

{
  int *in_ECX;
  
  return *(uint *)(*in_ECX + 0x1bc) & 1;
}

