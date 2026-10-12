/* Ghidra pseudocode, not original source.
 * ev_d4a7937fff77c5bbe199b0bfbeb7b7598feaf173902b06fa34e0deca16dde16c
 * Entry: 0x68ee40; label: FUN_0068ee40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0068ee40(int param_1,int param_2)

{
  float *pfVar1;
  short *psVar2;
  float *pfVar3;
  uint *puVar4;
  short sVar5;
  short *psVar6;
  float fVar7;
  int iVar8;
  int iVar9;
  float *pfVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  float fVar14;
  float10 fVar15;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  
  iVar8 = DAT_0292186c;
  if ((((*(short **)(DAT_0292186c + 0x8c) == (short *)0x0) ||
       (**(short **)(DAT_0292186c + 0x8c) == 0)) || (DAT_02947c74 == 0)) ||
     ((*(short *)(DAT_02947c74 + 8) == 0 || (_DAT_00810b30 == 0.0)))) {
    return param_1;
  }
  iVar9 = FUN_006de8d0(0x948);
  psVar6 = *(short **)(iVar8 + 0x8c);
  psVar2 = (short *)(iVar9 + 0x148);
  sVar5 = *psVar6;
  DAT_0292186c = iVar9;
  while (0 < sVar5) {
    *psVar2 = sVar5;
    iVar13 = (int)sVar5;
    psVar2[1] = psVar6[1];
    while( true ) {
      psVar6 = psVar6 + 2;
      psVar2 = psVar2 + 2;
      if (iVar13 < 1) break;
      *psVar2 = *psVar6;
      psVar2[1] = psVar6[1];
      iVar13 = iVar13 + -1;
    }
    sVar5 = *psVar6;
  }
  *psVar2 = 0;
  psVar2[1] = 0;
  *(undefined4 *)(iVar9 + 0x50) = *(undefined4 *)(iVar8 + 0x50);
  pfVar10 = (float *)(iVar9 + 0xc0);
  *(undefined4 *)(iVar9 + 0x5c) = *(undefined4 *)(iVar8 + 0x5c);
  *(undefined4 *)(iVar9 + 0x68) = *(undefined4 *)(iVar8 + 0x68);
  *(undefined4 *)(iVar9 + 0x58) = *(undefined4 *)(iVar8 + 0x58);
  *(undefined4 *)(iVar9 + 0xa0) = *(undefined4 *)(iVar8 + 0xa0);
  *(undefined4 *)(iVar9 + 100) = *(undefined4 *)(iVar8 + 100);
  *(undefined4 *)(iVar9 + 0xa4) = *(undefined4 *)(iVar8 + 0xa4);
  *(undefined4 *)(iVar9 + 0x54) = *(undefined4 *)(iVar8 + 0x54);
  *(undefined4 *)(iVar9 + 0x60) = *(undefined4 *)(iVar8 + 0x60);
  *pfVar10 = *(float *)(iVar8 + 0x1c);
  *(undefined4 *)(iVar9 + 0xc4) = *(undefined4 *)(iVar8 + 0x20);
  *(undefined4 *)(iVar9 + 200) = *(undefined4 *)(iVar8 + 0x24);
  iVar11 = DAT_02947c74;
  iVar13 = iVar9;
  if ((DAT_02947c74 != 0) && ((*(byte *)(DAT_02947c74 + 6) & 1) != 0)) {
    iVar12 = *(short *)(DAT_02947c74 + 4) * 0x6c + DAT_0292fc68[0x1a];
    if ((*(byte *)(iVar12 + 0x4c) & 1) == 0) {
      iVar12 = *(short *)(DAT_02947c74 + 4) * 0x6c + DAT_0292fc68[0x1a];
      *(float *)(iVar9 + 0xc0) =
           (*(float *)(*(int *)(iVar12 + 0x40) + 0x30) - *(float *)(iVar12 + 0x30)) +
           *(float *)(iVar9 + 0xc0);
      iVar12 = *(short *)(iVar11 + 4) * 0x6c + DAT_0292fc68[0x1a];
      *(float *)(iVar9 + 0xc4) =
           (*(float *)(*(int *)(iVar12 + 0x40) + 0x34) - *(float *)(iVar12 + 0x34)) *
           *(float *)(iVar8 + 100) + *(float *)(iVar9 + 0xc4);
      iVar11 = *(short *)(iVar11 + 4) * 0x6c + DAT_0292fc68[0x1a];
      *(float *)(iVar9 + 200) =
           (*(float *)(*(int *)(iVar11 + 0x40) + 0x38) - *(float *)(iVar11 + 0x38)) +
           *(float *)(iVar9 + 200);
    }
    else {
      FUN_005b5b90(&DAT_0292fdd0,iVar12);
      _DAT_02921874 =
           *(float *)(iVar8 + 0x1c) -
           *(float *)(*(short *)(DAT_02947c74 + 4) * 0x6c + 0x30 + DAT_0292fc68[0x1a]);
      _DAT_02921878 =
           (*(float *)(iVar8 + 0x20) - *(float *)(DAT_0292186c + 0x50)) *
           *(float *)(DAT_0292186c + 0x5c) -
           *(float *)(*(short *)(DAT_02947c74 + 4) * 0x6c + 0x34 + DAT_0292fc68[0x1a]);
      _DAT_0292187c =
           *(float *)(iVar8 + 0x24) -
           *(float *)(*(short *)(DAT_02947c74 + 4) * 0x6c + 0x38 + DAT_0292fc68[0x1a]);
      _DAT_02921880 = 0x3f800000;
      FUN_005c03e0(&DAT_02921874,&DAT_02921874,&DAT_0292fdd0);
      FUN_005c03e0(&DAT_02921874,&DAT_02921874,
                   *(undefined4 *)(*(short *)(DAT_02947c74 + 4) * 0x6c + 0x40 + DAT_0292fc68[0x1a]))
      ;
      iVar13 = DAT_0292186c;
      pfVar10 = (float *)(DAT_0292186c + 0xc0);
      *pfVar10 = _DAT_02921874;
      *(float *)(iVar13 + 0xc4) =
           *(float *)(iVar13 + 100) * _DAT_02921878 + *(float *)(iVar13 + 0x50);
      *(float *)(iVar13 + 200) = _DAT_0292187c;
    }
  }
  *(float *)(iVar13 + 0xcc) = *pfVar10;
  *(undefined4 *)(iVar13 + 0x28) = 0;
  fVar7 = pfVar10[1];
  *(undefined4 *)(iVar13 + 0x30) = 0;
  *(float *)(iVar13 + 0xd0) = fVar7;
  *(float *)(iVar13 + 0xd4) = pfVar10[2];
  *(float *)(iVar13 + 0x1c) = *pfVar10;
  fVar7 = pfVar10[2];
  *(float *)(iVar13 + 0x20) = pfVar10[1];
  *(float *)(iVar13 + 0x24) = fVar7;
  fVar7 = _DAT_00810b30;
  *(float *)(iVar13 + 0x20) = _DAT_00810b30 + *(float *)(iVar13 + 0x20);
  *(float *)(iVar13 + 0x2c) = fVar7 * -2.0;
  FUN_0066f8f0();
  local_28 = *(float *)(DAT_0292186c + 0xa0);
  *(undefined4 *)(DAT_0292186c + 0xa0) = 0;
  FUN_00675240();
  FUN_0067a3b0();
  *(float *)(DAT_0292186c + 0xa0) = local_28;
  FUN_00678410();
  FUN_00678f60(&local_28);
  if (*(char *)(DAT_0292186c + 0x88) != '\0') {
    DAT_0292fdb8 = *(undefined4 *)(DAT_0292186c + 0xb4);
    DAT_0292fdbc = *(undefined4 *)(DAT_0292186c + 0xb8);
    DAT_0292fdc0 = *(undefined4 *)(DAT_0292186c + 0xbc);
  }
  pfVar10 = (float *)(DAT_0292186c + 0x20);
  pfVar1 = (float *)(DAT_0292186c + 0x50);
  pfVar3 = (float *)(DAT_0292186c + 0xc4);
  DAT_0292186c = iVar8;
  *pfVar3 = *pfVar10 - *pfVar1;
  if (*(char *)(iVar9 + 0x88) != '\0') {
    fVar7 = _DAT_00810b30 * 0.5;
    local_24 = ABS((*(float *)(iVar9 + 0xd0) - *(float *)(iVar9 + 0xc4)) - *(float *)(iVar8 + 0x50))
    ;
    if ((local_24 <= fVar7) && (0.707 <= *(float *)(iVar9 + 0xac))) {
      sVar5 = *(short *)(iVar9 + 0x6c);
      fVar14 = (float)(int)*(short *)(*DAT_0292fc68 + 0x30 + sVar5 * 0x38);
      iVar13 = *DAT_0292fc68 + sVar5 * 0x38;
      if ((*(float *)(param_2 + 4) <= fVar7) ||
         (iVar11 = DAT_0292fc68[0x1a] + (int)fVar14 * 0x6c, local_24 = fVar14,
         *(float *)(param_2 + 4) <=
         (*(float *)(*(int *)(iVar11 + 0x40) + 0x34) + fVar7) - *(float *)(iVar11 + 0x34))) {
        if (((0.707 < *(float *)(iVar9 + 0xac) != (*(float *)(iVar9 + 0xac) == 0.707)) &&
            (-1 < sVar5)) && (*(int *)(iVar13 + 0x2c) == 1)) {
          puVar4 = (uint *)(*(short *)(iVar13 + 0x30) * 0x6c + 0x4c + DAT_0292fc68[0x1a]);
          *puVar4 = *puVar4 | 2;
        }
        iVar13 = DAT_02947c74;
        *(undefined4 *)(iVar8 + 0xc0) = *(undefined4 *)(iVar9 + 0xc0);
        fVar7 = *(float *)(iVar8 + 0x50) + *(float *)(iVar9 + 0xc4);
        if ((*(byte *)(*(short *)(iVar13 + 4) * 0x6c + 0x4c + DAT_0292fc68[0x1a]) & 1) == 0) {
          fVar7 = fVar7 + 0.0025;
        }
        *(float *)(iVar8 + 0xc4) = fVar7;
        local_18 = *(float *)(iVar9 + 200);
        *(float *)(iVar8 + 200) = local_18;
        local_20 = *(float *)(iVar8 + 0xc0) - *(float *)(iVar8 + 0x1c);
        local_1c = *(float *)(iVar8 + 0xc4) - *(float *)(iVar8 + 0x20);
        local_18 = local_18 - *(float *)(iVar8 + 0x24);
        local_24 = local_18 * local_18 + local_20 * local_20 + local_1c * local_1c;
        fVar15 = (float10)FUN_005c0240(local_24);
        local_14 = (float)fVar15;
        fVar15 = (float10)FUN_0064fde0(local_20,local_14);
        local_20 = (float)fVar15;
        fVar15 = (float10)FUN_0064fde0(local_1c,local_14);
        local_1c = (float)fVar15;
        fVar15 = (float10)FUN_0064fde0(local_18,local_14);
        local_18 = (float)fVar15;
        local_10 = *(float *)(DAT_0292186c + 0x1c);
        local_c = *(float *)(DAT_0292186c + 0x20);
        local_8 = *(float *)(DAT_0292186c + 0x24);
        iVar11 = FUN_00679080(DAT_0292186c + 0xc0,DAT_0292186c + 0xcc,fVar14,1,0);
        iVar13 = DAT_0292186c;
        if ((*(char *)(DAT_0292186c + 0x88) != '\0') &&
           (sVar5 = *(short *)(DAT_0292186c + 0x6c), -1 < sVar5)) {
          if (*(int *)(*DAT_0292fc68 + 0x2c + sVar5 * 0x38) == 1) {
            *(undefined2 *)(DAT_02947c74 + 4) = *(undefined2 *)(*DAT_0292fc68 + sVar5 * 0x38 + 0x30)
            ;
          }
          if (*(float *)(iVar13 + 0xd4) * local_18 +
              *(float *)(iVar13 + 0xcc) * local_20 + *(float *)(iVar13 + 0xd0) * local_1c < -0.7) {
            iVar11 = 1;
          }
        }
        if (iVar11 == 0) {
          if ((0 < param_1 + -1) &&
             (local_28 = (*(float *)(iVar13 + 0x1c) - local_10) * local_20 +
                         (*(float *)(iVar13 + 0x20) - local_c) * local_1c +
                         (*(float *)(iVar13 + 0x24) - local_8) * local_18, local_28 < local_14)) {
            pfVar10 = (float *)(iVar13 + 0xc0);
            iVar9 = FUN_00678070(iVar13 + 0xcc,&local_20,pfVar10);
            if ((iVar9 != 0) &&
               ((local_24 = *(float *)(iVar13 + 200) * local_18 +
                            *pfVar10 * local_20 + *(float *)(iVar13 + 0xc4) * local_1c,
                0.0 < local_24 && (local_24 = (local_14 - local_28) / local_24, local_24 < 0.8)))) {
              *pfVar10 = *pfVar10 * local_24 + *(float *)(iVar13 + 0x1c);
              *(float *)(iVar13 + 0xc4) =
                   *(float *)(iVar13 + 0xc4) * local_24 + *(float *)(iVar13 + 0x20);
              *(float *)(iVar13 + 200) =
                   local_24 * *(float *)(iVar13 + 200) + *(float *)(iVar13 + 0x24);
            }
          }
        }
        else {
          DAT_02947d88 = *(undefined4 *)(iVar9 + 0x90);
          *(undefined4 *)(iVar13 + 0x1c) = *(undefined4 *)(iVar13 + 0xc0);
          *(undefined4 *)(iVar13 + 0x20) = *(undefined4 *)(iVar13 + 0xc4);
          *(undefined4 *)(iVar13 + 0x24) = *(undefined4 *)(iVar13 + 200);
          if (0.0 <= *(float *)(param_2 + 4)) {
            *(float *)(iVar13 + 0x2c) = *(float *)(iVar13 + 0x2c) * 0.75;
          }
          else {
            FUN_00677fb0(&DAT_0292fdb8,iVar13 + 0x28,iVar13 + 0x28);
            FUN_00677fb0(&DAT_0292fdb8,param_2,param_2);
          }
          *(undefined1 *)(*(int *)(iVar13 + 0x40) + 1) = 1;
          FUN_00678640(*(undefined4 *)(iVar8 + 0x40),iVar8 + 0x28,param_2,
                       (int)*(short *)(*DAT_0292fc68 + 0x30 + *(short *)(iVar9 + 0x6c) * 0x38));
        }
        FUN_006de960();
        DAT_0292186c = iVar8;
        return param_1 + -1;
      }
    }
  }
  FUN_006de960();
  return param_1;
}

