/* Ghidra analysis pseudocode, not original source.
 * ev_3ab0ab4bdd8dc8a455ed322812c7dbab6fd6000ce0d7a9019575e9409bf5a2c0
 * Entry: 0x4b7120; label: FUN_004b7120
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_004b7120(int param_1)

{
  int iVar1;
  
  if ((param_1 != -1) && ((param_1 == 0 || (param_1 == 1)))) {
    iVar1 = FUN_006e6b90();
    return (float10)((1.0 - ((float)(&DAT_029899a0)[iVar1 >> 1 & 0x7fff] + 1.0) * 0.5) *
                     (_DAT_007fc2bc - _DAT_007fc2b8) + _DAT_007fc2b8);
  }
  return (float10)_DAT_007fc2b8;
}

