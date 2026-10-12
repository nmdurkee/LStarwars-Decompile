/* Ghidra pseudocode, not original source.
 * ev_148a09dc694c3f4e6090ec8593a8f5c40e6398f75b0d17d245a3886ccb65c6ec
 * Entry: 0x57ef50; label: FUN_0057ef50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0057ef50(int param_1,int param_2)

{
  uint *puVar1;
  float fVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  float *pfVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  float *pfVar11;
  bool bVar12;
  int local_88;
  float local_84;
  int aiStack_80 [32];
  
  if (((DAT_00951cb0 != 0) && (*(int *)(DAT_00951cb0 + 4) != 0)) && (DAT_00951be8 != 0)) {
    FUN_0057ea60(DAT_00951be8);
  }
  DAT_00951c3c = 0;
  DAT_00951c80 = 0;
  DAT_00951bfc = -1;
  DAT_00951be0 = 0;
  DAT_00951c30 = 0;
  DAT_00951be8 = 0;
  DAT_00951c68 = 0;
  DAT_00951c34 = 0;
  _DAT_00951bf8 = 0;
  DAT_00951c5c = 0;
  FUN_006df320(0);
  piVar5 = *(int **)(param_1 + 0x2ab0);
  if (piVar5 == (int *)0x0) {
    return;
  }
  iVar8 = 0;
  if (0 < piVar5[1]) {
    do {
      iVar10 = *(int *)(*piVar5 + iVar8 * 4);
      iVar9 = *(int *)(iVar10 + 4);
      if ((iVar9 != 0) && ((*(byte *)(iVar9 + 0x88) & 2) != 0)) {
        uVar3 = *(uint *)(iVar10 + 0x50);
        if ((uVar3 & 1) != 0) {
          local_88 = iVar8;
          FUN_0057ce40();
          _DAT_00951c54 = _DAT_00951c54 + 1;
          goto LAB_0057f02d;
        }
        if ((uVar3 & 0x20) != 0) {
          DAT_00951c30 = 1;
        }
      }
      piVar5 = *(int **)(param_1 + 0x2ab0);
      iVar8 = iVar8 + 1;
    } while (iVar8 < piVar5[1]);
  }
  iVar8 = -1;
  local_88 = -1;
  FUN_00656e40(1);
LAB_0057f02d:
  DAT_00951c78 = 0;
  piVar5 = *(int **)(param_1 + 0x2ab0);
  iVar10 = 0;
  if (0 < piVar5[1]) {
    do {
      iVar7 = DAT_00951c2c;
      iVar9 = *(int *)(*piVar5 + iVar10 * 4);
      iVar4 = *(int *)(iVar9 + 4);
      if (iVar4 != 0) {
        if ((*(byte *)(iVar4 + 0x88) & 2) == 0) {
          aiStack_80[iVar10] = 0;
        }
        else {
          bVar12 = DAT_00951c2c != 0;
          *(undefined4 *)(iVar9 + 0x54) = *(undefined4 *)(iVar4 + 0x90);
          local_84 = *(float *)(iVar9 + 0x58);
          aiStack_80[iVar10] = 1;
          local_84 = local_84 + _DAT_00925018;
          *(float *)(iVar9 + 0x58) = local_84;
          if ((bVar12) && (23.0 <= local_84)) {
            iVar7 = 0;
            DAT_00951c2c = 0;
          }
          if ((iVar8 == -1) || (iVar10 == iVar8)) {
            if ((DAT_02962034 == 0) &&
               (((((DAT_02962038 == 0 && (iVar10 == iVar8)) && (*(int *)(iVar9 + 0x18c) != -1)) &&
                 ((*(float *)(iVar4 + 0x98) == 0.0 && (iVar7 != 0)))) &&
                (iVar4 = FUN_00694490(0x10,0), iVar4 != 4)))) {
              *(undefined4 *)(*(int *)(iVar9 + 4) + 0x98) = 0;
              DAT_00951c58 = 1;
            }
            else {
              if (DAT_00803f78 != -1) {
                if (DAT_0297dc00 < DAT_00803f78 + 5) {
                  *(undefined4 *)(*(int *)(iVar9 + 4) + 0x98) = 0;
                  DAT_00951c58 = 1;
                  goto LAB_0057f1bc;
                }
                DAT_00803f78 = -1;
                thunk_FUN_00696040(0x10,0);
              }
              local_84 = *(float *)(iVar9 + 0x5c) * _DAT_00925018;
              *(float *)(*(int *)(iVar9 + 4) + 0x98) = local_84;
              if ((iVar10 == iVar8) && (DAT_00951c58 != 0)) {
                DAT_00951c58 = 0;
                DAT_00951c2c = 0;
              }
            }
LAB_0057f1bc:
            FUN_00500390(*(undefined4 *)(iVar9 + 4),0);
            if (DAT_00951c90 != (code *)0x0) {
              (*DAT_00951c90)(iVar9);
            }
            FUN_0057cb10();
            DAT_00951c78 = DAT_00951c78 + 1;
          }
          else {
            *(undefined4 *)(iVar4 + 0x98) = 0;
            FUN_00500390(*(undefined4 *)(iVar9 + 4),1);
            DAT_00951c78 = DAT_00951c78 + 1;
          }
        }
      }
      piVar5 = *(int **)(param_1 + 0x2ab0);
      iVar10 = iVar10 + 1;
    } while (iVar10 < piVar5[1]);
  }
  FUN_00508cb0(param_2,0,0x3f800000);
  if (DAT_00951c94 != (code *)0x0) {
    (*DAT_00951c94)();
  }
  if (param_2 == 0) {
    piVar5 = *(int **)(param_1 + 0x2ab0);
    iVar8 = 0;
    if (0 < piVar5[1]) {
      do {
        iVar10 = *(int *)(*piVar5 + iVar8 * 4);
        if (*(int *)(iVar10 + 4) != 0) {
          if ((aiStack_80[iVar8] != 0) && (0.0 < *(float *)(*(int *)(iVar10 + 4) + 0x98))) {
            pfVar11 = (float *)(iVar10 + 0x74);
            iVar9 = 6;
            do {
              if (((*(short *)(pfVar11 + -1) != -1) && (*(float *)(iVar10 + 0x54) < *pfVar11)) &&
                 (fVar2 = *(float *)(*(int *)(iVar10 + 4) + 0x90),
                 *pfVar11 < fVar2 != (*pfVar11 == fVar2))) {
                if ((*(byte *)((int)pfVar11 + -2) & 1) == 0) {
                  pfVar6 = (float *)0x0;
                }
                else {
                  pfVar6 = pfVar11 + 1;
                }
                FUN_00681e90((int)*(short *)(pfVar11 + -1),pfVar6);
              }
              pfVar11 = pfVar11 + 5;
              iVar9 = iVar9 + -1;
            } while (iVar9 != 0);
          }
          if (((local_88 == -1) || (iVar8 != local_88)) &&
             ((aiStack_80[iVar8] != 0 &&
              (iVar9 = FUN_00500210(*(undefined4 *)(iVar10 + 4)), iVar9 != 0)))) {
            if (DAT_00951c98 != (code *)0x0) {
              (*DAT_00951c98)(iVar10);
            }
            if (DAT_00951c80 < 4) {
              iVar10 = *(int *)(iVar10 + 4);
              (&DAT_00951c3c)[DAT_00951c80] = iVar10;
              puVar1 = (uint *)(iVar10 + 0x88);
              *puVar1 = *puVar1 | 2;
              DAT_00951c80 = DAT_00951c80 + 1;
            }
          }
        }
        piVar5 = *(int **)(param_1 + 0x2ab0);
        iVar8 = iVar8 + 1;
      } while (iVar8 < piVar5[1]);
    }
  }
  if (local_88 == -1) {
    return;
  }
  iVar8 = *(int *)(**(int **)(param_1 + 0x2ab0) + local_88 * 4);
  FUN_00564ca0();
  iVar10 = FUN_00500210(*(undefined4 *)(iVar8 + 4));
  if (iVar10 == 0) {
    return;
  }
  if (((DAT_00951b80 == 0) || (*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_00951b80)) ||
     (DAT_00951b80 != DAT_00951b94)) {
    local_84 = 2.8026e-45;
    FUN_005b1220(&local_84,0);
  }
  if (DAT_00951c98 != (code *)0x0) {
    (*DAT_00951c98)(iVar8);
  }
  if (*(int *)(iVar8 + 0x148) != -1) {
    DAT_0093b0e4 = DAT_0093b0e4 & ~(1 << ((byte)*(int *)(iVar8 + 0x148) & 0x1f));
  }
  if (*(int *)(iVar8 + 0x150) != -1) {
    DAT_0093b0e4 = DAT_0093b0e4 & ~(1 << ((byte)*(int *)(iVar8 + 0x150) & 0x1f));
  }
  if (*(int *)(iVar8 + 0x158) != -1) {
    DAT_0093b0e4 = DAT_0093b0e4 & ~(1 << ((byte)*(int *)(iVar8 + 0x158) & 0x1f));
  }
  if (*(int *)(iVar8 + 0x160) != -1) {
    DAT_0093b0e4 = DAT_0093b0e4 & ~(1 << ((byte)*(int *)(iVar8 + 0x160) & 0x1f));
  }
  if (*(short *)(iVar8 + 0xec) == -1) {
    if ((((*(int *)(param_1 + 0x2ab0) == 0) || (iVar8 + 0x104 == 0)) ||
        (iVar9 = FUN_0057c970(*(int *)(param_1 + 0x2ab0),iVar8 + 0x104), iVar10 = DAT_00951b94,
        iVar9 == 0)) || (7 < DAT_00951c7c)) {
      iVar9 = 0;
      iVar10 = DAT_00951b94;
    }
    else {
      (&DAT_00951c0c)[DAT_00951c7c] = iVar9;
      DAT_00951c7c = DAT_00951c7c + 1;
    }
    if (((DAT_00951cb0 == 0) || (*(int *)(DAT_00951cb0 + 4) == 0)) || (iVar9 != 0)) {
      if ((*(uint *)(iVar8 + 0x50) & 0x400) == 0) {
        if (*(char *)(iVar8 + 0xf4) == '\0') {
          if ((*(uint *)(iVar8 + 0x50) & 0x100) != 0) {
            local_88 = 2;
            FUN_005b1220(&local_88,0);
            FUN_00565be0(1);
            FUN_005b11b0(1);
            FUN_00547930(0x2d,0,0,0);
          }
        }
        else {
          iVar10 = FUN_005756c0(param_1,iVar8 + 0xf4);
          if (iVar10 != 0) {
            FUN_00575c20(param_1,iVar10,1);
          }
        }
      }
      else {
        DAT_0087658c = 1;
      }
    }
    else {
      FUN_0057a6d0(iVar10,0xffffffff,0xffffffff,1);
      DAT_0095de48 = 1;
    }
    goto LAB_0057f606;
  }
  DAT_00951b80 = *(short *)(iVar8 + 0xec) * 0x130 + DAT_00951b78;
  if ((DAT_00951b94 == 0) || (DAT_00951b80 != DAT_00951b94)) {
    if ((DAT_00951cb0 != 0) &&
       (((*(int *)(DAT_00951cb0 + 4) != 0 && ((*(byte *)(DAT_00951b80 + 100) & 0xe0) == 0)) &&
        ((*(byte *)(iVar8 + 0x18a) & 2) == 0)))) goto LAB_0057f4cc;
  }
  else if ((DAT_00951cb0 == 0) || (*(int *)(DAT_00951cb0 + 4) == 0)) {
    if ((*(int *)(PTR_DAT_00802c54 + 300) != 0) &&
       ((*(byte *)(*(int *)(PTR_DAT_00802c54 + 300) + 0x7a) & 2) != 0)) {
      if (DAT_0093b2a8 == 0) {
        DAT_00951b80 = DAT_00951b9c;
      }
      else {
        DAT_00951b80 = DAT_00951b98;
      }
    }
  }
  else {
LAB_0057f4cc:
    FUN_0057a6d0(DAT_00951b94,0xffffffff,0xffffffff,1);
    DAT_0095de48 = 1;
  }
  if (DAT_0093d84c != -1) {
    DAT_00951c70 = 1;
    FUN_00652fb0();
    FUN_00694100(0x10);
    FUN_00698e70();
    DAT_00803df4 = 1;
  }
LAB_0057f606:
  _DAT_00951bf8 = 0;
  if (DAT_00951c80 < 4) {
    iVar8 = *(int *)(iVar8 + 4);
    (&DAT_00951c3c)[DAT_00951c80] = iVar8;
    puVar1 = (uint *)(iVar8 + 0x88);
    *puVar1 = *puVar1 | 2;
    DAT_00951bfc = DAT_00951c80;
    DAT_00951c80 = DAT_00951c80 + 1;
  }
  return;
}

