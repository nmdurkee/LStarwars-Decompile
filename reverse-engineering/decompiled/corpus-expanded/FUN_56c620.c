/* Ghidra pseudocode, not original source.
 * ev_6cd7b427fefd6a18a341146345d1c01d98fc33d6c80c45f814d5cdd3902e445d
 * Entry: 0x56c620; label: FUN_0056c620
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0056c620(float param_1,undefined4 param_2)

{
  short sVar1;
  int iVar2;
  ushort uVar3;
  float10 fVar4;
  
  iVar2 = (int)param_1;
  sVar1 = *(short *)((int)param_1 + 0x7aa);
  if ((sVar1 != -1) &&
     ((((sVar1 == DAT_00804c48 || (sVar1 == DAT_00804c4c)) || (sVar1 == DAT_00804c50)) ||
      ((sVar1 == DAT_00804c54 || (sVar1 == DAT_00804cc0)))))) {
    if (*(int *)(*(int *)(*(int *)((int)param_1 + 0x50) + 0xc) + sVar1 * 4) != 0) {
      fVar4 = (float10)FUN_0062f1c0(*(int *)((int)param_1 + 0x50),(int)sVar1);
      param_1 = ABS((float)fVar4);
      if (param_1 != 0.0) goto LAB_0056c6b1;
    }
  }
  param_1 = 0.5;
LAB_0056c6b1:
  uVar3 = *(ushort *)(iVar2 + 0x5a);
  *(float *)(iVar2 + 0xf18) = (float)(&DAT_029899a0)[uVar3 >> 1] * param_1;
  *(undefined4 *)(iVar2 + 0xf1c) = 0;
  *(float *)(iVar2 + 0xf20) = (float)(&DAT_029899a0)[(int)(uVar3 + 0x4000) >> 1 & 0x7fff] * param_1;
  if (0.0 < *(float *)(*(int *)(iVar2 + 0xca4) + 0x28)) {
    uVar3 = uVar3 + 0x4000;
    fVar4 = (float10)FUN_00550180(param_2,(uint)uVar3);
    *(float *)(iVar2 + 0xf18) =
         *(float *)(iVar2 + 0xf18) + param_1 * (float)fVar4 * (float)(&DAT_029899a0)[uVar3 >> 1];
    *(float *)(iVar2 + 0xf20) =
         (float)fVar4 * (float)(&DAT_029899a0)[(int)(uVar3 + 0x4000) >> 1 & 0x7fff] * param_1 +
         *(float *)(iVar2 + 0xf20);
    fVar4 = (float10)FUN_00550180(param_2,*(undefined2 *)(iVar2 + 0x5a));
    *(float *)(iVar2 + 0xf1c) =
         (float)(fVar4 * (float10)param_1 + (float10)*(float *)(iVar2 + 0xf1c));
  }
  return 1;
}

