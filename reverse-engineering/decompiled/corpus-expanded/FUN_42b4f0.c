/* Ghidra pseudocode, not original source.
 * ev_cdce1c1a74417fce840dfa63a2c32577050f1657d9e1cb9f16f7031f05578a24
 * Entry: 0x42b4f0; label: FUN_0042b4f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0042b4f0(float *param_1)

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

