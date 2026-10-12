/* Ghidra pseudocode, not original source.
 * ev_dd26b1472d11f86911997a5210ef83804c7265178bcab9b4c8b40141cd7b855f
 * Entry: 0x4d1cf0; label: FUN_004d1cf0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_004d1cf0(int param_1)

{
  float fVar1;
  float fVar2;
  float *pfVar3;
  int iVar4;
  ushort uVar5;
  
  pfVar3 = (float *)(param_1 + 0x19c);
  if ((*(uint *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x90) & 0x80000) == 0) {
    pfVar3 = (float *)(param_1 + 400);
  }
  *(float *)(param_1 + 0xf18) = (*(float *)(param_1 + 0x754) - *pfVar3) * 3.0;
  *(float *)(param_1 + 0xf1c) = (*(float *)(param_1 + 0x758) - pfVar3[1]) * 3.0;
  *(float *)(param_1 + 0xf20) = (*(float *)(param_1 + 0x75c) - pfVar3[2]) * 3.0;
  uVar5 = *(short *)(*(int *)(param_1 + 0x798) + 0x44) + 0x4000;
  iVar4 = FUN_006e6b90();
  fVar2 = (float)(&DAT_029899a0)[iVar4 >> 1 & 0x7fff] * 0.5;
  iVar4 = FUN_0054fa60();
  *(float *)(param_1 + 0xf18) =
       ((float)iVar4 * 1.5259022e-05 - 0.5) * fVar2 * (float)(&DAT_029899a0)[uVar5 >> 1] +
       *(float *)(param_1 + 0xf18);
  fVar1 = *(float *)(param_1 + 0xf1c);
  iVar4 = FUN_0054fa60();
  *(float *)(param_1 + 0xf1c) = fVar1 - (float)iVar4 * 1.5259022e-05 * fVar2;
  iVar4 = FUN_0054fa60();
  *(float *)(param_1 + 0xf20) =
       ((float)iVar4 * 1.5259022e-05 - 0.5) * fVar2 *
       (float)(&DAT_029899a0)[(int)(uVar5 + 0x4000) >> 1 & 0x7fff] + *(float *)(param_1 + 0xf20);
  if ((*(short *)(param_1 + 0x7aa) != 6) && (*(short *)(param_1 + 0x7aa) != 5)) {
    return 1;
  }
  return 0;
}

