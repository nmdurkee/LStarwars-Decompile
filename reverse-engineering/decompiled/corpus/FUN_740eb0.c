/* Ghidra analysis pseudocode, not original source.
 * ev_ec9281a2aa4ea110a1eb16e51d284c9eba7f36598b96ab7e95af51b91ca91f37
 * Entry: 0x740eb0; label: FUN_00740eb0
 */

void FUN_00740eb0(int param_1,int param_2)

{
  char *in_ECX;
  
  if ((*in_ECX != '\0') && (*(void **)(in_ECX + 0xc) != (void *)0x0)) {
    _free(*(void **)(in_ECX + 0xc));
  }
  *(int *)(in_ECX + 4) = param_1;
  *(int *)(in_ECX + 0xc) = param_1;
  *in_ECX = '\0';
  *(int *)(in_ECX + 8) = param_1 + param_2;
  return;
}

