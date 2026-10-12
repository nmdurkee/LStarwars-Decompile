/* Ghidra analysis pseudocode, not original source.
 * ev_f77d0ac966a5398976b96c42189a5c308704a96dca5e44da054727b198f01d57
 * Entry: 0x432330; label: FUN_00432330
 */

char FUN_00432330(int param_1,int param_2,undefined4 param_3,uint param_4)

{
  float fVar1;
  undefined1 uVar2;
  undefined2 uVar3;
  int iVar4;
  int iVar5;
  float10 fVar6;
  int local_40 [16];
  
  iVar5 = 0;
  if (*(char *)(param_1 + 0x280) != -1) {
    return '\0';
  }
  iVar4 = *(int *)(*(int *)(param_1 + 0x50) + 0xc);
  if ((*(int *)(iVar4 + 0x29c) != 0) && (*(int *)(iVar4 + 0x2a8) != 0)) {
    local_40[0] = 0xa7;
    iVar5 = 1;
  }
  if ((*(int *)(iVar4 + 0x2a0) != 0) && (*(int *)(iVar4 + 0x2ac) != 0)) {
    local_40[iVar5] = 0xa8;
    iVar5 = iVar5 + 1;
  }
  if ((*(int *)(iVar4 + 0x2a4) != 0) && (*(int *)(iVar4 + 0x2b0) != 0)) {
    local_40[iVar5] = 0xa9;
    iVar5 = iVar5 + 1;
  }
  if ((param_4 & 0x200) == 0) {
    if (*(int *)(iVar4 + 0xf4) != 0) {
      local_40[iVar5] = 0x3d;
      iVar5 = iVar5 + 1;
    }
    if (((param_2 != 0) && ((*(byte *)(param_2 + 0x1fc) & 0x80) != 0)) &&
       (*(int *)(iVar4 + 0x2e4) != 0)) {
      local_40[iVar5] = 0xb9;
      iVar5 = iVar5 + 1;
    }
  }
  if (iVar5 == 0) {
    iVar5 = 1;
  }
  else {
    iVar4 = FUN_0054fa60();
    iVar5 = local_40[iVar4 / ((int)(0xffff / (ulonglong)(longlong)iVar5) + 1)];
    if (iVar5 == -1) {
      return '\0';
    }
  }
  uVar2 = *(undefined1 *)(param_1 + 0xe32);
  *(short *)(param_1 + 0x7aa) = (short)iVar5;
  fVar6 = (float10)FUN_0062f1c0(*(undefined4 *)(param_1 + 0x50),(int)(short)iVar5);
  fVar1 = (float)fVar6;
  *(float *)(param_1 + 0x750) = fVar1;
  if ((*(short *)(param_1 + 0x7aa) != 0xb9) && (*(short *)(param_1 + 0x7aa) != 0x3d)) {
    if (0.0 < fVar1) {
      if (fVar1 < 0.8 != (fVar1 == 0.8)) {
        *(undefined4 *)(param_1 + 0x750) = 0x3f4ccccd;
      }
    }
    else {
      *(undefined4 *)(param_1 + 0x750) = 0x3f800000;
    }
  }
  FUN_0062e650(param_1 + 8,0xffffffff);
  FUN_0055e4a0(param_1,1);
  FUN_0055e4e0(param_1 + 0x6c4);
  *(undefined4 *)(param_1 + 0x778) = param_3;
  *(undefined1 *)(param_1 + 0x7b5) = 0x5a;
  *(undefined1 *)(param_1 + 0x7b3) = 0;
  if (param_2 != 0) {
    uVar3 = FUN_005be2d0(*(float *)(param_2 + 0x80) - *(float *)(param_1 + 0x80),
                         *(float *)(param_2 + 0x88) - *(float *)(param_1 + 0x88));
    *(undefined2 *)(param_1 + 0x27a) = uVar3;
    *(undefined2 *)(param_1 + 0x5a) = uVar3;
    *(undefined2 *)(param_1 + 0x58) = uVar3;
  }
  iVar5 = (int)*(short *)(param_1 + 0x7aa);
  if ((*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + iVar5 * 4) == 0) ||
     ((*(byte *)(*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 8) + iVar5 * 4) + 4) & 2) == 0)) {
    fVar6 = (float10)FUN_0062e040((int)*(short *)(param_1 + 0x1064),iVar5,0,0,
                                  *(short *)(param_1 + 0x7aa) != 0xb9);
    *(float *)(param_1 + 0x77c) = (float)fVar6;
    if (0.0 < (float)fVar6) goto LAB_004325a5;
    fVar1 = 0.6;
  }
  else {
    iVar5 = FUN_0054fa60();
    fVar1 = (float)iVar5 * 1.5259022e-05 * 0.5 + 1.0;
  }
  *(float *)(param_1 + 0x77c) = fVar1;
LAB_004325a5:
  if (param_2 != 0) {
    uVar3 = FUN_005be2d0(-(*(float *)(param_1 + 0x80) - *(float *)(param_2 + 0x80)),
                         -(*(float *)(param_1 + 0x88) - *(float *)(param_2 + 0x88)));
    *(undefined2 *)(param_1 + 0x5a) = uVar3;
  }
  *(undefined1 *)(param_1 + 0xe32) = uVar2;
  return (*(short *)(param_1 + 0x7aa) == 0xb9) + '\x01';
}

