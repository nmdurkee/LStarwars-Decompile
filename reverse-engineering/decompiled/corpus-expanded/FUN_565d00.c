/* Ghidra pseudocode, not original source.
 * ev_cad26e3a9467a6f282c08bc6ac149c0630e72073e26a30c176ee0d766772994c
 * Entry: 0x565d00; label: FUN_00565d00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00565d00(void)

{
  float fVar1;
  
  if ((DAT_0087b4d8 == 0) && (DAT_00950744 == 0)) {
    if ((DAT_0093b328 == 0) && (DAT_0093b32c == 0)) {
      fVar1 = _DAT_00950774 - _DAT_00802e24 * _DAT_00925018;
      _DAT_00950774 = 0.0;
      if (0.0 < fVar1) {
        _DAT_00950774 = fVar1;
        return;
      }
    }
    else {
      fVar1 = _DAT_00802e24 * _DAT_00925018 + _DAT_00950774;
      _DAT_00950774 = 1.0;
      if (fVar1 < 1.0) {
        _DAT_00950774 = fVar1;
        return;
      }
    }
  }
  return;
}

