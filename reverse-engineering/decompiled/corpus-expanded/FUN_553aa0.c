/* Ghidra pseudocode, not original source.
 * ev_23fe0c900a66283c3d20cf72d3e92d7068463e5c92bfb1d0cb56e731534c3cac
 * Entry: 0x553aa0; label: FUN_00553aa0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00553aa0(int param_1)

{
  void *_Dst;
  undefined4 *puVar1;
  undefined4 *puVar2;
  int *piVar3;
  byte *pbVar4;
  undefined4 uVar5;
  float fVar6;
  char cVar7;
  undefined2 uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  float10 fVar15;
  float local_70;
  float local_6c;
  int local_68;
  int local_64;
  int local_60;
  float local_5c;
  int local_58;
  int local_54;
  float local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  int local_40;
  int local_3c;
  int local_38;
  uint local_34;
  float local_30;
  float local_2c;
  int local_28;
  undefined1 local_24 [32];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_70;
  local_5c = 0.0;
  if (*(int *)(param_1 + 0x46e0) != 0) {
    FUN_005cf5b0(DAT_00924880,&DAT_0093b118,"Spinner_default_Base",0);
    FUN_005cf5b0(DAT_00924880,&DAT_0093b10c,"Spinner_default_Arm",0);
    if (*(int *)(param_1 + 0x46e4) == 0) {
      local_68 = FUN_006217e0();
      iVar9 = FUN_006217e0();
      *(int *)(param_1 + 0x46e4) = iVar9;
      local_54 = 0;
      if (0 < iVar9) {
        iVar9 = 0;
        local_58 = 0;
        local_60 = 0x2e0;
        do {
          iVar11 = local_58;
          local_50 = 1.0;
          _Dst = (void *)(*(int *)(param_1 + 0x46e0) + iVar9);
          local_40 = 0;
          local_34 = 0;
          local_3c = 0;
          uVar5 = *(undefined4 *)((int)_Dst + 0x68);
          local_38 = 4;
          _memset(_Dst,0,0x304);
          *(undefined4 *)(*(int *)(param_1 + 0x46e0) + 0x68 + iVar9) = uVar5;
          cVar7 = FUN_006218c0();
          FUN_006216f0(*(int *)(param_1 + 0x46e0) + 0x40 + iVar9,(int)cVar7);
          FUN_00621900(*(int *)(param_1 + 0x46e0) + 0x5c + iVar9);
          uVar8 = FUN_00621860();
          *(undefined2 *)(*(int *)(param_1 + 0x46e0) + 0x82 + iVar9) = uVar8;
          cVar7 = FUN_006218c0();
          FUN_006216f0(local_24,(int)cVar7);
          FUN_005cf5b0(*(undefined4 *)(param_1 + 0x13c),&local_4c,local_24,0);
          iVar10 = FUN_005cfac0(&local_4c);
          if (iVar10 == 0) {
            FUN_005cf5b0(DAT_00924880,&local_4c,local_24,0);
            iVar10 = FUN_005cfac0(&local_4c);
            if (iVar10 == 0) {
              local_40 = 1;
            }
          }
          puVar1 = (undefined4 *)(*(int *)(param_1 + 0x46e0) + 0x50 + iVar9);
          *puVar1 = local_4c;
          puVar1[1] = local_48;
          puVar1[2] = local_44;
          cVar7 = FUN_006218c0();
          iVar10 = (int)cVar7;
          local_64 = iVar10;
          if (1 < local_68) {
            cVar7 = FUN_006218c0();
            local_38 = (int)cVar7;
            if (2 < local_68) {
              local_34 = FUN_006217e0();
              local_34 = local_34 & 0xfffffc9f;
              fVar15 = (float10)FUN_006217a0();
              *(float *)(*(int *)(param_1 + 0x46e0) + 0x2d8 + iVar9) = (float)fVar15;
              if (3 < local_68) {
                fVar15 = (float10)FUN_006217a0();
                local_50 = (float)fVar15;
                if (5 < local_68) {
                  cVar7 = FUN_006218c0();
                  local_3c = (int)cVar7;
                }
              }
            }
          }
          FUN_005a0a00(*(undefined4 *)(*(int *)(param_1 + 0x46e0) + 0x68 + iVar9));
          if (local_68 < 5) {
            cVar7 = FUN_006218c0();
            iVar13 = (int)cVar7;
            if (0 < iVar13) {
              do {
                local_70 = 1.0;
                local_6c = 1e+09;
                cVar7 = FUN_006218c0();
                FUN_006216f0(local_24,(int)cVar7);
                FUN_005cf5b0(*(undefined4 *)(param_1 + 0x13c),&local_4c,local_24,0);
                iVar10 = FUN_005cfac0(&local_4c);
                if (iVar10 == 0) {
                  FUN_005cf5b0(DAT_00924880,&local_4c,local_24,0);
                  FUN_005cfac0(&local_4c);
                }
                if (2 < local_68) {
                  fVar15 = (float10)FUN_006217a0();
                  local_70 = (float)fVar15;
                  fVar15 = (float10)FUN_006217a0();
                  local_6c = (float)fVar15;
                }
                iVar10 = FUN_005a0810(*(undefined4 *)(*(int *)(param_1 + 0x46e0) + 0x68 + iVar9),
                                      &local_4c,local_70,local_6c,0);
                piVar3 = (int *)(*(int *)(param_1 + 0x46e0) + 0x6c + iVar9);
                if (*piVar3 == 0) {
                  if ((iVar10 != 0) && (*(int *)(iVar10 + 0x14) != 0)) {
                    *piVar3 = iVar10;
                    local_70 = *(float *)(iVar10 + 0x1c) - *(float *)(iVar10 + 0x18);
                    local_5c = ABS(local_70);
                  }
                }
                else if ((iVar10 != 0) && (*(int *)(iVar10 + 0x14) != 0)) {
                  local_70 = *(float *)(iVar10 + 0x1c) - *(float *)(iVar10 + 0x18);
                  local_30 = ABS(local_70);
                  if (local_5c < local_30) {
                    *piVar3 = iVar10;
                    local_5c = local_30;
                  }
                }
                iVar13 = iVar13 + -1;
                iVar10 = local_64;
              } while (iVar13 != 0);
            }
          }
          else {
            iVar13 = *(int *)(param_1 + 0x46e0) + iVar9;
            FUN_005aef10(*(undefined4 *)(iVar13 + 0x68),param_1,0,local_68,"Spinner",iVar13 + 0x40);
            for (puVar1 = *(undefined4 **)
                           (*(int *)(*(int *)(param_1 + 0x46e0) + 0x68 + iVar9) + 0x18);
                puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)*puVar1) {
              puVar2 = (undefined4 *)(*(int *)(param_1 + 0x46e0) + 0x6c + iVar9);
              if (*(int *)(*(int *)(param_1 + 0x46e0) + 0x6c + iVar9) == 0) {
                if ((puVar1 != (undefined4 *)0x0) && (puVar1[5] != 0)) {
                  *puVar2 = puVar1;
                  local_70 = (float)puVar1[7] - (float)puVar1[6];
                  local_5c = ABS(local_70);
                }
              }
              else if ((puVar1 != (undefined4 *)0x0) && (puVar1[5] != 0)) {
                local_70 = (float)puVar1[7] - (float)puVar1[6];
                local_2c = ABS(local_70);
                if (local_5c < local_2c) {
                  *puVar2 = puVar1;
                  local_5c = local_2c;
                }
              }
            }
          }
          if (local_68 < 7) {
            iVar13 = *(int *)(param_1 + 0x46e0) + iVar9;
            if ((*(int *)(iVar13 + 0x68) != 0) &&
               (local_28 = *(int *)(iVar13 + 0x6c), local_28 != 0)) {
              local_6c = *(float *)(local_28 + 0x1c) - *(float *)(local_28 + 0x18);
              local_70 = 0.0;
              if (0 < local_64) {
                local_6c = (float)(local_64 + -1);
                iVar10 = local_60;
                do {
                  fVar6 = local_70;
                  iVar11 = FUN_006e6b90();
                  local_70 = (float)((int)fVar6 + 1);
                  *(float *)(iVar10 + *(int *)(param_1 + 0x46e0)) =
                       (float)iVar11 + *(float *)(local_28 + 0x18);
                  iVar11 = local_58;
                  iVar10 = iVar10 + 4;
                } while ((int)local_70 < local_64);
              }
              iVar13 = local_64;
              if (3 < 8 - local_64) {
                iVar14 = (4U - local_64 >> 2) + 1;
                iVar10 = (iVar11 + local_64) * 4 + 0x2e4;
                iVar13 = local_64 + iVar14 * 4;
                do {
                  *(undefined4 *)(iVar10 + -4 + *(int *)(param_1 + 0x46e0)) = 0xbf800000;
                  *(undefined4 *)(iVar10 + *(int *)(param_1 + 0x46e0)) = 0xbf800000;
                  *(undefined4 *)(iVar10 + 4 + *(int *)(param_1 + 0x46e0)) = 0xbf800000;
                  *(undefined4 *)(iVar10 + 8 + *(int *)(param_1 + 0x46e0)) = 0xbf800000;
                  iVar10 = iVar10 + 0x10;
                  iVar14 = iVar14 + -1;
                } while (iVar14 != 0);
              }
              iVar10 = local_64;
              if (iVar13 < 8) {
                iVar14 = (iVar11 + iVar13) * 4 + 0x2e0;
                iVar13 = 8 - iVar13;
                do {
                  *(undefined4 *)(iVar14 + *(int *)(param_1 + 0x46e0)) = 0xbf800000;
                  iVar14 = iVar14 + 4;
                  iVar13 = iVar13 + -1;
                } while (iVar13 != 0);
              }
            }
          }
          else {
            iVar13 = local_60;
            iVar14 = local_64;
            if (0 < iVar10) {
              do {
                fVar15 = (float10)FUN_006217a0();
                *(float *)(iVar13 + *(int *)(param_1 + 0x46e0)) = (float)fVar15;
                iVar14 = iVar14 + -1;
                iVar10 = local_64;
                iVar13 = iVar13 + 4;
                iVar11 = local_58;
              } while (iVar14 != 0);
            }
            iVar13 = iVar10;
            if (3 < 8 - iVar10) {
              iVar12 = (4U - iVar10 >> 2) + 1;
              iVar14 = (iVar11 + iVar10) * 4 + 0x2e4;
              iVar13 = iVar10 + iVar12 * 4;
              do {
                *(undefined4 *)(iVar14 + -4 + *(int *)(param_1 + 0x46e0)) = 0xbf800000;
                *(undefined4 *)(iVar14 + *(int *)(param_1 + 0x46e0)) = 0xbf800000;
                *(undefined4 *)(iVar14 + 4 + *(int *)(param_1 + 0x46e0)) = 0xbf800000;
                *(undefined4 *)(iVar14 + 8 + *(int *)(param_1 + 0x46e0)) = 0xbf800000;
                iVar14 = iVar14 + 0x10;
                iVar12 = iVar12 + -1;
                iVar11 = local_58;
              } while (iVar12 != 0);
            }
            if (iVar13 < 8) {
              iVar14 = (iVar11 + iVar13) * 4 + 0x2e0;
              iVar13 = 8 - iVar13;
              do {
                *(undefined4 *)(iVar14 + *(int *)(param_1 + 0x46e0)) = 0xbf800000;
                iVar14 = iVar14 + 4;
                iVar13 = iVar13 + -1;
              } while (iVar13 != 0);
            }
          }
          if (local_68 < 8) {
            fVar15 = (float10)0;
          }
          else {
            fVar15 = (float10)FUN_006217a0();
          }
          local_6c = (float)fVar15;
          if (local_68 < 9) {
            fVar15 = (float10)local_50;
          }
          else {
            fVar15 = (float10)FUN_006217a0();
          }
          local_70 = (float)fVar15;
          if (local_40 == 0) {
            FUN_005539a0();
            *(undefined1 *)(*(int *)(param_1 + 0x46e0) + 0x8b + iVar9) = (undefined1)local_38;
            *(float *)(*(int *)(param_1 + 0x46e0) + 0x78 + iVar9) = local_50;
            *(float *)(*(int *)(param_1 + 0x46e0) + 0x2dc + iVar9) = local_70;
            *(char *)(*(int *)(param_1 + 0x46e0) + 0xa4 + iVar9) = (char)iVar10;
            *(uint *)(*(int *)(param_1 + 0x46e0) + 0x84 + iVar9) = local_34;
            *(undefined1 *)(*(int *)(param_1 + 0x46e0) + 0xac + iVar9) = (undefined1)local_3c;
            *(float *)(*(int *)(param_1 + 0x46e0) + 0x98 + iVar9) = local_6c;
            pbVar4 = (byte *)(*(int *)(param_1 + 0x46e0) + 0xac + iVar9);
            *pbVar4 = *pbVar4 | 1;
            pbVar4 = (byte *)(*(int *)(param_1 + 0x46e0) + 0xac + iVar9);
            *pbVar4 = *pbVar4 & 0xdd;
          }
          else {
            pbVar4 = (byte *)(*(int *)(param_1 + 0x46e0) + 0xac + iVar9);
            *pbVar4 = *pbVar4 & 0xfe;
            FUN_00553710(*(int *)(param_1 + 0x46e0) + 0x40 + iVar9,local_24);
            *(int *)(param_1 + 0x46e4) = *(int *)(param_1 + 0x46e4) + -1;
            local_54 = local_54 + -1;
            local_58 = iVar11 + -0xc1;
            iVar9 = iVar9 + -0x304;
            local_60 = local_60 + -0x304;
          }
          local_60 = local_60 + 0x304;
          local_54 = local_54 + 1;
          local_58 = local_58 + 0xc1;
          iVar9 = iVar9 + 0x304;
        } while (local_54 < *(int *)(param_1 + 0x46e4));
      }
      __security_check_cookie(local_4 ^ (uint)&local_70);
      return;
    }
  }
  __security_check_cookie(local_4 ^ (uint)&local_70);
  return;
}

