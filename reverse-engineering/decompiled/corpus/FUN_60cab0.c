/* Ghidra analysis pseudocode, not original source.
 * ev_49dad5f20e053bf764d7eecccea7d519a0835f455b7dcdd298ee46307ff6e048
 * Entry: 0x60cab0; label: FUN_0060cab0
 */

void FUN_0060cab0(byte param_1)

{
  exception *in_ECX;
  
  *(undefined ***)in_ECX = &PTR_FUN_0076a8cc;
  if (0xf < *(uint *)(in_ECX + 0x24)) {
    _free(*(void **)(in_ECX + 0x10));
  }
  *(undefined4 *)(in_ECX + 0x24) = 0xf;
  *(undefined4 *)(in_ECX + 0x20) = 0;
  in_ECX[0x10] = (exception)0x0;
  exception::~exception(in_ECX);
  if ((param_1 & 1) != 0) {
    _free(in_ECX);
  }
  return;
}

