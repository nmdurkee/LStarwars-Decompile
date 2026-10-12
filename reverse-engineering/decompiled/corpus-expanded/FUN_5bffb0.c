/* Ghidra pseudocode, not original source.
 * ev_36c2cdffab22dec35ae5154a8d67af88b00f5702395280041def6b77535d68b9
 * Entry: 0x5bffb0; label: FUN_005bffb0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005bffb0(float *param_1,float *param_2,float *param_3,float *param_4,float *param_5)

{
  float fVar1;
  float fVar2;
  int iVar3;
  
  fVar1 = param_1[10];
  fVar2 = (fVar1 + fVar1) / param_1[0xe] - 1.0;
  *param_4 = fVar2;
  *param_5 = (fVar2 * fVar1) / (fVar1 - 1.0);
  *param_3 = param_1[5] / *param_1;
  iVar3 = FUN_005be2d0(1.0 / param_1[5],0x3f800000);
  *param_2 = ((float)iVar3 * 9.58738e-05 * 360.0) / 3.1415927;
  return;
}

