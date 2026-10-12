/* Ghidra analysis pseudocode, not original source.
 * ev_d43409c1beaf04de5181c7e79b8ae898b4513b764b0aa0772119c8ac5b4cb60b
 * Entry: 0x74c230; label: FUN_0074c230
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

