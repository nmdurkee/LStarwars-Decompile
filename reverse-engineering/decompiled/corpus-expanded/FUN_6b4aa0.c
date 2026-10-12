/* Ghidra pseudocode, not original source.
 * ev_8eef0e367f1a27c7ef4dce890dd1e02a98f2c666b50c9e5dab0b6aeb2e260fd2
 * Entry: 0x6b4aa0; label: FUN_006b4aa0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_006b4aa0(void)

{
  int iVar1;
  int in_ECX;
  uint uVar2;
  
  iVar1 = 0;
  if (in_ECX != 0) {
    for (uVar2 = in_ECX - 1; uVar2 != 0; uVar2 = uVar2 >> 1) {
      iVar1 = iVar1 + 1;
    }
  }
  return iVar1;
}

