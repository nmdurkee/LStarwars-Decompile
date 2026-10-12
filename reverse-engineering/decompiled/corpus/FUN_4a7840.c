/* Ghidra analysis pseudocode, not original source.
 * ev_5c5e85395afb46ea48eeeced9462a622408ed7e413dd4eac1252ab90af09b35e
 * Entry: 0x4a7840; label: FUN_004a7840
 */

void FUN_004a7840(void)

{
  int in_ECX;
  
  if ((0.0 < *(float *)(*(int *)(in_ECX + 0xca4) + 0x28)) &&
     (*(int *)(*(int *)(*(int *)(in_ECX + 0x50) + 0xc) + 0x394) != 0)) {
    *(undefined2 *)(in_ECX + 0x7aa) = 0xe5;
    return;
  }
  *(undefined2 *)(in_ECX + 0x7aa) = 0x8e;
  return;
}

