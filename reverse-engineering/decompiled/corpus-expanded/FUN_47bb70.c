/* Ghidra pseudocode, not original source.
 * ev_2606baf984ee455df312fc83a5be5e2bd228e340f9dbc5529ae9524aab57b603
 * Entry: 0x47bb70; label: FUN_0047bb70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0047bb70(void)

{
  ushort uVar1;
  float fVar2;
  short sVar3;
  short sVar4;
  float fVar5;
  float10 fVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int *piVar10;
  undefined4 uVar11;
  char cVar12;
  undefined4 *puVar13;
  int iVar14;
  undefined4 *puVar15;
  float10 fVar16;
  float10 extraout_ST0;
  float10 fVar17;
  float10 extraout_ST0_00;
  float10 extraout_ST0_01;
  float10 extraout_ST0_02;
  float10 fVar18;
  float10 extraout_ST0_03;
  float10 extraout_ST1;
  float10 extraout_ST1_00;
  float10 extraout_ST1_01;
  float10 extraout_ST1_02;
  float local_90;
  float local_8c;
  float local_88;
  float local_84;
  float local_80;
  float local_7c [4];
  float local_6c;
  float local_68;
  float local_64;
  int *local_60;
  float local_5c [2];
  int local_54 [2];
  double local_4c;
  undefined1 local_44 [64];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_90;
  uVar1 = *(ushort *)(DAT_00879afc * 0x9c + 0x7a + DAT_00951354);
  if ((uVar1 & 1) == 0) {
    piVar10 = &DAT_00855ea4;
  }
  else if ((uVar1 & 4) == 0) {
    piVar10 = &DAT_00855ed0;
  }
  else {
    piVar10 = &DAT_00855f24;
  }
  local_60 = piVar10;
  if (0.0 < _DAT_00950780) {
    __security_check_cookie(local_4 ^ (uint)&local_90);
    return;
  }
  if (DAT_00879564 == 0) {
    local_90 = DAT_00879540 / (_DAT_00879504 * 0.5);
    if (1.0 < local_90) {
      local_90 = 1.0;
    }
    local_90 = 1.0 - local_90;
    if (0.0 < local_90) {
      uVar1 = *(ushort *)(DAT_008795a0 * 0x9c + DAT_00951354 + 0x7a);
      if ((uVar1 & 0x100) == 0) {
        if ((uVar1 & 4) == 0) {
          FUN_00478f30(local_90,DAT_008795a0,0xffffffff);
          FUN_00475090(0,local_90);
        }
        else if (DAT_0087950c == 0) {
          FUN_0047ab00(local_90,0xffffffff,DAT_00879584);
          FUN_004763d0(0,local_90);
        }
        else {
          FUN_00475890(local_90);
          FUN_004763d0(0,local_90);
        }
      }
      else {
        FUN_0047af70(local_90);
        FUN_004763d0(0,local_90);
      }
      goto LAB_0047bce4;
    }
    local_90 = 1.0;
  }
  else {
LAB_0047bce4:
    fVar18 = (float10)0;
    fVar17 = (float10)1;
    if ((DAT_00879564 == 3) || (DAT_00879564 == 4)) goto LAB_0047c231;
    if (DAT_00879564 == 2) {
      if (DAT_00879540 < _DAT_00879504 - 0.1) {
        local_90 = 1.0 - DAT_00879540 / (_DAT_00879504 - 0.1);
      }
      else {
        local_90 = (float)fVar18;
      }
    }
    else {
      local_90 = (float)fVar17;
    }
  }
  iVar9 = (int)DAT_0087a840;
  if (DAT_0087b6c8 == '\0') {
    local_84 = _DAT_007fc2d8;
  }
  else {
    local_84 = 1.0;
  }
  local_8c = local_84 * local_90;
  if (DAT_00879b0c <= 0.0) {
    if (DAT_0087955c != 0) {
      iVar9 = (int)DAT_0087b6c4;
    }
  }
  else {
    local_80 = DAT_00879b0c / _DAT_007fa1cc;
    if (DAT_0087955c == 0) {
      local_80 = 1.0 - local_80;
    }
    local_8c = local_80 * local_8c;
  }
  if (0.0 < local_8c) {
    FUN_0055b830(iVar9,-_DAT_007fc31c,_DAT_007fc310,0,_DAT_007fc318,0xa6,local_8c,local_8c,1,0);
  }
  iVar9 = (int)DAT_0087a844;
  if (DAT_0087b6c9 == '\0') {
    local_84 = _DAT_007fc2d8;
  }
  else {
    local_84 = 1.0;
  }
  local_8c = local_84 * local_90;
  if (DAT_00879b10 <= 0.0) {
    if (DAT_00879560 != 0) {
      iVar9 = (int)DAT_0087b6c6;
    }
  }
  else {
    local_80 = DAT_00879b10 / _DAT_007fa1cc;
    if (DAT_00879560 == 0) {
      local_80 = 1.0 - local_80;
    }
    local_8c = local_80 * local_8c;
  }
  if (0.0 < local_8c) {
    FUN_0055b830(iVar9,_DAT_007fc31c,_DAT_007fc310,0,_DAT_007fc318,0xa5,local_8c,local_8c,1,0);
  }
  fVar18 = (float10)0;
  fVar17 = (float10)1;
  if (DAT_00879564 == 1) {
    iVar9 = 0;
    do {
      if ((&DAT_0087b6c8)[iVar9] != '\0') {
        iVar14 = (int)(&DAT_0087b6c4)[iVar9];
        iVar7 = FUN_00594960(iVar14);
        if (iVar7 == 0) {
          iVar14 = -1;
        }
        if ((&DAT_0087b6c8)[iVar9] == '\0') {
          local_8c = _DAT_007fc2d8;
        }
        else {
          local_8c = 1.0;
        }
        fVar17 = (float10)1;
        fVar18 = (float10)0;
        if ((float10)(&DAT_00879b0c)[iVar9] <= fVar18) {
          local_8c = (float)(&DAT_00879538)[iVar9] * local_8c;
        }
        if (iVar9 == 0) {
          uVar11 = 0xa6;
          local_90 = -0.4;
          local_84 = -_DAT_007fc31c;
        }
        else {
          uVar11 = 0xa5;
          local_90 = 0.4;
          local_84 = _DAT_007fc31c;
        }
        if ((&DAT_0087b6c8)[iVar9 - 1U & 1] == '\0') {
          local_90 = (float)fVar18;
        }
        local_7c[3] = _DAT_007f9358;
        if ((DAT_0093b0d8 != 0) && (*(char *)(DAT_0093b0d8 + 0xb) != '\0')) {
          local_7c[3] = _DAT_007f9358 * 0.875;
        }
        local_5c[0] = _DAT_007fc310;
        local_6c = _DAT_00804fb0;
        fVar16 = (float10)local_90;
        if ((float10)(&DAT_00879b0c)[iVar9] <= fVar18) {
          local_7c[2] = (float)fVar18;
          fVar6 = fVar17;
          if ((&DAT_0087955c)[iVar9] == 0) goto LAB_0047c0bd;
          local_8c = (float)fVar18;
          local_88 = (float)fVar18;
LAB_0047c15a:
          fVar17 = (float10)1;
          fVar18 = (float10)0;
        }
        else {
          local_80 = (&DAT_00879b0c)[iVar9] / _DAT_007fa1cc;
          if ((&DAT_0087955c)[iVar9] == 0) {
            local_80 = 1.0 - local_80;
          }
          fVar6 = (float10)local_80;
          fVar17 = fVar18;
          iVar7 = FUN_006e6b90();
          fVar18 = fVar16;
          fVar16 = fVar6;
          local_7c[2] = (float)(extraout_ST0 -
                               ((float10)(float)(&DAT_029899a0)[iVar7 >> 1 & 0x7fff] + extraout_ST0)
                               * (float10)0.5);
          fVar6 = extraout_ST1;
LAB_0047c0bd:
          local_88 = (float)fVar6;
          if (fVar18 < (float10)local_8c) {
            fVar17 = (float10)local_7c[2];
            local_7c[0] = (float)(((float10)local_84 - fVar16) * fVar17 + fVar16);
            FUN_0055b830(iVar14,local_7c[0],
                         (float)((float10)_DAT_007f9354 +
                                fVar17 * ((float10)local_5c[0] - (float10)_DAT_007f9354)),
                         (float)fVar18,
                         (float)(fVar17 * ((float10)local_6c - (float10)local_7c[3]) +
                                (float10)local_7c[3]),uVar11,local_8c,local_8c,1,0);
            goto LAB_0047c15a;
          }
        }
        if ((iVar14 != -1) && (fVar18 < (float10)local_88)) {
          uVar11 = FUN_006e6b90();
          uVar11 = FUN_00434930(iVar14,0,local_44,(float)extraout_ST0_00,_DAT_007f935c,
                                (float)extraout_ST1_00,0x3ee66666,0x3ee66666,0x3ee66666,1,0xff,0xbf,
                                0,0x3f400000,2,0,0,uVar11);
          FUN_0050d910(uVar11);
          fVar18 = (float10)0;
          fVar17 = (float10)1;
        }
      }
      iVar9 = iVar9 + 1;
      piVar10 = local_60;
    } while (iVar9 < 2);
  }
LAB_0047c231:
  iVar9 = DAT_00879598;
  fVar5 = DAT_00879540;
  if (DAT_00879564 == 0) {
    local_7c[0] = ABS(_DAT_00804fb4);
    DAT_00879b80 = DAT_0087b6c4;
    DAT_00879b88 = 0xffff;
    local_68 = -((1.0 - local_7c[0]) + 1.0);
    DAT_00879b84 = DAT_0087b6c6;
    iVar9 = FUN_006e6b90(piVar10[4],&DAT_00879b80,(float)fVar17,1);
    local_7c[0] = (float)((float10)local_68 +
                         (float10)(float)(&DAT_029899a0)[iVar9 >> 1 & 0x7fff] *
                         (extraout_ST0_01 - (float10)local_68));
    FUN_00594c30(piVar10,(float)extraout_ST1_01,local_7c[0]);
    FUN_00477630(piVar10,1,0x3f800000,0x3f800000);
    __security_check_cookie(local_4 ^ (uint)&local_90);
    return;
  }
  if (DAT_00879564 != 1) {
    if ((DAT_00879564 != 3) && (DAT_00879564 != 4)) {
      if (DAT_00879564 != 2) {
        __security_check_cookie(local_4 ^ (uint)&local_90);
        return;
      }
      DAT_00879b80 = DAT_0087b6c4;
      iVar7 = 2;
      DAT_00879b84 = DAT_0087b6c6;
      if (0 < DAT_00879598) {
        puVar13 = (undefined4 *)&DAT_008795a8;
        puVar15 = (undefined4 *)&DAT_00879b88;
        for (iVar7 = DAT_00879598; iVar7 != 0; iVar7 = iVar7 + -1) {
          *puVar15 = *puVar13;
          puVar13 = puVar13 + 1;
          puVar15 = puVar15 + 1;
        }
        iVar7 = iVar9 + 2;
      }
      fVar2 = _DAT_00879504;
      (&DAT_00879b80)[iVar7 * 2] = 0xffff;
      fVar2 = fVar2 - 0.1;
      if (fVar2 < fVar5 == (fVar2 == fVar5)) {
        local_88 = 1.0 - fVar5 / fVar2;
      }
      else {
        local_88 = (float)fVar18;
      }
      local_90 = local_88;
      FUN_00594c30(piVar10,(float)fVar18,_DAT_00804fb4,piVar10[4],&DAT_00879b80,local_88,1);
      FUN_00477630(piVar10,1,0x3f800000,local_88);
      __security_check_cookie(local_4 ^ (uint)&local_90);
      return;
    }
    iVar7 = 0;
    DAT_00879b80 = DAT_0087b6c4;
    iVar9 = 2;
    DAT_00879b88 = 0xffff;
    DAT_00879b84 = DAT_0087b6c6;
    if (0 < DAT_00879598) {
      do {
        iVar14 = FUN_00630680(&DAT_00879b80,(int)(short)(&DAT_008795a8)[iVar7 * 2],0);
        if (iVar14 == 0) {
          *(undefined4 *)(&DAT_00879b80 + iVar9 * 2) = *(undefined4 *)(&DAT_008795a8 + iVar7 * 2);
          iVar9 = iVar9 + 1;
          (&DAT_00879b80)[iVar9 * 2] = 0xffff;
        }
        iVar7 = iVar7 + 1;
      } while (iVar7 < DAT_00879598);
      fVar17 = (float10)1;
      fVar18 = (float10)0;
    }
    iVar7 = DAT_00879564;
    fVar5 = DAT_00879540;
    (&DAT_00879b80)[iVar9 * 2] = 0xffff;
    local_80 = fVar5 / _DAT_00879504;
    if (iVar7 == 3) {
      if (0.8 <= fVar5) {
        local_8c = (float)fVar18;
      }
      else {
        local_8c = 1.0 - fVar5 / 0.8;
      }
      FUN_00594c30(piVar10,(float)fVar18,_DAT_00804fb4,piVar10[4],&DAT_00879b80,local_8c,1);
      fVar17 = (float10)1;
      iVar7 = DAT_00879564;
    }
    local_8c = _DAT_007f9350;
    if (8 < iVar9) {
      local_8c = _DAT_007f9350 - (float)(iVar9 + -8) * 0.02;
    }
    if (local_8c < 0.1) {
      local_8c = 0.1;
    }
    local_7c[2] = local_8c / _DAT_00804fb0;
    local_88 = local_7c[2] * _DAT_00804fa4;
    if ((DAT_0093b0d8 != 0) && (*(char *)(DAT_0093b0d8 + 0xb) != '\0')) {
      local_88 = local_88 * 0.75;
    }
    local_7c[0] = (float)(iVar9 + -1);
    uVar8 = 0;
    local_5c[0] = local_7c[2] * _DAT_00804fa8 * 0.5 * 0.875;
    local_90 = -(local_88 * (float)(int)local_7c[0] * 0.5 * 0.5);
    local_54[0] = iVar9;
    if (iVar9 < 1) {
      __security_check_cookie(local_4 ^ (uint)&local_90);
      return;
    }
    local_4c = (double)(local_88 * 0.5);
    do {
      piVar10 = local_60;
      iVar9 = DAT_0093b0d8;
      local_7c[0] = (float)(int)(&DAT_00879b80)[uVar8 * 2];
      local_88 = local_5c[0];
      if ((uVar8 & 1) == 0) {
        local_88 = -local_5c[0];
      }
      if (iVar7 == 3) {
        if (uVar8 == 0) {
          local_84 = -_DAT_007fc31c;
          local_68 = _DAT_007fc310;
          local_7c[3] = _DAT_00804fb0;
          if (DAT_0087b6c8 == '\0') {
            cVar12 = -0x5a;
            local_64 = _DAT_007fc2d8;
          }
          else {
            cVar12 = -0x5a;
            local_64 = (float)fVar17;
          }
LAB_0047c8c4:
          local_6c = local_8c;
          if ((DAT_0093b0d8 != 0) && (*(char *)(DAT_0093b0d8 + 0xb) != '\0')) {
            local_6c = local_8c * 0.875;
          }
          iVar9 = FUN_006e6b90();
          fVar17 = (float10)1;
          fVar18 = (float10)(float)(fVar17 - ((float10)(float)(&DAT_029899a0)[iVar9 >> 1 & 0x7fff] +
                                             fVar17) * (float10)0.5);
          local_7c[2] = (float)(fVar18 * ((float10)local_90 - (float10)local_84) + (float10)local_84
                               );
          local_88 = (float)((float10)local_68 + fVar18 * ((float10)local_88 - (float10)local_68));
          local_84 = (float)((float10)local_7c[3] +
                            fVar18 * ((float10)local_6c - (float10)local_7c[3]));
          fVar18 = (fVar17 - (float10)local_64) * fVar18 + (float10)local_64;
          fVar17 = extraout_ST0_02;
          goto LAB_0047c9d4;
        }
        if (uVar8 == 1) {
          local_84 = _DAT_007fc31c;
          local_68 = _DAT_007fc310;
          local_7c[3] = _DAT_00804fb0;
          if (DAT_0087b6c9 == '\0') {
            cVar12 = -0x5b;
            local_64 = _DAT_007fc2d8;
          }
          else {
            cVar12 = -0x5b;
            local_64 = (float)fVar17;
          }
          goto LAB_0047c8c4;
        }
        iVar9 = FUN_00594250(local_7c[0],*local_60,*(undefined2 *)((int)local_60 + 6));
        if (iVar9 != -1) {
          iVar7 = *piVar10;
          local_84 = *(float *)(iVar7 + 0x14 + iVar9 * 0x1c);
          local_68 = *(float *)(iVar7 + iVar9 * 0x1c + 0x18);
          local_7c[3] = (float)piVar10[4] * _DAT_00804fb0;
          if ((DAT_0093b0d8 != 0) && (*(char *)(DAT_0093b0d8 + 0xb) != '\0')) {
            local_7c[3] = local_7c[3] * 0.875;
          }
          cVar12 = -0x59;
          local_64 = 1.0;
          goto LAB_0047c8c4;
        }
      }
      else {
        if (uVar8 == 0) {
          cVar12 = -0x5a;
        }
        else {
          cVar12 = (uVar8 != 1) * '\x02' + -0x5b;
        }
        iVar7 = FUN_006e6b90();
        local_7c[2] = (1.0 - (float)(&DAT_029899a0)[iVar7 >> 1 & 0x7fff]) +
                      (1.0 - (float)(&DAT_029899a0)[iVar7 >> 1 & 0x7fff]) + local_90;
        local_84 = (float)extraout_ST0_03;
        fVar18 = extraout_ST1_02;
        if ((iVar9 != 0) && (*(char *)(iVar9 + 0xb) != '\0')) {
          local_84 = (float)(extraout_ST0_03 * (float10)0.875);
        }
LAB_0047c9d4:
        local_6c = (float)fVar18;
        FUN_0055b830(local_7c[0],local_7c[2],local_88,(float)fVar17,local_84,cVar12,local_6c,
                     local_6c,1,0);
      }
      uVar8 = uVar8 + 1;
      local_90 = local_90 + (float)local_4c;
      if (local_54[0] <= (int)uVar8) {
        __security_check_cookie(local_4 ^ (uint)&local_90);
        return;
      }
      fVar17 = (float10)1;
      iVar7 = DAT_00879564;
    } while( true );
  }
  DAT_00879b80 = DAT_0087b6c4;
  DAT_00879b88 = 0xffff;
  DAT_00879b84 = DAT_0087b6c6;
  FUN_00594c30(piVar10,(float)fVar18,_DAT_00804fb4,piVar10[4],&DAT_00879b80,(float)fVar17,1);
  FUN_00477630(piVar10,1,0x3f800000,0x3f800000);
  iVar9 = 0;
  do {
    local_5c[iVar9] = -NAN;
    local_7c[iVar9] = -NAN;
    local_54[iVar9] = -1;
    uVar8 = iVar9 - 1U & 1;
    switch((&DAT_0087955c)[iVar9]) {
    case 0:
      if ((&DAT_00879b0c)[iVar9] <= 0.0) {
        local_5c[iVar9] = (float)(int)DAT_00880868;
        local_7c[iVar9] = (float)(int)DAT_00880824;
        local_54[iVar9] = (int)DAT_00880e8c;
      }
      break;
    case 1:
      if ((&DAT_00879b0c)[iVar9] <= 0.0) {
        local_5c[iVar9] = (float)(int)DAT_00880844;
        sVar3 = DAT_00880854;
        sVar4 = DAT_00880e90;
LAB_0047c41c:
        local_54[iVar9] = (int)sVar4;
        local_7c[iVar9] = (float)(int)sVar3;
      }
      break;
    case 2:
    case 3:
      if (((&DAT_0087b6c8)[uVar8] != '\0') &&
         (sVar3 = DAT_00880870, sVar4 = DAT_00880e94,
         (&DAT_0087955c)[uVar8] < (&DAT_0087955c)[iVar9])) goto LAB_0047c41c;
    }
    iVar9 = iVar9 + 1;
    if (1 < iVar9) {
      FUN_004b79a0(DAT_0087b6c8,local_5c[0],0x3f800000,0xffffffff,local_7c[0],0xffffffff,local_54[0]
                   ,DAT_0087b6c9,local_5c[1],0x3f800000,0xffffffff,local_7c[1],0xffffffff,
                   local_54[1]);
      __security_check_cookie(local_4 ^ (uint)&local_90);
      return;
    }
  } while( true );
}

