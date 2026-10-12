/* Ghidra pseudocode, not original source.
 * ev_d7259de4d528e446adcf31e3fd20dda0be8e8c3eebc020039674bf2429a30a4e
 * Entry: 0x4762a0; label: FUN_004762a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004762a0(float *param_1)

{
  float fVar1;
  
  fVar1 = *param_1;
  if (!NAN(fVar1) && 5.0 < fVar1 != (fVar1 == 5.0)) {
    DAT_00951b80 = DAT_00951b94;
    return;
  }
  fVar1 = *param_1;
  if ((!NAN(fVar1) && 1.5 < fVar1 != (fVar1 == 1.5)) && (DAT_0086e71c == 0)) {
    FUN_00681f40("Victory",0);
    DAT_0086e71c = 1;
  }
  return;
}

