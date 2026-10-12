/* Ghidra pseudocode, not original source.
 * ev_80f10280a68e27d1163faa95206013e039612dceeee316e4395f60ba03bc283c
 * Entry: 0x5d0ee0; label: FUN_005d0ee0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

