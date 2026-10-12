/* Ghidra analysis pseudocode, not original source.
 * ev_7bd2508c4b1dcfad55b57fc1ea402f6c06ab2cec8e89f22b5b974cf1cad07afb
 * Entry: 0x5fa1e0; label: FUN_005fa1e0
 */

void FUN_005fa1e0(byte param_1)

{
  exception *in_ECX;
  
  *(undefined ***)in_ECX = &PTR_FUN_0076a75c;
  exception::~exception(in_ECX);
  if ((param_1 & 1) != 0) {
    _free(in_ECX);
  }
  return;
}

