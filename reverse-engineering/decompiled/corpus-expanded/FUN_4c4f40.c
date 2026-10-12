/* Ghidra pseudocode, not original source.
 * ev_e691f105e7e9df146417299401ecc100ef54520e911e9eb278e110fa7bbc9740
 * Entry: 0x4c4f40; label: FUN_004c4f40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004c4f40(void)

{
  float10 fVar1;
  
  if (_DAT_00880498 <= 0.0) {
    return;
  }
  if (((DAT_0087ffe8 != 0) && (_DAT_00880498 < 3.1499999)) &&
     (fVar1 = (float10)FUN_005b7d30(_DAT_00880498,0x3eb33333), fVar1 < (float10)0.175)) {
    FUN_0050d910(DAT_0087ffe8,0,(_DAT_007f92ec + _DAT_007f92e4) * 0.5,0x3f800000,0x3f4ccccd,
                 0x3f4ccccd,0x3f4ccccd,0,0,0xff,0,0x3fd9999a,1,0,0,0x80);
  }
  _DAT_00880498 = _DAT_00880498 - _DAT_00925018;
  return;
}

