/* Ghidra analysis pseudocode, not original source.
 * ev_988aedce7a102035a37775149c4794654cf73d0aa98e786da352e425eaa98523
 * Entry: 0x439a50; label: FUN_00439a50
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00439a50(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
                 int param_7,uint param_8,uint param_9)

{
  uint *puVar1;
  byte bVar2;
  short sVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  float fVar7;
  float fVar8;
  bool bVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  bool bVar14;
  float10 fVar15;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 extraout_ST0_01;
  float10 extraout_ST0_02;
  float10 extraout_ST0_03;
  float10 extraout_ST0_04;
  float10 extraout_ST1;
  float10 extraout_ST1_00;
  undefined8 uVar16;
  float local_30;
  int local_2c;
  float local_24;
  int local_20;
  int *local_18;
  float local_c;
  float local_8;
  float local_4;
  
  fVar15 = (float10)0;
  local_c = (float)fVar15;
  iVar12 = 0;
  local_8 = (float)fVar15;
  local_4 = (float)fVar15;
  local_20 = 0x20;
  if ((param_1 == 0) || (param_4 == 0)) {
    return;
  }
  bVar14 = param_6 == 0;
  if ((((DAT_00876cd8 != 0) && ((*(uint *)(DAT_00876cd8 + 0x1fc) & 0x1000) != 0)) &&
      ((*(byte *)(DAT_00876cd8 + 0x1f8) & 5) == 0)) &&
     ((*(uint *)(*(int *)(*(int *)(DAT_00876cd8 + 0x54) + 0x24) + 0x90) & 0x8000) == 0)) {
    iVar13 = DAT_00876cd8;
    if (0 < param_6) {
      do {
        piVar4 = *(int **)(param_7 + iVar12 * 4);
        uVar16 = __allshl();
        if (((uint)uVar16 & piVar4[0xaa]) == 0 &&
            ((uint)((ulonglong)uVar16 >> 0x20) & piVar4[0xab]) == 0) {
          if (((((*(char *)((int)*(short *)(*piVar4 + 0x106a) + *(int *)(PTR_DAT_00802c54 + 0x2a94))
                  != '\0') &&
                (local_c = _DAT_00876cb8 - (float)piVar4[0x20], local_c < (float)piVar4[0x8d])) &&
               ((local_4 = _DAT_00876cc0 - (float)piVar4[0x22], local_4 < (float)piVar4[0x8d] &&
                ((local_8 = _DAT_00876cbc - (float)piVar4[0x21], local_8 < (float)piVar4[0x8e] &&
                 ((float)piVar4[0x8f] < local_8)))))) &&
              (local_c * local_c + local_4 * local_4 < (float)piVar4[0x8d] * (float)piVar4[0x8d]))
             && ((bVar2 = *(byte *)((int)piVar4 + 0x28d), uVar16 = __allshl(),
                 ((uint)uVar16 &
                 *(uint *)(*(int *)(PTR_DAT_00802c54 + 0x298c) + 8 + (uint)bVar2 * 8)) != 0 ||
                 ((uint)((ulonglong)uVar16 >> 0x20) &
                 *(uint *)(*(int *)(PTR_DAT_00802c54 + 0x298c) + 0xc + (uint)bVar2 * 8)) != 0 ||
                 (fVar7 = *(float *)(iVar13 + 0x88) - (float)piVar4[0x22],
                 fVar8 = *(float *)(iVar13 + 0x80) - (float)piVar4[0x20],
                 (float)piVar4[0x8c] * (float)piVar4[0x8c] < fVar8 * fVar8 + fVar7 * fVar7)))) {
            *(int *)(*piVar4 + 0xec0) = iVar13;
            uVar16 = __allshl();
            piVar4[0xaa] = piVar4[0xaa] | (uint)uVar16;
            piVar4[0xab] = piVar4[0xab] | (uint)((ulonglong)uVar16 >> 0x20);
            param_8 = param_8 | piVar4[0xaa];
            param_9 = param_9 | piVar4[0xab];
            *(float *)(*piVar4 + 0xec4) = (float)extraout_ST1_00;
            iVar13 = DAT_00876cd8;
          }
        }
        else {
          *(int *)(*piVar4 + 0xec0) = iVar13;
          *(float *)(*piVar4 + 0xec4) = (float)extraout_ST1;
          iVar13 = DAT_00876cd8;
        }
        iVar12 = iVar12 + 1;
      } while (iVar12 < param_6);
    }
    _DAT_00876cdc = _DAT_00876cdc - _DAT_00925018;
    if ((float10)_DAT_00876cdc <= fVar15) {
      DAT_00876cd8 = 0;
    }
  }
  if (param_4 <= (int)(uint)*(byte *)(param_1 + 0x1385)) {
    *(undefined1 *)(param_1 + 0x1385) = 0;
  }
  do {
    if (bVar14) goto LAB_0043a573;
    bVar2 = *(byte *)(param_1 + 0x1385);
    while ((int)(uint)bVar2 < param_4) {
      if (local_20 < 1) goto LAB_0043a563;
      local_24 = 1e+09;
      piVar4 = *(int **)(param_5 + (uint)*(byte *)(param_1 + 0x1385) * 4);
      local_18 = (int *)0x0;
      local_2c = 0;
      if (0 < param_6) {
        local_20 = local_20 - param_6;
        do {
          piVar5 = *(int **)(param_7 + local_2c * 4);
          bVar9 = false;
          if ((piVar5 != piVar4) && (*(int **)(piVar5[1] + 0xec) != piVar4)) {
            if ((*(byte *)(*piVar5 + 0xef0) & 2) == 0) {
              uVar16 = __allshl();
              uVar10 = (uint)((ulonglong)uVar16 >> 0x20);
              if ((piVar4[0xaa] & (uint)uVar16) == 0 && (piVar4[0xab] & uVar10) == 0) {
                if ((*(uint *)(*(int *)(PTR_DAT_00802c54 + 0x298c) + 8 +
                              (uint)*(byte *)((int)piVar4 + 0x28d) * 8) & (uint)uVar16) != 0 ||
                    (*(uint *)(*(int *)(PTR_DAT_00802c54 + 0x298c) + 0xc +
                              (uint)*(byte *)((int)piVar4 + 0x28d) * 8) & uVar10) != 0) {
                  fVar15 = (float10)FUN_005becc0(piVar5 + 0x17,piVar4 + 0x17,&local_c);
                  bVar9 = true;
                  iVar12 = FUN_004398f0(piVar4,piVar5,(float)fVar15,param_8,param_9,local_c,local_4)
                  ;
                  if (iVar12 != 0) {
                    uVar16 = __allshl();
                    piVar4[0xaa] = piVar4[0xaa] | (uint)uVar16;
                    piVar4[0xab] = piVar4[0xab] | (uint)((ulonglong)uVar16 >> 0x20);
                    param_8 = param_8 | piVar4[0xaa];
                    param_9 = param_9 | piVar4[0xab];
                  }
                }
              }
              else {
                fVar15 = (float10)FUN_005becc0(piVar5 + 0x17,piVar4 + 0x17,&local_c);
                bVar9 = true;
                if ((float)piVar4[0x8c] + (float)piVar5[0x90] < (float)fVar15 !=
                    ((float)piVar4[0x8c] + (float)piVar5[0x90] == (float)fVar15)) goto LAB_00439e3c;
              }
            }
            else {
LAB_00439e3c:
              uVar16 = __allshl();
              piVar4[0xaa] = piVar4[0xaa] & ~(uint)uVar16;
              piVar4[0xab] = piVar4[0xab] & ~(uint)((ulonglong)uVar16 >> 0x20);
            }
            if ((*(byte *)(*piVar4 + 0xef0) & 2) == 0) {
              if (*(int **)(*piVar5 + 0xec0) == piVar4) {
                uVar16 = __allshl();
                piVar5[0xaa] = piVar5[0xaa] | (uint)uVar16;
                piVar5[0xab] = piVar5[0xab] | (uint)((ulonglong)uVar16 >> 0x20);
                param_8 = param_8 | piVar5[0xaa];
                param_9 = param_9 | piVar5[0xab];
              }
              else {
                uVar16 = __allshl();
                uVar10 = (uint)((ulonglong)uVar16 >> 0x20);
                if (((uint)uVar16 & piVar5[0xaa]) == 0 && (uVar10 & piVar5[0xab]) == 0) {
                  if ((*(uint *)(*(int *)(PTR_DAT_00802c54 + 0x298c) + 8 +
                                (uint)*(byte *)((int)piVar5 + 0x28d) * 8) & (uint)uVar16) != 0 ||
                      (*(uint *)(*(int *)(PTR_DAT_00802c54 + 0x298c) + 0xc +
                                (uint)*(byte *)((int)piVar5 + 0x28d) * 8) & uVar10) != 0) {
                    fVar15 = extraout_ST0;
                    if (!bVar9) {
                      fVar15 = (float10)FUN_005becc0(piVar5 + 0x17,piVar4 + 0x17,&local_c);
                      fVar15 = (float10)(float)fVar15;
                    }
                    bVar9 = true;
                    iVar12 = FUN_004398f0(piVar5,piVar4,(float)fVar15,param_8,param_9,-local_c,
                                          -local_4);
                    if (iVar12 != 0) {
                      uVar16 = __allshl();
                      piVar5[0xaa] = piVar5[0xaa] | (uint)uVar16;
                      piVar5[0xab] = piVar5[0xab] | (uint)((ulonglong)uVar16 >> 0x20);
                      param_8 = param_8 | piVar5[0xaa];
                      param_9 = param_9 | piVar5[0xab];
                    }
                  }
                }
                else {
                  fVar15 = extraout_ST0;
                  if (!bVar9) {
                    fVar15 = (float10)FUN_005becc0(piVar5 + 0x17,piVar4 + 0x17,&local_c);
                    fVar15 = (float10)(float)fVar15;
                  }
                  bVar9 = true;
                  if ((float10)(float)piVar4[0x90] + (float10)(float)piVar5[0x8c] < fVar15 !=
                      ((float10)(float)piVar4[0x90] + (float10)(float)piVar5[0x8c] == fVar15))
                  goto LAB_00439fb9;
                }
              }
            }
            else {
LAB_00439fb9:
              uVar16 = __allshl();
              piVar5[0xaa] = piVar5[0xaa] & ~(uint)uVar16;
              piVar5[0xab] = piVar5[0xab] & ~(uint)((ulonglong)uVar16 >> 0x20);
            }
            uVar16 = __allshl();
            if ((((uint)uVar16 & piVar4[0xaa]) != 0 ||
                 ((uint)((ulonglong)uVar16 >> 0x20) & piVar4[0xab]) != 0) ||
               (uVar16 = __allshl(),
               ((uint)uVar16 & piVar5[0xaa]) != 0 ||
               ((uint)((ulonglong)uVar16 >> 0x20) & piVar5[0xab]) != 0)) {
              if (!bVar9) {
                FUN_005becc0(piVar5 + 0x17,piVar4 + 0x17,&local_c);
              }
              iVar12 = *piVar5;
              sVar3 = *(short *)(iVar12 + 0x1064);
              if ((sVar3 == DAT_007f197c) || (sVar3 == DAT_007f1a30)) {
                iVar12 = FUN_004a60b0(*piVar4);
                if (iVar12 == 0) {
                  iVar12 = *piVar5;
                  uVar16 = __allshl();
                  puVar1 = (uint *)(iVar12 + 0xeb8);
                  *puVar1 = *puVar1 | (uint)uVar16;
                  puVar1 = (uint *)(iVar12 + 0xebc);
                  *puVar1 = *puVar1 | (uint)((ulonglong)uVar16 >> 0x20);
                }
              }
              else if ((((*(uint *)(piVar4[0x15] + 4) & 0x80000) != 0) ||
                       ((((*(byte *)(iVar12 + 0xeef) & 1) != 0 && (*piVar4 != DAT_0093d810)) &&
                        (*piVar4 != DAT_0093d814)))) ||
                      ((*(short *)(*piVar4 + 0x1064) == DAT_007f191c && (sVar3 != DAT_007f1914)))) {
                uVar16 = __allshl();
                *(uint *)(iVar12 + 0xeb8) = *(uint *)(iVar12 + 0xeb8) | (uint)uVar16;
                *(uint *)(iVar12 + 0xebc) =
                     *(uint *)(iVar12 + 0xebc) | (uint)((ulonglong)uVar16 >> 0x20);
              }
              uVar16 = __allshl();
              if (((uint)uVar16 & *(uint *)(*piVar5 + 0xeb8)) == 0 &&
                  ((uint)((ulonglong)uVar16 >> 0x20) & *(uint *)(*piVar5 + 0xebc)) == 0) {
                if (extraout_ST0_00 < (float10)*(float *)(piVar5[1] + 0xe0)) {
                  *(int **)(piVar5[1] + 0xdc) = piVar4;
                  *(float *)(piVar5[1] + 0xe0) = (float)extraout_ST0_00;
                }
                fVar15 = extraout_ST0_00;
                if (*(int **)(piVar5[1] + 0xe4) == piVar4) {
                  fVar15 = extraout_ST0_00 - (float10)_DAT_007f67d0;
                }
                local_30 = (float)fVar15;
                uVar16 = __allshl();
                uVar10 = (uint)((ulonglong)uVar16 >> 0x20);
                if (((uint)uVar16 & piVar5[0xaa]) != 0 || (uVar10 & piVar5[0xab]) != 0) {
                  iVar12 = piVar5[1];
                  if (*(int *)(iVar12 + 0xec) == 0) {
                    fVar7 = local_24;
                    if ((((*(uint *)(iVar12 + 0x1e8) & 0x20000) == 0) ||
                        ((*(uint *)(*(int *)(PTR_DAT_00802c54 + 0x298c) + 8 +
                                   (uint)*(byte *)((int)piVar5 + 0x28d) * 8) & (uint)uVar16) != 0 ||
                         (*(uint *)(*(int *)(PTR_DAT_00802c54 + 0x298c) + 0xc +
                                   (uint)*(byte *)((int)piVar5 + 0x28d) * 8) & uVar10) != 0)) ||
                       (*(int **)(*piVar5 + 0xec0) == piVar4)) {
LAB_0043a2d1:
                      if (local_30 < fVar7) goto LAB_0043a2da;
                    }
                  }
                  else if (((*(byte *)(piVar4 + 0x7f) & 0x80) != 0) &&
                          ((*(uint *)(*piVar5 + 0xeec) & 0x40000000) != 0)) {
                    if ((*(byte *)(*(int *)(iVar12 + 0xec) + 0x1fc) & 0x80) != 0) {
                      fVar7 = *(float *)(iVar12 + 0xf0);
                      goto LAB_0043a2d1;
                    }
LAB_0043a2da:
                    local_24 = (float)extraout_ST0_01;
                    local_18 = piVar5;
                  }
                }
              }
              if (((*(short *)(*piVar5 + 0x1064) == DAT_007f197c) ||
                  (*(short *)(*piVar5 + 0x1064) == DAT_007f1a30)) ||
                 ((*(uint *)(piVar5[0x15] + 4) & 0x80000) != 0)) {
                iVar12 = *piVar4;
                uVar16 = __allshl();
                puVar1 = (uint *)(iVar12 + 0xeb8);
                *puVar1 = *puVar1 | (uint)uVar16;
                puVar1 = (uint *)(iVar12 + 0xebc);
                *puVar1 = *puVar1 | (uint)((ulonglong)uVar16 >> 0x20);
              }
              uVar16 = __allshl();
              if (((uint)uVar16 & *(uint *)(*piVar4 + 0xeb8)) == 0 &&
                  ((uint)((ulonglong)uVar16 >> 0x20) & *(uint *)(*piVar4 + 0xebc)) == 0) {
                if (extraout_ST0_02 < (float10)*(float *)(piVar4[1] + 0xe0)) {
                  *(int **)(piVar4[1] + 0xdc) = piVar5;
                  *(float *)(piVar4[1] + 0xe0) = (float)extraout_ST0_02;
                }
                iVar12 = piVar4[1];
                fVar15 = extraout_ST0_02;
                if (*(int **)(iVar12 + 0xe4) == piVar5) {
                  fVar15 = extraout_ST0_02 - (float10)_DAT_007f67d0;
                }
                local_30 = (float)fVar15;
                uVar16 = __allshl();
                uVar10 = (uint)((ulonglong)uVar16 >> 0x20);
                if ((((piVar4[0xaa] & (uint)uVar16) != 0 || (piVar4[0xab] & uVar10) != 0) &&
                    (((*(uint *)(iVar12 + 0x1e8) & 0x20000) == 0 ||
                     ((*(uint *)(*(int *)(PTR_DAT_00802c54 + 0x298c) + 8 +
                                (uint)*(byte *)((int)piVar4 + 0x28d) * 8) & (uint)uVar16) != 0 ||
                      (*(uint *)(*(int *)(PTR_DAT_00802c54 + 0x298c) + 0xc +
                                (uint)*(byte *)((int)piVar4 + 0x28d) * 8) & uVar10) != 0)))) &&
                   ((local_30 < *(float *)(iVar12 + 0xf0) ||
                    (((piVar6 = *(int **)(iVar12 + 0xec), piVar6 != (int *)0x0 && (*piVar6 != 0)) &&
                     ((*(char *)(*piVar6 + 0x7b5) == 'Z' && (*(char *)(*piVar5 + 0x7b5) != 'Z'))))))
                   )) {
                  *(int **)(iVar12 + 0xec) = piVar5;
                  *(float *)(piVar4[1] + 0xf0) = (float)extraout_ST0_03;
                }
              }
            }
          }
          local_2c = local_2c + 1;
        } while (local_2c < param_6);
        if ((local_18 != (int *)0x0) && (*(int **)(local_18[1] + 0xec) != piVar4)) {
          *(int **)(local_18[1] + 0xec) = piVar4;
          *(float *)(local_18[1] + 0xf0) = local_24;
          *(ushort *)(param_1 + 0x1386) = *(ushort *)(param_1 + 0x1386) | 2;
          uVar16 = __allshl();
          uVar10 = (uint)((ulonglong)uVar16 >> 0x20);
          if ((((*(uint *)(*piVar4 + 0xeb8) & (uint)uVar16) == 0 &&
                (*(uint *)(*piVar4 + 0xebc) & uVar10) == 0) &&
              ((piVar4[0xaa] & (uint)uVar16) != 0 || (piVar4[0xab] & uVar10) != 0)) &&
             ((iVar12 = piVar4[1], (*(uint *)(iVar12 + 0x1e8) & 0x1000) == 0 ||
              (extraout_ST0_04 < (float10)*(float *)(iVar12 + 0xf0))))) {
            *(int **)(iVar12 + 0xec) = local_18;
            *(float *)(piVar4[1] + 0xf0) = (float)extraout_ST0_04;
            *(uint *)(piVar4[1] + 0x1e8) = *(uint *)(piVar4[1] + 0x1e8) | 0x1000;
          }
        }
      }
      *(char *)(param_1 + 0x1385) = *(char *)(param_1 + 0x1385) + '\x01';
      if (param_4 <= (int)(uint)*(byte *)(param_1 + 0x1385)) {
        *(undefined1 *)(param_1 + 0x1385) = 0;
        if ((*(ushort *)(param_1 + 0x1386) & 2) == 0) {
          bVar14 = true;
        }
        else {
          *(ushort *)(param_1 + 0x1386) = *(ushort *)(param_1 + 0x1386) & 0xfffd;
          bVar14 = false;
        }
      }
      bVar2 = *(byte *)(param_1 + 0x1385);
    }
  } while (0 < local_20);
LAB_0043a563:
  if (bVar14) {
LAB_0043a573:
    *(undefined1 *)(param_1 + 0x1385) = 0;
    _DAT_00876840 = 0;
    local_18 = (int *)0x0;
    if (0 < param_4) {
      do {
        piVar4 = *(int **)(param_5 + (int)local_18 * 4);
        local_2c = 0;
        if (0 < param_6) {
          do {
            piVar5 = *(int **)(param_7 + local_2c * 4);
            uVar16 = __allshl();
            uVar11 = (uint)((ulonglong)uVar16 >> 0x20);
            uVar10 = (uint)uVar16;
            if (((uVar10 & piVar4[0xaa]) == 0 && (uVar11 & piVar4[0xab]) == 0) ||
               ((*(uint *)(*(int *)(PTR_DAT_00802c54 + 0x298c) + 8 +
                          (uint)*(byte *)((int)piVar4 + 0x28d) * 8) & uVar10) == 0 &&
                (*(uint *)(*(int *)(PTR_DAT_00802c54 + 0x298c) + 0xc +
                          (uint)*(byte *)((int)piVar4 + 0x28d) * 8) & uVar11) == 0)) {
              iVar12 = *piVar4;
              if (((*(uint *)(iVar12 + 0xeb0) & uVar10) != 0 ||
                   (*(uint *)(iVar12 + 0xeb4) & uVar11) != 0) &&
                 ((uVar10 & piVar4[0xaa]) == 0 && (uVar11 & piVar4[0xab]) == 0)) {
                *(uint *)(iVar12 + 0xeb0) = ~uVar10 & *(uint *)(iVar12 + 0xeb0);
                *(uint *)(iVar12 + 0xeb4) = ~uVar11 & *(uint *)(iVar12 + 0xeb4);
              }
            }
            else {
              iVar12 = *piVar4;
              puVar1 = (uint *)(iVar12 + 0xeb0);
              *puVar1 = *puVar1 | uVar10;
              puVar1 = (uint *)(iVar12 + 0xeb4);
              *puVar1 = *puVar1 | uVar11;
            }
            uVar16 = __allshl();
            uVar11 = (uint)((ulonglong)uVar16 >> 0x20);
            uVar10 = (uint)uVar16;
            if (((piVar5[0xaa] & uVar10) == 0 && (piVar5[0xab] & uVar11) == 0) ||
               ((*(uint *)(*(int *)(PTR_DAT_00802c54 + 0x298c) + 8 +
                          (uint)*(byte *)((int)piVar5 + 0x28d) * 8) & uVar10) == 0 &&
                (*(uint *)(*(int *)(PTR_DAT_00802c54 + 0x298c) + 0xc +
                          (uint)*(byte *)((int)piVar5 + 0x28d) * 8) & uVar11) == 0)) {
              iVar12 = *piVar5;
              if (((*(uint *)(iVar12 + 0xeb0) & uVar10) != 0 ||
                   (*(uint *)(iVar12 + 0xeb4) & uVar11) != 0) &&
                 ((piVar5[0xaa] & uVar10) == 0 && (piVar5[0xab] & uVar11) == 0)) {
                *(uint *)(iVar12 + 0xeb0) = ~uVar10 & *(uint *)(iVar12 + 0xeb0);
                *(uint *)(iVar12 + 0xeb4) = ~uVar11 & *(uint *)(iVar12 + 0xeb4);
              }
            }
            else {
              iVar12 = *piVar5;
              puVar1 = (uint *)(iVar12 + 0xeb0);
              *puVar1 = *puVar1 | uVar10;
              puVar1 = (uint *)(iVar12 + 0xeb4);
              *puVar1 = *puVar1 | uVar11;
            }
            local_2c = local_2c + 1;
          } while (local_2c < param_6);
        }
        local_18 = (int *)((int)local_18 + 1);
      } while ((int)local_18 < param_4);
    }
    iVar12 = 0;
    if (0 < param_2) {
      do {
        piVar4 = *(int **)(param_3 + iVar12 * 4);
        *(undefined4 *)(piVar4[1] + 0xe4) = *(undefined4 *)(piVar4[1] + 0xec);
        *(undefined4 *)(piVar4[1] + 0xe8) = *(undefined4 *)(piVar4[1] + 0xf0);
        uVar10 = *(uint *)(piVar4[1] + 0x1e8);
        *(uint *)(piVar4[1] + 0x1e8) = (uVar10 >> 1 ^ uVar10) & 0x800 ^ uVar10;
        *(undefined4 *)(piVar4[1] + 0xd4) = *(undefined4 *)(piVar4[1] + 0xdc);
        *(undefined4 *)(piVar4[1] + 0xd8) = *(undefined4 *)(piVar4[1] + 0xe0);
        *(undefined4 *)(piVar4[1] + 0xdc) = 0;
        *(undefined4 *)(piVar4[1] + 0xe0) = 0x4e6e6b28;
        *(undefined4 *)(piVar4[1] + 0xec) = 0;
        *(undefined4 *)(piVar4[1] + 0xf0) = 0x4e6e6b28;
        *(uint *)(piVar4[1] + 0x1e8) = *(uint *)(piVar4[1] + 0x1e8) & 0xffffefff;
        uVar16 = __allshl();
        if (((uint)uVar16 & param_8) == 0 && ((uint)((ulonglong)uVar16 >> 0x20) & param_9) == 0) {
          puVar1 = (uint *)(piVar4[1] + 0x1e8);
          *puVar1 = *puVar1 & 0xffffbfff;
        }
        else {
          puVar1 = (uint *)(piVar4[1] + 0x1e8);
          *puVar1 = *puVar1 | 0x4000;
        }
        *(uint *)(*piVar4 + 0xeec) = *(uint *)(*piVar4 + 0xeec) & 0xfffff7ff;
        iVar13 = *piVar4;
        *(undefined4 *)(iVar13 + 0xeb8) = 0;
        *(undefined4 *)(iVar13 + 0xebc) = 0;
        if (((DAT_0093d810 != 0) &&
            (uVar16 = __allshl(),
            ((uint)uVar16 & *(uint *)(*piVar4 + 0xeb0)) != 0 ||
            ((uint)((ulonglong)uVar16 >> 0x20) & *(uint *)(*piVar4 + 0xeb4)) != 0)) ||
           ((DAT_0093d814 != 0 &&
            (uVar16 = __allshl(),
            ((uint)uVar16 & *(uint *)(*piVar4 + 0xeb0)) != 0 ||
            ((uint)((ulonglong)uVar16 >> 0x20) & *(uint *)(*piVar4 + 0xeb4)) != 0)))) {
          _DAT_00876840 = _DAT_00876840 + 1;
        }
        if (*(int *)(*piVar4 + 0x10a4) != 0) {
          *(int *)(piVar4[1] + 0xe4) = *(int *)(*piVar4 + 0x10a4);
          fVar15 = (float10)FUN_005becc0(*(int *)(piVar4[1] + 0xe4) + 0x5c,piVar4 + 0x17,&local_c);
          *(float *)(piVar4[1] + 0xe8) = (float)fVar15;
          iVar13 = piVar4[1];
          if (*(int **)(*(int *)(*(int *)(iVar13 + 0xe4) + 4) + 0xe4) == piVar4) {
            *(uint *)(iVar13 + 0x1e8) = *(uint *)(iVar13 + 0x1e8) | 0x800;
          }
          else {
            *(uint *)(iVar13 + 0x1e8) = *(uint *)(iVar13 + 0x1e8) & 0xfffff7ff;
          }
        }
        iVar12 = iVar12 + 1;
      } while (iVar12 < param_2);
    }
  }
  return;
}

