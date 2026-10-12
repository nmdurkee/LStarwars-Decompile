/* Ghidra pseudocode, not original source.
 * ev_8eef0e367f1a27c7ef4dce890dd1e02a98f2c666b50c9e5dab0b6aeb2e260fd2
 * Entry: 0x6b5190; label: FUN_006b5190
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_006b5190(void)

{
  uint uVar1;
  
  uVar1 = FUN_006e6b90();
  if (0x3ff < (int)uVar1) {
    return 0x3ff;
  }
  return uVar1 & ((int)uVar1 < 0) - 1;
}

