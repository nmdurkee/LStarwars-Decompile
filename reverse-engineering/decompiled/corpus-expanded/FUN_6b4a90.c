/* Ghidra pseudocode, not original source.
 * ev_8eef0e367f1a27c7ef4dce890dd1e02a98f2c666b50c9e5dab0b6aeb2e260fd2
 * Entry: 0x6b4a90; label: FUN_006b4a90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_006b4a90(void)

{
  int iVar1;
  uint in_ECX;
  
  iVar1 = 0;
  for (; in_ECX != 0; in_ECX = in_ECX >> 1) {
    iVar1 = iVar1 + 1;
  }
  return iVar1;
}

