/* Ghidra pseudocode, not original source.
 * ev_96889fd8ad85600c7e65ee5089ba5210c04395d98557e70e963bff93f64702f9
 * Entry: 0x67ab50; label: FUN_0067ab50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0067ab50(float *param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float *pfVar4;
  
  pfVar4 = DAT_02921838;
  fVar1 = DAT_02921838[2] * param_1[2] + *param_1 * *DAT_02921838;
  fVar2 = param_1[2] * *DAT_02921838 - *param_1 * DAT_02921838[2];
  if (DAT_02921838[4] < fVar1) {
    fVar1 = DAT_02921838[4];
  }
  fVar3 = -DAT_02921838[4];
  if (fVar1 < fVar3) {
    fVar1 = fVar3;
  }
  if (DAT_02921838[4] * 0.2 < fVar2) {
    fVar2 = DAT_02921838[4] * 0.2;
  }
  if (fVar2 < fVar3 * 0.2) {
    fVar2 = fVar3 * 0.2;
  }
  *param_2 = *param_2 - ((fVar2 * param_1[2] + *param_1 * fVar1) - *DAT_02921838);
  param_2[2] = param_2[2] - ((fVar1 * param_1[2] - *param_1 * fVar2) - pfVar4[2]);
  *pfVar4 = fVar2 * param_1[2] + *param_1 * fVar1;
  pfVar4[2] = param_1[2] * fVar1 - fVar2 * *param_1;
  return;
}

