/* Ghidra pseudocode, not original source.
 * ev_fbc0fd73cf89a7f733f4465e4ab1049333b8e7c593c45a6546f4f82b49062809
 * Entry: 0x5ec760; label: FUN_005ec760
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Removing unreachable block (ram,0x005ec907) */
/* WARNING: Removing unreachable block (ram,0x005ec936) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005ec760(undefined4 param_1,float param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,int param_6)

{
  float fVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 *puVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  float fVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  bool bVar14;
  ushort in_FPUControlWord;
  float10 fVar15;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 extraout_ST0_01;
  float10 fVar16;
  float10 extraout_ST0_02;
  float10 fVar17;
  float10 extraout_ST0_03;
  float10 fVar18;
  float10 fVar19;
  float10 fVar20;
  float10 extraout_ST0_04;
  float10 fVar21;
  float10 extraout_ST1;
  float10 extraout_ST1_00;
  float10 extraout_ST1_01;
  float10 extraout_ST1_02;
  longlong lVar22;
  undefined4 local_160;
  float local_15c;
  float local_158;
  undefined8 local_154;
  undefined1 *local_14c;
  int local_148;
  double local_144;
  undefined2 local_13c;
  int local_13a;
  undefined2 local_136;
  undefined2 local_134;
  uint local_132;
  undefined4 local_12c;
  int local_128;
  int local_124;
  undefined2 local_120;
  undefined2 local_11e;
  undefined4 local_11c;
  int local_118;
  undefined4 local_114;
  undefined4 local_110;
  undefined4 local_10c;
  undefined4 local_108;
  char local_104 [256];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_160;
  local_14c = (undefined1 *)0x0;
  fVar15 = (float10)FUN_005b7d30(param_2,0x3f000000);
  param_2 = param_2 - (float)fVar15;
  if (0.25 < (float)fVar15) {
    param_2 = param_2 + 0.5;
  }
  if (0.5 <= param_2) {
    if (4.0 < param_2) {
      param_2 = 4.0;
    }
  }
  else {
    param_2 = 0.5;
  }
  local_15c = param_2 / 0.75;
  iVar2 = FUN_006e6b90();
  local_15c = (float)iVar2;
  fVar15 = (float10)iVar2;
  if (fVar15 < extraout_ST0) {
    fVar15 = fVar15 + (float10)1.0;
  }
  _DAT_0097ba8c = (float)fVar15;
  _DAT_0097ba88 = _DAT_0097ba8c;
  if (DAT_0080b6ec == -1) {
    DAT_0097392c = 1;
    uVar3 = FUN_006e6b90(param_4,param_3,param_5);
    FUN_005ff040(&DAT_0097ba80,uVar3);
    if (param_6 < 0) {
      _sprintf(local_104,"%s.bmp",param_1);
      iVar2 = 0;
      lVar22 = FUN_004fa690(local_104);
      while (0 < lVar22) {
        _sprintf(local_104,"%s%03d.bmp",param_1,iVar2);
        iVar2 = iVar2 + 1;
        lVar22 = FUN_004fa690(local_104);
      }
    }
    else {
      _sprintf(local_104,"%s%d.bmp",param_1,param_6);
    }
    local_13a = DAT_00973904 * DAT_00973900 * 0xc + 0x36;
    local_13c = 0x4d42;
    local_136 = 0;
    local_134 = 0;
    local_132 = 0x36;
    local_12c = 0x28;
    local_154._0_4_ = (int)(longlong)ROUND(param_2 * (float)DAT_00973900);
    iVar2 = (int)local_154;
    local_128 = (int)local_154;
    local_120 = 1;
    local_11e = 0x18;
    local_11c = 0;
    local_114 = 1;
    local_110 = 1;
    local_10c = 0;
    local_108 = 0;
    local_160 = (float)CONCAT22(local_160._2_2_,in_FPUControlWord);
    local_15c = (float)(in_FPUControlWord | 0xc00);
    local_154 = (ulonglong)ROUND(param_2 * (float)DAT_00973904);
    local_124 = (int)local_154;
    local_118 = (int)local_154 * iVar2 * 3;
    DAT_0097ba7c = FUN_004fa5f0(local_104,1);
    if (DAT_0097ba7c == 0) {
      FUN_005ff050(&DAT_0097ba80);
      _DAT_0097ba78 = 0.0;
      _DAT_0097ba74 = 0.0;
      DAT_0080b6ec = -1;
      _DAT_0097ba8c = 0.0;
      _DAT_0097ba88 = 0.0;
      FUN_005db310();
    }
    else {
      FUN_004f03d0(DAT_0097ba7c,&local_13c,0xe);
      FUN_004f03d0(DAT_0097ba7c,&local_12c,0x28);
      FUN_004f6de0(DAT_0097ba7c,local_118 + -1,0,1);
      FUN_004f03d0(DAT_0097ba7c,&local_148,1);
      _DAT_0097ba74 = 0.0;
      _DAT_0097ba78 = 0.0;
      local_160 = (float)DAT_0080e698;
      DAT_0097ba70 = local_132;
      DAT_0080b6ec = 0;
      DAT_0097ba6c = 3;
      DAT_0097ba68 = 0;
      local_158 = (float)DAT_0080e694;
      fVar1 = local_160 * 0.0 * 0.75;
      fVar10 = local_158 * 0.0 * 0.75;
      local_15c = (local_158 * -0.125 + fVar10) / param_2;
      FUN_005ff660(local_15c,(local_160 * -0.125 + fVar1) / param_2,
                   (local_158 + fVar10 + local_158 * -0.125) / param_2,
                   (local_160 + fVar1 + local_160 * -0.125) / param_2,0,0,local_158,local_160);
    }
  }
  else if (DAT_0097ba6c == 0) {
    FUN_005ff060(&local_14c);
    if (local_14c == (undefined1 *)0x0) {
      FUN_005ff050(&DAT_0097ba80);
      DAT_0080b6ec = -1;
      FUN_004f99e0(DAT_0097ba7c);
      _DAT_0097ba78 = 0.0;
      _DAT_0097ba74 = 0.0;
      _DAT_0097ba8c = 0.0;
      _DAT_0097ba88 = 0.0;
      FUN_005db310();
    }
    else {
      iVar2 = DAT_00973900;
      if ((((DAT_0097ba83 != -1) || (DAT_0097ba80 != '\0')) || (DAT_0097ba81 != '\x01')) ||
         (DAT_0097ba82 != '\x02')) {
        local_148 = 0;
        iVar9 = (DAT_0097ba83 != -1) + 3;
        if (0 < DAT_00973904) {
          iVar8 = iVar9 * DAT_00973900;
          puVar4 = local_14c;
          do {
            iVar11 = 0;
            if (0 < iVar8) {
              do {
                local_160 = *(float *)(local_14c + (uint)DAT_0097ba84 * iVar9 * local_148 + iVar11);
                *puVar4 = *(undefined1 *)((int)&local_160 + (int)DAT_0097ba80);
                puVar4[1] = *(undefined1 *)((int)&local_160 + (int)DAT_0097ba81);
                puVar4[2] = *(undefined1 *)((int)&local_160 + (int)DAT_0097ba82);
                iVar8 = iVar9 * DAT_00973900;
                iVar11 = iVar11 + iVar9;
                puVar4 = puVar4 + 3;
                iVar2 = DAT_00973900;
              } while (iVar11 < iVar8);
            }
            local_148 = local_148 + 1;
          } while (local_148 < DAT_00973904);
        }
      }
      local_15c = (float)DAT_00973900;
      local_15c = (float)FUN_006e6b90();
      local_158 = (float)DAT_00973904;
      local_144 = (double)((float10)DAT_00973904 * extraout_ST0_00);
      fVar20 = extraout_ST0_00;
      local_158 = (float)FUN_006e6b90();
      fVar15 = (float10)1;
      if ((float10)_DAT_0097ba74 == (float10)_DAT_0097ba88 - fVar15) {
        fVar16 = (float10)param_2;
        fVar18 = extraout_ST0_01;
        fVar20 = extraout_ST1;
        local_15c = (float)FUN_006e6b90();
        fVar15 = extraout_ST0_02;
        fVar19 = extraout_ST1_00;
      }
      else {
        fVar19 = (float10)param_2;
        fVar16 = extraout_ST0_01;
        fVar18 = extraout_ST1;
      }
      fVar15 = (float10)_DAT_0097ba8c - fVar15;
      fVar17 = (float10)_DAT_0097ba78;
      fVar21 = fVar19;
      if (fVar17 == fVar15) {
        local_158 = (float)FUN_006e6b90();
        fVar17 = (float10)_DAT_0097ba78;
        fVar15 = extraout_ST0_03;
        fVar21 = extraout_ST1_01;
        fVar16 = fVar19;
        fVar20 = fVar18;
      }
      local_160._2_2_ = (undefined2)((uint)(DAT_0097ba68 * 3) >> 0x10);
      local_154._0_4_ =
           (int)(longlong)
                ROUND((((float10)(DAT_0097ba68 * 3) * fVar20) / (float10)DAT_0080e694) * fVar21);
      iVar9 = (int)local_154;
      local_154._0_4_ =
           (int)(longlong)ROUND((float10)DAT_0097ba84 * (float10)-3.0 * (float10)0.125 * fVar16);
      iVar9 = iVar9 - (int)local_154;
      local_154 = (ulonglong)ROUND(fVar20 * (float10)-0.125 * (float10)3.0);
      puVar4 = local_14c + (iVar9 - (int)local_154);
      if (fVar17 == fVar15) {
        local_154._4_4_ = (undefined4)(local_154 >> 0x20);
        local_154 = CONCAT44(local_154._4_4_,(uint)in_FPUControlWord) | 0xc00;
        local_144 = (double)(longlong)
                            ROUND(((float10)local_144 - (float10)(int)local_158) * fVar20 *
                                  (float10)3.0);
        puVar4 = puVar4 + local_144._0_4_;
      }
      local_160 = (float)CONCAT22(local_160._2_2_,in_FPUControlWord);
      uVar5 = FUN_006e6b90();
      local_154 = CONCAT44(local_154._4_4_,iVar2 * (int)local_158);
      uVar6 = FUN_006e6b90();
      uVar7 = FUN_006e6b90();
      uVar12 = (uVar5 - uVar6) + uVar7;
      uVar13 = uVar12 + DAT_0097ba70;
      iVar2 = ((((int)uVar5 >> 0x1f) - ((int)uVar6 >> 0x1f)) - (uint)(uVar5 < uVar6)) +
              ((int)uVar7 >> 0x1f) + (uint)CARRY4(uVar5 - uVar6,uVar7) + ((int)DAT_0097ba70 >> 0x1f)
              + (uint)CARRY4(uVar12,DAT_0097ba70);
      if (0 < (int)local_158) {
        local_154 = CONCAT44(local_154._4_4_,(int)local_15c * 3);
        fVar10 = local_158;
        do {
          FUN_004f6de0(DAT_0097ba7c,uVar13,iVar2,0);
          uVar5 = FUN_006e6b90();
          bVar14 = CARRY4(uVar13,uVar5);
          uVar13 = uVar13 + uVar5;
          iVar2 = iVar2 + ((int)uVar5 >> 0x1f) + (uint)bVar14;
          FUN_004f03d0(DAT_0097ba7c,puVar4,(int)local_154);
          fVar10 = (float)((int)fVar10 + -1);
          puVar4 = puVar4 + (uint)DAT_0097ba84 * 3;
        } while (fVar10 != 0.0);
      }
      FUN_005ff070(&local_14c);
      DAT_0080b6ec = DAT_0080b6ec + 1;
      if ((float)DAT_0080b6ec < _DAT_0097ba88 * _DAT_0097ba8c) {
        _DAT_0097ba74 = _DAT_0097ba74 + 1.0;
        fVar15 = (float10)0;
        if (_DAT_0097ba88 <= _DAT_0097ba74) {
          _DAT_0097ba74 = (float)fVar15;
          _DAT_0097ba78 = _DAT_0097ba78 + 1.0;
        }
        fVar16 = (float10)DAT_0080e694;
        fVar18 = fVar16 * (float10)_DAT_0097ba74 * (float10)0.75;
        fVar19 = (float10)-0.125;
        fVar20 = (float10)param_2;
        local_15c = (float)((fVar16 * fVar19 + fVar18) / fVar20);
        local_158 = (float)((fVar16 + fVar18 + fVar16 * fVar19) / fVar20);
        fVar18 = (float10)local_158;
        if (fVar18 <= fVar16) {
          DAT_0097ba68 = 0;
        }
        else {
          fVar15 = fVar16;
          DAT_0097ba68 = FUN_006e6b90();
          fVar16 = fVar20;
          local_158 = (float)fVar16;
          local_15c = local_15c - (float)DAT_0097ba68;
          fVar18 = (float10)local_158;
          fVar20 = extraout_ST1_02;
          fVar19 = extraout_ST0_04;
        }
        local_160 = (float)DAT_0080e698;
        fVar21 = (float10)DAT_0080e698;
        fVar17 = fVar21 * (float10)_DAT_0097ba78 * (float10)0.75;
        fVar10 = (float)((fVar21 * fVar19 + fVar17) / fVar20);
        local_154 = CONCAT44(local_154._4_4_,fVar10);
        FUN_005ff660(local_15c,fVar10,(float)fVar18,
                     (float)((fVar21 + fVar17 + fVar21 * fVar19) / fVar20),(float)fVar15,
                     (float)fVar15,(float)fVar16,local_160);
        DAT_0097ba6c = 3;
      }
      else {
        FUN_005ff050(&DAT_0097ba80);
        DAT_0080b6ec = -1;
        FUN_004f99e0(DAT_0097ba7c);
        _DAT_0097ba78 = 0.0;
        _DAT_0097ba74 = 0.0;
        _DAT_0097ba8c = 0.0;
        _DAT_0097ba88 = 0.0;
        local_160 = (float)DAT_0080e698;
        local_158 = (float)DAT_0080e694;
        FUN_005ff660(0,0,local_158,local_160,0,0,local_158,local_160);
        DAT_0097392c = 0;
      }
    }
  }
  else {
    DAT_0097ba6c = DAT_0097ba6c + -1;
  }
  __security_check_cookie(local_4 ^ (uint)&local_160);
  return;
}

