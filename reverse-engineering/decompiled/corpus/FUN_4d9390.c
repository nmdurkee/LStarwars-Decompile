/* Ghidra analysis pseudocode, not original source.
 * ev_469f0313f1021f0e4bd926e538674038e4b9c059f1b4f78e0c32d78ee9f9f283
 * Entry: 0x4d9390; label: FUN_004d9390
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004d9390(void)

{
  int iVar1;
  float10 fVar2;
  float local_c [3];
  
  if (((DAT_00882a70 < 4) && (DAT_00855de0 == 0)) &&
     (_DAT_0088240c = _DAT_0088240c + _DAT_00925018, 1.0 < _DAT_0088240c)) {
    if (_DAT_008823d8 == 1e+09) {
      _DAT_008823d8 = *(float *)(PTR_DAT_008021b4 + 0x2c);
    }
    if ((*(float *)(PTR_DAT_008021b4 + 0x2c) < _DAT_007ffcf4) &&
       (_DAT_008823d8 < *(float *)(PTR_DAT_008021b4 + 0x2c) !=
        (_DAT_008823d8 == *(float *)(PTR_DAT_008021b4 + 0x2c)))) {
      fVar2 = (float10)FUN_005b9dd0();
      local_c[0] = (float)(((float10)_DAT_007ffcec + (float10)_DAT_007ffcec) *
                          ((float10)0.5 - fVar2));
      local_c[1] = 0.0;
      local_c[2] = (float)_DAT_007ffcf0;
      FUN_005b3620(local_c,local_c,*(undefined2 *)(DAT_0093d810 + 0x696));
      FUN_005b37d0(local_c,local_c,DAT_0093d810 + 0x80);
      iVar1 = FUN_004d8af0();
      if (iVar1 != 0) {
        _DAT_008823d8 =
             *(float *)(&DAT_007ffcdc + DAT_00882a70 * 4) + *(float *)(PTR_DAT_008021b4 + 0x2c);
      }
    }
  }
  return;
}

