/* Ghidra pseudocode, not original source.
 * ev_c97b225204041db9abadf07c9fc18e64db4e00ddeb87fb2f1b5eee4128d34da7
 * Entry: 0x74d790; label: FUN_0074d790
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0074d790(void)

{
  int in_ECX;
  
  FUN_0074d690();
  FUN_00748490();
  if (*(int *)(in_ECX + 0x104) != 0) {
    FUN_006e85b0(*(int *)(in_ECX + 0x104));
  }
  *(undefined4 *)(in_ECX + 0x104) = 0;
  *(undefined4 *)(in_ECX + 0x108) = 0;
  *(undefined4 *)(in_ECX + 0x10c) = 0;
  return;
}

