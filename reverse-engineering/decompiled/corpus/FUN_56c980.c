/* Ghidra analysis pseudocode, not original source.
 * ev_9c4a7344b4ed6999b1698de871080e88c37121f37ac9563577536a7a556549db
 * Entry: 0x56c980; label: FUN_0056c980
 */

undefined4 FUN_0056c980(float param_1)

{
  int iVar1;
  float10 fVar2;
  
  iVar1 = (int)param_1;
  if (*(float *)(*(int *)((int)param_1 + 0xca4) + 0x28) <= 0.0) {
    *(undefined4 *)((int)param_1 + 0xf20) = 0;
    *(undefined4 *)((int)param_1 + 0xf18) = 0;
    *(undefined4 *)((int)param_1 + 0xf1c) = 0x3f000000;
    return 1;
  }
  if (DAT_00804c40 != -1) {
    if (*(int *)(*(int *)(*(int *)((int)param_1 + 0x50) + 0xc) + DAT_00804c40 * 4) != 0) {
      fVar2 = (float10)FUN_0062f1c0(*(int *)((int)param_1 + 0x50),(int)DAT_00804c40);
      param_1 = (float)fVar2;
      if (param_1 < 0.25) {
        param_1 = 0.25;
      }
      goto LAB_0056c9eb;
    }
  }
  param_1 = 0.5;
LAB_0056c9eb:
  *(float *)(iVar1 + 0xf18) = param_1 * (float)(&DAT_029899a0)[*(ushort *)(iVar1 + 0x5a) >> 1];
  *(float *)(iVar1 + 0xf20) =
       param_1 * (float)(&DAT_029899a0)[(int)(*(ushort *)(iVar1 + 0x5a) + 0x4000) >> 1 & 0x7fff];
  *(undefined4 *)(iVar1 + 0xf1c) = 0x3f000000;
  return 1;
}

