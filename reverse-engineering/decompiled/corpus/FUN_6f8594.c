/* Ghidra analysis pseudocode, not original source.
 * ev_2f277248dc33480f063e4f0d474d621052bdb6108e7bcd5536ed18fa967ce013
 * Entry: 0x6f8594; label: FUN_006f8594
 */

void FUN_006f8594(byte param_1)

{
  exception *in_ECX;
  
  *(undefined ***)in_ECX = &PTR_FUN_0077dff8;
  exception::~exception(in_ECX);
  if ((param_1 & 1) != 0) {
    _free(in_ECX);
  }
  return;
}

