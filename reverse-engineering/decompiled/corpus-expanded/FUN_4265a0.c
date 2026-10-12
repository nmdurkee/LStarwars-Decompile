/* Ghidra pseudocode, not original source.
 * ev_e29f926c447264a3e79b54e28a3bd4babd6a11bd163f218199d416ac4d0e9917
 * Entry: 0x4265a0; label: FUN_004265a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004265a0(void)

{
  short sVar1;
  float fVar2;
  undefined2 extraout_var;
  uint uVar3;
  undefined4 extraout_ECX;
  uint uVar4;
  float fVar5;
  float fVar6;
  int iVar7;
  float fVar8;
  uint uVar9;
  float local_24 [3];
  int local_18;
  int local_14;
  float local_10 [4];
  
  if (((DAT_00921d24 == 0) && (DAT_008569ac == 0)) && (DAT_00856980 != 0)) {
    FUN_00425350(DAT_00856980);
    FUN_004246f0(local_10,&local_14);
    local_24[0] = _DAT_007fc2d8;
    if (DAT_0087b6c8 != '\0') {
      local_24[0] = 1.0;
    }
    FUN_0055b830((int)DAT_0087b6c4,-_DAT_007fc31c,_DAT_007fc310,0,_DAT_007fc318,0xa6,local_24[0],
                 local_24[0],1,0);
    local_24[0] = _DAT_007fc2d8;
    if (DAT_0087b6c9 != '\0') {
      local_24[0] = 1.0;
    }
    FUN_0055b830((int)DAT_0087b6c6,_DAT_007fc31c,_DAT_007fc310,0,_DAT_007fc318,0xa5,local_24[0],
                 local_24[0],1,0);
    sVar1 = DAT_00880864;
    iVar7 = DAT_008568f0;
    local_10[0] = (float)(int)DAT_00880730;
    if (local_14 != 1) {
      local_10[0] = -NAN;
    }
    local_24[0] = (float)(int)DAT_00880738;
    local_10[3] = -NAN;
    local_10[2] = -NAN;
    local_24[1] = local_24[0];
    local_10[1] = local_10[0];
    if (DAT_0093b338 == 0) {
      uVar9 = 0;
      do {
        uVar3 = uVar9;
        if ((local_14 == 1) && ((&DAT_0087b6ca)[uVar9] != '\0')) {
          uVar3 = (uint)(uVar9 == 0);
        }
        if ((&DAT_008568f0)[uVar3] == 1) {
          local_10[uVar9] = (float)(int)sVar1;
          local_24[uVar9 + 2] = -NAN;
          local_24[uVar9] = -NAN;
        }
        fVar2 = (float)FUN_004247d0(uVar3);
        local_10[uVar9 + 2] = fVar2;
        local_24[uVar9 + 2] = -NAN;
        if ((iVar7 != 1) && (DAT_008568f4 != 1)) {
          if (DAT_00856900 == 0) {
            local_24[uVar9 + 2] = (float)(int)DAT_00880824;
          }
          else {
            local_24[uVar9 + 2] = (float)(int)DAT_00880734;
          }
        }
        uVar9 = uVar9 + 1;
        fVar2 = local_24[1];
        fVar5 = local_10[1];
        fVar6 = local_10[0];
        fVar8 = local_24[0];
      } while ((int)uVar9 < 2);
    }
    else {
      fVar2 = local_24[0];
      fVar5 = local_10[0];
      fVar6 = local_10[0];
      fVar8 = local_24[0];
      if ((DAT_0087b6c8 == '\0') || (DAT_0087b6c9 == '\0')) {
        local_18 = (int)DAT_00880838;
        local_24[2] = (float)local_18;
      }
      else {
        sVar1 = DAT_00880740;
        if (DAT_0087b6cc != '\0') {
          fVar6 = -NAN;
          fVar8 = -NAN;
          sVar1 = DAT_00880870;
        }
        local_24[2] = (float)(int)sVar1;
        if (DAT_0087b6cd == '\0') {
          local_18 = (int)DAT_00880740;
        }
        else {
          local_18 = (int)DAT_00880870;
          fVar2 = -NAN;
          fVar5 = -NAN;
        }
      }
    }
    FUN_004b79a0(DAT_0087b6c8,fVar6,0x3f800000,fVar8,local_24[2],local_10[2],(int)DAT_00880e8c,
                 DAT_0087b6c9,fVar5,0x3f800000,fVar2,local_18,local_10[3],(int)DAT_00880e8c);
    local_24[0] = -_DAT_007fc31c;
    iVar7 = (-(uint)(DAT_009213e4 != 0) & 0xffffffc0) + 0xff;
    uVar9 = 0;
    do {
      uVar3 = uVar9;
      if ((local_14 == 1) && ((&DAT_0087b6ca)[uVar9] != '\0')) {
        uVar3 = (uint)(uVar9 == 0);
      }
      if (((&DAT_0087b6c8)[uVar9] != '\0') && ((&DAT_008568f0)[uVar3] != 1)) {
        local_24[2] = _DAT_007fc310 - 0.225;
        local_10[0] = 0.0;
        if (0.0 < (float)(&DAT_00856924)[uVar9]) {
          local_10[0] = 0.015000001;
        }
        local_10[0] = (local_24[0] - 0.05) - local_10[0];
        FUN_00511500(&DAT_007533c8,local_10[0],local_24[2],0x3f800000,0x3f000000,0x3f000000,
                     0x3f000000,0,iVar7,iVar7,iVar7);
        local_10[0] = 0.0;
        if (0.0 < (float)(&DAT_0085691c)[uVar9]) {
          local_10[0] = 0.015000001;
        }
        local_10[0] = local_24[0] + 0.05 + local_10[0];
        FUN_00511500(&DAT_007533c4,local_10[0],local_24[2],0x3f800000,0x3f000000,0x3f000000,
                     0x3f000000,0,iVar7,iVar7,iVar7);
        local_10[0] = 0.0;
        if (0.0 < (float)(&DAT_00856934)[uVar9]) {
          local_10[0] = -0.021000002;
        }
        uVar4 = CONCAT31((int3)((uint)extraout_ECX >> 8),((int)(&DAT_00856984)[uVar3] < 1) + -1) &
                0xffffff60;
        local_10[0] = (local_24[2] - -0.07) - local_10[0];
        FUN_0050c780(PTR_DAT_007f3a18,local_24[0],local_10[0],0x3f800000,0x3f000000,0x3f000000,
                     0x3f000000,0,iVar7,iVar7,iVar7,CONCAT31((int3)(uVar4 >> 8),(char)uVar4 + ' '));
        local_10[0] = 0.0;
        fVar2 = (float)(&DAT_00856870)[uVar9];
        if (0.0 < fVar2) {
          local_10[0] = -0.021000002;
        }
        uVar3 = CONCAT31((int3)(CONCAT22(extraout_var,
                                         (ushort)(0.0 < fVar2) << 8 | (ushort)NAN(fVar2) << 10 |
                                         (ushort)(fVar2 == 0.0) << 0xe) >> 8),
                         (7 < (int)(&DAT_00856984)[uVar3]) + -1) & 0xffffff60;
        local_10[0] = (local_24[2] - 0.07) + local_10[0];
        FUN_0050c780(PTR_DAT_007f3a1c,local_24[0],local_10[0],0x3f800000,0x3f000000,0x3f000000,
                     0x3f000000,0,iVar7,iVar7,iVar7,CONCAT31((int3)(uVar3 >> 8),(char)uVar3 + ' '));
        local_10[0] = _DAT_007fc310 - 0.375;
        FUN_0050d910(*(undefined4 *)(DAT_00926c20 + DAT_00880868 * 4),local_24[0],local_10[0],
                     0x3f800000,0x3e99999a,0x3e99999a,0x3e99999a,0,iVar7,iVar7,iVar7,0x3e19999a,1,0,
                     0,0x80);
      }
      uVar9 = uVar9 + 1;
      local_24[0] = _DAT_007fc31c + _DAT_007fc31c + local_24[0];
    } while ((int)uVar9 < 2);
  }
  return;
}

