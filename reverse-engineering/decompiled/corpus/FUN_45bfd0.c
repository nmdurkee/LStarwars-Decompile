/* Ghidra analysis pseudocode, not original source.
 * ev_5f3da693bf096313253939ed49ba5271cfe8862e4a440ae5c9d57980f69a0d69
 * Entry: 0x45bfd0; label: FUN_0045bfd0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0045bfd0(int param_1,int param_2,int param_3)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 extraout_ST0_01;
  float10 extraout_ST0_02;
  float10 extraout_ST0_03;
  float10 fVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  float local_14;
  float local_10;
  float local_c;
  int local_8;
  
  if ((param_3 != 0) && (0 < *(int *)(param_1 + 0x14))) {
    fVar5 = (float10)0;
    local_10 = (float)fVar5;
    local_c = (float)fVar5;
    local_14 = (float)fVar5;
    uVar3 = 0;
    uVar4 = 0;
    switch(*(int *)(param_1 + 0x14)) {
    case 1:
      iVar2 = FUN_006e6b90();
      uVar3 = 0;
      uVar4 = 0;
      local_10 = 1.0 - ((float)(&DAT_029899a0)[iVar2 >> 1 & 0x7fff] + 1.0) * 0.5;
      local_14 = (float)extraout_ST0;
      local_c = (float)extraout_ST0;
      fVar5 = extraout_ST0;
      break;
    case 2:
      local_10 = 1.0;
      iVar2 = FUN_006e6b90();
      uVar4 = DAT_00876db4 & 0xffff;
      uVar3 = 0;
      local_14 = 1.0 - ((float)(&DAT_029899a0)[iVar2 >> 1 & 0x7fff] + 1.0) * 0.5;
      local_c = (float)extraout_ST0_00;
      fVar5 = extraout_ST0_00;
      break;
    case 3:
      local_10 = 1.0;
      uVar3 = 0;
      uVar4 = 0;
      local_14 = 1.0;
      local_c = (float)fVar5;
      break;
    case 4:
      local_10 = 1.0;
      local_14 = 1.0;
      iVar2 = FUN_006e6b90();
      uVar4 = 0;
      uVar3 = -DAT_00876db4 & 0xffff;
      local_c = 1.0 - ((float)(&DAT_029899a0)[iVar2 >> 1 & 0x7fff] + 1.0) * 0.5;
      fVar5 = extraout_ST0_01;
      break;
    case 5:
      local_10 = 1.0;
      uVar3 = 0;
      uVar4 = 0;
      local_14 = 1.0;
      local_c = 1.0;
      break;
    case 6:
    case 7:
      uVar3 = 0;
      local_14 = 1.0;
      uVar4 = 0;
      local_c = 1.0;
      if (_DAT_007f8224 <= *(float *)(param_1 + 0x18)) {
        local_10 = 1.0;
      }
      else {
        iVar2 = FUN_006e6b90();
        local_10 = (float)(&DAT_029899a0)[iVar2 >> 1 & 0x7fff] * 0.25 + 1.0;
        fVar5 = extraout_ST0_02;
      }
      break;
    case 8:
      iVar2 = FUN_006e6b90();
      uVar4 = DAT_00876db4 & 0xffff;
      uVar3 = -DAT_00876db4 & 0xffff;
      local_14 = 1.0 - (1.0 - ((float)(&DAT_029899a0)[iVar2 >> 1 & 0x7fff] + 1.0) * 0.5);
      fVar5 = extraout_ST0_03;
      local_10 = local_14;
      local_c = local_14;
    }
    bVar1 = *(byte *)(param_2 + 0xbe);
    if (bVar1 < 2) {
      local_8 = (int)(longlong)ROUND(local_14 * 255.0);
      uVar6 = *(undefined4 *)(DAT_00926c20 + DAT_00880758 * 4);
    }
    else {
      local_8 = (int)(longlong)ROUND(local_14 * 255.0);
      uVar6 = *(undefined4 *)(DAT_00926c20 + DAT_0088075c * 4);
    }
    FUN_00482f40(uVar6,uVar4,(float)fVar5,local_14 * _DAT_007fa4c0,local_14 * _DAT_007f8218,
                 local_8 << 0x18 | 0xc8ff,0);
    fVar5 = (float10)FUN_005b7d30(_DAT_00925028,0x40800000);
    uVar4 = (int)ROUND(fVar5 * (float10)0.25 * (float10)65536.0) & 0xffff;
    FUN_00552d10(0,0,0x3f800000,local_10,local_10,local_10,
                 (int)ROUND((float)(&DAT_029899a0)[(int)(uVar4 * 2) >> 1 & 0x7fff] * 1820.0) &
                 0xffff,uVar4,0,*(int *)(PTR_DAT_00802c54 + 0x2ac0) + 0xd30,2);
    if ((*(int *)(param_1 + 0x14) != 6) || (1.0 <= *(float *)(param_1 + 0x18))) {
      uVar7 = 0;
      uVar6 = 0;
      local_8 = (int)(longlong)ROUND(local_c * 255.0);
      uVar4 = local_8 << 0x18 | 0xc8ff;
    }
    else {
      uVar7 = 0x3f800000;
      uVar6 = *(undefined4 *)(param_1 + 0x18);
      uVar4 = 0xbf00c8ff;
    }
    FUN_00483190(bVar1,DAT_0093b30c,0,-_DAT_007fa4c0 * local_c,uVar3,local_c * _DAT_007f8218,uVar4,
                 uVar6,uVar7);
    if (0x3c < DAT_0086e4e2) {
      FUN_004b80e0(**(undefined4 **)(param_2 + 0x1c),
                   _DAT_007fc314 + local_14 * (_DAT_007fc310 - _DAT_007fc314),_DAT_0087b93c,1,
                   0x3f800000,0xff,0xbf,0);
    }
  }
  return;
}

