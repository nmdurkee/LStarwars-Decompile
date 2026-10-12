/* Ghidra analysis pseudocode, not original source.
 * ev_0d1e553906e4ac29f0c898728bb3c9cf38177ab98ca2cbcdea8e6b852723dd83
 * Entry: 0x59c980; label: FUN_0059c980
 */

undefined4 FUN_0059c980(float param_1,undefined4 param_2)

{
  ushort uVar1;
  int iVar2;
  ushort uVar3;
  float10 fVar4;
  
  iVar2 = (int)param_1;
  uVar1 = *(ushort *)((int)param_1 + 0x5a);
  uVar3 = uVar1 + 0x4000;
  *(undefined4 *)((int)param_1 + 0xf18) = (&DAT_029899a0)[uVar1 >> 1];
  *(undefined4 *)((int)param_1 + 0xf20) = (&DAT_029899a0)[(int)(uVar1 + 0x4000) >> 1 & 0x7fff];
  fVar4 = (float10)FUN_00550180(param_2,(uint)uVar3);
  if ((float)fVar4 <= DAT_02996ef4) {
    if (-DAT_02996ef4 <= (float)fVar4) {
      *(undefined2 *)((int)param_1 + 0x7aa) = DAT_00804c58;
      return 0;
    }
    if ((DAT_00804c5c == -1) ||
       (*(int *)(*(int *)(*(int *)((int)param_1 + 0x50) + 0xc) + DAT_00804c5c * 4) == 0)) {
      param_1 = -0.5;
      goto LAB_0059ca38;
    }
    *(short *)((int)param_1 + 0x7aa) = DAT_00804c5c;
    fVar4 = (float10)FUN_0062f1c0(*(int *)((int)param_1 + 0x50),(int)DAT_00804c5c);
    fVar4 = -fVar4;
  }
  else {
    if ((DAT_00804c60 == -1) ||
       (*(int *)(*(int *)(*(int *)((int)param_1 + 0x50) + 0xc) + DAT_00804c60 * 4) == 0)) {
      param_1 = 0.5;
      goto LAB_0059ca38;
    }
    *(short *)((int)param_1 + 0x7aa) = DAT_00804c60;
    fVar4 = (float10)FUN_0062f1c0(*(int *)((int)param_1 + 0x50),(int)DAT_00804c60);
  }
  param_1 = (float)fVar4;
  if (param_1 == 0.0) {
    return 0;
  }
LAB_0059ca38:
  *(float *)(iVar2 + 0xf18) =
       *(float *)(iVar2 + 0xf18) + param_1 * (float)(&DAT_029899a0)[uVar3 >> 1];
  *(float *)(iVar2 + 0xf20) =
       param_1 * (float)(&DAT_029899a0)[(int)(uVar3 + 0x4000) >> 1 & 0x7fff] +
       *(float *)(iVar2 + 0xf20);
  return 0;
}

