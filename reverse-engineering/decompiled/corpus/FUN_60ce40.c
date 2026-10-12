/* Ghidra analysis pseudocode, not original source.
 * ev_49f26c3128d8416ab7d2a78e52c78c067d57c30a907ee8cca08757c1961064c2
 * Entry: 0x60ce40; label: FUN_0060ce40
 */

void FUN_0060ce40(void)

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

