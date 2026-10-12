/* Ghidra analysis pseudocode, not original source.
 * ev_7a6f44793a1ae116413d84873b30ec9fe28028ad0afd3b3275dd7a03cd0119e5
 * Entry: 0x696bf0; label: FUN_00696bf0
 */

void FUN_00696bf0(byte param_1)

{
  void *in_ECX;
  
  FUN_006998f0();
  if ((param_1 & 1) != 0) {
    _free(in_ECX);
  }
  return;
}

