/* Ghidra analysis pseudocode, not original source.
 * ev_b1d683d72d7bcdb306124a83b006db4b41bf581671bc5ef620d768a8a4b84d3d
 * Entry: 0x66cc60; label: FUN_0066cc60
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0066cc60(void)

{
  float *pfVar1;
  short *psVar2;
  float fVar3;
  float fVar4;
  short sVar5;
  uint *puVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  short *psVar10;
  float10 fVar11;
  float10 fVar12;
  float10 fVar13;
  float10 fVar14;
  float10 fVar15;
  float10 fVar16;
  float10 fVar17;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  float local_24;
  
  piVar9 = DAT_0292fc68;
  if (DAT_0292fc68 != (int *)0x0) {
    iVar7 = 0;
    do {
      if (*(int *)(iVar7 + 0x198 + (int)piVar9) != 0) {
        if (0 < *(short *)(iVar7 + 0x1a0 + (int)piVar9)) {
          psVar10 = (short *)(iVar7 + 0x1a0 + (int)piVar9);
          *psVar10 = *psVar10 + -1;
          piVar9 = DAT_0292fc68;
        }
        if (0 < *(short *)(iVar7 + 0x1a2 + (int)piVar9)) {
          psVar10 = (short *)(iVar7 + 0x1a2 + (int)piVar9);
          *psVar10 = *psVar10 + -1;
          piVar9 = DAT_0292fc68;
        }
      }
      if (*(int *)(iVar7 + 0x1b0 + (int)piVar9) != 0) {
        sVar5 = *(short *)(iVar7 + 0x1b8 + (int)piVar9);
        if (0 < sVar5) {
          *(short *)(iVar7 + 0x1b8 + (int)piVar9) = sVar5 + -1;
          piVar9 = DAT_0292fc68;
        }
        sVar5 = *(short *)(iVar7 + 0x1ba + (int)piVar9);
        if (0 < sVar5) {
          *(short *)(iVar7 + 0x1ba + (int)piVar9) = sVar5 + -1;
          piVar9 = DAT_0292fc68;
        }
      }
      if (*(int *)(iVar7 + 0x1c8 + (int)piVar9) != 0) {
        sVar5 = *(short *)(iVar7 + 0x1d0 + (int)piVar9);
        if (0 < sVar5) {
          *(short *)(iVar7 + 0x1d0 + (int)piVar9) = sVar5 + -1;
          piVar9 = DAT_0292fc68;
        }
        sVar5 = *(short *)(iVar7 + 0x1d2 + (int)piVar9);
        if (0 < sVar5) {
          *(short *)(iVar7 + 0x1d2 + (int)piVar9) = sVar5 + -1;
          piVar9 = DAT_0292fc68;
        }
      }
      if (*(int *)(iVar7 + 0x1e0 + (int)piVar9) != 0) {
        sVar5 = *(short *)(iVar7 + 0x1e8 + (int)piVar9);
        if (0 < sVar5) {
          *(short *)(iVar7 + 0x1e8 + (int)piVar9) = sVar5 + -1;
          piVar9 = DAT_0292fc68;
        }
        sVar5 = *(short *)(iVar7 + 0x1ea + (int)piVar9);
        if (0 < sVar5) {
          *(short *)(iVar7 + 0x1ea + (int)piVar9) = sVar5 + -1;
          piVar9 = DAT_0292fc68;
        }
      }
      iVar7 = iVar7 + 0x60;
    } while (iVar7 < 0x600);
    iVar7 = 0;
    do {
      if (0 < *(short *)(iVar7 + 0x1bb8 + (int)piVar9)) {
        psVar10 = (short *)(iVar7 + 0x1bb8 + (int)piVar9);
        *psVar10 = *psVar10 + -1;
        piVar9 = DAT_0292fc68;
      }
      sVar5 = *(short *)(iVar7 + 0x23c4 + (int)piVar9);
      if (0 < sVar5) {
        *(short *)(iVar7 + 0x23c4 + (int)piVar9) = sVar5 + -1;
        piVar9 = DAT_0292fc68;
      }
      sVar5 = *(short *)(iVar7 + 0x2bd0 + (int)piVar9);
      if (0 < sVar5) {
        *(short *)(iVar7 + 0x2bd0 + (int)piVar9) = sVar5 + -1;
        piVar9 = DAT_0292fc68;
      }
      sVar5 = *(short *)(iVar7 + 0x33dc + (int)piVar9);
      if (0 < sVar5) {
        *(short *)(iVar7 + 0x33dc + (int)piVar9) = sVar5 + -1;
        piVar9 = DAT_0292fc68;
      }
      iVar7 = iVar7 + 0x2030;
    } while (iVar7 < 0x80c0);
  }
  iVar7 = 0;
  if (0 < DAT_02947d7c) {
    do {
      (*(code *)(&DAT_02921218)[iVar7 * 2])((&DAT_0292121c)[iVar7 * 2]);
      iVar7 = iVar7 + 1;
      piVar9 = DAT_0292fc68;
    } while (iVar7 < DAT_02947d7c);
  }
  DAT_02947d7c = 0;
  _DAT_0292118c = 0;
  if (piVar9 != (int *)0x0) {
    fVar11 = (float10)_DAT_00810b34;
    fVar12 = (float10)DAT_00973708 * fVar11;
    fVar13 = (float10)0.25;
    fStack_2c = (float)((float10)DAT_009736e8 * (float10)(float)-fVar11 * fVar13 - fVar12 * fVar13);
    fVar14 = (float10)DAT_00973710 * fVar11;
    local_24 = (float)((float10)_DAT_009736f0 * (float10)(float)-fVar11 * fVar13 - fVar14 * fVar13);
    fVar17 = fVar11 * (float10)DAT_009736e8;
    fVar15 = fVar17 * (float10)0.3499999940395355;
    fVar3 = (float)(fVar12 - fVar15);
    fStack_30 = fStack_2c;
    if (fVar3 < fStack_2c) {
      fStack_30 = fVar3;
    }
    if (fStack_2c < fVar3) {
      fStack_2c = fVar3;
    }
    fVar16 = (float10)_DAT_009736f0 * fVar11 * (float10)0.3499999940395355;
    fVar3 = (float)(fVar14 - fVar16);
    fStack_28 = local_24;
    if (fVar3 < local_24) {
      fStack_28 = fVar3;
    }
    if (local_24 < fVar3) {
      local_24 = fVar3;
    }
    fVar3 = (float)(fVar15 + fVar12);
    if (fVar3 < fStack_30) {
      fStack_30 = fVar3;
    }
    if (fStack_2c < fVar3) {
      fStack_2c = fVar3;
    }
    fVar3 = (float)(fVar16 + fVar14);
    if (fVar3 < fStack_28) {
      fStack_28 = fVar3;
    }
    if (local_24 < fVar3) {
      local_24 = fVar3;
    }
    fVar3 = (float)((float10)(double)fVar17 * fVar13 - (float10)(double)(fVar12 * fVar13));
    if (fVar3 < fStack_30) {
      fStack_30 = fVar3;
    }
    if (fStack_2c < fVar3) {
      fStack_2c = fVar3;
    }
    fVar3 = (float)(fVar13 * (float10)(double)((float10)_DAT_009736f0 * fVar11) -
                   (float10)(double)(fVar14 * fVar13));
    if (fVar3 < fStack_28) {
      fStack_28 = fVar3;
    }
    if (local_24 < fVar3) {
      local_24 = fVar3;
    }
    fStack_30 = fStack_30 + (DAT_00973718 - 1.0);
    fStack_2c = fStack_2c + DAT_00973718 + 1.0;
    fStack_28 = (DAT_00973720 - 1.0) + fStack_28;
    fVar3 = DAT_00973720 + 1.0 + local_24;
    piVar9[0x4c] = (int)fStack_30;
    DAT_0292fc68[0x4f] = (int)fStack_2c;
    DAT_0292fc68[0x4e] = (int)fStack_28;
    local_24 = 0.0;
    DAT_0292fc68[0x51] = (int)fVar3;
    DAT_0292fc68[0x4b] = 0;
    psVar10 = (short *)(DAT_0292fc68[0x6ed] + (short)DAT_0292fc68[0x6e6] * 2);
    piVar9 = DAT_0292fc68;
    if (0 < *(short *)((int)DAT_0292fc68 + 0x1b9a)) {
      do {
        pfVar1 = (float *)(*piVar9 + *psVar10 * 0x38);
        iVar8 = *(short *)(pfVar1 + 0xc) * 0x6c;
        iVar7 = iVar8 + piVar9[0x1a];
        puVar6 = *(uint **)(iVar7 + 0x68);
        if (puVar6 == (uint *)0x0) {
LAB_0066d130:
          if (pfVar1[0xb] != 0.0) {
            if (*(int *)(iVar7 + 0x40) != 0) {
              if (*(short *)(iVar7 + 0x50) != 0) {
                if (*(short *)(iVar7 + 0x50) < 0x7d) {
                  fVar4 = *(float *)(iVar8 + 0x5c + piVar9[0x1a]);
                  iVar7 = iVar8 + piVar9[0x1a];
                  fVar4 = fVar4 - *(float *)(iVar7 + 100) * fVar4;
                }
                else {
                  iVar7 = piVar9[0x1a] + iVar8;
                  fVar4 = (*(float *)(piVar9[0x1a] + 0x54 + iVar8) -
                          *(float *)(iVar7 + 100) * *(float *)(iVar7 + 0x5c)) +
                          *(float *)(iVar7 + 0x5c);
                }
                *(float *)(iVar7 + 0x5c) = fVar4;
                iVar7 = DAT_0292fc68[0x1a] + iVar8;
                *(float *)(iVar7 + 0x5c) =
                     (-*(float *)(iVar7 + 0x58) * ABS(*(float *)(DAT_0292fc68[0x1a] + 0x58 + iVar8))
                      * *(float *)(iVar7 + 0x60) * 0.5 -
                     *(float *)(iVar7 + 0x58) * *(float *)(iVar7 + 0x60)) + *(float *)(iVar7 + 0x5c)
                ;
                iVar7 = DAT_0292fc68[0x1a] + iVar8;
                *(float *)(iVar7 + 0x58) =
                     *(float *)(DAT_0292fc68[0x1a] + 0x5c + iVar8) + *(float *)(iVar7 + 0x58);
                psVar2 = (short *)(DAT_0292fc68[0x1a] + 0x50 + iVar8);
                *psVar2 = *psVar2 + -1;
                iVar7 = *(int *)(DAT_0292fc68[0x1a] + iVar8 + 0x40);
                *(float *)(iVar7 + 0x34) =
                     *(float *)(DAT_0292fc68[0x1a] + 0x58 + iVar8) + *(float *)(iVar7 + 0x34);
                piVar9 = DAT_0292fc68;
              }
              *pfVar1 = *(float *)(*(int *)(piVar9[0x1a] + 0x40 + iVar8) + 0x30);
              pfVar1[1] = *(float *)(*(int *)(DAT_0292fc68[0x1a] + 0x40 + iVar8) + 0x34);
              pfVar1[2] = *(float *)(*(int *)(DAT_0292fc68[0x1a] + 0x40 + iVar8) + 0x38);
              piVar9 = DAT_0292fc68;
            }
            if ((*(byte *)(piVar9[0x1a] + iVar8 + 0x4c) & 2) != 0) {
              *(undefined2 *)(piVar9[0x1a] + iVar8 + 0x50) = 0x80;
              piVar9 = DAT_0292fc68;
            }
            puVar6 = (uint *)(piVar9[0x1a] + 0x4c + iVar8);
            *puVar6 = *puVar6 & 0xfffffffd;
            *(undefined4 *)(DAT_0292fc68[0x1a] + 0x44 + iVar8) = 0;
            piVar9 = DAT_0292fc68;
            if ((*(byte *)(DAT_0292fc68[0x1a] + 0x4c + iVar8) & 1) == 0) {
              if (((pfVar1[4] + *pfVar1 <= fStack_2c) && (fStack_30 <= pfVar1[7] + *pfVar1)) &&
                 (pfVar1[6] + pfVar1[2] <= fVar3)) {
                fVar4 = pfVar1[9] + pfVar1[2];
                goto LAB_0066d2f3;
              }
            }
            else if (((*pfVar1 - pfVar1[0xd] <= fStack_2c) && (fStack_30 <= pfVar1[0xd] + *pfVar1))
                    && (pfVar1[2] - pfVar1[0xd] <= fVar3)) {
              fVar4 = pfVar1[2] + pfVar1[0xd];
LAB_0066d2f3:
              if ((fStack_28 <= fVar4) && (DAT_0292fc68[0x4b] < 0x60)) {
                *(short *)((int)DAT_0292fc68 + DAT_0292fc68[0x4b] * 2 + 0x6c) = *psVar10;
                DAT_0292fc68[0x4b] = DAT_0292fc68[0x4b] + 1;
                piVar9 = DAT_0292fc68;
              }
            }
          }
        }
        else if ((*(byte *)(iVar7 + 0x4c) & 4) == 0) {
          if ((*puVar6 & 1) != 0) goto LAB_0066d130;
        }
        else if ((*puVar6 & 2) != 0) goto LAB_0066d130;
        local_24 = (float)((int)local_24 + 1);
        psVar10 = psVar10 + 1;
        if ((int)*(short *)((int)piVar9 + 0x1b9a) <= (int)local_24) {
          return;
        }
      } while( true );
    }
  }
  return;
}

