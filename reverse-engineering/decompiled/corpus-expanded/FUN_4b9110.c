/* Ghidra pseudocode, not original source.
 * ev_994c8ab95260a4a020e9117574c628d5ef7b33cde61134a1d0677698b3534ab7
 * Entry: 0x4b9110; label: FUN_004b9110
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004b9110(int param_1)

{
  float fVar1;
  char cVar2;
  short sVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  undefined *puVar9;
  ushort uVar10;
  undefined4 *puVar11;
  int iVar12;
  uint uVar13;
  undefined4 uVar14;
  undefined2 in_FPUControlWord;
  float10 fVar15;
  float10 extraout_ST0;
  float local_170;
  float local_16c;
  float local_168;
  float local_164;
  float local_160;
  float local_15c;
  float local_158;
  float local_154;
  int local_150;
  undefined4 local_14c;
  byte local_148 [4];
  char local_144 [256];
  undefined1 local_44 [64];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_170;
  if ((_DAT_00950780 != 0.0) || ((*(byte *)(*(int *)(PTR_DAT_00802c54 + 0x128) + 100) & 2) == 0))
  goto LAB_004ba170;
  iVar4 = FUN_00475850(local_148);
  iVar5 = FUN_006e6b90();
  iVar12 = 0;
  iVar6 = *(int *)(PTR_DAT_00802c54 + 300);
  local_164 = (_DAT_007fc310 - _DAT_007fc314) * (float)(&DAT_029899a0)[iVar5 >> 1 & 0x7fff] +
              _DAT_007fc314;
  if (((iVar6 != 0) && ((iVar6 == DAT_00951364 || ((*(ushort *)(iVar6 + 0x7a) & 0x100) != 0)))) ||
     ((DAT_0093b2a8 != 0 ||
      (((DAT_00856c08 != 0 || (iVar6 = FUN_0058a900(0), iVar6 != 0)) || (local_150 = 0, iVar4 == 0))
      )))) {
    local_150 = 1;
  }
  FUN_00574e20();
  fVar15 = (float10)FUN_005b7d30(_DAT_00925030,0x3f000000);
  local_16c = (float)CONCAT22(local_16c._2_2_,in_FPUControlWord);
  local_168 = (float)(int)ROUND((fVar15 + fVar15) * (float10)65536.0);
  local_154 = (float)FUN_006e6b90();
  local_14c = FUN_006d6350();
  do {
    FUN_006d6340(iVar12);
    iVar6 = (&DAT_0093d7f0)[iVar12];
    if (iVar6 != 0) {
      if (((param_1 == 0) || (iVar12 == DAT_00802af8)) || ((*(byte *)(iVar6 + 0x1fc) & 0x80) == 0))
      {
        local_160 = 1.0;
      }
      else {
        local_160 = 0.5;
      }
      if (iVar12 == 0) {
        uVar13 = 2;
        local_16c = -_DAT_007fc31c;
        uVar14 = 0xa6;
      }
      else {
        uVar13 = 8;
        uVar14 = 0xa5;
        local_16c = _DAT_007fc31c;
      }
      local_158 = _DAT_007fc2d8;
      if ((*(byte *)(iVar6 + 0x1fc) & 0x80) != 0) {
        local_158 = 1.0;
      }
      local_158 = local_158 * local_160;
      local_168 = (float)FUN_006e6b90();
      _DAT_00802924 = iVar12;
      if (((*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_0087b248) && (*(int *)(iVar6 + 0xcd0) != 0))
         && (*(short *)(*(int *)(iVar6 + 0xcd0) + 0x1064) == DAT_007f18c8)) {
        if ((*(float *)(iVar6 + 0xd60) <= 0.0) ||
           ((*(float *)(iVar6 + 0xd60) < 2.0 &&
            (fVar15 = (float10)FUN_005b7d30(*(undefined4 *)(iVar6 + 0xd60),0x3ecccccd),
            fVar15 < (float10)0.20000000298023224)))) {
          uVar7 = 1;
        }
        else {
          uVar7 = 0;
        }
        sVar3 = *(short *)(iVar6 + 0x1064);
      }
      else {
        if ((*(float *)(iVar6 + 0xd60) <= 0.0) ||
           ((*(float *)(iVar6 + 0xd60) < 2.0 &&
            (fVar15 = (float10)FUN_005b7d30(*(undefined4 *)(iVar6 + 0xd60),0x3ecccccd),
            fVar15 < (float10)0.20000000298023224)))) {
          uVar7 = 1;
        }
        else {
          uVar7 = 0;
        }
        if (*(int *)(iVar6 + 0xcd0) == 0) {
          sVar3 = *(short *)(iVar6 + 0x1064);
        }
        else {
          sVar3 = *(short *)(*(int *)(iVar6 + 0xcd0) + 0x1064);
        }
      }
      FUN_0055b830((int)sVar3,local_16c,local_164,0,_DAT_007fc318,uVar14,local_158,local_158,uVar7,0
                  );
      local_16c = _DAT_007fc294 + _DAT_007fc31c;
      if (iVar12 == 0) {
        local_16c = -local_16c;
      }
      if ((((*(byte *)(iVar6 + 0x1fc) & 0x80) != 0) && (**(int **)(iVar6 + 0x54) != -1)) &&
         ((param_1 != 0 ||
          (((0.0 < *(float *)(iVar6 + 0xd60) && (*(float *)(iVar6 + 0xd60) < 2.0)) &&
           (fVar15 = (float10)FUN_005b7d30(*(undefined4 *)(iVar6 + 0xd60),0x3ecccccd),
           fVar15 < (float10)0.20000000298023224)))))) {
        local_15c = _DAT_007fc298 + local_164;
        uVar14 = FUN_006e6b90();
        local_170 = _DAT_007fc28c;
        if (DAT_008668d7 != '\0') {
          local_170 = _DAT_007fc290;
        }
        uVar14 = FUN_00434930(0xffffffff,iVar6,local_44,local_16c,local_15c,0x3f800000,_DAT_007fc27c
                              ,_DAT_007fc27c,_DAT_007fc27c,uVar13 | 1,DAT_007fc280,DAT_007fc284,
                              DAT_007fc288,local_170,2,0,0,uVar14);
        FUN_0050d910(uVar14);
      }
      if (((DAT_007fc29c != 0) && (param_1 != 0)) && (iVar12 == DAT_00802af8)) {
        fVar1 = _DAT_007fc28c;
        if (DAT_008668d7 != '\0') {
          fVar1 = _DAT_007fc290;
        }
        local_170 = _DAT_007fc2a0 + local_164;
        FUN_0050d910(*(undefined4 *)(DAT_00926c20 + DAT_00880814 * 4),local_16c,local_170,0x3f800000
                     ,_DAT_007fc27c,_DAT_007fc27c,_DAT_007fc27c,uVar13 | 1,DAT_007fc2a4,DAT_007fc2a8
                     ,DAT_0087b9a4,fVar1,1,0,0,local_154);
      }
      if (((DAT_007f39e4 != 0) && (param_1 == 0)) &&
         ((_DAT_00950780 == 0.0 && ((*(byte *)(iVar6 + 0x1fc) & 0x80) != 0)))) {
        if ((DAT_008032cc == 0) || (*(float *)(iVar6 + 0xdec) <= 0.0)) {
          uVar8 = FUN_0056e2a0(1);
          if ((DAT_0087b924 & 1 << ((byte)iVar12 & 0x1f)) != 0) {
            uVar8 = uVar8 * 2;
          }
          if (1 < uVar8) {
            _sprintf(local_144,(char *)&PTR_LAB_00758ca8,uVar8);
            local_170 = _DAT_007fc31c;
            if (iVar12 == 0) {
              local_170 = -_DAT_007fc31c;
            }
            local_160 = _DAT_007fc2a0 + local_164;
            FUN_0050c780(local_144,local_170,local_160,0x3f800000,0x3e99999a,0x3eb33333,0x3eb33333,1
                         ,0xff,0,0xff,local_154);
          }
        }
        else {
          iVar4 = FUN_005618e0(7,0,(int)*(char *)(iVar6 + 0x280),0);
          if ((iVar4 == 0) &&
             ((fVar1 = *(float *)(iVar6 + 0xdec), !NAN(fVar1) && 3.0 < fVar1 != (fVar1 == 3.0) ||
              (DAT_00925068 % 6 < 3)))) {
            local_170 = _DAT_007fc31c;
            if (iVar12 == 0) {
              local_170 = -_DAT_007fc31c;
            }
            fVar15 = (float10)FUN_004b7120(iVar12,0x3f800000,_DAT_007fc2b4,_DAT_007fc2b4,
                                           _DAT_007fc2b4,0,(&DAT_00879360)[iVar12],0,
                                           *(int *)(PTR_DAT_00802c54 + 0x2ac0) + 0xd00,0,0x3f800000)
            ;
            local_160 = (float)(fVar15 + (float10)local_164);
            FUN_00552c10(local_170,local_160);
            local_170 = _DAT_007fc31c;
            if (iVar12 == 0) {
              local_170 = -_DAT_007fc31c;
            }
            fVar15 = (float10)FUN_004b7120(iVar12,0x3f800000,_DAT_007fc2b4,_DAT_007fc2b4,
                                           _DAT_007fc2b4,0,(&DAT_00879360)[iVar12],0,
                                           *(int *)(PTR_DAT_00802c54 + 0x2ac0) + 0xd10,0,0x3f800000)
            ;
            local_160 = (float)(fVar15 + (float10)local_164);
            FUN_00552c10(local_170,local_160);
          }
        }
      }
      if ((*(byte *)(iVar6 + 0x1fc) & 0x80) == 0) {
        if (((param_1 == 0) && (DAT_00951be0 == 0)) && (iVar4 = FUN_006e6b90(), 0 < iVar4)) {
          local_16c = _DAT_007fc2d4;
          if (iVar12 == 0) {
            local_16c = -_DAT_007fc2d4;
          }
          local_15c = local_164;
          if (local_150 == 0) {
            local_15c = _DAT_007fc300 + local_164;
          }
          puVar9 = PTR_DAT_00800a6c;
          if (iVar12 != 0) {
            puVar9 = PTR_DAT_00800a70;
          }
          FUN_0050d910(puVar9,local_16c,local_15c,0x3f800000,_DAT_007fc2dc,_DAT_007fc2dc,
                       _DAT_007fc2dc,uVar13,0xff,0xff,0xff,0x3e99999a,2,0,0,iVar4);
        }
      }
      else {
        local_16c = _DAT_007fc2fc;
        if (iVar12 == 0) {
          local_16c = -_DAT_007fc2fc;
        }
        local_15c = local_164;
        if (local_150 == 0) {
          local_15c = _DAT_007fc300 + local_164;
        }
        FUN_004b88b0(local_16c,local_15c,_DAT_007fc304,0x3f800000,uVar13,local_158,1);
      }
      if (local_150 == 0) {
        if ((local_148[0] & 2) == 0) {
          if (*(undefined4 **)(iVar6 + 0x7fc) != (undefined4 *)0x0) {
            FUN_0054bb30(**(undefined4 **)(iVar6 + 0x7fc),local_144);
            fVar1 = local_168;
            if (iVar12 == 0) {
              local_160 = -_DAT_007fc2ec;
              local_16c = -_DAT_007fc2e0;
            }
            else {
              local_160 = _DAT_007fc2ec;
              local_16c = _DAT_007fc2e0;
            }
            local_170 = *(float *)(*(int *)(iVar6 + 0x7fc) + 4) * _DAT_007fc2f8;
            local_15c = _DAT_007fc2e4 + local_164;
            local_168 = _DAT_007fc2e8 + local_15c;
            FUN_0050c780(local_144,local_160,local_168,0x3f800000,local_170,local_170,local_170,
                         uVar13,0xff,0xbf,0,fVar1);
            iVar4 = (int)*(short *)(*(int *)(iVar6 + 0x7fc) + 8);
            if (iVar4 - 0xb7U < 4) {
              iVar4 = iVar4 + -4;
            }
            else if (iVar4 - 0xbfU < 4) {
              iVar4 = iVar4 + -4;
            }
            else if (iVar4 - 199U < 4) {
              iVar4 = iVar4 + -4;
            }
            else if (iVar4 - 0xd5U < 4) {
              iVar4 = iVar4 + 4;
            }
            iVar4 = iVar4 * 0x10 + *(int *)(PTR_DAT_00802c54 + 0x2ac0);
            if (*(char *)(iVar4 + 0xe) != '\0') {
              local_170 = *(float *)(*(int *)(iVar6 + 0x7fc) + 4);
              goto LAB_004b9c14;
            }
          }
        }
        else {
          _sprintf(local_144,"%i/%i",(&DAT_00951250)[iVar12],
                   *(undefined4 *)(&DAT_007fa134 + DAT_007fa190 * 0xc));
          fVar1 = local_168;
          if (iVar12 == 0) {
            local_160 = -_DAT_007fc2ec;
            local_16c = -_DAT_007fc2e0;
          }
          else {
            local_160 = _DAT_007fc2ec;
            local_16c = _DAT_007fc2e0;
          }
          local_170 = *(float *)(*(int *)(iVar6 + 0x7fc) + 4) * _DAT_007fc2f8;
          local_15c = _DAT_007fc2e4 + local_164;
          local_168 = _DAT_007fc2e8 + local_15c;
          FUN_0050c780(local_144,local_160,local_168,0x3f800000,local_170,local_170,local_170,uVar13
                       ,0xff,0xbf,0,fVar1);
          iVar4 = *(int *)(PTR_DAT_00802c54 + 0x2ac0) + 0x350;
          if (*(char *)(*(int *)(PTR_DAT_00802c54 + 0x2ac0) + 0x35e) != '\0') {
            local_170 = *(float *)(*(int *)(iVar6 + 0x7fc) + 4);
LAB_004b9c14:
            local_170 = local_170 * _DAT_007fc2f4;
            FUN_00552c10(local_16c,local_15c,0x3f800000,local_170,local_170,local_170,0,0,0,iVar4,0,
                         local_158);
          }
        }
      }
    }
    iVar12 = iVar12 + 1;
  } while (iVar12 < 2);
  iVar6 = FUN_0050b310();
  if (iVar6 == 0) {
    if ((*(int *)(PTR_DAT_00802c54 + 300) != 0) &&
       (uVar13 = ~-(uint)(DAT_0093b338 != 0) & DAT_0093b2a4, DAT_0093b2a8 == 0)) {
      if (DAT_00856c08 == 0) {
        iVar6 = FUN_0058a900(0);
        if (((iVar6 == 0) && (DAT_0093b324 == 0)) &&
           ((*(byte *)(*(int *)(PTR_DAT_00802c54 + 300) + 0x7a) & 0x10) != 0)) {
          if (DAT_0093b314 == 0) {
            iVar6 = *(int *)(PTR_DAT_00802c54 + 0x120) * 0xc;
            if ((&DAT_0086e0f6)[iVar6] != '\0') goto LAB_004b9dc2;
            cVar2 = (&DAT_0086e0f7)[iVar6];
          }
          else {
            cVar2 = (&DAT_0086e0f6)[*(int *)(PTR_DAT_00802c54 + 0x120) * 0xc + uVar13];
          }
          if ((cVar2 == '\0') &&
             (iVar6 = *(int *)(*(int *)(PTR_DAT_00802c54 + 300) + 0x8c + uVar13 * 4), iVar6 != 0)) {
            iVar4 = FUN_006e6b90();
            local_164 = (_DAT_007fc310 - _DAT_007fc314) *
                        (float)(&DAT_029899a0)[iVar4 >> 1 & 0x7fff] + _DAT_007fc314;
            local_15c = _DAT_007fc2e4 + local_164;
            iVar4 = iVar6;
            if (DAT_0087b980 == 0) {
              iVar4 = DAT_0087b994;
            }
            FUN_004b86f0(0,local_15c,iVar4,iVar6,0x3f800000,_DAT_0087b92c,0x3f800000,0);
          }
        }
LAB_004b9dc2:
        if (DAT_0093b2a8 != 0) goto LAB_004ba014;
      }
      iVar6 = FUN_0058a900(0);
      if (((iVar6 == 0) && (DAT_0093b324 == 0)) &&
         (((*(byte *)(*(int *)(PTR_DAT_00802c54 + 300) + 0x7a) & 0x10) != 0 ||
          (((*(uint *)(*(int *)(PTR_DAT_00802c54 + 0x128) + 100) & 0x200) != 0 &&
           (iVar6 = FUN_00570030(PTR_DAT_00802c54,4,0), 0 < iVar6)))))) {
        uVar14 = DAT_00951238;
        if (DAT_00856c08 != 0) {
          uVar14 = DAT_00951244;
        }
        FUN_0059a1e0(_DAT_0087b99c,_DAT_00955fc0,uVar14,10);
      }
      if ((((((DAT_0093b2a8 == 0) && (DAT_00856c08 == 0)) && (iVar6 = FUN_0058a900(0), iVar6 == 0))
           && ((DAT_0093b324 == 0 &&
               ((*(byte *)(*(int *)(PTR_DAT_00802c54 + 300) + 0x7a) & 0x10) != 0)))) &&
          ((DAT_0095122c == 2 || ((&DAT_0086e0fa)[*(int *)(PTR_DAT_00802c54 + 0x120) * 0xc] != '\0')
           ))) && (0.0 < _DAT_0087b974)) {
        iVar6 = FUN_006e6b90();
        local_170 = (float)(&DAT_029899a0)[iVar6 >> 1 & 0x7fff];
        local_154 = local_170 * (_DAT_007fc324 - _DAT_007fc32c) + _DAT_007fc32c;
        local_164 = _DAT_007fc330 + (_DAT_007fc328 - _DAT_007fc330) * local_170;
        fVar15 = (float10)FUN_005b7d30(_DAT_00925028,0x40800000);
        local_168._0_2_ = (short)(int)ROUND(fVar15 * (float10)0.25 * (float10)-65536.0);
        uVar10 = 0x1555 - local_168._0_2_;
        local_170 = _DAT_0087b948 * _DAT_007fc320;
        local_16c = (float)CONCAT22(local_16c._2_2_,in_FPUControlWord);
        local_168 = (float)(int)ROUND((float)(&DAT_029899a0)[(int)((uint)uVar10 * 2) >> 1 & 0x7fff]
                                      * 1820.0);
        FUN_00552d10(local_154,local_164,0x3f800000,local_170,local_170,local_170,
                     (uint)local_168 & 0xffff,(uint)uVar10,0,
                     *(int *)(PTR_DAT_00802c54 + 0x2ac0) + 0xd20,2);
      }
    }
LAB_004ba014:
    if (0.0 < _DAT_00925040) {
      FUN_004b9090(_DAT_00925040);
    }
  }
  if (((DAT_00951154 != 0) && (*(int *)(PTR_DAT_00802c54 + 300) != 0)) &&
     ((*(ushort *)(*(int *)(PTR_DAT_00802c54 + 300) + 0x7a) & 0x104) == 4)) {
    puVar11 = &DAT_00879544;
    if (DAT_0093b324 == 0) {
      puVar11 = &DAT_0086e714;
    }
    if ((DAT_0093d7f4 == 0) || ((*(byte *)(DAT_0093d7f4 + 0x1fc) & 0x80) == 0)) {
      uVar14 = 0;
    }
    else {
      uVar14 = 1;
    }
    if ((DAT_0093d7f0 == 0) || ((*(byte *)(DAT_0093d7f0 + 0x1fc) & 0x80) == 0)) {
      uVar7 = 0;
    }
    else {
      uVar7 = 1;
    }
    FUN_004b8cf0(local_164,uVar7,uVar14,0x3f800000,puVar11);
  }
  if (((DAT_00951364 != 0) && (*(int *)(PTR_DAT_00802c54 + 300) == DAT_00951364)) &&
     (0.0 < _DAT_0087b9a0)) {
    iVar6 = FUN_006e6b90(0x3f800000,DAT_0086e4e2,DAT_0093b30c);
    local_168 = (-_DAT_007fc310 - -_DAT_007fc314) * (float)(&DAT_029899a0)[iVar6 >> 1 & 0x7fff] -
                _DAT_007fc314;
    FUN_00478d20(0xd3,(float)extraout_ST0,local_168);
  }
  FUN_006d6340(local_14c);
LAB_004ba170:
  __security_check_cookie(local_4 ^ (uint)&local_170);
  return;
}

