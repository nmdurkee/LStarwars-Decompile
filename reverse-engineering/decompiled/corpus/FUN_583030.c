/* Ghidra analysis pseudocode, not original source.
 * ev_cf42e26bdd29ce594f9da2c695f01b0cbf0dbb26fec502101b142af0e3962cb1
 * Entry: 0x583030; label: FUN_00583030
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00583030(int param_1)

{
  int *piVar1;
  float *pfVar2;
  int *piVar3;
  char cVar4;
  code *pcVar5;
  bool bVar6;
  float fVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  undefined4 uVar11;
  int iVar12;
  int *piVar13;
  short *psVar14;
  float10 fVar15;
  undefined1 *puVar16;
  float local_88;
  int local_84;
  int local_80;
  undefined4 local_7c;
  undefined4 uStack_78;
  float fStack_74;
  undefined1 auStack_70 [12];
  float fStack_64;
  int iStack_60;
  int iStack_5c;
  undefined1 auStack_58 [12];
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined1 auStack_40 [12];
  undefined1 local_34 [4];
  float local_30;
  undefined1 local_28 [4];
  char local_24 [32];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_88;
  local_84 = param_1;
  local_44 = DAT_00802508;
  local_4c = DAT_00802500;
  local_48 = DAT_00802504;
  local_24[0] = '\0';
  local_24[1] = '\0';
  local_24[2] = '\0';
  local_24[3] = '\0';
  local_24[4] = '\0';
  local_24[5] = '\0';
  local_24[6] = '\0';
  local_24[7] = '\0';
  local_24[8] = '\0';
  local_24[9] = '\0';
  local_24[10] = '\0';
  local_24[0xb] = '\0';
  local_24[0xc] = '\0';
  local_24[0xd] = '\0';
  local_24[0xe] = '\0';
  local_24[0xf] = '\0';
  local_24[0x10] = '\0';
  local_24[0x11] = '\0';
  local_24[0x12] = '\0';
  local_24[0x13] = '\0';
  local_24[0x14] = '\0';
  local_24[0x15] = '\0';
  local_24[0x16] = '\0';
  local_24[0x17] = '\0';
  local_24[0x18] = '\0';
  local_24[0x19] = '\0';
  local_24[0x1a] = '\0';
  local_24[0x1b] = '\0';
  local_24[0x1c] = '\0';
  local_24[0x1d] = '\0';
  local_24[0x1e] = '\0';
  local_24[0x1f] = '\0';
  piVar13 = &DAT_00951ce8;
  local_80 = 0;
  do {
    if (((char)piVar13[0x40] != '\0') && (local_24[local_80] == '\0')) {
      if ((piVar13[1] != 0) &&
         ((uVar9 = *(uint *)(piVar13[1] + 0x1fc), (uVar9 & 1) == 0 || ((uVar9 & 0x1000) == 0)))) {
        piVar13[1] = 0;
      }
      iVar10 = *piVar13;
      if ((*(byte *)(piVar13 + 0x3c) & 4) == 0) {
        local_88 = (float)piVar13[0x37] - _DAT_00925018;
        piVar13[0x37] = (int)local_88;
        if (local_88 <= 0.0) {
          local_88 = (float)piVar13[0x33] * 0.2;
          FUN_005b3830(local_34,piVar13 + 0x2b,local_88);
          piVar13[0x37] = 0x3e4ccccd;
          if ((float)piVar13[0x3b] != 0.0) {
            local_30 = (float)piVar13[0x29] * 0.2 + (float)piVar13[0x3b] * 0.5 * 0.040000003;
          }
          piVar1 = piVar13 + 0x22;
          FUN_005b37d0(&local_7c,piVar1,local_34);
          FUN_005b3800(local_34,&local_7c,piVar13 + 0x2e);
          iVar8 = FUN_0057f9a0(piVar13 + 0x2e);
          if (iVar8 != 0) {
            FUN_0067b230(&local_4c);
            FUN_0067ab20(local_28);
            fVar15 = (float10)FUN_0067b200();
            piVar13[0x34] =
                 (int)(float)(fVar15 * (float10)(float)piVar13[0x37] + (float10)(float)piVar13[0x32]
                             );
            if (*(code **)(*piVar13 + 0x50) != (code *)0x0) {
              (**(code **)(*piVar13 + 0x50))(piVar13,&local_4c);
            }
          }
          piVar13[0x3a] = 0x49f42400;
          fVar15 = (float10)FUN_005506f0(0,piVar1,0x40a00000,0xffffffff);
          local_88 = (float)fVar15;
          if (local_88 != 2e+06) {
            iVar8 = FUN_005cfac0(iVar10 + 0x98);
            if (iVar8 != 0) {
              piVar13[0x39] = (int)local_88;
              FUN_0054fec0(&DAT_0292fdb8,piVar13 + 0x3d,(int)piVar13 + 0xf6);
            }
            uVar9 = FUN_0067a600();
            if ((uVar9 < 0x20) && (((&DAT_008034cc)[uVar9 * 0xc] & 2) != 0)) {
              fVar15 = (float10)local_88;
            }
            else {
              local_88 = (float)FUN_0067a6e0();
              if ((float)(int)local_88 == -1.0) goto LAB_005832c6;
              fVar15 = (float10)FUN_00553500(piVar1);
            }
            piVar13[0x3a] = (int)(float)fVar15;
          }
        }
      }
LAB_005832c6:
      piVar13[0x32] = (int)((float)piVar13[0x32] + _DAT_00925018);
      if (*(code **)(iVar10 + 0x48) != (code *)0x0) {
        (**(code **)(iVar10 + 0x48))(piVar13);
      }
      if ((float)piVar13[0x3b] != 0.0) {
        piVar13[0x29] = (int)((float)piVar13[0x3b] * _DAT_00925018 + (float)piVar13[0x29]);
        fVar15 = (float10)FUN_005bec80(piVar13 + 0x28);
        piVar13[0x33] = (int)(float)fVar15;
        FUN_005b3b30(piVar13 + 0x2b,piVar13 + 0x28);
        if ((piVar13[0x3c] & 0x1000U) != 0) {
          FUN_0057fb30();
        }
      }
      fVar7 = _DAT_00925018;
      pfVar2 = (float *)(piVar13 + 0x22);
      *pfVar2 = _DAT_00925018 * (float)piVar13[0x28] + *pfVar2;
      piVar13[0x23] = (int)((float)piVar13[0x29] * fVar7 + (float)piVar13[0x23]);
      piVar13[0x24] = (int)(fVar7 * (float)piVar13[0x2a] + (float)piVar13[0x24]);
      fStack_64 = *pfVar2;
      iStack_60 = piVar13[0x23];
      iStack_5c = piVar13[0x24];
      if ((piVar13[0x3c] & 0x200U) == 0) {
        uStack_78 = 0;
        local_7c = 0;
        fStack_74 = (float)piVar13[0x36] + (float)piVar13[0x36];
        FUN_005b3200(&local_7c,&local_7c,piVar13 + 2);
        FUN_005b3800(auStack_70,pfVar2,&local_7c);
        FUN_005b37d0(auStack_58,pfVar2,&local_7c);
      }
      piVar13[0x42] = (int)(*pfVar2 - (float)piVar13[0x35]);
      piVar13[0x43] = (int)((float)piVar13[0x23] - (float)piVar13[0x35]);
      piVar13[0x44] = (int)((float)piVar13[0x24] - (float)piVar13[0x35]);
      piVar13[0x45] = (int)((float)piVar13[0x35] + *pfVar2);
      piVar13[0x46] = (int)((float)piVar13[0x35] + (float)piVar13[0x23]);
      piVar13[0x47] = (int)((float)piVar13[0x35] + (float)piVar13[0x24]);
      if ((float)piVar13[0x34] < (float)piVar13[0x32] ==
          ((float)piVar13[0x34] == (float)piVar13[0x32])) {
        if (DAT_00951ccc != (code *)0x0) {
          (*DAT_00951ccc)(piVar13,auStack_70);
        }
        psVar14 = (short *)(iVar10 + 0x30);
        iVar10 = 2;
        do {
          if ((*psVar14 != -1) && (psVar14[2] != 0)) {
            FUN_006561d0(*(undefined4 *)(*(int *)(*(int *)(local_84 + 0x134) + 8) + *psVar14 * 0x14)
                         ,pfVar2,0,piVar13 + 0x28,psVar14[2],_DAT_00925018,0,0,20000,0);
          }
          psVar14 = psVar14 + 1;
          iVar10 = iVar10 + -1;
        } while (iVar10 != 0);
        if ((piVar13[0x3c] & 0x10000U) == 0) {
          iVar8 = 0;
          iVar10 = DAT_0093d504;
          if (0 < DAT_0093d500) {
            do {
              if ((((((((*(uint *)(iVar10 + 0x1fc) & 1) != 0) &&
                      ((*(uint *)(iVar10 + 0x1fc) & 0x1000) != 0)) &&
                     (*(char *)(iVar10 + 0x28b) == '\0')) &&
                    (((iVar12 = piVar13[1], iVar10 != iVar12 &&
                      ((*(byte *)(iVar10 + 0xe20) & 0x20) == 0)) &&
                     ((iVar12 == 0 ||
                      ((*(int *)(iVar12 + 0xcd0) == 0 || (iVar10 != *(int *)(iVar12 + 0xcd0)))))))))
                   && ((-1 < (char)piVar13[0x3c] ||
                       ((*(char *)(iVar10 + 0x280) != -1 ||
                        ((*(int *)(iVar10 + 0xcd0) != 0 &&
                         (*(char *)(*(int *)(iVar10 + 0xcd0) + 0x280) != -1)))))))) &&
                  ((*(uint *)(PTR_PTR_007fb0e4 + *(char *)(iVar10 + 0x7b5) * 0x10 + 8) & 0x8080) ==
                   0)) && (((((*(uint *)(iVar10 + 0xe24) & 0x8000) == 0 &&
                             (((((DAT_00951288 == 0 || (DAT_00951154 != 0)) || (iVar12 == 0)) ||
                               ((*(char *)(iVar12 + 0x280) == -1 ||
                                (*(char *)(iVar10 + 0x280) == -1)))) &&
                              ((((*(uint *)(*(int *)(*(int *)(iVar10 + 0x54) + 0x24) + 0x90) &
                                 0x8000) == 0 &&
                                (((float)piVar13[0x42] <= *(float *)(iVar10 + 0x184) &&
                                 (*(float *)(iVar10 + 0x178) <= (float)piVar13[0x45])))) &&
                               ((float)piVar13[0x44] <= *(float *)(iVar10 + 0x18c))))))) &&
                            (*(float *)(iVar10 + 0x180) <= (float)piVar13[0x47])) &&
                           ((((piVar13[0x3c] & 0x8000000U) != 0 ||
                             (((float)piVar13[0x43] <= *(float *)(iVar10 + 0x188) &&
                              (*(float *)(iVar10 + 0x17c) <= (float)piVar13[0x46])))) &&
                            (iVar12 = FUN_00581fb0(piVar13,iVar10,auStack_70,piVar13 + 0x42,
                                                   piVar13 + 0x45,piVar13[0x36],local_24),
                            iVar12 != 0)))))) goto LAB_00583aaf;
              iVar8 = iVar8 + 1;
              iVar10 = iVar10 + 0x10d8;
            } while (iVar8 < DAT_0093d500);
          }
          if (((*(byte *)(piVar13 + 0x3c) & 0x13) != 0) ||
             ((iVar10 = piVar13[1], iVar10 != 0 &&
              (((*(uint *)(iVar10 + 0xeec) & 0x10000000) != 0 ||
               (*(char *)(iVar10 + 0xf00) == '\x05')))))) {
            piVar1 = piVar13 + 0x45;
            piVar3 = piVar13 + 0x42;
            iVar10 = FUN_0046a6d0(*(undefined4 *)(local_84 + 0x2ac8),local_84,piVar13,auStack_70,
                                  piVar3,piVar1,piVar13[0x36],local_24);
            if ((iVar10 == 0) && (iVar10 = FUN_00581110(piVar3,piVar1,piVar13[0x36]), iVar10 == 0))
            {
              if (piVar13[1] == 0) {
LAB_00583a8f:
                uVar11 = 3;
              }
              else {
                cVar4 = *(char *)(piVar13[1] + 0x280);
                if (cVar4 == '\0') {
                  uVar11 = 4;
                }
                else {
                  uVar11 = 5;
                  if (cVar4 != '\x01') goto LAB_00583a8f;
                }
              }
              FUN_00580a10(piVar13,auStack_70,piVar3,piVar1,piVar13[0x36],uVar11);
            }
          }
        }
      }
      else {
        bVar6 = false;
        local_88 = 0.0;
        if ((char)piVar13[0x41] == -1) {
          puVar16 = (undefined1 *)0x0;
LAB_00583508:
          (**(code **)(PTR_PTR_008040bc + 0xc))(piVar13,auStack_70,0xffffffff,puVar16,0);
        }
        else {
          FUN_0057fc30(piVar13 + 0x48,piVar13 + 0x28,auStack_40);
          FUN_005b3830(auStack_40,auStack_40,0x3e4ccccd);
          bVar6 = true;
          local_88 = 1.4013e-45;
          if (((*(short *)((int)piVar13 + 0xfa) == -1) || ((char)piVar13[0x41] == -1)) ||
             ((*(uint *)(&DAT_008034cc + (char)piVar13[0x41] * 0xc) & 0x1000) == 0)) {
            puVar16 = auStack_40;
            goto LAB_00583508;
          }
          (**(code **)(PTR_PTR_008040bc + 0xc))(piVar13,auStack_70,0xffffffff,auStack_40,1);
        }
        *(undefined1 *)(piVar13 + 0x40) = 0;
        if ((*piVar13 != 0) && (pcVar5 = *(code **)(*piVar13 + 0x4c), pcVar5 != (code *)0x0)) {
          (*pcVar5)(piVar13);
        }
        if (((piVar13[0x3c] & 0x10000U) == 0) &&
           (iVar10 = FUN_00582270(piVar13,auStack_70,piVar13 + 0x42,piVar13 + 0x45,piVar13[0x36],0),
           iVar10 == 0)) {
          if (((*(byte *)(piVar13 + 0x3c) & 0x13) == 0) &&
             ((iVar10 = piVar13[1], iVar10 == 0 ||
              (((*(uint *)(iVar10 + 0xeec) & 0x10000000) == 0 &&
               (*(char *)(iVar10 + 0xf00) != '\x05')))))) {
            if (bVar6) {
              if (((*(short *)((int)piVar13 + 0xfa) != -1) && ((char)piVar13[0x41] != -1)) &&
                 ((*(uint *)(&DAT_008034cc + (char)piVar13[0x41] * 0xc) & 0x1000) != 0)) {
                FUN_00547930(0x29,pfVar2,0,0);
                FUN_0057fc80(piVar13,piVar13 + 0x2b,piVar13 + 0x48,local_24);
              }
LAB_005836d0:
              if (((local_88 != 0.0) && (cVar4 = (char)piVar13[0x41], -1 < cVar4)) &&
                 ((cVar4 < ' ' &&
                  (((*(uint *)(&DAT_008034cc + cVar4 * 0xc) & 0x800) != 0 &&
                   ((piVar13[0x3c] & 0x8000U) == 0)))))) {
                FUN_00547930(0x29,pfVar2,0,0);
                FUN_0057fc80(piVar13,piVar13 + 0x28,piVar13 + 0x48,local_24);
                goto LAB_00583746;
              }
            }
            if ((piVar13[0x3c] & 0x80000U) == 0) {
              FUN_0057fe80(piVar13);
            }
          }
          else if (*(short *)((int)piVar13 + 0xfa) == -1) {
            piVar1 = piVar13 + 0x42;
            iVar10 = FUN_0046a6d0(*(undefined4 *)(local_84 + 0x2ac8),local_84,piVar13,auStack_70,
                                  piVar1,piVar13 + 0x45,piVar13[0x36],0);
            if (iVar10 == 0) {
              iVar10 = FUN_00581110(piVar1,piVar13 + 0x45,piVar13[0x36]);
              if (iVar10 == 0) {
                uVar11 = FUN_005809e0(piVar13);
                iVar10 = FUN_00580a10(piVar13,auStack_70,piVar1,piVar13 + 0x45,piVar13[0x36],uVar11)
                ;
                if (iVar10 == 0) goto LAB_005836d0;
              }
            }
          }
          else if ((DAT_00951cc4 == (code *)0x0) || (iVar10 = (*DAT_00951cc4)(piVar13), iVar10 == 0)
                  ) {
            FUN_00580f50(local_24);
          }
LAB_00583746:
          if (((*(int *)(PTR_PTR_008040bc + 8) != 0) && (iVar10 = piVar13[1], iVar10 != 0)) &&
             ((*(byte *)(iVar10 + 0x1fc) & 0x80) != 0)) {
            (**(code **)(PTR_PTR_008040bc + 8))(iVar10,pfVar2);
          }
        }
      }
    }
LAB_00583aaf:
    local_80 = local_80 + 1;
    piVar13 = piVar13 + 0x4e;
    if (0x1f < local_80) {
      __security_check_cookie(local_4 ^ (uint)&local_88);
      return;
    }
  } while( true );
}

