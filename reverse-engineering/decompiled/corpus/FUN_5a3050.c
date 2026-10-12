/* Ghidra analysis pseudocode, not original source.
 * ev_0b4f3bc8b4a39fc427a7fcc8ed3e1304ee3926d0e45102a57071cb05acfa7baa
 * Entry: 0x5a3050; label: FUN_005a3050
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005a3050(int *param_1)

{
  int iVar1;
  float fVar2;
  short sVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  float *pfVar7;
  int iVar8;
  int iVar9;
  int *local_40;
  int local_3c;
  undefined4 local_28;
  float local_24 [3];
  float local_18 [3];
  float local_c [2];
  float local_4;
  
  piVar4 = param_1;
  iVar9 = 0;
  if ((param_1 != (int *)0x0) && (iVar5 = FUN_0055f450(), (short)param_1[1] != 0)) {
    local_18[0] = (float)param_1[5];
    local_18[1] = 0.0;
    local_18[2] = (float)param_1[6];
    FUN_005b3620(local_18,local_18,0x4000);
    local_3c = 0;
    if ((short)param_1[1] != 0) {
      do {
        iVar6 = *(int *)(iVar9 + 0x30 + *piVar4);
        if ((iVar6 != 0) &&
           (iVar6 = FUN_0055a320(*(undefined4 *)(iVar5 + 0x2ac8),iVar6), iVar6 == 0)) {
          *(undefined2 *)(iVar9 + 0x1e + *piVar4) = 1;
          FUN_005cfc00(*piVar4 + iVar9,0);
        }
        if (*(short *)(iVar9 + 0x1e + *piVar4) == 0) {
          pfVar7 = (float *)FUN_005cf9e0(iVar9 + *piVar4);
          *(float *)(iVar9 + 0x14 + *piVar4) = *(float *)(iVar9 + 0x14 + *piVar4) - _DAT_00925018;
          iVar6 = iVar9 + *piVar4;
          if ((*(float *)(iVar6 + 0x14) <= 0.0) && (DAT_00951b50 == 0)) {
            if (*(short *)(iVar6 + 0x1c) == 0) {
              *(undefined2 *)(iVar6 + 0x1c) = 1;
              *(undefined4 *)(*piVar4 + iVar9 + 0x14) = *(undefined4 *)(*piVar4 + 0xc + iVar9);
              sVar3 = *(short *)((int)piVar4 + 6);
            }
            else {
              *(undefined2 *)(iVar6 + 0x1c) = 0;
              *(undefined4 *)(iVar9 + *piVar4 + 0x14) = *(undefined4 *)(iVar9 + 0x10 + *piVar4);
              sVar3 = (short)piVar4[2];
            }
            FUN_005478a0((int)sVar3,pfVar7,0,0);
            FUN_005cfc00(iVar9 + *piVar4,*(undefined2 *)(iVar9 + 0x1c + *piVar4));
            if (*(short *)(iVar9 + 0x1c + *piVar4) == 0) {
              sVar3 = (short)piVar4[3];
            }
            else {
              sVar3 = *(short *)((int)piVar4 + 10);
            }
            FUN_005478a0((int)sVar3,pfVar7,0,0);
          }
          if (*(short *)(iVar9 + 0x1c + *piVar4) != 0) {
            fVar2 = (float)piVar4[4];
            if (*(char *)((int)piVar4 + 0x1e) == '\0') {
              local_24[0] = local_18[0];
              local_24[1] = 0.0;
              local_24[2] = local_18[2];
            }
            else {
              local_24[0] = *pfVar7 - local_18[0];
              local_24[1] = 0.0;
              local_24[2] = pfVar7[2] - local_18[2];
              FUN_005b3b30(local_24,local_24);
            }
            local_40 = &DAT_0093d7f0;
            do {
              iVar6 = *local_40;
              if (((((iVar6 != 0) && ((*(byte *)(iVar6 + 0x1fc) & 0x80) != 0)) &&
                   (*(char *)(iVar6 + 0x28b) == '\0')) &&
                  ((DAT_00802828 == -1 || (*(char *)(iVar6 + 0x7b5) != DAT_00802828)))) &&
                 ((*(float *)(iVar6 + 0x1018) <= 0.0 &&
                  ((*(float *)(iVar6 + 0x1000) <= 0.0 &&
                   ((*(uint *)(iVar6 + 0xef0) & 0x400000) == 0)))))) {
                iVar1 = iVar6 + 0x80;
                FUN_005b3800(local_c,iVar1,pfVar7);
                param_1 = (int *)(local_c[0] * local_24[0] + local_4 * local_24[2]);
                if (*(char *)((int)piVar4 + 0x1e) == '\x01') {
                  if ((float)param_1 < 0.0) goto LAB_005a3418;
                  FUN_005b3620(local_c,local_c,0x4000);
                  param_1 = (int *)(local_c[0] * local_24[0] + local_4 * local_24[2]);
                }
                if ((ABS((float)param_1) < fVar2) &&
                   ((*(char *)((int)piVar4 + 0x1e) != '\0' ||
                    (0.0 <= local_c[0] * (float)piVar4[5] + (float)piVar4[6] * local_4)))) {
                  FUN_005478a0((int)*(short *)((int)piVar4 + 0xe),iVar1,0,0);
                  iVar8 = FUN_00438230(0,iVar6,1,0,0,1);
                  if (iVar8 == 2) {
                    FUN_0054aa10(iVar6);
                  }
                  else {
                    FUN_0054aae0(iVar6,0x3f333333);
                    iVar8 = 3;
                    if (0.0 <= (float)param_1) {
                      iVar8 = 4;
                    }
                    *(undefined4 *)(iVar6 + 0x68) = 0;
                    *(undefined4 *)(iVar6 + 0x70) = 0;
                    *(uint *)(iVar6 + 0xe24) =
                         *(uint *)(iVar6 + 0xe24) ^
                         (iVar8 << 0x10 ^ *(uint *)(iVar6 + 0xe24)) & 0x70000;
                    local_28 = 0xffffffff;
                    FUN_00690460(&local_28,
                                 *(undefined4 *)
                                  (*(int *)(*(int *)(iVar5 + 0x134) + 8) + (short)piVar4[7] * 0x14),
                                 iVar1,1);
                  }
                }
              }
LAB_005a3418:
              local_40 = local_40 + 1;
            } while ((int)local_40 < 0x93d7f8);
          }
        }
        local_3c = local_3c + 1;
        iVar9 = iVar9 + 0x34;
      } while (local_3c < (int)(uint)*(ushort *)(piVar4 + 1));
    }
  }
  return;
}

