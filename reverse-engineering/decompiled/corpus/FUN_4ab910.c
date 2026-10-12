/* Ghidra analysis pseudocode, not original source.
 * ev_d01615a5a43d674e3d5304a49d42c1316108bf7c3b83d91b26d188fd5d83afac
 * Entry: 0x4ab910; label: FUN_004ab910
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004ab910(float param_1)

{
  int *piVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  float10 fVar5;
  
  iVar3 = (int)param_1;
  *(undefined2 *)((int)param_1 + 0x42) = 1;
  if ((((*(byte *)((int)param_1 + 0x1fc) & 0x80) == 0) || (*(char *)((int)param_1 + 0x280) == -1))
     || ((*(short *)((int)param_1 + 0x1064) != DAT_007f1b14 &&
         (*(short *)((int)param_1 + 0x1064) != DAT_007f1b18)))) {
    fVar5 = (float10)FUN_004dbb60(PTR_DAT_00802c54);
    if (((float10)0.0 < fVar5) || (iVar3 = FUN_004daa70(PTR_DAT_00802c54), iVar3 != 0)) {
      *(undefined2 *)((int)param_1 + 0x42) = 1;
    }
    else if (*(float *)((int)param_1 + 0x1038) <= 0.0) {
      if ((*(byte *)((int)param_1 + 0x1fc) & 0x80) == 0) {
        *(undefined2 *)((int)param_1 + 0x42) = 3;
      }
      else if ((DAT_0087af5c == 0) || (*(int *)(PTR_DAT_00802c54 + 300) != DAT_0087af5c)) {
        *(undefined2 *)((int)param_1 + 0x42) = 0;
      }
      else if (*(short *)((int)param_1 + 0xe10) != -1) {
        *(short *)((int)param_1 + 0x42) = *(short *)((int)param_1 + 0xe10);
      }
    }
    else {
      *(undefined2 *)((int)param_1 + 0x42) = 0x17;
    }
    if (*(int *)(*(int *)(*(int *)((int)param_1 + 0x50) + 0xc) + *(short *)((int)param_1 + 0x42) * 4
                ) == 0) {
      *(undefined2 *)((int)param_1 + 0x42) = 1;
    }
    return;
  }
  iVar4 = (int)*(char *)((int)param_1 + 0x280);
  piVar1 = (int *)((int)param_1 + 0x50);
  fVar2 = _DAT_00925018 * 30.0;
  *(undefined2 *)((int)param_1 + 0x42) = 1;
  param_1 = fVar2;
  if (*(int *)(*(int *)(*piVar1 + 0xc) + 4) != 0) {
    param_1 = (*(float *)(*(int *)(*(int *)(*piVar1 + 8) + 4) + 0x18) / 30.0) * fVar2;
  }
  param_1 = (float)(&DAT_007fc198)[iVar4] + param_1;
  (&DAT_007fc198)[iVar4] = param_1;
  if (_DAT_007fc1a0 < param_1 == (_DAT_007fc1a0 == param_1)) {
    FUN_004ab8a0(iVar3 + 8,iVar4);
    return;
  }
  (&DAT_007fc198)[iVar4] = param_1 - (_DAT_007fc1a0 - 1.0);
  FUN_004ab8a0(iVar3 + 8,iVar4);
  return;
}

