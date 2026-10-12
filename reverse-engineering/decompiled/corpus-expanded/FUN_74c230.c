/* Ghidra pseudocode, not original source.
 * ev_c97b225204041db9abadf07c9fc18e64db4e00ddeb87fb2f1b5eee4128d34da7
 * Entry: 0x74c230; label: FUN_0074c230
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0074c230(void)

{
  int iVar1;
  int in_ECX;
  
  FUN_0074bbc0();
  iVar1 = *(int *)(in_ECX + 0x458);
  if (*(int *)(in_ECX + 0x130 + *(int *)(in_ECX + 0x2c4) * 4) !=
      *(int *)(in_ECX + 0x2c4 + iVar1 * 4)) {
    do {
      *(int *)(in_ECX + 0x2c4) = *(int *)(in_ECX + 0x2c4) + -1;
    } while (*(int *)(in_ECX + 0x130 + *(int *)(in_ECX + 0x2c4) * 4) !=
             *(int *)(in_ECX + 0x2c4 + iVar1 * 4));
  }
  *(int *)(in_ECX + 0x2c4) = *(int *)(in_ECX + 0x2c4) + -1;
  *(int *)(in_ECX + 0x118) = *(int *)(in_ECX + 0x134 + *(int *)(in_ECX + 0x2c4) * 4) + 4;
  *(int *)(in_ECX + 0x458) = iVar1 + -1;
  return;
}

