/* Ghidra pseudocode, not original source.
 * ev_c97b225204041db9abadf07c9fc18e64db4e00ddeb87fb2f1b5eee4128d34da7
 * Entry: 0x74c180; label: FUN_0074c180
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0074c180(void)

{
  int in_ECX;
  
  FUN_0074bbc0();
  *(int *)(in_ECX + 0x118) = *(int *)(in_ECX + 0x130 + *(int *)(in_ECX + 0x2c4) * 4) + 0xc;
  return;
}

