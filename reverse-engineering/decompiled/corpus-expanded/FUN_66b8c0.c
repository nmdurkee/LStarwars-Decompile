/* Ghidra pseudocode, not original source.
 * ev_c3511c7e9be8c9ea3f86dbf498dc77cf8080442af45acd9c68d26e3bdf8b902d
 * Entry: 0x66b8c0; label: FUN_0066b8c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0066b8c0(undefined4 param_1,int *param_2,float param_3,undefined4 param_4,undefined4 param_5
                ,int param_6,undefined4 param_7,float param_8,float param_9,int param_10)

{
  uint *puVar1;
  short *psVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  int *piVar6;
  short *psVar7;
  int iVar8;
  undefined2 uVar9;
  float *pfVar10;
  ushort uVar11;
  float *pfVar12;
  short sVar13;
  uint uVar14;
  float *pfVar15;
  float *pfVar16;
  int *piVar17;
  int iVar18;
  undefined2 *puVar19;
  int iVar20;
  int iVar21;
  ushort *puVar22;
  byte bVar23;
  int iVar24;
  undefined4 *puVar25;
  float *pfVar26;
  float *pfVar27;
  float *pfVar28;
  float10 fVar29;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 extraout_ST0_01;
  float10 extraout_ST0_02;
  float10 extraout_ST0_03;
  float10 fVar30;
  float10 extraout_ST1;
  float10 extraout_ST1_00;
  float10 extraout_ST1_01;
  float10 extraout_ST1_02;
  float10 extraout_ST1_03;
  float10 fVar31;
  float local_30;
  int local_24;
  float local_20;
  float local_1c;
  
  iVar8 = (int)param_9;
  uVar14 = ((uint)param_3 & 0xfffffffe) + (int)param_9 * -2;
  pfVar15 = (float *)((uVar14 & 0xfffffffc) + (int)param_9 * -4);
  pfVar16 = pfVar15 + (int)param_9 * -2;
  iVar5 = *param_2;
  if (DAT_02962b30 == 0) {
    DAT_02962b30 = FUN_004eef40(0xc800,"d:\\projects\\legosagapc\\gameapi.saga\\gamelib\\terrain.c",
                                0x1d2);
  }
  if (DAT_02962b34 == 0) {
    DAT_02962b34 = FUN_004eef40(0xc800,"d:\\projects\\legosagapc\\gameapi.saga\\gamelib\\terrain.c",
                                0x1d4);
  }
  if (DAT_02947ca0 == 0) {
    DAT_02947ca0 = FUN_004eef40(0x2000,"d:\\projects\\legosagapc\\gameapi.saga\\gamelib\\terrain.c",
                                0x1d6);
  }
  if (DAT_0292fb50 == 0) {
    DAT_0292fb50 = FUN_004eef40(0x600,"d:\\projects\\legosagapc\\gameapi.saga\\gamelib\\terrain.c",
                                0x1d8);
  }
  piVar6 = (int *)*param_2;
  *param_2 = (int)(piVar6 + 0x2924);
  piVar6[0x2923] = param_10;
  piVar6[0x2921] = (int)param_8;
  piVar6[0x2922] = (int)param_9;
  *piVar6 = *param_2;
  *param_2 = *param_2 + ((int)param_9 + 0x80) * 0x38;
  piVar6[0x6ed] = *param_2;
  *param_2 = *param_2 + (int)param_8 * 2;
  piVar6[0x1a] = *param_2;
  *param_2 = *param_2 + piVar6[0x2923] * 0x6c;
  piVar17 = piVar6 + 0x6f1;
  iVar24 = 0x11;
  do {
    *(undefined2 *)(piVar17 + -3) = 0;
    *piVar17 = 0;
    piVar17 = piVar17 + 0x203;
    iVar24 = iVar24 + -1;
  } while (iVar24 != 0);
  _memset((void *)*piVar6,0,piVar6[0x2922] * 0x38);
  iVar24 = 0;
  if (0 < piVar6[0x2922]) {
    puVar25 = (undefined4 *)(*piVar6 + 0x2c);
    do {
      *puVar25 = 0xffffffff;
      iVar24 = iVar24 + 1;
      puVar25 = puVar25 + 0xe;
    } while (iVar24 < piVar6[0x2922]);
  }
  puVar19 = (undefined2 *)((int)piVar6 + 0x79a);
  iVar24 = 0x101;
  do {
    *puVar19 = 0;
    puVar19 = puVar19 + 10;
    iVar24 = iVar24 + -1;
  } while (iVar24 != 0);
  iVar24 = 0;
  if (0 < piVar6[0x2923]) {
    iVar18 = 0;
    do {
      *(undefined4 *)(iVar18 + 0x40 + piVar6[0x1a]) = 0;
      *(undefined4 *)(iVar18 + 0x44 + piVar6[0x1a]) = 0;
      *(undefined4 *)(iVar18 + 0x54 + piVar6[0x1a]) = 0;
      *(undefined4 *)(iVar18 + 0x58 + piVar6[0x1a]) = 0;
      *(undefined4 *)(iVar18 + 0x5c + piVar6[0x1a]) = 0;
      *(undefined4 *)(iVar18 + 100 + piVar6[0x1a]) = 0;
      *(undefined4 *)(iVar18 + 0x60 + piVar6[0x1a]) = 0;
      puVar1 = (uint *)(iVar18 + 0x4c + piVar6[0x1a]);
      *puVar1 = *puVar1 & 0xfffffffb;
      iVar24 = iVar24 + 1;
      iVar18 = iVar18 + 0x6c;
    } while (iVar24 < piVar6[0x2923]);
  }
  puVar19 = (undefined2 *)((int)piVar6 + 0x1a2);
  iVar24 = 0x40;
  do {
    *(undefined4 *)(puVar19 + -5) = 0;
    *puVar19 = 0;
    puVar19 = puVar19 + 0xc;
    iVar24 = iVar24 + -1;
  } while (iVar24 != 0);
  piVar6[0x19] = 0;
  piVar6[0x4b] = 0;
  piVar6[0x55] = 0;
  _DAT_02961fe0 = 0;
  DAT_0292fc64 = 0;
  DAT_0292119c = 0;
  local_24 = 0;
  DAT_0292fbf0 = 0;
  DAT_02947d88 = 0;
  DAT_0292125e = 0;
  DAT_02961f74 = 0xffffffff;
  sVar13 = FUN_0066b330(param_5,0,param_2,piVar6);
  *(short *)(piVar6 + 0x53) = sVar13;
  if (sVar13 < 0) {
    *param_2 = iVar5;
    return 0;
  }
  pfVar26 = (float *)*piVar6;
  piVar6[0x6eb] = 0x7fffffff;
  param_10 = 0;
  if (0 < sVar13) {
    do {
      fVar29 = (float10)1;
      fVar30 = (float10)0.707;
      if ((pfVar26[0xb] == 0.0) || (pfVar26[0xb] == 1.4013e-45)) {
        fVar31 = (float10)0;
        pfVar27 = (float *)pfVar26[3];
        sVar13 = *(short *)pfVar27;
        local_30 = (float)fVar31;
        param_2 = (int *)0x4d3ebc20;
        local_20 = 2e+08;
        param_3 = 2e+08;
        param_9 = -2e+08;
        local_1c = -2e+08;
        param_8 = -2e+08;
        while (-1 < sVar13) {
          pfVar12 = pfVar27 + 5;
          pfVar10 = pfVar27;
          for (iVar24 = (int)*(short *)((int)pfVar27 + 2); pfVar27 = pfVar12, 0 < iVar24;
              iVar24 = iVar24 + -1) {
            pfVar28 = pfVar10 + 0x19;
            if (((pfVar10[0x17] == -NAN) || (pfVar10[0x18] == -NAN)) || (*pfVar28 == -NAN)) {
              pfVar10[0x17] = (float)fVar31;
              *pfVar28 = (float)fVar31;
              pfVar10[0x18] = (float)fVar29;
            }
            if (((pfVar10[0x1a] == -NAN) || (pfVar10[0x1b] == -NAN)) || (pfVar10[0x1c] == -NAN)) {
              pfVar10[0x1a] = (float)fVar31;
              pfVar10[0x1c] = (float)fVar31;
              pfVar10[0x1b] = (float)fVar29;
            }
            if (0xef < *(byte *)((int)pfVar10 + 0x75)) {
              *(byte *)((int)pfVar10 + 0x77) =
                   *(byte *)((int)pfVar10 + 0x77) | (*(byte *)((int)pfVar10 + 0x75) + 0x11) * '\x04'
              ;
              *(undefined1 *)((int)pfVar10 + 0x75) = 0;
            }
            bVar23 = *(byte *)(pfVar10 + 0x1d);
            if (bVar23 == 0xff) {
              bVar23 = *(byte *)((int)pfVar10 + 0x75);
              *(byte *)((int)pfVar10 + 0x76) = *(byte *)((int)pfVar10 + 0x76) | 0x80;
              *(undefined1 *)((int)pfVar10 + 0x75) = 0;
LAB_0066bc4f:
              *(byte *)(pfVar10 + 0x1d) = bVar23;
            }
            else if ((char)bVar23 < '\0') {
              *(byte *)((int)pfVar10 + 0x76) = *(byte *)((int)pfVar10 + 0x76) | 0x40;
              bVar23 = bVar23 & 0x7f;
              goto LAB_0066bc4f;
            }
            if (*(short *)((int)piVar6 + 0x14e) == 0) {
              bVar23 = *(byte *)((int)pfVar10 + 0x77) & 0xfc;
              *(byte *)((int)pfVar10 + 0x77) = bVar23;
              if ((float10)pfVar10[0x18] <= fVar30) {
                *(byte *)((int)pfVar10 + 0x77) = bVar23 | 1;
              }
              if ((float10)pfVar10[0x1b] <= fVar30) {
                *(byte *)((int)pfVar10 + 0x77) = *(byte *)((int)pfVar10 + 0x77) | 2;
              }
            }
            if (*pfVar27 < (float)param_2) {
              param_2 = (int *)*pfVar27;
            }
            if (pfVar10[7] < local_20) {
              local_20 = pfVar10[7];
            }
            if (pfVar10[9] < param_3) {
              param_3 = pfVar10[9];
            }
            if (param_9 < pfVar10[6]) {
              param_9 = pfVar10[6];
            }
            if (local_1c < pfVar10[8]) {
              local_1c = pfVar10[8];
            }
            if (param_8 < pfVar10[10]) {
              param_8 = pfVar10[10];
            }
            if (pfVar10[0xc] + pfVar26[1] < (float)piVar6[0x6eb]) {
              fVar31 = fVar30;
              iVar18 = FUN_006e6b90();
              piVar6[0x6eb] = iVar18;
              fVar29 = extraout_ST0;
              fVar30 = extraout_ST1;
            }
            if (pfVar10[0xf] + pfVar26[1] < (float)piVar6[0x6eb]) {
              fVar31 = fVar30;
              iVar18 = FUN_006e6b90();
              piVar6[0x6eb] = iVar18;
              fVar29 = extraout_ST0_00;
              fVar30 = extraout_ST1_00;
            }
            if (pfVar10[0x12] + pfVar26[1] < (float)piVar6[0x6eb]) {
              fVar31 = fVar30;
              iVar18 = FUN_006e6b90();
              piVar6[0x6eb] = iVar18;
              fVar29 = extraout_ST0_01;
              fVar30 = extraout_ST1_01;
            }
            if (pfVar10[0x15] + pfVar26[1] < (float)piVar6[0x6eb]) {
              fVar31 = fVar30;
              iVar18 = FUN_006e6b90();
              piVar6[0x6eb] = iVar18;
              fVar29 = extraout_ST0_02;
              fVar30 = extraout_ST1_02;
            }
            fVar3 = pfVar10[0xd] * pfVar10[0xd] +
                    pfVar10[0xb] * pfVar10[0xb] + pfVar10[0xc] * pfVar10[0xc];
            if (local_30 < fVar3) {
              local_30 = fVar3;
            }
            fVar3 = pfVar10[0x10] * pfVar10[0x10] +
                    pfVar10[0xe] * pfVar10[0xe] + pfVar10[0xf] * pfVar10[0xf];
            if (local_30 < fVar3) {
              local_30 = fVar3;
            }
            fVar3 = pfVar10[0x13] * pfVar10[0x13] +
                    pfVar10[0x11] * pfVar10[0x11] + pfVar10[0x12] * pfVar10[0x12];
            if (local_30 < fVar3) {
              local_30 = fVar3;
            }
            fVar3 = pfVar10[0x16] * pfVar10[0x16] +
                    pfVar10[0x14] * pfVar10[0x14] + pfVar10[0x15] * pfVar10[0x15];
            if (local_30 < fVar3) {
              local_30 = fVar3;
            }
            pfVar12 = pfVar27 + 0x19;
            pfVar10 = pfVar28;
          }
          sVar13 = *(short *)pfVar27;
        }
        fVar30 = (float10)FUN_005c0240(local_30);
        pfVar26[0xd] = (float)fVar30;
        if (pfVar26[0xb] == 1.4013e-45) {
          pfVar26[4] = (float)param_2;
          pfVar26[5] = local_20;
          pfVar26[6] = param_3;
          pfVar26[7] = param_9;
          pfVar26[8] = local_1c;
        }
        else {
          pfVar26[4] = *pfVar26 + (float)param_2;
          pfVar26[5] = local_20 + pfVar26[1];
          pfVar26[6] = pfVar26[2] + param_3;
          pfVar26[7] = *pfVar26 + param_9;
          pfVar26[8] = local_1c + pfVar26[1];
          param_8 = pfVar26[2] + param_8;
        }
        _DAT_02961fe0 = _DAT_02961fe0 + 1;
        pfVar26[9] = param_8;
      }
      param_10 = param_10 + 1;
      pfVar26 = pfVar26 + 0xe;
    } while (param_10 < (short)piVar6[0x53]);
  }
  fVar30 = (float10)2e+08;
  fVar29 = (float10)-2e+08;
  fVar3 = (float)fVar30;
  pfVar26 = (float *)*piVar6;
  fVar4 = (float)fVar30;
  param_9 = (float)fVar29;
  param_8 = (float)fVar29;
  if (0 < (short)piVar6[0x53]) {
    param_10 = (int)(short)piVar6[0x53];
    pfVar27 = pfVar26;
    do {
      if (pfVar27[0xb] == 0.0) {
        psVar7 = (short *)pfVar27[3];
        sVar13 = *psVar7;
        while (-1 < sVar13) {
          if (*(float *)(psVar7 + 2) + *pfVar27 < fVar3) {
            fVar3 = *(float *)(psVar7 + 2) + *pfVar27;
          }
          if (param_9 < *(float *)(psVar7 + 4) + *pfVar27) {
            param_9 = *(float *)(psVar7 + 4) + *pfVar27;
          }
          if (*(float *)(psVar7 + 6) + pfVar27[2] < fVar4) {
            fVar4 = *(float *)(psVar7 + 6) + pfVar27[2];
          }
          if (param_8 < *(float *)(psVar7 + 8) + pfVar27[2]) {
            param_8 = *(float *)(psVar7 + 8) + pfVar27[2];
          }
          psVar2 = psVar7 + psVar7[1] * 0x32 + 10;
          psVar7 = psVar7 + psVar7[1] * 0x32 + 10;
          sVar13 = *psVar2;
        }
      }
      pfVar27 = pfVar27 + 0xe;
      param_10 = param_10 + -1;
    } while (param_10 != 0);
  }
  piVar6[0x54] = 0;
  param_10 = 0;
  if (0 < (short)piVar6[0x53]) {
    iVar24 = (int)pfVar16 + (iVar8 * -4 - (int)pfVar15);
    iVar18 = (int)pfVar16 - (int)pfVar15;
    pfVar27 = pfVar15;
    do {
      if (pfVar26[0xb] == 0.0) {
        psVar7 = (short *)pfVar26[3];
        *pfVar27 = (float)fVar30;
        *(float *)(iVar18 + (int)pfVar27) = (float)fVar30;
        pfVar27[-iVar8] = (float)fVar29;
        *(float *)(iVar24 + (int)pfVar27) = (float)fVar29;
        sVar13 = *psVar7;
        while (-1 < sVar13) {
          sVar13 = psVar7[1];
          if (*(float *)(psVar7 + 2) + *pfVar26 < *pfVar27) {
            *pfVar27 = *(float *)(psVar7 + 2) + *pfVar26;
          }
          if (pfVar27[-iVar8] < *(float *)(psVar7 + 4) + *pfVar26) {
            pfVar27[-iVar8] = *(float *)(psVar7 + 4) + *pfVar26;
          }
          if (*(float *)(psVar7 + 6) + pfVar26[2] < *(float *)(iVar18 + (int)pfVar27)) {
            *(float *)(iVar18 + (int)pfVar27) = *(float *)(psVar7 + 6) + pfVar26[2];
          }
          if (*(float *)(iVar24 + (int)pfVar27) < *(float *)(psVar7 + 8) + pfVar26[2]) {
            *(float *)(iVar24 + (int)pfVar27) = *(float *)(psVar7 + 8) + pfVar26[2];
          }
          psVar2 = psVar7 + sVar13 * 0x32 + 10;
          psVar7 = psVar7 + sVar13 * 0x32 + 10;
          sVar13 = *psVar2;
        }
        FUN_006e6b90();
        iVar20 = FUN_006e6b90();
        if (iVar20 < 0) {
          iVar20 = 0;
        }
        else if (6 < iVar20) {
          iVar20 = 6;
        }
        fVar30 = extraout_ST1_03;
        FUN_006e6b90();
        iVar21 = FUN_006e6b90();
        if (iVar21 < 0) {
          iVar21 = 0;
        }
        else if (6 < iVar21) {
          iVar21 = 6;
        }
        *(short *)(uVar14 + param_10 * 2) = (short)iVar21 * 7 + (short)iVar20;
        fVar29 = extraout_ST0_03;
      }
      param_10 = param_10 + 1;
      pfVar26 = pfVar26 + 0xe;
      pfVar27 = pfVar27 + 1;
    } while (param_10 < (short)piVar6[0x53]);
  }
  piVar6[0x6ec] = 0;
  param_10 = 0;
  do {
    param_2 = (int *)(float)fVar30;
    param_3 = (float)fVar30;
    *(short *)(piVar6 + piVar6[0x6ec] * 5 + 0x1e6) = (short)piVar6[0x54];
    param_9 = (float)fVar29;
    iVar24 = 0;
    param_8 = (float)fVar29;
    if (0 < (short)piVar6[0x53]) {
      piVar17 = (int *)(*piVar6 + 0x2c);
      iVar18 = (int)pfVar15 + (iVar8 * -4 - (int)pfVar16);
      pfVar26 = pfVar16;
      do {
        if ((*(short *)(uVar14 + iVar24 * 2) == param_10) && (*piVar17 == 0)) {
          if (*(float *)((int)pfVar26 + ((int)pfVar15 - (int)pfVar16)) < (float)param_2) {
            param_2 = *(int **)((int)pfVar26 + ((int)pfVar15 - (int)pfVar16));
          }
          if (*pfVar26 < param_3) {
            param_3 = *pfVar26;
          }
          if (param_9 < *(float *)(iVar18 + (int)pfVar26)) {
            param_9 = *(float *)(iVar18 + (int)pfVar26);
          }
          if (param_8 < pfVar26[-iVar8]) {
            param_8 = pfVar26[-iVar8];
          }
          psVar7 = (short *)((int)piVar6 + piVar6[0x6ec] * 0x14 + 0x79a);
          *psVar7 = *psVar7 + 1;
          *(short *)(piVar6[0x6ed] + piVar6[0x54] * 2) = (short)iVar24;
          piVar6[0x54] = piVar6[0x54] + 1;
        }
        iVar24 = iVar24 + 1;
        piVar17 = piVar17 + 0xe;
        pfVar26 = pfVar26 + 1;
      } while (iVar24 < (short)piVar6[0x53]);
    }
    if (*(short *)((int)piVar6 + piVar6[0x6ec] * 0x14 + 0x79a) != 0) {
      piVar6[piVar6[0x6ec] * 5 + 0x1e7] = (int)param_2;
      piVar6[piVar6[0x6ec] * 5 + 0x1e8] = (int)param_3;
      piVar6[piVar6[0x6ec] * 5 + 0x1e9] = (int)param_9;
      piVar6[(piVar6[0x6ec] + 0x62) * 5] = (int)param_8;
      piVar6[0x6ec] = piVar6[0x6ec] + 1;
    }
    param_10 = param_10 + 1;
  } while (param_10 < 0x31);
  *(short *)(piVar6 + 0x6e6) = (short)piVar6[0x54];
  param_10 = 0;
  if (0 < (short)piVar6[0x53]) {
    puVar22 = (ushort *)(*piVar6 + 0x30);
    do {
      if (*(int *)(puVar22 + -2) == 1) {
        if (local_24 < piVar6[0x2923]) {
          _DAT_0292fc5c = *puVar22;
          if ((param_6 != 0) && (*(int *)(param_6 + 0x58) != 0)) {
            _DAT_0292fc5c = *(ushort *)(*(int *)(param_6 + 0x5c) + (uint)_DAT_0292fc5c * 2);
          }
          uVar11 = _DAT_0292fc5c;
          uVar14 = (uint)_DAT_0292fc5c;
          *puVar22 = (ushort)local_24;
          if (param_6 != 0) {
            uVar9 = (undefined2)param_10;
            if (*(int *)(param_6 + 0x110) == 0) {
              if ((int)uVar14 < *(int *)(param_6 + 0x1c)) {
                *(undefined2 *)(piVar6[0x6ed] + piVar6[0x54] * 2) = uVar9;
                piVar6[0x54] = piVar6[0x54] + 1;
                *(short *)((int)piVar6 + 0x1b9a) = *(short *)((int)piVar6 + 0x1b9a) + 1;
                puVar1 = (uint *)((short)*puVar22 * 0x6c + 0x4c + piVar6[0x1a]);
                *puVar1 = *puVar1 ^ (*(uint *)(puVar22 + -4) ^ *puVar1) & 1;
                *(ushort *)((short)*puVar22 * 0x6c + 0x4a + piVar6[0x1a]) = uVar11;
                *(undefined2 *)((short)*puVar22 * 0x6c + 0x48 + piVar6[0x1a]) = uVar9;
                puVar1 = (uint *)((short)*puVar22 * 0x6c + 0x4c + piVar6[0x1a]);
                *puVar1 = *puVar1 & 0xfffffffb;
                iVar24 = uVar14 * 0x50;
                iVar8 = *(int *)(*(int *)(param_6 + 0x20) + 0x48 + iVar24);
                if (iVar8 == 0) {
                  *(int *)((short)*puVar22 * 0x6c + 0x40 + piVar6[0x1a]) =
                       *(int *)(param_6 + 0x20) + iVar24;
                }
                else {
                  *(int *)((short)*puVar22 * 0x6c + 0x40 + piVar6[0x1a]) = iVar8;
                }
                local_24 = local_24 + 1;
                *(int *)((short)*puVar22 * 0x6c + 0x68 + piVar6[0x1a]) =
                     *(int *)(param_6 + 0x20) + 0x44 + iVar24;
                goto LAB_0066c630;
              }
            }
            else {
              *(undefined2 *)(piVar6[0x6ed] + piVar6[0x54] * 2) = uVar9;
              piVar6[0x54] = piVar6[0x54] + 1;
              *(short *)((int)piVar6 + 0x1b9a) = *(short *)((int)piVar6 + 0x1b9a) + 1;
              puVar1 = (uint *)((short)*puVar22 * 0x6c + 0x4c + piVar6[0x1a]);
              *puVar1 = *puVar1 ^ (*(uint *)(puVar22 + -4) ^ *puVar1) & 1;
              *(ushort *)((short)*puVar22 * 0x6c + 0x4a + piVar6[0x1a]) = uVar11;
              *(undefined2 *)((short)*puVar22 * 0x6c + 0x48 + piVar6[0x1a]) = uVar9;
              puVar1 = (uint *)((short)*puVar22 * 0x6c + 0x4c + piVar6[0x1a]);
              *puVar1 = *puVar1 & 0xfffffffb;
              iVar8 = *(int *)(*(int *)(param_6 + 0x110) + 0x6c);
              iVar24 = 0;
              if (0 < iVar8) {
                iVar18 = *(int *)(*(int *)(param_6 + 0x110) + 0x70);
                do {
                  if (*(uint *)(iVar18 + 0xc0) == uVar14) {
                    iVar8 = *(int *)(iVar18 + 0xc4);
                    if ((iVar8 == -1) || (iVar8 == 0)) {
                      *(int *)((short)*puVar22 * 0x6c + 0x40 + piVar6[0x1a]) = iVar18 + 0x40;
                    }
                    else {
                      *(int *)((short)*puVar22 * 0x6c + 0x40 + piVar6[0x1a]) = iVar8;
                    }
                    *(int *)((short)*puVar22 * 0x6c + 0x68 + piVar6[0x1a]) =
                         iVar24 * 0xd0 + 0xb8 + *(int *)(*(int *)(param_6 + 0x110) + 0x70);
                    puVar1 = (uint *)((short)*puVar22 * 0x6c + 0x4c + piVar6[0x1a]);
                    *puVar1 = *puVar1 | 4;
                    local_24 = local_24 + 1;
                    goto LAB_0066c630;
                  }
                  iVar24 = iVar24 + 1;
                  iVar18 = iVar18 + 0xd0;
                } while (iVar24 < iVar8);
              }
            }
          }
        }
        puVar22[-0xffffffff00000002] = 0xffff;
        puVar22[-0xffffffff00000001] = 0xffff;
        puVar22 = (ushort *)FUN_0064fdb0(param_5);
      }
LAB_0066c630:
      param_10 = param_10 + 1;
      puVar22 = puVar22 + 0x1c;
    } while (param_10 < (short)piVar6[0x53]);
  }
  DAT_02947c60 = 0;
  return iVar5;
}

