/* Ghidra analysis pseudocode, not original source.
 * ev_9121b524f6182e73d65d2cf5b7796f5032c40ac2ecc24e842002b0e6ddc347ec
 * Entry: 0x61f8d0; label: FUN_0061f8d0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0061f8d0(void)

{
  float fVar1;
  
  fVar1 = 0.0;
  if ((0.0 <= _DAT_0080f550) && (fVar1 = _DAT_0080f550, 640.0 < _DAT_0080f550)) {
    _DAT_0080f550 = 640.0;
    fVar1 = _DAT_0080f550;
  }
  _DAT_0080f550 = fVar1;
  if (_DAT_0080f554 < 0.0) {
    _DAT_0080f554 = 0.0;
  }
  if (224.0 < _DAT_0080f554) {
    _DAT_0080f554 = 224.0;
  }
  return;
}

