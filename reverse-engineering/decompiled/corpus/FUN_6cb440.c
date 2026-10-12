/* Ghidra analysis pseudocode, not original source.
 * ev_defa56967bea180293c2bb16677406271af3ce5a827b3a721aa49801cdb81f39
 * Entry: 0x6cb440; label: FUN_006cb440
 */

void FUN_006cb440(byte param_1)

{
  void *in_ECX;
  
  *(undefined ***)((int)in_ECX + 0x109c) = &PTR_LAB_0076f6e0;
  FUN_00633540();
  if ((param_1 & 1) != 0) {
    _free(in_ECX);
  }
  return;
}

