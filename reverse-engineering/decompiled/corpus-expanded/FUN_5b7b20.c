/* Ghidra pseudocode, not original source.
 * ev_5f8bd7f02bbfa9819b1ea6d4f28ed7de24e0304b6779d959c9b1888bbc6517da
 * Entry: 0x5b7b20; label: FUN_005b7b20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005b7b20(float *param_1,float *param_2,float *param_3,float *param_4,float *param_5,
                 float *param_6,float *param_7)

{
  float fVar1;
  float fVar2;
  
  fVar1 = (param_1[10] + 1.0) * 0.5;
  fVar2 = -((param_1[0xe] * 0.5) / fVar1);
  if (param_7 != (float *)0x0) {
    *param_7 = (fVar2 * fVar1) / (fVar1 - 1.0);
  }
  if (param_2 != (float *)0x0) {
    *param_2 = ((-1.0 - param_1[8]) * fVar2) / *param_1;
  }
  if (param_3 != (float *)0x0) {
    *param_3 = ((1.0 - param_1[8]) * fVar2) / *param_1;
  }
  if (param_4 != (float *)0x0) {
    *param_4 = ((-1.0 - param_1[9]) * fVar2) / param_1[5];
  }
  if (param_5 != (float *)0x0) {
    *param_5 = ((1.0 - param_1[9]) * fVar2) / param_1[5];
  }
  if (param_6 == (float *)0x0) {
    return;
  }
  *param_6 = fVar2;
  return;
}

