/* Ghidra analysis pseudocode, not original source.
 * ev_d881831d71d8ed35fa38d5b5eaee7ca2bcae4cde952964886fd1c7ddf43d442a
 * Entry: 0x4df0c0; label: FUN_004df0c0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004df0c0(void)

{
  if (_DAT_00888ed8 < 0.1) {
    _DAT_00888ed8 = _DAT_00888ed8 + _DAT_00925018;
    return;
  }
  if (6 < DAT_00888ed4) {
    if (DAT_0093b2a4 == 0) {
      DAT_00951b80 = DAT_0087b0d0;
    }
    FUN_0057a5b0();
  }
  DAT_00888ed6 = 0;
  _DAT_00888ed8 = 0.0;
  return;
}

