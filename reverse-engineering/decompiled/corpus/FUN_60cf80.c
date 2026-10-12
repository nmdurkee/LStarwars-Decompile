/* Ghidra analysis pseudocode, not original source.
 * ev_49f26c3128d8416ab7d2a78e52c78c067d57c30a907ee8cca08757c1961064c2
 * Entry: 0x60cf80; label: FUN_0060cf80
 */

void FUN_0060cf80(void)

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
  return;
}

