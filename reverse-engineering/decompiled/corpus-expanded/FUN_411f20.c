/* Ghidra pseudocode, not original source.
 * ev_ba3680c91cc7668ea4367646649a520903a061e5f40eaeec700e4023a7d0b71b
 * Entry: 0x411f20; label: FUN_00411f20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00411f20(int param_1)

{
  float fVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  float local_40;
  float local_3c;
  float local_38;
  undefined4 local_34;
  float local_30;
  float local_2c;
  float local_28;
  undefined4 local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  undefined4 local_4;
  
  if (DAT_00855e68 == 0) {
    iVar3 = param_1 + 0x10;
    iVar5 = 2;
    do {
      iVar7 = iVar5;
      if (*(short *)(iVar3 + 0x32) != 0) {
        FUN_005b30a0(iVar3 + 0x20,iVar3,PTR_DAT_008021b4 + 0xb8);
      }
      iVar3 = iVar3 + 0x50;
      iVar5 = iVar7 + -1;
    } while (iVar5 != 0);
    iVar5 = param_1 + 0xe0;
    iVar3 = iVar7 + 7;
    do {
      iVar7 = iVar3;
      if (*(int *)(iVar5 + 0x628) != 0) {
        iVar6 = 5;
        iVar3 = iVar5;
        do {
          if (*(int *)(iVar3 + 0x110) != 0) {
            FUN_00411470(iVar3);
          }
          iVar3 = iVar3 + 0x130;
          iVar6 = iVar6 + -1;
        } while (iVar6 != 0);
      }
      iVar5 = iVar5 + 0x680;
      iVar3 = iVar7 + -1;
    } while (iVar3 != 0);
    iVar7 = iVar7 + 0x5f;
    param_1 = param_1 + 0x564d0;
    do {
      if (*(int *)(param_1 + 0x110) != 0) {
        FUN_00411470(param_1);
      }
      param_1 = param_1 + 0x130;
      iVar7 = iVar7 + -1;
    } while (iVar7 != 0);
    FUN_0040ee00();
  }
  uVar2 = 0;
  piVar4 = &DAT_007f1628;
  do {
    iVar3 = (&DAT_0093d7f0)[(int)uVar2 >> 1];
    if (iVar3 != 0) {
      if ((*(short *)(iVar3 + 0x1064) == DAT_007f19e4) ||
         (*(short *)(iVar3 + 0x1064) == DAT_007f19e8)) {
        if (*piVar4 == -1) {
          FUN_00684ee0(piVar4,*(undefined4 *)
                               (*(int *)(*(int *)(PTR_DAT_00802c54 + 0x134) + 8) + 0x3ac),0,0,0);
        }
        else {
          local_40 = *(float *)(iVar3 + 0xb8);
          local_3c = *(float *)(iVar3 + 0xbc);
          local_38 = *(float *)(iVar3 + 0xc0);
          local_34 = *(undefined4 *)(iVar3 + 0xc4);
          local_30 = *(float *)(iVar3 + 0xd8);
          local_2c = *(float *)(iVar3 + 0xdc);
          local_28 = *(float *)(iVar3 + 0xe0);
          local_24 = *(undefined4 *)(iVar3 + 0xe4);
          local_20 = -*(float *)(iVar3 + 200);
          local_1c = -*(float *)(iVar3 + 0xcc);
          local_18 = -*(float *)(iVar3 + 0xd0);
          local_14 = -*(float *)(iVar3 + 0xd4);
          local_4 = *(undefined4 *)(iVar3 + 0xf4);
          if ((uVar2 & 1) == 0) {
            local_10 = _DAT_007f1640 * local_30 +
                       _DAT_007f1638 * local_40 + _DAT_007f163c * local_20;
            local_c = _DAT_007f1640 * local_2c + _DAT_007f1638 * local_3c + _DAT_007f163c * local_1c
            ;
            fVar1 = _DAT_007f1638 * local_38 + local_18 * _DAT_007f163c;
          }
          else {
            local_10 = _DAT_007f1640 * local_30 +
                       (_DAT_007f163c * local_20 - _DAT_007f1638 * local_40);
            local_c = _DAT_007f1640 * local_2c +
                      (_DAT_007f163c * local_1c - _DAT_007f1638 * local_3c);
            fVar1 = local_18 * _DAT_007f163c - _DAT_007f1638 * local_38;
          }
          local_c = local_c + *(float *)(iVar3 + 0xec);
          local_10 = *(float *)(iVar3 + 0xe8) + local_10;
          local_8 = _DAT_007f1640 * local_28 + fVar1 + *(float *)(iVar3 + 0xf0);
          FUN_00655a40(*piVar4,&local_40);
        }
      }
      else if (*piVar4 != -1) {
        FUN_00684400(piVar4);
      }
    }
    piVar4 = piVar4 + 1;
    uVar2 = uVar2 + 1;
  } while ((int)piVar4 < 0x7f1638);
  return;
}

