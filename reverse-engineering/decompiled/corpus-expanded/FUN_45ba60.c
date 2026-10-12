/* Ghidra pseudocode, not original source.
 * ev_586220d7ac6b37fe8b0c159ff03e90627c1db9a143c695a82bf037091d09cd88
 * Entry: 0x45ba60; label: FUN_0045ba60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0045ba60(int param_1,int param_2,float param_3)

{
  float fVar1;
  float fVar2;
  short sVar3;
  undefined1 *puVar4;
  bool bVar5;
  undefined2 in_FPUControlWord;
  float local_118;
  undefined4 local_114;
  undefined4 local_110;
  undefined4 local_10c;
  undefined4 local_108;
  undefined1 local_104 [256];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_118;
  local_118 = *(float *)(param_1 + 0x18);
  fVar1 = param_3 + *(float *)(param_1 + 0x18);
  *(float *)(param_1 + 0x18) = fVar1;
  local_114._2_2_ = (undefined2)((uint)fVar1 >> 0x10);
  fVar2 = fVar1;
  local_114 = fVar1;
  switch(*(undefined4 *)(param_1 + 0x14)) {
  case 0:
    DAT_00876db4._0_2_ = 0;
    _DAT_0087a1a8 = 0;
    *(undefined4 *)(param_1 + 0x18) = 0;
    *(undefined4 *)(param_1 + 0x14) = 1;
    *(undefined4 *)(param_1 + 0x1c) = _DAT_007f8220;
    __security_check_cookie(local_4 ^ (uint)&local_118);
    return;
  case 1:
    DAT_00876db4._0_2_ = 0;
    if (*(float *)(param_1 + 0x1c) < fVar1 != (*(float *)(param_1 + 0x1c) == fVar1)) {
      *(undefined4 *)(param_1 + 0x18) = 0;
      *(undefined4 *)(param_1 + 0x14) = 2;
      *(undefined4 *)(param_1 + 0x1c) = _DAT_007f8220;
      __security_check_cookie(local_4 ^ (uint)&local_118);
      return;
    }
    break;
  case 2:
    local_114 = (float)CONCAT22(local_114._2_2_,in_FPUControlWord);
    local_118 = (float)(int)ROUND(param_3 * 65536.0 * 4.0);
    DAT_00876db4._0_2_ = (short)DAT_00876db4 + local_118._0_2_;
    fVar2 = local_114;
    if (*(float *)(param_1 + 0x1c) < fVar1 != (*(float *)(param_1 + 0x1c) == fVar1)) {
      FUN_00681f40("TrueJedi_100pc",0);
      FUN_004836f0(0xffffffff,0x3f19999a,0,0);
      *(undefined4 *)(param_1 + 0x18) = 0;
      *(undefined4 *)(param_1 + 0x1c) = _DAT_007f8224;
      *(undefined4 *)(param_1 + 0x14) = 3;
      __security_check_cookie(local_4 ^ (uint)&local_118);
      return;
    }
    break;
  case 3:
    DAT_00876db4._0_2_ = 0;
    if (*(float *)(param_1 + 0x1c) < fVar1 != (*(float *)(param_1 + 0x1c) == fVar1)) {
      *(undefined4 *)(param_1 + 0x18) = 0;
      *(undefined4 *)(param_1 + 0x14) = 4;
      *(undefined4 *)(param_1 + 0x1c) = _DAT_007f8220;
      __security_check_cookie(local_4 ^ (uint)&local_118);
      return;
    }
    break;
  case 4:
    local_114 = (float)CONCAT22(local_114._2_2_,in_FPUControlWord);
    local_118 = (float)(int)ROUND(param_3 * 65536.0 * 4.0);
    DAT_00876db4._0_2_ = (short)DAT_00876db4 + local_118._0_2_;
    fVar2 = local_114;
    if (*(float *)(param_1 + 0x1c) < fVar1 != (*(float *)(param_1 + 0x1c) == fVar1)) {
      *(undefined4 *)(param_1 + 0x18) = 0;
      *(undefined4 *)(param_1 + 0x14) = 5;
      *(undefined4 *)(param_1 + 0x1c) = _DAT_007f8224;
      __security_check_cookie(local_4 ^ (uint)&local_118);
      return;
    }
    break;
  case 5:
    DAT_00876db4._0_2_ = 0;
    if (*(float *)(param_1 + 0x1c) < fVar1 != (*(float *)(param_1 + 0x1c) == fVar1)) {
      *(undefined4 *)(param_1 + 0x18) = 0;
      *(undefined4 *)(param_1 + 0x14) = 6;
      *(undefined4 *)(param_1 + 0x1c) = 0x40200000;
      __security_check_cookie(local_4 ^ (uint)&local_118);
      return;
    }
    break;
  case 6:
    DAT_00876db4._0_2_ = 0;
    if (*(float *)(param_1 + 0x1c) < fVar1 != (*(float *)(param_1 + 0x1c) == fVar1)) {
      bVar5 = DAT_0086e4e2 <= *(byte *)(param_2 + 0xbe);
      *(undefined4 *)(param_1 + 0x18) = 0;
      if (bVar5) {
        *(undefined4 *)(param_1 + 0x1c) = _DAT_007f8224;
        *(undefined4 *)(param_1 + 0x14) = 7;
        __security_check_cookie(local_4 ^ (uint)&local_118);
        return;
      }
      *(undefined4 *)(param_1 + 0x1c) = 0x40200000;
      *(undefined4 *)(param_1 + 0x14) = 6;
      __security_check_cookie(local_4 ^ (uint)&local_118);
      return;
    }
    if (local_118 == 0.0) {
      FUN_00681f40("TrueJedi_100pc",0);
      FUN_004836f0(0xffffffff,0x3f19999a,0,0);
      *(char *)(param_2 + 0xbe) = *(char *)(param_2 + 0xbe) + '\x01';
      local_110 = 0;
      local_10c = 0x3d19999a;
      local_108 = 0x3f800000;
      sVar3 = *(short *)(param_2 + 300 + (uint)*(byte *)(param_2 + 0xbe) * 2);
      puVar4 = *(undefined1 **)(DAT_00926c20 + sVar3 * 4);
      if (sVar3 == DAT_008807f8) {
        FUN_004f1f10(local_104,puVar4);
        FUN_004f1e80(local_104,&DAT_007587cc);
        sVar3 = DAT_00880888;
        if ((*(byte *)(param_2 + 0xb0) & 0x40) == 0) {
          sVar3 = DAT_00880884;
        }
        FUN_004f1e80(local_104,*(undefined4 *)(DAT_00926c20 + sVar3 * 4));
        puVar4 = local_104;
      }
      FUN_00560fa0(puVar4,&local_110,0x3f333333,&local_110,0x3f333333,0xff,0,0x7f,0x4020,0x40000000)
      ;
      fVar2 = local_114;
      if (0x3c < *(byte *)(param_2 + 0xbe)) {
        FUN_005533f0(*(undefined4 *)(param_2 + 0x1c),100000,0,0);
        _DAT_0087b93c = 0x3fc00000;
        FUN_00681f40("Shop_BuyCheat",0);
        FUN_0054bb30(100000,local_104);
        FUN_00561b20(local_104,0,-_DAT_007fc310,0x3f000000,0x3fa00000,0,0);
        __security_check_cookie(local_4 ^ (uint)&local_118);
        return;
      }
    }
    break;
  case 7:
    DAT_00876db4._0_2_ = 0;
    if (*(float *)(param_1 + 0x1c) < fVar1 != (*(float *)(param_1 + 0x1c) == fVar1)) {
      *(undefined4 *)(param_1 + 0x14) = 8;
      *(undefined4 *)(param_1 + 0x18) = 0;
      *(undefined4 *)(param_1 + 0x1c) = _DAT_007f8220;
    }
    goto LAB_0045bf23;
  case 8:
LAB_0045bf23:
    local_114 = (float)CONCAT22(local_114._2_2_,in_FPUControlWord);
    local_118 = (float)(int)ROUND(param_3 * 65536.0 * 4.0);
    DAT_00876db4._0_2_ = (short)DAT_00876db4 + local_118._0_2_;
    fVar2 = local_114;
    if (*(float *)(param_1 + 0x1c) < *(float *)(param_1 + 0x18) !=
        (*(float *)(param_1 + 0x1c) == *(float *)(param_1 + 0x18))) {
      FUN_004838f0(param_2);
      __security_check_cookie(local_4 ^ (uint)&local_118);
      return;
    }
  }
  local_114 = fVar2;
  __security_check_cookie(local_4 ^ (uint)&local_118);
  return;
}

