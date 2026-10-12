/* Ghidra pseudocode, not original source.
 * ev_a581b26cc49c1240ca9fc8201471236b1c0a2571dfff42173a4e3442f2e0fd27
 * Entry: 0x4364e0; label: FUN_004364e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004364e0(int param_1,int param_2)

{
  uint *puVar1;
  byte *pbVar2;
  ushort *puVar3;
  char cVar4;
  byte bVar5;
  short sVar6;
  int iVar7;
  float fVar8;
  bool bVar9;
  byte bVar10;
  uint uVar11;
  int *piVar12;
  undefined4 uVar13;
  uint uVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  int *piVar19;
  uint uVar20;
  float10 extraout_ST0;
  float10 fVar21;
  float local_28;
  float local_24;
  float local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  int local_10 [4];
  
  iVar16 = param_2;
  bVar9 = false;
  if (param_2 == 5) {
    param_2 = 4;
  }
  if ((*(byte *)(param_1 + 0x1fc) & 0x80) != 0) {
    DAT_00951224 = DAT_00951224 + 1;
    DAT_0087b2d0 = DAT_0087b2d0 + 1;
  }
  FUN_00698a20(param_1 + 400,0);
  iVar15 = param_1 + 0x80;
  FUN_00698a20(iVar15,0);
  FUN_00698a20(param_1 + 0x19c,0);
  FUN_0054e7d0(param_1);
  FUN_004c0c80(PTR_DAT_00802c54,param_1);
  iVar17 = -1;
  local_10[0] = -1;
  local_10[1] = 0xffffffff;
  local_10[2] = 0xffffffff;
  local_10[3] = 0xffffffff;
  if (param_2 == 4) {
    FUN_00597350(param_1);
  }
  else {
    if ((*(uint *)(*(int *)(param_1 + 0x54) + 4) & 0x4000000) == 0) {
      if (*(code **)(*(int *)(param_1 + 0x54) + 0x18) == FUN_004b30e0) {
        local_10[0] = 0x4b;
        local_10[1] = 0x75;
      }
      else {
        sVar6 = *(short *)(param_1 + 0x1064);
        if (sVar6 == DAT_007f1910) {
          local_10[0] = 0x26;
          iVar17 = 0;
        }
        else if ((sVar6 == DAT_007f1920) || (sVar6 == DAT_007f18f8)) {
          local_10[1] = 0x82;
          local_10[2] = 0x85;
          local_10[3] = 0x84;
        }
        else if (sVar6 == DAT_007f18f4) {
          local_10[0] = 0x2c;
        }
        else if (sVar6 == DAT_007f1914) {
          FUN_00549bb0(PTR_DAT_008021b4,0x3f800000,0x3f800000,0x3f800000);
          FUN_0054a910(0x3f333333,0,0,0);
        }
        else if ((((((sVar6 == DAT_007f1a1c) || (sVar6 == DAT_007f1a24)) || (sVar6 == DAT_007f19a4))
                  || ((sVar6 == DAT_007f1970 || (sVar6 == DAT_007f1a28)))) ||
                 ((sVar6 == DAT_007f196c || ((sVar6 == DAT_007f1964 || (sVar6 == DAT_007f1a2c))))))
                || (sVar6 == DAT_007f195c)) {
          local_10[0] = 0x22;
          if ((*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_0087b1b4) &&
             (*(char *)(param_1 + 0x280) == -1)) {
            iVar18 = FUN_0054fa60();
            if (iVar18 < 0x8000) {
              uVar13 = 0xbf400000;
            }
            else {
              uVar13 = 0x3f400000;
            }
            FUN_00549de0(PTR_DAT_008021b4,uVar13,2,0);
            FUN_0054a910(0x3f800000,0x3dcccccd,0,0);
          }
        }
        else if (sVar6 == DAT_007f19a8) {
          local_10[0] = 0x22;
        }
        else if (sVar6 == DAT_007f18b0) {
          local_10[0] = 0x45;
          iVar17 = 1;
        }
        else if (sVar6 == DAT_007f191c) {
          FUN_00549bb0(PTR_DAT_008021b4,0x3f800000,0x3f800000,0x3f800000);
          FUN_0054a910(0x3f800000,0x3dcccccd,0,0);
          FUN_0056e5f0(iVar15,DAT_00950f60 * 0.6,0x3f000000,0,0xffffffff,0x807);
          iVar18 = FUN_0056e160(5);
          if (iVar18 == 0) {
            local_10[0] = 0x52;
            local_10[1] = 0x53;
            local_10[2] = 0x54;
            iVar17 = 3;
            FUN_00681f40("exp_thermalDet",iVar15);
          }
          else {
            local_10[0] = 0x7d;
            local_10[1] = 0x7e;
            FUN_00681f40("exp_thermalDet",iVar15);
          }
        }
        else if (sVar6 == DAT_007f18c4) {
          iVar17 = 5;
        }
        else if (sVar6 == DAT_007f18b4) {
          local_10[0] = 0x82;
          local_10[1] = 0x85;
        }
      }
    }
    else {
      local_10[0] = 0x49;
      local_10[1] = 0x4a;
      local_10[2] = 0x4b;
    }
    if (*(char *)(param_1 + 0x7b5) != '+') {
      FUN_00548460(param_1);
    }
    if ((*(byte *)(param_1 + 0x1fc) & 0x80) != 0) {
      FUN_0054a9b0(param_1);
    }
    if ((*(uint *)(*(int *)(param_1 + 0x54) + 4) & 0x2000) == 0) {
      local_28 = DAT_0093b0cc;
      local_24 = DAT_0093b0d0;
      local_20 = DAT_0093b0d4;
    }
    else {
      local_28 = *(float *)(param_1 + 0x68) * 0.5;
      local_24 = *(float *)(param_1 + 0x6c) * 0.5;
      local_20 = *(float *)(param_1 + 0x70) * 0.5;
    }
    iVar18 = 0;
    do {
      iVar7 = local_10[iVar18];
      if (iVar7 != -1) {
        if ((*(uint *)(*(int *)(param_1 + 0x54) + 4) & 0x2000) == 0) {
          FUN_0062c560(*(undefined4 *)(PTR_DAT_00802c54 + 0x134),iVar7,iVar15);
        }
        else {
          FUN_0062c5b0(*(undefined4 *)(PTR_DAT_00802c54 + 0x134),iVar7,iVar15,&local_28,&local_28);
        }
      }
      iVar18 = iVar18 + 1;
    } while (iVar18 < 4);
    if (iVar17 != -1) {
      FUN_00571b60(*(undefined4 *)(PTR_DAT_00802c54 + 0x138),iVar17,iVar15);
    }
    FUN_00597780(param_1);
  }
  if (((*(char *)(param_1 + 0x7b5) == '+') &&
      (*(undefined1 *)(param_1 + 0x7b5) = 0xff, (*(byte *)(param_1 + 0x1fc) & 0x80) != 0)) &&
     ((*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_0087b1dc ||
      (*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_0087b0d4)))) {
    FUN_0054a3e0(PTR_DAT_008021b4,0x3f000000,0,1);
  }
  if (param_2 == 4) {
    param_2 = 2;
    bVar9 = true;
  }
  else if ((*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_0087b234) &&
          (*(char *)(param_1 + 0x378) == '\x02')) {
    iVar15 = FUN_005aac00(DAT_0095df4c,"SpeedersKilled",0);
    if (iVar15 != 0) {
      *(float *)(iVar15 + 0x28) = *(float *)(iVar15 + 0x28) + 1.0;
    }
    DAT_00880558 = DAT_00880558 + 1;
  }
  if ((*(uint *)(*(int *)(param_1 + 0x54) + 4) & 0x2000) == 0) {
    fVar8 = 0.0;
    *(undefined4 *)(param_1 + 0x68) = 0;
  }
  else {
    *(float *)(param_1 + 0x68) = *(float *)(param_1 + 0x68) * 0.5;
    *(float *)(param_1 + 0x6c) = *(float *)(param_1 + 0x6c) * 0.5;
    fVar8 = *(float *)(param_1 + 0x70) * 0.5;
  }
  *(float *)(param_1 + 0x70) = fVar8;
  if (param_2 == 3) {
    param_2 = 2;
  }
  *(undefined1 *)(param_1 + 0x28b) = (undefined1)param_2;
  *(undefined1 *)(param_1 + 0x107f) = 0;
  if ((*(char *)(param_1 + 0x7b5) == '\a') || (*(char *)(param_1 + 0xe33) == '\x01')) {
    *(uint *)(param_1 + 0xe20) = *(uint *)(param_1 + 0xe20) | 0x10000;
  }
  else if ((*(char *)(param_1 + 0x7b5) == '\x06') || (*(char *)(param_1 + 0xe33) == '\x02')) {
    *(uint *)(param_1 + 0xe20) = *(uint *)(param_1 + 0xe20) & 0xfffeffff;
  }
  if (*(char *)(param_1 + 0x1082) != '\0') {
    FUN_00433aa0(param_1,1,0);
  }
  iVar15 = *(int *)(param_1 + 0xcd0);
  FUN_0055e4a0(param_1,1);
  if ((iVar15 != 0) && (bVar9)) {
    FUN_004364e0(iVar15,4,0);
  }
  FUN_0048ffc0(param_1);
  FUN_0055e4e0(param_1 + 0x6c4);
  if ((*(byte *)(param_1 + 0x1fc) & 0x80) != 0) {
    if (*(char **)(param_1 + 0xcc4) != (char *)0x0) {
      cVar4 = **(char **)(param_1 + 0xcc4);
      while (cVar4 != '\0') {
        FUN_00684c90(*(undefined4 *)(*(int *)(*(int *)(PTR_DAT_00802c54 + 0x134) + 8) + 0x58c),
                     *(byte **)(param_1 + 0xcc4) + (**(byte **)(param_1 + 0xcc4) + 5) * 0xc,0x1e,0,0
                    );
        **(char **)(param_1 + 0xcc4) = **(char **)(param_1 + 0xcc4) + -1;
        cVar4 = **(char **)(param_1 + 0xcc4);
      }
    }
    if ((((*(char *)(param_1 + 0x28b) == '\0') || ((*(byte *)(param_1 + 0x1fc) & 0x80) == 0)) ||
        ((*(uint *)(*(int *)(param_1 + 0x54) + 4) & 0x2000) == 0)) ||
       ((*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_0087b234 && (DAT_009253a4 == 0)))) {
      FUN_0054a3e0(PTR_DAT_008021b4,0x3f800000,0,1);
    }
    if ((*(uint *)(param_1 + 0x1f8) & 0x40000) == 0) {
      iVar15 = *(int *)(param_1 + 0xcd4);
      if ((iVar15 == 0) ||
         ((*(int *)(iVar15 + 0xcd0) != 0 && (*(int *)(iVar15 + 0xcd0) != param_1)))) {
        FUN_0055cd80(param_1);
      }
      else {
        FUN_004871a0(iVar15,&local_1c);
        *(undefined4 *)(param_1 + 0x8c) = local_1c;
        *(undefined4 *)(param_1 + 0x5c) = local_1c;
        *(undefined4 *)(param_1 + 0x10bc) = local_1c;
        *(undefined4 *)(param_1 + 0x90) = local_18;
        *(undefined4 *)(param_1 + 0x60) = local_18;
        *(undefined4 *)(param_1 + 0x10c0) = local_18;
        *(undefined4 *)(param_1 + 0x94) = local_14;
        *(undefined4 *)(param_1 + 100) = local_14;
        *(undefined4 *)(param_1 + 0x10c4) = local_14;
      }
    }
    FUN_0055d2b0(param_1);
    FUN_0052f800(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ae8),param_1,param_1 + 0x2c8,0xff,1);
  }
  *(undefined4 *)(param_1 + 0x1008) = 0;
  if ((*(char *)(param_1 + 0x28b) != '\x02') &&
     (*(undefined1 *)(param_1 + 0x28b) = 1, *(char *)(param_1 + 0x28b) != '\x02')) {
    *(undefined1 *)(param_1 + 0x28b) = 1;
  }
  if (*(char *)(param_1 + 0x28b) == '\x01') {
    *(undefined4 *)(param_1 + 0x8c) = *(undefined4 *)(param_1 + 0x5c);
    *(undefined4 *)(param_1 + 0x90) = *(undefined4 *)(param_1 + 0x60);
    *(undefined4 *)(param_1 + 0x94) = *(undefined4 *)(param_1 + 100);
  }
  if (*(char *)(param_1 + 0x28b) == '\x02') {
    *(undefined4 *)(param_1 + 0x100c) = 0;
  }
  else {
    *(undefined4 *)(param_1 + 0x100c) = 0x3f000000;
  }
  if (*(float *)(param_1 + 0x100c) <= 0.0) {
    *(undefined2 *)(param_1 + 0xe18) = 0;
  }
  if (!bVar9) {
    iVar15 = param_1 + 0x2c8;
    iVar17 = FUN_0052c790(iVar15,"BeenKilled");
    if (iVar17 != 0) {
      FUN_0052cc90(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ae8),param_1,iVar15,iVar15,_DAT_00925018);
    }
  }
  fVar21 = (float10)0;
  iVar15 = *(int *)(param_1 + 0x40c);
  if (iVar15 != 0) {
    uVar11 = __allshl();
    puVar1 = (uint *)(iVar15 + 0x4c);
    *puVar1 = *puVar1 & ~uVar11;
    bVar5 = *(byte *)(param_1 + 0x412);
    iVar15 = *(int *)(param_1 + 0x40c);
    bVar10 = __allshl();
    pbVar2 = (byte *)((uint)bVar5 * 0x34 + iVar15 + 0x81);
    *pbVar2 = *pbVar2 & ~bVar10;
    fVar21 = extraout_ST0;
    if (**(int **)(param_1 + 0x40c) == param_1) {
      **(int **)(param_1 + 0x40c) = 0;
      piVar12 = *(int **)(param_1 + 0x40c);
      if ((*(byte *)(piVar12 + 0x14) & 4) == 0) {
        iVar15 = 0;
        if (*(char *)((int)piVar12 + 7) != '\0') {
          iVar17 = 0xc;
          do {
            piVar12 = (int *)(*(int *)(param_1 + 0x40c) + iVar17);
            if (*piVar12 != 0) {
              iVar18 = *(int *)*piVar12;
              if (iVar18 == 0) {
                *piVar12 = 0;
              }
              else if ((((param_1 != iVar18) && ((*(uint *)(iVar18 + 0x1fc) & 1) != 0)) &&
                       ((*(uint *)(iVar18 + 0x1fc) & 0x1000) != 0)) &&
                      (*(char *)(iVar18 + 0x28b) == '\0')) {
                **(int **)(param_1 + 0x40c) = iVar18;
                break;
              }
            }
            iVar15 = iVar15 + 1;
            iVar17 = iVar17 + 4;
          } while (iVar15 < (int)(uint)*(byte *)(*(int *)(param_1 + 0x40c) + 7));
        }
      }
      else {
        iVar15 = *(byte *)((int)piVar12 + 7) - 1;
        if (-1 < iVar15) {
          piVar19 = piVar12 + *(byte *)((int)piVar12 + 7) + 2;
          do {
            if (((*piVar19 != 0) && (iVar17 = *(int *)*piVar19, param_1 != iVar17)) &&
               (((*(uint *)(iVar17 + 0x1fc) & 1) != 0 &&
                (((*(uint *)(iVar17 + 0x1fc) & 0x1000) != 0 && (*(char *)(iVar17 + 0x28b) == '\0')))
                ))) {
              *piVar12 = iVar17;
              break;
            }
            iVar15 = iVar15 + -1;
            piVar19 = piVar19 + -1;
          } while (-1 < iVar15);
        }
      }
    }
  }
  *(uint *)(param_1 + 0x4b0) = *(uint *)(param_1 + 0x4b0) & 0xffffafff;
  *(undefined4 *)(param_1 + 0x3a8) = 0x4e6e6b28;
  *(undefined4 *)(param_1 + 0x3b8) = 0x4e6e6b28;
  *(undefined4 *)(param_1 + 0x39c) = 0;
  *(float *)(param_1 + 0xec4) = (float)fVar21;
  *(undefined4 *)(param_1 + 0x3a4) = 0;
  *(undefined4 *)(param_1 + 0x3b4) = 0;
  *(undefined4 *)(param_1 + 0x2a8) = 0;
  *(undefined4 *)(param_1 + 0x2ac) = 0;
  *(undefined4 *)(param_1 + 0xeb0) = 0;
  *(undefined4 *)(param_1 + 0xeb4) = 0;
  *(undefined4 *)(param_1 + 0x10a4) = 0;
  *(undefined4 *)(param_1 + 0x3ac) = 0;
  *(undefined4 *)(param_1 + 0xec0) = 0;
  if (*(int *)(param_1 + 0xea4) != 0) {
    *(undefined4 *)(*(int *)(param_1 + 0xea4) + 0xea4) = 0;
    *(undefined4 *)(param_1 + 0xea4) = 0;
  }
  if ((*(char *)(param_1 + 0x7b5) == 'G') && (*(int *)(param_1 + 0x798) != 0)) {
    puVar3 = (ushort *)(*(int *)(param_1 + 0x798) + 0x68);
    *puVar3 = *puVar3 & 0xfeff;
    *(undefined4 *)(param_1 + 0x798) = 0;
  }
  FUN_00404e30(param_1);
  FUN_0058b0f0(param_1);
  FUN_0049c4e0(param_1);
  FUN_0058ff10(param_1,0);
  FUN_0059cb00(param_1);
  iVar17 = 0;
  iVar15 = DAT_0093d504;
  if (0 < DAT_0093d500) {
    do {
      if ((((*(uint *)(iVar15 + 0x1fc) & 1) != 0) && ((*(uint *)(iVar15 + 0x1fc) & 0x1000) != 0)) &&
         (iVar15 != param_1)) {
        if (*(char *)(iVar15 + 0x7b5) == '\x1b') {
          if (*(int *)(iVar15 + 0x790) == param_1) {
            FUN_004a25b0(iVar15,0);
            goto LAB_00436f72;
          }
        }
        else {
LAB_00436f72:
          if (*(int *)(iVar15 + 0x790) == param_1) {
            *(undefined4 *)(iVar15 + 0x790) = 0;
          }
        }
        if (*(int *)(iVar15 + 0xd1c) == param_1) {
          *(undefined4 *)(iVar15 + 0xd1c) = 0;
        }
      }
      iVar17 = iVar17 + 1;
      iVar15 = iVar15 + 0x10d8;
    } while (iVar17 < DAT_0093d500);
  }
  FUN_004a25b0(param_1,0);
  if (*(char *)(param_1 + 0x280) == -1) {
    piVar12 = &DAT_00951cec;
    iVar15 = 0x20;
    do {
      if (((char)piVar12[0x3f] != '\0') && (*piVar12 == param_1)) {
        *piVar12 = 0;
      }
      piVar12 = piVar12 + 0x4e;
      iVar15 = iVar15 + -1;
    } while (iVar15 != 0);
    if (0 < DAT_0081020c) {
      piVar12 = (int *)(DAT_0291f664 + 0xd4);
      iVar15 = 0;
      do {
        if (((*(byte *)(piVar12 + 0x1c) & 1) != 0) && (*piVar12 == param_1)) {
          *piVar12 = 0;
        }
        iVar15 = iVar15 + 1;
        piVar12 = piVar12 + 0x88;
      } while (iVar15 < DAT_0081020c);
    }
    if ((DAT_00950db4 < DAT_00950db8) && (DAT_00950da0 == param_1)) {
      DAT_00950da0 = 0;
    }
    if ((DAT_00950dec < DAT_00950df0) && (DAT_00950dd8 == param_1)) {
      DAT_00950dd8 = 0;
    }
    if ((_DAT_00950e24 < _DAT_00950e28) && (DAT_00950e10 == param_1)) {
      DAT_00950e10 = 0;
    }
    if ((_DAT_00950e5c < _DAT_00950e60) && (DAT_00950e48 == param_1)) {
      DAT_00950e48 = 0;
    }
    if ((_DAT_00950e94 < _DAT_00950e98) && (DAT_00950e80 == param_1)) {
      DAT_00950e80 = 0;
    }
    if ((_DAT_00950ecc < _DAT_00950ed0) && (DAT_00950eb8 == param_1)) {
      DAT_00950eb8 = 0;
    }
    if ((_DAT_00950f04 < _DAT_00950f08) && (DAT_00950ef0 == param_1)) {
      DAT_00950ef0 = 0;
    }
    if ((_DAT_00950f3c < _DAT_00950f40) && (DAT_00950f28 == param_1)) {
      DAT_00950f28 = 0;
    }
  }
  if ((((DAT_0087b0f8 != 0) && (iVar15 = FUN_0055f450(), *(int *)(iVar15 + 0x128) == DAT_0087b0f8))
      && (DAT_007f3b14 == -1)) && ((*(uint *)(param_1 + 0x1f8) & 0x40000) == 0)) {
    uVar13 = FUN_0055f450("EP3_DOGFIGHT_DIE",1);
    FUN_0057a620(uVar13);
  }
  if ((!bVar9) || (*(char *)(param_1 + 0x280) != -1)) goto LAB_00437328;
  if (iVar16 == 5) {
LAB_00437317:
    *(uint *)(param_1 + 0x1fc) = *(uint *)(param_1 + 0x1fc) & 0xffffefff;
    *(undefined1 *)(param_1 + 0x406) = 4;
    goto LAB_00437328;
  }
  uVar20 = *(uint *)(param_1 + 0xeec) >> 0x14 & 1;
  uVar11 = 0;
  iVar16 = 0;
  if (((*(uint *)(param_1 + 0x1f8) & 0x4000) == 0) || ((*(uint *)(param_1 + 0x1f8) & 0x400) == 0)) {
LAB_00437254:
    if (uVar20 == 0) goto LAB_00437317;
LAB_0043725c:
    if (uVar11 != 0) goto LAB_00437264;
  }
  else {
    iVar16 = (uint)*(byte *)(param_1 + 0x400) * 0xa4 +
             *(int *)(*(int *)(PTR_DAT_00802c54 + 0x2ae8) + 0x18);
    uVar11 = *(uint *)(param_1 + 0xeec) >> 0x15 & 1;
    if (uVar20 != 0) goto LAB_0043725c;
    if ((*(char *)(iVar16 + 0x86) == -1) || (*(int *)(param_1 + 0x478) != 0)) {
      uVar14 = *(int *)(param_1 + 0x4c4) + 1;
    }
    else {
      uVar14 = (int)(((int)*(char *)(iVar16 + 0x86) - (int)*(char *)(iVar16 + 0x85)) *
                    (DAT_008668c8._1_1_ - 1)) / 9 + 1 + (int)*(char *)(iVar16 + 0x85);
    }
    if (uVar14 <= *(uint *)(param_1 + 0x4c4)) goto LAB_00437254;
LAB_00437264:
    if (iVar16 != 0) {
      *(uint *)(param_1 + 0x1fc) = *(uint *)(param_1 + 0x1fc) & 0xffffefff;
      *(undefined1 *)(param_1 + 0x406) = 1;
      fVar8 = 1.0 - ((float)DAT_008668c8._1_1_ - 1.0) / 9.0;
      *(float *)(param_1 + 0x4c8) = fVar8;
      if ((*(float *)(iVar16 + 0x88) <= 0.0) || (*(float *)(iVar16 + 0x8c) <= 0.0)) {
        iVar16 = FUN_0054fa60();
        *(float *)(param_1 + 0x4c8) =
             ((float)iVar16 * 1.5259022e-05 + (float)iVar16 * 1.5259022e-05) *
             *(float *)(param_1 + 0x4c8);
      }
      else {
        *(float *)(param_1 + 0x4c8) =
             fVar8 * *(float *)(iVar16 + 0x8c) + *(float *)(iVar16 + 0x88) * (1.0 - fVar8);
      }
      goto LAB_00437328;
    }
  }
  *(undefined4 *)(param_1 + 0x1010) = 0x3f800000;
LAB_00437328:
  if ((*(int *)(param_1 + 0xcc4) != 0) && (*(char *)(param_1 + 0x280) == -1)) {
    FUN_004d22f0((undefined4 *)(param_1 + 0xcc4));
    *(undefined4 *)(param_1 + 0xcc4) = 0;
  }
  if ((DAT_00951288 != 0) &&
     ((cVar4 = *(char *)(param_1 + 0x280), cVar4 == '\0' || (cVar4 == '\x01')))) {
    FUN_00684400(&DAT_007f5dc4 + cVar4 * 4);
  }
  return 1;
}

