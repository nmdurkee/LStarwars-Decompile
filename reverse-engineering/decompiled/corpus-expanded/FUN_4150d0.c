/* Ghidra pseudocode, not original source.
 * ev_c5aa9bb8cc1ea02955c57ce11c44cd7d2d7b8bb5b9f56b563e0c53fc6061ed49
 * Entry: 0x4150d0; label: FUN_004150d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004150d0(int param_1,int param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  float10 fVar3;
  
  if (param_3 == 0x97) {
    return;
  }
  *(undefined4 *)(param_1 + 700) = 0;
  *(short *)(param_1 + 0x2c4) = (short)param_3;
  iVar1 = (short)param_3 * 4;
  if (*(int *)(iVar1 + *(int *)(*(int *)(param_1 + 0x50) + 0xc)) != 0) {
    iVar1 = *(int *)(iVar1 + *(int *)(*(int *)(param_1 + 0x50) + 8));
    param_3 = (uint)*(byte *)(iVar1 + 0xc);
    if (param_3 != 0) {
      uVar2 = (uint)*(byte *)(iVar1 + 0xd);
      if (param_3 < uVar2) {
        iVar1 = FUN_0054fa60();
        param_3 = param_3 + iVar1 / ((int)(0xffff / (longlong)(int)(uVar2 - param_3)) + 1);
      }
      fVar3 = (float10)FUN_0062e040((int)*(short *)(param_1 + 0x1064),
                                    (int)*(short *)(param_1 + 0x2c4),0,0,0);
      fVar3 = fVar3 * (float10)(int)param_3 - (float10)_DAT_029a99a4;
      goto LAB_00415199;
    }
  }
  iVar1 = FUN_0054fa60();
  fVar3 = (float10)iVar1 * (float10)1.5259021893143654e-05 * (float10)7.0 + (float10)8.0;
LAB_00415199:
  *(float *)(param_1 + 0x2c0) = (float)fVar3;
  if ((0 < param_2) && (*(undefined4 *)(param_1 + 0x2b8) = 0, 1 < param_2)) {
    *(undefined2 *)(param_1 + 0x2c6) = 0xffff;
  }
  return;
}

