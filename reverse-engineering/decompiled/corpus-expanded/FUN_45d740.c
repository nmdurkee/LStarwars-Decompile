/* Ghidra pseudocode, not original source.
 * ev_e37398024b26761df01c7e6d1f7f3789c673fd129cb2ff02e0ba3ea718b801df
 * Entry: 0x45d740; label: FUN_0045d740
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0045d740(float param_1,float param_2,int param_3)

{
  float fVar1;
  short sVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  float10 extraout_ST0;
  float10 fVar12;
  float10 extraout_ST1;
  float10 fVar13;
  undefined8 uVar14;
  float local_11c;
  float local_118;
  float local_114;
  float local_110;
  float local_10c;
  float local_108;
  undefined1 local_104 [256];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_11c;
  local_114 = param_1;
  local_110 = param_2;
  if (param_3 == 0) goto LAB_0045defe;
  fVar13 = (float10)1;
  fVar12 = (float10)0;
  if (0 < *(int *)((int)param_1 + 0x14)) {
    if (_DAT_007f8220 <= *(float *)((int)param_1 + 0x18)) {
      if (_DAT_007f8224 + _DAT_007f8220 <= *(float *)((int)param_1 + 0x18)) {
        if (_DAT_007f8220 + _DAT_007f8220 + _DAT_007f8224 <= *(float *)((int)param_1 + 0x18)) {
          if (*(float *)((int)param_1 + 0x1c) - _DAT_007f8220 < *(float *)((int)param_1 + 0x18)) {
            uVar11 = -DAT_00876db4 & 0xffff;
            local_118 = (*(float *)((int)param_1 + 0x1c) - *(float *)((int)param_1 + 0x18)) /
                        _DAT_007f8220;
            local_108 = local_118;
            goto LAB_0045d7be;
          }
          uVar11 = 0;
          uVar10 = 0;
          local_118 = (float)fVar13;
          local_108 = (float)fVar13;
        }
        else {
          uVar10 = 0;
          local_108 = (float)fVar13;
          uVar11 = -DAT_00876db4 & 0xffff;
          local_118 = (*(float *)((int)param_1 + 0x18) - (_DAT_007f8224 + _DAT_007f8220)) /
                      _DAT_007f8220;
        }
      }
      else {
        uVar10 = 0;
        uVar11 = 0;
        local_108 = (float)fVar13;
        local_118 = (float)fVar12;
      }
    }
    else {
      local_108 = *(float *)((int)param_1 + 0x18) / _DAT_007f8220;
      uVar11 = 0;
      local_118 = (float)fVar12;
LAB_0045d7be:
      uVar10 = DAT_00876db4 & 0xffff;
      local_11c = local_118;
      local_10c = local_108;
      if ((float10)local_108 <= fVar12) goto LAB_0045dbb1;
    }
    local_11c = local_118;
    local_118 = _DAT_007f8218 * local_118;
    local_10c = local_108;
    local_108 = _DAT_007f8218 * local_108;
    iVar5 = FUN_006e6b90();
    iVar6 = FUN_006e6b90();
    iVar7 = *(int *)((int)local_114 + 0xc);
    if (iVar7 == 0xd) {
      local_11c = local_108 * _DAT_007fa4c0;
      FUN_00482f40(*(undefined4 *)(DAT_00926c20 + DAT_00880708 * 4),uVar10,(float)extraout_ST0,
                   local_11c,local_108,
                   ((_DAT_0087a774 & 0xff | iVar5 << 8) << 8 | _DAT_007fa4cc & 0xff) << 8 |
                   _DAT_007fa4c8 & 0xff,0);
      uVar10 = ((_DAT_0087a774 & 0xff | iVar6 << 8) << 8 | _DAT_007fa4cc & 0xff) << 8 |
               _DAT_007fa4c8 & 0xff;
      local_11c = -_DAT_007fa4c0 * local_118;
      sVar2 = DAT_0088070c;
    }
    else {
      if (iVar7 != 8) {
        if (iVar7 == 0x17) {
          uVar10 = _DAT_007fa4c8;
          uVar8 = _DAT_007fa4cc;
          uVar9 = _DAT_0087a774;
          if (*(char *)((int)local_110 + 0xa6) == '\x02') {
            uVar10 = 0xff;
            uVar8 = 0xff;
            uVar9 = 0xff;
          }
          local_11c = local_118 * _DAT_007fa4c0;
          FUN_00482f40(*(undefined4 *)(DAT_00926c20 + DAT_00880844 * 4),uVar11,(float)extraout_ST0,
                       local_11c,local_118,
                       ((uVar9 & 0xff | iVar6 << 8) << 8 | uVar8 & 0xff) << 8 | uVar10 & 0xff,0);
          fVar13 = (float10)1;
          fVar12 = (float10)0;
        }
        else {
          fVar12 = extraout_ST0;
          fVar13 = extraout_ST1;
          if (iVar7 == 0x1a) {
            uVar10 = _DAT_007fa4c8;
            uVar8 = _DAT_007fa4cc;
            uVar9 = _DAT_0087a774;
            sVar2 = DAT_008806d4;
            if (*(char *)((int)local_110 + 0xa7) == '\x02') {
              uVar10 = 0xff;
              uVar8 = 0xff;
              uVar9 = 0xff;
              sVar2 = DAT_008806c4;
            }
            FUN_00482f40(*(undefined4 *)(DAT_00926c20 + sVar2 * 4),uVar11,(float)extraout_ST0,
                         (float)extraout_ST0,_DAT_00876dd0,
                         ((uVar9 & 0xff | iVar6 << 8) << 8 | uVar8 & 0xff) << 8 | uVar10 & 0xff,0);
            fVar13 = (float10)1;
            fVar12 = (float10)0;
          }
        }
        goto LAB_0045dbb1;
      }
      local_11c = local_108 * _DAT_007fa4c0;
      FUN_00482f40(*(undefined4 *)(DAT_00926c20 + DAT_00880844 * 4),uVar10,(float)extraout_ST0,
                   local_11c,local_108,
                   ((_DAT_0087a774 & 0xff | iVar5 << 8) << 8 | _DAT_007fa4cc & 0xff) << 8 |
                   _DAT_007fa4c8 & 0xff,0);
      uVar10 = ((_DAT_0087a774 & 0xff | iVar6 << 8) << 8 | _DAT_007fa4cc & 0xff) << 8 |
               _DAT_007fa4c8 & 0xff;
      local_11c = -_DAT_007fa4c0 * local_118;
      sVar2 = DAT_00880854;
    }
    FUN_00482f40(*(undefined4 *)(DAT_00926c20 + sVar2 * 4),uVar11,0,local_11c,local_118,uVar10,0);
    fVar13 = (float10)1;
    fVar12 = (float10)0;
  }
LAB_0045dbb1:
  fVar4 = local_110;
  fVar3 = local_114;
  iVar7 = *(int *)((int)local_114 + 0xc);
  if (((iVar7 == 0x17) || (iVar7 == 0x1a)) &&
     (((iVar7 == 0x1a && (*(char *)((int)local_110 + 0xa7) == '\x02')) ||
      ((iVar7 == 0x17 && (*(char *)((int)local_110 + 0xa6) == '\x02')))))) {
    if (0.75 <= *(float *)((int)local_114 + 0x18)) {
      local_118 = *(float *)((int)local_114 + 0x1c) - 0.75;
      if (local_118 <= *(float *)((int)local_114 + 0x18)) {
        local_110 = 1.0 - (*(float *)((int)local_114 + 0x18) - local_118) / 0.75;
        local_114 = (float)fVar13;
      }
      else {
        local_110 = (float)fVar13;
        local_114 = (*(float *)((int)local_114 + 0x18) - 0.75) / (local_118 - 0.75);
      }
    }
    else {
      local_110 = *(float *)((int)local_114 + 0x18) / 0.7;
      local_114 = (float)fVar12;
    }
    local_11c = local_110;
    fVar1 = *(float *)((int)fVar3 + 0x18);
    if (!NAN(fVar1) && 0.75 < fVar1 != (fVar1 == 0.75)) {
      local_11c = (float)fVar13;
    }
    local_10c = *(float *)((int)fVar4 + 0x74);
    local_108 = (float)(*(int *)((int)fVar4 + 0x78) - (int)local_10c);
    uVar14 = FUN_006e6bc6(0);
    FUN_005533f0(&local_10c,uVar14);
    iVar7 = FUN_006e6b90(_DAT_0087b93c,1,0x3f800000,0xff,0xbf,0);
    local_11c = (_DAT_007fc310 - _DAT_007fc314) * (float)(&DAT_029899a0)[iVar7 >> 1 & 0x7fff] +
                _DAT_007fc314;
    FUN_004b80e0(local_10c,local_11c);
    if (*(int *)((int)fVar3 + 0xc) == 0x1a) {
      local_118 = (float)*(ushort *)(*(int *)((int)fVar4 + 0x20) + 0x10) -
                  *(float *)((int)fVar4 + 100);
      if (local_118 < 0.0) {
        local_118 = 0.0;
      }
      local_11c = (1.0 - local_114) * local_118;
      FUN_0054bbc0(local_11c,0,1,1,local_104);
      iVar7 = FUN_006e6b90(0x3f800000,0x3f19999a,0x3f19999a,0x3f19999a,0,0xff,0xbf,0);
      local_11c = -((_DAT_007fc310 - _DAT_007fc314) * (float)(&DAT_029899a0)[iVar7 >> 1 & 0x7fff] +
                   _DAT_007fc314);
      FUN_00511500(local_104,0,local_11c);
    }
    if (*(int *)((int)fVar3 + 0xc) == 0x17) {
      local_11c = (float)(uint)*(ushort *)
                                (*(short *)((int)fVar4 + 0xa0) * 0x9c + 0x84 + DAT_00951354);
      local_118 = (float)(int)local_11c - *(float *)((int)fVar4 + 100);
      if (local_118 < 0.0) {
        local_118 = 0.0;
      }
      local_114 = (1.0 - local_114) * local_118;
      FUN_0054bbc0(local_114,0,1,1,local_104);
      iVar7 = FUN_006e6b90(0x3f800000,0x3f19999a,0x3f19999a,0x3f19999a,0,0xff,0xbf,0);
      local_114 = -((_DAT_007fc310 - _DAT_007fc314) * (float)(&DAT_029899a0)[iVar7 >> 1 & 0x7fff] +
                   _DAT_007fc314);
      FUN_00511500(local_104,0,local_114);
      __security_check_cookie(local_4 ^ (uint)&local_11c);
      return;
    }
  }
LAB_0045defe:
  __security_check_cookie(local_4 ^ (uint)&local_11c);
  return;
}

