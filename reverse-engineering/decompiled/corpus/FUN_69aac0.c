/* Ghidra analysis pseudocode, not original source.
 * ev_f1a36c6b3ad286842b1ed86bd3c2163f44c7dc63d65997010e74903b0be7db2b
 * Entry: 0x69aac0; label: FUN_0069aac0
 */

undefined4 FUN_0069aac0(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  if (*(char *)(in_ECX + 0x40) == '\0') {
    uVar1 = FUN_0069a250();
    return uVar1;
  }
  FUN_004ffaa0(DAT_02973a00);
  if (*(int *)(in_ECX + 0x318) == 0) {
    FUN_004ffac0(DAT_02973a00);
    return 0x80004005;
  }
  FUN_0069c3c0(in_ECX + 0x48);
  if (*(int *)(in_ECX + 0x318) != 0) {
    *(int *)(*(int *)(in_ECX + 0x318) + 0x110) = *(int *)(*(int *)(in_ECX + 0x318) + 0x110) + -1;
  }
  *(undefined4 *)(in_ECX + 0x318) = 0;
  FUN_004ffac0(DAT_02973a00);
  return 0;
}

