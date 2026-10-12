/* Ghidra analysis pseudocode, not original source.
 * ev_f0b2ce2d5885583ae7420409f057ba3a395d2cbd12cd318b48692f86b50c0045
 * Entry: 0x655c30; label: FUN_00655c30
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00655c30(int param_1)

{
  float fVar1;
  int iVar2;
  undefined2 uVar3;
  int iVar4;
  float10 fVar5;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 fVar6;
  float10 fVar7;
  float10 extraout_ST1;
  float10 extraout_ST1_00;
  
  FUN_006e6b90();
  if (param_1 != 0) {
    iVar2 = *(int *)(DAT_0296209c + *(short *)(param_1 + 0x182) * 4);
    fVar1 = _DAT_0296205c;
    if (*(char *)(iVar2 + 0x2f1) == '\x04') {
      fVar1 = _DAT_02962060;
    }
    fVar7 = (float10)0;
    if ((fVar7 == (float10)*(float *)(iVar2 + 0x20)) && (fVar7 == (float10)*(float *)(iVar2 + 0x28))
       ) {
      fVar5 = (float10)fVar1;
      iVar4 = FUN_006e6b90();
      if ((*(char *)(iVar2 + 0x2c) == '\a') && (fVar5 == (float10)*(float *)(iVar2 + 0x24))) {
        uVar3 = FUN_006e6b90();
        *(undefined2 *)(param_1 + 0x1d0) = uVar3;
        uVar3 = FUN_006e6b90();
        *(undefined2 *)(param_1 + 0x1d2) = uVar3;
        fVar6 = (float10)(float)((float10)iVar4 * extraout_ST0) + extraout_ST0_00;
        fVar7 = extraout_ST0_00;
        fVar5 = extraout_ST1_00;
      }
      else {
        fVar6 = extraout_ST0 + (float10)(float)((float10)iVar4 * extraout_ST0) + fVar7;
        fVar7 = extraout_ST0;
        fVar5 = extraout_ST1;
      }
      *(float *)(param_1 + 0x1e0) = (float)fVar6;
      fVar1 = *(float *)(param_1 + 0x1e0);
      while (fVar5 < (float10)fVar1) {
        *(float *)(param_1 + 0x1e0) = (float)((float10)*(float *)(param_1 + 0x1e0) - fVar7);
        fVar1 = *(float *)(param_1 + 0x1e0);
      }
    }
    else {
      *(float *)(param_1 + 0x1e0) = fVar1;
    }
    fVar7 = (float10)FUN_005b9d90(&DAT_00810900);
    *(float *)(param_1 + 0x1e4) =
         (float)((float10)*(float *)(iVar2 + 0x1c) + (float10)*(float *)(param_1 + 0x1e0) +
                fVar7 * (float10)*(float *)(iVar2 + 0x20));
    *(undefined4 *)(param_1 + 0x1dc) = 0xc1200000;
    return;
  }
  return;
}

