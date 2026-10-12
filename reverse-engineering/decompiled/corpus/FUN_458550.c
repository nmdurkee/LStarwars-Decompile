/* Ghidra analysis pseudocode, not original source.
 * ev_5f3da693bf096313253939ed49ba5271cfe8862e4a440ae5c9d57980f69a0d69
 * Entry: 0x458550; label: FUN_00458550
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00458550(float param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 extraout_ST0_01;
  float10 fVar5;
  float10 extraout_ST1;
  float10 extraout_ST1_00;
  float10 fVar6;
  undefined1 local_40 [64];
  
  iVar3 = (int)param_1;
  FUN_005b44e0(local_40);
  if (param_1 == 0.0) {
    return;
  }
  iVar4 = *(int *)((int)param_1 + 0x124);
  if (iVar4 == 0) {
    return;
  }
  if (*(int *)(iVar4 + 0x14) != -1) {
    if (*(int *)((int)param_1 + 0x120) != 0) {
      FUN_00552d10(-_DAT_007f824c,_DAT_007f8254,_DAT_007f8258,0x40400000,0x40400000,0x40400000,
                   0xc000,0,0,
                   *(short *)(*(int *)((int)param_1 + 0x120) + 0x10) * 0x10 +
                   *(int *)(PTR_DAT_00802c54 + 0x2ac0),0);
    }
    if (*(int *)((int)param_1 + 0x124) != 0) {
      FUN_00552d10(0,_DAT_007f8254,_DAT_007f8258,0x40400000,0x40400000,0x40400000,0xc000,0,0,
                   *(short *)(*(int *)((int)param_1 + 0x124) + 0x10) * 0x10 +
                   *(int *)(PTR_DAT_00802c54 + 0x2ac0),0);
    }
    if (*(int *)((int)param_1 + 0x128) == 0) {
      return;
    }
    FUN_00552d10(_DAT_007f824c,_DAT_007f8254,_DAT_007f8258,0x40400000,0x40400000,0x40400000,0xc000,0
                 ,0,*(short *)(*(int *)((int)param_1 + 0x128) + 0x10) * 0x10 +
                    *(int *)(PTR_DAT_00802c54 + 0x2ac0),0);
    return;
  }
  *(float *)(iVar4 + 0x18) = *(float *)(iVar4 + 0x18) + _DAT_00925018;
  iVar4 = *(int *)((int)param_1 + 0x124);
  if (1.0 <= *(float *)(iVar4 + 0x18)) {
    if (*(float *)(iVar4 + 0x18) < 2.0) {
      iVar4 = FUN_006e6b90();
      param_1 = (_DAT_007f824c + 0.1) *
                (float)(extraout_ST0_00 + (float10)(float)(&DAT_029899a0)[iVar4 >> 1 & 0x7fff]) -
                0.1;
      goto LAB_004587de;
    }
    if ((*(float *)(iVar4 + 0x18) < 2.1) && ((*(byte *)((int)param_1 + 0xb0) & 2) == 0)) {
      iVar4 = FUN_006e6b90();
      param_1 = (float)(&DAT_029899a0)[iVar4 >> 1 & 0x7fff] * -0.1;
      goto LAB_004587de;
    }
    if ((3.1 <= *(float *)(iVar4 + 0x18)) || ((*(byte *)((int)param_1 + 0xb0) & 2) != 0)) {
      *(undefined4 *)(iVar4 + 0x18) = 0;
      *(undefined4 *)(*(int *)((int)param_1 + 0x124) + 0x14) = 0;
      *(undefined4 *)((int)param_1 + 0x11c) = 0;
      param_1 = 0.0;
      goto LAB_004587de;
    }
    param_1 = 0.0;
    if (_DAT_007f8258 == 1.1) {
      *(undefined4 *)(iVar4 + 0x18) = 0x40466666;
      goto LAB_004587de;
    }
    iVar4 = FUN_006e6b90();
    fVar1 = (float)(&DAT_029899a0)[iVar4 >> 1 & 0x7fff];
    fVar5 = extraout_ST0_01;
    fVar6 = extraout_ST1_00;
  }
  else {
    param_1 = _DAT_007f824c;
    if (_DAT_007f8258 == 1.5) {
      *(undefined4 *)(iVar4 + 0x18) = 0x3f800000;
      goto LAB_004587de;
    }
    iVar4 = FUN_006e6b90();
    fVar1 = (float)(&DAT_029899a0)[iVar4 >> 1 & 0x7fff];
    fVar5 = extraout_ST0;
    fVar6 = extraout_ST1;
  }
  fVar5 = (float10)FUN_0054fad0((float)fVar6,(float)fVar5,(1.0 - (fVar1 + 1.0) * 0.5) * 0.25);
  _DAT_007f8258 = (float)fVar5;
LAB_004587de:
  fVar1 = param_1 - _DAT_007f824c;
  fVar2 = fVar1 - _DAT_007f824c;
  FUN_00552d10(param_1,_DAT_007f8254,_DAT_007f8258,0x40400000,0x40400000,0x40400000,0xc000,0,0,
               *(short *)(*(int *)(iVar3 + 0x124) + 0x10) * 0x10 +
               *(int *)(PTR_DAT_00802c54 + 0x2ac0),0);
  if (*(int *)(iVar3 + 0x11c) != 0) {
    FUN_00552d10(fVar2,_DAT_007f8254,_DAT_007f8258,0x40400000,0x40400000,0x40400000,0xc000,0,0,
                 *(short *)(*(int *)(iVar3 + 0x11c) + 0x10) * 0x10 +
                 *(int *)(PTR_DAT_00802c54 + 0x2ac0),0);
  }
  if (*(int *)(iVar3 + 0x120) != 0) {
    FUN_00552d10(fVar1,_DAT_007f8254,_DAT_007f8258,0x40400000,0x40400000,0x40400000,0xc000,0,0,
                 *(short *)(*(int *)(iVar3 + 0x120) + 0x10) * 0x10 +
                 *(int *)(PTR_DAT_00802c54 + 0x2ac0),0);
  }
  if (*(int *)(iVar3 + 0x128) == 0) {
    return;
  }
  FUN_00552d10(_DAT_007f824c + param_1,_DAT_007f8254,_DAT_007f8258,0x40400000,0x40400000,0x40400000,
               0xc000,0,0,
               *(short *)(*(int *)(iVar3 + 0x128) + 0x10) * 0x10 +
               *(int *)(PTR_DAT_00802c54 + 0x2ac0),0);
  return;
}

