/* Ghidra analysis pseudocode, not original source.
 * ev_7c1f0ecd29c800f910a33bdaa344f8ed50b7b31113b7bd43cf044ecf7b83bf10
 * Entry: 0x6e9e1e; label: FUN_006e9e1e
 */

void FUN_006e9e1e(byte param_1)

{
  exception *in_ECX;
  
  *(undefined ***)in_ECX = &PTR_FUN_00777d74;
  exception::~exception(in_ECX);
  if ((param_1 & 1) != 0) {
    _free(in_ECX);
  }
  return;
}

