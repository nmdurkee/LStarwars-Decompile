/* Ghidra analysis pseudocode, not original source.
 * ev_ec9281a2aa4ea110a1eb16e51d284c9eba7f36598b96ab7e95af51b91ca91f37
 * Entry: 0x740e90; label: FUN_00740e90
 */

void FUN_00740e90(void)

{
  char *in_ECX;
  
  if ((*in_ECX != '\0') && (*(void **)(in_ECX + 0xc) != (void *)0x0)) {
    _free(*(void **)(in_ECX + 0xc));
  }
  return;
}

