/* Ghidra analysis pseudocode, not original source.
 * ev_8e49f0d7b7d603436767358480d73156eb2c225a9905dada8633f81c37eed0ad
 * Entry: 0x4239e0; label: FUN_004239e0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004239e0(void)

{
  float fVar1;
  int iVar2;
  undefined4 uVar3;
  float *unaff_ESI;
  ushort unaff_DI;
  undefined2 in_FPUControlWord;
  float10 extraout_ST0;
  double dVar4;
  undefined2 local_4;
  
  if (unaff_ESI[1] < *unaff_ESI) {
    fVar1 = _DAT_00925018 + unaff_ESI[1];
    unaff_ESI[1] = fVar1;
    if (*unaff_ESI < fVar1 != (*unaff_ESI == fVar1)) {
      unaff_ESI[1] = *unaff_ESI;
      iVar2 = FUN_0054fa60();
      unaff_ESI[2] = (float)iVar2 * 1.5259022e-05 * 0.5 + 0.5;
    }
    uVar3 = FUN_00550040(*(undefined2 *)(unaff_ESI + 3),*(undefined2 *)((int)unaff_ESI + 0xe));
    iVar2 = FUN_006e6b90(uVar3);
    local_4 = (undefined2)
              (int)ROUND((float10)*(ushort *)(unaff_ESI + 3) +
                         ((float10)1 -
                         ((float10)(float)(&DAT_029899a0)[iVar2 >> 1 & 0x7fff] + (float10)1) *
                         (float10)0.5) * extraout_ST0);
    *(undefined2 *)(unaff_ESI + 4) = local_4;
    return;
  }
  fVar1 = unaff_ESI[2] - _DAT_00925018;
  unaff_ESI[2] = fVar1;
  if (fVar1 <= 0.0) {
    *(undefined2 *)(unaff_ESI + 3) = *(undefined2 *)(unaff_ESI + 4);
    iVar2 = FUN_00550040();
    dVar4 = (double)iVar2;
    iVar2 = FUN_0054fa60();
    local_4 = (undefined2)
              (int)ROUND((double)unaff_DI + (double)iVar2 * 1.5259021893143654e-05 * dVar4);
    *(undefined2 *)((int)unaff_ESI + 0xe) = local_4;
    unaff_ESI[1] = 0.0;
    iVar2 = FUN_0054fa60(in_FPUControlWord);
    *unaff_ESI = (float)iVar2 * 1.5259022e-05 + 1.0;
  }
  return;
}

