/* Ghidra pseudocode, not original source.
 * ev_b142addbfc413d4476e6a560937bb6deb0d869285f4b587c6bb2379626f1bfc8
 * Entry: 0x5912e0; label: FUN_005912e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005912e0(int param_1,int *param_2)

{
  uint *puVar1;
  float fVar2;
  float fVar3;
  byte bVar4;
  char cVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  undefined4 uVar12;
  int iVar13;
  uint uVar14;
  int iVar15;
  uint uVar16;
  undefined4 *puVar17;
  float10 fVar18;
  float10 extraout_ST0;
  float10 extraout_ST1;
  undefined4 uVar19;
  float local_a8;
  float local_a4;
  int local_a0;
  int local_98;
  float fStack_90;
  float fStack_8c;
  float fStack_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  float local_74;
  float local_70;
  int local_6c;
  uint local_68;
  undefined1 local_64 [12];
  float local_58;
  undefined4 uStack_54;
  float fStack_50;
  undefined1 local_4c [12];
  undefined4 local_40 [13];
  float local_c;
  
  if (param_2 != (int *)0x0) {
    if (0.0 < _DAT_009555a8) {
      _DAT_009555a8 = _DAT_009555a8 - _DAT_00925018;
    }
    iVar15 = *param_2;
    local_6c = 0;
    if ((short)param_2[1] != 0) {
      do {
        if (((((*(ushort *)(iVar15 + 0x7a) & 2) != 0) && ((*(ushort *)(iVar15 + 0x7a) & 1) != 0)) &&
            (*(int *)(iVar15 + 0x10) != 0)) && (*(byte *)(iVar15 + 0x6c) != 0)) {
          if (*(char *)(iVar15 + 0x6d) == '\x01') {
            fVar2 = _DAT_00925018 + *(float *)(iVar15 + 0x44);
            *(float *)(iVar15 + 0x44) = fVar2;
            if (!NAN(fVar2) && 0.6 < fVar2 != (fVar2 == 0.6)) {
              FUN_00576960(DAT_00803990);
              FUN_00590ba0(iVar15);
              FUN_005b37d0(&local_84,iVar15 + 0x34,iVar15 + 0x5c);
              FUN_00547930(0x3a,&local_84,0,0);
              FUN_0054a910(0x3f400000,0x3dcccccd,0,0);
              FUN_00549de0(PTR_DAT_008021b4,0xbecccccd,0,0);
              if ((*(ushort *)(iVar15 + 0x7a) & 0x200) == 0) {
                *(ushort *)(iVar15 + 0x7a) = *(ushort *)(iVar15 + 0x7a) | 0x200;
                iVar8 = FUN_0046c4f0();
                if ((*(short *)(iVar15 + 0x56) != 0) || (iVar8 != 0)) {
                  FUN_005b35a0(local_4c,&DAT_00802500,*(undefined2 *)(iVar15 + 0x58));
                  FUN_005b3620(local_4c,local_4c,*(undefined2 *)(iVar15 + 0x5a));
                  FUN_0046d270(*(undefined2 *)(iVar15 + 0x56),iVar8,0,0,&local_84,local_4c,
                               0x40000000,0xffffffff,0x3fe00000,0x49f42400,0,1,0);
                }
              }
              if (*(short *)(iVar15 + 0x78) != -1) {
                FUN_0056a8c0(param_1,(int)*(short *)(iVar15 + 0x78),iVar15 + 0x34);
                FUN_005a15e0(*(undefined4 *)(iVar15 + 0x10),0);
              }
            }
            iVar8 = 0;
            if (*(char *)(iVar15 + 0x6c) != '\0') {
              iVar9 = FUN_006e6b90();
              do {
                iVar13 = *(int *)(*(int *)(iVar15 + 0x14) + iVar8 * 4);
                iVar6 = *(int *)(iVar13 + 0x24);
                if (*(int *)(iVar15 + 0x18) == 0) {
                  puVar10 = (undefined4 *)FUN_005cf9c0(iVar13 + 4);
                  local_84 = *puVar10;
                  local_80 = puVar10[1];
                  local_7c = puVar10[2];
                }
                else {
                  local_84 = *(undefined4 *)(iVar6 + 0x70);
                  local_80 = *(undefined4 *)(iVar6 + 0x74);
                  local_7c = *(undefined4 *)(iVar6 + 0x78);
                }
                if ((*(byte *)(iVar15 + 0x72) & 1) == 0) {
                  local_70 = 0.0;
                  local_78 = 0;
                  local_74 = (float)(&DAT_029899a0)[iVar9 >> 1 & 0x7fff] * 0.2;
                }
                else {
                  local_74 = 0.0;
                  local_78 = 0;
                  local_70 = (float)(&DAT_029899a0)[iVar9 >> 1 & 0x7fff] * 0.2;
                  FUN_005b3620(&local_78,&local_78,
                               (int)((uint)*(ushort *)(iVar15 + 0x54) * 0x10000) / 0x168);
                }
                FUN_005b37d0(&local_84,&local_84,&local_78);
                if (*(int *)(iVar15 + 0x18) == 0) {
                  FUN_005ea5d0(iVar13 + 4,&local_84);
                }
                else {
                  *(undefined4 *)(iVar6 + 0xb0) = local_84;
                  *(undefined4 *)(iVar6 + 0xb4) = local_80;
                  *(undefined4 *)(iVar6 + 0xb8) = local_7c;
                }
                iVar8 = iVar8 + 1;
              } while (iVar8 < (int)(uint)*(byte *)(iVar15 + 0x6c));
            }
          }
          else if (*(char *)(iVar15 + 0x6d) == '\0') {
            local_a8 = 0.0;
            local_98 = 0;
            if ((*(byte *)(iVar15 + 0x72) & 0x40) == 0) {
              if (*(char *)(iVar15 + 0x6e) == '\0') {
                *(undefined4 *)(iVar15 + 0x48) = 0x3e99999a;
                *(undefined4 *)(iVar15 + 0x44) = 0x3e99999a;
                if ((*(int *)(iVar15 + 0x18) == 0) &&
                   (*(byte *)(iVar15 + 0x6f) < *(byte *)(iVar15 + 0x6c))) {
                  FUN_005cfc00(*(int *)(*(int *)(iVar15 + 0x14) + (uint)*(byte *)(iVar15 + 0x6f) * 4
                                       ) + 4,1);
                }
              }
              else {
                iVar8 = FUN_0058e9d0();
                fVar2 = *(float *)(iVar15 + 0x44);
                fVar3 = (float)((float10)*(float *)(iVar15 + 0x44) - extraout_ST0);
                fVar18 = (float10)fVar3;
                *(float *)(iVar15 + 0x44) = fVar3;
                if (fVar18 < extraout_ST1 == (fVar18 == extraout_ST1)) {
                  iVar8 = *(int *)(*(int *)(iVar15 + 0x14) + (uint)*(byte *)(iVar15 + 0x6f) * 4);
                  if (*(float *)(iVar15 + 0x48) == fVar2) {
                    uVar12 = FUN_005cf9e0(iVar8 + 4);
                    iVar9 = FUN_0054fa60(uVar12);
                    FUN_0062c560(*(undefined4 *)(param_1 + 0x134),
                                 (int)*(short *)(&DAT_00804e38 + (iVar9 / 0x2aab) * 2));
                  }
                  if (*(int *)(iVar15 + 0x18) == 0) {
                    FUN_005cfc00(iVar8 + 4,0);
                  }
                }
                else {
                  iVar9 = *(int *)(*(int *)(iVar15 + 0x14) + (uint)*(byte *)(iVar15 + 0x6f) * 4);
                  if (*(int *)(iVar15 + 0x18) == 0) {
                    iVar13 = iVar9 + 4;
                    FUN_005cfc00(iVar13,1);
                    puVar1 = (uint *)(*(int *)(iVar9 + 0x10) + 0x50);
                    *puVar1 = *puVar1 & 0xfffffffe;
                    *(undefined4 *)(*(int *)(iVar9 + 0x10) + 0x4c) = *(undefined4 *)(iVar9 + 0x1c);
                    FUN_00552760(iVar13,*(undefined4 *)(*(int *)(iVar9 + 0x10) + 0x4c));
                    uVar19 = 0;
                    uVar12 = 0;
                    iVar9 = FUN_005cf9e0(iVar13,0,0);
                  }
                  else {
                    iVar9 = *(int *)(iVar9 + 0x24);
                    uVar19 = 0;
                    puVar10 = (undefined4 *)(iVar9 + 0x40);
                    puVar11 = (undefined4 *)(iVar9 + 0x80);
                    for (iVar13 = 0x10; iVar13 != 0; iVar13 = iVar13 + -1) {
                      *puVar11 = *puVar10;
                      puVar10 = puVar10 + 1;
                      puVar11 = puVar11 + 1;
                    }
                    uVar12 = 0;
                    iVar9 = iVar9 + 0xb0;
                  }
                  FUN_00547930(0x3b,iVar9,uVar12,uVar19);
                  *(char *)(iVar15 + 0x6f) = *(char *)(iVar15 + 0x6f) + '\x01';
                  bVar4 = *(byte *)(iVar15 + 0x6c);
                  if (*(byte *)(iVar15 + 0x6f) == bVar4) {
                    iVar9 = 0;
                    *(undefined4 *)(iVar15 + 0x44) = 0;
                    *(undefined1 *)(iVar15 + 0x6d) = 1;
                    if (bVar4 != 0) {
                      do {
                        iVar13 = FUN_0054fa60(*(int *)(*(int *)(*(int *)(iVar15 + 0x14) + iVar9 * 4)
                                                      + 0x24) + 0x70);
                        FUN_0062c560(*(undefined4 *)(param_1 + 0x134),
                                     (int)*(short *)(&DAT_00804e38 + (iVar13 / 0x2aab) * 2));
                        iVar9 = iVar9 + 1;
                      } while (iVar9 < (int)(uint)*(byte *)(iVar15 + 0x6c));
                    }
                    local_a8 = 0.1;
                  }
                  else if (*(byte *)(iVar15 + 0x6f) <= bVar4) {
                    FUN_00590be0(iVar15,iVar8);
                    local_98 = 1;
                  }
                  if (iVar8 != 0) {
                    if (local_a8 <= 0.0) {
                      if (local_98 != 0) {
                        FUN_0054a8d0(**(undefined4 **)(iVar8 + 0xca4),local_98,0);
                      }
                    }
                    else {
                      FUN_0054a8a0(**(undefined4 **)(iVar8 + 0xca4),local_a8,0);
                    }
                    if ((*(char *)(iVar15 + 0x6d) == '\0') &&
                       (((*(uint *)(*(int *)(iVar8 + 0xca4) + 4) & DAT_00802280) != 0 ||
                        ((*(uint *)(iVar8 + 0x1f8) & 0x40000) != 0)))) {
                      *(uint *)(iVar8 + 0xe20) = *(uint *)(iVar8 + 0xe20) ^ 0x4000;
                      if (*(byte *)(iVar8 + 0x7b4) < 10) {
                        *(byte *)(iVar8 + 0x7b4) = *(byte *)(iVar8 + 0x7b4) + 1;
                      }
                    }
                    else {
                      FUN_0058ff10(iVar8,*(char *)(iVar15 + 0x6d));
                    }
                  }
                }
              }
            }
            else {
              if ((DAT_009555ac != (code *)0x0) &&
                 (iVar8 = (*DAT_009555ac)(param_1,iVar15 + 0x28,&local_58,&local_68),
                 uVar7 = local_68, iVar8 != 0)) {
                uVar14 = local_68 - 0x4000;
                if (*(float *)(iVar15 + 0x44) <= 4.5) {
                  iVar8 = FUN_006e6b90();
                  fVar2 = (float)(&DAT_029899a0)[iVar8 >> 1 & 0x7fff];
                  uVar16 = (uint)*(byte *)(iVar15 + 0x6c);
                  uVar14 = (uint)ROUND(((fVar2 + 1.0) * 5.0 * 360.0 * 65536.0) / 360.0 +
                                       (float)(int)((uVar7 & 0xffff) - 0x4000));
                  fVar18 = (float10)FUN_0058e920(0x47800000,(float)uVar16);
                  fVar2 = 0.5 - (fVar2 + 1.0) * 0.3;
                }
                else {
                  uVar16 = (uint)*(byte *)(iVar15 + 0x6c);
                  fVar18 = (float10)FUN_0058e920(0x47800000,(float)uVar16);
                  fVar2 = 0.5;
                }
                local_a8 = (float)((int)ROUND(fVar18) & 0xffff);
                uVar14 = uVar14 & 0xffff;
                iVar8 = uVar16 - 1;
                if ((int)(uint)*(byte *)(iVar15 + 0x6f) <= iVar8) {
                  do {
                    uVar14 = uVar14 + (int)local_a8;
                    fStack_8c = (float)uStack_54;
                    fStack_90 = (float)(&DAT_029899a0)
                                       [(int)((uVar14 & 0xffff) + 0x4000) >> 1 & 0x7fff] * fVar2 +
                                local_58;
                    fStack_88 = fVar2 * (float)(&DAT_029899a0)[(uVar14 & 0xffff) >> 1] + fStack_50;
                    puVar10 = (undefined4 *)
                              FUN_005cf9e0(*(int *)(*(int *)(iVar15 + 0x14) + iVar8 * 4) + 4);
                    fVar18 = (float10)FUN_0054fb40(*puVar10,fStack_90,0x40c00000);
                    fStack_90 = (float)fVar18;
                    fVar18 = (float10)FUN_0054fb40(puVar10[1],fStack_8c,0x40c00000);
                    fStack_8c = (float)fVar18;
                    fVar18 = (float10)FUN_0054fb40(puVar10[2],fStack_88,0x40c00000);
                    fStack_88 = (float)fVar18;
                    if (*(int *)(iVar15 + 0x18) == 0) {
                      FUN_005ea5d0(*(int *)(*(int *)(iVar15 + 0x14) + iVar8 * 4) + 4,&fStack_90);
                      FUN_005ea660(*(int *)(*(int *)(iVar15 + 0x14) + iVar8 * 4) + 4);
                    }
                    else {
                      iVar9 = *(int *)(*(int *)(*(int *)(iVar15 + 0x14) + iVar8 * 4) + 0x24);
                      *(float *)(iVar9 + 0xb0) = fStack_90;
                      *(float *)(iVar9 + 0xb4) = fStack_8c;
                      *(float *)(iVar9 + 0xb8) = fStack_88;
                    }
                    iVar8 = iVar8 + -1;
                  } while ((int)(uint)*(byte *)(iVar15 + 0x6f) <= iVar8);
                }
              }
              fVar2 = *(float *)(iVar15 + 0x44);
              fVar3 = *(float *)(iVar15 + 0x44) - _DAT_00925018;
              *(float *)(iVar15 + 0x44) = fVar3;
              if (0.0 < fVar3) {
                iVar8 = *(int *)(*(int *)(iVar15 + 0x14) + (uint)*(byte *)(iVar15 + 0x6f) * 4);
                if (*(float *)(iVar15 + 0x48) == fVar2) {
                  uVar12 = FUN_005cf9e0(iVar8 + 4);
                  iVar9 = FUN_0054fa60(uVar12);
                  FUN_0062c560(*(undefined4 *)(param_1 + 0x134),
                               (int)*(short *)(&DAT_00804e38 + (iVar9 / 0x2aab) * 2));
                }
                FUN_0058ed90(iVar15,iVar8);
              }
              else {
                iVar8 = *(int *)(*(int *)(iVar15 + 0x14) + (uint)*(byte *)(iVar15 + 0x6f) * 4);
                if (*(int *)(iVar15 + 0x18) == 0) {
                  iVar9 = iVar8 + 4;
                  FUN_005cfc00(iVar9,1);
                  if (*(int *)(iVar8 + 0x10) != 0) {
                    puVar1 = (uint *)(*(int *)(iVar8 + 0x10) + 0x50);
                    *puVar1 = *puVar1 & 0xfffffffe;
                    *(undefined4 *)(*(int *)(iVar8 + 0x10) + 0x4c) = *(undefined4 *)(iVar8 + 0x1c);
                    FUN_00552760(iVar9,*(undefined4 *)(*(int *)(iVar8 + 0x10) + 0x4c));
                  }
                  uVar12 = FUN_005cf9e0(iVar9,0,0);
                  FUN_00547930(0x3b,uVar12);
                  uVar12 = FUN_005cf9c0(iVar9);
                  FUN_005ea5d0(iVar9,uVar12);
                }
                else {
                  iVar8 = *(int *)(iVar8 + 0x24);
                  puVar10 = (undefined4 *)(iVar8 + 0x40);
                  puVar11 = (undefined4 *)(iVar8 + 0x80);
                  for (iVar9 = 0x10; iVar9 != 0; iVar9 = iVar9 + -1) {
                    *puVar11 = *puVar10;
                    puVar10 = puVar10 + 1;
                    puVar11 = puVar11 + 1;
                  }
                  FUN_00547930(0x3b,iVar8 + 0xb0,0,0);
                }
                *(char *)(iVar15 + 0x6f) = *(char *)(iVar15 + 0x6f) + '\x01';
                if (*(char *)(iVar15 + 0x6f) == *(char *)(iVar15 + 0x6c)) {
                  iVar8 = 0;
                  *(undefined4 *)(iVar15 + 0x44) = 0;
                  *(undefined1 *)(iVar15 + 0x6d) = 1;
                  if (*(char *)(iVar15 + 0x6c) != '\0') {
                    do {
                      iVar9 = FUN_0054fa60(*(int *)(*(int *)(*(int *)(iVar15 + 0x14) + iVar8 * 4) +
                                                   0x24) + 0x70);
                      FUN_0062c560(*(undefined4 *)(param_1 + 0x134),
                                   (int)*(short *)(&DAT_00804e38 + (iVar9 / 0x2aab) * 2));
                      iVar8 = iVar8 + 1;
                    } while (iVar8 < (int)(uint)*(byte *)(iVar15 + 0x6c));
                  }
                }
                else {
                  *(undefined4 *)(iVar15 + 0x48) = 0x3e99999a;
                  *(undefined4 *)(iVar15 + 0x44) = 0x3e99999a;
                }
              }
            }
          }
          if (((*(char *)(iVar15 + 0x6d) == '\0') && ((*(ushort *)(iVar15 + 0x72) & 0x40) == 0)) &&
             ((-1 < (char)*(ushort *)(iVar15 + 0x72) || (DAT_0087baf0 != 0)))) {
            local_a4 = 0.1 - (float)(int)((uint)*(byte *)(iVar15 + 0x6c) -
                                         (uint)*(byte *)(iVar15 + 0x6f)) * 0.002;
            if (local_a4 < 0.01) {
              local_a4 = 0.01;
            }
            if ((*(byte *)(iVar15 + 0x7a) & 4) == 0) {
              local_a4 = local_a4 * 0.1;
            }
            local_a0 = 0;
            if (*(byte *)(iVar15 + 0x6c) != 0) {
              do {
                if ((*(int *)(iVar15 + 0x18) == 0) ||
                   ((int)(uint)*(byte *)(iVar15 + 0x6f) <= local_a0)) {
                  iVar8 = *(int *)(*(int *)(iVar15 + 0x14) + local_a0 * 4);
                  puVar10 = *(undefined4 **)(iVar8 + 0x24);
                  puVar11 = puVar10;
                  if (*(int *)(iVar15 + 0x18) == 0) {
                    puVar11 = (undefined4 *)FUN_005cfa20(iVar8 + 4);
                  }
                  puVar17 = local_40;
                  for (iVar9 = 0x10; iVar9 != 0; iVar9 = iVar9 + -1) {
                    *puVar17 = *puVar11;
                    puVar11 = puVar11 + 1;
                    puVar17 = puVar17 + 1;
                  }
                  if ((float)puVar10[0x30] <= 0.0) {
                    if ((int)(uint)*(byte *)(iVar15 + 0x6f) <= local_a0) {
                      if (*(int *)(iVar15 + 0x18) == 0) {
                        iVar9 = FUN_005cfe70(iVar8 + 4);
                        if (iVar9 != 0) goto LAB_00591f2b;
                      }
                      else if (*(char *)((int)puVar10 + 0xc6) != '\0') {
LAB_00591f2b:
                        iVar9 = FUN_0054fa60();
                        if ((float)iVar9 * 1.5259022e-05 < local_a4) {
                          puVar10[0x30] = 0x3e4ccccd;
                          iVar9 = FUN_0054fa60();
                          *(char *)(puVar10 + 0x31) =
                               ((char)(iVar9 / 0x2aab) + (char)(iVar9 >> 0x1f)) -
                               (char)((longlong)iVar9 * 0x2fffa001 >> 0x3f);
                        }
                      }
                    }
                  }
                  else {
                    fVar2 = (float)puVar10[0x30] - _DAT_00925018;
                    puVar10[0x30] = fVar2;
                    if (((fVar2 < 0.0 != (fVar2 == 0.0)) && (_DAT_009555a8 <= 0.0)) &&
                       (((*(byte *)(iVar15 + 0x7a) & 4) != 0 ||
                        (iVar9 = FUN_0054fa60(), iVar9 < 0x8000)))) {
                      FUN_00547930(0x3c,iVar15 + 0x28,0,0);
                      iVar9 = FUN_0054fa60();
                      _DAT_009555a8 = (float)iVar9 * 1.5259022e-05 * 0.2 + 0.1;
                    }
                  }
                  if (0.0 < (float)puVar10[0x30]) {
                    FUN_006e6b90();
                    FUN_006e6b90();
                    cVar5 = *(char *)(puVar10 + 0x31);
                    if ((cVar5 == '\0') || (cVar5 == '\x01')) {
                      FUN_005b6e60(local_40,local_64);
                      FUN_0058ea20();
                      uVar12 = FUN_006e6b90();
                      FUN_005b4dd0(local_40,uVar12);
                    }
                    else if ((cVar5 == '\x02') || (cVar5 == '\x03')) {
                      FUN_005b6e80(local_40,local_64);
                      FUN_0058ea20();
                      uVar12 = FUN_006e6b90();
                      FUN_005b5060(local_40,uVar12);
                    }
                    else {
                      FUN_005b6ea0(local_40,local_64);
                      FUN_0058ea20();
                      uVar12 = FUN_006e6b90();
                      FUN_005b5240(local_40,uVar12);
                    }
                    iVar9 = FUN_006e6b90();
                    local_c = (float)(&DAT_029899a0)[iVar9 >> 1 & 0x7fff] * _DAT_00804e34 *
                              *(float *)(iVar15 + 0x4c) + local_c;
                  }
                  if (*(int *)(iVar15 + 0x18) == 0) {
                    FUN_005ea570(iVar8 + 4,local_40);
                    FUN_005ea660(iVar8 + 4);
                  }
                  else {
                    puVar11 = local_40;
                    puVar10 = puVar10 + 0x20;
                    for (iVar8 = 0x10; iVar8 != 0; iVar8 = iVar8 + -1) {
                      *puVar10 = *puVar11;
                      puVar11 = puVar11 + 1;
                      puVar10 = puVar10 + 1;
                    }
                  }
                }
                local_a0 = local_a0 + 1;
              } while (local_a0 < (int)(uint)*(byte *)(iVar15 + 0x6c));
            }
          }
        }
        local_6c = local_6c + 1;
        iVar15 = iVar15 + 0x7c;
        if ((int)(uint)*(ushort *)(param_2 + 1) <= local_6c) {
          return;
        }
      } while( true );
    }
  }
  return;
}

