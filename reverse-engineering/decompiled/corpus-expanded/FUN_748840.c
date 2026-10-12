/* Ghidra pseudocode, not original source.
 * ev_80517fb4f192ecd2851e0fd4e2a7dbbf5e68bec5ed1b7e7e17e8e9bcd800f2e9
 * Entry: 0x748840; label: FUN_00748840
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00748840(void)

{
  int *in_ECX;
  
  if (((in_ECX[3] == 0) && ((*(uint *)(*in_ECX + 0x1b8) & 0x20) != 0)) &&
     ((*(uint *)(*in_ECX + 0x1b8) & 0x8000) != 0)) {
    return 1;
  }
  return 0;
}

