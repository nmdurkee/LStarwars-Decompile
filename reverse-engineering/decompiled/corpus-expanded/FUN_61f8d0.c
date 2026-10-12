/* Ghidra pseudocode, not original source.
 * ev_001bae53855cec29a6ea9336ea11e15c4e661e4f9ad78accb3ab39ae90f716fb
 * Entry: 0x61f8d0; label: FUN_0061f8d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

