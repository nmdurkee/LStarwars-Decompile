/* Ghidra pseudocode, not original source.
 * ev_0733f146760cc31006e6190a74f2cd28d34a83dcf7f13916827ecd624512e4e0
 * Entry: 0x5f0f00; label: FUN_005f0f00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_005f0f00(int *param_1,undefined1 *param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  byte bVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  byte *pbVar8;
  undefined4 uVar9;
  bool bVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  float *pfVar14;
  int iVar15;
  int *piVar16;
  int *piVar17;
  float10 fVar18;
  uint local_94;
  uint *local_90;
  float local_88;
  int local_84;
  int local_7c;
  undefined4 local_74;
  int local_70;
  int local_6c;
  int local_68;
  undefined1 local_64 [12];
  undefined1 local_58 [12];
  undefined1 local_4c [12];
  undefined1 local_40 [64];
  
  if (param_1 == (int *)0x0) {
    return 0;
  }
  iVar13 = param_1[2];
  local_6c = iVar13;
  if (*(short *)(iVar13 + 0xca) != 0) {
    FUN_005ec590(local_40,param_2,(int)*(short *)(iVar13 + 0xca),(int)*(short *)(iVar13 + 200));
    param_2 = local_40;
  }
  iVar6 = DAT_00806ccc;
  if (DAT_00806ccc == -1) {
    iVar6 = FUN_006042e0(iVar13 + 0x80,iVar13 + 0x90,param_2,0,0);
  }
  iVar5 = *(int *)(*param_1 + 0x110);
  if (((*(byte *)(*(int *)(iVar5 + 0x48) + *(int *)(iVar13 + 0xc0)) & 0x20) == 0) ||
     (DAT_00966384 < 1)) {
    local_70 = 0;
    local_84 = 0;
  }
  else {
    local_70 = DAT_009715a0;
    FUN_005b30a0(local_4c,iVar13 + 0x80,param_2);
    FUN_005b30a0(local_58,iVar13 + 0x90,param_2);
    local_84 = FUN_005ea6a0(local_4c,local_58,0);
  }
  if ((iVar6 == 0) && (local_84 == 0)) {
    return 0;
  }
  FUN_005b37d0(local_64,iVar13 + 0x80,iVar13 + 0x90);
  FUN_005b3830(local_64,local_64,0x3f000000);
  FUN_005b30a0(local_64,local_64,param_2);
  fVar18 = (float10)FUN_005b3c50(local_64,&DAT_00973718,0);
  fVar2 = (float)fVar18;
  if (fVar2 < 0.0) {
    fVar2 = 0.0;
  }
  pfVar14 = *(float **)(iVar13 + 0xbc);
  if (*pfVar14 == 0.0) {
    local_90 = *(uint **)(iVar13 + 0xb0);
  }
  else if (DAT_009738ec == 0) {
    iVar11 = 0;
    fVar3 = *pfVar14;
    while (fVar2 < fVar3) {
      pfVar1 = pfVar14 + 1;
      pfVar14 = pfVar14 + 1;
      iVar11 = iVar11 + 1;
      fVar3 = *pfVar1;
    }
    local_90 = (uint *)(*(int *)(iVar13 + 0xb0) + iVar11 * 0xc);
  }
  else {
    fVar3 = *pfVar14;
    for (iVar11 = 0; (fVar3 != 0.0 && (iVar11 != DAT_009738ec)); iVar11 = iVar11 + 1) {
      pfVar14 = pfVar14 + 1;
      fVar3 = *pfVar14;
    }
    local_90 = (uint *)(*(int *)(iVar13 + 0xb0) + iVar11 * 0xc);
  }
  local_88 = 1.0;
  if ((*(int *)(iVar5 + 0xc) != 0) &&
     (iVar13 = *(int *)(iVar13 + 0xc0), (*(byte *)(*(int *)(iVar5 + 0x48) + iVar13) & 0x40) != 0)) {
    fVar18 = (float10)FUN_005df7b0(fVar2,*(undefined4 *)(*(int *)(iVar5 + 0xc) + iVar13 * 8),
                                   *(undefined4 *)(*(int *)(iVar5 + 0xc) + 4 + iVar13 * 8));
    local_88 = (float)fVar18;
    if (local_88 == 0.0) {
      return 0;
    }
  }
  local_74 = 0;
  local_94 = 0;
  if (*local_90 != 0) {
    do {
      iVar13 = *(int *)(*(int *)(iVar5 + 0x50) + *(int *)(local_90[1] + local_94 * 4) * 4);
      iVar11 = iVar13;
      if ((DAT_009738f4 == 0) || (bVar4 = *(byte *)(iVar13 + 0x9a), bVar4 == 0)) {
        iVar7 = DAT_009738f0;
        if (DAT_009738f0 != 0) goto LAB_005f11d9;
      }
      else if (*(int *)(DAT_009738f4 + (uint)bVar4 * 4) != 0) {
        iVar7 = *(int *)(DAT_009738f4 + (uint)bVar4 * 4);
LAB_005f11d9:
        if ((iVar7 != 0) && (iVar11 = iVar7, *(int *)(iVar13 + 0x1f0) != *(int *)(iVar7 + 0x1f0))) {
          iVar11 = FUN_005e5020(iVar13,iVar7);
        }
      }
      for (; iVar11 != 0; iVar11 = *(int *)(iVar11 + 0x30)) {
        if (DAT_02974d1c == 1) {
          if ((*(byte *)(iVar11 + 0xf8) == 0xff) ||
             ((uint)*(byte *)(iVar11 + 0xfa) + (uint)*(byte *)(iVar11 + 0xf9) +
              (uint)*(byte *)(iVar11 + 0xf8) == 0)) {
LAB_005f1242:
            if (iVar6 != 0) {
              piVar16 = *(int **)(iVar11 + 0x3c);
              *(uint *)(*piVar16 + 0x74) = *(uint *)(*piVar16 + 0x74) | 2;
              pbVar8 = (byte *)(((int)(piVar16[1] + (piVar16[1] >> 0x1f & 7U)) >> 3) +
                               *(int *)(*piVar16 + 0x58 +
                                       (*(uint *)(*piVar16 + 0x74) >> 0xf & 1) * 4));
              uVar12 = piVar16[1] & 0x80000007;
              if ((int)uVar12 < 0) {
                uVar12 = (uVar12 - 1 | 0xfffffff8) + 1;
              }
              *pbVar8 = *pbVar8 | '\x01' << ((byte)uVar12 & 0x1f);
              FUN_005fd220(DAT_00973890,DAT_00973894,_DAT_00806b9c,&DAT_00806cc0,iVar11);
              FUN_00607590(piVar16,&DAT_009868a0);
              if (((*(byte *)(*(int *)(iVar5 + 0x48) + *(int *)(local_6c + 0xc0)) & 0x20) == 0) ||
                 (DAT_009738a8 != 0)) {
                uVar9 = 0;
              }
              else {
                uVar9 = 1;
              }
              FUN_005e0530(iVar11,*(undefined4 *)(local_90[2] + local_94 * 4),local_4c,&local_74,
                           param_4,param_5,local_88,uVar9);
            }
            uVar12 = *(uint *)(iVar11 + 0x40) >> 0xe & 3;
            bVar10 = false;
            if ((uVar12 == 1) || (uVar12 == 3)) {
              bVar10 = true;
            }
            if ((((local_84 != 0) && (DAT_009738a8 == 0)) && (!bVar10)) &&
               (iVar13 = 0, DAT_00966384 != 0)) {
              do {
                iVar7 = *(int *)((&DAT_0096d9d0)[iVar13] + 0x710);
                if (DAT_009715a0 == 0) {
                  local_7c = -1;
                }
                else {
                  local_7c = (&DAT_0096e550)[iVar13];
                }
                iVar15 = 0;
                local_68 = iVar7;
                if (0 < iVar7) {
                  piVar16 = (int *)((&DAT_0096d9d0)[iVar13] + 0x2a4);
                  do {
                    if ((local_7c >> ((byte)iVar15 & 0x1f) & 1U) != 0) {
                      piVar17 = piVar16;
                      if (*(char *)(iVar11 + 0x268) != '\0') {
                        piVar17 = piVar16 + 0x11;
                      }
                      *piVar17 = iVar5;
                      FUN_00603530(piVar17,1);
                      *(undefined1 *)piVar17[9] = 0x80;
                      *(undefined1 *)(piVar17[9] + 1) = 3;
                      *(int *)(piVar17[9] + 4) = iVar11;
                      piVar17[9] = piVar17[9] + 0x10;
                      FUN_00607820(piVar17,&DAT_009868a0);
                      FUN_005e0530(iVar11,*(undefined4 *)(local_90[2] + local_94 * 4),local_58,
                                   &local_74,param_4,param_5,local_88,1);
                      iVar7 = local_68;
                    }
                    iVar15 = iVar15 + 1;
                    piVar16 = piVar16 + 0xe0;
                  } while (iVar15 < iVar7);
                }
                iVar13 = iVar13 + 1;
              } while (iVar13 != DAT_00966384);
            }
          }
        }
        else if (*(char *)(iVar11 + 0xf8) != -1) goto LAB_005f1242;
      }
      local_94 = local_94 + 1;
    } while (local_94 < *local_90);
  }
  FUN_005fd220(0,0,0,0,0);
  if (local_70 == 0) {
    DAT_009715a0 = 0;
  }
  return iVar6;
}

