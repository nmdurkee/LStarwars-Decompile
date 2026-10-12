/* Ghidra analysis pseudocode, not original source.
 * ev_4a4bd67d6afd5c9569b182b6d27082f0bf05f4f4620e9437cf0e48e464abf09d
 * Entry: 0x5132a0; label: FUN_005132a0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_005132a0(undefined4 param_1)

{
  float10 fVar1;
  
  _DAT_0092224c = 0;
  DAT_00922250 = 0;
  DAT_00922254 = 0;
  fVar1 = (float10)FUN_004f88e0(param_1,&LAB_00513230);
  if (DAT_00922250 != 0) {
    DAT_00922254 = 1;
  }
  return (float10)(float)fVar1;
}

