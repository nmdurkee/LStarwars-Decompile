/* Ghidra pseudocode, not original source.
 * ev_c8c236b59c094db138f75ad711126508fb50275f6e5d8f12ab0ad6308e4435ce
 * Entry: 0x497540; label: FUN_00497540
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00497540(float *param_1)

{
  float fVar1;
  
  fVar1 = *param_1;
  if (!NAN(fVar1) && 5.0 < fVar1 != (fVar1 == 5.0)) {
    FUN_0057a5b0();
    return;
  }
  fVar1 = *param_1;
  if ((!NAN(fVar1) && 1.5 < fVar1 != (fVar1 == 1.5)) && (DAT_0086e71c == 0)) {
    FUN_00681f40("Victory",0);
    DAT_0086e71c = 1;
  }
  return;
}

