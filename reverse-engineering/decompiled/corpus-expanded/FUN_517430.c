/* Ghidra pseudocode, not original source.
 * ev_7610d2e5ecab5d7a95653def000f5e9425ca0c842a62593dc010feaabdcb80b1
 * Entry: 0x517430; label: FUN_00517430
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00517430(int param_1,undefined4 param_2,uint *param_3)

{
  undefined1 uVar1;
  char cVar2;
  byte bVar3;
  undefined2 uVar4;
  short sVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  uint uVar9;
  byte *pbVar10;
  uint uVar11;
  size_t sVar12;
  int iVar13;
  byte *pbVar14;
  void *pvVar15;
  int *piVar16;
  undefined4 *puVar17;
  undefined1 *_Dst;
  int *unaff_EDI;
  float10 fVar18;
  undefined8 uVar19;
  int local_120;
  float local_11c;
  byte *local_118;
  int local_114;
  int local_110;
  int local_10c;
  undefined4 local_108;
  undefined1 local_104 [256];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_120;
  local_108 = param_2;
  pbVar14 = (byte *)0x0;
  iVar6 = FUN_006217e0();
  if (iVar6 != 0) {
    local_118 = (byte *)0x0;
    if (((unaff_EDI == (int *)0x0) || (param_3 == (uint *)0x0)) || (*param_3 <= *unaff_EDI + 0x10U))
    {
      iVar6 = FUN_00512850();
    }
    else {
      uVar11 = *unaff_EDI + 0xf;
      pbVar14 = (byte *)(uVar11 & 0xfffffff0);
      *unaff_EDI = (uVar11 & 0xfffffff0) + 0x10;
      pbVar14[0] = 0;
      pbVar14[1] = 0;
      pbVar14[2] = 0;
      pbVar14[3] = 0;
      pbVar14[4] = 0;
      pbVar14[5] = 0;
      pbVar14[6] = 0;
      pbVar14[7] = 0;
      pbVar14[8] = 0;
      pbVar14[9] = 0;
      pbVar14[10] = 0;
      pbVar14[0xb] = 0;
      pbVar14[0xc] = 0;
      pbVar14[0xd] = 0;
      pbVar14[0xe] = 0;
      pbVar14[0xf] = 0;
      local_118 = pbVar14;
    }
    if (pbVar14 != (byte *)0x0) {
      *pbVar14 = (byte)iVar6;
      uVar7 = FUN_00517160();
      *(undefined4 *)(pbVar14 + 4) = uVar7;
      local_114 = 0;
      if (*pbVar14 != 0) {
        do {
          iVar6 = local_114;
          pvVar15 = (void *)0x0;
          if (((unaff_EDI == (int *)0x0) || (param_3 == (uint *)0x0)) ||
             (*param_3 <= *unaff_EDI + 0xa8U)) {
            FUN_00512850();
          }
          else {
            uVar11 = *unaff_EDI + 0xf;
            pvVar15 = (void *)(uVar11 & 0xfffffff0);
            *unaff_EDI = (uVar11 & 0xfffffff0) + 0xa8;
            _memset(pvVar15,0,0xa8);
          }
          *(void **)(*(int *)(local_118 + 4) + iVar6 * 4) = pvVar15;
          iVar6 = *(int *)(*(int *)(local_118 + 4) + iVar6 * 4);
          local_110 = iVar6;
          FUN_006216f0(iVar6,0x10);
          uVar1 = FUN_006218c0();
          *(undefined1 *)(iVar6 + 0x10) = uVar1;
          uVar1 = FUN_006218c0();
          *(undefined1 *)(iVar6 + 0x11) = uVar1;
          *(undefined1 *)(iVar6 + 0x15) = (undefined1)local_114;
          if (param_1 == 1) {
            cVar2 = FUN_006218c0();
            *(short *)(iVar6 + 0x12) = (short)cVar2;
          }
          else {
            uVar4 = FUN_00621860();
            *(undefined2 *)(iVar6 + 0x12) = uVar4;
          }
          if (*(ushort *)(iVar6 + 0x12) != 0) {
            sVar12 = (uint)*(ushort *)(iVar6 + 0x12) * 0x24;
            pvVar15 = (void *)0x0;
            if (((unaff_EDI == (int *)0x0) || (param_3 == (uint *)0x0)) ||
               (*param_3 <= *unaff_EDI + sVar12)) {
              FUN_00512850();
            }
            else {
              uVar11 = *unaff_EDI + 0xf;
              pvVar15 = (void *)(uVar11 & 0xfffffff0);
              *unaff_EDI = (uVar11 & 0xfffffff0) + sVar12;
              _memset(pvVar15,0,sVar12);
            }
            *(void **)(iVar6 + 0x80) = pvVar15;
            local_120 = 0;
            if (*(short *)(iVar6 + 0x12) != 0) {
              iVar13 = 0;
              do {
                piVar16 = (int *)(*(int *)(iVar6 + 0x80) + iVar13);
                uVar1 = FUN_006218c0();
                *(undefined1 *)(piVar16 + 4) = uVar1;
                uVar1 = FUN_006218c0();
                *(undefined1 *)((int)piVar16 + 0x11) = uVar1;
                if (param_1 < 0xc) {
                  if (param_1 < 9) {
                    cVar2 = FUN_006218c0();
                    *piVar16 = (int)cVar2;
                    cVar2 = FUN_006218c0();
                    piVar16[1] = (int)cVar2;
                  }
                  else {
                    sVar5 = FUN_00621860();
                    *piVar16 = (int)sVar5;
                    sVar5 = FUN_00621860();
                    piVar16[1] = (int)sVar5;
                  }
                }
                else {
                  iVar8 = FUN_006217e0();
                  *piVar16 = iVar8;
                  iVar8 = FUN_006217e0();
                  piVar16[1] = iVar8;
                }
                piVar16[2] = *piVar16;
                piVar16[3] = piVar16[1];
                uVar4 = FUN_00621860();
                *(undefined2 *)((int)piVar16 + 0x12) = uVar4;
                uVar4 = FUN_00621860();
                *(undefined2 *)(piVar16 + 5) = uVar4;
                fVar18 = (float10)FUN_006217a0();
                piVar16[6] = (int)(float)fVar18;
                fVar18 = (float10)FUN_006217a0();
                local_11c = (float)fVar18;
                piVar16[7] = (int)local_11c;
                if (local_11c == 0.0) {
                  piVar16[7] = 0x3727c5ac;
                }
                local_120 = local_120 + 1;
                iVar13 = iVar13 + 0x24;
              } while (local_120 < (int)(uint)*(ushort *)(iVar6 + 0x12));
            }
          }
          if (param_1 == 1) {
            FUN_006218c0();
          }
          if (*(byte *)(iVar6 + 0x10) != 0) {
            sVar12 = (uint)*(byte *)(iVar6 + 0x10) * 0x5c;
            pvVar15 = (void *)0x0;
            if (((unaff_EDI == (int *)0x0) || (param_3 == (uint *)0x0)) ||
               (*param_3 <= *unaff_EDI + sVar12)) {
              FUN_00512850();
            }
            else {
              uVar11 = *unaff_EDI + 0xf;
              pvVar15 = (void *)(uVar11 & 0xfffffff0);
              *unaff_EDI = (uVar11 & 0xfffffff0) + sVar12;
              _memset(pvVar15,0,sVar12);
            }
            *(void **)(iVar6 + 0x7c) = pvVar15;
            local_120 = 0;
            if (*(char *)(iVar6 + 0x10) != '\0') {
              local_10c = 0;
              do {
                puVar17 = (undefined4 *)(*(int *)(iVar6 + 0x7c) + local_10c);
                local_11c = (float)FUN_006217e0();
                if (local_11c != 0.0) {
                  sVar12 = (int)local_11c + 1;
                  pvVar15 = (void *)0x0;
                  if (((unaff_EDI == (int *)0x0) || (param_3 == (uint *)0x0)) ||
                     (*param_3 <= *unaff_EDI + sVar12)) {
                    FUN_00512850();
                  }
                  else {
                    pvVar15 = (void *)(*unaff_EDI + 0xfU & 0xfffffff0);
                    *unaff_EDI = (*unaff_EDI + 0xfU & 0xfffffff0) + sVar12;
                    _memset(pvVar15,0,sVar12);
                  }
                  *puVar17 = pvVar15;
                  FUN_006216f0(pvVar15,local_11c);
                }
                fVar18 = (float10)FUN_006217a0();
                puVar17[1] = (float)fVar18;
                fVar18 = (float10)FUN_006217a0();
                puVar17[2] = (float)fVar18;
                fVar18 = (float10)FUN_006217a0();
                puVar17[3] = (float)fVar18;
                fVar18 = (float10)FUN_006217a0();
                local_11c = (float)fVar18;
                puVar17[4] = local_11c;
                puVar17[5] = local_11c * local_11c;
                if (param_1 < 8) {
                  puVar17[6] = (float)puVar17[2] - _DAT_00801c58;
                  fVar18 = (float10)(float)puVar17[2] + (float10)_DAT_00801c58;
                }
                else {
                  fVar18 = (float10)FUN_006217a0();
                  puVar17[6] = (float)fVar18;
                  fVar18 = (float10)FUN_006217a0();
                }
                puVar17[8] = (float)fVar18;
                puVar17[7] = (float)puVar17[6] - (float)puVar17[2];
                puVar17[9] = (float)puVar17[8] - (float)puVar17[2];
                uVar1 = FUN_006218c0();
                *(undefined1 *)(puVar17 + 10) = uVar1;
                uVar1 = FUN_006218c0();
                *(undefined1 *)((int)puVar17 + 0x29) = uVar1;
                FUN_006218c0();
                bVar3 = FUN_006218c0();
                *(byte *)((int)puVar17 + 0x2b) = bVar3 & 0xf9;
                uVar4 = FUN_00621860();
                *(undefined2 *)(puVar17 + 0xb) = uVar4;
                if (param_1 < 0x13) {
                  FUN_006218c0();
                  *(undefined1 *)(puVar17 + 0xc) = 0xff;
                }
                else {
                  uVar1 = FUN_006218c0();
                  *(undefined1 *)(puVar17 + 0xc) = uVar1;
                }
                cVar2 = FUN_006218c0();
                if (cVar2 != 0) {
                  FUN_006216f0(local_104,(int)cVar2);
                  iVar13 = FUN_005cf5b0(local_108,puVar17 + 0x10,local_104,1);
                  *(bool *)((int)puVar17 + 0x2a) = iVar13 != 0;
                  fVar18 = (float10)FUN_006217a0();
                  puVar17[0x13] = (float)fVar18;
                  fVar18 = (float10)FUN_006217a0();
                  puVar17[0x14] = (float)fVar18;
                  fVar18 = (float10)FUN_006217a0();
                  puVar17[0x15] = (float)fVar18;
                }
                if ((*(int *)(iVar6 + 0x80) != 0) && (*(byte *)(puVar17 + 10) != 0)) {
                  sVar12 = (uint)*(byte *)(puVar17 + 10) * 4;
                  pvVar15 = (void *)0x0;
                  if ((unaff_EDI == (int *)0x0) ||
                     ((param_3 == (uint *)0x0 || (*param_3 <= *unaff_EDI + sVar12)))) {
                    FUN_00512850();
                  }
                  else {
                    pvVar15 = (void *)(*unaff_EDI + 0xfU & 0xfffffff0);
                    *unaff_EDI = (*unaff_EDI + 0xfU & 0xfffffff0) + sVar12;
                    _memset(pvVar15,0,sVar12);
                  }
                  puVar17[0xd] = pvVar15;
                  iVar13 = 0;
                  if (*(char *)(puVar17 + 10) != '\0') {
                    do {
                      sVar5 = FUN_00621860();
                      *(int *)(puVar17[0xd] + iVar13 * 4) = *(int *)(iVar6 + 0x80) + sVar5 * 0x24;
                      iVar13 = iVar13 + 1;
                    } while (iVar13 < (int)(uint)*(byte *)(puVar17 + 10));
                  }
                  if ((*(byte *)(puVar17 + 10) & 1) != 0) {
                    FUN_00621860();
                  }
                }
                if (4 < param_1) {
                  uVar4 = FUN_00621860();
                  *(undefined2 *)(puVar17 + 0x16) = uVar4;
                  uVar4 = FUN_00621860();
                  *(undefined2 *)((int)puVar17 + 0x5a) = uVar4;
                }
                local_10c = local_10c + 0x5c;
                *(undefined1 *)((int)puVar17 + 0x2e) = 0xff;
                *(undefined1 *)((int)puVar17 + 0x2f) = 0xff;
                local_120 = local_120 + 1;
              } while (local_120 < (int)(uint)*(byte *)(iVar6 + 0x10));
            }
            FUN_00517220(iVar6);
          }
          sVar12 = (uint)*(byte *)(iVar6 + 0x10) * 4;
          pvVar15 = (void *)0x0;
          if (((unaff_EDI == (int *)0x0) || (param_3 == (uint *)0x0)) ||
             (*param_3 <= sVar12 + *unaff_EDI)) {
            FUN_00512850();
          }
          else {
            uVar11 = *unaff_EDI + 0xf;
            pvVar15 = (void *)(uVar11 & 0xfffffff0);
            *unaff_EDI = (uVar11 & 0xfffffff0) + sVar12;
            _memset(pvVar15,0,sVar12);
          }
          *(void **)(iVar6 + 0x84) = pvVar15;
          local_120 = 0;
          if (*(char *)(iVar6 + 0x10) != '\0') {
            do {
              iVar13 = local_120;
              uVar11 = (uint)*(byte *)(iVar6 + 0x10);
              pvVar15 = (void *)0x0;
              if ((unaff_EDI == (int *)0x0) || (param_3 == (uint *)0x0)) {
                FUN_00512850();
              }
              else if (uVar11 + *unaff_EDI < *param_3) {
                uVar9 = *unaff_EDI + 0xf;
                pvVar15 = (void *)(uVar9 & 0xfffffff0);
                *unaff_EDI = (uVar9 & 0xfffffff0) + uVar11;
                _memset(pvVar15,0,uVar11);
                iVar13 = local_120;
              }
              else {
                FUN_00512850();
                iVar13 = local_120;
              }
              *(void **)(*(int *)(iVar6 + 0x84) + iVar13 * 4) = pvVar15;
              FUN_006216f0(*(undefined4 *)(*(int *)(iVar6 + 0x84) + iVar13 * 4),
                           *(undefined1 *)(iVar6 + 0x10));
              local_120 = iVar13 + 1;
            } while (local_120 < (int)(uint)*(byte *)(iVar6 + 0x10));
          }
          if (4 < param_1) {
            bVar3 = FUN_006218c0();
            *(byte *)(local_110 + 0x14) = bVar3;
            if (bVar3 != 0) {
              sVar12 = (uint)bVar3 * 0x28;
              pvVar15 = (void *)0x0;
              if (((unaff_EDI == (int *)0x0) || (param_3 == (uint *)0x0)) ||
                 (*param_3 <= sVar12 + *unaff_EDI)) {
                FUN_00512850();
              }
              else {
                uVar11 = *unaff_EDI + 0xf;
                pvVar15 = (void *)(uVar11 & 0xfffffff0);
                *unaff_EDI = (uVar11 & 0xfffffff0) + sVar12;
                _memset(pvVar15,0,sVar12);
              }
              *(void **)(local_110 + 0x88) = pvVar15;
              local_120 = 0;
              if (*(char *)(local_110 + 0x14) != '\0') {
                local_11c = 0.0;
                do {
                  puVar17 = (undefined4 *)(*(int *)(local_110 + 0x88) + (int)local_11c);
                  cVar2 = FUN_006218c0();
                  sVar12 = (size_t)cVar2;
                  if (sVar12 != 0) {
                    pvVar15 = (void *)0x0;
                    if (((unaff_EDI == (int *)0x0) || (param_3 == (uint *)0x0)) ||
                       (*param_3 <= *unaff_EDI + sVar12)) {
                      FUN_00512850();
                    }
                    else {
                      uVar11 = *unaff_EDI + 0xf;
                      pvVar15 = (void *)(uVar11 & 0xfffffff0);
                      *unaff_EDI = (uVar11 & 0xfffffff0) + sVar12;
                      _memset(pvVar15,0,sVar12);
                    }
                    *puVar17 = pvVar15;
                    FUN_006216f0(pvVar15,sVar12);
                    uVar1 = FUN_006218c0();
                    *(undefined1 *)(puVar17 + 4) = uVar1;
                    uVar1 = FUN_006218c0();
                    *(undefined1 *)((int)puVar17 + 0x11) = uVar1;
                    FUN_006218c0();
                    FUN_006218c0();
                    if ((*(byte *)(local_110 + 0x10) != 0) && (*(char *)(puVar17 + 4) != '\0')) {
                      pvVar15 = (void *)0x0;
                      uVar11 = (uint)*(byte *)(local_110 + 0x10);
                      if ((unaff_EDI == (int *)0x0) ||
                         ((param_3 == (uint *)0x0 || (*param_3 <= uVar11 + *unaff_EDI)))) {
                        FUN_00512850();
                      }
                      else {
                        uVar9 = *unaff_EDI + 0xf;
                        pvVar15 = (void *)(uVar9 & 0xfffffff0);
                        *unaff_EDI = (uVar9 & 0xfffffff0) + uVar11;
                        _memset(pvVar15,0,uVar11);
                      }
                      puVar17[1] = pvVar15;
                      FUN_006216f0(pvVar15,*(undefined1 *)(local_110 + 0x10));
                      uVar11 = (uint)*(byte *)(puVar17 + 4);
                      pvVar15 = (void *)0x0;
                      if (((unaff_EDI == (int *)0x0) || (param_3 == (uint *)0x0)) ||
                         (*param_3 <= uVar11 + *unaff_EDI)) {
                        FUN_00512850();
                      }
                      else {
                        uVar9 = *unaff_EDI + 0xf;
                        pvVar15 = (void *)(uVar9 & 0xfffffff0);
                        *unaff_EDI = (uVar9 & 0xfffffff0) + uVar11;
                        _memset(pvVar15,0,uVar11);
                      }
                      puVar17[2] = pvVar15;
                      FUN_006216f0(pvVar15,*(undefined1 *)(puVar17 + 4));
                      sVar12 = (uint)*(byte *)(puVar17 + 4) * 4;
                      pvVar15 = (void *)0x0;
                      if (((unaff_EDI == (int *)0x0) || (param_3 == (uint *)0x0)) ||
                         (*param_3 <= sVar12 + *unaff_EDI)) {
                        FUN_00512850();
                      }
                      else {
                        uVar11 = *unaff_EDI + 0xf;
                        pvVar15 = (void *)(uVar11 & 0xfffffff0);
                        *unaff_EDI = (uVar11 & 0xfffffff0) + sVar12;
                        _memset(pvVar15,0,sVar12);
                      }
                      puVar17[5] = pvVar15;
                      local_10c = 0;
                      if (*(char *)(puVar17 + 4) != '\0') {
                        do {
                          iVar6 = local_10c;
                          uVar11 = (uint)*(byte *)(puVar17 + 4);
                          pvVar15 = (void *)0x0;
                          if ((unaff_EDI == (int *)0x0) || (param_3 == (uint *)0x0)) {
                            FUN_00512850();
                          }
                          else if (uVar11 + *unaff_EDI < *param_3) {
                            uVar9 = *unaff_EDI + 0xf;
                            pvVar15 = (void *)(uVar9 & 0xfffffff0);
                            *unaff_EDI = (uVar9 & 0xfffffff0) + uVar11;
                            _memset(pvVar15,0,uVar11);
                            iVar6 = local_10c;
                          }
                          else {
                            FUN_00512850();
                            iVar6 = local_10c;
                          }
                          *(void **)(puVar17[5] + iVar6 * 4) = pvVar15;
                          FUN_006216f0(*(undefined4 *)(puVar17[5] + iVar6 * 4),
                                       *(undefined1 *)(puVar17 + 4));
                          local_10c = iVar6 + 1;
                        } while (local_10c < (int)(uint)*(byte *)(puVar17 + 4));
                      }
                      if (*(byte *)((int)puVar17 + 0x11) != 0) {
                        pvVar15 = (void *)0x0;
                        uVar11 = (uint)*(byte *)((int)puVar17 + 0x11);
                        if (((unaff_EDI == (int *)0x0) || (param_3 == (uint *)0x0)) ||
                           (*param_3 <= uVar11 + *unaff_EDI)) {
                          FUN_00512850();
                        }
                        else {
                          uVar9 = *unaff_EDI + 0xf;
                          pvVar15 = (void *)(uVar9 & 0xfffffff0);
                          *unaff_EDI = (uVar9 & 0xfffffff0) + uVar11;
                          _memset(pvVar15,0,uVar11);
                        }
                        puVar17[3] = pvVar15;
                        FUN_006216f0(pvVar15,*(undefined1 *)((int)puVar17 + 0x11));
                      }
                    }
                  }
                  cVar2 = FUN_006218c0();
                  iVar6 = (int)cVar2;
                  if (0 < iVar6) {
                    do {
                      cVar2 = FUN_006218c0();
                      FUN_006216f0(local_104,(int)cVar2);
                      if (DAT_00923888 != (code *)0x0) {
                        bVar3 = (*DAT_00923888)(local_104);
                        if (bVar3 < 0x40) {
                          uVar19 = __allshl();
                          uVar11 = (uint)((ulonglong)uVar19 >> 0x20);
                          puVar17[6] = puVar17[6] | (uint)uVar19;
                          puVar17[7] = puVar17[7] | uVar11;
                          puVar17[8] = puVar17[8] | (uint)uVar19;
                          puVar17[9] = puVar17[9] | uVar11;
                        }
                        else {
                          puVar17[9] = puVar17[9] | 0x80000000;
                          puVar17[6] = 0xffffffff;
                          puVar17[7] = 0xffffffff;
                          puVar17[8] = puVar17[8];
                        }
                      }
                      iVar6 = iVar6 + -1;
                    } while (iVar6 != 0);
                  }
                  local_11c = (float)((int)local_11c + 0x28);
                  local_120 = local_120 + 1;
                } while (local_120 < (int)(uint)*(byte *)(local_110 + 0x14));
              }
            }
          }
          if (0x12 < param_1) {
            bVar3 = FUN_006218c0();
            iVar6 = local_110;
            *(byte *)(local_110 + 0x7a) = bVar3;
            if (bVar3 != 0) {
              sVar12 = (uint)bVar3 * 4;
              _Dst = (undefined1 *)0x0;
              if (((unaff_EDI == (int *)0x0) || (param_3 == (uint *)0x0)) ||
                 (*param_3 <= sVar12 + *unaff_EDI)) {
                FUN_00512850();
              }
              else {
                uVar11 = *unaff_EDI + 0xf;
                _Dst = (undefined1 *)(uVar11 & 0xfffffff0);
                *unaff_EDI = (uVar11 & 0xfffffff0) + sVar12;
                _memset(_Dst,0,sVar12);
              }
              iVar13 = 0;
              *(undefined1 **)(iVar6 + 0x8c) = _Dst;
              if (*(char *)(iVar6 + 0x7a) != '\0') {
                do {
                  uVar1 = FUN_006218e0();
                  *_Dst = uVar1;
                  uVar4 = FUN_00621860();
                  *(undefined2 *)(_Dst + 2) = uVar4;
                  iVar13 = iVar13 + 1;
                  _Dst = _Dst + 4;
                } while (iVar13 < (int)(uint)*(byte *)(iVar6 + 0x7a));
              }
            }
          }
          local_114 = local_114 + 1;
        } while (local_114 < (int)(uint)*local_118);
      }
      if (0x12 < param_1) {
        sVar5 = FUN_00621860();
        pbVar14 = local_118;
        *(short *)(local_118 + 2) = sVar5;
        if (sVar5 != 0) {
          pbVar10 = (byte *)FUN_00517160();
          *(byte **)(pbVar14 + 0xc) = pbVar10;
          local_114 = 0;
          if (*(short *)(pbVar14 + 2) != 0) {
            do {
              bVar3 = FUN_006218c0();
              *pbVar10 = bVar3;
              if (bVar3 != 0) {
                sVar12 = (uint)bVar3 * 4;
                pvVar15 = (void *)0x0;
                if ((unaff_EDI == (int *)0x0) || (param_3 == (uint *)0x0)) {
                  FUN_00512850();
                }
                else if (sVar12 + *unaff_EDI < *param_3) {
                  uVar11 = *unaff_EDI + 0xf;
                  pvVar15 = (void *)(uVar11 & 0xfffffff0);
                  *unaff_EDI = (uVar11 & 0xfffffff0) + sVar12;
                  _memset(pvVar15,0,sVar12);
                  pbVar14 = local_118;
                }
                else {
                  FUN_00512850();
                  pbVar14 = local_118;
                }
                *(void **)(pbVar10 + 4) = pvVar15;
                iVar6 = 0;
                if (*pbVar10 != 0) {
                  do {
                    cVar2 = FUN_006218c0();
                    *(undefined4 *)(*(int *)(pbVar10 + 4) + iVar6 * 4) =
                         *(undefined4 *)(*(int *)(pbVar14 + 4) + cVar2 * 4);
                    iVar6 = iVar6 + 1;
                  } while (iVar6 < (int)(uint)*pbVar10);
                }
              }
              local_114 = local_114 + 1;
              pbVar10 = pbVar10 + 8;
            } while (local_114 < (int)(uint)*(ushort *)(pbVar14 + 2));
          }
        }
        __security_check_cookie(local_4 ^ (uint)&local_120);
        return;
      }
      __security_check_cookie(local_4 ^ (uint)&local_120);
      return;
    }
  }
  __security_check_cookie(local_4 ^ (uint)&local_120);
  return;
}

