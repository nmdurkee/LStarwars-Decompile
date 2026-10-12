/* Ghidra pseudocode, not original source.
 * ev_586220d7ac6b37fe8b0c159ff03e90627c1db9a143c695a82bf037091d09cd88
 * Entry: 0x45b290; label: FUN_0045b290
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0045b290(int param_1,int param_2,int param_3)

{
  uint uVar1;
  float fVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  undefined2 in_FPUControlWord;
  float10 fVar8;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 extraout_ST0_01;
  float10 extraout_ST1;
  float10 extraout_ST1_00;
  float10 extraout_ST1_01;
  float local_5c;
  float local_58;
  undefined4 uStack_54;
  float local_50;
  float local_4c;
  float local_48;
  uint local_44;
  float local_40;
  float local_3c;
  int local_38;
  float local_34;
  float local_30;
  undefined1 local_2c [8];
  undefined1 local_24 [32];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_5c;
  local_4c = 0.0;
  local_48 = 0.0;
  local_3c = 0.0;
  iVar7 = 0;
  local_50 = 1.0;
  uVar5 = 0;
  uVar6 = 0;
  local_5c = _DAT_007fc314;
  local_38 = param_2;
  local_44 = 0;
  if (param_3 != 0) {
    fVar8 = (float10)0.5;
    switch(*(undefined4 *)(param_1 + 0x14)) {
    case 0:
      local_50 = 0.0;
      break;
    case 1:
      if (_DAT_007f8220 <= *(float *)(param_1 + 0x18)) {
        if (_DAT_007f8220 + _DAT_007f8220 <= *(float *)(param_1 + 0x18)) {
          uVar6 = 0;
          uVar5 = 0;
          local_48 = 1.0;
          local_4c = 1.0;
          local_50 = 1.0;
        }
        else {
          local_48 = 1.0;
          local_50 = 1.0;
          iVar3 = FUN_006e6b90();
          uVar5 = DAT_00876db4 & 0xffff;
          uVar6 = -DAT_00876db4 & 0xffff;
          local_4c = (float)(extraout_ST1_00 -
                            ((float10)(float)(&DAT_029899a0)[iVar3 >> 1 & 0x7fff] + extraout_ST1_00)
                            * extraout_ST0_00);
        }
        local_44 = 0;
      }
      else {
        iVar3 = FUN_006e6b90();
        local_44 = DAT_00876db4 & 0xffff;
        uVar5 = 0;
        uVar6 = 0;
        local_50 = (float)(extraout_ST0 -
                          ((float10)(float)(&DAT_029899a0)[iVar3 >> 1 & 0x7fff] + extraout_ST0) *
                          extraout_ST1);
        local_4c = (float)fVar8;
        local_48 = local_50;
      }
      fVar8 = (float10)FUN_00458490(*(undefined4 *)(param_1 + 0x18),*(undefined4 *)(param_1 + 0x1c))
      ;
      fVar8 = (float10)FUN_004850e0((float)fVar8);
      _DAT_0087a188 = (float)fVar8;
      local_5c = -_DAT_007fa4c0;
      break;
    case 2:
      uVar6 = 0;
      local_44 = 0;
      uVar5 = 0;
      local_5c = -_DAT_007fa4c0;
      local_4c = 1.0;
      local_48 = 1.0;
      break;
    case 3:
      uVar6 = 0;
      local_44 = 0;
      uVar5 = 0;
      local_5c = -_DAT_007fa4c0;
      local_4c = 1.0;
      local_48 = 1.0;
      local_3c = *(float *)(param_1 + 0x18) / *(float *)(param_1 + 0x1c);
      break;
    case 4:
      local_44 = DAT_00876db4 & 0xffff;
      uVar5 = DAT_00876db4 & 0xffff;
      local_50 = 1.0 - *(float *)(param_1 + 0x18);
      uVar6 = -DAT_00876db4 & 0xffff;
      iVar3 = FUN_006e6b90();
      local_4c = (float)(extraout_ST1_01 -
                        ((float10)(float)(&DAT_029899a0)[iVar3 >> 1 & 0x7fff] + extraout_ST1_01) *
                        extraout_ST0_01);
      local_5c = -_DAT_007fa4c0;
      local_48 = local_4c;
    }
    if (0 < *(int *)(param_1 + 0x14)) {
      local_30 = local_5c * local_4c;
      do {
        FUN_0054bb30(*(undefined4 *)(local_38 + 0x84 + iVar7 * 4),local_2c);
        if (*(char *)(local_38 + 0xa4 + iVar7) == '\0') {
          local_5c = local_50 * 0.25;
        }
        else {
          local_5c = 1.0;
        }
        uVar1 = *(uint *)(local_38 + 0x84 + iVar7 * 4);
        if (uVar1 < 10000) {
          if (uVar1 < 1000) {
            iVar3 = (-(uint)(uVar1 < 100) & 0xfffffff8) + 0xbb;
          }
          else {
            iVar3 = 0xc3;
          }
        }
        else {
          iVar3 = 0xd9;
        }
        if (iVar7 == 0) {
          local_40 = -0.75;
        }
        else {
          local_40 = 0.75;
        }
        iVar3 = iVar3 * 0x10 + *(int *)(PTR_DAT_00802c54 + 0x2ac0);
        local_34 = local_40;
        if (*(char *)(iVar3 + 0xe) != '\0') {
          uVar1 = uVar5;
          if (iVar7 == 0) {
            uVar1 = uVar6;
          }
          fVar2 = local_4c * _DAT_007f8218;
          _local_58 = CONCAT44(uStack_54,local_4c * local_40);
          FUN_00552c10(local_4c * local_40,local_30,0x3f800000,fVar2,fVar2,fVar2,0,0,uVar1,iVar3,0,
                       local_5c);
        }
        uVar1 = uVar5;
        if (iVar7 == 0) {
          uVar1 = uVar6;
        }
        fVar2 = local_5c * 255.0;
        local_5c = (float)CONCAT22(local_5c._2_2_,in_FPUControlWord);
        local_58 = (float)(longlong)ROUND(fVar2);
        uVar4 = (int)local_58 << 0x18;
        uStack_54 = (undefined4)((ulonglong)(longlong)ROUND(fVar2) >> 0x20);
        _local_58 = CONCAT44(uStack_54,local_4c * local_40);
        FUN_00482f40(local_2c,uVar1,local_4c * local_40,local_30,local_4c * _DAT_007f8218,
                     uVar4 | 0xbfff,(-(iVar7 != 0) & 6U) + 2);
        iVar7 = iVar7 + 1;
      } while (iVar7 < 2);
      if (*(int *)(param_1 + 0x14) == 3) {
        FUN_0054bb30(**(undefined4 **)(local_38 + 0x1c),local_24);
        local_5c = (float)CONCAT22(local_5c._2_2_,in_FPUControlWord);
        fVar2 = _DAT_007fc364 * local_4c * _DAT_007f8218 * local_48 * 1.5;
        local_40 = (local_3c * 0.5 + 1.0) * fVar2;
        uStack_54 = (undefined4)((ulonglong)_local_58 >> 0x20);
        fVar2 = (1.0 - local_3c * 0.5) * fVar2;
        local_58 = (float)(int)ROUND((1.0 - local_3c) * 128.0);
        uVar5 = (uint)local_58 & 0xff;
        local_3c = fVar2;
        FUN_0050c780(local_24,0,0,0x3f800000,fVar2,fVar2,fVar2,0,0xff,0xbf,0,uVar5);
        FUN_0050c780(local_24,0,0,0x3f800000,local_40,local_40,local_40,0,0xff,0xbf,0,uVar5);
        local_3c = _DAT_007f8218 * local_48 * 1.5;
        iVar7 = FUN_006e6b90();
        local_40 = local_3c * _DAT_007fc368 * (float)(&DAT_029899a0)[iVar7 >> 1 & 0x7fff];
        iVar7 = *(int *)(PTR_DAT_00802c54 + 0x2ac0) + DAT_007fc374 * 0x10;
        if (*(char *)(iVar7 + 0xe) != '\0') {
          local_58 = -(_DAT_00921d00 * 0.5) - _DAT_007fc36c * local_3c;
          FUN_00552c10(local_58,0,0x3f800000,local_40,local_40,local_40,0,0,0,iVar7,0,0x3f800000);
        }
        iVar7 = *(int *)(PTR_DAT_00802c54 + 0x2ac0) + DAT_007fc378 * 0x10;
        if (*(char *)(iVar7 + 0xe) != '\0') {
          fVar2 = _DAT_00921d00 * 0.5 + local_3c * _DAT_007fc36c;
          _local_58 = CONCAT44(uStack_54,fVar2);
          FUN_00552c10(fVar2,0,0x3f800000,local_40,local_40,local_40,0,0,0,iVar7,0,0x3f800000);
        }
      }
      else {
        fVar2 = _DAT_007f8218 * local_48 * 1.5;
        _local_58 = CONCAT44(uStack_54,fVar2);
        FUN_004b80e0(**(undefined4 **)(local_38 + 0x1c),0,fVar2,1,local_50,0xff,0xbf,0);
      }
      if (0.0 <= local_50) {
        if (1.0 < local_50) {
          local_50 = 1.0;
        }
      }
      else {
        local_50 = 0.0;
      }
      local_5c = (float)CONCAT22(local_5c._2_2_,in_FPUControlWord);
      local_58 = (float)(longlong)ROUND(local_50 * 255.0);
      uVar5 = (int)local_58 << 0x18;
      uStack_54 = (undefined4)((ulonglong)(longlong)ROUND(local_50 * 255.0) >> 0x20);
      _local_58 = CONCAT44(uStack_54,local_48 * _DAT_007fa4c0);
      FUN_00482f40(*(undefined4 *)(DAT_00926c20 + DAT_008808b4 * 4),local_44,0,
                   local_48 * _DAT_007fa4c0,local_48 * _DAT_007f8218,uVar5 | 0xffffff,0);
      __security_check_cookie(local_4 ^ (uint)&local_5c);
      return;
    }
  }
  __security_check_cookie(local_4 ^ (uint)&local_5c);
  return;
}

