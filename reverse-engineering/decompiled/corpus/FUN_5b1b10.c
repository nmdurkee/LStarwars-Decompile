/* Ghidra analysis pseudocode, not original source.
 * ev_9de9052a7a74906b1fb5570bf9c5ea7426c8a6fcab6dcccf13cbc82c1ebad988
 * Entry: 0x5b1b10; label: FUN_005b1b10
 */

void FUN_005b1b10(int param_1)

{
  int *piVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  byte bVar8;
  int iVar9;
  float *pfVar10;
  int iVar11;
  byte bVar12;
  float10 fVar13;
  int local_10;
  int local_c;
  
  local_c = 0;
  if (0 < *(int *)(param_1 + 0x46cc)) {
    local_10 = 0;
    do {
      iVar9 = *(int *)(param_1 + 0x46d0) + local_10;
      pfVar10 = *(float **)(iVar9 + 0x10);
      piVar1 = (int *)(iVar9 + 4);
      iVar5 = FUN_005cfac0(piVar1);
      if ((((iVar5 != 0) && (iVar5 = FUN_005cfd60(piVar1), iVar5 != 0)) &&
          (iVar5 = FUN_005d0420(piVar1), iVar5 != 0)) &&
         (*(int *)(*(int *)(*piVar1 + 0x54) + (uint)*(ushort *)(iVar5 + 0x5c) * 4) != 0)) {
        fVar13 = (float10)FUN_005ca4b0(*(undefined4 *)
                                        (*(int *)(*piVar1 + 0x54) +
                                        (uint)*(ushort *)(iVar5 + 0x5c) * 4));
        fVar2 = (float)fVar13;
        fVar3 = *(float *)(iVar5 + 0x4c);
        if (((*(byte *)(iVar5 + 0x50) & 1) == 0) && (*(char *)(iVar9 + 3) == '\0')) {
          iVar5 = 0;
          if ('\0' < *(char *)(iVar9 + 2)) {
            do {
              if (((pfVar10 != (float *)0x0) &&
                  (*(byte *)(pfVar10 + 1) = *(byte *)(pfVar10 + 1) & 0xfe,
                  ((uint)pfVar10[1] & 2) == 0)) && (fVar3 < fVar2)) {
                *pfVar10 = 0.0;
              }
              pfVar10 = (float *)pfVar10[3];
              iVar5 = iVar5 + 1;
            } while (iVar5 < *(char *)(iVar9 + 2));
          }
          *(undefined1 *)(iVar9 + 3) = 0;
        }
        else {
          uVar6 = FUN_005cf9e0(piVar1);
          iVar7 = FUN_005aea20(iVar5);
          iVar11 = 0;
          if ('\0' < *(char *)(iVar9 + 2)) {
            do {
              if (pfVar10 != (float *)0x0) {
                bVar12 = *(byte *)(pfVar10 + 1);
                if ((bVar12 & 2) == 0) {
                  bVar8 = bVar12 >> 2 & 1;
                  if ((bVar8 == 0) || ((bVar12 & 8) == 0)) {
                    if (bVar8 == 0) {
                      if ((bVar12 & 8) != 0) {
                        if ((pfVar10[2] < *pfVar10) && (fVar3 <= pfVar10[2])) goto LAB_005b1d50;
                        if (fVar2 == *pfVar10) {
                          bVar12 = (byte)((ushort)((ushort)(NAN(fVar2) || NAN(pfVar10[2])) << 10) >>
                                         8) |
                                   (byte)((ushort)((ushort)(fVar2 == pfVar10[2]) << 0xe) >> 8);
                          goto LAB_005b1d4e;
                        }
                      }
                    }
                    else if ((pfVar10[2] <= *pfVar10) ||
                            (pfVar10[2] < fVar3 == (pfVar10[2] == fVar3))) {
                      if (*pfVar10 == 0.0) {
                        bVar12 = (byte)((ushort)((ushort)NAN(pfVar10[2]) << 10) >> 8) |
                                 (byte)((ushort)((ushort)(pfVar10[2] == 1.0) << 0xe) >> 8);
LAB_005b1d4e:
                        if ((POPCOUNT(bVar12) & 1U) != 0) goto LAB_005b1d50;
                      }
                    }
                    else {
LAB_005b1d50:
                      FUN_005478a0((int)*(short *)((int)pfVar10 + 6),uVar6,0,0);
                    }
                  }
                  else {
                    if ((*pfVar10 < pfVar10[2]) && (pfVar10[2] < fVar3 != (pfVar10[2] == fVar3)))
                    goto LAB_005b1d50;
                    if (pfVar10[2] < *pfVar10) {
                      fVar4 = pfVar10[2];
                      goto joined_r0x005b1cdf;
                    }
                  }
                }
                else if (((iVar7 == 0) && ((bVar12 & 4) != 0)) ||
                        (((bVar12 & 4) != 0 && ((bVar12 & 8) != 0)))) {
                  if (pfVar10[2] < fVar3 != (pfVar10[2] == fVar3)) {
                    fVar4 = *pfVar10;
joined_r0x005b1cdf:
                    if (fVar3 <= fVar4) goto LAB_005b1d50;
                  }
                }
                else if (((iVar7 == 1) && ((bVar12 & 8) != 0)) && (fVar3 <= pfVar10[2])) {
                  bVar12 = *pfVar10 < fVar3 |
                           (byte)((ushort)((ushort)(*pfVar10 == fVar3) << 0xe) >> 8);
                  goto LAB_005b1d4e;
                }
                if (((uint)pfVar10[1] & 2) == 0) {
                  *pfVar10 = fVar3;
                }
              }
              pfVar10 = (float *)pfVar10[3];
              iVar11 = iVar11 + 1;
            } while (iVar11 < *(char *)(iVar9 + 2));
          }
          *(byte *)(iVar9 + 3) = *(byte *)(iVar5 + 0x50) & 1;
        }
      }
      local_10 = local_10 + 0x14;
      local_c = local_c + 1;
    } while (local_c < *(int *)(param_1 + 0x46cc));
  }
  return;
}

