/* Ghidra analysis pseudocode, not original source.
 * ev_fd88e83c03467170e633a7d88452db02a14be58504554e3319fa3a0da483c1d2
 * Entry: 0x4fda90; label: FUN_004fda90
 */

void FUN_004fda90(undefined4 param_1,uint *param_2,int param_3,undefined4 param_4,undefined4 param_5
                 )

{
  char cVar1;
  short sVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  undefined4 *puVar7;
  short *psVar8;
  int iVar9;
  short *psVar10;
  char *pcVar11;
  char *pcVar12;
  int iVar13;
  uint *puVar14;
  uint *puVar15;
  int local_12c;
  int local_128;
  int local_124;
  int local_120;
  uint local_11c;
  int local_118;
  uint *local_114;
  uint local_110;
  uint local_10c;
  char *local_108;
  undefined1 local_104 [128];
  undefined1 local_84 [128];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_12c;
  local_128 = -1;
  local_12c = -1;
  iVar5 = (int)DAT_0091eef4;
  puVar15 = &DAT_0091eed0 + iVar5 * 3;
  local_110 = 0;
  local_11c = 0;
  local_114 = puVar15;
  FUN_004f2ee0(local_104,param_4);
  FUN_004f2ee0(local_84,param_5);
  if (*puVar15 != 0) {
    FUN_004ef790();
  }
  *puVar15 = 0;
  *(undefined4 *)(&DAT_0091eed8 + iVar5 * 0xc) = 0;
  (&DAT_0091eed4)[iVar5 * 3] = 0;
  if (param_3 - *param_2 < 0x14b000) {
    FUN_004ef790();
  }
  iVar13 = param_3 + -0x100000;
  iVar5 = FUN_004fd5d0(param_1,iVar13,0x100000);
  if (0x100000 - iVar5 < 0x18000) {
    FUN_004ef790();
  }
  local_120 = iVar13 + iVar5;
  local_124 = local_120 + 0x8000;
  local_108 = (char *)(param_3 + -0xf0000 + iVar5);
  if (0 < iVar5) {
    iVar9 = 0;
    piVar6 = &DAT_02983750;
    do {
      if (*piVar6 == 0) {
        iVar4 = iVar9 * 0x14;
        local_118 = iVar9 + 0x400;
        *(int *)(&DAT_02983740 + iVar4) = iVar13;
        *(int *)(&DAT_02983744 + iVar4) = local_120 + -1;
        *(int *)(&DAT_02983748 + iVar4) = iVar13;
        *(undefined4 *)(iVar4 + 0x298374c) = 0;
        (&DAT_02983750)[iVar9 * 5] = 1;
        if (local_118 != 0) {
          puVar7 = (undefined4 *)FUN_004fc750(local_118);
          if (puVar7 != (undefined4 *)0x0) {
            puVar7[0x143] = local_124;
            puVar7[0x144] = local_120;
            puVar7[0x145] = 0x8000;
            puVar7[0x146] = 0x8000;
            iVar9 = FUN_004fc5b0(puVar7);
            while (iVar9 != 0) {
              local_11c = local_11c + 1;
              iVar9 = FUN_004fc5b0(puVar7);
            }
            *puVar7 = 0;
          }
          FUN_004f99e0(local_118);
          puVar15 = local_114;
        }
        break;
      }
      piVar6 = piVar6 + 5;
      iVar9 = iVar9 + 1;
    } while ((int)piVar6 < 0x29838e0);
  }
  local_10c = *param_2 + 3 & 0xfffffffc;
  *param_2 = (*param_2 + 3 & 0xfffffffc) + local_11c * 8;
  if (0 < iVar5) {
    iVar5 = 0;
    piVar6 = &DAT_02983750;
    do {
      if (*piVar6 == 0) {
        iVar9 = iVar5 * 0x14;
        *(int *)(&DAT_02983740 + iVar9) = iVar13;
        *(int *)(&DAT_02983748 + iVar9) = iVar13;
        iVar13 = iVar5 + 0x400;
        *(int *)(&DAT_02983744 + iVar9) = local_120 + -1;
        *(undefined4 *)(iVar9 + 0x298374c) = 0;
        (&DAT_02983750)[iVar5 * 5] = 1;
        local_118 = iVar13;
        if (iVar13 != 0) {
          puVar7 = (undefined4 *)FUN_004fc750(iVar13);
          if (puVar7 != (undefined4 *)0x0) {
            puVar7[0x144] = local_120;
            puVar7[0x143] = local_124;
            puVar7[0x145] = 0x8000;
            puVar7[0x146] = 0x8000;
            iVar5 = FUN_004fc5b0(puVar7);
            if (iVar5 != 0) {
              do {
                iVar5 = 0;
                iVar13 = FUN_004f7fb0(puVar7);
                while (iVar13 != 0) {
                  uVar3 = puVar7[0x144];
                  iVar13 = FUN_004f24e0(uVar3,local_104);
                  if (iVar13 == 0) {
                    local_128 = iVar5;
                  }
                  iVar13 = FUN_004f24e0(uVar3,local_84);
                  if (iVar13 == 0) {
                    local_12c = iVar5;
                  }
                  iVar5 = iVar5 + 1;
                  iVar13 = FUN_004f7fb0(puVar7);
                  puVar15 = local_114;
                }
              } while (((local_128 < 0) || (local_12c < 0)) &&
                      (iVar5 = FUN_004fc5b0(puVar7), iVar5 != 0));
              iVar13 = local_118;
              if (((-1 < local_128) && (-1 < local_12c)) &&
                 (iVar5 = FUN_004fc5b0(puVar7), iVar13 = local_118, iVar5 != 0)) {
                puVar14 = (uint *)(local_10c + 4);
                do {
                  local_124 = 0;
                  iVar5 = FUN_004f7fb0(puVar7);
                  if (iVar5 != 0) {
                    iVar5 = 0;
                    do {
                      if (iVar5 == local_128) {
                        psVar8 = (short *)puVar7[0x144];
                        iVar13 = 0;
                        sVar2 = *psVar8;
                        while (sVar2 != 0) {
                          psVar8 = psVar8 + 1;
                          iVar13 = iVar13 + 1;
                          sVar2 = *psVar8;
                        }
                        puVar14[-1] = *param_2;
                        *param_2 = *param_2 + iVar13 + 1;
                        FUN_004f2dc0(puVar14[-1],puVar7[0x144]);
                      }
                      pcVar12 = local_108;
                      if (iVar5 == local_12c) {
                        psVar8 = (short *)puVar7[0x144];
                        if (DAT_00800484 == 1) {
                          iVar13 = 0;
                          sVar2 = *psVar8;
                          while (sVar2 != 0) {
                            psVar8 = psVar8 + 1;
                            iVar13 = iVar13 + 1;
                            sVar2 = *psVar8;
                          }
                          *puVar14 = *param_2 + 1 & 0xfffffffe;
                          *param_2 = (*param_2 + 1 & 0xfffffffe) + 2 + iVar13 * 2;
                          psVar8 = (short *)puVar7[0x144];
                          psVar10 = (short *)*puVar14;
                          if (psVar8 == (short *)0x0) {
                            *psVar10 = 0;
                          }
                          else {
                            do {
                              *psVar10 = *psVar8;
                              sVar2 = *psVar8;
                              psVar10 = psVar10 + 1;
                              psVar8 = psVar8 + 1;
                            } while (sVar2 != 0);
                          }
                        }
                        else {
                          FUN_004f2e60(local_108,psVar8);
                          iVar5 = FUN_004f1ff0(pcVar12);
                          *puVar14 = *param_2 + 1 & 0xfffffffe;
                          *param_2 = (*param_2 + 1 & 0xfffffffe) + iVar5 + 1;
                          pcVar11 = (char *)*puVar14;
                          if (pcVar12 != (char *)0x0) {
                            cVar1 = *pcVar12;
                            while (cVar1 != '\0') {
                              pcVar12 = pcVar12 + 1;
                              *pcVar11 = cVar1;
                              pcVar11 = pcVar11 + 1;
                              cVar1 = *pcVar12;
                            }
                          }
                          *pcVar11 = '\0';
                          iVar5 = local_124;
                        }
                      }
                      iVar5 = iVar5 + 1;
                      local_124 = iVar5;
                      if ((local_128 < iVar5) && (local_12c < iVar5)) {
                        if ((puVar14[-1] == 0) || (*puVar14 == 0)) {
                          puVar14[-1] = 0;
                          *puVar14 = 0;
                        }
                        else {
                          local_110 = local_110 + 1;
                          puVar14 = puVar14 + 2;
                        }
                        break;
                      }
                      iVar13 = FUN_004f7fb0(puVar7);
                    } while (iVar13 != 0);
                  }
                  iVar5 = FUN_004fc5b0(puVar7);
                  iVar13 = local_118;
                  puVar15 = local_114;
                } while (iVar5 != 0);
              }
            }
            *puVar7 = 0;
            *puVar15 = local_10c;
            puVar15[1] = local_110;
            puVar15[2] = local_11c;
          }
          FUN_004f99e0(iVar13);
        }
        break;
      }
      piVar6 = piVar6 + 5;
      iVar5 = iVar5 + 1;
    } while ((int)piVar6 < 0x29838e0);
  }
  __security_check_cookie(local_4 ^ (uint)&local_12c);
  return;
}

