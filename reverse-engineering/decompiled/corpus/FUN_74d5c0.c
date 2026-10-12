/* Ghidra analysis pseudocode, not original source.
 * ev_d43409c1beaf04de5181c7e79b8ae898b4513b764b0aa0772119c8ac5b4cb60b
 * Entry: 0x74d5c0; label: FUN_0074d5c0
 */

void FUN_0074d5c0(void)

{
  int in_ECX;
  
  if (*(void **)(in_ECX + 4) != (void *)0x0) {
    _free(*(void **)(in_ECX + 4));
  }
  *(undefined4 *)(in_ECX + 4) = 0;
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  return;
}

