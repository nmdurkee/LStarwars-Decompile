/* Ghidra analysis pseudocode, not original source.
 * ev_3ab0ab4bdd8dc8a455ed322812c7dbab6fd6000ce0d7a9019575e9409bf5a2c0
 * Entry: 0x4b9040; label: FUN_004b9040
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_004b9040(void)

{
  int iVar1;
  
  FUN_005b7d30(_DAT_00925064,0x3f000000);
  iVar1 = FUN_006e6b90();
  return (float10)((float)(&DAT_029899a0)[iVar1 >> 1 & 0x7fff] * 0.2 + 0.5);
}

