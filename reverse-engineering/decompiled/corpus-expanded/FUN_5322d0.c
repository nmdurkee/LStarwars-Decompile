/* Ghidra pseudocode, not original source.
 * ev_f14574f1686883c8a991ff5dcc30f6c2e407e48e229a0065a53ff25a44d38981
 * Entry: 0x5322d0; label: FUN_005322d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

byte * FUN_005322d0(int *param_1,uint *param_2,int *param_3,uint *param_4)

{
  byte *pbVar1;
  undefined1 *puVar2;
  char cVar3;
  ushort uVar4;
  undefined2 uVar5;
  int iVar6;
  void *pvVar7;
  int iVar8;
  undefined4 uVar9;
  char *pcVar10;
  void *pvVar11;
  char *pcVar12;
  int *piVar13;
  uint uVar14;
  int iVar15;
  size_t sVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  uint uVar20;
  int iVar21;
  undefined4 *puVar22;
  float10 fVar23;
  byte *local_4c;
  int local_44;
  int local_40;
  int *local_3c;
  int local_38;
  int local_34;
  int *local_30;
  uint local_2c;
  int *local_28;
  undefined4 local_24 [2];
  undefined4 local_1c;
  int local_18;
  int local_14;
  undefined4 local_10;
  uint local_c;
  float local_8;
  undefined4 local_4;
  
  local_44 = *param_3;
  local_4c = (byte *)0x0;
  _DAT_009242a0 = 0;
  if (*(int *)(DAT_009238e4 + 0x4868) != 0) {
    uVar20 = 0;
    iVar6 = FUN_004f1440(DAT_009238e4 + 0x4874);
    if (iVar6 != 0) {
      do {
        *(char *)(iVar6 + 0x38) = (char)uVar20;
        uVar20 = uVar20 + 1;
        iVar6 = FUN_004f1460(DAT_009238e4 + 0x4874,iVar6);
      } while (iVar6 != 0);
      if ((uVar20 != 0) &&
         (local_4c = (byte *)FUN_00517160(param_1,param_2,0x10), local_4c != (byte *)0x0)) {
        local_4c[0] = 0;
        local_4c[1] = 0;
        local_4c[2] = 0;
        local_4c[3] = 0;
        local_4c[4] = 0;
        local_4c[5] = 0;
        local_4c[6] = 0;
        local_4c[7] = 0;
        local_4c[8] = 0;
        local_4c[9] = 0;
        local_4c[10] = 0;
        local_4c[0xb] = 0;
        local_4c[0xc] = 0;
        local_4c[0xd] = 0;
        local_4c[0xe] = 0;
        local_4c[0xf] = 0;
        *local_4c = (byte)uVar20;
        DAT_009242a4 = (void *)0x0;
        if ((byte)uVar20 != 0) {
          DAT_009242a4 = (void *)FUN_00517160(&local_44,param_4,(uVar20 & 0xff) * 4);
          _memset(DAT_009242a4,0,(uint)*local_4c * 4);
        }
        local_4c[2] = 0;
        local_4c[3] = 0;
        for (iVar6 = FUN_004f1440(DAT_009238e4 + 0x31b8c); iVar6 != 0;
            iVar6 = FUN_004f1460(DAT_009238e4 + 0x31b8c,iVar6)) {
          *(byte *)(iVar6 + 9) = local_4c[2];
          *(short *)(local_4c + 2) = *(short *)(local_4c + 2) + 1;
        }
        iVar6 = local_44;
        if (*(ushort *)(local_4c + 2) != 0) {
          pvVar7 = (void *)FUN_00517160(&local_44,param_4,(uint)*(ushort *)(local_4c + 2) * 8);
          *(void **)(local_4c + 0xc) = pvVar7;
          _memset(pvVar7,0,(uint)*(ushort *)(local_4c + 2) * 8);
          iVar8 = FUN_004f1440(DAT_009238e4 + 0x31b8c);
          iVar6 = local_44;
          for (; iVar8 != 0; iVar8 = FUN_004f1460(DAT_009238e4 + 0x31b8c,iVar8)) {
            cVar3 = *(char *)(iVar8 + 9);
            iVar18 = *(int *)(local_4c + 0xc);
            sVar16 = *(char *)(iVar8 + 8) * 0xa8;
            pvVar7 = (void *)0x0;
            if ((param_4 == (uint *)0x0) || (*param_4 <= sVar16 + iVar6)) {
              FUN_00512850();
            }
            else {
              pvVar7 = (void *)(iVar6 + 0xfU & 0xfffffff0);
              iVar6 = (iVar6 + 0xfU & 0xfffffff0) + sVar16;
              _memset(pvVar7,0,sVar16);
            }
            *(void **)(iVar18 + cVar3 * 8 + 4) = pvVar7;
            _memset(pvVar7,0,*(char *)(iVar8 + 8) * 0xa8);
          }
        }
        local_44 = iVar6;
        pvVar7 = (void *)FUN_00517160(param_1,param_2,(uint)*local_4c * 4);
        *(void **)(local_4c + 4) = pvVar7;
        if (pvVar7 != (void *)0x0) {
          _memset(pvVar7,0,(uint)*local_4c * 4);
          local_40 = FUN_004f1440(DAT_009238e4 + 0x4874);
          param_3 = (int *)0x0;
          for (; local_40 != 0; local_40 = FUN_004f1460(DAT_009238e4 + 0x4874,local_40)) {
            uVar9 = FUN_00517160(param_1,param_2,0xa8);
            *(undefined4 *)(*(int *)(local_4c + 4) + (int)param_3 * 4) = uVar9;
            piVar13 = (int *)(*(int *)(local_4c + 4) + (int)param_3 * 4);
            if (*piVar13 != 0) {
              pvVar7 = (void *)*piVar13;
              _memset(pvVar7,0,0xa8);
              iVar6 = local_40;
              pcVar10 = (char *)(local_40 + 8);
              iVar8 = (int)pvVar7 - (int)pcVar10;
              do {
                cVar3 = *pcVar10;
                pcVar10[iVar8] = cVar3;
                pcVar10 = pcVar10 + 1;
              } while (cVar3 != '\0');
              *(undefined1 *)((int)pvVar7 + 0x15) = param_3._0_1_;
              for (iVar8 = FUN_004f1440(local_40 + 0x18); iVar8 != 0;
                  iVar8 = FUN_004f1460(iVar6 + 0x18,iVar8)) {
                *(ushort *)(iVar8 + 0x90) = (ushort)*(byte *)((int)pvVar7 + 0x10);
                *(char *)((int)pvVar7 + 0x10) = *(char *)((int)pvVar7 + 0x10) + '\x01';
                piVar13 = (int *)(iVar8 + 0x30);
                iVar18 = 8;
                do {
                  if (*piVar13 != 0) {
                    *(short *)((int)pvVar7 + 0x12) = *(short *)((int)pvVar7 + 0x12) + 1;
                  }
                  piVar13 = piVar13 + 3;
                  iVar18 = iVar18 + -1;
                } while (iVar18 != 0);
                if (*(int *)(iVar8 + 0xb0) != 0) {
                  *(char *)((int)pvVar7 + 0x7a) = *(char *)((int)pvVar7 + 0x7a) + '\x01';
                }
              }
              if (*(ushort *)((int)pvVar7 + 0x12) != 0) {
                uVar4 = *(ushort *)((int)pvVar7 + 0x12) >> 1;
                *(ushort *)((int)pvVar7 + 0x12) = uVar4;
                pvVar11 = (void *)FUN_00517160(param_1,param_2,(uint)uVar4 * 0x24);
                *(void **)((int)pvVar7 + 0x80) = pvVar11;
                if (pvVar11 != (void *)0x0) {
                  _memset(pvVar11,0,(uint)*(ushort *)((int)pvVar7 + 0x12) * 0x24);
                }
              }
              if (*(byte *)((int)pvVar7 + 0x7a) != 0) {
                pvVar11 = (void *)FUN_00517160(param_1,param_2,
                                               (uint)*(byte *)((int)pvVar7 + 0x7a) * 4);
                *(void **)((int)pvVar7 + 0x8c) = pvVar11;
                _memset(pvVar11,0,(uint)*(byte *)((int)pvVar7 + 0x7a) * 4);
                *(undefined1 *)((int)pvVar7 + 0x7a) = 0;
              }
              if (*(byte *)((int)pvVar7 + 0x10) != 0) {
                pvVar11 = (void *)FUN_00517160(param_1,param_2,
                                               (uint)*(byte *)((int)pvVar7 + 0x10) * 0x5c);
                *(void **)((int)pvVar7 + 0x7c) = pvVar11;
                if (pvVar11 != (void *)0x0) {
                  _memset(pvVar11,0,(uint)*(byte *)((int)pvVar7 + 0x10) * 0x5c);
                  local_38 = 0;
                  for (iVar6 = FUN_004f1440(iVar6 + 0x18); iVar6 != 0;
                      iVar6 = FUN_004f1460(local_40 + 0x18,iVar6)) {
                    puVar22 = (undefined4 *)
                              (*(short *)(iVar6 + 0x90) * 0x5c + *(int *)((int)pvVar7 + 0x7c));
                    pcVar10 = (char *)(iVar6 + 8);
                    pcVar12 = pcVar10;
                    do {
                      cVar3 = *pcVar12;
                      pcVar12 = pcVar12 + 1;
                    } while (cVar3 != '\0');
                    iVar8 = (int)pcVar12 - (iVar6 + 9);
                    if (iVar8 != 0) {
                      pcVar12 = (char *)FUN_00517160(param_1,param_2,iVar8 + 1);
                      *puVar22 = pcVar12;
                      do {
                        cVar3 = *pcVar10;
                        *pcVar12 = cVar3;
                        pcVar10 = pcVar10 + 1;
                        pcVar12 = pcVar12 + 1;
                      } while (cVar3 != '\0');
                    }
                    puVar22[1] = *(undefined4 *)(iVar6 + 0x18);
                    puVar22[2] = *(undefined4 *)(iVar6 + 0x1c);
                    puVar22[3] = *(undefined4 *)(iVar6 + 0x20);
                    puVar22[4] = *(undefined4 *)(iVar6 + 0x24);
                    puVar22[5] = *(float *)(iVar6 + 0x24) * *(float *)(iVar6 + 0x24);
                    *(undefined1 *)((int)puVar22 + 0x2b) = *(undefined1 *)(iVar6 + 0x92);
                    puVar22[0x10] = *(undefined4 *)(iVar6 + 0x98);
                    puVar22[0x11] = *(undefined4 *)(iVar6 + 0x9c);
                    puVar22[0x12] = *(undefined4 *)(iVar6 + 0xa0);
                    iVar8 = FUN_005cfac0(puVar22 + 0x10);
                    if (iVar8 != 0) {
                      *(undefined1 *)((int)puVar22 + 0x2a) = 1;
                    }
                    puVar22[0x13] = *(undefined4 *)(iVar6 + 0xa4);
                    puVar22[0x14] = *(undefined4 *)(iVar6 + 0xa8);
                    puVar22[0x15] = *(undefined4 *)(iVar6 + 0xac);
                    local_30 = (int *)(iVar6 + 0x30);
                    iVar8 = 8;
                    puVar22[6] = *(float *)(iVar6 + 0x28) + (float)puVar22[2];
                    puVar22[8] = *(float *)(iVar6 + 0x2c) + (float)puVar22[2];
                    puVar22[7] = (float)puVar22[6] - (float)puVar22[2];
                    puVar22[9] = (float)puVar22[8] - (float)puVar22[2];
                    piVar13 = local_30;
                    do {
                      if (*piVar13 != 0) {
                        *(char *)(puVar22 + 10) = *(char *)(puVar22 + 10) + '\x01';
                      }
                      piVar13 = piVar13 + 3;
                      iVar8 = iVar8 + -1;
                    } while (iVar8 != 0);
                    if ((*(int *)((int)pvVar7 + 0x80) != 0) && (*(byte *)(puVar22 + 10) != 0)) {
                      sVar16 = (uint)*(byte *)(puVar22 + 10) * 4;
                      pvVar11 = (void *)0x0;
                      if ((param_1 == (int *)0x0) ||
                         ((param_2 == (uint *)0x0 || (*param_2 <= sVar16 + *param_1)))) {
                        FUN_00512850();
                      }
                      else {
                        uVar20 = *param_1 + 0xf;
                        pvVar11 = (void *)(uVar20 & 0xfffffff0);
                        *param_1 = (uVar20 & 0xfffffff0) + sVar16;
                        _memset(pvVar11,0,sVar16);
                      }
                      puVar22[0xd] = pvVar11;
                      if (pvVar11 != (void *)0x0) {
                        _memset(pvVar11,0,(uint)*(byte *)(puVar22 + 10) * 4);
                      }
                      piVar13 = local_30;
                      iVar8 = 0;
                      local_34 = local_38 * 0x24;
                      local_30 = (int *)0x8;
                      do {
                        if (*piVar13 != 0) {
                          uVar4 = *(ushort *)(iVar6 + 0x90);
                          local_3c = (int *)(uint)uVar4;
                          iVar18 = *(short *)(*piVar13 + 0x90) * 0x5c + *(int *)((int)pvVar7 + 0x7c)
                          ;
                          if (*(short *)(*piVar13 + 0x90) < (short)uVar4) {
                            local_2c = (uint)*(byte *)(iVar18 + 0x28);
                            iVar17 = 0;
                            if (local_2c != 0) {
                              local_28 = *(int **)(iVar18 + 0x34);
                              local_3c = local_28;
                              do {
                                if (*(byte *)(*local_3c + 0x11) == uVar4) {
                                  *(int *)(puVar22[0xd] + iVar8) = local_28[iVar17];
                                  *(int *)(*(int *)(puVar22[0xd] + iVar8) + 4) = piVar13[1];
                                  *(int *)(*(int *)(puVar22[0xd] + iVar8) + 0xc) = piVar13[1];
                                  break;
                                }
                                local_3c = local_3c + 1;
                                iVar17 = iVar17 + 1;
                              } while (iVar17 < (int)local_2c);
                            }
                          }
                          else {
                            *(int *)(puVar22[0xd] + iVar8) = *(int *)((int)pvVar7 + 0x80) + local_34
                            ;
                            local_34 = local_34 + 0x24;
                            *(undefined1 *)(*(int *)(puVar22[0xd] + iVar8) + 0x10) =
                                 *(undefined1 *)(iVar6 + 0x90);
                            *(undefined1 *)(*(int *)(puVar22[0xd] + iVar8) + 0x11) =
                                 *(undefined1 *)(*piVar13 + 0x90);
                            local_38 = local_38 + 1;
                            **(int **)(puVar22[0xd] + iVar8) = piVar13[1];
                            *(int *)(*(int *)(puVar22[0xd] + iVar8) + 8) = piVar13[1];
                            fVar23 = (float10)FUN_005becc0(*piVar13 + 0x18,iVar6 + 0x18,local_24);
                            *(float *)(*(int *)(puVar22[0xd] + iVar8) + 0x18) = (float)fVar23;
                            fVar23 = (float10)FUN_005bed80(*piVar13 + 0x18,iVar6 + 0x18,local_24);
                            *(float *)(*(int *)(puVar22[0xd] + iVar8) + 0x1c) = (float)fVar23;
                            if (*(float *)(*(int *)(puVar22[0xd] + iVar8) + 0x1c) == 0.0) {
                              *(undefined4 *)(*(int *)(puVar22[0xd] + iVar8) + 0x1c) = 0x38d1b717;
                            }
                            FUN_005bfe00(local_24[0],local_1c);
                            uVar5 = FUN_006e6b90();
                            *(undefined2 *)(*(int *)(puVar22[0xd] + iVar8) + 0x12) = uVar5;
                          }
                          iVar8 = iVar8 + 4;
                        }
                        piVar13 = piVar13 + 3;
                        local_30 = (int *)((int)local_30 + -1);
                      } while (local_30 != (int *)0x0);
                    }
                    *(undefined1 *)((int)puVar22 + 0x2e) = 0xff;
                    *(undefined1 *)((int)puVar22 + 0x2f) = 0xff;
                    if (*(int *)(iVar6 + 0xb0) == 0) {
                      *(undefined1 *)(puVar22 + 0xc) = 0xff;
                    }
                    else {
                      cVar3 = *(char *)(*(int *)(iVar6 + 0xb0) + 9);
                      iVar8 = *(int *)(local_4c + 0xc);
                      *(undefined1 *)(puVar22 + 0xc) = *(undefined1 *)((int)pvVar7 + 0x7a);
                      *(char *)((int)pvVar7 + 0x7a) = *(char *)((int)pvVar7 + 0x7a) + '\x01';
                      pbVar1 = (byte *)(iVar8 + cVar3 * 8);
                      puVar2 = (undefined1 *)
                               (*(int *)((int)pvVar7 + 0x8c) + (uint)*(byte *)(puVar22 + 0xc) * 4);
                      *(void **)(*(int *)(pbVar1 + 4) + (uint)*pbVar1 * 4) = pvVar7;
                      *pbVar1 = *pbVar1 + 1;
                      *puVar2 = *(undefined1 *)(iVar6 + 0x90);
                      *(short *)(puVar2 + 2) = (short)*(char *)(*(int *)(iVar6 + 0xb0) + 9);
                    }
                  }
                }
              }
              piVar13 = (int *)((int)DAT_009242a4 + (int)param_3 * 4);
              local_28 = piVar13;
              iVar6 = FUN_00524df0(0,&local_44,param_4);
              *piVar13 = iVar6;
              if (*(byte *)((int)pvVar7 + 0x10) != 0) {
                sVar16 = (uint)*(byte *)((int)pvVar7 + 0x10) * 4;
                pvVar11 = (void *)0x0;
                if (((param_1 == (int *)0x0) || (param_2 == (uint *)0x0)) ||
                   (*param_2 <= sVar16 + *param_1)) {
                  FUN_00512850();
                }
                else {
                  uVar20 = *param_1 + 0xf;
                  pvVar11 = (void *)(uVar20 & 0xfffffff0);
                  *param_1 = (uVar20 & 0xfffffff0) + sVar16;
                  _memset(pvVar11,0,sVar16);
                }
                *(void **)((int)pvVar7 + 0x84) = pvVar11;
                _memset(pvVar11,0,(uint)*(byte *)((int)pvVar7 + 0x10) * 4);
                local_38 = 0;
                if (*(char *)((int)pvVar7 + 0x10) != '\0') {
                  do {
                    iVar6 = local_38;
                    uVar20 = (uint)*(byte *)((int)pvVar7 + 0x10);
                    pvVar11 = (void *)0x0;
                    if ((param_1 == (int *)0x0) || (param_2 == (uint *)0x0)) {
                      FUN_00512850();
                    }
                    else if (uVar20 + *param_1 < *param_2) {
                      uVar14 = *param_1 + 0xf;
                      pvVar11 = (void *)(uVar14 & 0xfffffff0);
                      *param_1 = (uVar14 & 0xfffffff0) + uVar20;
                      _memset(pvVar11,0,uVar20);
                      iVar6 = local_38;
                    }
                    else {
                      FUN_00512850();
                      iVar6 = local_38;
                    }
                    *(void **)(*(int *)((int)pvVar7 + 0x84) + iVar6 * 4) = pvVar11;
                    _memset(*(void **)(*(int *)((int)pvVar7 + 0x84) + iVar6 * 4),0,
                            (uint)*(byte *)((int)pvVar7 + 0x10));
                    local_38 = iVar6 + 1;
                  } while (local_38 < (int)(uint)*(byte *)((int)pvVar7 + 0x10));
                }
                FUN_00524f30(pvVar7,0,*local_28,*(undefined4 *)((int)pvVar7 + 0x84));
                FUN_00526800(&local_44,param_4);
              }
            }
            param_3 = (int *)((int)param_3 + 1);
          }
        }
        if (1 < *local_4c) {
          local_28 = (int *)**(undefined4 **)(local_4c + 4);
          local_18 = 0;
          local_14 = 0;
          local_10 = 0;
          local_c = 0;
          local_8 = 0.0;
          local_4 = 0;
          param_3 = (int *)0x1;
          if (1 < *local_4c) {
            do {
              iVar6 = *(int *)(*(int *)(local_4c + 4) + (int)param_3 * 4);
              iVar8 = 0;
              if (*(char *)(iVar6 + 0x10) != '\0') {
                iVar18 = 0;
                do {
                  iVar17 = *(int *)(iVar6 + 0x7c) + iVar18;
                  FUN_0051ba10(*(undefined4 *)(DAT_009238e4 + 100),iVar17 + 4,&local_18,local_28,
                               0xff,0,0);
                  if ((local_c & 0x10000) == 0) {
                    *(byte *)(iVar17 + 0x2b) = *(byte *)(iVar17 + 0x2b) & 0xfe;
                    *(undefined2 *)(iVar17 + 0x2c) = 0xffff;
                  }
                  else {
                    iVar19 = local_14 - *(int *)(iVar6 + 0x80);
                    *(short *)(iVar17 + 0x2c) =
                         ((short)(iVar19 / 0x24) + (short)(iVar19 >> 0x1f)) -
                         (short)((longlong)iVar19 * 0x38e38e39 >> 0x3f);
                    if (0.5 < local_8) {
                      *(byte *)(iVar17 + 0x2b) = *(byte *)(iVar17 + 0x2b) | 4;
                    }
                    else if (((char)local_10 != '\0') && (local_8 < 0.5)) {
                      *(byte *)(iVar17 + 0x2b) = *(byte *)(iVar17 + 0x2b) | 4;
                    }
                    iVar19 = local_14 - *(int *)(local_18 + 0x80);
                    *(byte *)(iVar17 + 0x2b) = *(byte *)(iVar17 + 0x2b) | 1;
                    *(short *)(iVar17 + 0x2c) =
                         ((short)(iVar19 / 0x24) + (short)(iVar19 >> 0x1f)) -
                         (short)((longlong)iVar19 * 0x38e38e39 >> 0x3f);
                    *(byte *)(iVar6 + 0x11) = *(byte *)(iVar6 + 0x11) | 2;
                  }
                  iVar8 = iVar8 + 1;
                  iVar18 = iVar18 + 0x5c;
                } while (iVar8 < (int)(uint)*(byte *)(iVar6 + 0x10));
              }
              if (((((*(byte *)(iVar6 + 0x11) & 2) != 0) && (DAT_009242a4 != (void *)0x0)) &&
                  (iVar8 = *(int *)((int)DAT_009242a4 + (int)param_3 * 4), iVar8 != 0)) &&
                 (iVar18 = 0, *(char *)(iVar6 + 0x10) != '\0')) {
                local_38 = 0;
                do {
                  iVar17 = *(int *)(iVar6 + 0x7c) + local_38;
                  if ((*(byte *)(iVar17 + 0x2b) & 1) == 0) {
                    iVar19 = 0;
                    local_30 = (int *)0x7f7fffff;
                    if (*(char *)(iVar6 + 0x10) != '\0') {
                      iVar21 = 0;
                      do {
                        pvVar7 = DAT_009242a4;
                        iVar15 = *(int *)(iVar6 + 0x7c) + iVar21;
                        if (((iVar17 != iVar15) && ((*(byte *)(iVar15 + 0x2b) & 1) != 0)) &&
                           (*(float *)(*(int *)(iVar8 + iVar18 * 4) + iVar19 * 4) < (float)local_30)
                           ) {
                          *(short *)(iVar17 + 0x2c) = (short)iVar19;
                          iVar8 = *(int *)((int)pvVar7 + (int)param_3 * 4);
                          local_30 = *(int **)(*(int *)(iVar8 + iVar18 * 4) + iVar19 * 4);
                        }
                        iVar19 = iVar19 + 1;
                        iVar21 = iVar21 + 0x5c;
                      } while (iVar19 < (int)(uint)*(byte *)(iVar6 + 0x10));
                    }
                  }
                  local_38 = local_38 + 0x5c;
                  iVar18 = iVar18 + 1;
                } while (iVar18 < (int)(uint)*(byte *)(iVar6 + 0x10));
              }
              param_3 = (int *)((int)param_3 + 1);
            } while ((int)param_3 < (int)(uint)*local_4c);
          }
        }
      }
    }
  }
  DAT_009242a4 = (void *)0x0;
  return local_4c;
}

