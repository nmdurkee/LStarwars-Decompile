/* Ghidra analysis pseudocode, not original source.
 * ev_7899ebfae6ed5d770b9bee2927149d51290c957b7eb14b433099b39f075be2b3
 * Entry: 0x5d0ee0; label: FUN_005d0ee0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005d0ee0(float param_1,float param_2)

{
  if (1.0 <= param_1) {
    _DAT_0080b610 = param_1;
  }
  else {
    _DAT_0080b610 = 1.0;
  }
  if (param_2 < 1.0) {
    _DAT_0080b614 = 1.0;
    return;
  }
  _DAT_0080b614 = param_2;
  return;
}

