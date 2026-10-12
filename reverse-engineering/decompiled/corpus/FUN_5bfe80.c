/* Ghidra analysis pseudocode, not original source.
 * ev_63802f60b4285c5edf6c429a3d1e3220ec0e39d2563d3bbc7dd58661d8af5682
 * Entry: 0x5bfe80; label: FUN_005bfe80
 */

void FUN_005bfe80(float *param_1,float *param_2,float *param_3,float *param_4,float *param_5)

{
  float fVar1;
  float fVar2;
  int iVar3;
  
  fVar1 = param_1[10];
  fVar2 = param_1[0xe];
  *param_4 = -fVar2 / fVar1;
  *param_5 = ((-fVar2 / fVar1) * fVar1) / (fVar1 - 1.0);
  *param_3 = param_1[5] / *param_1;
  iVar3 = FUN_005be2d0(1.0 / param_1[5],0x3f800000);
  *param_2 = ((float)iVar3 * 9.58738e-05 * 360.0) / 3.1415927;
  return;
}

