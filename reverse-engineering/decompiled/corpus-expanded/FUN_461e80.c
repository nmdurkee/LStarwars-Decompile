/* Ghidra pseudocode, not original source.
 * ev_a0c576544e413369fb0a5ddd4679e51ae37c83af368344a8e8d6b5078f1bd76b
 * Entry: 0x461e80; label: FUN_00461e80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00461e80(int param_1,int param_2,int param_3)

{
  short sVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  float10 extraout_ST0;
  float10 fVar8;
  float10 extraout_ST1;
  float fVar9;
  float fVar10;
  float local_118;
  float local_114;
  float local_110;
  float local_10c;
  int local_108;
  char local_104 [256];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_118;
  if (param_3 == 0) {
    if (*(char *)(param_1 + 0x12) != '\0') {
      fVar8 = (float10)FUN_0045e430(param_2);
      local_118 = (float)fVar8;
      if (((*(int *)(param_1 + 0xc) == 0x1a) && (*(char *)(param_2 + 0xa7) == '\x02')) ||
         ((*(int *)(param_1 + 0xc) == 0x17 && (*(char *)(param_2 + 0xa6) == '\x02')))) {
        FUN_004b80e0(**(undefined4 **)(param_2 + 0x1c),_DAT_007fc310,_DAT_0087b93c,1,local_118,0xff,
                     0xbf,0);
        __security_check_cookie(local_4 ^ (uint)&local_118);
        return;
      }
    }
    goto LAB_004628a8;
  }
  if (0 < *(int *)(param_1 + 0x14)) {
    if (0.5 <= *(float *)(param_1 + 0x18)) {
      if (3.5 <= *(float *)(param_1 + 0x18)) {
        local_118 = 1.0 - (*(float *)(param_1 + 0x18) - 3.5) * 2.0;
        goto LAB_00461ff9;
      }
      local_118 = 1.0;
    }
    else {
      local_118 = *(float *)(param_1 + 0x18) * 2.0;
LAB_00461ff9:
      if (local_118 <= 0.0) goto LAB_00462487;
    }
    uVar2 = FUN_006e6b90();
    iVar7 = *(int *)(param_1 + 0xc);
    if (iVar7 == 0xe) {
      _sprintf(local_104,"%s",
               *(undefined4 *)
                (DAT_00926c20 + *(short *)(DAT_00956290 + 2 + *(char *)(param_2 + 0xa2) * 0x1c) * 4)
              );
      local_118 = _DAT_007f85f8 * 0.75;
      FUN_0050d910(local_104,0,_DAT_007f85f4,0x3f800000,local_118,local_118,local_118,0,
                   _DAT_007fa4c8 & 0xff,_DAT_007fa4cc & 0xff,_DAT_0087a774 & 0xff,0x3fd9999a,1,0,0,
                   uVar2);
      uVar6 = _DAT_0087a774 & 0xff;
      iVar7 = (int)DAT_0088071c;
LAB_00462431:
      uVar4 = _DAT_007fa4cc & 0xff;
      uVar5 = _DAT_007fa4c8 & 0xff;
      fVar10 = 1.0;
      fVar8 = (float10)0;
      fVar9 = _DAT_007f85fc;
    }
    else {
      fVar8 = extraout_ST0;
      if (iVar7 == 0xd) {
        if (((DAT_0087b014 != 0) && (*(int *)(param_2 + 0x14) == DAT_0087b014)) ||
           ((DAT_0087b01c != 0 && (*(int *)(param_2 + 0x14) == DAT_0087b01c)))) {
          uVar6 = _DAT_0087a774 & 0xff;
          uVar4 = _DAT_007fa4cc & 0xff;
          uVar5 = _DAT_007fa4c8 & 0xff;
          iVar7 = (int)DAT_00880708;
          fVar10 = (float)extraout_ST1;
          fVar9 = (_DAT_007f85fc + _DAT_007f85f4) * 0.5;
          local_10c = fVar9;
          goto LAB_0046246a;
        }
        FUN_0050d910(*(undefined4 *)(DAT_00926c20 + DAT_00880708 * 4),(float)extraout_ST0,
                     _DAT_007f85f4,(float)extraout_ST1,_DAT_007f85f8,_DAT_007f85f8,_DAT_007f85f8,0,
                     _DAT_007fa4c8 & 0xff,_DAT_007fa4cc & 0xff,_DAT_0087a774 & 0xff,0x3fd9999a,1,0,0
                     ,uVar2);
        uVar6 = _DAT_0087a774 & 0xff;
        iVar7 = (int)DAT_0088070c;
        goto LAB_00462431;
      }
      if (iVar7 == 8) {
        FUN_0050d910(*(undefined4 *)(DAT_00926c20 + DAT_008810ac * 4),(float)extraout_ST0,
                     _DAT_007f85f4,(float)extraout_ST1,_DAT_007f85f8,_DAT_007f85f8,_DAT_007f85f8,0,
                     _DAT_007fa4c8 & 0xff,_DAT_007fa4cc & 0xff,_DAT_0087a774 & 0xff,0x3fd9999a,1,0,0
                     ,uVar2);
        uVar6 = _DAT_0087a774 & 0xff;
        iVar7 = (int)DAT_008810b0;
        goto LAB_00462431;
      }
      if (iVar7 == 0x1c) {
        uVar6 = _DAT_0087a774 & 0xff;
        uVar4 = _DAT_007fa4cc & 0xff;
        uVar5 = _DAT_007fa4c8 & 0xff;
        iVar7 = (int)DAT_008806f0;
        fVar10 = (float)extraout_ST1;
        fVar9 = (float)extraout_ST0;
      }
      else {
        if (iVar7 != 0x17) {
          if (iVar7 == 0x1a) {
            uVar5 = _DAT_007fa4c8;
            uVar4 = _DAT_007fa4cc;
            uVar6 = _DAT_0087a774;
            sVar1 = DAT_008806d4;
            if (*(char *)(param_2 + 0xa7) == '\x02') {
              uVar5 = 0xff;
              uVar4 = 0xff;
              uVar6 = 0xff;
              sVar1 = DAT_008806c4;
            }
            FUN_0050d910(*(undefined4 *)(DAT_00926c20 + sVar1 * 4),(float)extraout_ST0,
                         (float)extraout_ST0,(float)extraout_ST1,_DAT_007f85f8,_DAT_007f85f8,
                         _DAT_007f85f8,0,uVar5,uVar4,uVar6,0x3fd9999a,1,0,0,uVar2);
            goto LAB_00462487;
          }
          if (iVar7 == 0x1d) {
            uVar3 = *(undefined4 *)(DAT_00926c20 + DAT_00880ff4 * 4);
          }
          else if (iVar7 == 0x1e) {
            uVar3 = *(undefined4 *)(DAT_00926c20 + DAT_00880ffc * 4);
          }
          else {
            sVar1 = DAT_00881004;
            if (iVar7 == 0x1f) {
LAB_004623ad:
              uVar3 = *(undefined4 *)(DAT_00926c20 + sVar1 * 4);
            }
            else if (iVar7 == 0x20) {
              uVar3 = *(undefined4 *)(DAT_00926c20 + DAT_0088100c * 4);
            }
            else {
              sVar1 = DAT_0088101c;
              if (iVar7 != 0x21) goto LAB_004623ad;
              uVar3 = *(undefined4 *)(DAT_00926c20 + DAT_00881014 * 4);
            }
          }
          FUN_0050d910(uVar3,(float)extraout_ST0,_DAT_007f85f4,(float)extraout_ST1,_DAT_007f85f8,
                       _DAT_007f85f8,_DAT_007f85f8,0,_DAT_007fa4c8 & 0xff,_DAT_007fa4cc & 0xff,
                       _DAT_0087a774 & 0xff,0x3fd9999a,1,0,0,uVar2);
          uVar6 = _DAT_0087a774 & 0xff;
          iVar7 = (int)DAT_00880710;
          goto LAB_00462431;
        }
        if (*(char *)(param_2 + 0xa6) == '\x02') {
          iVar7 = (int)DAT_008806c8;
          uVar5 = 0xff;
          uVar4 = 0xff;
          uVar6 = 0xff;
        }
        else {
          iVar7 = (int)DAT_008806d4;
          uVar5 = _DAT_007fa4c8;
          uVar4 = _DAT_007fa4cc;
          uVar6 = _DAT_0087a774;
          if (*(char *)(param_2 + 0xa6) != '\x03') {
            iVar7 = (int)DAT_00880fec;
          }
        }
        fVar10 = (float)extraout_ST1;
        fVar9 = (float)extraout_ST0;
      }
    }
LAB_0046246a:
    FUN_0050d910(*(undefined4 *)(DAT_00926c20 + iVar7 * 4),(float)fVar8,fVar9,fVar10,_DAT_007f85f8,
                 _DAT_007f85f8,_DAT_007f85f8,0,uVar5,uVar4,uVar6,0x3fd9999a,1,0,0,uVar2);
  }
LAB_00462487:
  if ((*(int *)(param_1 + 0xc) == 0x17) || (*(int *)(param_1 + 0xc) == 0x1a)) {
    if (*(int *)(param_1 + 0x14) == 0) {
      _DAT_0087a1d0 = 0.0;
    }
    else {
      local_118 = *(float *)(param_1 + 0x1c) - 0.5;
      if (local_118 <= *(float *)(param_1 + 0x18)) {
        _DAT_0087a1d0 = *(float *)(param_1 + 0x18) - local_118;
        _DAT_0087a1d0 = _DAT_0087a1d0 + _DAT_0087a1d0;
      }
      else {
        _DAT_0087a1d0 = 0.0;
      }
    }
    if ((*(int *)(param_1 + 0xc) == 0x1a) && (*(char *)(param_2 + 0xa7) == '\x02')) {
      if (*(byte *)(param_2 + 0xbd) < DAT_0086e4e2) {
        _DAT_0087a1d0 = 0.0;
      }
    }
    else if ((*(int *)(param_1 + 0xc) != 0x17) || (*(char *)(param_2 + 0xa6) != '\x02'))
    goto LAB_004628a8;
    if (0.75 <= *(float *)(param_1 + 0x18)) {
      fVar10 = *(float *)(param_1 + 0x1c) - 0.75;
      if (fVar10 <= *(float *)(param_1 + 0x18)) {
        local_114 = 1.0 - (*(float *)(param_1 + 0x18) - fVar10) / 0.75;
        local_110 = 1.0;
      }
      else {
        local_114 = 1.0;
        local_110 = (*(float *)(param_1 + 0x18) - 0.75) / (fVar10 - 0.75);
      }
    }
    else {
      local_114 = *(float *)(param_1 + 0x18) / 0.7;
      local_110 = 0.0;
    }
    local_118 = local_114;
    fVar10 = *(float *)(param_1 + 0x18);
    if (!NAN(fVar10) && 0.75 < fVar10 != (fVar10 == 0.75)) {
      local_118 = 1.0;
    }
    local_10c = *(float *)(param_2 + 0x74);
    local_108 = *(int *)(param_2 + 0x78) - (int)local_10c;
    iVar7 = FUN_006e6b90(0);
    FUN_005533f0(&local_10c,iVar7,iVar7 >> 0x1f);
    iVar7 = FUN_006e6b90(_DAT_0087b93c,1,0x3f800000,0xff,0xbf,0);
    local_118 = (_DAT_007fc310 - _DAT_007fc314) * (float)(&DAT_029899a0)[iVar7 >> 1 & 0x7fff] +
                _DAT_007fc314;
    FUN_004b80e0(local_10c,local_118);
    if (*(int *)(param_1 + 0xc) == 0x1a) {
      local_118 = (float)*(ushort *)(*(int *)(param_2 + 0x20) + 0x10) - *(float *)(param_2 + 100);
      if (local_118 < 0.0) {
        local_118 = 0.0;
      }
      local_118 = (1.0 - local_110) * local_118;
      FUN_0054bbc0(local_118,0,1,1,local_104);
      iVar7 = FUN_006e6b90(0x3f800000,0x3f19999a,0x3f19999a,0x3f19999a,0,0xff,0xbf,0);
      local_118 = -((_DAT_007fc310 - _DAT_007fc314) * (float)(&DAT_029899a0)[iVar7 >> 1 & 0x7fff] +
                   _DAT_007fc314);
      FUN_00511500(local_104,0,local_118);
    }
    if (*(int *)(param_1 + 0xc) == 0x17) {
      local_118 = (float)*(ushort *)(*(int *)(param_2 + 0x14) + 0x84) - *(float *)(param_2 + 100);
      if (local_118 < 0.0) {
        local_118 = 0.0;
      }
      local_110 = (1.0 - local_110) * local_118;
      FUN_0054bbc0(local_110,0,1,1,local_104);
      iVar7 = FUN_006e6b90(0x3f800000,0x3f19999a,0x3f19999a,0x3f19999a,0,0xff,0xbf,0);
      local_114 = -((_DAT_007fc310 - _DAT_007fc314) * (float)(&DAT_029899a0)[iVar7 >> 1 & 0x7fff] +
                   _DAT_007fc314);
      FUN_00511500(local_104,0,local_114);
      __security_check_cookie(local_4 ^ (uint)&local_118);
      return;
    }
  }
LAB_004628a8:
  __security_check_cookie(local_4 ^ (uint)&local_118);
  return;
}

