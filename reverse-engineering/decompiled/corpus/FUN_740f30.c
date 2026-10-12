/* Ghidra analysis pseudocode, not original source.
 * ev_ec9281a2aa4ea110a1eb16e51d284c9eba7f36598b96ab7e95af51b91ca91f37
 * Entry: 0x740f30; label: FUN_00740f30
 */

void FUN_00740f30(int param_1,int param_2)

{
  undefined1 *in_ECX;
  
  *(int *)(in_ECX + 4) = param_1;
  *(int *)(in_ECX + 0xc) = param_1;
  *in_ECX = 0;
  *(int *)(in_ECX + 8) = param_1 + param_2;
  return;
}

