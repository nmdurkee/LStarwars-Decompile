/* Ghidra pseudocode, not original source.
 * ev_d9eb3013c9fda622502628697ce0d7be845892a91a12bfef10a3ae0a3a8d7789
 * Entry: 0x6dc750; label: FUN_006dc750
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

bool FUN_006dc750(void)

{
  int in_ECX;
  
  return *(int *)(in_ECX + 0x158) == 1;
}

